#ifndef ZEEK_NETMAP_COMPAT_H
#define ZEEK_NETMAP_COMPAT_H

#include <zeek/zeek-config.h>

#if ZEEK_VERSION_NUMBER >= 30100 && ZEEK_VERSION_NUMBER < 30200

#define ZEEK_PLUGIN_NS plugin
#define ZEEK_IOSOURCE_NS iosource

#elif ZEEK_VERSION_NUMBER >= 30200 && ZEEK_VERSION_NUMBER < 40000

#define ZEEK_PLUGIN_NS zeek::plugin
#define ZEEK_IOSOURCE_NS iosource

#elif ZEEK_VERSION_NUMBER >= 40000

#define ZEEK_PLUGIN_NS zeek::plugin
#define ZEEK_IOSOURCE_NS zeek::iosource

#endif
#endif
