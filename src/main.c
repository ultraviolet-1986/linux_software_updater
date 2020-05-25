// Linux Software Updater: A program which updates all known package managers.
// Copyright (C) 2020 William Willis Whinn

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

// ############
// # Includes #
// ############

#include "system_update.h"
#include "check_network.h"

// ###########
// # Defines #
// ###########

#define BLUE "\x1B[34m"
#define RED "\x1B[31m"

#define BOLD "\x1B[1m"
#define RESET "\x1B[0m"

// #############
// # Functions #
// #############

int main()
{
	// #############
	// # Variables #
	// #############

	// Program Metadata.
	const char *PROGRAM_VERSION = "0.0.2";
	const char *PROGRAM_URL =
		"https://github.com/ultraviolet-1986/linux_software_updater";

	// Internet connection status.
	int internet_connection = check_network();

	// #############
	// # Kickstart #
	// #############

	// Clear the screen.
	system("clear");

	// Display program header.
	printf(BLUE BOLD "Linux System Software Update Utility ");
	printf(PROGRAM_VERSION);
	printf(RESET "\n");

	printf(BLUE);
	printf(PROGRAM_URL);
	printf(RESET "\n");

	printf(BLUE "Copyright (C) 2020 William Whinn" RESET "\n\n");

	// Detect Internet Connection and proceed.
	if (internet_connection == 0)
	{
		system_update();
	}
	else if (internet_connection == 1)
	{
		printf(RED "ERROR: An active Internet connection is required.\n\n"
			RESET);
	}
	else
	{
		printf(RED "ERROR: An unknown error occurred.\n\n" RESET);
	}

	return 0;
}

// End of File.
