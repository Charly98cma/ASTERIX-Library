/**
 * @file I021_151.h
 * @brief Definition of I021/151, and related functions and values
 */

#ifndef I021_151_H
#define I021_151_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_151_LSB_TAS          (1.0)                   /// LSB = 1 knot

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_151
 * @brief Category 021 / Item 151 - True Air Speed
 * 
 * True Air Speed.
 * 
 * @note The RE-Bit, if set, indicates that the value to be transmitted
 *       is beyond the range defined for this specific data item and the
 *       applied technology. In this case the True Air Speed contains the
 *       maximum value that can be downloaded from the aircraft avionics and
 *       the RE-bit indicates that the actual value is greater than the value
 *       contained in the field.
 */
typedef struct I021_151 {
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
             * @brief True Air Speed
             * 
             * LSB = 1 knot
             */
            uint16_t TAS    :15;
        };
    };
} I021_151;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Range Exceeded Indicator (RE) from I021/151
 * 
 * @param item Pointer to I021_151 structure
 * 
 * @return uint8_t Range Exceeded Indicator value (0: in range,
 *                                                 1: exceeds range)
 */
ASTERIX_API uint8_t get_I021_151_RE(const I021_151 * item);

/**
 * @brief Get the True Air Speed (TAS) from I021/151 
 * 
 * @param item Pointer to I021_151 structure
 * 
 * @return uint16_t True Air Speed value in knots (LSB = 1 knot)
 */
ASTERIX_API uint16_t get_I021_151_TAS(const I021_151 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Range Exceeded Indicator (RE) value into
 *        I021/151
 * 
 * @param item Pointer to I021_151 structure
 * @param re New RE indicator (0: within range, 1: exceeds range)
 */
ASTERIX_API void set_I021_151_RE(I021_151 * item, uint8_t re);

/**
 * @brief Set the given True Air Speed (TAS) value (LSB = 1 knot) into
 *        I021/151
 * 
 * @param item Pointer to I021_151 structure
 * @param tas_kts New True Air Speed in knots
 */
ASTERIX_API void set_I021_151_TAS(I021_151 * item, uint16_t tas_kts);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/151 (True Speed) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/151 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_151(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/151 (True Speed) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/151 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_151(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the True Air Speed data of the I021/151
 * 
 * @param item Pointer to I021_151 structure
 */
ASTERIX_API void print_I021_151(const I021_151 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_151_H */