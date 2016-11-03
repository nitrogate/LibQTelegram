#ifndef NOTIFICATIONOBJECT_H
#define NOTIFICATIONOBJECT_H

#include <QObject>
#include "../../autogenerated/types/types.h"

class NotificationObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Dialog* dialog READ dialog NOTIFY dialogChanged)
    Q_PROPERTY(QString title READ title NOTIFY titleChanged)
    Q_PROPERTY(QString message READ message NOTIFY messageChanged)
    Q_PROPERTY(bool isCurrentDialog READ isCurrentDialog NOTIFY isCurrentDialogChanged)

    public:
        explicit NotificationObject(QObject *parent = 0);
        Dialog* dialog() const;
        const QString& title() const;
        const QString& message() const;
        bool isCurrentDialog() const;
        void setDialog(Dialog* dialog);
        void setTitle(const QString& title);
        void setMessage(const QString& message);
        void setIsCurrentDialog(bool iscurrentdialog);

    signals:
        void dialogChanged();
        void titleChanged();
        void messageChanged();
        void isCurrentDialogChanged();

    private:
        Dialog* _dialog;
        QString _title;
        QString _message;
        bool _iscurrentdialog;
};

#endif // NOTIFICATIONOBJECT_H