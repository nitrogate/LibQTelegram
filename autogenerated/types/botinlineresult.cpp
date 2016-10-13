// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "botinlineresult.h"


BotInlineResult::BotInlineResult(QObject* parent) : TelegramObject(parent)
{
	this->_flags = 0;
	this->_w = 0;
	this->_h = 0;
	this->_duration = 0;
	this->_send_message = NULL;
	this->_photo = NULL;
	this->_document = NULL;
}

void BotInlineResult::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == BotInlineResult::CtorBotInlineResult) ||
		 (this->_constructorid == BotInlineResult::CtorBotInlineMediaResult));
	
	if(this->_constructorid == BotInlineResult::CtorBotInlineResult)
	{
		this->_flags = mtstream->readTLInt();
		this->_id = mtstream->readTLString();
		this->_type = mtstream->readTLString();
		if(IS_FLAG_SET(this->_flags, 1))
			this->_title = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 2))
			this->_description = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 3))
			this->_url = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 4))
			this->_thumb_url = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 5))
			this->_content_url = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 5))
			this->_content_type = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 6))
			this->_w = mtstream->readTLInt();
		
		if(IS_FLAG_SET(this->_flags, 6))
			this->_h = mtstream->readTLInt();
		
		if(IS_FLAG_SET(this->_flags, 7))
			this->_duration = mtstream->readTLInt();
		
		TLInt send_message_ctor = mtstream->peekTLConstructor();
		
		if(send_message_ctor != TLTypes::Null)
		{
			this->resetTLType<BotInlineMessage>(&this->_send_message);
			this->_send_message->read(mtstream);
		}
		else
		{
			this->nullTLType<BotInlineMessage>(&this->_send_message);
			mtstream->readTLConstructor(); // Skip Null
		}
	}
	else if(this->_constructorid == BotInlineResult::CtorBotInlineMediaResult)
	{
		this->_flags = mtstream->readTLInt();
		this->_id = mtstream->readTLString();
		this->_type = mtstream->readTLString();
		if(IS_FLAG_SET(this->_flags, 0))
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
		
		if(IS_FLAG_SET(this->_flags, 1))
		{
			TLInt document_ctor = mtstream->peekTLConstructor();
			
			if(document_ctor != TLTypes::Null)
			{
				this->resetTLType<Document>(&this->_document);
				this->_document->read(mtstream);
			}
			else
			{
				this->nullTLType<Document>(&this->_document);
				mtstream->readTLConstructor(); // Skip Null
			}
		}
		
		if(IS_FLAG_SET(this->_flags, 2))
			this->_title = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 3))
			this->_description = mtstream->readTLString();
		
		TLInt send_message_ctor = mtstream->peekTLConstructor();
		
		if(send_message_ctor != TLTypes::Null)
		{
			this->resetTLType<BotInlineMessage>(&this->_send_message);
			this->_send_message->read(mtstream);
		}
		else
		{
			this->nullTLType<BotInlineMessage>(&this->_send_message);
			mtstream->readTLConstructor(); // Skip Null
		}
	}
}

void BotInlineResult::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == BotInlineResult::CtorBotInlineResult) ||
		 (this->_constructorid == BotInlineResult::CtorBotInlineMediaResult));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == BotInlineResult::CtorBotInlineResult)
	{
		mtstream->writeTLInt(this->_flags);
		mtstream->writeTLString(this->_id);
		mtstream->writeTLString(this->_type);
		if(IS_FLAG_SET(this->_flags, 1))
			mtstream->writeTLString(this->_title);
		
		if(IS_FLAG_SET(this->_flags, 2))
			mtstream->writeTLString(this->_description);
		
		if(IS_FLAG_SET(this->_flags, 3))
			mtstream->writeTLString(this->_url);
		
		if(IS_FLAG_SET(this->_flags, 4))
			mtstream->writeTLString(this->_thumb_url);
		
		if(IS_FLAG_SET(this->_flags, 5))
			mtstream->writeTLString(this->_content_url);
		
		if(IS_FLAG_SET(this->_flags, 5))
			mtstream->writeTLString(this->_content_type);
		
		if(IS_FLAG_SET(this->_flags, 6))
			mtstream->writeTLInt(this->_w);
		
		if(IS_FLAG_SET(this->_flags, 6))
			mtstream->writeTLInt(this->_h);
		
		if(IS_FLAG_SET(this->_flags, 7))
			mtstream->writeTLInt(this->_duration);
		
		if(this->_send_message != NULL)
			this->_send_message->write(mtstream);
		else
			mtstream->writeTLConstructor(TLTypes::Null);
	}
	else if(this->_constructorid == BotInlineResult::CtorBotInlineMediaResult)
	{
		mtstream->writeTLInt(this->_flags);
		mtstream->writeTLString(this->_id);
		mtstream->writeTLString(this->_type);
		if(IS_FLAG_SET(this->_flags, 0))
		{
			if(this->_photo != NULL)
				this->_photo->write(mtstream);
			else
				mtstream->writeTLConstructor(TLTypes::Null);
		}
		
		if(IS_FLAG_SET(this->_flags, 1))
		{
			if(this->_document != NULL)
				this->_document->write(mtstream);
			else
				mtstream->writeTLConstructor(TLTypes::Null);
		}
		
		if(IS_FLAG_SET(this->_flags, 2))
			mtstream->writeTLString(this->_title);
		
		if(IS_FLAG_SET(this->_flags, 3))
			mtstream->writeTLString(this->_description);
		
		if(this->_send_message != NULL)
			this->_send_message->write(mtstream);
		else
			mtstream->writeTLConstructor(TLTypes::Null);
	}
}

void BotInlineResult::compileFlags() 
{
	this->_flags = 0;
	
	if(this->_constructorid == BotInlineResult::CtorBotInlineResult)
	{
		if(!this->_title.isEmpty())
			SET_FLAG_BIT(this->_flags, 1);
		if(!this->_description.isEmpty())
			SET_FLAG_BIT(this->_flags, 2);
		if(!this->_url.isEmpty())
			SET_FLAG_BIT(this->_flags, 3);
		if(!this->_thumb_url.isEmpty())
			SET_FLAG_BIT(this->_flags, 4);
		if(!this->_content_url.isEmpty())
			SET_FLAG_BIT(this->_flags, 5);
		if(!this->_content_type.isEmpty())
			SET_FLAG_BIT(this->_flags, 5);
		if(this->_w)
			SET_FLAG_BIT(this->_flags, 6);
		if(this->_h)
			SET_FLAG_BIT(this->_flags, 6);
		if(this->_duration)
			SET_FLAG_BIT(this->_flags, 7);
	}
	else if(this->_constructorid == BotInlineResult::CtorBotInlineMediaResult)
	{
		if(this->_photo)
			SET_FLAG_BIT(this->_flags, 0);
		if(this->_document)
			SET_FLAG_BIT(this->_flags, 1);
		if(!this->_title.isEmpty())
			SET_FLAG_BIT(this->_flags, 2);
		if(!this->_description.isEmpty())
			SET_FLAG_BIT(this->_flags, 3);
	}
}

TLInt BotInlineResult::flags() const
{
	return this->_flags;
}

void BotInlineResult::setFlags(TLInt flags) 
{
	if(this->_flags == flags)
		return;

	this->_flags = flags;
	emit flagsChanged();
}

TLString BotInlineResult::id() const
{
	return this->_id;
}

void BotInlineResult::setId(TLString id) 
{
	if(this->_id == id)
		return;

	this->_id = id;
	emit idChanged();
}

TLString BotInlineResult::type() const
{
	return this->_type;
}

void BotInlineResult::setType(TLString type) 
{
	if(this->_type == type)
		return;

	this->_type = type;
	emit typeChanged();
}

TLString BotInlineResult::title() const
{
	return this->_title;
}

void BotInlineResult::setTitle(TLString title) 
{
	if(this->_title == title)
		return;

	this->_title = title;
	emit titleChanged();
}

TLString BotInlineResult::description() const
{
	return this->_description;
}

void BotInlineResult::setDescription(TLString description) 
{
	if(this->_description == description)
		return;

	this->_description = description;
	emit descriptionChanged();
}

TLString BotInlineResult::url() const
{
	return this->_url;
}

void BotInlineResult::setUrl(TLString url) 
{
	if(this->_url == url)
		return;

	this->_url = url;
	emit urlChanged();
}

TLString BotInlineResult::thumbUrl() const
{
	return this->_thumb_url;
}

void BotInlineResult::setThumbUrl(TLString thumb_url) 
{
	if(this->_thumb_url == thumb_url)
		return;

	this->_thumb_url = thumb_url;
	emit thumbUrlChanged();
}

TLString BotInlineResult::contentUrl() const
{
	return this->_content_url;
}

void BotInlineResult::setContentUrl(TLString content_url) 
{
	if(this->_content_url == content_url)
		return;

	this->_content_url = content_url;
	emit contentUrlChanged();
}

TLString BotInlineResult::contentType() const
{
	return this->_content_type;
}

void BotInlineResult::setContentType(TLString content_type) 
{
	if(this->_content_type == content_type)
		return;

	this->_content_type = content_type;
	emit contentTypeChanged();
}

TLInt BotInlineResult::w() const
{
	return this->_w;
}

void BotInlineResult::setW(TLInt w) 
{
	if(this->_w == w)
		return;

	this->_w = w;
	emit wChanged();
}

TLInt BotInlineResult::h() const
{
	return this->_h;
}

void BotInlineResult::setH(TLInt h) 
{
	if(this->_h == h)
		return;

	this->_h = h;
	emit hChanged();
}

TLInt BotInlineResult::duration() const
{
	return this->_duration;
}

void BotInlineResult::setDuration(TLInt duration) 
{
	if(this->_duration == duration)
		return;

	this->_duration = duration;
	emit durationChanged();
}

BotInlineMessage* BotInlineResult::sendMessage() const
{
	return this->_send_message;
}

void BotInlineResult::setSendMessage(BotInlineMessage* send_message) 
{
	if(this->_send_message == send_message)
		return;

	this->deleteChild(this->_send_message);
	this->_send_message = send_message;

	if(this->_send_message)
		this->_send_message->setParent(this);

	emit sendMessageChanged();
}

Photo* BotInlineResult::photo() const
{
	return this->_photo;
}

void BotInlineResult::setPhoto(Photo* photo) 
{
	if(this->_photo == photo)
		return;

	this->deleteChild(this->_photo);
	this->_photo = photo;

	if(this->_photo)
		this->_photo->setParent(this);

	emit photoChanged();
}

Document* BotInlineResult::document() const
{
	return this->_document;
}

void BotInlineResult::setDocument(Document* document) 
{
	if(this->_document == document)
		return;

	this->deleteChild(this->_document);
	this->_document = document;

	if(this->_document)
		this->_document->setParent(this);

	emit documentChanged();
}

