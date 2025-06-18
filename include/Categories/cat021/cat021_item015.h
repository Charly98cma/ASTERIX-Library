/**
 * @file cat021_item015.h
 * @brief Definition of item 015 of CAT 021, and related functions and values
 */

#ifndef CAT021_ITEM015_H
#define CAT021_ITEM015_H

#include <stdint.h>
#include "visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item015
 * @brief Category 021 / Item 015 - Service Identification
 * 
 * Identification of the service provided to one or more users.
 */
typedef struct cat021_item015 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        struct {
            /// @brief Service Identification (direct access)
            uint8_t SI;
        };
    };
} cat021_item015;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Service Identification value (SI) from I021/015.
 * 
 * Portable access to the SI bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item015 structure.
 * @return uint8_t Value of SI
 */
ASTERIX_API uint8_t get_cat021_item015_SI(const cat021_item015 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Service Identification value (SI) into the raw field.
 * 
 * @param item Pointer to cat021_item015 structure.
 * @param sic_value Value of the SI
 */
ASTERIX_API void set_cat021_item015_SI(cat021_item015 * item, uint8_t value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 015.
 *
 * This function prints the values of the main byte.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a cat021_item015 structure.
 */
ASTERIX_API void print_cat021_item015(const cat021_item015 *item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM015_H */