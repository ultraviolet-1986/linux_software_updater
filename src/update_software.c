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

// ###########
// # Defines #
// ###########

// Text formatting.
#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"

// #############
// # Functions #
// #############

void update_software()
{
	// #############
	// # Variables #
	// #############

	// Environmental Variables.
	char *HOME = getenv("HOME");

	// Native System Package Managers.
	const char *APT_PATH = "/usr/bin/apt";
	const char *DNF_PATH = "/usr/bin/dnf";
	const char *EOPKG_PATH = "/usr/bin/eopkg";
	const char *PACMAN_PATH = "/usr/bin/pacman";
	const char *RPM_OSTREE_PATH = "/usr/bin/rpm-ostree";
	const char *XBPS_INSTALL_PATH = "usr/bin/xbps-install";
	const char *ZYPPER_PATH = "usr/bin/zypper";

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

	// Native distribution package managers.
	if (access(APT_PATH, F_OK) != -1)
	{
		// Distribution most likely Ubuntu or compatible.
		// Success: APT is installed. Update the system.
		printf(YELLOW "Update APT System Software" RESET "\n");
		system("sudo apt update");
		printf("\n");
		system("sudo apt full-upgrade");
		printf("\n");
	}
	else if (access(DNF_PATH, F_OK) != -1)
	{
		// Distribution most likely CentOS/Fedora/RHEL or compatible.
		// Success: DNF is installed. Update the system.
		printf(YELLOW "Update DNF System Software" RESET "\n");
		system("sudo dnf update --refresh");
		printf("\n");
	}
	else if (access(EOPKG_PATH, F_OK) != -1)
	{
		// Distribution most likely Solus or compatible.
		// Success: EOPKG is installed. Update the system.
		printf(YELLOW "Update EOPKG System Software" RESET "\n");
		system("sudo eopkg update-repo");
		printf("\n");
		system("sudo eopkg upgrade");
		printf("\n");
	}
	else if (access(PACMAN_PATH, F_OK) != -1)
	{
		// Distribution most likely Arch Linux or compatible.
		// Success: Pacman is installed. Update the System.
		printf(YELLOW "Update Pacman System Software" RESET "\n");
		system("sudo pacman -Syu");
		printf("\n");
	}
	else if (access(RPM_OSTREE_PATH, F_OK) != -1)
	{
		// Distribution most likely Fedora Silverblue or compatible.
		// Success: RPM-OSTree is installed. Update the system.
		printf(YELLOW "Update RPM-OSTree System Software" RESET "\n");
		system("rpm-ostree refresh-md");
		printf("\n");
		system("rpm-ostree upgrade");
		printf("\n");
	}
	else if (access(XBPS_INSTALL_PATH, F_OK) != -1)
	{
		// Distribution most likely Void or compatible.
		// Success: XBPS-INSTALL is installed. Update the system.
		printf(YELLOW "Update XBPS System Software" RESET "\n");
		system("sudo xbps-install -Su");
		printf("\n");
	}
	else if (access(ZYPPER_PATH, F_OK) != -1)
	{
		// Distribution most likely openSUSE or compatible.
		// Success: Zypper is installed. Update the system.
		printf(YELLOW "Update Zypper System Software" RESET "\n");
		system("sudo zypper refresh");
		printf("\n");
		system("sudo zypper update");
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
		printf(YELLOW "Update Flatpak Universal Software" RESET "\n");
		system("flatpak update");
		printf("\n");
	}

	if (access(SNAP_PATH, F_OK) != -1)
	{
		// Success: SNAP is installed. Update the system.
		printf(YELLOW "Update Snap Universal Software" RESET "\n");
		system("snap refresh");
		printf("\n");
	}

	// Update an Anaconda3 installation.
	if (access(ANACONDA3_PATH, F_OK) != -1)
	{
		// Success: Anaconda/Miniconda 3 is installed. Update packages.
		printf(YELLOW "Update Anaconda/Miniconda Python Distribution" RESET "\n");
		system("conda update conda");
		printf("\n");
		system("conda update anaconda");
		printf("\n");
		system("conda update --all");
		printf("\n");
	}

	// ClamAV virus definition update.
	if (access(FRESHCLAM_PATH, F_OK) != -1)
	{
		// Success: ClamAV is installed. Update Antivirus definitions.
		printf(YELLOW "Update ClamAV Antivirus Definitions" RESET "\n");
		system("sudo freshclam");
		printf("\n");
	}

	// All Updating tasks complete
	printf(GREEN "System software has been updated." RESET "\n\n");
}

// End of File.
