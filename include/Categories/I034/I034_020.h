/**
 * @file I034_020.h
 * @brief
 * @version 0.1
 * @date 2026-02-09
 *
 * @copyright Copyright (c) 2026
 */
#ifndef I034_020_H
#define I034_020_H

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

/**
 * @brief Sector Number LSB = 360/2^8 degrees
 */
#define I034_020_LSB_SECTNUM (1.40625F)

/* ================================= ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I034_020
 * @brief Data Item I034/020 - Sector Number
 */
typedef struct I034_020
{
    /**
     * @brief Sector azimuth in degrees
     * 
     * Range = [0 - 358.59375] degrees
     * 
     * LSB = 360/2^8 degrees
     */
    float SECTAZ;
} I034_020;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode the data item I034/020 (Sector Number) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_020 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_020(BitStream *bs, const I034_020 *item);

/** @brief Decode the data item I034/020 (Sector Number) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_020 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_020(BitStream *bs, I034_020 *item);

/* ============================== EXTRA FUNCS ============================== */

/** @brief Print the contents of item 034/020 data item.
 *
 * @param[in] item Pointer to a I034_020 structure.
 */
ASTERIX_LIB void print_I034_020(const I034_020 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_020_H */