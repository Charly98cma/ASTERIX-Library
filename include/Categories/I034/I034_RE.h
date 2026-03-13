/**
 * @file I034_RE.h
 * @brief 
 * @version 0.1
 * @date 2026-02-13
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef I034_RE_H
#define I034_RE_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= ENUMS ================================= */

/* ================================= MACROS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I034_RE
 * @brief Data item I034/SP - Reserved Expansion Field
 */
typedef struct
{
    /* Spare bits set to 0 */
    uint8_t spare;
} I034_RE;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode item I034/RE (Reserved Expansion Field) into a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_RE structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_RE(BitStream *bs, const I034_RE *item);

/** @brief Decode item I034/RE (Reserved Expansion Field) from a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_RE structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_RE(BitStream *bs, I034_RE *item);

/* ============================== EXTRA FUNCS ============================== */

/** @brief Print the contents of the given I034/RE data item.
 *
 * @param item Pointer to the I034_RE structure.
 */
ASTERIX_LIB void print_I034_RE(const I034_RE *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_RE_H */