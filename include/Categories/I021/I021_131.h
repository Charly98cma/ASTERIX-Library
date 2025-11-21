/**
 * @file I021_131.h
 * @brief Definition of I021/131, and related functions and values
 */

#ifndef I021_131_H
#define I021_131_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_131_LSB_LAT             (180.0/P2_30)    /// LSB = 1/2^30 deg
#define I021_131_LSB_LON             (180.0/P2_30)    /// LSB = 1/2^30 deg

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_131
 * @brief Category 021 / Item 131 - High-Resolution Position in WGS-84 Co-ordinates
 * 
 * High-Resolution Position in WGS-84 Co-ordinates
 */
typedef struct I021_131 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[8];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** @brief Latitude in WGS-84 in two's complement (LSB = 180/2^30 deg.)
             * 
             * Range = -90 <= latitude <= 90 deg.
             */
            uint8_t LAT[4];
            /** @brief Longitude in WGS-84 in two's complement (LSB = 180/2^30 deg.)
             * 
             * Range -180 <= longitude < 180 deg.
             */
            uint8_t LON[4];
        };
    };
} I021_131;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the target Latitude in WGS-84 coordinates from I021/131 
 * 
 * @param item Pointer to I021_131 structure
 * @return double High-resolution latitude value in degrees (see LSB)
 */
ASTERIX_API double get_I021_131_LAT(const I021_131 * item);

 /**
 * @brief Get the target Longitude in WGS-84 coordinates from I021/131 
 * 
 * @param item Pointer to I021_131 structure
 * @return double High-resolution longitude value in degrees (see LSB)
 */
ASTERIX_API double get_I021_131_LON(const I021_131 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the new Latitude in High-Resolution Position in WGS-84
 *        coordinates into I021/130
 * 
 * @param item Pointer to I021_131 structure
 * @param lan New high-resolution latitude (in range -90:90) value in degrees's (see LSB)
 */
ASTERIX_API void set_I021_131_LAT(I021_131 * item, double lat);

/**
 * @brief Set the new Longitude in High-Resolution Position in WGS-84
 *        coordinates into I021/130 
 * 
 * @param item Pointer to I021_131 structure
 * @param lan New high-resolution longitude (in range -180:180) value in degrees's (see LSB)
 */
ASTERIX_API void set_I021_131_LON(I021_131 * item, double lon);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/131 (High-Resolution Position WGS-84 Coordinates) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/131 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_131(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/131 (High-Resolution Position WGS-84 Coordinates) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/131 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_131(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of I021/131
 * 
 * @param item Pointer to I021_131 structure.
 */
ASTERIX_API void print_I021_131(const I021_131 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_131_H */
