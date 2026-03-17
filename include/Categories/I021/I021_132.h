/**
 * @file I021_132.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_132_H
#define I021_132_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

#define I021_132_LSB_MAM    (1.0) /// LSB = 1 dBm

/* ================================= ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I021_132
 * @brief Data Item I021/132 - Message Amplitude
 * 
 * Amplitude, in dBm, of ADS-B messages received by the ground  station,
 * coded in two's complement.
 */
typedef struct I021_132
{
    /// @brief Message Amplitude (LSB = 1 dBm)
    u8 MAM;
} I021_132;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/132 (Message Amplitude) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_132 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_132(BitStream *bs, const I021_132 *item);

/**
 * @brief Decode the data item I021/132 (Message Amplitude) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_132 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_132(BitStream *bs, I021_132 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given data item I021/132.
 *
 * @param[in] item Pointer to a I021_132 structure.
 */
ASTERIX_LIB void print_I021_132(const I021_132 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_132_H */