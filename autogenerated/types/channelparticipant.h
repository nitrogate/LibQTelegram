#ifndef CHANNELPARTICIPANT_H
#define CHANNELPARTICIPANT_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class ChannelParticipant: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt userId READ userId WRITE setUserId NOTIFY userIdChanged)
	Q_PROPERTY(TLInt date READ date WRITE setDate NOTIFY dateChanged)
	Q_PROPERTY(TLInt inviterId READ inviterId WRITE setInviterId NOTIFY inviterIdChanged)
	Q_PROPERTY(TLInt kickedBy READ kickedBy WRITE setKickedBy NOTIFY kickedByChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorChannelParticipant = 0x15ebac1d,
			CtorChannelParticipantSelf = 0xa3289a6d,
			CtorChannelParticipantModerator = 0x91057fef,
			CtorChannelParticipantEditor = 0x98192d61,
			CtorChannelParticipantKicked = 0x8cc5e69a,
			CtorChannelParticipantCreator = 0xe3e2e1f9,
		};

	public:
		explicit ChannelParticipant(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt userId() const;
		void setUserId(TLInt user_id);
		TLInt date() const;
		void setDate(TLInt date);
		TLInt inviterId() const;
		void setInviterId(TLInt inviter_id);
		TLInt kickedBy() const;
		void setKickedBy(TLInt kicked_by);

	signals:
		void userIdChanged();
		void dateChanged();
		void inviterIdChanged();
		void kickedByChanged();

	private:
		TLInt _user_id;
		TLInt _date;
		TLInt _inviter_id;
		TLInt _kicked_by;

};

#endif // CHANNELPARTICIPANT_H
