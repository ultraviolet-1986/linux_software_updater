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

// ############
// # INCLUDES #
// ############

#include "update_software.h"

// #############
// # FUNCTIONS #
// #############

void update_software()
{
	// #############
	// # VARIABLES #
	// #############

	/* ENVIRONMENTAL VARIABLES */
	char *HOME = getenv("HOME");

	/* NATIVE DISTRIBUTION PACKAGE MANAGERS */
	const char *APT_PATH = "/usr/bin/apt";
	const char *DNF_PATH = "/usr/bin/dnf";
	const char *EOPKG_PATH = "/usr/bin/eopkg";
	const char *PACKAGEKIT_PATH = "/usr/bin/pkcon";
	const char *PACMAN_PATH = "/usr/bin/pacman";
	const char *RPM_OSTREE_PATH = "/usr/bin/rpm-ostree";
	const char *XBPS_INSTALL_PATH = "usr/bin/xbps-install";
	const char *ZYPPER_PATH = "usr/bin/zypper";

	/* UNIVERSAL PACKAGE MANAGERS */
	const char *FLATPAK_PATH = "/usr/bin/flatpak";
	const char *SNAP_PATH = "/usr/bin/snap";

	/* OTHER PACKAGE MANAGERS: ANACONDA 3 */
	char *anaconda3_path_incomplete = "/anaconda3/bin/conda";
	char *anaconda3_path = malloc(strlen(HOME) +
		strlen(anaconda3_path_incomplete) * sizeof(char) + 1);
	strcpy(anaconda3_path, HOME);
	strcat(anaconda3_path, anaconda3_path_incomplete);

	/* OTHER PACKAGE MANAGERS: MINICONDA 3 */
	char *miniconda3_path_incomplete = "/miniconda3/bin/conda";
	char *miniconda3_path = malloc(strlen(HOME) +
		strlen(miniconda3_path_incomplete) * sizeof(char) + 1);
	strcpy(miniconda3_path, HOME);
	strcat(miniconda3_path, miniconda3_path_incomplete);

	/* OTHER SOTWARE: CLAMAV */
	const char *FRESHCLAM_PATH = "/usr/bin/freshclam";

	// #############
	// # KICKSTART #
	// #############

	/* NATIVE DISTRIBUTION PACKAGE MANAGERS */
	if (access(PACKAGEKIT_PATH, F_OK) != -1) {
		/* Evaluate PackageKit first because it is often
		 * installed alongside other package managers and this
		 * can interfere with stability on systems such as KDE
		 * Neon or CentOS 7 (etc).
		 */

		printf(YELLOW "Refresh PackageKit Software Metadata" RESET "\n");
		system("pkcon refresh force");
		printf("\n");

		printf(YELLOW "Update PackageKit System Software" RESET "\n");
		system("sudo -S pkcon update");
		printf("\n");

	} else if (access(APT_PATH, F_OK) != -1) {
		printf(YELLOW "Refresh APT Software Metadata" RESET "\n");
		system("sudo -S apt update");
		printf("\n");

		printf(YELLOW "Update APT System Software" RESET "\n");
		system("sudo -S apt full-upgrade");
		printf("\n");

	} else if (access(DNF_PATH, F_OK) != -1) {
		printf(YELLOW "Update DNF System Software" RESET "\n");
		system("sudo -S dnf update --refresh");
		printf("\n");

	} else if (access(EOPKG_PATH, F_OK) != -1) {
		printf(YELLOW "Refresh EOPKG Software Metadata" RESET "\n");
		system("sudo -S eopkg update-repo");
		printf("\n");

		printf(YELLOW "Update EOPKG System Software" RESET "\n");
		system("sudo -S eopkg upgrade");
		printf("\n");

	} else if (access(PACMAN_PATH, F_OK) != -1) {
		printf(YELLOW "Update Pacman System Software" RESET "\n");
		system("sudo -S pacman -Syu");
		printf("\n");

	} else if (access(RPM_OSTREE_PATH, F_OK) != -1) {
		printf(YELLOW "Update RPM-OSTree System Software" RESET "\n");
		system("rpm-ostree cleanup -m");
		system("rpm-ostree upgrade");
		printf("\n");

	} else if (access(XBPS_INSTALL_PATH, F_OK) != -1) {
		printf(YELLOW "Update XBPS System Software" RESET "\n");
		system("sudo -S xbps-install -Su");
		printf("\n");

	} else if (access(ZYPPER_PATH, F_OK) != -1) {
		printf(YELLOW "Refresh Zypper Software Metadata" RESET "\n");
		system("sudo -S zypper refresh");
		printf("\n");

		printf(YELLOW "Update Zypper System Software" RESET "\n");
		system("sudo -S zypper update");
		printf("\n");

	} else {
		printf(RED "ERROR: A supported package manager was not detected." RESET "\n");
		exit(127);
	}

	/* UNIVERSAL PACKAGE MANAGERS: FLATPAK */
	if (access(FLATPAK_PATH, F_OK) != -1) {
		printf(YELLOW "Update Flatpak Universal Software" RESET "\n");
		system("flatpak update");
		printf("\n");
	}

	/* UNIVERSAL PACKAGE MANAGERS: SNAP */
	if (access(SNAP_PATH, F_OK) != -1) {
		printf(YELLOW "Update Snap Universal Software" RESET "\n");
		system("snap refresh");
		printf("\n");
	}

	/* OTHER PACKAGE MANAGERS: ANACONDA/MINICONDA 3 */
	if (access(anaconda3_path, F_OK) != -1 ||
		access(miniconda3_path, F_OK) != -1) {
		printf(YELLOW "Update Anaconda/Miniconda 3 Python Distribution" RESET "\n");
		system("conda update --all");
		printf("\n");
	}

	/* OTHER SOFTWARE: CLAMAV */
	if (access(FRESHCLAM_PATH, F_OK) != -1) {
		printf(YELLOW "Update ClamAV Antivirus Definitions" RESET "\n");
		system("sudo -S freshclam");
		printf("\n");
	}

	/* PROCESS COMPLETE */
	printf(GREEN "System software has been updated." RESET "\n\n");
}

// End of File.
