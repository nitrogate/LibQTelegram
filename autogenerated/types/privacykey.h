#ifndef PRIVACYKEY_H
#define PRIVACYKEY_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class PrivacyKey: public TelegramObject
{
	Q_OBJECT

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorPrivacyKeyStatusTimestamp = 0xbc2eab30,
			CtorPrivacyKeyChatInvite = 0x500e6dfa,
		};

	public:
		explicit PrivacyKey(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();

};

#endif // PRIVACYKEY_H
