// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "contactscontacts.h"


ContactsContacts::ContactsContacts(QObject* parent) : TelegramObject(parent)
{
	
}

void ContactsContacts::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == ContactsContacts::CtorContactsContactsNotModified) ||
		 (this->_constructorid == ContactsContacts::CtorContactsContacts));
	
	if(this->_constructorid == ContactsContacts::CtorContactsContacts)
	{
		mtstream->readTLVector<Contact>(this->_contacts, false, this);
		mtstream->readTLVector<User>(this->_users, false, this);
	}
}

void ContactsContacts::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == ContactsContacts::CtorContactsContactsNotModified) ||
		 (this->_constructorid == ContactsContacts::CtorContactsContacts));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == ContactsContacts::CtorContactsContacts)
	{
		mtstream->writeTLVector(this->_contacts, false);
		mtstream->writeTLVector(this->_users, false);
	}
}

void ContactsContacts::compileFlags() 
{
	
}

const TLVector<Contact*>& ContactsContacts::contacts() const
{
	return this->_contacts;
}

void ContactsContacts::setContacts(const TLVector<Contact*>& contacts) 
{
	if(this->_contacts == contacts)
		return;

	this->_contacts = contacts;
	emit contactsChanged();
}

const TLVector<User*>& ContactsContacts::users() const
{
	return this->_users;
}

void ContactsContacts::setUsers(const TLVector<User*>& users) 
{
	if(this->_users == users)
		return;

	this->_users = users;
	emit usersChanged();
}

