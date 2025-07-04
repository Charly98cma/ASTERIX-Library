/**
 * @file cat021_item016.h
 * @brief Definition of item 016 of CAT 021, and related functions and values
 */

#ifndef CAT021_ITEM016_H
#define CAT021_ITEM016_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define CAT021_ITEM016_LSB_RP           (0.5)       /// @brief LSB = 0.5 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item016
 * @brief Category 021 / Item 016 - Service Management
 * 
 * Identification of services offered by a ground station
 * (identified by a SIC code)
 */
typedef struct cat021_item016 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;


        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** 
             * @brief Report Period (direct access)
             * 
             * Range: 0 … 127.5 seconds (value of 127.5 indicates 127.5 or more)
             * 
             * LSB = 0.5 s
             */
            uint8_t RP      :8;
        };
    };
} cat021_item016;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Report Period (RP) raw value from I021/016.
 * 
 * Portable access to the RP bits, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item016 structure.
 * @return uint8_t Value of RP
 */
ASTERIX_API uint8_t get_cat021_item016_RP_raw(const cat021_item016 * item);

/**
 * @brief Get the Report Period value (RP) from I021/016 in seconds.
 * 
 * Converts the raw RP value to seconds.
 * 
 * Range: 0 … 127.5 seconds (value of 127.5 indicates 127.5 or more)
 * 
 * @param item Pointer to cat021_item016 structure.
 * @return double Report Period in seconds
 */
ASTERIX_API double get_cat021_item016_RP_seconds(const cat021_item016 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Report Period (RP) raw value into the raw field.
 * 
 * @param item Pointer to cat021_item016 structure.
 * @param sic_value Value of the RP in steps of 0.5 seconds
 */
ASTERIX_API void set_cat021_item016_RP_raw(cat021_item016 * item,
                                           const uint8_t raw_value);

/**
 * @brief Set the Report Period (RP) valie in seconds into the raw field.
 * 
 * @param item Pointer to cat021_item016 structure.
 * @param sic_value Value of the RP in seconds
 */
ASTERIX_API void set_cat021_item016_RP_seconds(cat021_item016 * item,
                                               const double seconds);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 016.
 *
 * This function prints the values of the main byte.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a cat021_item016 structure.
 */
ASTERIX_API void print_cat021_item016(const cat021_item016 *item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM016_H */