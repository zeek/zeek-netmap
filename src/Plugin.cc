#include <zeek/iosource/Component.h>

#include "Plugin.h"
#include "Netmap.h"

namespace ZEEK_PLUGIN_NS { namespace Zeek_Netmap { Plugin plugin; } }

using namespace ZEEK_PLUGIN_NS::Zeek_Netmap;
using namespace ZEEK_IOSOURCE_NS;

ZEEK_PLUGIN_NS::Configuration Plugin::Configure()
	{
	AddComponent(new PktSrcComponent("NetmapReader", "netmap", PktSrcComponent::LIVE,
					 pktsrc::NetmapSource::InstantiateNetmap));
	AddComponent(new PktSrcComponent("NetmapReader", "vale", PktSrcComponent::LIVE,
					 pktsrc::NetmapSource::InstantiateVale));

	ZEEK_PLUGIN_NS::Configuration config;
	config.name = "Zeek::Netmap";
	config.description = "Packet acquisition via Netmap";
	config.version.major = 1;
	config.version.minor = 0;
	return config;
	}
