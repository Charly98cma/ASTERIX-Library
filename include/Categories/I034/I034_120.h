/**
 * @file I034_120.h
 * @brief Definition of I034/120, and related functions and values
 */

#ifndef I034_120_H
#define I034_120_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/// @brief LSB value for Latitude in WGS84 (in degrees)
#define I034_120_LSB_LATWGS84         (180.0 / P2_23)

/// @brief LSB value for Longitude in WGS84 (in degrees)
#define I034_120_LSB_LONWGS84         (180.0 / P2_23)

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I034_120
 * @brief Category 034 / Item 120 - 3D-Position Of Data Source.
 *
 * 3D-Position of Data Source in WGS 84 Co-ordinates.
 */
typedef struct
{
    union
    {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[8];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct
        {
            /**
             * @brief Signed Height of the Data Source, expressed in meters above WGS 84 reference ellipsoid.
             * 
             * LSB: 1 meter.
             */
            int16_t HEIGHT;
            /**
             * @brief Latitude in WGS 84 expressed in two’s complement.
             * 
             * Range: -90 to +90 degrees.
             * 
             * LSB: 180/2^23 degrees.
             */
            uint8_t LATWGS84[3];
            /**
             * @brief Longitude in WGS 84 expressed in two’s complement.
             *
             * Range: -180 to +180 degrees.
             *
             * LSB: 180/2^23 degrees.
             */
            uint8_t LONWGS84[3];
        };
    };
} I034_120;

/*******************************************************************************
 * Getters
 ******************************************************************************/

 /** @brief Get the signed height of the data source (meters above WGS84 ellipsoid).
 *
 * @param item Pointer to an I034_120 structure.
 * 
 * @return Height in meters.
 */
ASTERIX_API int16_t get_I034_120_HEIGHT(const I034_120 *item);

/** @brief Get the latitude of the data source in WGS84 degrees.
 *
 * @param item Pointer to an I034_120 structure.
 *
 * @return Latitude in degrees (LSB = 180/2^23) (Range: [-90.0, +90.0]).
 */
ASTERIX_API float get_I034_120_LATWGS84(const I034_120 *item);

/** @brief Get the longitude of the data source in WGS84 degrees.
 *
 * @param item Pointer to an I034_120 structure.
 * 
 * @return Longitude in degrees (LSB = 180/2^23) (Range: [-180.0 .. +180.0)).
 */
ASTERIX_API float get_I034_120_LONWGS84(const I034_120 *item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/** @brief Set the signed height of the data source (meters above WGS84 ellipsoid).
 *
 * @param item Pointer to an I034_120 structure to modify.
 * @param height Height in meters as a signed 16-bit integer.
 */
ASTERIX_API void set_I034_120_HEIGHT(I034_120 *item, int16_t height);

/** @brief Set the latitude of the data source in WGS84 degrees.
 *
 * @param item Pointer to an I034_120 structure to modify.
 * @param lat_wgs84 Latitude in degrees (Range: [-90.0, +90.0]).
 */
ASTERIX_API void set_I034_120_LATWGS84(I034_120 *item, float lat_wgs84);

/** @brief Set the longitude of the data source in WGS84 degrees.
 *
 * @param item Pointer to an I034_120 structure to modify.
 * @param lon_wgs84 Longitude in degrees (Range: [-180.0 .. +180.0)).
 */
ASTERIX_API void set_I034_120_LONWGS84(I034_120 *item, float lon_wgs84);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item 034/120 into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I034_120 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I034_120(void *item_in,
                                     unsigned char *msg_out,
                                     uint16_t out_index);

/** @brief Decode item 034/120 from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I034_120 structure.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 *
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I034_120(void *item_out,
                                     const unsigned char *msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/** @brief Print the contents of item 034/120.
 *
 * @param item Pointer to the input I034_120 structure.
 */
ASTERIX_API void print_I034_120(const I034_120 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_120_H */