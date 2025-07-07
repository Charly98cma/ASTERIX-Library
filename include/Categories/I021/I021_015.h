/**
 * @file I021_015.h
 * @brief Definition of item 015 of CAT 021, and related functions and values
 */

#ifndef I021_015_H
#define I021_015_H

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
 * @typedef I021_015
 * @brief Category 021 / Item 015 - Service Identification
 * 
 * Identification of the service provided to one or more users.
 */
typedef struct I021_015 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        struct {
            /// @brief Service Identification (direct access)
            uint8_t SI;
        };
    };
} I021_015;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Service Identification value (SI) from I021/015.
 * 
 * Portable access to the SI bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_015 structure.
 * 
 * @return uint8_t Value of SI
 */
ASTERIX_API uint8_t get_I021_015_SI(const I021_015 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Service Identification value (SI) into the raw field.
 * 
 * @param item Pointer to I021_015 structure.
 * @param sic_value Value of the SI
 */
ASTERIX_API void set_I021_015_SI(I021_015 * item, const uint8_t value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 015.
 *
 * This function prints the values of the main byte.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a I021_015 structure.
 */
ASTERIX_API void print_I021_015(const I021_015 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_015_H */