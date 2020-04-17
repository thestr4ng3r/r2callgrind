cmake_minimum_required(VERSION 3.12)

project(r2callgrind)

set(RADARE2_INSTALL_PLUGDIR "share/radare2/plugins" CACHE PATH "Directory to install radare2 plugin into")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Radare2 REQUIRED)

add_library(core_callgrind SHARED core_callgrind.c)
target_link_libraries(core_callgrind Radare2::libr)

install(TARGETS core_callgrind DESTINATION "${RADARE2_INSTALL_PLUGDIR}")