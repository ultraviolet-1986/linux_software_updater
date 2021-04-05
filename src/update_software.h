/* sysupdate: A program which updates all known package managers.
 * Copyright (C) 2021 William Willis Whinn
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

#ifndef SYSTEM_UPDATE_H
#define SYSTEM_UPDATE_H

// ############
// # INCLUDES #
// ############

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// ###########
// # DEFINES #
// ###########

#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"

// #############
// # FUNCTIONS #
// #############

void update_software();

#endif /* SYSTEM_UPDATE_H */

// End of File.
