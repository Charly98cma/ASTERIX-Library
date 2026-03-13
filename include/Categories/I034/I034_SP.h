/**
 * @file I034_SP.h
 * @brief 
 * @version 0.1
 * @date 2026-02-13
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef I034_SP_H
#define I034_SP_H

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
 * @typedef I034_SP
 * @brief Data item I034/SP - Special Purpose Field
 */
typedef struct
{
    /* Spare bits set to 0 */
    uint8_t spare;
} I034_SP;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode item I034/SP (Special Purpose Field) into a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_SP structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_SP(BitStream *bs, const I034_SP *item);

/** @brief Decode item I034/SP (Special Purpose Field) from a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_SP structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_SP(BitStream *bs, I034_SP *item);

/* ============================== EXTRA FUNCS ============================== */

/** @brief Print the contents of the given I034/SP data item.
 *
 * @param item Pointer to the I034_SP structure.
 */
ASTERIX_LIB void print_I034_SP(const I034_SP *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_SP_H */