#ifndef MESSAGESSAVEDGIFS_H
#define MESSAGESSAVEDGIFS_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"
#include "document.h"

class MessagesSavedGifs: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt hash READ hash WRITE setHash NOTIFY hashChanged)
	Q_PROPERTY(TLVector<Document*> gifs READ gifs WRITE setGifs NOTIFY gifsChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorMessagesSavedGifsNotModified = 0xe8025ca2,
			CtorMessagesSavedGifs = 0x2e0709a5,
		};

	public:
		explicit MessagesSavedGifs(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt hash() const;
		void setHash(TLInt hash);
		const TLVector<Document*>& gifs() const;
		void setGifs(const TLVector<Document*>& gifs);

	signals:
		void hashChanged();
		void gifsChanged();

	private:
		TLInt _hash;
		TLVector<Document*> _gifs;

};

#endif // MESSAGESSAVEDGIFS_H
