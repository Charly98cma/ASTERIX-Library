/**
 * @file I021_072.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-16
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_072_H
#define I021_072_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

#define I021_072_LSB_TAV    (0.0078125)     /// LSB = 1/128 seconds

/* ================================= ENUMS ================================= */

/**
 * @typedef I021_072
 * @brief Data Item I021/072 - Time of Applicability for Velocity
 *
 * Time of applicability (measurement) of the reported velocity,
 * in the form of elapsed time since last midnight, expressed as UTC
 */
typedef struct I021_072 {
    /// @brief Time of Applicability for Velocity
    float TAV;
} I021_072;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/072 (Time of Applicability for Velocity) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_072 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_072(BitStream *bs, const I021_072 *item);

/**
 * @brief Decode the data item I021/072 (Time of Applicability for Velocity) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_072 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_072(BitStream *bs, I021_072 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given I021/072 data item.
 *
 * @param[in] item Pointer to a I021_072 structure.
 */
ASTERIX_LIB void print_I021_072(const I021_072 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_072_H */