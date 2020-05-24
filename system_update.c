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

#include "system_update.h"

// Text colours.
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

#define BOLD "\x1B[1m"
#define UNDERLINE "\x1B[4m"
#define RESET "\x1B[0m"

void system_update(void)
{
	// ####################
	// # Define Variables #
	// ####################

	// Environmental Variables.
	char *HOME = getenv("HOME");

	// Native System Package Managers.
	const char *APT_PATH = "/usr/bin/apt";
	const char *DNF_PATH = "/usr/bin/dnf";

	// Universal Package Managers.
	const char *FLATPAK_PATH = "/usr/bin/flatpak";
	const char *SNAP_PATH = "/usr/bin/snap";

	// Build the Anaconda 3 executable string (user-installed).
	char *ANACONDA3_PATH_INCOMPLETE = "/anaconda3/bin/conda";
	char *ANACONDA3_PATH = malloc(strlen(HOME) +
		strlen(ANACONDA3_PATH_INCOMPLETE) * sizeof(char) + 1);
	strcpy(ANACONDA3_PATH, HOME);
	strcat(ANACONDA3_PATH, ANACONDA3_PATH_INCOMPLETE);

	// ClamAV Antivirus.
	const char *FRESHCLAM_PATH = "/usr/bin/freshclam";

	// #############
	// # Kickstart #
	// #############

	// Display program header.
	printf("\n" BOLD "Linux System Software Update Utility " RESET "\n");
	printf(BOLD "Copyright (C) 2020 William Whinn" RESET "\n\n");

	// Native distribution package managers.
	if (access(APT_PATH, F_OK) != -1)
	{
		// Success: APT is installed. Update the system.
		printf(YELLOW "APT System Software Section" RESET "\n");
		system("sudo apt update");
		system("sudo apt full-upgrade");
		printf("\n");
	}
	else if (access(DNF_PATH, F_OK) != -1)
	{
		// Success: DNF is installed. Update the system.
		printf(YELLOW "DNF System Software Section" RESET "\n");
		system("sudo dnf update --refresh");
		printf("\n");
	}
	else
	{
		// Package manager was not installed on the system.
		printf(RED "ERROR: A supported package manager was not detected." RESET
			"\n");
		exit(0);
	}

	// Universal software package managers.
	if (access(FLATPAK_PATH, F_OK) != -1)
	{
		// Success: Flatpak is installed. Update the system.
		printf(YELLOW "Flatpak Universal Software Section" RESET "\n");
		system("flatpak update");
		printf("\n");
	}

	if (access(SNAP_PATH, F_OK) != -1)
	{
		// Success: SNAP is installed. Update the system.
		printf(YELLOW "Snap Universal Software Section" RESET "\n");
		system("snap refresh");
		printf("\n");
	}

	// Update an Anaconda3 installation.
	if (access(ANACONDA3_PATH, F_OK) != -1)
	{
		// Success: Anaconda3 is installed. Update packages.
		printf(YELLOW "Anaconda 3 Python Distribution Section" RESET "\n");
		system("conda update conda");
		system("conda update anaconda");
	}

	// ClamAV virus definition update.
	if (access(FRESHCLAM_PATH, F_OK) != -1)
	{
		// Success: ClamAV is installed. Update Antivirus definitions.
		printf(YELLOW "ClamAV Antivirus Definitions Update" RESET "\n");
		system("sudo freshclam");
		printf("\n");
	}

	// All Updating tasks complete
	printf(GREEN "System software has been updated" RESET "\n\n");
}

// End of File.
