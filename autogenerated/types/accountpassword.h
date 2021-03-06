#ifndef ACCOUNTPASSWORD_H
#define ACCOUNTPASSWORD_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class AccountPassword: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLBytes newSalt READ newSalt WRITE setNewSalt NOTIFY newSaltChanged)
	Q_PROPERTY(TLString emailUnconfirmedPattern READ emailUnconfirmedPattern WRITE setEmailUnconfirmedPattern NOTIFY emailUnconfirmedPatternChanged)
	Q_PROPERTY(TLBytes currentSalt READ currentSalt WRITE setCurrentSalt NOTIFY currentSaltChanged)
	Q_PROPERTY(TLString hint READ hint WRITE setHint NOTIFY hintChanged)
	Q_PROPERTY(TLBool hasRecovery READ hasRecovery WRITE setHasRecovery NOTIFY hasRecoveryChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorAccountNoPassword = 0x96dabc18,
			CtorAccountPassword = 0x7c18141c,
		};

	public:
		explicit AccountPassword(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLBytes newSalt() const;
		void setNewSalt(TLBytes new_salt);
		TLString emailUnconfirmedPattern() const;
		void setEmailUnconfirmedPattern(TLString email_unconfirmed_pattern);
		TLBytes currentSalt() const;
		void setCurrentSalt(TLBytes current_salt);
		TLString hint() const;
		void setHint(TLString hint);
		TLBool hasRecovery() const;
		void setHasRecovery(TLBool has_recovery);

	signals:
		void newSaltChanged();
		void emailUnconfirmedPatternChanged();
		void currentSaltChanged();
		void hintChanged();
		void hasRecoveryChanged();

	private:
		TLBytes _new_salt;
		TLString _email_unconfirmed_pattern;
		TLBytes _current_salt;
		TLString _hint;
		TLBool _has_recovery;

};

#endif // ACCOUNTPASSWORD_H
