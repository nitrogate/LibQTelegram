// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "messagesmessages.h"


MessagesMessages::MessagesMessages(QObject* parent) : TelegramObject(parent)
{
	this->_count = 0;
	this->_flags = 0;
	this->_pts = 0;
}

void MessagesMessages::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == MessagesMessages::CtorMessagesMessages) ||
		 (this->_constructorid == MessagesMessages::CtorMessagesMessagesSlice) ||
		 (this->_constructorid == MessagesMessages::CtorMessagesChannelMessages));
	
	if(this->_constructorid == MessagesMessages::CtorMessagesMessages)
	{
		mtstream->readTLVector<Message>(this->_messages, false, this);
		mtstream->readTLVector<Chat>(this->_chats, false, this);
		mtstream->readTLVector<User>(this->_users, false, this);
	}
	else if(this->_constructorid == MessagesMessages::CtorMessagesMessagesSlice)
	{
		this->_count = mtstream->readTLInt();
		mtstream->readTLVector<Message>(this->_messages, false, this);
		mtstream->readTLVector<Chat>(this->_chats, false, this);
		mtstream->readTLVector<User>(this->_users, false, this);
	}
	else if(this->_constructorid == MessagesMessages::CtorMessagesChannelMessages)
	{
		this->_flags = mtstream->readTLInt();
		this->_pts = mtstream->readTLInt();
		this->_count = mtstream->readTLInt();
		mtstream->readTLVector<Message>(this->_messages, false, this);
		mtstream->readTLVector<Chat>(this->_chats, false, this);
		mtstream->readTLVector<User>(this->_users, false, this);
	}
}

void MessagesMessages::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == MessagesMessages::CtorMessagesMessages) ||
		 (this->_constructorid == MessagesMessages::CtorMessagesMessagesSlice) ||
		 (this->_constructorid == MessagesMessages::CtorMessagesChannelMessages));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == MessagesMessages::CtorMessagesMessages)
	{
		mtstream->writeTLVector(this->_messages, false);
		mtstream->writeTLVector(this->_chats, false);
		mtstream->writeTLVector(this->_users, false);
	}
	else if(this->_constructorid == MessagesMessages::CtorMessagesMessagesSlice)
	{
		mtstream->writeTLInt(this->_count);
		mtstream->writeTLVector(this->_messages, false);
		mtstream->writeTLVector(this->_chats, false);
		mtstream->writeTLVector(this->_users, false);
	}
	else if(this->_constructorid == MessagesMessages::CtorMessagesChannelMessages)
	{
		mtstream->writeTLInt(this->_flags);
		mtstream->writeTLInt(this->_pts);
		mtstream->writeTLInt(this->_count);
		mtstream->writeTLVector(this->_messages, false);
		mtstream->writeTLVector(this->_chats, false);
		mtstream->writeTLVector(this->_users, false);
	}
}

void MessagesMessages::compileFlags() 
{
	
}

const TLVector<Message*>& MessagesMessages::messages() const
{
	return this->_messages;
}

void MessagesMessages::setMessages(const TLVector<Message*>& messages) 
{
	if(this->_messages == messages)
		return;

	this->_messages = messages;
	emit messagesChanged();
}

const TLVector<Chat*>& MessagesMessages::chats() const
{
	return this->_chats;
}

void MessagesMessages::setChats(const TLVector<Chat*>& chats) 
{
	if(this->_chats == chats)
		return;

	this->_chats = chats;
	emit chatsChanged();
}

const TLVector<User*>& MessagesMessages::users() const
{
	return this->_users;
}

void MessagesMessages::setUsers(const TLVector<User*>& users) 
{
	if(this->_users == users)
		return;

	this->_users = users;
	emit usersChanged();
}

TLInt MessagesMessages::count() const
{
	return this->_count;
}

void MessagesMessages::setCount(TLInt count) 
{
	if(this->_count == count)
		return;

	this->_count = count;
	emit countChanged();
}

TLInt MessagesMessages::flags() const
{
	return this->_flags;
}

void MessagesMessages::setFlags(TLInt flags) 
{
	if(this->_flags == flags)
		return;

	this->_flags = flags;
	emit flagsChanged();
}

TLInt MessagesMessages::pts() const
{
	return this->_pts;
}

void MessagesMessages::setPts(TLInt pts) 
{
	if(this->_pts == pts)
		return;

	this->_pts = pts;
	emit ptsChanged();
}

