// sysupdate: A program which updates all known package managers.
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

#include "update_software.h"
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
	const char *PROGRAM_VERSION = "0.0.6";
	const char *PROGRAM_URL =
		"https://github.com/ultraviolet-1986/linux_sysupdate";

	// #############
	// # Kickstart #
	// #############

	// Terminate program if not running under GNU/Linux.
	#ifndef __linux__
		printf(RED "ERROR: This program is intended for use with GNU/Linux."
			RESET "\n");
		return 0;
	#endif

	// Parse any given command-line arguments.
	if (argc == 2 && strcmp(argv[1], "--help") == 0)
	{
		printf("Usage: sysupdate [OPTION]\n\n");
		printf("  --version\tDisplay version information.\n");
		printf("  --help\tDisplay this help and exit.\n\n");

		return 0;
	}
	else if (argc == 2 && strcmp(argv[1], "--version") == 0)
	{
		printf("sysupdate ");
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
	else if (argc == 2 && strcmp(argv[1], "--help") != 0 ||
				argc == 2 && strcmp(argv[1], "--version") != 0)
	{
		printf(RED "ERROR: An invalid argument was provided." RESET "\n");
		return 0;
	}
	else if (argc >= 3)
	{
		printf(RED "ERROR: Too many arguments were provided." RESET "\n");
		return 0;
	}

	// Detect Internet connection and proceed.
	int internet_connection = check_network();

	if (internet_connection == 0)
	{
		update_software();
	}
	else if (internet_connection == 1)
	{
		printf(RED "ERROR: An active Internet connection is required." RESET
			"\n");
	}
	else
	{
		printf(RED "ERROR: An unknown error occurred." RESET "\n");
	}

	return 0;
}

// End of File.
