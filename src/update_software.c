// sysupdate: A program which updates all known package managers.
// Copyright (C) 2020 William Willis Whinn

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

// ############
// # Includes #
// ############

#include "update_software.h"

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
    const char *PACKAGEKIT_PATH = "/usr/bin/pkcon";
    const char *PACMAN_PATH = "/usr/bin/pacman";
    const char *RPM_OSTREE_PATH = "/usr/bin/rpm-ostree";
    const char *XBPS_INSTALL_PATH = "usr/bin/xbps-install";
    const char *YUM_PATH = "/usr/bin/yum";
    const char *ZYPPER_PATH = "usr/bin/zypper";

    // Universal Package Managers.
    const char *FLATPAK_PATH = "/usr/bin/flatpak";
    const char *SNAP_PATH = "/usr/bin/snap";

    // Build the Anaconda 3 executable string (user-installed).
    char *anaconda3_path_incomplete = "/anaconda3/bin/conda";
    char *anaconda3_path = malloc(strlen(HOME) +
        strlen(anaconda3_path_incomplete) * sizeof(char) + 1);
    strcpy(anaconda3_path, HOME);
    strcat(anaconda3_path, anaconda3_path_incomplete);

    // Build the Miniconda 3 executable string (user-installed).
    char *miniconda3_path_incomplete = "/miniconda3/bin/conda";
    char *miniconda3_path = malloc(strlen(HOME) +
        strlen(miniconda3_path_incomplete) * sizeof(char) + 1);
    strcpy(miniconda3_path, HOME);
    strcat(miniconda3_path, miniconda3_path_incomplete);

    // ClamAV Antivirus.
    const char *FRESHCLAM_PATH = "/usr/bin/freshclam";

    // #############
    // # Kickstart #
    // #############

    // Native distribution package managers.
    if (access(PACKAGEKIT_PATH, F_OK) != -1)
    {
        // Evaluate this first because it often pairs with other package
        // managers and this can interfere with stability on systems
        // such as KDE Neon.

        // Success: PackageKit is installed. Update the system.
        printf(YELLOW "Refresh PackageKit Software Metadata" RESET "\n");
        system("pkcon refresh force");
        printf("\n");
        printf(YELLOW "Update PackageKit System Software" RESET "\n");
        system("sudo -S pkcon update");
        printf("\n");
    }
    else if (access(APT_PATH, F_OK) != -1)
    {
        // Distribution most likely Ubuntu or compatible.
        // Success: APT is installed. Update the system.
        printf(YELLOW "Refresh APT Software Metadata" RESET "\n");
        system("sudo -S apt update");
        printf("\n");
        printf(YELLOW "Update APT System Software" RESET "\n");
        system("sudo -S apt full-upgrade");
        printf("\n");
    }
    else if (access(DNF_PATH, F_OK) != -1)
    {
        // Distribution most likely CentOS/Fedora/RHEL or compatible.
        // Success: DNF is installed. Update the system.
        printf(YELLOW "Update DNF System Software" RESET "\n");
        system("sudo -S dnf update --refresh");
        printf("\n");
    }
    else if (access(EOPKG_PATH, F_OK) != -1)
    {
        // Distribution most likely Solus or compatible.
        // Success: EOPKG is installed. Update the system.
        printf(YELLOW "Refresh EOPKG Software Metadata" RESET "\n");
        system("sudo -S eopkg update-repo");
        printf("\n");
        printf(YELLOW "Update EOPKG System Software" RESET "\n");
        system("sudo -S eopkg upgrade");
        printf("\n");
    }
    else if (access(PACMAN_PATH, F_OK) != -1)
    {
        // Distribution most likely Arch Linux or compatible.
        // Success: Pacman is installed. Update the System.
        printf(YELLOW "Update Pacman System Software" RESET "\n");
        system("sudo -S pacman -Syu");
        printf("\n");
    }
    else if (access(RPM_OSTREE_PATH, F_OK) != -1)
    {
        // Distribution most likely Fedora Silverblue or compatible.
        // Success: RPM-OSTree is installed. Update the system.
        printf(YELLOW "Refresh RPM-OSTree Software Metadata" RESET "\n");
        system("rpm-ostree refresh-md");
        printf("\n");
        printf(YELLOW "Update RPM-OSTree System Software" RESET "\n");
        system("rpm-ostree upgrade");
        printf("\n");
    }
    else if (access(XBPS_INSTALL_PATH, F_OK) != -1)
    {
        // Distribution most likely Void or compatible.
        // Success: XBPS-INSTALL is installed. Update the system.
        printf(YELLOW "Update XBPS System Software" RESET "\n");
        system("sudo -S xbps-install -Su");
        printf("\n");
    }
    else if (access(YUM_PATH, F_OK) != -1)
    {
        // Distribution most likely Legacy RHEL or compatible.
        // Success: Yum is installed. Update the system.
        printf(YELLOW "Update Yum System Software" RESET "\n");
        system("sudo -S yum update --refresh");
        printf("\n");
    }
    else if (access(ZYPPER_PATH, F_OK) != -1)
    {
        // Distribution most likely openSUSE or compatible.
        // Success: Zypper is installed. Update the system.
        printf(YELLOW "Refresh Zypper Software Metadata" RESET "\n");
        system("sudo -S zypper refresh");
        printf("\n");
        printf(YELLOW "Update Zypper System Software" RESET "\n");
        system("sudo -S zypper update");
        printf("\n");
    }
    else
    {
        // Package manager was not installed on the system.
        printf(RED "ERROR: A supported package manager was not detected." RESET
            "\n");
        exit(127);
    }

    // Universal Package Managers: Flatpak.
    if (access(FLATPAK_PATH, F_OK) != -1)
    {
        // Success: Flatpak is installed. Update the system.
        printf(YELLOW "Update Flatpak Universal Software" RESET "\n");
        system("flatpak update");
        printf("\n");
    }

    // Universal Package Managers: Snap.
    if (access(SNAP_PATH, F_OK) != -1)
    {
        // Success: SNAP is installed. Update the system.
        printf(YELLOW "Update Snap Universal Software" RESET "\n");
        system("snap refresh");
        printf("\n");
    }

    // Update an Anaconda/Miniconda 3 installation.
    if (access(anaconda3_path, F_OK) != -1 ||
        access(miniconda3_path, F_OK) != -1)
    {
        // Success: Anaconda 3 is installed. Update packages.
        printf(YELLOW "Update Anaconda/Miniconda 3 Python Distribution" RESET
            "\n");
        system("conda update --all");
        printf("\n");
    }

    // ClamAV virus definition update.
    if (access(FRESHCLAM_PATH, F_OK) != -1)
    {
        // Success: ClamAV is installed. Update Antivirus definitions.
        printf(YELLOW "Update ClamAV Antivirus Definitions" RESET "\n");
        system("sudo -S freshclam");
        printf("\n");
    }

    // All Updating tasks complete
    printf(GREEN "System software has been updated." RESET "\n\n");
}

// End of File.
