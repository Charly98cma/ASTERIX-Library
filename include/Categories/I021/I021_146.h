/**
 * @file I021_146.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_146_H
#define I021_146_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

#define I021_146_LSB_ALT    (25.0)  /// LSB = 25 ft

/* ================================= ENUMS ================================= */

typedef enum eI021_146_SAS
{
    eI021_146_SAS_NO_SOURCE,    // No source information provided
    eI021_146_SAS_SOURCE,       // Source Information provided
} eI021_146_SAS;

typedef enum eI021_146_SRC
{
    eI021_146_SRC_UNKNOWN,  // Unknown
    eI021_146_SRC_AC_ALT,   // Aircraft Altitude (Holding Altitude)
    eI021_146_SRC_MCP_FCU,  // MCP/FCU Selected Altitude
    eI021_146_SRC_FMS,      // FMS Selected Altitude
} eI021_146_SRC;

/* ================================= STRUCTS ================================= */

/**
 * @typedef I021_146
 * @brief Data Item I021/146 - Selected Altitude
 *
 * The Selected Altitude as provided by the avionics and
 * corresponding either to the MCP/FCU Selected Altitude (the ATC
 * cleared altitude entered by the flight crew into the avionics) or to
 * the FMS Selected Altitude
 */
typedef struct I021_146
{
    /// @brief Source Availability
    eI021_146_SAS   SAS;
    /// @brief Selected Altitude Source
    eI021_146_SRC   SRC;
    /** @brief Altitude in two’s complement form (LSB = 25 ft)
     * 
     * Range: [-1300ft, 100000] ft
     */
    s16             ALT;
} I021_146;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/146 (Selected Altitude) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_146 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_146(BitStream *bs, const I021_146 *item);

/**
 * @brief Decode the data item I021/146 (Selected Altitude) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_146 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_146(BitStream *bs, I021_146 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given data item I021/146.
 *
 * @param[in] item Pointer to a I021_146 structure.
 */
ASTERIX_LIB void print_I021_146(const I021_146 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_146_H */