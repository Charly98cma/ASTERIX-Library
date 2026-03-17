/**
 * @file I021_150.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_150_H
#define I021_150_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

#define I021_150_LSB_IAS    (0.00006103515625)  /// LSB = 1/2^14 NM/s
#define I021_150_LSB_MACH   (0.001)             /// LSB = 0.001

/* ================================= ENUMS ================================= */

typedef enum eI021_150_IM
{
    eI021_150_IM_IAS,   // Incoming Air Speed
    eI021_150_IM_MACH,  // MACH
} eI021_150_IM;

/* ================================= STRUCTS ================================= */

/**
 * @typedef I021_150
 * @brief Data Item I021/150 - Air Speed
 * 
 * Calculated Air Speed (Element of Air Vector).
 */
typedef struct I021_150
{
    /// @brief IM
    eI021_150_IM    IM;
    /// @brief Air Speed (IAS if IM = 0; MACH if IM = 1)
    float           AIRSPD;
} I021_150;
/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/150 (Air Speed) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_150 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_150(BitStream *bs, const I021_150 *item);

/**
 * @brief Decode the data item I021/150 (Air Speed) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_150 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_150(BitStream *bs, I021_150 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given data item I021/150.
 *
 * @param[in] item Pointer to a I021_150 structure.
 */
ASTERIX_LIB void print_I021_150(const I021_150 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_150_H */