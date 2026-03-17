/**
 * @file I021_080.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-16
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_080_H
#define I021_080_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

/* ================================== ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I021_080
 * @brief Data Item I021/080 - Target Address
 * 
 * Target ICAO Address.
 */
typedef struct I021_080
{
    /// @brief Target ICAO Address
    u32 TGTADDR;
} I021_080;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/080 (Target Address) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_080 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_080(BitStream *bs, const I021_080 *item);

/**
 * @brief Decode the data item I021/080 (Target Address) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_080 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_080(BitStream *bs, I021_080 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given I021/080 data item.
 *
 * @param[in] item Pointer to a I021_080 structure.
 */
ASTERIX_LIB void print_I021_080(const I021_080 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_080_H */