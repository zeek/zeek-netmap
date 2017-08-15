Bro::Netmap
===========

This plugin provides native `Netmap
<http://info.iet.unipi.it/~luigi/netmap>`_ support for Bro as a
packet source.

Installation
------------

Follow Netmap's instructions to get its kernel module and,
potentially, custom drivers installed. The following will then compile
and install the Netmap plugin alongside Bro::

    # ./configure && make && make install

If everything built and installed correctly, you should see this::

    # bro -N Bro::Netmap
    Bro::Netmap - Packet acquisition via Netmap (dynamic, version 1.0)

To use Netmap, Bro needs read and write access to ``/dev/netmap``. If
you give that permission to a user, you can run Bro as non-root.

Usage
-----

Once installed, you can use Netmap interfaces/ports by prefixing them
with either ``netmap::`` or ``vale::`` on the command line. For example,
to use Netmap to monitor interface ``eth0``::

    bro -i netmap::eth0

Netmap does not enable promiscuous mode on interfaces,
you'll have to do that yourself. For example, on Linux::

    ifconfig eth0 promisc

To use it in production with multiple Bro processes, use a
configuration similar to this in node.cfg::

    [worker-1]
    type=worker
    host=localhost
    lb_method=custom
    lb_procs=<number of processes, like 16>
    interface=netmap::<interface name, like p2p1>

This will start up Bro processes sniffing on netmap pipes attached to
the interface. In order to balance packets from the interface across 
those pipes you will need to run the tool named `lb` that is included
in the `apps/lb` directory of the Netmap distribution. Make sure that you
instruct `lb` to split the packets into the same number of pipes that 
Bro is configured to sniff.

Enjoy!
