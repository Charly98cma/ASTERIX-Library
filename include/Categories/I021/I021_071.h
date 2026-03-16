/**
 * @file I021_071.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-16
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_071_H
#define I021_071_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

#define I021_071_LSB_TAP    (0.0078125)     /// LSB = 1/128 seconds

/* ================================= ENUMS ================================= */

/**
 * @typedef I021_071
 * @brief Data Item I021/071 - Time of Applicability for Position
 * 
 * Time of applicability of the reported position, in the form of
 * elapsed time since last midnight, expressed as UTC.
 */
typedef struct I021_071 {
    /// @brief Time of Applicability for Position
    float TAP;
} I021_071;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/071 (Time of Applicability for Position) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_071 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_071(BitStream *bs, const I021_071 *item);

/**
 * @brief Decode the data item I021/071 (Time of Applicability for Position) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_071 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_071(BitStream *bs, I021_071 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given I021/071 data item.
 *
 * @param[in] item Pointer to a I021_071 structure.
 */
ASTERIX_LIB void print_I021_071(const I021_071 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_071_H */