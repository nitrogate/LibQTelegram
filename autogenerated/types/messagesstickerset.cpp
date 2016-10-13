// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "messagesstickerset.h"


MessagesStickerSet::MessagesStickerSet(QObject* parent) : TelegramObject(parent)
{
	this->_set = NULL;
	this->_constructorid = MessagesStickerSet::CtorMessagesStickerSet;
}

void MessagesStickerSet::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == MessagesStickerSet::CtorMessagesStickerSet));
	
	if(this->_constructorid == MessagesStickerSet::CtorMessagesStickerSet)
	{
		TLInt set_ctor = mtstream->peekTLConstructor();
		
		if(set_ctor != TLTypes::Null)
		{
			this->resetTLType<StickerSet>(&this->_set);
			this->_set->read(mtstream);
		}
		else
		{
			this->nullTLType<StickerSet>(&this->_set);
			mtstream->readTLConstructor(); // Skip Null
		}
		
		mtstream->readTLVector<StickerPack>(this->_packs, false, this);
		mtstream->readTLVector<Document>(this->_documents, false, this);
	}
}

void MessagesStickerSet::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == MessagesStickerSet::CtorMessagesStickerSet));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == MessagesStickerSet::CtorMessagesStickerSet)
	{
		if(this->_set != NULL)
			this->_set->write(mtstream);
		else
			mtstream->writeTLConstructor(TLTypes::Null);
		
		mtstream->writeTLVector(this->_packs, false);
		mtstream->writeTLVector(this->_documents, false);
	}
}

void MessagesStickerSet::compileFlags() 
{
	
}

StickerSet* MessagesStickerSet::set() const
{
	return this->_set;
}

void MessagesStickerSet::setSet(StickerSet* set) 
{
	if(this->_set == set)
		return;

	this->deleteChild(this->_set);
	this->_set = set;

	if(this->_set)
		this->_set->setParent(this);

	emit setChanged();
}

const TLVector<StickerPack*>& MessagesStickerSet::packs() const
{
	return this->_packs;
}

void MessagesStickerSet::setPacks(const TLVector<StickerPack*>& packs) 
{
	if(this->_packs == packs)
		return;

	this->_packs = packs;
	emit packsChanged();
}

const TLVector<Document*>& MessagesStickerSet::documents() const
{
	return this->_documents;
}

void MessagesStickerSet::setDocuments(const TLVector<Document*>& documents) 
{
	if(this->_documents == documents)
		return;

	this->_documents = documents;
	emit documentsChanged();
}

