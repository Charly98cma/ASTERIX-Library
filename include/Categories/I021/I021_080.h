/**
 * @file I021_080.h
 * @brief Definition of I021/080, and related functions and values
 */

#ifndef I021_080_H
#define I021_080_H

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
 * @typedef I021_080
 * @brief Category 021 / Item 080 - Target Address
 * 
 * Target ICAO (24 bits) Address.
 */
typedef struct I021_080 {

    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[3];
        
        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
        
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Target ICAO Address (24 bits)
            uint8_t TGTADDR[3];
        };
    };
} I021_080;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Returns the Target ICAO Address value
 *
 * Returns the 24-bit value of the Target ICAO Address.
 *
 * @param item Pointer to I021_080 structure.
 * @return uint32_t 24-bit target address.
 */
ASTERIX_API uint32_t get_I021_080_TGTADDR(const I021_080 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Target ICAO Address value into I021/080.
 *
 * Stores the 24-bit value into the raw array.
 *
 * @param item Pointer to I021_080 structure.
 * @param addr 24-bit target address.
 */
ASTERIX_API void set_I021_080_TGTADDR(I021_080 * item, const uint32_t addr);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of I021/080 (Target ICAO Address).
 * 
 * Prints both 3 hexadecimal that compose the ICAO Address of the target aircraft.
 * 
 * @param item Pointer to I021_080 structure.
 */
ASTERIX_API void print_I021_080(const I021_080 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_080_H */