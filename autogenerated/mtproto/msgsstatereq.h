#ifndef MSGSSTATEREQ_H
#define MSGSSTATEREQ_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class MsgsStateReq: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLVector<TLLong> msgIds READ msgIds WRITE setMsgIds NOTIFY msgIdsChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorMsgsStateReq = 0xda69fb52,
		};

	public:
		explicit MsgsStateReq(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		const TLVector<TLLong>& msgIds() const;
		void setMsgIds(const TLVector<TLLong>& msg_ids);

	signals:
		void msgIdsChanged();

	private:
		TLVector<TLLong> _msg_ids;

};

#endif // MSGSSTATEREQ_H
