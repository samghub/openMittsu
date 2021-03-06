#ifndef OPENMITTSU_UTILITY_QOBJECTCONNECTIONMACRO_H_
#define OPENMITTSU_UTILITY_QOBJECTCONNECTIONMACRO_H_

#include <QObject>
#include "exceptions/InternalErrorException.h"

#define OPENMITTSU_CONNECT(sourceObjectPtr, sourceSignal, targetObjectPtr, targetSlot) do { \
	if (!QObject::connect(sourceObjectPtr, SIGNAL(sourceSignal), targetObjectPtr, SLOT(targetSlot))) { \
		throw InternalErrorException() << "Could not connect signal " << #sourceObjectPtr << "->" << #sourceSignal << " to " << #targetSlot << " in " << __FILE__ << "  at line " << __LINE__ << "."; \
	} \
} while (false)

#define OPENMITTSU_CONNECT_QUEUED(sourceObjectPtr, sourceSignal, targetObjectPtr, targetSlot) do { \
	if (!QObject::connect(sourceObjectPtr, SIGNAL(sourceSignal), targetObjectPtr, SLOT(targetSlot), Qt::QueuedConnection)) { \
		throw InternalErrorException() << "Could not connect signal " << #sourceObjectPtr << "->" << #sourceSignal << " to " << #targetSlot << " in " << __FILE__ << "  at line " << __LINE__ << "."; \
	} \
} while (false)

#define OPENMITTSU_DISCONNECT(sourceObjectPtr, sourceSignal, targetObjectPtr, targetSlot) do { \
	if (!QObject::disconnect(sourceObjectPtr, SIGNAL(sourceSignal), targetObjectPtr, SLOT(targetSlot))) { \
		throw InternalErrorException() << "Could not disconnect signal " << #sourceObjectPtr << "->" << #sourceSignal << " to " << #targetSlot << " in " << __FILE__ << "  at line " << __LINE__ << "."; \
	} \
} while (false)

#endif // OPENMITTSU_UTILITY_QOBJECTCONNECTIONMACRO_H_