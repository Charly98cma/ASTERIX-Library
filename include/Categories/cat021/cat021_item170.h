/**
 * @file cat021_item170.h
 * @brief Definition of CAT 021 Item 170, and related functions and values
 */

#ifndef CAT021_ITEM170_H
#define CAT021_ITEM170_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/// @brief Number of octets of Cat 021 Item 170
#define CAT021_ITEM170_N_OCTETS         6

/// @brief Number of characters of the Target Identification
#define CAT021_ITEM170_NUM_CHARS        8

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item170
 * @brief Category 021 Item 170 - Target Identification
 * 
 * Target (aircraft or vehicle) identification in 8 characters, as reported
 * by the target.
 * 
 * @note Characters 1-8 (coded on 6 Bits each) defining target identification
 * when flight plan is available or the registration marking when no flight
 * plan is available.
 */
typedef struct cat021_item170 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[CAT021_ITEM170_N_OCTETS];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Character 1 (6 bits)
            uint8_t CHAR1           :6;
            /// @brief Character 2 (6 bits)
            uint8_t CHAR2           :6;
            /// @brief Character 3 (6 bits)
            uint8_t CHAR3           :6;
            /// @brief Character 4 (6 bits)
            uint8_t CHAR4           :6;
            /// @brief Character 5 (6 bits)
            uint8_t CHAR5           :6;
            /// @brief Character 6 (6 bits)
            uint8_t CHAR6           :6;
            /// @brief Character 7 (6 bits)
            uint8_t CHAR7           :6;
            /// @brief Character 8 (6 bits)
            uint8_t CHAR8           :6;
        };
    };
} cat021_item170;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Target Identification string from Cat 021 Item 170
 * 
 * @param item pointer to cat021_item170 structure
 * @param str pointer to return the Target Identification string
 */
ASTERIX_API void get_cat021_item170_TI(const cat021_item170 * item,
                                       unsigned char * str);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Target Identification string into Cat 021 Item 170
 * 
 * @param item pointer to cat021_item170 structure
 * @param str pointer to Target Identification string to write
 */
ASTERIX_API void set_cat021_item170_TI(cat021_item170 * item,
                                       const unsigned char * str);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Track Identification string of the Cat 021 Item 170
 * 
 * @param item pointer to cat021_item170 structure
 */
ASTERIX_API void print_cat021_item170(const cat021_item170 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM170_H */