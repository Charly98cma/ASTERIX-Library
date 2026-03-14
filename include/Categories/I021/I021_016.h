/**
 * @file I021_016.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_016_H
#define I021_016_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

/// @brief Report Period LSB = 0.5 seconds
#define I021_016_LSB_RP             (0.5)

/* ================================= ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I021_016
 * @brief Data Item 021/016 - Service Management
 * 
 * Identification of services offered by a ground station
 * (identified by a SIC code)
 */
typedef struct I021_016
{
    /** 
     * @brief Report Period in seconds
     * 
     * Range: 0 … 127.5 seconds (value of 127.5 indicates 127.5 or more)
     * 
     * LSB = 0.5 s
     */
    float RP;
} I021_016;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode the data item I021/016 (Service Management) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_016 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_016(BitStream *bs, const I021_016 *item);

/** @brief Decode the data item I021/016 (Service Management) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_016 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_016(BitStream *bs, I021_016 *item);

/* ============================== EXTRA FUNCS ============================== */

/** @brief Print the contents of data item I021/016.
 *
 * @param[in] item Pointer to a I021_016 structure.
 */
ASTERIX_LIB void print_I021_016(const I021_016 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_016_H */