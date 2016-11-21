#include "cacheinitializer.h"
#include "../autogenerated/telegramapi.h"
#include "../mtproto/dc/dcsessionmanager.h"
#include "telegramcache.h"

#define DialogsFirstLoad 20
#define DialogsPerPage   500

CacheInitializer::CacheInitializer(QObject *parent) : QObject(parent), _state(CacheInitializer::First)
{
    this->_dialogsoffsetdate = 0;
    this->_dialogsoffsetid = 0;
    this->_totaldialogs = 0;
    this->_loadeddialogs = 0;
    this->_unreadcount = 0;
    this->_dialogoffsetpeer.setConstructorId(TLTypes::InputPeerEmpty);
}

void CacheInitializer::initialize()
{
    if(this->_state == CacheInitializer::RequestState)
        this->requestState();
    if(this->_state == CacheInitializer::RequestContacts)
        this->requestContacts();
    else if(this->_state == CacheInitializer::RequestDialogs)
        this->requestDialogs();

    if(this->_state > CacheInitializer::Last)
        emit initialized(this->_unreadcount);
}

void CacheInitializer::requestState() const
{
    MTProtoRequest* req = TelegramAPI::updatesGetState(DC_MainSession);
    connect(req, &MTProtoRequest::replied, this, &CacheInitializer::onRequestStateReplied);
}

void CacheInitializer::requestContacts() const
{
    MTProtoRequest* req = TelegramAPI::contactsGetContacts(DC_MainSession, TLString());
    connect(req, &MTProtoRequest::replied, this, &CacheInitializer::onRequestContactsReplied);
}

void CacheInitializer::requestDialogs()
{
    TLInt limit = this->_dialogsoffsetdate ? DialogsPerPage : DialogsFirstLoad;

    MTProtoRequest* req = TelegramAPI::messagesGetDialogs(DC_MainSession,
                                                          this->_dialogsoffsetdate,
                                                          this->_dialogsoffsetid,
                                                          &this->_dialogoffsetpeer, limit);

    connect(req, &MTProtoRequest::replied, this, &CacheInitializer::onRequestDialogsReplied);
}

void CacheInitializer::updateUnreadCount(MessagesDialogs *messagesdialogs)
{
    foreach(Dialog* dialog, messagesdialogs->dialogs())
        this->_unreadcount += dialog->unreadCount();
}

bool CacheInitializer::seekDialogs(MessagesDialogs* messagesdialogs)
{
    Dialog* oldestdialog = messagesdialogs->dialogs().last();
    Message* message = this->findMessage(messagesdialogs, oldestdialog->topMessage());

    if(!message)
        return false;

    if(TelegramHelper::isChat(oldestdialog) || TelegramHelper::isChannel(oldestdialog))
    {
        Chat* chat = this->findChat(messagesdialogs, TelegramHelper::identifier(oldestdialog));

        if(!chat)
            return false;

        this->_dialogoffsetpeer.setAccessHash(chat->accessHash());

        if(TelegramHelper::isChat(oldestdialog))
        {
            this->_dialogoffsetpeer.setConstructorId(TLTypes::InputPeerChat);
            this->_dialogoffsetpeer.setChatId(oldestdialog->peer()->chatId());
        }
        else
        {
            this->_dialogoffsetpeer.setConstructorId(TLTypes::InputPeerChannel);
            this->_dialogoffsetpeer.setChannelId(oldestdialog->peer()->channelId());
        }
    }
    else
    {
        User* user = this->findUser(messagesdialogs, TelegramHelper::identifier(oldestdialog));

        if(!user)
            return false;

        this->_dialogoffsetpeer.setConstructorId(TLTypes::InputPeerUser);
        this->_dialogoffsetpeer.setUserId(oldestdialog->peer()->userId());
        this->_dialogoffsetpeer.setAccessHash(user->accessHash());;
    }

    this->_dialogsoffsetdate = message->date();
    this->_dialogsoffsetid = message->id();
    return true;
}


Message *CacheInitializer::findMessage(MessagesDialogs *messagesdialogs, TLInt messageid) const
{
    for(TLInt i = messagesdialogs->messages().length(); i > 0; )
    {
        Message* message = messagesdialogs->messages().at(--i);

        if(message->id() == messageid)
            return message;
    }

    return NULL;
}

Chat *CacheInitializer::findChat(MessagesDialogs *messagesdialogs, TLInt chatid) const
{
    for(TLInt i = messagesdialogs->chats().length(); i > 0; )
    {
        Chat* chat = messagesdialogs->chats().at(--i);

        if(chat->id() == chatid)
            return chat;
    }

    return NULL;
}

User *CacheInitializer::findUser(MessagesDialogs *messagesdialogs, TLInt userid) const
{
    for(TLInt i = messagesdialogs->users().length(); i > 0; )
    {
        User* user = messagesdialogs->users().at(--i);

        if(user->id() == userid)
            return user;
    }

    return NULL;
}

void CacheInitializer::onRequestStateReplied(MTProtoReply *mtreply)
{
    TelegramConfig_clientState->read(mtreply);

    this->_state++;
    this->initialize();
}

void CacheInitializer::onRequestContactsReplied(MTProtoReply *mtreply)
{
    ContactsContacts contacts;
    contacts.read(mtreply);

    TelegramCache_store(contacts.users());

    this->_state++;
    this->initialize();
}

void CacheInitializer::onRequestDialogsReplied(MTProtoReply *mtreply)
{
    MessagesDialogs messagesdialogs;
    messagesdialogs.read(mtreply);

    TelegramCache_store(messagesdialogs.dialogs());
    TelegramCache_store(messagesdialogs.users());
    TelegramCache_store(messagesdialogs.chats());
    TelegramCache_store(messagesdialogs.messages());

    this->updateUnreadCount(&messagesdialogs);

    if(messagesdialogs.constructorId() == TLTypes::MessagesDialogsSlice)
    {
        this->_totaldialogs = messagesdialogs.count();
        this->_loadeddialogs += messagesdialogs.dialogs().count();

        if((this->_loadeddialogs >= this->_totaldialogs) || !this->seekDialogs(&messagesdialogs))
            this->_state++;
    }
    else
        this->_state++;

    this->initialize();
}
