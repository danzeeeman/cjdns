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

if (WIN32)
   set(admin Admin_W32.c)
else()
   set(admin Admin.c)
endif()

add_library(cjdadmin
    ${admin}
    AdminClient.c
    AuthorizedPasswords.c
    Configurator.c
)

target_link_libraries(cjdadmin crypto cjdbenc_StandardBencSerializer)

add_subdirectory(testframework)

enable_testing()
add_subdirectory(test)
