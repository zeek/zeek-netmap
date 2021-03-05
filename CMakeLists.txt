cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(ZeekPluginNetmap)

include(ZeekPlugin)

find_package(Netmap REQUIRED)

include_directories(BEFORE ${NETMAP_INCLUDE_DIR})

zeek_plugin_begin(Zeek Netmap)
zeek_plugin_cc(src/Plugin.cc)
zeek_plugin_cc(src/Netmap.cc)
zeek_plugin_dist_files(README COPYING zeekctl/netmap.py)
zeek_plugin_end()
