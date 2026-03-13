/**
 * @file I034_000.h
 * @brief
 * @version 0.1
 * @date 2026-02-09
 *
 * @copyright Copyright (c) 2026
 */
#ifndef I034_000_H
#define I034_000_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>
#include <Common/versions.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* ================================= MACROS ================================= */

/* ================================= ENUMS ================================= */

typedef enum eI034_000_MSG_TYPE
{
    eI034_000_MSG_TYPE_NORTH_MARKER = 1,
    eI034_000_MSG_TYPE_SECTOR_CROSSING,
    eI034_000_MSG_TYPE_GEO_FILTERING,
    eI034_000_MSG_TYPE_JAMMING_STROBE,
#if ((EDITION_NUMBER_I034 >= 1) && (VERSION_NUMBER_I034 >= 28))
    eI034_000_MSG_TYPE_SOLAR_STORM,
#endif
#if ((EDITION_NUMBER_I034 >= 1) && (VERSION_NUMBER_I034 >= 29))
    eI034_000_MSG_TYPE_SSR_JAMMING_STROBE,
    eI034_000_MSG_TYPE_MS_JAMMING_STROBE,
#endif
} eI034_000_MSG_TYPE;

/* ================================= STRUCTS ================================= */

/**
 * @typedef I034_000
 * @brief Data Item I034/000 - Message Type
 *
 * This Data Item allows for a more convenient handling of the messages
 * at the receiver side by further defining the type of transaction.
 * 
 * @note Format: One-octet fixed length Data Item.
 */
typedef struct I034_000
{
    /// @brief Message type
    eI034_000_MSG_TYPE MSGTYPE;
} I034_000;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I034/000 (Message Type) into a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_010 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_000(BitStream *bs, const I034_000 *item);

/**
 * @brief Decode the data item I034/000 (Message Type) from a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_010 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_000(BitStream *bs, I034_000 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given I034/000 data item.
 *
 * @param[in] item Pointer to a I034_000 structure.
 */
ASTERIX_LIB void print_I034_000(const I034_000 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_000_H */