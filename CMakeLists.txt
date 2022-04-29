# Isidor
# Copyright (C) 2015 Ingo Ruhnke <grumbel@gmx.de>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.0)
project(isidor VERSION 0.0.0)

include(GNUInstallDirs)

find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(CLANCORE REQUIRED clanCore-1.0)
pkg_search_module(CLANAPP REQUIRED clanApp-1.0)
pkg_search_module(CLANGL REQUIRED clanGL-1.0)
pkg_search_module(CLANDISPLAY REQUIRED clanDisplay-1.0)

set(ISIDOR_SOURCES
  src/datadir.cpp
  src/isidor_main.cpp
  src/isotile_layer.cpp
  src/isowall_layer.cpp)

add_executable(isidor ${ISIDOR_SOURCES})
target_link_libraries(isidor PUBLIC
  ${CLANCORE_LIBRARIES}
  ${CLANAPP_LIBRARIES}
  ${CLANGL_LIBRARIES}
  ${CLANDISPLAY_LIBRARIES}
  ${CLANGL_LIBRARIES}
  ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(isidor PUBLIC
  ${CLANCORE_INCLUDE_DIRS}
  ${CLANAPP_INCLUDE_DIRS}
  ${CLANGL_INCLUDE_DIRS}
  ${CLANDISPLAY_INCLUDE_DIRS}
  ${CLANGL_INCLUDE_DIRS})

install(TARGETS isidor
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY data/
  DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME})

# EOF #
