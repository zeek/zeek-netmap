
#ifndef ZEEK_PLUGIN_ZEEK_NETMAP
#define ZEEK_PLUGIN_ZEEK_NETMAP

#include <plugin/Plugin.h>

namespace plugin {
namespace Zeek_Netmap {

class Plugin : public ::plugin::Plugin
{
protected:
	// Overridden from plugin::Plugin.
	virtual plugin::Configuration Configure();
};

extern Plugin plugin;

}
}

#endif
