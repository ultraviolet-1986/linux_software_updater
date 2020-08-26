/* sysupdate: A program which updates all known package managers.
 * Copyright (C) 2020 William Willis Whinn
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// ##############
// # REFERENCES #
// ##############

// <https://bbs.archlinux.org/viewtopic.php?id=213878>

#ifndef CHECK_NETWORK_H
#define CHECK_NETWORK_H

// ############
// # INCLUDES #
// ############

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

// #############
// # FUNCTIONS #
// #############

int check_network();

#endif /* CHECK_NETWORK_H */

// End of File.
