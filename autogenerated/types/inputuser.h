#ifndef INPUTUSER_H
#define INPUTUSER_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class InputUser: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt userId READ userId WRITE setUserId NOTIFY userIdChanged)
	Q_PROPERTY(TLLong accessHash READ accessHash WRITE setAccessHash NOTIFY accessHashChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorInputUserEmpty = 0xb98886cf,
			CtorInputUserSelf = 0xf7c1b13f,
			CtorInputUser = 0xd8292816,
		};

	public:
		explicit InputUser(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt userId() const;
		void setUserId(TLInt user_id);
		TLLong accessHash() const;
		void setAccessHash(TLLong access_hash);

	signals:
		void userIdChanged();
		void accessHashChanged();

	private:
		TLInt _user_id;
		TLLong _access_hash;

};

#endif // INPUTUSER_H
