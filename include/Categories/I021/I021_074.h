/**
 * @file I021_074.h
 * @brief Definition of I021/074, and related functions and values
 */

#ifndef I021_074_H
#define I021_074_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_074_LSB_TMRP_HP   (1.0/P2_30) /// @brief LSB = 1/2^30 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_074
 * @brief Category 021 / Item 074 - Time of Message Reception of Position–High Precision
 * 
 * Time at which the latest ADS-B position information was received
 * by the ground station, expressed as fraction of the second of the UTC Time.
 */
typedef struct I021_074 {
    /** 
     * @brief Time of Message Reception of Position–High Precision (TMRP_HP)
     * 
     * Raw 4-bytes as received
     */
    uint8_t raw[4];
    
    union {
        struct {
            /** 
             * @brief Full Second Indication
             * 
             * = 3 - RESERVED |
             * = 2 - TOMRp whole seconds = (I021/073) Whole seconds - 1 |
             * = 1 - TOMRp whole seconds = (I021/073) Whole seconds + 1 |
             * = 0 - TOMRp whole seconds = (I021/073) Whole seconds
             */
            uint32_t FSI        :2;
            /** 
             * @brief Time of Message Reception of Position–High Precision
             * 
             * Fractional part of the time of message reception
             * for position in the ground station (LSB = 1/2^30)
             */
            uint32_t TMRP_HP    :30;
        };
    };
} I021_074;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get Full Second Indication (FSI) value from I021/074.
 *
 * @param item Pointer to I021_074 structure.
 * @return uint32_t FSI value (0: I021/073, 1: I021/073+1 sec, 2: I021/073-1 sec, 3: Reserved).
 */
ASTERIX_API uint8_t get_I021_074_FSI(const I021_074 * item);

/**
 * @brief Get Time of Message Reception of Position–High Precision (TMRP_HP)
 *        raw value from I021/074.
 *
 * @param item Pointer to I021_074 structure.
 * @return uint32_t TMRP_HP value (number of 1/2^30 seconds jumps)
 */
ASTERIX_API uint32_t get_I021_074_TMRP_HP_raw(const I021_074 * item);

/**
 * @brief Get Time of Message Reception of Position–High Precision (TMRP_HP)
 *        value in seconds from I021/074.
 *
 * @param item Pointer to I021_074 structure.
 * @return uint32_t TMRP_HP value (in seconds).
 */
ASTERIX_API double get_I021_074_TMRP_HP_seconds(const I021_074 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Full Second Indication (FSI) value into I021/074.
 *
 * @param item Pointer to I021_074 structure.
 * @param raw_value Raw 2-bit to store.
 */
ASTERIX_API void set_I021_074_FSI(I021_074 * item, const uint8_t raw_value);

/**
 * @brief Set the Time of Message Reception of Position–High Precision (TMRP_HP)
 *        raw value into I021/074.
 *
 * Stores the 30-bit value into the raw array.
 *
 * @param item Pointer to I021_074 structure.
 * @param raw_value Raw 30-bit time value to store (units of 1/2^30 seconds).
 */
ASTERIX_API void set_I021_074_TMRP_HP_raw(I021_074 * item, const uint32_t raw_value);

/**
 * @brief Set the Time of Message Reception of Position–High Precision (TMRP_HP)
 *        value in seconds into I021/074.
 *
 * @param item Pointer to I021_074 structure.
 * @param seconds Time in seconds (will be converted to 1/2^30 second units)
 */
ASTERIX_API void set_I021_074_TMRP_HP_seconds(I021_074 * item, const double seconds);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of I021/074.
 * 
 * Prints both the Full Second Indication (FSI) value, and the raw value and 
 * converted time in seconds of Time of Message Reception of Position–High
 * Precision (TMRP_HP).
 * 
 * @param item Pointer to I021_074 structure.
 */
ASTERIX_API void print_I021_074(const I021_074 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_074_H */