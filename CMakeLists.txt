cmake_minimum_required(VERSION 2.6.3)

project(BroPluginNetmap)
include(BroPlugin)

# Not currently using this because we are shipping the
# netmap headers for now.
#find_package(Netmap)

#if ( NETMAP_FOUND )
#     include_directories(BEFORE ${NETMAP_INCLUDE_DIR})

     bro_plugin_begin(Bro Netmap)
     bro_plugin_cc(src/Plugin.cc)
     bro_plugin_cc(src/Netmap.cc)
     bro_plugin_dist_files(README COPYING broctl/netmap.py)
     bro_plugin_end()

#    message(STATUS "Netmap prefix       : ${NETMAP_ROOT_DIR}")
#else ()
#    message(FATAL_ERROR "Netmap headers not found.")
#endif ()
