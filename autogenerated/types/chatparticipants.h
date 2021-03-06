#ifndef CHATPARTICIPANTS_H
#define CHATPARTICIPANTS_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "chatparticipant.h"
#include "../../types/telegramobject.h"

class ChatParticipants: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt flags READ flags WRITE setFlags NOTIFY flagsChanged)
	Q_PROPERTY(TLInt chatId READ chatId WRITE setChatId NOTIFY chatIdChanged)
	Q_PROPERTY(ChatParticipant* selfParticipant READ selfParticipant WRITE setSelfParticipant NOTIFY selfParticipantChanged)
	Q_PROPERTY(TLVector<ChatParticipant*> participants READ participants WRITE setParticipants NOTIFY participantsChanged)
	Q_PROPERTY(TLInt version READ version WRITE setVersion NOTIFY versionChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorChatParticipantsForbidden = 0xfc900c2b,
			CtorChatParticipants = 0x3f460fed,
		};

	public:
		explicit ChatParticipants(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt flags() const;
		void setFlags(TLInt flags);
		TLInt chatId() const;
		void setChatId(TLInt chat_id);
		ChatParticipant* selfParticipant() const;
		void setSelfParticipant(ChatParticipant* self_participant);
		const TLVector<ChatParticipant*>& participants() const;
		void setParticipants(const TLVector<ChatParticipant*>& participants);
		TLInt version() const;
		void setVersion(TLInt version);

	signals:
		void flagsChanged();
		void chatIdChanged();
		void selfParticipantChanged();
		void participantsChanged();
		void versionChanged();

	private:
		TLInt _flags;
		TLInt _chat_id;
		ChatParticipant* _self_participant;
		TLVector<ChatParticipant*> _participants;
		TLInt _version;

};

#endif // CHATPARTICIPANTS_H
