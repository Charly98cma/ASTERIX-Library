/**
 * @file I021_151.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_151_H
#define I021_151_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

#define I021_151_LSB_TAS    (1.0)   /// LSB = 1 knot

/* ================================= ENUMS ================================= */

typedef enum eI021_151_RE
{
    eI021_151_RE_IN_RANGE,  // True Air Speed within defined range
    eI021_151_RE_OUT_RANGE, // True Air Speed exceeds defined range
} eI021_151_RE;

/* ================================= STRUCTS ================================= */

/**
 * @typedef I021_151
 * @brief Data Item I021/151 - True Air Speed
 *
 * @note The RE-Bit, if set, indicates that the value to be transmitted
 *       is beyond the range defined for this specific data item and the
 *       applied technology. In this case the True Air Speed contains the
 *       maximum value that can be downloaded from the aircraft avionics and
 *       the RE-bit indicates that the actual value is greater than the value
 *       contained in the field.
 */
typedef struct I021_151
{
    /// @brief Range Exceeded Indicator
    eI021_151_RE    RE;
    /// @brief True Air Speed (LSB = 1 knot)
    u16             TAS;
} I021_151;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/151 (True Air Speed) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_151 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_151(BitStream *bs, const I021_151 *item);

/**
 * @brief Decode the data item I021/151 (True Air Speed) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_151 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_151(BitStream *bs, I021_151 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given data item I021/151.
 *
 * @param[in] item Pointer to a I021_151 structure.
 */
ASTERIX_LIB void print_I021_151(const I021_151 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_151_H */