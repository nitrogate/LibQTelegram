#ifndef EXPORTEDMESSAGELINK_H
#define EXPORTEDMESSAGELINK_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class ExportedMessageLink: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLString link READ link WRITE setLink NOTIFY linkChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorExportedMessageLink = 0x1f486803,
		};

	public:
		explicit ExportedMessageLink(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLString link() const;
		void setLink(TLString link);

	signals:
		void linkChanged();

	private:
		TLString _link;

};

#endif // EXPORTEDMESSAGELINK_H
