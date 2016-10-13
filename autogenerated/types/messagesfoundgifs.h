#ifndef MESSAGESFOUNDGIFS_H
#define MESSAGESFOUNDGIFS_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"
#include "foundgif.h"

class MessagesFoundGifs: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt nextOffset READ nextOffset WRITE setNextOffset NOTIFY nextOffsetChanged)
	Q_PROPERTY(TLVector<FoundGif*> results READ results WRITE setResults NOTIFY resultsChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorMessagesFoundGifs = 0x450a1c0a,
		};

	public:
		explicit MessagesFoundGifs(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt nextOffset() const;
		void setNextOffset(TLInt next_offset);
		const TLVector<FoundGif*>& results() const;
		void setResults(const TLVector<FoundGif*>& results);

	signals:
		void nextOffsetChanged();
		void resultsChanged();

	private:
		TLInt _next_offset;
		TLVector<FoundGif*> _results;

};

#endif // MESSAGESFOUNDGIFS_H
