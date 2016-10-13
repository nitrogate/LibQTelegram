// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "contactstatus.h"


ContactStatus::ContactStatus(QObject* parent) : TelegramObject(parent)
{
	this->_user_id = 0;
	this->_status = NULL;
	this->_constructorid = ContactStatus::CtorContactStatus;
}

void ContactStatus::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == ContactStatus::CtorContactStatus));
	
	if(this->_constructorid == ContactStatus::CtorContactStatus)
	{
		this->_user_id = mtstream->readTLInt();
		TLInt status_ctor = mtstream->peekTLConstructor();
		
		if(status_ctor != TLTypes::Null)
		{
			this->resetTLType<UserStatus>(&this->_status);
			this->_status->read(mtstream);
		}
		else
		{
			this->nullTLType<UserStatus>(&this->_status);
			mtstream->readTLConstructor(); // Skip Null
		}
	}
}

void ContactStatus::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == ContactStatus::CtorContactStatus));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == ContactStatus::CtorContactStatus)
	{
		mtstream->writeTLInt(this->_user_id);
		if(this->_status != NULL)
			this->_status->write(mtstream);
		else
			mtstream->writeTLConstructor(TLTypes::Null);
	}
}

void ContactStatus::compileFlags() 
{
	
}

TLInt ContactStatus::userId() const
{
	return this->_user_id;
}

void ContactStatus::setUserId(TLInt user_id) 
{
	if(this->_user_id == user_id)
		return;

	this->_user_id = user_id;
	emit userIdChanged();
}

UserStatus* ContactStatus::status() const
{
	return this->_status;
}

void ContactStatus::setStatus(UserStatus* status) 
{
	if(this->_status == status)
		return;

	this->deleteChild(this->_status);
	this->_status = status;

	if(this->_status)
		this->_status->setParent(this);

	emit statusChanged();
}

