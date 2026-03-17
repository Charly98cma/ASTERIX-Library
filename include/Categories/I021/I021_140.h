/**
 * @file I021_140.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_140_H
#define I021_140_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

#define I021_140_LSB_GH (6.25)  /// LSB = 6.25 ft

/* ================================= ENUMS ================================= */

/**
 * @typedef I021_140
 * @brief Data Item I021/140 - Geometric Height
 * 
 * Minimum height from a plane tangent to the earth’s ellipsoid, defined by
 * WGS-84, in two's complement form.
 */
typedef struct I021_140
{
    /**
     * @brief Geometric Height (LSB = 6.25 ft)
     * 
     * Range: [-1500 ft, 150000] ft
     */
    float GH;
} I021_140;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/140 (Geometric Height) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_140 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_140(BitStream *bs, const I021_140 *item);

/**
 * @brief Decode the data item I021/140 (Geometric Height) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_140 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_140(BitStream *bs, I021_140 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given data item I021/140.
 *
 * @param[in] item Pointer to a I021_140 structure.
 */
ASTERIX_LIB void print_I021_140(const I021_140 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_140_H */