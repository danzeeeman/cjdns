# You may redistribute this program and/or modify it under the terms of
# the GNU General Public License as published by the Free Software Foundation,
# either version 3 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
project(util C)
cmake_minimum_required(VERSION 2.4)

add_subdirectory(checksum)

find_package(Libevent2 REQUIRED)
include_directories(${LIBEVENT2_INCLUDE_DIRS})

if(WIN32)
    set(sec Security_W32.c)
else()
    set(sec Security.c)
endif()

add_library(util
    AverageRoller.c
    Timeout.c
    Hex.c
    Pinger.c
    ${sec}
)
target_link_libraries(util cjdmemory ${LIBEVENT2_LIBRARIES})

# Everything must be tested.
enable_testing()
add_subdirectory(test)
