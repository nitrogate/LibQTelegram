#ifndef CONTACTSTATUS_H
#define CONTACTSTATUS_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"
#include "userstatus.h"

class ContactStatus: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt userId READ userId WRITE setUserId NOTIFY userIdChanged)
	Q_PROPERTY(UserStatus* status READ status WRITE setStatus NOTIFY statusChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorContactStatus = 0xd3680c61,
		};

	public:
		explicit ContactStatus(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt userId() const;
		void setUserId(TLInt user_id);
		UserStatus* status() const;
		void setStatus(UserStatus* status);

	signals:
		void userIdChanged();
		void statusChanged();

	private:
		TLInt _user_id;
		UserStatus* _status;

};

#endif // CONTACTSTATUS_H
