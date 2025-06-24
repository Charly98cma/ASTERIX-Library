/**
 * @file cat021_item150.h
 * @brief Definition of CAT 021 Item 150, and related functions and values
 */

#ifndef CAT021_ITEM150_H
#define CAT021_ITEM150_H

#include <stdio.h>
#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * Macros
 ******************************************************************************/

#define CAT021_ITEM150_IM_IAS           0
#define CAT021_ITEM150_IM_MACH          1

#define LSB_CAT021_ITEM150_IAS          (double) (1/P2_14)  /// LSB = 2^-14 NM/s
#define LSB_CAT021_ITEM150_MACH         (double) (0.25)     /// LSB = 0-001

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item150
 * @brief Category 021 Item 150 - Air Speed
 * 
 * Calculated Air Speed (Element of Air Vector).
 */
typedef struct cat021_item150 {
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
             * @brief IM
             * 
             * = 0: IAS | = 1: Mach
             */
            uint16_t IM;
            /**
             * @brief Air Speed (IAS or MACH)
             * 
             * if IAS LSB = 2^-14 | if MACH LSB = 0.001
             */
            uint16_t AIRSPD;
        };
    };
} cat021_item150;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Airspeed Mode (IM) from Cat 021 Item 150
 * 
 * @param item Pointer to cat021_item150 structure
 * 
 * @return uint8_t Air Speed mode (0: IAS, 1: MACH)
 */
ASTERIX_API uint8_t get_cat021_item150_IM(const cat021_item150 * item);

/**
 * @brief Get the Air Speed (AIRSPD) from Cat 021 Item 150 
 * 
 * The data in this fields changes based on the value of the field IM,
 * which can be IAS or MACH Air Speed.
 * 
 * @param item Pointer to cat021_item150 structure
 * 
 * @return double Air Speed (IAS - LSB 1/2^14 NM/s, or MACH - LSB = 0.001)
 */
ASTERIX_API double get_cat021_item150_AIRSPD(const cat021_item150 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Airspeed Mode (IM) value into Cat 021 Item 150
 * 
 * @param item Pointer to cat021_item150 structure
 * @param value New IM value (0: IAS, 1: MACH)
 */
ASTERIX_API void set_cat021_item150_IM(cat021_item150 * item, uint8_t im);

/**
 * @brief Set the given Air Speed (AIRSPD) value (see LSB for each mode) into
 *        Cat 021 Item 150
 * 
 * @param item Pointer to cat021_item150 structure
 * @param value New Air Speed (IAS LSB = 1/ 2^14 NM/s, MACH LSB = 0.001)
 */
ASTERIX_API void set_cat021_item150_FL_feet(cat021_item150 * item, double value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Flight Level of the Cat 021 Item 150
 * 
 * @param item Pointer to cat021_item150 structure
 */
ASTERIX_API void print_cat021_item150(const cat021_item150 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM150_H */