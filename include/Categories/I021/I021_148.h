/**
 * @file I021_148.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_148_H
#define I021_148_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

#define I021_148_LSB_ALT    (25.0)  /// LSB = 25 ft

/* ================================= ENUMS ================================= */

typedef enum eI021_148_MV
{
    eI021_148_MV_NOT_ACTIVE,    // Not active / Unknown
    eI021_148_MV_ACTIVE,        // Active
} eI021_148_MV;

typedef enum eI021_148_AH
{
    eI021_148_AH_NOT_ACTIVE, // Not active / Unknown
    eI021_148_AH_ACTIVE,     // Active
} eI021_148_AH;

typedef enum eI021_148_AM
{
    eI021_148_AM_NOT_ACTIVE, // Not active / Unknown
    eI021_148_AM_ACTIVE,     // Active
} eI021_148_AM;

/* ================================= STRUCTS ================================= */

/**
 * @typedef I021_148
 * @brief Data Item I021/148 - Final State Selected Altitude
 *
 * The vertical intent value that corresponds with the ATC cleared altitude,
 * as derived from the Altitude Control Panel (MCP/FCU).
 */
typedef struct I021_148
{
    /// @brief Manage Vertical Mode
    eI021_148_MV    MV;
    /// @brief Altitude Hold Mode
    eI021_148_AH    AH;
    /// @brief Approach Mode
    eI021_148_AM    AM;
    /** @brief Altitude in two's complement form (LSB = 25 ft)
     * 
     * Range: [-1300, 100000] ft
     */
    s16             ALT;
} I021_148;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/148 (Final State Selected Altitude) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_148 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_148(BitStream *bs, const I021_148 *item);

/**
 * @brief Decode the data item I021/148 (Final State Selected Altitude) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_148 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_148(BitStream *bs, I021_148 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given data item I021/148.
 *
 * @param[in] item Pointer to a I021_148 structure.
 */
ASTERIX_LIB void print_I021_148(const I021_148 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_148_H */