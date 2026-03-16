/**
 * @file I021_073.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-16
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_073_H
#define I021_073_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

#define I021_073_LSB_TMRP    (0.0078125)     /// LSB = 1/128 seconds

/* ================================= ENUMS ================================= */

/**
 * @typedef I021_073
 * @brief Data Item I021/073 - Time of Message Reception of Position
 *
 * Time of reception of the latest position squitter in the Ground
 * Station, in the form of elapsed time since last midnight, expressed as UTC
 */
typedef struct I021_073 {
    /// @brief Time of Message Reception of Position
    float TMRP;
} I021_073;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/073 (Time of Message Reception of Position) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_073 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_073(BitStream *bs, const I021_073 *item);

/**
 * @brief Decode the data item I021/073 (Time of Message Reception of Position) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_073 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_073(BitStream *bs, I021_073 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given I021/073 data item.
 *
 * @param[in] item Pointer to a I021_073 structure.
 */
ASTERIX_LIB void print_I021_073(const I021_073 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_073_H */