/**
 * @file cat021_item145.h
 * @brief Definition of CAT 021 Item 145, and related functions and values
 */

#ifndef CAT021_ITEM145_H
#define CAT021_ITEM145_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define CAT021_ITEM145_LSB_FL                    (0.25)         /// LSB = 1/4 FL

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item145
 * @brief Category 021 Item 145 - Flight Level
 * 
 * Flight Level from barometric measurements, not QNH corrected,
 * in two's complement form
 */
typedef struct cat021_item145 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint16_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Flight Level (LSB = 0.25 ft)
             * 
             * -15 ft <= Flight Level <= 1500 ft
             */
            uint16_t FL;
        };
    };
} cat021_item145;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Flight Level (FL) from Cat 021 Item 145
 * 
 * @param item Pointer to cat021_item145 structure
 * 
 * @return double flight level in steps of 0.25 FL's (see LSB)
 */
ASTERIX_API uint16_t get_cat021_item145_FL_raw(const cat021_item145 * item);

/**
 * @brief Get the Flight Level (FL) from Cat 021 Item 145 
 * 
 * @param item Pointer to cat021_item145 structure
 * 
 * @return int16_t flight levels
 */
ASTERIX_API int16_t get_cat021_item145_FL_feet(const cat021_item145 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Flight Level (FL) raw value (no LSB) into
 *        Cat 021 Item 145
 * 
 * @param item Pointer to cat021_item145 structure
 * @param value New FL raw value in steps of 1/4 FL (see LSB)
 */
ASTERIX_API void set_cat021_item145_FL_raw(cat021_item145 * item,
                                           const uint16_t fl_raw);

/**
 * @brief Set the given Flight Level (FL) value (see LSB) into
 *        Cat 021 Item 145
 * 
 * @param item Pointer to cat021_item145 structure
 * @param value New FL value (LSB = 0.25 FL)
 */
ASTERIX_API void set_cat021_item145_FL_feet(cat021_item145 * item,
                                            const int16_t fl);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Flight Level of the Cat 021 Item 145
 * 
 * @param item Pointer to cat021_item145 structure
 */
ASTERIX_API void print_cat021_item145(const cat021_item145 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM145_H */