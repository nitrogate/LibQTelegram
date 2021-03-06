#ifndef MESSAGERANGE_H
#define MESSAGERANGE_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class MessageRange: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt minId READ minId WRITE setMinId NOTIFY minIdChanged)
	Q_PROPERTY(TLInt maxId READ maxId WRITE setMaxId NOTIFY maxIdChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorMessageRange = 0xae30253,
		};

	public:
		explicit MessageRange(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt minId() const;
		void setMinId(TLInt min_id);
		TLInt maxId() const;
		void setMaxId(TLInt max_id);

	signals:
		void minIdChanged();
		void maxIdChanged();

	private:
		TLInt _min_id;
		TLInt _max_id;

};

#endif // MESSAGERANGE_H
