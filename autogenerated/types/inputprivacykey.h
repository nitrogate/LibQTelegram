#ifndef INPUTPRIVACYKEY_H
#define INPUTPRIVACYKEY_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class InputPrivacyKey: public TelegramObject
{
	Q_OBJECT

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorInputPrivacyKeyStatusTimestamp = 0x4f96cb18,
			CtorInputPrivacyKeyChatInvite = 0xbdfb0426,
		};

	public:
		explicit InputPrivacyKey(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();

};

#endif // INPUTPRIVACYKEY_H
