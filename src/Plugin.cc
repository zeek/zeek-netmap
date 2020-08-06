
#include "Plugin.h"
#include "Netmap.h"
#include <iosource/Component.h>

namespace plugin { namespace Zeek_Netmap { Plugin plugin; } }

using namespace plugin::Zeek_Netmap;

plugin::Configuration Plugin::Configure()
	{
	AddComponent(new ::iosource::PktSrcComponent("NetmapReader", "netmap", ::iosource::PktSrcComponent::LIVE, ::iosource::pktsrc::NetmapSource::InstantiateNetmap));
	AddComponent(new ::iosource::PktSrcComponent("NetmapReader", "vale", ::iosource::PktSrcComponent::LIVE, ::iosource::pktsrc::NetmapSource::InstantiateVale));

	plugin::Configuration config;
	config.name = "Zeek::Netmap";
	config.description = "Packet acquisition via Netmap";
	config.version.major = 1;
	config.version.minor = 0;
	return config;
	}
