/**
 * @file I034_110.h
 * @brief 
 * @version 0.1
 * @date 2026-02-10
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef I034_110_H
#define I034_110_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* ================================= MACROS ================================= */

/* ================================= ENUMS ================================= */

typedef enum eI034_110_TYP_T
{
    eI034_110_TYP_WEATHER = 1,     /* Filter for Weather data */
    eI034_110_TYP_JAMM_STR,        /* Filter for Jamming Strobe */
    eI034_110_TYP_PSR,             /* Filter for PSR data */
    eI034_110_TYP_SSR_MS,          /* Filter for SSR/Mode S data */
    eI034_110_TYP_SSR_MS_PSR,      /* Filter for SSR/Mode S+PSR data */
    eI034_110_TYP_ENHS,            /* Filter for Enhanced Surveillance data */
    eI034_110_TYP_PSR_ENHS,        /* Filter for PSR+Enhanced Surveillance */
    eI034_110_TYP_PSR_ENHS_SSRMS,  /* Filter for PSR+Enhanced Surveillance + SSR/Mode S data not in Area of Prime Interest */
    eI034_110_TYP_PSR_ENHS_MS,     /* Filter for PSR+Enhanced Surveillance + all SSR/Mode S data */
} eI034_110_TYP;

/* ================================= STRUCTS ================================= */

/**
 * @typedef I034_110
 * @brief Data Item 034/110 - Data Filter
 *
 * Data Filter, which allows suppression of individual data types
 */
typedef struct I034_110
{
    /// @brief Data Filter Type
    eI034_110_TYP TYP;
} I034_110;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode item I034/110 (Data Filter) into a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_110 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_110(BitStream *bs, const I034_110 *item);

/** @brief Decode item I034/110 (Data Filter) from a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_110 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_110(BitStream *bs, I034_110 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given I034/110 data item.
 *
 * @param item Pointer to a I034_110 structure.
 */
ASTERIX_LIB void print_I034_110(const I034_110 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_110_H */