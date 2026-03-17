/**
 * @file I021_130.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_130_H
#define I021_130_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>
#include <Common/constants.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

#define I021_130_LSB_LAT (180.0 / P2_23) /// LSB = 1/2^23 deg
#define I021_130_LSB_LON (180.0 / P2_23) /// LSB = 1/2^23 deg

/* ================================= ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I021_130
 * @brief Data Item I021/130 - Position in WGS-84 Co-ordinates
 * 
 * Position in WGS-84 Co-ordinates
 */
typedef struct I021_130
{
    /** @brief Latitude in WGS-84 in two's complement (LSB = 180/2^23 deg.)
     * 
     * Range = -90 <= latitude <= 90 deg.
     */
    float LAT;
    /** @brief Longitude in WGS-84 in two's complement (LSB = 180/2^23 deg.)
     * 
     * Range -180 <= longitude < 180 deg.
     */
    float LON;
} I021_130;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/130 (Position in WGS-84 Co-ordinates) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_130 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_130(BitStream *bs, const I021_130 *item);

/**
 * @brief Decode the data item I021/130 (Position in WGS-84 Co-ordinates) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_130 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_130(BitStream *bs, I021_130 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the data item I021/130.
 *
 * @param[in] item Pointer to a I021_130 structure.
 */
ASTERIX_LIB void print_I021_130(const I021_130 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_130_H */
