# ASTERIX Library

## About this project

The aim of this projects is creating a dynamic library (.so file) in C to use, encode, decode and handle ASTERIX messages in embedded and real-time systems, which is also why there's no dynamic memory allocation, using the least resources possible and making the architecture, compiler and endianness of the target system transparent to the data.

Since the the architecture of the target system is unknown, the library supports big and little-endian through bit-wise operations instead of reading values directly from bit-fields. The use of bit-fields is discouraged unless the user is certain the architecture and endianness of the target system does not change the value stored in memory. If unsure of the endianness, the use of the already implemented getters and setters for all items and categories is encouraged.

There are some drawbacks from avoiding dynamic memory allocation, since certain items might repeat certain extensions, which is controled through macros and static memory, making the objects a bit heavier, but the user should adjust this macros to its project scope.

## Compilation process



## Structure of the project
```text
/
├── bin/
├── build/
├── docs/
├── include/
│   ├── Aux_Funcs
|   |   ├── aircraft_ident_char_encoding.h  # Encoding of A/C identification characters
|   |   └── aux_funcs.h                     # Additional functions
│   ├── Categories
│   │   ├── IXXX/                   # Folder of each category
│   │   │   ├── IXXX_YYY.h          # Items (types, macros and LSBs)
│   │   │   └── IXXX.h              # Header with structure, FSPEC, items, and functions to encode/decode the category
│   │   ├── Header.h                # Common types, macros and variables
|   |   └── SAC_SIC.h               # Item 010 present in multiple categories
│   ├── Common
│   │   ├── constants.h             # Useful macros and constant values
│   │   ├── versions.h              # Configuration file to define Edition and Version Number of each category
│   │   └── visibility.h            # Visibility header for functions use
│   └── Logger
│       └── asterix_log.h           # Logger header for debugging purposes
├── src
│   ├── Categories
│   │   ├── IXXX/                   # Folder of each category
│   │   |   ├── IXXX.c              # Encode/Decode functions
│   │   |   └── IXXX_YYY.c          # Functions of each item (getters/setters, prints, ...)
│   |   ├── Header.c                # CAT and LEN getters and setters
│   |   └── SAC_SIC.c               # Getter and print function of Item 010
│   └── Logger
│       └── asterix_log.c           # Logger macros and functions
├── test
│   ├── I021                        # Category 021 tests
│   └── I034                        # Category 034 tests
├── .gitignore
├── docker-compose.yml              # Docker Compose for compilation environment
├── Dockerfile                      # Custom image for compilation environment
├── LICENSE
├── Makefile
└── README.md
```

## Categories

The following categories will be (or are) implemented in this project, since not
all of them are public due. The one not public will be the last ones implemented,
being just a wrapper with basic information.

- Category 004 - Safety Nets Messages
- Category 007 - Directed Interrogation Messages
- Category 008 - Monoradar Derived Weather Information
- Category 009 - Multisensor Derived Weather Information
- Category 010 - Monosensor Surface Movement Data
- Category 011 - Advanced-SMGCS Data 
- Category 015 - INCS (Independent Non-Cooperative Surveillance) Target Reports
- Category 016 - INCS Configuration Reports
- Category 017 - Mode S Surveillance Co-ordination Function Messages
- Category 018 - Mode S Data-Link Function Messages
- Category 019 - MLT System Status Messages
- Category 020 - MLT Messages
- Category 021 - ADS-B Target Reports 
- Category 023 - CNS/ATM Ground Station Service Messages
- Category 025 - CNS/ATM Ground System Status Report 
- Category 032 - Miniplan Reports to an SDPS
- Category 033 - ADS-B Messages
- Category 034 - Transmission of Monoradar Service Messages 
- Category 048 - Monoradar Target Reports
- Category 061 - SDPS Session and Service Control Messages
- Category 062 - System Track Data
- Category 063 - Sensor Status Messages
- Category 065 - SDPS Service Status Messages
- Category 129 - UAS Identification Reports
- Category 150 - Flight Data Messages
- Category 151 - Association Messages
- Category 152 - Time Stamp Messages
- Category 153 - Special Purpose Messages
- Category 204 - Recognised Air Picture
- Category 205 - Radio Direction Finder Reports
- Category 237 - Aeronautical Data Messages
- Category 238 - Service Prediction Reports
- Category 239 - Foreign Object Debris (FOD)
- Category 240 - Radar Video Transmission
- Category 244 - Transmission of Reference Trajectory State Vectors
- Category 247 - Version Number Exchange 
- Category 253 - Remote Station Monitoring and Control Information 