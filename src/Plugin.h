
#ifndef ZEEK_NETMAP_PLUGIN_H
#define ZEEK_NETMAP_PLUGIN_H

#include <zeek/plugin/Plugin.h>
#include "zeek-compat.h"

namespace ZEEK_PLUGIN_NS {
namespace Zeek_Netmap {

class Plugin : public ZEEK_PLUGIN_NS::Plugin
{
protected:
	// Overridden from plugin::Plugin.
	virtual ZEEK_PLUGIN_NS::Configuration Configure();
};

extern Plugin plugin;

}
}

#endif
