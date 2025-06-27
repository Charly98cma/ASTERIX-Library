/**
 * @file cat021_item080.h
 * @brief Definition of CAT 021 Item 080, and related functions and values
 */

#ifndef CAT021_ITEM080_H
#define CAT021_ITEM080_H

#include <stdio.h>
#include <stdint.h>
#include "Common/visibility.h"

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
 * @typedef cat021_item080
 * @brief Category 021 / Item 080 - Target Address
 * 
 * Target ICAO (24 bits) Address.
 */
typedef struct cat021_item080 {

    /// @brief Target ICAO Address (24 bits)
    uint8_t raw[3];

} cat021_item080;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Returns the Target ICAO Address value
 *
 * Returns the 24-bit value of the Target ICAO Address.
 *
 * @param item Pointer to cat021_item080 structure.
 * @return uint32_t 24-bit target address.
 */
ASTERIX_API uint32_t get_cat021_item080_TGTADDR(const cat021_item080 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Target ICAO Address value into Cat 021 Item 080.
 *
 * Stores the 24-bit value into the raw array.
 *
 * @param item Pointer to cat021_item080 structure.
 * @param addr 24-bit target address.
 */
ASTERIX_API void set_cat021_item080_TGTADDR(cat021_item080 * item, uint32_t addr);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT021 Item 080 (Target ICAO Address).
 * 
 * Prints both 3 hexadecimal that compose the ICAO Address of the target aircraft.
 * 
 * @param item Pointer to cat021_item080 structure.
 */
ASTERIX_API void print_cat021_item080(const cat021_item080 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM080_H */