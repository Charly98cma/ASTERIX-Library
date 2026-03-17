/**
 * @file I021_145.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_145_H
#define I021_145_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

#define I021_145_LSB_FL                    (0.25)         /// LSB = 1/4 FL

/* ================================= ENUMS ================================= */

/**
 * @typedef I021_145
 * @brief Data Item I021/145 - Flight Level
 * 
 * Flight Level from barometric measurements, not QNH corrected,
 * in two's complement form
 */
typedef struct I021_145
{
    /**
     * @brief Flight Level (LSB = 0.25 ft)
     * 
     * Range: [-15 ft, 1500] ft
     */
    float FL;
} I021_145;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/145 (Flight Level) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_145 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_145(BitStream *bs, const I021_145 *item);

/**
 * @brief Decode the data item I021/145 (Flight Level) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_145 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_145(BitStream *bs, I021_145 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given data item I021/145.
 *
 * @param[in] item Pointer to a I021_145 structure.
 */
ASTERIX_LIB void print_I021_145(const I021_145 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_145_H */