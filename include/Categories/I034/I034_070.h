/**
 * @file I034_070.h
 * @brief 
 * @version 0.1
 * @date 2026-02-10
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef I034_070_H
#define I034_070_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>
#include <Common/versions.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

/// @brief Max. number of Message Count Values (change as needed)
#define I034_070_MAX_REP                255

/* ================================= ENUMS ================================= */

typedef enum eI034_070_TYP
{
    eI034_070_TYP_MISSES = 0,           /* No detection (number of misses) */
    eI034_070_TYP_SING_PSR_REP,         /* Single PSR target reports */
    eI034_070_TYP_SING_SSR_REP,         /* Single SSR target reports (Non-Mode S) */
    eI034_070_TYP_SSR_PSR_REP,          /* SSR+PSR target reports (Non-Mode S) */
    eI034_070_TYP_SING_ACALL_REP,       /* Single All-Call target reports (Mode S) */
    eI034_070_TYP_SING_RCALL_REP,       /* Single Roll-Call target reports (Mode S) */
    eI034_070_TYP_ACALL_PSR_REP,        /* All-Call + PSR (Mode S) target reports */
    eI034_070_TYP_RCALL_PSR_REP,        /* Roll-Call + PSR (Mode S) target reports */
    eI034_070_TYP_FIL_WEATHER,          /* Filter for Weather data */
    eI034_070_TYP_FIL_JAMM_STR,         /* Filter for Jamming Strobe */
    eI034_070_TYP_FIL_PSR,              /* Filter for PSR data */
    eI034_070_TYP_FIL_SSR_MS,           /* Filter for SSR/Mode S data */
    eI034_070_TYP_FIL_SSR_MS_PSR,       /* Filter for SSR/Mode S+PSR data */
    eI034_070_TYP_FIL_ENHS,             /* Filter for Enhanced Surveillance data */
    eI034_070_TYP_FIL_PSR_ENHS,         /* Filter for PSR+Enhanced Surveillance */
    eI034_070_TYP_FIL_PSR_ENHS_SSRMS,   /* Filter for PSR+Enhanced Surveillance + SSR/Mode S data not in Area of Prime Interest */
    eI034_070_TYP_FIL_PSR_ENHS_MS,      /* Filter for PSR+Enhanced Surveillance + all SSR/Mode S data */
#if ((EDITION_NUMBER_I034 >= 1) && (VERSION_NUMBER_I034 >= 28))
    eI034_070_TYP_REINT,                /* Re-Interrogations (per sector) */
    eI034_070_TYP_BDSSWAP_WRONGDFREP,   /* BDS Swap and wrong DF replies (per sector) */
    eI034_070_TYP_MODEAC_FRUIT,         /* Mode A/C FRUIT (per sector) */
    eI034_070_TYP_MS_FRUIT,             /* Mode S FRUIT (per sector) */
#endif
} eI034_070_TYP;

/* ================================= STRUCTS ================================= */

/**
 * @typedef I034_070
 * @brief Data Item 034/070 - Message Count Values
 *
 * Message Count values, according the various types of messages. The values
 * are collected for the last completed antenna revolution, counted between two
 * North crossings unless otherwise stated in the TYP definition below.
 */
typedef struct I034_070
{
    /// @brief Repetition Factor of counters following
    u8 REP;

    struct COUNTER
    {
        /// @brief Type of message counter
        eI034_070_TYP TYP;
        /// @brief 11-bit counter value
        u16 COUNTER;
    } COUNTER[I034_070_MAX_REP];
} I034_070;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode item I034/070 (Message Count Values) into a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_060 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_070(BitStream *bs, const I034_070 *item);

/** @brief Decode item I034/070 (Message Count Values) from a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_060 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_070(BitStream *bs, I034_070 *item);

/* ============================== EXTRA FUNCS ============================== */

/** @brief Print the contents of the given I034/070 data item.
 *
 * @param[in] item Pointer to a I034_070 structure.
 */
ASTERIX_LIB void print_I034_070(const I034_070 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_070_H */