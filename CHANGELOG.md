# sysupdate Changelog

## Table of Contents

- [0.1.x Series](#01x-series)

## 0.1.x Series

### 0.1.9 Currently in Development

- Removed two-step refresh and upgrade code, now the `&&` operator is passed so
  that if the refreshing of metadata cannot be performed, the upgrade will be
  skipped and `sysupdate` will continue to search for software managers.
- Updated file headers to reflect current date.
- Included support for the Rust language via `rustup`.

### 0.1.7 Released Tuesday 1st September 2020

- Adopted Linux Kernel C style syntax with 100 columns.
- Corrected variables for `anaconda/miniconda` to indicate their mutability.
- Updated `RPM-OSTree` management. Now the cache will be cleared before new
  metadata is downloaded. This will ensure that all current updates are detected
  and applied.
- Optimised argument parsing logic.

### 0.1.6 Released Thursday 20th August 2020

- Corrected program return codes to verify program exit status. This status can
  be checked on the BASH (or compatible) shell using this command: `echo $?`.
- Corrected text colour declarations by placing them within the
  `update_software.h` header file.
- Removed redundant code which detects a non-GNU/Linux system and prevents
  execution.
