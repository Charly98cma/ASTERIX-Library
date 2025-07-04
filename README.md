# ASTERIX Library

## About this project

The aim of this projects is creating a dynamic library (.so file) in C to use, encode, decode and handle ASTERIX messages in embedded and real-time systems, which is also why there's no dynamic memory allocation, using the least resources possible and making the architecture, compiler and endianness of the target system transparent to the data.

Since the the architecture of the target system is unknown, the library supports big and little-endian through bit-wise operations instead of reading values directly from bit-fields which are implemented, but its use is discouraged unless the user is certain the architecture and endian of the target system does not change the value stored in memory. This is why the use of the already implemented getters and setters for all items and categories is encouraged.

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
|   |   ├── aux_funcs.h             # Additional functions for better code mantainability
|   |   ├── bitwise_funcs.h         # Functions to RW/WR values using bits and shifts
|   |   └── char_encoding.h         # Values and converter of A/C identification characters
│   ├── Categories
│   │   ├── catXXX/                 # Folder of each category
│   │   │   ├── catXXX.h            # Header with all items and encoding/decoding
│   │   │   └── catXXX_itemYYY.h    # Items (types, macros and LSBs)
│   │   ├── header.h                # Common types, macros and variables
|   |   ├── item010.h               # Item 010 present in multiple categories
│   │   └── repo_api.h              # Aux. header to import all categories at once
│   └── Common
│   │   ├── constants.h             # Useful macros and constant values
│   │   ├── versions.h              # Configuration file to define Edition and Version Number of each category
│   │   └── visibility.h            # Visibility header for functions use
│   └── Logger
│       └── asterix_log.h           # Logger header for debugging purposes
├── src
│   ├── Categories
│   │   ├── catXXX/                 # Folder of each category
│   │   |   ├── catXXX.c            # Encode/Decode functions
│   │   |   └── catXXX_itemYYY.c    # Functions of each item (getters/setters, prints, ...)
│   |   ├── header.h                # CAT and LEN getters and setters
│   |   └── item010.h               # Getter and print function of Item 010
│   └── Logger
│       └── asterix_log.c           # Logger macros and functions
├── .gitignore
├── LICENSE
├── Makefile
└── README.md
```
