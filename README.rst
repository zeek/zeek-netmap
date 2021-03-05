Zeek::Netmap
===========

This plugin provides native `NETMAP
<https://github.com/luigirizzo/netmap>`_ support for Zeek as a
packet source.

Installation
------------

Follow NETMAP's instructions to get its kernel module and,
potentially, custom drivers installed.  Then install this plugin
through the Zeek Package Manager::

    # zkg install zeek/zeek-netmap

To use NETMAP, Zeek needs read and write access to ``/dev/netmap``. If
you give that permission to a user, you can run Zeek as non-root.

Usage
-----

Once installed, you can use NETMAP interfaces/ports by prefixing them
with either ``netmap::`` or ``vale::`` on the command line. For example,
to use NETMAP to monitor interface ``eth0``::

    zeek -i netmap::eth0

Netmap does not enable promiscuous mode on interfaces,
you'll have to do that yourself. For example, on Linux::

    ifconfig eth0 promisc

To use it in production with multiple Zeek processes, use a
configuration similar to this in node.cfg::

    [worker-1]
    type=worker
    host=localhost
    lb_method=custom
    lb_procs=<number of processes, like 16>
    interface=netmap::<interface name, like p2p1>

This will start up Zeek processes sniffing on NETMAP pipes attached to
the interface. In order to balance packets from the interface across 
those pipes you will need to run the tool named `lb` that is included
in the `apps/lb` directory of the NETMAP distribution. 

Make sure that you instruct `lb` to split the packets into the same number 
of pipes (this should match what you set as lb_procs) that Zeek is configured 
to sniff.

Setting up Zeek with Zeek::Netmap Plugin on FreeBSD
--------------------------------------

On FreeBSD 13+, the netmap tools are available in the latest source code.
Simply download the latest source code to get the app under 
`/usr/src/tools/tools/netmap`. Navigate to this directory and run
make to build all of the tools::

    # cd /usr/src/tools/tools/netmap/
    # make
    Building /usr/obj/usr/src/amd64.amd64/tools/tools/netmap/pkt-gen.o
    Building /usr/obj/usr/src/amd64.amd64/tools/tools/netmap/pkt-gen
    Building /usr/obj/usr/src/amd64.amd64/tools/tools/netmap/nmreplay.o
    Building /usr/obj/usr/src/amd64.amd64/tools/tools/netmap/nmreplay
    Building /usr/obj/usr/src/amd64.amd64/tools/tools/netmap/bridge.o
    Building /usr/obj/usr/src/amd64.amd64/tools/tools/netmap/bridge
    Building /usr/obj/usr/src/amd64.amd64/tools/tools/netmap/lb.o
    Building /usr/obj/usr/src/amd64.amd64/tools/tools/netmap/pkt_hash.o
    Building /usr/obj/usr/src/amd64.amd64/tools/tools/netmap/lb

You can move the lb binary to wherever you want. In the following example,
all of the netmap tools have been moved to /nsm/netmap. Running the following
`lb` command line will create a "zeek" interface, connected to interface `em0`
with 4 netmap pipes (note this is not a service, the lb binary must be forked
to the background or left running, which needs to be fixed)::

    /nsm/netmap/lb -i em0 -p zeek:4 &

Ensure the `em0` interface is in promiscuous mode before running this. With `lb`
running, use the following node.cfg to use 4 zeek processes to match 
the 4 netmap pipes::

    [worker-1]
    type=worker
    host=localhost
    lb_method=custom
    lb_procs=4
    interface=netmap::zeek

Then run `zeekctl deploy` and you should be up and running

Enjoy!
