#include "qml_plugin.h"
#include <qqml.h>

#include "qsjsonlistmodel.h"
#include "qsuuid.h"
#include "qsyncableqmlwrapper.h"

template <typename T>
static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine) {
  Q_UNUSED(engine);
  Q_UNUSED(scriptEngine);

  T *object = new T();

  return object;
}

void QMLQsyncablePlugin::registerTypes(const char *uri) {
  // @uri com.mycompany.qmlcomponents
  Q_ASSERT(uri == QLatin1String("QSyncable"));

  qmlRegisterType<QSJsonListModel>("QSyncable", 1, 0, "JsonListModel");
  qmlRegisterSingletonType<QSUuid>("QSyncable", 1, 0, "Uuid", provider<QSUuid>);
  qmlRegisterSingletonType<QSyncableQmlWrapper>("QSyncable", 1, 0, "QSyncable",
                                                provider<QSyncableQmlWrapper>);
}
