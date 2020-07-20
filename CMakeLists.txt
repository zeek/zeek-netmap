cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(ZeekPluginNetmap)

include(ZeekPlugin)

# Not currently using this because we are shipping the
# netmap headers for now.
#find_package(Netmap)

#if ( NETMAP_FOUND )
#     include_directories(BEFORE ${NETMAP_INCLUDE_DIR})

zeek_plugin_begin(Zeek Netmap)
zeek_plugin_cc(src/Plugin.cc)
zeek_plugin_cc(src/Netmap.cc)
zeek_plugin_dist_files(README COPYING broctl/netmap.py)
zeek_plugin_end()

#    message(STATUS "Netmap prefix       : ${NETMAP_ROOT_DIR}")
#else ()
#    message(FATAL_ERROR "Netmap headers not found.")
#endif ()
