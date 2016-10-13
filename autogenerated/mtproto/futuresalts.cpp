// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "futuresalts.h"


FutureSalts::FutureSalts(QObject* parent) : TelegramObject(parent)
{
	this->_req_msg_id = 0;
	this->_now = 0;
	this->_constructorid = FutureSalts::CtorFutureSalts;
}

void FutureSalts::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == FutureSalts::CtorFutureSalts));
	
	if(this->_constructorid == FutureSalts::CtorFutureSalts)
	{
		this->_req_msg_id = mtstream->readTLLong();
		this->_now = mtstream->readTLInt();
		mtstream->readTLVector<FutureSalt>(this->_salts, false, this);
	}
}

void FutureSalts::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == FutureSalts::CtorFutureSalts));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == FutureSalts::CtorFutureSalts)
	{
		mtstream->writeTLLong(this->_req_msg_id);
		mtstream->writeTLInt(this->_now);
		mtstream->writeTLVector(this->_salts, false);
	}
}

void FutureSalts::compileFlags() 
{
	
}

TLLong FutureSalts::reqMsgId() const
{
	return this->_req_msg_id;
}

void FutureSalts::setReqMsgId(TLLong req_msg_id) 
{
	if(this->_req_msg_id == req_msg_id)
		return;

	this->_req_msg_id = req_msg_id;
	emit reqMsgIdChanged();
}

TLInt FutureSalts::now() const
{
	return this->_now;
}

void FutureSalts::setNow(TLInt now) 
{
	if(this->_now == now)
		return;

	this->_now = now;
	emit nowChanged();
}

const TLVector<FutureSalt*>& FutureSalts::salts() const
{
	return this->_salts;
}

void FutureSalts::setSalts(const TLVector<FutureSalt*>& salts) 
{
	if(this->_salts == salts)
		return;

	this->_salts = salts;
	emit saltsChanged();
}

