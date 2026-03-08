# ASTERIX Library

## About this project

This project provides a lightweight and portable C library for handling, encoding, and decoding ASTERIX (All-purpose Structured EUROCONTROL Surveillance Information Exchange) messages. The library is designed for embedded systems and resource-constrained environments, following the C99 standard and relying exclusively on static memory allocation. By avoiding dynamic memory, it guarantees deterministic memory usage, low overhead, and predictable performance.

To ensure portability across architectures, the implementation avoids compiler-dependent limitations such as bitfields. All bit-level parsing is handled explicitly during encoding and decoding. While this approach results in slightly larger structures, it simplifies the codebase, avoids endianness-related issues, and ensures consistent behavior across different compilers and target platforms.

## Compilation process

The provided Makefile offers simple commands to build the static and/or dynamic library files:

- `make all`: compiles both the static (asterix_lib.a) and dynamic (asterix_lib.so) files
- `make static`: compiles only the static (asterix_lib.a) library
- `make shared`: compiles only the dynamic (asterix_lib.so) library

## Structure of the project

```text
/
├── bin/
├── build/
├── docs/
├── include/
│   ├── Categories
│   ├── Common
│   ├── Infra
│   ├── Logger
├── src
│   ├── Categories
│   ├── Infra
│   └── Logger
├── test
│   └── I034                        # Category 034 tests
├── .gitignore
├── LICENSE
├── Makefile
└── README.md
```

## Categories

ASTERIX does not publish documentation for all categories since some are used in military projects, so this library will cover only publicly available and mantained categories.

The remaining categories and data items (mainly the not public ones) must be implemented by the user, if possible, following the same coding structure.

- [ ] Category 004 - Safety Nets Messages
- [ ] Category 007 - Directed Interrogation Messages
- [ ] Category 008 - Monoradar Derived Weather Information
- [ ] Category 009 - Multisensor Derived Weather Information
- [ ] Category 010 - Monosensor Surface Movement Data
- [ ] Category 011 - Advanced-SMGCS Data 
- [ ] Category 015 - INCS (Independent Non-Cooperative Surveillance) Target Reports
- [ ] Category 016 - INCS Configuration Reports
- [ ] Category 017 - Mode S Surveillance Co-ordination Function Messages
- [ ] Category 018 - Mode S Data-Link Function Messages
- [ ] Category 019 - MLT System Status Messages
- [ ] Category 020 - MLT Messages
- [ ] Category 021 - ADS-B Target Reports 
- [ ] Category 023 - CNS/ATM Ground Station Service Messages
- [ ] Category 025 - CNS/ATM Ground System Status Report 
- [ ] Category 032 - Miniplan Reports to an SDPS
- [ ] Category 033 - ADS-B Messages
- [ ] Category 034 - Transmission of Monoradar Service Messages 
- [ ] Category 048 - Monoradar Target Reports
- [ ] Category 061 - SDPS Session and Service Control Messages
- [ ] Category 062 - System Track Data
- [ ] Category 063 - Sensor Status Messages
- [ ] Category 065 - SDPS Service Status Messages
- [ ] Category 129 - UAS Identification Reports
- [ ] Category 150 - Flight Data Messages
- [ ] Category 151 - Association Messages
- [ ] Category 152 - Time Stamp Messages
- [ ] Category 153 - Special Purpose Messages
- [ ] Category 204 - Recognised Air Picture
- [ ] Category 205 - Radio Direction Finder Reports
- [ ] Category 237 - Aeronautical Data Messages
- [ ] Category 238 - Service Prediction Reports
- [ ] Category 239 - Foreign Object Debris (FOD)
- [ ] Category 240 - Radar Video Transmission
- [ ] Category 244 - Transmission of Reference Trajectory State Vectors
- [ ] Category 247 - Version Number Exchange 
- [ ] Category 253 - Remote Station Monitoring and Control Information 

## User-defined data items

The following data items are empty and, if needed, must be implemented before using the library, since the official documentation does not specify its contents:

1. Category 034 - Transmission of Monoradar Service Messages 
    - Reserved Expansion Field 
        - include: ./include/Categories/I034/I034_RE.h
        - src: ./include/Categories/I034/I034_RE.c
    - Special Purpose 
