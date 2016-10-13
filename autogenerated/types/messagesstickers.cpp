// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "messagesstickers.h"


MessagesStickers::MessagesStickers(QObject* parent) : TelegramObject(parent)
{
	
}

void MessagesStickers::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == MessagesStickers::CtorMessagesStickersNotModified) ||
		 (this->_constructorid == MessagesStickers::CtorMessagesStickers));
	
	if(this->_constructorid == MessagesStickers::CtorMessagesStickers)
	{
		this->_hash = mtstream->readTLString();
		mtstream->readTLVector<Document>(this->_stickers, false, this);
	}
}

void MessagesStickers::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == MessagesStickers::CtorMessagesStickersNotModified) ||
		 (this->_constructorid == MessagesStickers::CtorMessagesStickers));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == MessagesStickers::CtorMessagesStickers)
	{
		mtstream->writeTLString(this->_hash);
		mtstream->writeTLVector(this->_stickers, false);
	}
}

void MessagesStickers::compileFlags() 
{
	
}

TLString MessagesStickers::hash() const
{
	return this->_hash;
}

void MessagesStickers::setHash(TLString hash) 
{
	if(this->_hash == hash)
		return;

	this->_hash = hash;
	emit hashChanged();
}

const TLVector<Document*>& MessagesStickers::stickers() const
{
	return this->_stickers;
}

void MessagesStickers::setStickers(const TLVector<Document*>& stickers) 
{
	if(this->_stickers == stickers)
		return;

	this->_stickers = stickers;
	emit stickersChanged();
}

