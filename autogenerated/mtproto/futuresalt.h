#ifndef FUTURESALT_H
#define FUTURESALT_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class FutureSalt: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt validSince READ validSince WRITE setValidSince NOTIFY validSinceChanged)
	Q_PROPERTY(TLInt validUntil READ validUntil WRITE setValidUntil NOTIFY validUntilChanged)
	Q_PROPERTY(TLLong salt READ salt WRITE setSalt NOTIFY saltChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorFutureSalt = 0x0949d9dc,
		};

	public:
		explicit FutureSalt(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt validSince() const;
		void setValidSince(TLInt valid_since);
		TLInt validUntil() const;
		void setValidUntil(TLInt valid_until);
		TLLong salt() const;
		void setSalt(TLLong salt);

	signals:
		void validSinceChanged();
		void validUntilChanged();
		void saltChanged();

	private:
		TLInt _valid_since;
		TLInt _valid_until;
		TLLong _salt;

};

#endif // FUTURESALT_H
