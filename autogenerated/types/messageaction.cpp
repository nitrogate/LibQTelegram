// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "messageaction.h"


MessageAction::MessageAction(QObject* parent) : TelegramObject(parent)
{
	this->_photo = NULL;
	this->_user_id = 0;
	this->_inviter_id = 0;
	this->_channel_id = 0;
	this->_chat_id = 0;
	this->_game_id = 0;
	this->_score = 0;
}

void MessageAction::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == MessageAction::CtorMessageActionEmpty) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatCreate) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatEditTitle) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatEditPhoto) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatDeletePhoto) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatAddUser) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatDeleteUser) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatJoinedByLink) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChannelCreate) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatMigrateTo) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChannelMigrateFrom) ||
		 (this->_constructorid == MessageAction::CtorMessageActionPinMessage) ||
		 (this->_constructorid == MessageAction::CtorMessageActionHistoryClear) ||
		 (this->_constructorid == MessageAction::CtorMessageActionGameScore));
	
	if(this->_constructorid == MessageAction::CtorMessageActionChatCreate)
	{
		this->_title = mtstream->readTLString();
		mtstream->readTLVector<TLInt>(this->_users, false);
	}
	else if(this->_constructorid == MessageAction::CtorMessageActionChatEditTitle)
		this->_title = mtstream->readTLString();
	else if(this->_constructorid == MessageAction::CtorMessageActionChatEditPhoto)
	{
		TLInt photo_ctor = mtstream->peekTLConstructor();
		
		if(photo_ctor != TLTypes::Null)
		{
			this->resetTLType<Photo>(&this->_photo);
			this->_photo->read(mtstream);
		}
		else
		{
			this->nullTLType<Photo>(&this->_photo);
			mtstream->readTLConstructor(); // Skip Null
		}
	}
	else if(this->_constructorid == MessageAction::CtorMessageActionChatAddUser)
		mtstream->readTLVector<TLInt>(this->_users, false);
	else if(this->_constructorid == MessageAction::CtorMessageActionChatDeleteUser)
		this->_user_id = mtstream->readTLInt();
	else if(this->_constructorid == MessageAction::CtorMessageActionChatJoinedByLink)
		this->_inviter_id = mtstream->readTLInt();
	else if(this->_constructorid == MessageAction::CtorMessageActionChannelCreate)
		this->_title = mtstream->readTLString();
	else if(this->_constructorid == MessageAction::CtorMessageActionChatMigrateTo)
		this->_channel_id = mtstream->readTLInt();
	else if(this->_constructorid == MessageAction::CtorMessageActionChannelMigrateFrom)
	{
		this->_title = mtstream->readTLString();
		this->_chat_id = mtstream->readTLInt();
	}
	else if(this->_constructorid == MessageAction::CtorMessageActionGameScore)
	{
		this->_game_id = mtstream->readTLLong();
		this->_score = mtstream->readTLInt();
	}
}

void MessageAction::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == MessageAction::CtorMessageActionEmpty) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatCreate) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatEditTitle) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatEditPhoto) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatDeletePhoto) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatAddUser) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatDeleteUser) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatJoinedByLink) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChannelCreate) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChatMigrateTo) ||
		 (this->_constructorid == MessageAction::CtorMessageActionChannelMigrateFrom) ||
		 (this->_constructorid == MessageAction::CtorMessageActionPinMessage) ||
		 (this->_constructorid == MessageAction::CtorMessageActionHistoryClear) ||
		 (this->_constructorid == MessageAction::CtorMessageActionGameScore));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == MessageAction::CtorMessageActionChatCreate)
	{
		mtstream->writeTLString(this->_title);
		mtstream->writeTLVector(this->_users, false);
	}
	else if(this->_constructorid == MessageAction::CtorMessageActionChatEditTitle)
		mtstream->writeTLString(this->_title);
	else if(this->_constructorid == MessageAction::CtorMessageActionChatEditPhoto)
	{
		if(this->_photo != NULL)
			this->_photo->write(mtstream);
		else
			mtstream->writeTLConstructor(TLTypes::Null);
	}
	else if(this->_constructorid == MessageAction::CtorMessageActionChatAddUser)
		mtstream->writeTLVector(this->_users, false);
	else if(this->_constructorid == MessageAction::CtorMessageActionChatDeleteUser)
		mtstream->writeTLInt(this->_user_id);
	else if(this->_constructorid == MessageAction::CtorMessageActionChatJoinedByLink)
		mtstream->writeTLInt(this->_inviter_id);
	else if(this->_constructorid == MessageAction::CtorMessageActionChannelCreate)
		mtstream->writeTLString(this->_title);
	else if(this->_constructorid == MessageAction::CtorMessageActionChatMigrateTo)
		mtstream->writeTLInt(this->_channel_id);
	else if(this->_constructorid == MessageAction::CtorMessageActionChannelMigrateFrom)
	{
		mtstream->writeTLString(this->_title);
		mtstream->writeTLInt(this->_chat_id);
	}
	else if(this->_constructorid == MessageAction::CtorMessageActionGameScore)
	{
		mtstream->writeTLLong(this->_game_id);
		mtstream->writeTLInt(this->_score);
	}
}

void MessageAction::compileFlags() 
{
	
}

TLString MessageAction::title() const
{
	return this->_title;
}

void MessageAction::setTitle(TLString title) 
{
	if(this->_title == title)
		return;

	this->_title = title;
	emit titleChanged();
}

const TLVector<TLInt>& MessageAction::users() const
{
	return this->_users;
}

void MessageAction::setUsers(const TLVector<TLInt>& users) 
{
	if(this->_users == users)
		return;

	this->_users = users;
	emit usersChanged();
}

Photo* MessageAction::photo() const
{
	return this->_photo;
}

void MessageAction::setPhoto(Photo* photo) 
{
	if(this->_photo == photo)
		return;

	this->deleteChild(this->_photo);
	this->_photo = photo;

	if(this->_photo)
		this->_photo->setParent(this);

	emit photoChanged();
}

TLInt MessageAction::userId() const
{
	return this->_user_id;
}

void MessageAction::setUserId(TLInt user_id) 
{
	if(this->_user_id == user_id)
		return;

	this->_user_id = user_id;
	emit userIdChanged();
}

TLInt MessageAction::inviterId() const
{
	return this->_inviter_id;
}

void MessageAction::setInviterId(TLInt inviter_id) 
{
	if(this->_inviter_id == inviter_id)
		return;

	this->_inviter_id = inviter_id;
	emit inviterIdChanged();
}

TLInt MessageAction::channelId() const
{
	return this->_channel_id;
}

void MessageAction::setChannelId(TLInt channel_id) 
{
	if(this->_channel_id == channel_id)
		return;

	this->_channel_id = channel_id;
	emit channelIdChanged();
}

TLInt MessageAction::chatId() const
{
	return this->_chat_id;
}

void MessageAction::setChatId(TLInt chat_id) 
{
	if(this->_chat_id == chat_id)
		return;

	this->_chat_id = chat_id;
	emit chatIdChanged();
}

TLLong MessageAction::gameId() const
{
	return this->_game_id;
}

void MessageAction::setGameId(TLLong game_id) 
{
	if(this->_game_id == game_id)
		return;

	this->_game_id = game_id;
	emit gameIdChanged();
}

TLInt MessageAction::score() const
{
	return this->_score;
}

void MessageAction::setScore(TLInt score) 
{
	if(this->_score == score)
		return;

	this->_score = score;
	emit scoreChanged();
}

