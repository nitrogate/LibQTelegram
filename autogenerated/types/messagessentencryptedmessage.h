#ifndef MESSAGESSENTENCRYPTEDMESSAGE_H
#define MESSAGESSENTENCRYPTEDMESSAGE_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"
#include "encryptedfile.h"

class MessagesSentEncryptedMessage: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt date READ date WRITE setDate NOTIFY dateChanged)
	Q_PROPERTY(EncryptedFile* file READ file WRITE setFile NOTIFY fileChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorMessagesSentEncryptedMessage = 0x560f8935,
			CtorMessagesSentEncryptedFile = 0x9493ff32,
		};

	public:
		explicit MessagesSentEncryptedMessage(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt date() const;
		void setDate(TLInt date);
		EncryptedFile* file() const;
		void setFile(EncryptedFile* file);

	signals:
		void dateChanged();
		void fileChanged();

	private:
		TLInt _date;
		EncryptedFile* _file;

};

#endif // MESSAGESSENTENCRYPTEDMESSAGE_H
