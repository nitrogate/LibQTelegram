#ifndef CLIENTSYNCMANAGER_H
#define CLIENTSYNCMANAGER_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "types/updates.h"
#include "tltypes.h"
#include "types/update.h"
#include "types/updatesstate.h"
#include <QObject>

class ClientSyncManager: public QObject
{
	Q_OBJECT

	public:
		static void syncUpdate(Update* u, UpdatesState* updatestate);
		static void syncUpdates(Updates* u, UpdatesState* updatestate);

};

#endif // CLIENTSYNCMANAGER_H
