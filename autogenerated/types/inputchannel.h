#ifndef INPUTCHANNEL_H
#define INPUTCHANNEL_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class InputChannel: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt channelId READ channelId WRITE setChannelId NOTIFY channelIdChanged)
	Q_PROPERTY(TLLong accessHash READ accessHash WRITE setAccessHash NOTIFY accessHashChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorInputChannelEmpty = 0xee8c1e86,
			CtorInputChannel = 0xafeb712e,
		};

	public:
		explicit InputChannel(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt channelId() const;
		void setChannelId(TLInt channel_id);
		TLLong accessHash() const;
		void setAccessHash(TLLong access_hash);

	signals:
		void channelIdChanged();
		void accessHashChanged();

	private:
		TLInt _channel_id;
		TLLong _access_hash;

};

#endif // INPUTCHANNEL_H
