/**
 * @file I021_157.h
 * @brief Definition of I021/157, and related functions and values
 */

#ifndef I021_157_H
#define I021_157_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_157_LSB_GVR                (6.25)  /// LSB = 6.25 feet/minute

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_157
 * @brief Category 021 / Item 157 - Geometric Vertical Rate
 * 
 * Geometric Vertical Rate, in two's complement form, with reference to WGS-84
 * 
 * @note The RE-Bit, if set, indicates that the value to be transmitted is 
 *       beyond the range defined for this specific data item and the 
 *       applied technology. In this case the Geometric Vertical Rate 
 *       contains the maximum value that can be downloaded from the 
 *       aircraft avionics and the RE-bit indicates that the actual value is 
 *       greater than the value contained in the field. 
 */
typedef struct I021_157 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[2];

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
             * @brief Geometric Vertical Rate
             * 
             * LSB = 6.25 feet/minute
             */
            uint16_t GVR    :15;
        };
    };
} I021_157;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Range Exceeded Indicator (RE) from I021/157
 * 
 * @param item Pointer to I021_157 structure
 * 
 * @return uint8_t Range Exceeded Indicator value (0: in range,
 *                                                 1: exceeds range)
 */
ASTERIX_API uint8_t get_I021_157_RE(const I021_157 * item);

/**
 * @brief Get the Geometric Vertical Rate (GVR) from I021/157 
 * 
 * @param item Pointer to I021_157 structure
 * 
 * @return double GVR value in feets/minute (see LSB)
 */
ASTERIX_API double get_I021_157_GVR(const I021_157 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Range Exceeded Indicator (RE) value into
 *        I021/157
 * 
 * @param item Pointer to I021_157 structure
 * @param re New RE indicator (0: within range, 1: exceeds range)
 */
ASTERIX_API void set_I021_157_RE(I021_157 * item, uint8_t re);

/**
 * @brief Set the given Geometric Vertical Rate (GVR) value (see LSB) into
 *        I021/157
 * 
 * @param item Pointer to I021_157 structure
 * @param gvr_ftpmin New GVR in feets/minute (see LSB)
 */
ASTERIX_API void set_I021_157_GVR(I021_157 * item, double gvr_ftpmin);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/**
 * @brief
 * 
 * @param item_in
 * @param msg_out
 * @param out_index
 * 
 * @return uint16_t
 */
ASTERIX_API uint16_t encode_I021_157(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/**
 * @brief
 * 
 * @param item_in
 * @param msg_in
 * @param in_index
 * 
 * @return uint16_t
 */
ASTERIX_API uint16_t decode_I021_157(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Geometric Vertical Rate data of the I021/157
 * 
 * @param item Pointer to I021_157 structure
 */
ASTERIX_API void print_I021_157(const I021_157 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_157_H */