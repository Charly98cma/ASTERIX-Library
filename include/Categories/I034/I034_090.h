/**
 * @file I034_090.h
 * @brief
 * @version 0.1
 * @date 2026-02-09
 *
 * @copyright Copyright (c) 2026
 */
#ifndef I034_090_H
#define I034_090_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* ================================= MACROS ================================= */

/// @brief Range Error LSB = 1/128 NM
#define I034_090_LSB_RANGEERR (0.0078125F)

/// @brief Azimiuth Error LSB = 360/2^14 degrees
#define I034_090_LSB_AZERR (0.02197265625F)

/* ================================= ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I034_090
 * @brief Data Item I034/090 - Collimation Error
 *
 * Averaged difference in range and in azimuth for the primary target
 * position with respect to the SSR target position as calculated by the radar
 * station.
 *
 * @note Format: Two-octet fixed length Data Item.
 * @note Negative values are coded in two’s complement form.
 */
typedef struct I034_090
{
    /**
     * @brief Range Error
     * 
     * LSB = 1/2^7 NM
     */
    float RANGEERR;
    /**
     * @brief Azimuth Error
     * 
     * LSB = 360/2^14 degrees
     */
    float AZERR;
} I034_090;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode item I034/090 (Collimation Error) into a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_090 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_090(BitStream *bs, const I034_090 *item);

/** @brief Decode item I034/090 (Collimation Error) from a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_090 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_090(BitStream *bs, I034_090 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of given I034/090 data item.
 *
 * @param item Pointer to a I034_090 structure.
 */
ASTERIX_LIB void print_I034_090(const I034_090 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_090_H */