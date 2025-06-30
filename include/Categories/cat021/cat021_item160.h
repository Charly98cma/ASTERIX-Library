/**
 * @file cat021_item160.h
 * @brief Definition of CAT 021 Item 160, and related functions and values
 */

#ifndef CAT021_ITEM160_H
#define CAT021_ITEM160_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define CAT021_ITEM160_MIN_GRDSPD       (0) /// @brief Min ground speed = 0 NM/s
#define CAT021_ITEM160_MAX_GRDSPD       (2) /// @brief Max ground speed = 2 NM/s

#define CAT021_ITEM160_MIN_TRKANG       (0)     /// @brief Min track angle = 0 degrees
#define CAT021_ITEM160_MAX_TRKANG       (360)   /// @brief Max track angle = 360 degrees

#define CAT021_ITEM160_LSB_GRDSPD      (double) (1/P2_14)      /// LSB = 1/2^14 knots
#define CAT021_ITEM160_LSB_TRKANG      (double) (360/P2_16)    /// LSB = 360/2^16 degrees

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item160
 * @brief Category 021 Item 160 - Airborne Ground Vector
 * 
 * Ground Speed and Track Angle elements of Airborne Ground Vector.
 * 
 * @note The RE-Bit, if set, indicates that the value to be transmitted is
 *       beyond the range defined for this specific data item and the applied
 *       technology. In this case the Ground Speed contains the maximum value
 *       that can be downloaded from the aircraft avionics and the RE-bit
 *       indicates that the actual value is greater than the value contained
 *       in the field.
 * @note The Surface Ground Vector format is defined in the Reserved Expansion
 *       Field in the subfield SGV.
 */
typedef struct cat021_item160 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[4];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Range Exceeded Indicator
             * 
             * = 0: value within defined range | = 1: value exceeds defines range
             */
            uint16_t RE     :1;
            /**
             * @brief Ground Speed referenced to WGS-84
             * 
             * Range: 0 <= GRDSPD < 2 NM/s
             * 
             * LSB = 1/2^14 NM/s = 0.22 knots
            */
           uint16_t GRDSPD  :15;
           /**
            * @brief Track Angle clockwise reference to "True North"
            * 
            * LSB = 360/2^16 degrees
            */
           uint16_t TRKANG;
        };
    };
} cat021_item160;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the "Range Exceeded" Indicator from CAt 021 Item 160
 * 
 * @param item pointer to cat021_item160 structure
 * 
 * @return uint8_t RE indicator (0: in range, 1: exceeds range)
 */
ASTERIX_API uint8_t get_cat021_item160_RE(const cat021_item160 * item);

/**
 * @brief Get the Ground Speed value from Cat 021 Item 160
 * 
 * @param item pointer to cat021_item160 structure
 * 
 * @return double ground speed in nautical miles per minute (NM/minute)
 */
ASTERIX_API double get_cat021_item160_GRDSPD(const cat021_item160 * item);

/**
 * @brief Get the Track Angle value from Cat 021 Item 160
 * 
 * @param item pointer to cat021_item160 structure
 * 
 * @return double track angle in degrees
 */
ASTERIX_API double get_cat021_item160_TRKANG(const cat021_item160 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Range Exceeded indicator (RE) into Cat 021 Item 160
 * 
 * @param item pointer to cat021_item160 structure
 * @param re new RE indicator (0: within range, 1: exceeds range)
 */
ASTERIX_API void set_cat021_item160_RE(cat021_item160 * item, uint8_t re);
/**
 * @brief Set the Ground Speed (GRDSPD) value in NM/min into Cat 021 Item 160
 * 
 * @param item pointer to cat021_item160 structure
 * @param ground_speed new ground speed value in nautical miles per minute
 *                     (Range: 0 <= ground_speed < 2)
 */
ASTERIX_API void set_cat021_item160_GRDSPD(cat021_item160 * item,
                                           double ground_speed);
/**
 * @brief Set the Track Angle (TRKANG) value in degrees into Cat 021 Item 160
 * 
 * @param item pointer to cat021_item160 structure
 * @param track_angle new track angle value in degrees
 */
ASTERIX_API void set_cat021_item160_TRKANG(cat021_item160 * item,
                                           double track_angle);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Air Ground Vector data of the Cat 021 Item 160
 * 
 * @param item Pointer to cat021_item160 structure
 */
ASTERIX_API void print_cat021_item160(const cat021_item160 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM160_H */