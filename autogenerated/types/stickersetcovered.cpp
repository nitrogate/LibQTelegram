// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "stickersetcovered.h"


StickerSetCovered::StickerSetCovered(QObject* parent) : TelegramObject(parent)
{
	this->_set = NULL;
	this->_cover = NULL;
}

void StickerSetCovered::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == StickerSetCovered::CtorStickerSetCovered) ||
		 (this->_constructorid == StickerSetCovered::CtorStickerSetMultiCovered));
	
	if(this->_constructorid == StickerSetCovered::CtorStickerSetCovered)
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
		
		TLInt cover_ctor = mtstream->peekTLConstructor();
		
		if(cover_ctor != TLTypes::Null)
		{
			this->resetTLType<Document>(&this->_cover);
			this->_cover->read(mtstream);
		}
		else
		{
			this->nullTLType<Document>(&this->_cover);
			mtstream->readTLConstructor(); // Skip Null
		}
	}
	else if(this->_constructorid == StickerSetCovered::CtorStickerSetMultiCovered)
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
		
		mtstream->readTLVector<Document>(this->_covers, false, this);
	}
}

void StickerSetCovered::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == StickerSetCovered::CtorStickerSetCovered) ||
		 (this->_constructorid == StickerSetCovered::CtorStickerSetMultiCovered));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == StickerSetCovered::CtorStickerSetCovered)
	{
		if(this->_set != NULL)
			this->_set->write(mtstream);
		else
			mtstream->writeTLConstructor(TLTypes::Null);
		
		if(this->_cover != NULL)
			this->_cover->write(mtstream);
		else
			mtstream->writeTLConstructor(TLTypes::Null);
	}
	else if(this->_constructorid == StickerSetCovered::CtorStickerSetMultiCovered)
	{
		if(this->_set != NULL)
			this->_set->write(mtstream);
		else
			mtstream->writeTLConstructor(TLTypes::Null);
		
		mtstream->writeTLVector(this->_covers, false);
	}
}

void StickerSetCovered::compileFlags() 
{
	
}

StickerSet* StickerSetCovered::set() const
{
	return this->_set;
}

void StickerSetCovered::setSet(StickerSet* set) 
{
	if(this->_set == set)
		return;

	this->deleteChild(this->_set);
	this->_set = set;

	if(this->_set)
		this->_set->setParent(this);

	emit setChanged();
}

Document* StickerSetCovered::cover() const
{
	return this->_cover;
}

void StickerSetCovered::setCover(Document* cover) 
{
	if(this->_cover == cover)
		return;

	this->deleteChild(this->_cover);
	this->_cover = cover;

	if(this->_cover)
		this->_cover->setParent(this);

	emit coverChanged();
}

const TLVector<Document*>& StickerSetCovered::covers() const
{
	return this->_covers;
}

void StickerSetCovered::setCovers(const TLVector<Document*>& covers) 
{
	if(this->_covers == covers)
		return;

	this->_covers = covers;
	emit coversChanged();
}

