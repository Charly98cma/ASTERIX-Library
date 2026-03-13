/**
 * @file I034_010.h
 * @brief 
 * @version 0.1
 * @date 2026-02-09
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef I034_010_H
#define I034_010_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>
#include <Categories/SAC_SIC.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* ================================= MACROS ================================= */

/* ================================= ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I034_010
 * @brief Data Item 034/010 - Data Source Identification
 *
 * Identification of the radar station from which the data are received.
 *
 * @note Item present in every ASTERIX record
 */
typedef SAC_SIC I034_010;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I034/010 (Data source Identification) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_010 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_010(BitStream *bs, const I034_010 *item);

/**
 * @brief Decode the data item I034/010 (Data source Identification) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_010 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_010(BitStream *bs, I034_010 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given I034/010 data item.
 *
 * @param item Pointer to a I034_010 structure.
 */
ASTERIX_LIB void print_I034_010(const I034_010 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_010_H */