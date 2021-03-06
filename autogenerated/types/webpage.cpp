// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "webpage.h"


WebPage::WebPage(QObject* parent) : TelegramObject(parent)
{
	this->_id = 0;
	this->_date = 0;
	this->_flags = 0;
	this->_photo = NULL;
	this->_embed_width = 0;
	this->_embed_height = 0;
	this->_duration = 0;
	this->_document = NULL;
}

void WebPage::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == WebPage::CtorWebPageEmpty) ||
		 (this->_constructorid == WebPage::CtorWebPagePending) ||
		 (this->_constructorid == WebPage::CtorWebPage));
	
	if(this->_constructorid == WebPage::CtorWebPageEmpty)
		this->_id = mtstream->readTLLong();
	else if(this->_constructorid == WebPage::CtorWebPagePending)
	{
		this->_id = mtstream->readTLLong();
		this->_date = mtstream->readTLInt();
	}
	else if(this->_constructorid == WebPage::CtorWebPage)
	{
		this->_flags = mtstream->readTLInt();
		this->_id = mtstream->readTLLong();
		this->_url = mtstream->readTLString();
		this->_display_url = mtstream->readTLString();
		if(IS_FLAG_SET(this->_flags, 0))
			this->_type = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 1))
			this->_site_name = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 2))
			this->_title = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 3))
			this->_description = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 4))
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
		
		if(IS_FLAG_SET(this->_flags, 5))
			this->_embed_url = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 5))
			this->_embed_type = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 6))
			this->_embed_width = mtstream->readTLInt();
		
		if(IS_FLAG_SET(this->_flags, 6))
			this->_embed_height = mtstream->readTLInt();
		
		if(IS_FLAG_SET(this->_flags, 7))
			this->_duration = mtstream->readTLInt();
		
		if(IS_FLAG_SET(this->_flags, 8))
			this->_author = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 9))
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
	}
}

void WebPage::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == WebPage::CtorWebPageEmpty) ||
		 (this->_constructorid == WebPage::CtorWebPagePending) ||
		 (this->_constructorid == WebPage::CtorWebPage));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == WebPage::CtorWebPageEmpty)
		mtstream->writeTLLong(this->_id);
	else if(this->_constructorid == WebPage::CtorWebPagePending)
	{
		mtstream->writeTLLong(this->_id);
		mtstream->writeTLInt(this->_date);
	}
	else if(this->_constructorid == WebPage::CtorWebPage)
	{
		mtstream->writeTLInt(this->_flags);
		mtstream->writeTLLong(this->_id);
		mtstream->writeTLString(this->_url);
		mtstream->writeTLString(this->_display_url);
		if(IS_FLAG_SET(this->_flags, 0))
			mtstream->writeTLString(this->_type);
		
		if(IS_FLAG_SET(this->_flags, 1))
			mtstream->writeTLString(this->_site_name);
		
		if(IS_FLAG_SET(this->_flags, 2))
			mtstream->writeTLString(this->_title);
		
		if(IS_FLAG_SET(this->_flags, 3))
			mtstream->writeTLString(this->_description);
		
		if(IS_FLAG_SET(this->_flags, 4))
		{
			if(this->_photo != NULL)
				this->_photo->write(mtstream);
			else
				mtstream->writeTLConstructor(TLTypes::Null);
		}
		
		if(IS_FLAG_SET(this->_flags, 5))
			mtstream->writeTLString(this->_embed_url);
		
		if(IS_FLAG_SET(this->_flags, 5))
			mtstream->writeTLString(this->_embed_type);
		
		if(IS_FLAG_SET(this->_flags, 6))
			mtstream->writeTLInt(this->_embed_width);
		
		if(IS_FLAG_SET(this->_flags, 6))
			mtstream->writeTLInt(this->_embed_height);
		
		if(IS_FLAG_SET(this->_flags, 7))
			mtstream->writeTLInt(this->_duration);
		
		if(IS_FLAG_SET(this->_flags, 8))
			mtstream->writeTLString(this->_author);
		
		if(IS_FLAG_SET(this->_flags, 9))
		{
			if(this->_document != NULL)
				this->_document->write(mtstream);
			else
				mtstream->writeTLConstructor(TLTypes::Null);
		}
	}
}

void WebPage::compileFlags() 
{
	this->_flags = 0;
	
	if(this->_constructorid == WebPage::CtorWebPage)
	{
		if(!this->_type.isEmpty())
			SET_FLAG_BIT(this->_flags, 0);
		if(!this->_site_name.isEmpty())
			SET_FLAG_BIT(this->_flags, 1);
		if(!this->_title.isEmpty())
			SET_FLAG_BIT(this->_flags, 2);
		if(!this->_description.isEmpty())
			SET_FLAG_BIT(this->_flags, 3);
		if(this->_photo)
			SET_FLAG_BIT(this->_flags, 4);
		if(!this->_embed_url.isEmpty())
			SET_FLAG_BIT(this->_flags, 5);
		if(!this->_embed_type.isEmpty())
			SET_FLAG_BIT(this->_flags, 5);
		if(this->_embed_width)
			SET_FLAG_BIT(this->_flags, 6);
		if(this->_embed_height)
			SET_FLAG_BIT(this->_flags, 6);
		if(this->_duration)
			SET_FLAG_BIT(this->_flags, 7);
		if(!this->_author.isEmpty())
			SET_FLAG_BIT(this->_flags, 8);
		if(this->_document)
			SET_FLAG_BIT(this->_flags, 9);
	}
}

TLLong WebPage::id() const
{
	return this->_id;
}

void WebPage::setId(TLLong id) 
{
	if(this->_id == id)
		return;

	this->_id = id;
	emit idChanged();
}

TLInt WebPage::date() const
{
	return this->_date;
}

void WebPage::setDate(TLInt date) 
{
	if(this->_date == date)
		return;

	this->_date = date;
	emit dateChanged();
}

TLInt WebPage::flags() const
{
	return this->_flags;
}

void WebPage::setFlags(TLInt flags) 
{
	if(this->_flags == flags)
		return;

	this->_flags = flags;
	emit flagsChanged();
}

TLString WebPage::url() const
{
	return this->_url;
}

void WebPage::setUrl(TLString url) 
{
	if(this->_url == url)
		return;

	this->_url = url;
	emit urlChanged();
}

TLString WebPage::displayUrl() const
{
	return this->_display_url;
}

void WebPage::setDisplayUrl(TLString display_url) 
{
	if(this->_display_url == display_url)
		return;

	this->_display_url = display_url;
	emit displayUrlChanged();
}

TLString WebPage::type() const
{
	return this->_type;
}

void WebPage::setType(TLString type) 
{
	if(this->_type == type)
		return;

	this->_type = type;
	emit typeChanged();
}

TLString WebPage::siteName() const
{
	return this->_site_name;
}

void WebPage::setSiteName(TLString site_name) 
{
	if(this->_site_name == site_name)
		return;

	this->_site_name = site_name;
	emit siteNameChanged();
}

TLString WebPage::title() const
{
	return this->_title;
}

void WebPage::setTitle(TLString title) 
{
	if(this->_title == title)
		return;

	this->_title = title;
	emit titleChanged();
}

TLString WebPage::description() const
{
	return this->_description;
}

void WebPage::setDescription(TLString description) 
{
	if(this->_description == description)
		return;

	this->_description = description;
	emit descriptionChanged();
}

Photo* WebPage::photo() const
{
	return this->_photo;
}

void WebPage::setPhoto(Photo* photo) 
{
	if(this->_photo == photo)
		return;

	this->deleteChild(this->_photo);
	this->_photo = photo;

	if(this->_photo)
		this->_photo->setParent(this);

	emit photoChanged();
}

TLString WebPage::embedUrl() const
{
	return this->_embed_url;
}

void WebPage::setEmbedUrl(TLString embed_url) 
{
	if(this->_embed_url == embed_url)
		return;

	this->_embed_url = embed_url;
	emit embedUrlChanged();
}

TLString WebPage::embedType() const
{
	return this->_embed_type;
}

void WebPage::setEmbedType(TLString embed_type) 
{
	if(this->_embed_type == embed_type)
		return;

	this->_embed_type = embed_type;
	emit embedTypeChanged();
}

TLInt WebPage::embedWidth() const
{
	return this->_embed_width;
}

void WebPage::setEmbedWidth(TLInt embed_width) 
{
	if(this->_embed_width == embed_width)
		return;

	this->_embed_width = embed_width;
	emit embedWidthChanged();
}

TLInt WebPage::embedHeight() const
{
	return this->_embed_height;
}

void WebPage::setEmbedHeight(TLInt embed_height) 
{
	if(this->_embed_height == embed_height)
		return;

	this->_embed_height = embed_height;
	emit embedHeightChanged();
}

TLInt WebPage::duration() const
{
	return this->_duration;
}

void WebPage::setDuration(TLInt duration) 
{
	if(this->_duration == duration)
		return;

	this->_duration = duration;
	emit durationChanged();
}

TLString WebPage::author() const
{
	return this->_author;
}

void WebPage::setAuthor(TLString author) 
{
	if(this->_author == author)
		return;

	this->_author = author;
	emit authorChanged();
}

Document* WebPage::document() const
{
	return this->_document;
}

void WebPage::setDocument(Document* document) 
{
	if(this->_document == document)
		return;

	this->deleteChild(this->_document);
	this->_document = document;

	if(this->_document)
		this->_document->setParent(this);

	emit documentChanged();
}

