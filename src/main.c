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

#include "software_updater.h"
#include "check_network.h"

// ###########
// # Defines #
// ###########

#define RED "\x1B[31m"
#define RESET "\x1B[0m"

// #############
// # Functions #
// #############

int main(int argc, char *argv[])
{
	// #############
	// # Variables #
	// #############

	// Program Metadata.
	const char *PROGRAM_VERSION = "0.0.5";
	const char *PROGRAM_URL =
		"https://github.com/ultraviolet-1986/linux_software_updater";

	// #############
	// # Kickstart #
	// #############

	// Parse any given command-line arguments.
	if (argc == 2 && strcmp(argv[1], "--help") == 0)
	{
		printf("Usage: software_updater [OPTION]\n\n");
		printf("  --version\tDisplay version information.\n");
		printf("  --help\tDisplay this help and exit.\n\n");

		return 0;
	}
	else if (argc == 2 && strcmp(argv[1], "--version") == 0)
	{
		printf("Linux Software Updater ");
		printf(PROGRAM_VERSION);
		printf("\n");
		printf("Copyright (C) 2020 William Whinn\n");
		printf(PROGRAM_URL);
		printf("\n");
		printf("License GPLv3+: GNU GPL version 3 or later "
			"<https://gnu.org/licenses/gpl.html>.\n");
		printf("This is free software: you are free to change and "
			"redistribute it.\n");
		printf("There is NO WARRANTY, to the extent permitted by law.\n");
		printf("\n");

		return 0;
	}
	else if (argc >= 3)
	{
		printf(RED "ERROR: Too many arguments passed.\n" RESET);
		return 0;
	}

	// Detect Internet connection and proceed.
	int internet_connection = check_network();

	if (internet_connection == 0)
	{
		system_update();
	}
	else if (internet_connection == 1)
	{
		printf(RED "ERROR: An active Internet connection is required.\n" RESET);
	}
	else
	{
		printf(RED "ERROR: An unknown error occurred.\n" RESET);
	}

	return 0;
}

// End of File.
