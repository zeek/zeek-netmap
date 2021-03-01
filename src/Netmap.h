// See the file "COPYING" in the main distribution directory for copyright.

#ifndef ZEEK_NETMAP_NETMAP_H
#define ZEEK_NETMAP_NETMAP_H

extern "C" {
#include <pcap.h>
#define NETMAP_WITH_LIBS
#include <net/netmap_user.h>
}

#include <zeek/iosource/PktSrc.h>
#include "zeek-compat.h"

namespace ZEEK_IOSOURCE_NS::pktsrc {

class NetmapSource : public iosource::PktSrc {
public:
	/**
	 * Constructor.
	 *
	 * path: Name of the interface to open (the netmap source doesn't
	 * support reading from files). The interface must be given without
	 * the "netmap" or "vale" prefix, that's left for \a kind.
	 *
	 * is_live: Must be true (the netmap source doesn't support offline
	 * operation).
	 *
	 * kind: Either "netmap" or "vale".
	 */
	NetmapSource(const std::string& path, bool is_live, const std::string& kind);

	/**
	 * Destructor.
	 */
	virtual ~NetmapSource();

	static PktSrc* InstantiateNetmap(const std::string& path, bool is_live);
	static PktSrc* InstantiateVale(const std::string& path, bool is_live);

protected:
	// PktSrc interface.
	virtual void Open();
	virtual void Close();
	virtual bool ExtractNextPacket(Packet* pkt);
	virtual void DoneWithPacket();
	virtual bool PrecompileFilter(int index, const std::string& filter);
	virtual bool SetFilter(int index);
	virtual void Statistics(Stats* stats);

private:
	Properties props;
	Stats stats;

	std::string kind;
	int current_filter;
	unsigned int num_discarded;
	struct nm_desc *nd;

	struct pcap_pkthdr current_hdr;
	struct pcap_pkthdr last_hdr;
	const u_char* last_data;
};

}

#endif
