/**
 * @file I034_120.h
 * @brief 
 * @version 0.1
 * @date 2026-02-10
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef I034_120_H
#define I034_120_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

/// @brief Latitude in WGS84 LSB = 180/2^23 degrees
#define I034_120_LSB_LATWGS84   (0.1200042915344238F)

/// @brief Longitude in WGS84 LSB = 180/2^23 degrees
#define I034_120_LSB_LONWGS84   (0.1200042915344238F)

/* ================================= ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I034_120
 * @brief Data item I034/120 - 3D-Position Of Data Source.
 *
 * 3D-Position of Data Source in WGS 84 Co-ordinates.
 */
typedef struct
{
    /// @brief Height of the Data Source (meters above WGS 84 reference ellipsoid)
    u16 HEIGHT;
    /**
     * @brief Latitude in WGS 84
     * 
     * Range = [-90 to 90] degrees
     * 
     * LSB = 180/2^23 degrees
     */
    float LATWGS84;
    /**
     * @brief Longitude in WGS 84
     * 
     * Range = [-180 to 180] degrees
     * 
     * LSB = 180/2^23 degrees
     */
    float LONWGS84;
} I034_120;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode item I034/120 (3D-Position Of Data Source) into a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_120 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_120(BitStream *bs, const I034_120 *item);

/** @brief Decode item I034/120 (3D-Position Of Data Source) from a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_120 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_120(BitStream *bs, I034_120 *item);

/* ============================== EXTRA FUNCS ============================== */

/** @brief Print the contents of the given I034/120 data item.
 *
 * @param item Pointer to the I034_120 structure.
 */
ASTERIX_LIB void print_I034_120(const I034_120 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_120_H */