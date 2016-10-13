#ifndef UPDATES_H
#define UPDATES_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "chat.h"
#include "../../types/basic.h"
#include "../../types/telegramobject.h"
#include "messageentity.h"
#include "user.h"
#include "messagefwdheader.h"
#include "update.h"
#include "messagemedia.h"

class Updates: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt flags READ flags WRITE setFlags NOTIFY flagsChanged)
	Q_PROPERTY(TLTrue isOut READ isOut WRITE setIsOut NOTIFY isOutChanged)
	Q_PROPERTY(TLTrue isMentioned READ isMentioned WRITE setIsMentioned NOTIFY isMentionedChanged)
	Q_PROPERTY(TLTrue isMediaUnread READ isMediaUnread WRITE setIsMediaUnread NOTIFY isMediaUnreadChanged)
	Q_PROPERTY(TLTrue isSilent READ isSilent WRITE setIsSilent NOTIFY isSilentChanged)
	Q_PROPERTY(TLInt id READ id WRITE setId NOTIFY idChanged)
	Q_PROPERTY(TLInt userId READ userId WRITE setUserId NOTIFY userIdChanged)
	Q_PROPERTY(TLString message READ message WRITE setMessage NOTIFY messageChanged)
	Q_PROPERTY(TLInt pts READ pts WRITE setPts NOTIFY ptsChanged)
	Q_PROPERTY(TLInt ptsCount READ ptsCount WRITE setPtsCount NOTIFY ptsCountChanged)
	Q_PROPERTY(TLInt date READ date WRITE setDate NOTIFY dateChanged)
	Q_PROPERTY(MessageFwdHeader* fwdFrom READ fwdFrom WRITE setFwdFrom NOTIFY fwdFromChanged)
	Q_PROPERTY(TLInt viaBotId READ viaBotId WRITE setViaBotId NOTIFY viaBotIdChanged)
	Q_PROPERTY(TLInt replyToMsgId READ replyToMsgId WRITE setReplyToMsgId NOTIFY replyToMsgIdChanged)
	Q_PROPERTY(TLVector<MessageEntity*> entities READ entities WRITE setEntities NOTIFY entitiesChanged)
	Q_PROPERTY(TLInt fromId READ fromId WRITE setFromId NOTIFY fromIdChanged)
	Q_PROPERTY(TLInt chatId READ chatId WRITE setChatId NOTIFY chatIdChanged)
	Q_PROPERTY(Update* update READ update WRITE setUpdate NOTIFY updateChanged)
	Q_PROPERTY(TLVector<Update*> updates READ updates WRITE setUpdates NOTIFY updatesChanged)
	Q_PROPERTY(TLVector<User*> users READ users WRITE setUsers NOTIFY usersChanged)
	Q_PROPERTY(TLVector<Chat*> chats READ chats WRITE setChats NOTIFY chatsChanged)
	Q_PROPERTY(TLInt seqStart READ seqStart WRITE setSeqStart NOTIFY seqStartChanged)
	Q_PROPERTY(TLInt seq READ seq WRITE setSeq NOTIFY seqChanged)
	Q_PROPERTY(MessageMedia* media READ media WRITE setMedia NOTIFY mediaChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorUpdatesTooLong = 0xe317af7e,
			CtorUpdateShortMessage = 0x914fbf11,
			CtorUpdateShortChatMessage = 0x16812688,
			CtorUpdateShort = 0x78d4dec1,
			CtorUpdatesCombined = 0x725b04c3,
			CtorUpdates = 0x74ae4240,
			CtorUpdateShortSentMessage = 0x11f1331c,
		};

	public:
		explicit Updates(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt flags() const;
		void setFlags(TLInt flags);
		TLTrue isOut() const;
		void setIsOut(TLTrue is_out);
		TLTrue isMentioned() const;
		void setIsMentioned(TLTrue is_mentioned);
		TLTrue isMediaUnread() const;
		void setIsMediaUnread(TLTrue is_media_unread);
		TLTrue isSilent() const;
		void setIsSilent(TLTrue is_silent);
		TLInt id() const;
		void setId(TLInt id);
		TLInt userId() const;
		void setUserId(TLInt user_id);
		TLString message() const;
		void setMessage(TLString message);
		TLInt pts() const;
		void setPts(TLInt pts);
		TLInt ptsCount() const;
		void setPtsCount(TLInt pts_count);
		TLInt date() const;
		void setDate(TLInt date);
		MessageFwdHeader* fwdFrom() const;
		void setFwdFrom(MessageFwdHeader* fwd_from);
		TLInt viaBotId() const;
		void setViaBotId(TLInt via_bot_id);
		TLInt replyToMsgId() const;
		void setReplyToMsgId(TLInt reply_to_msg_id);
		const TLVector<MessageEntity*>& entities() const;
		void setEntities(const TLVector<MessageEntity*>& entities);
		TLInt fromId() const;
		void setFromId(TLInt from_id);
		TLInt chatId() const;
		void setChatId(TLInt chat_id);
		Update* update() const;
		void setUpdate(Update* update);
		const TLVector<Update*>& updates() const;
		void setUpdates(const TLVector<Update*>& updates);
		const TLVector<User*>& users() const;
		void setUsers(const TLVector<User*>& users);
		const TLVector<Chat*>& chats() const;
		void setChats(const TLVector<Chat*>& chats);
		TLInt seqStart() const;
		void setSeqStart(TLInt seq_start);
		TLInt seq() const;
		void setSeq(TLInt seq);
		MessageMedia* media() const;
		void setMedia(MessageMedia* media);

	signals:
		void flagsChanged();
		void isOutChanged();
		void isMentionedChanged();
		void isMediaUnreadChanged();
		void isSilentChanged();
		void idChanged();
		void userIdChanged();
		void messageChanged();
		void ptsChanged();
		void ptsCountChanged();
		void dateChanged();
		void fwdFromChanged();
		void viaBotIdChanged();
		void replyToMsgIdChanged();
		void entitiesChanged();
		void fromIdChanged();
		void chatIdChanged();
		void updateChanged();
		void updatesChanged();
		void usersChanged();
		void chatsChanged();
		void seqStartChanged();
		void seqChanged();
		void mediaChanged();

	private:
		TLInt _flags;
		TLTrue _is_out;
		TLTrue _is_mentioned;
		TLTrue _is_media_unread;
		TLTrue _is_silent;
		TLInt _id;
		TLInt _user_id;
		TLString _message;
		TLInt _pts;
		TLInt _pts_count;
		TLInt _date;
		MessageFwdHeader* _fwd_from;
		TLInt _via_bot_id;
		TLInt _reply_to_msg_id;
		TLVector<MessageEntity*> _entities;
		TLInt _from_id;
		TLInt _chat_id;
		Update* _update;
		TLVector<Update*> _updates;
		TLVector<User*> _users;
		TLVector<Chat*> _chats;
		TLInt _seq_start;
		TLInt _seq;
		MessageMedia* _media;

};

#endif // UPDATES_H
