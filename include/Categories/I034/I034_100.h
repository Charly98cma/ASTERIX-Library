/**
 * @file I034_100.h
 * @brief 
 * @version 0.1
 * @date 2026-02-10
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef I034_100_H
#define I034_100_H

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

/**
 * @brief Rho Start/End LDB = 1/256 NM
 */
#define I034_100_LSB_RHO    (0.00390625F)
/**
 * @brief Theta Start/End LSB = 360/2^16 degrees
 */
#define I034_100_LSB_THETA  (0.0054931640625F)

/* ================================= ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef I034_100
 * @brief Data Item 034/100 - Generic Polar Window
 *
 * Geographical window defined in polar co-ordinates.
 */
typedef struct I034_100
{
    /**
     * @brief Rho Start in Nautical Miles
     * 
     * Range = [0 to 256] NM
     * 
     * LSB = 1/256 NM
     */
    float RHO_START;
    /**
     * @brief Rho End in Nautical Miles
     * 
     * Range = [0 to 256] NM
     * 
     * LSB = 1/256 NM
     */
    float RHO_END;
    /**
     * @brief Theta Start in degrees
     * 
     * Range = [0 to 359.9945] degrees
     * 
     * LSB = 360/2^16 degrees
     */
    float THETA_START;
    /**
     * @brief Theta End in degrees
     * 
     * Range = [0 to 359.9945] degrees
     * 
     * LSB = 360/2^16 degrees
     */
    float THETA_END;
} I034_100;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode item I034/100 (Generic Polar Window) into a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_100 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_100(BitStream *bs, const I034_100 *item);

/** @brief Decode item I034/100 (Generic Polar Window) from a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_100 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_100(BitStream *bs, I034_100 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given I034/100 data item.
 *
 * @param item Pointer to a I034_100 structure.
 */
ASTERIX_LIB void print_I034_100(const I034_100 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_100_H */