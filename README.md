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

- CAT004 Safety Nets Messages
- CAT007 Directed Interrogation Messages
- CAT008 Monoradar Derived Weather Information
- CAT009 Multisensor Derived Weather Information
- CAT010 Monosensor Surface Movement Data
- CAT011 Advanced-SMGCS Data 
- CAT015 INCS (Independent Non-Cooperative Surveillance) Target Reports
- CAT016 INCS Configuration Reports
- CAT017 Mode S Surveillance Co-ordination Function messages
- CAT018 Mode S Data-Link Function messages
- CAT019 MLT System Status Messages
- CAT020 MLT Messages
- CAT021 ADS-B Target Reports 
- CAT023 CNS/ATM Ground Station Service Messages
- CAT025 CNS/ATM Ground System Status Report 
- CAT032 Miniplan Reports to an SDPS
- CAT033 ADS-B Messages
- CAT034 Transmission of Monoradar Service Messages 
- CAT048 Monoradar Target Reports
- CAT061 SDPS Session and Service Control Messages
- CAT062 System Track Data
- CAT063 Sensor Status Messages
- CAT065 SDPS Service Status Messages
- CAT129 UAS Identification Reports
- CAT150 Flight Data Messages
- CAT151 Association Messages
- CAT152 Time Stamp Messages
- CAT153 Special Purpose Messages
- CAT204 Recognised Air Picture
- CAT205 Radio Direction Finder Reports
- CAT237 Aeronautical Data Messages
- CAT238 Service Prediction Reports
- CAT239 Foreign Object Debris (FOD)
- CAT240 Radar Video Transmission
- CAT244 Transmission of Reference Trajectory State Vectors
- CAT247 Version Number Exchange 
- CAT253 Remote Station Monitoring and Control Information 