/**
 * @file I021_131.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_131_H
#define I021_131_H

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

#define I021_131_LSB_LAT             (180.0/P2_30)    /// LSB = 1/2^30 deg
#define I021_131_LSB_LON             (180.0/P2_30)    /// LSB = 1/2^30 deg

/* ================================= ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I021_131
 * @brief Data Item I021/131 - High-Resolution Position in WGS-84 Co-ordinates
 * 
 * High-Resolution Position in WGS-84 Co-ordinates
 */
typedef struct I021_131
{
    /** @brief Latitude in WGS-84 in two's complement (LSB = 180/2^30 deg.)
     * 
     * Range = -90 <= latitude <= 90 deg.
     */
    float LAT;
    /** @brief Longitude in WGS-84 in two's complement (LSB = 180/2^30 deg.)
     * 
     * Range -180 <= longitude < 180 deg.
     */
    float LON;
} I021_131;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/131 (High-Resolution Position WGS-84 Coordinates) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_131 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_131(BitStream *bs, const I021_131 *item);

/**
 * @brief Decode the data item I021/131 (High-Resolution Position WGS-84 Coordinates) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_131 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_131(BitStream *bs, I021_131 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the data item I021/131.
 *
 * @param[in] item Pointer to a I021_131 structure.
 */
ASTERIX_LIB void print_I021_131(const I021_131 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_131_H */
