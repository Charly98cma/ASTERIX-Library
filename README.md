# ASTERIX Library

## Structure of the project
```text
/
├── bin/
├── build/
├── docs/
├── include/
│   ├── Categories
│   │   └── catXXX/                 # Folder of each category
│   │       ├── catXXX.h            # Header with all items
│   │       ├── catXXX_itemYYY.h    # Items (types, macros and LSBs)
│   │       └── repo_api.h          # Aux. header to import all categories
│   └── Common
│       ├── asterix_log.h           # Logger header
│       ├── common.h                # Common types, macros and variables
│       ├── constants.h             # Useful macros and constant values
│       ├── item010.h               # Item 010 in multiple categories
│       └── visibility.h            # Visibility header for compilation
├── src
│   ├── Categories
│   │   └── catXXX/                 # Folder of each category
│   │       ├── catXXX.c            # Encode/Decode functions
│   │       └── catXXX_itemYYY.c    # Functions of each item (getters and print)
│   └── Common
│       ├── asterix_log.c           # Logger functions
│       ├── common.h                # CAT and LEN getters
│       └── item010.h               # Getter and print function of Item 010
├── .gitignore
├── LICENSE
├── Makefile
└── README.md
```
