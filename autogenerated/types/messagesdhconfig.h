#ifndef MESSAGESDHCONFIG_H
#define MESSAGESDHCONFIG_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class MessagesDhConfig: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLBytes random READ random WRITE setRandom NOTIFY randomChanged)
	Q_PROPERTY(TLInt g READ g WRITE setG NOTIFY gChanged)
	Q_PROPERTY(TLBytes p READ p WRITE setP NOTIFY pChanged)
	Q_PROPERTY(TLInt version READ version WRITE setVersion NOTIFY versionChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorMessagesDhConfigNotModified = 0xc0e24635,
			CtorMessagesDhConfig = 0x2c221edd,
		};

	public:
		explicit MessagesDhConfig(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLBytes random() const;
		void setRandom(TLBytes random);
		TLInt g() const;
		void setG(TLInt g);
		TLBytes p() const;
		void setP(TLBytes p);
		TLInt version() const;
		void setVersion(TLInt version);

	signals:
		void randomChanged();
		void gChanged();
		void pChanged();
		void versionChanged();

	private:
		TLBytes _random;
		TLInt _g;
		TLBytes _p;
		TLInt _version;

};

#endif // MESSAGESDHCONFIG_H
