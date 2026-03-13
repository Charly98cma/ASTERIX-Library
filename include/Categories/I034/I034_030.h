/**
 * @file I034_030.h
 * @brief 
 * @version 0.1
 * @date 2026-02-10
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef I034_030_H
#define I034_030_H

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
 * @brief Time of the Dat LSB = 1/128
 */
#define I034_030_LSB_TOD    (0.0078125F)

/* ================================= ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I034_030
 * @brief Data Item 034/030 - Time of the Day (TOD)
 *
 * Absolute time stamping expressed as UTC time.
 */
typedef struct I034_030
{
    /**
     * @brief Time of Day in seconds since midnight
     * 
     * LSB = 1/128 seconds
     */
    float TOD;
} I034_030;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode data item I034/030 (Time of Day) into a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_030 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_030(BitStream *bs, const I034_030 *item);

/** @brief Decode data item I034/030 (Time of Day) from a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_030 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_030(BitStream *bs, I034_030 *item);

/* ============================== EXTRA FUNCS ============================== */

/** @brief Print the contents of item given 034/030 data item.
 *
 * @param[in] item Pointer to a I034_030 structure.
 */
ASTERIX_LIB void print_I034_030(const I034_030 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_030_H */