/**
 * @file I021_130.h
 * @brief Definition of I021/130, and related functions and values
 */

#ifndef I021_130_H
#define I021_130_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_130_LSB_LAT             (180.0/P2_23)    /// LSB = 1/2^23 deg
#define I021_130_LSB_LON             (180.0/P2_23)    /// LSB = 1/2^23 deg

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_130
 * @brief Category 021 / Item 130 - Position in WGS-84 Co-ordinates
 * 
 * Position in WGS-84 Co-ordinates
 */
typedef struct I021_130 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[6];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** @brief Latitude in WGS-84 in two's complement (LSB = 180/2^23 deg.)
             * 
             * Range = -90 <= latitude <= 90 deg.
             */
            uint8_t LAT[3];
            /** @brief Longitude in WGS-84 in two's complement (LSB = 180/2^23 deg.)
             * 
             * Range -180 <= longitude < 180 deg.
             */
            uint8_t LON[3];
        };
    };
} I021_130;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the target Latitude in WGS-84 coordinates from I021/130 
 * 
 * @param item Pointer to I021_130 structure
 * @return double Latitude value in degrees (see LSB)
 */
ASTERIX_API double get_I021_130_LAT(const I021_130 * item);

 /**
 * @brief Get the target Longitude in WGS-84 coordinates from I021/130 
 * 
 * @param item Pointer to I021_130 structure
 * @return double Longitude value in degrees (see LSB)
 */
ASTERIX_API double get_I021_130_LON(const I021_130 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the new Latitude in WGS-84 coordinates into I021/130
 * 
 * @param item Pointer to I021_130 structure
 * @param lan New latitude value in degrees's (see LSB)
 */
ASTERIX_API void set_I021_130_LAT(I021_130 * item, double lat);

/**
 * @brief Set the new Longitude in WGS-84 coordinates into I021/130 
 * 
 * @param item Pointer to I021_130 structure
 * @param lan New longitude value in degrees's (see LSB)
 */
ASTERIX_API void set_I021_130_LON(I021_130 * item, double lon);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/130 (Position in WGS-84 Coordinates) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/130 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_130(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/130 (Position in WGS-84 Coordinates) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/130 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_130(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of I021/130
 * 
 * @param item Pointer to I021_130 structure.
 */
ASTERIX_API void print_I021_130(const I021_130 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_130_H */
