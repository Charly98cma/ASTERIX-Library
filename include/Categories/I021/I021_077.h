/**
 * @file I021_077.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-16
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_077_H
#define I021_077_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

#define I021_077_LSB_TART    (0.0078125)     /// LSB = 1/128 seconds

/* ================================= ENUMS ================================= */

/**
 * @typedef I021_077
 * @brief Data Item I021/077 - Time of ASTERIX Report Transmission
 *
 * Time of applicability (measurement) of the reported velocity,
 * in the form of elapsed time since last midnight, expressed as UTC
 */
typedef struct I021_077 {
    /// @brief Time of ASTERIX Report Transmission
    float TART;
} I021_077;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/077 (Time of ASTERIX Report Transmission) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_077 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_077(BitStream *bs, const I021_077 *item);

/**
 * @brief Decode the data item I021/077 (Time of ASTERIX Report Transmission) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_077 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_077(BitStream *bs, I021_077 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given I021/077 data item.
 *
 * @param[in] item Pointer to a I021_077 structure.
 */
ASTERIX_LIB void print_I021_077(const I021_077 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_077_H */