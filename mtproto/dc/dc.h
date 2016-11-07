#ifndef DC_H
#define DC_H

#define QueryTimeout                 15000  // 15 seconds
#define AckTimeout                   16000  // 16 seconds
#define CloseDCTimeout                5000  //  5 seconds
#define CurrentDeltaTime(servertime) (QDateTime::currentDateTime().toTime_t() - servertime)

#include <QTimer>
#include <QHash>
#include "dcconnection.h"
#include "../../autogenerated/mtproto/decompiler/mtprotodecompiler.h"
#include "../mtprotoservicehandler.h"
#include "../mtprotorequest.h"
#include "../mtprotoreply.h"

class DC : public DCConnection
{
    Q_OBJECT

    public:
        explicit DC(const QString& address, qint16 port, int dcid, QObject *parent = 0);
        MTProtoRequest* lastRequest() const;
        void sendPlain(MTProtoStream* mtstream);
        void send(MTProtoRequest *req);
        void keepRequest(MTProtoRequest *req);
        MTProtoRequest* giveRequest();
        void addSessionRef();
        void removeSessionRef();

    protected:
        virtual void timerEvent(QTimerEvent *event);

    private:
        void freeOwnedRequests();
        void decompile(int direction, TLLong messageid, const QByteArray &body);
        void handleReply(const QByteArray& message);
        void assignMessageId(MTProtoRequest *req);
        void checkSyncronization(MTProtoReply* mtreply);
        TLInt generateContentMsgNo();
        TLInt getPacketLength();

    private slots:
        void repeatRequest(TLLong messageid);
        void handleReply(MTProtoReply* mtreply);
        void onAck(const TLVector<TLLong>& msgids);
        void onAckRequest(TLLong reqmsgid);
        void onDCFloodWait(int seconds);
        void onDCUnauthorized();
        void onDCReadyRead();
        void onDCConnected();

    signals:
        void authorizationReply(MTProtoReply* mtreply);
        void migrateDC(int fromdcid, int dcid);
        void floodWait(int seconds);
        void phoneCodeError(QString errormessage);
        void invalidPassword();
        void sessionPasswordNeeded();
        void unauthorized();

    private:
        QHash<TLLong, MTProtoRequest*> _pendingrequests; // Queries sent and waiting for ACKs
        MTProtoServiceHandler* _mtservicehandler;
        MTProtoDecompiler* _mtdecompiler;
        MTProtoRequest* _savedrequest;
        TLInt _lastpacketlen;
        TLInt _contentmsgno;
        TLLong _lastmsgid;
        int _dcid;
        int _ownedsessions;
        int _timcloseconnection;

    private:
        static TLLong _lastclientmsgid;
};

#endif // DC_H
