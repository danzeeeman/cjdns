/* vim: set expandtab ts=4 sw=4: */
/*
 * You may redistribute this program and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "crypto/Crypto.h"
#include "util/Assert.h"
#include "util/checksum/Checksum_impl0.h"
#include "util/checksum/Checksum_impl1.h"

#define CYCLES 50
#define MAX_SIZE 8192

int main()
{
    for (int i = 0; i < CYCLES; i++) {
        uint8_t buffer[MAX_SIZE];
        uint16_t size;
        randombytes((uint8_t*) &size, 2);
        size %= MAX_SIZE;
        randombytes(buffer, size);

        uint16_t sum0 = Checksum_impl0_complete(Checksum_impl0_step(buffer, size, 0));
        uint16_t sum1 = Checksum_impl1_complete(Checksum_impl1_step(buffer, size, 0));
        Assert_always(sum0 == sum1);
    }
}
