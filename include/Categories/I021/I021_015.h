/**
 * @file I021_015.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_015_H
#define I021_015_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

/* ================================= ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I021_015
 * @brief Data Item I021/015 - Service Identification
 * 
 * Identification of the service provided to one or more users.
 * 
 * @note The service identification is allocated by the system.
 * @note The service identification is also available in item I023/015
 */
typedef struct I021_015
{
    /// @brief Service Identification
    u8 SI;
} I021_015;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/015 (System Identification) into a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_010 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_015(BitStream *bs, const I021_015 *item);

/**
 * @brief Decode the data item I021/015 (System Identification) from a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_010 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_015(BitStream *bs, I021_015 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given I021/015 data item.
 *
 * @param[in] item Pointer to a I021_015 structure.
 */
ASTERIX_LIB void print_I021_015(const I021_015 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_015_H */