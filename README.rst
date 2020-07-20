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
in the `apps/lb` directory of the NETMAP distribution. Make sure that you
instruct `lb` to split the packets into the same number of pipes that 
Zeek is configured to sniff.

Enjoy!
