#ifndef FILELOCATION_H
#define FILELOCATION_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class FileLocation: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLLong volumeId READ volumeId WRITE setVolumeId NOTIFY volumeIdChanged)
	Q_PROPERTY(TLInt localId READ localId WRITE setLocalId NOTIFY localIdChanged)
	Q_PROPERTY(TLLong secret READ secret WRITE setSecret NOTIFY secretChanged)
	Q_PROPERTY(TLInt dcId READ dcId WRITE setDcId NOTIFY dcIdChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorFileLocationUnavailable = 0x7c596b46,
			CtorFileLocation = 0x53d69076,
		};

	public:
		explicit FileLocation(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLLong volumeId() const;
		void setVolumeId(TLLong volume_id);
		TLInt localId() const;
		void setLocalId(TLInt local_id);
		TLLong secret() const;
		void setSecret(TLLong secret);
		TLInt dcId() const;
		void setDcId(TLInt dc_id);

	signals:
		void volumeIdChanged();
		void localIdChanged();
		void secretChanged();
		void dcIdChanged();

	private:
		TLLong _volume_id;
		TLInt _local_id;
		TLLong _secret;
		TLInt _dc_id;

};

#endif // FILELOCATION_H
