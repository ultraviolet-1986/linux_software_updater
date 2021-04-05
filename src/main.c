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

// ############
// # INCLUDES #
// ############

#include "check_network.h"
#include "update_software.h"

// #############
// # FUNCTIONS #
// #############

int main(int argc, char *argv[])
{
	// #############
	// # VARIABLES #
	// #############

	/* PROGRAM METADATA */
	const char *PROGRAM_VERSION = "0.1.9";
	const char *PROGRAM_URL = "https://github.com/ultraviolet-1986/sysupdate";

	// #############
	// # KICKSTART #
	// #############

	/* PARSE ARGUMENTS */

	if (argc == 2) {
		/* HELP INFORMATION */
		if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
			printf("Usage: sysupdate [OPTION]\n\n");
			printf("  -v, --version\t\tDisplay version information.\n");
			printf("  -h, --help\t\tDisplay this help and exit.\n\n");
			return 0;

		/* VERSION INFORMATION */
		} else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
			printf("sysupdate %s\n", PROGRAM_VERSION);
			printf("Copyright (C) 2021 William Whinn\n");
			printf("<%s>\n", PROGRAM_URL);
			printf("License GPLv3+: GNU GPL version 3 or later "
				"<https://gnu.org/licenses/gpl.html>.\n");
			printf("This is free software: you are free to change and redistribute it."
				"\n");
			printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
			return 0;

		} else {
			printf(RED "ERROR: An invalid argument was provided." RESET "\n");
			return 1;
		}

	} else if (argc >= 3) {
		printf(RED "ERROR: Too many arguments were provided." RESET "\n");
		return 1;
	}

	/* CHECK INTERNET CONNECTION AND PROCEED */
	int internet_connection = check_network();

	if (internet_connection == 0) {
		update_software();

	} else if (internet_connection == 1) {
		printf(RED "ERROR: An active Internet connection is required." RESET "\n");
		return 1;

	} else {
		printf(RED "ERROR: An unknown error occurred." RESET "\n");
		return 1;
	}

	return 0;
}

// End of File.
