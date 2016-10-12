#ifndef FILECACHE_H
#define FILECACHE_H

#define FileCache_instance FileCache::instance()
#define FileCache_fileObject(obj) FileCache::instance()->fileObject(obj)

#include <QObject>
#include "../../autogenerated/types/types.h"
#include "../../objects/fileobject.h"

class FileCache : public QObject
{
    Q_OBJECT

    private:
        explicit FileCache(QObject *parent = 0);

    public:
        static FileCache* instance();
        FileObject* fileObject(TelegramObject* telegramobject);

    private:
        QString createFileId(FileLocation* filelocation);
        FileObject* fileObject(FileLocation* locthumbnail, FileLocation* locfile);

    private slots:
        void processQueue();

    private:
        QString _storagepath;
        QHash<QString, FileObject*> _filemap;
        QList<FileObject*> _queue;
        FileObject* _currentobject;

    private:
        static FileCache* _instance;
};

#endif // FILECACHE_H
