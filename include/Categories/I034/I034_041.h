/**
 * @file I034_041.h
 * @brief
 * @version 0.1
 * @date 2026-02-09
 *
 * @copyright Copyright (c) 2026
 */
#ifndef I034_041_H
#define I034_041_H

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
 * @brief Antenna Rotation Speed LSB = 1/128 seconds
 */
#define I034_042_LSB_ANTROTSPD (0.0078125F)

/* ================================= ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I034_041
 * @brief Data Item I034/041 - Antenna Rotation Speed
 *
 * Antenna rotation period as measured between two consecutive North
 * crossings or as averaged during a period of time
 */
typedef struct I034_041
{
    /**
     * @brief Antenna rotation speed 
     * 
     * LSB = 1/128 seconds
     */
    float ANTROTSPD;
} I034_041;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode item I034/041 (Antenna Rotation Speed) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_041 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_041(BitStream *bs, const I034_041 *item);

/** @brief Decode item I034/041 (Antenna Rotation Speed) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_041 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_041(BitStream *bs, I034_041 *item);

/* ============================== EXTRA FUNCS ============================== */

/** @brief Print the contents of given I034/041 data item.
 *
 * @param[in] item Pointer to a I034_041 structure.
 */
ASTERIX_LIB void print_I034_041(const I034_041 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_041_H */