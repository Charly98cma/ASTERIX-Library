/**
 * @file I021_160.h
 * @brief Definition of I021/160, and related functions and values
 */

#ifndef I021_160_H
#define I021_160_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_160_MIN_GRDSPD       (0) /// @brief Min ground speed = 0 NM/s
#define I021_160_MAX_GRDSPD       (2) /// @brief Max ground speed = 2 NM/s

#define I021_160_MIN_TRKANG       (0)     /// @brief Min track angle = 0 degrees
#define I021_160_MAX_TRKANG       (360)   /// @brief Max track angle = 360 degrees

#define I021_160_LSB_GRDSPD       (1.0/P2_14)    /// LSB = 1/2^14 knots
#define I021_160_LSB_TRKANG       (360.0/P2_16)  /// LSB = 360/2^16 degrees

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_160
 * @brief Category 021 / Item 160 - Airborne Ground Vector
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
typedef struct I021_160 {
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
} I021_160;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the "Range Exceeded" Indicator from I021/160
 * 
 * @param item pointer to I021_160 structure
 * 
 * @return uint8_t RE indicator (0: in range, 1: exceeds range)
 */
ASTERIX_API uint8_t get_I021_160_RE(const I021_160 * item);

/**
 * @brief Get the Ground Speed value from I021/160
 * 
 * @param item pointer to I021_160 structure
 * 
 * @return double ground speed in nautical miles per minute (NM/minute)
 */
ASTERIX_API double get_I021_160_GRDSPD(const I021_160 * item);

/**
 * @brief Get the Track Angle value from I021/160
 * 
 * @param item pointer to I021_160 structure
 * 
 * @return double track angle in degrees
 */
ASTERIX_API double get_I021_160_TRKANG(const I021_160 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Range Exceeded indicator (RE) into I021/160
 * 
 * @param item pointer to I021_160 structure
 * @param re new RE indicator (0: within range, 1: exceeds range)
 */
ASTERIX_API void set_I021_160_RE(I021_160 * item, uint8_t re);
/**
 * @brief Set the Ground Speed (GRDSPD) value in NM/min into I021/160
 * 
 * @param item pointer to I021_160 structure
 * @param ground_speed_nmpmin new ground speed value in nautical miles per minute
 *                            (Range: 0 <= ground_speed < 2)
 */
ASTERIX_API void set_I021_160_GRDSPD(I021_160 * item, double ground_speed_nmpmin);
/**
 * @brief Set the Track Angle (TRKANG) value in degrees into I021/160
 * 
 * @param item pointer to I021_160 structure
 * @param track_angle_deg new track angle value in degrees
 */
ASTERIX_API void set_I021_160_TRKANG(I021_160 * item, double track_angle_deg);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/160 (Airborne Ground Vector) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/160 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_160(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);
/** @brief Decode item I021/160 (Airborne Ground Vector) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/160 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_160(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Air Ground Vector data of the I021/160
 * 
 * @param item Pointer to I021_160 structure
 */
ASTERIX_API void print_I021_160(const I021_160 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_160_H */