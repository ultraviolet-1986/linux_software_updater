# Linux Software Updater

A program which attempts to connect to known package managers and update all
system software.

## Table of Contents

- [Introduction](#introduction)
- [Currently Supported Software](#currently-supported-software)
  - [Native Package Managers](#native-package-managers)
  - [Universal Package Managers](#universal-package-managers)
  - [Software Distributions](#software-distributions)
  - [Additional Software](#additional-software)
- [Compilation Instructions](#compilation-instructions)
- [References](#references)

## Introduction

This program has been built with a single function in mind: to provide a
junction to all known package managers included within a typical desktop Linux
distribution and perform all software upgrade tasks at-once. Each package
manager or piece of software (listed below) will only attempt an update if they
are installed. For example, this program will not attempt to update an Ubuntu
system using Fedora's update manager.

Native package managers are tested for initially and in the absence of these,
the program will halt. This is to ensure that this program is only operating in
a familiar environment and will not attempt to update an operating system which
is unknown. New Linux distribution and package management software will be added
on an ad-hoc basic as and when they can be thoroughly tested.

## Currently Supported Software

At present, these are the known package managers supported by this program:

### Native Package Managers

These package managers typically form the foundation of a standard Linux
distribution and as such, they are to be considered essential. This program will
attempt to detect these and exit if none are detected.

- **APT** (Debian / Ubuntu)
- **DNF** (CentOS / Fedora)
- **RPM-OSTree** (Fedora Silverblue)

### Universal Package Managers

These package managers are non-essential and may be detected on almost any
standard Linux distribution. If these are not detected, the program will
continue, ignoring these technologies.

- **Flatpak** (Universal)
- **Snap** (Universal)

### Software Distributions

These packages contain additional software which form (for example) additional
programming languages and version managers.

- **Anadonda 3** (Python, user-installed)

### Additional Software

Software which may be updated but is not considered a package manager will be
listed within this section.

- **ClamAV**

## Compilation Instructions

These commands should succeed and allow the program to run under any GNU/Linux
distribution which has a working `gcc` installation. This program was written in
a Fedora Workstation 32 (x86_64) environment with no additional dependencies.

```bash
# Build the executable.
gcc -std=c11 main.c check_network.c system_update.c -o system_update

# Launch the program.
./system_update
```

## References

- **`check_network.h` / `check_network.c`**
  - <https://bbs.archlinux.org/viewtopic.php?id=213878>
