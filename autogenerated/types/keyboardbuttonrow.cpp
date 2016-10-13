// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "keyboardbuttonrow.h"


KeyboardButtonRow::KeyboardButtonRow(QObject* parent) : TelegramObject(parent)
{
	this->_constructorid = KeyboardButtonRow::CtorKeyboardButtonRow;
}

void KeyboardButtonRow::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == KeyboardButtonRow::CtorKeyboardButtonRow));
	
	if(this->_constructorid == KeyboardButtonRow::CtorKeyboardButtonRow)
		mtstream->readTLVector<KeyboardButton>(this->_buttons, false, this);
}

void KeyboardButtonRow::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == KeyboardButtonRow::CtorKeyboardButtonRow));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == KeyboardButtonRow::CtorKeyboardButtonRow)
		mtstream->writeTLVector(this->_buttons, false);
}

void KeyboardButtonRow::compileFlags() 
{
	
}

const TLVector<KeyboardButton*>& KeyboardButtonRow::buttons() const
{
	return this->_buttons;
}

void KeyboardButtonRow::setButtons(const TLVector<KeyboardButton*>& buttons) 
{
	if(this->_buttons == buttons)
		return;

	this->_buttons = buttons;
	emit buttonsChanged();
}

