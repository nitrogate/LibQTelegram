// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "replymarkup.h"


ReplyMarkup::ReplyMarkup(QObject* parent) : TelegramObject(parent)
{
	this->_flags = 0;
	this->_is_selective = false;
	this->_is_single_use = false;
	this->_is_resize = false;
}

void ReplyMarkup::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == ReplyMarkup::CtorReplyKeyboardHide) ||
		 (this->_constructorid == ReplyMarkup::CtorReplyKeyboardForceReply) ||
		 (this->_constructorid == ReplyMarkup::CtorReplyKeyboardMarkup) ||
		 (this->_constructorid == ReplyMarkup::CtorReplyInlineMarkup));
	
	if(this->_constructorid == ReplyMarkup::CtorReplyKeyboardHide)
	{
		this->_flags = mtstream->readTLInt();
		this->_is_selective = IS_FLAG_SET(this->_flags, 2);
	}
	else if(this->_constructorid == ReplyMarkup::CtorReplyKeyboardForceReply)
	{
		this->_flags = mtstream->readTLInt();
		this->_is_single_use = IS_FLAG_SET(this->_flags, 1);
		this->_is_selective = IS_FLAG_SET(this->_flags, 2);
	}
	else if(this->_constructorid == ReplyMarkup::CtorReplyKeyboardMarkup)
	{
		this->_flags = mtstream->readTLInt();
		this->_is_resize = IS_FLAG_SET(this->_flags, 0);
		this->_is_single_use = IS_FLAG_SET(this->_flags, 1);
		this->_is_selective = IS_FLAG_SET(this->_flags, 2);
		mtstream->readTLVector<KeyboardButtonRow>(this->_rows, false, this);
	}
	else if(this->_constructorid == ReplyMarkup::CtorReplyInlineMarkup)
		mtstream->readTLVector<KeyboardButtonRow>(this->_rows, false, this);
}

void ReplyMarkup::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == ReplyMarkup::CtorReplyKeyboardHide) ||
		 (this->_constructorid == ReplyMarkup::CtorReplyKeyboardForceReply) ||
		 (this->_constructorid == ReplyMarkup::CtorReplyKeyboardMarkup) ||
		 (this->_constructorid == ReplyMarkup::CtorReplyInlineMarkup));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == ReplyMarkup::CtorReplyKeyboardHide)
		mtstream->writeTLInt(this->_flags);
	else if(this->_constructorid == ReplyMarkup::CtorReplyKeyboardForceReply)
		mtstream->writeTLInt(this->_flags);
	else if(this->_constructorid == ReplyMarkup::CtorReplyKeyboardMarkup)
	{
		mtstream->writeTLInt(this->_flags);
		mtstream->writeTLVector(this->_rows, false);
	}
	else if(this->_constructorid == ReplyMarkup::CtorReplyInlineMarkup)
		mtstream->writeTLVector(this->_rows, false);
}

void ReplyMarkup::compileFlags() 
{
	this->_flags = 0;
	
	if(this->_constructorid == ReplyMarkup::CtorReplyKeyboardHide)
	{
		if(this->_is_selective)
			SET_FLAG_BIT(this->_flags, 2);
	}
	else if(this->_constructorid == ReplyMarkup::CtorReplyKeyboardForceReply)
	{
		if(this->_is_single_use)
			SET_FLAG_BIT(this->_flags, 1);
		if(this->_is_selective)
			SET_FLAG_BIT(this->_flags, 2);
	}
	else if(this->_constructorid == ReplyMarkup::CtorReplyKeyboardMarkup)
	{
		if(this->_is_resize)
			SET_FLAG_BIT(this->_flags, 0);
		if(this->_is_single_use)
			SET_FLAG_BIT(this->_flags, 1);
		if(this->_is_selective)
			SET_FLAG_BIT(this->_flags, 2);
	}
}

TLInt ReplyMarkup::flags() const
{
	return this->_flags;
}

void ReplyMarkup::setFlags(TLInt flags) 
{
	if(this->_flags == flags)
		return;

	this->_flags = flags;
	emit flagsChanged();
}

TLTrue ReplyMarkup::isSelective() const
{
	return this->_is_selective;
}

void ReplyMarkup::setIsSelective(TLTrue is_selective) 
{
	if(this->_is_selective == is_selective)
		return;

	this->_is_selective = is_selective;
	emit isSelectiveChanged();
}

TLTrue ReplyMarkup::isSingleUse() const
{
	return this->_is_single_use;
}

void ReplyMarkup::setIsSingleUse(TLTrue is_single_use) 
{
	if(this->_is_single_use == is_single_use)
		return;

	this->_is_single_use = is_single_use;
	emit isSingleUseChanged();
}

TLTrue ReplyMarkup::isResize() const
{
	return this->_is_resize;
}

void ReplyMarkup::setIsResize(TLTrue is_resize) 
{
	if(this->_is_resize == is_resize)
		return;

	this->_is_resize = is_resize;
	emit isResizeChanged();
}

const TLVector<KeyboardButtonRow*>& ReplyMarkup::rows() const
{
	return this->_rows;
}

void ReplyMarkup::setRows(const TLVector<KeyboardButtonRow*>& rows) 
{
	if(this->_rows == rows)
		return;

	this->_rows = rows;
	emit rowsChanged();
}

