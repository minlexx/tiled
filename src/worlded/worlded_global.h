#ifndef WORLDED_GLOBAL_H
#define WORLDED_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WORLDED_LIBRARY)
#  define WORLDED_EXPORT Q_DECL_EXPORT
#else
#  define WORLDED_EXPORT Q_DECL_IMPORT
#endif

#endif // WORLDED_GLOBAL_H
