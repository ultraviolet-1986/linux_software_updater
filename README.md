# Linux Software Updater

A program which attempts to connect to known package managers and update all
system software.

## Currently Updated Software

At present, these are the known package managers supported by this program:

- **APT** (Debian / Ubuntu)
- **DNF** (CentOS / Fedora)

- **Flatpak** (Universal)
- **Snap** (Universal)

- **Anadonda 3** (Python, user-installed)

- **ClamAV**

## Build and Run

These commands should succeed and allow the program to run under any GNU/Linux
distribution which has a working `gcc` installation.

```bash
# Build the executable.
gcc -std=c11 main.c system_update.c -o system_update

# Launch the program.
./system_update
```
