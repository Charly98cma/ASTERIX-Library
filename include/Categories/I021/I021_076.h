/**
 * @file I021_076.h
 * @brief Definition of I021/076, and related functions and values
 */

#ifndef I021_076_H
#define I021_076_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_076_LSB_TMRV_HP   (1.0/P2_30) /// @brief LSB = 1/2^30 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_076
 * @brief Category 021 / Item 076 - Time of Message Reception of Position–High Precision
 * 
 * Time at which the latest ADS-B velocity information was received
 * by the ground station, expressed as fraction of the second of the  UTC Time.
 */
typedef struct I021_076 {
    /** 
     * @brief Time of Message Reception of Position–High Precision (TMRV_HP)
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
             * = 2 - TOMRv whole seconds = (I021/075) Whole seconds - 1 |
             * = 1 - TOMRv whole seconds = (I021/075) Whole seconds + 1 |
             * = 0 - TOMRv whole seconds = (I021/075) Whole seconds
             */
            uint32_t FSI        :2;
            /** 
             * @brief Time of Message Reception of Position–High Precision
             * 
             * Fractional part of the time of message reception
             * for velocity in the ground station (LSB = 1/2^30)
             */
            uint32_t TMRV_HP    :30;
        };
    };
} I021_076;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get Full Second Indication (FSI) value from I021/076.
 *
 * @param item Pointer to I021_076 structure.
 * @return uint32_t FSI value (0: I021/075, 1: I021/075+1 sec, 2: I021/075-1 sec, 3: Reserved).
 */
ASTERIX_API uint8_t get_I021_076_FSI(const I021_076 * item);

/**
 * @brief Get Time of Message Reception of Position–High Precision (TMRV_HP)
 *        raw value from I021/076.
 *
 * @param item Pointer to I021_076 structure.
 * @return uint32_t TMRV_HP value (number of 1/2^30 seconds jumps)
 */
ASTERIX_API uint32_t get_I021_076_TMRV_HP_raw(const I021_076 * item);

/**
 * @brief Get Time of Message Reception of Position–High Precision (TMRV_HP)
 *        value in seconds from I021/076.
 *
 * @param item Pointer to I021_076 structure.
 * @return uint32_t TMRV_HP value (in seconds).
 */
ASTERIX_API double get_I021_076_TMRV_HP_seconds(const I021_076 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Full Second Indication (FSI) value into I021/076.
 *
 * @param item Pointer to I021_076 structure.
 * @param raw_value Raw 2-bit to store.
 */
ASTERIX_API void set_I021_076_FSI(I021_076 * item, const uint8_t raw_value);

/**
 * @brief Set the Time of Message Reception of Position–High Precision (TMRV_HP)
 *        raw value into I021/076.
 *
 * Stores the 30-bit value into the raw array.
 *
 * @param item Pointer to I021_076 structure.
 * @param raw_value Raw 30-bit time value to store (units of 1/2^30 seconds).
 */
ASTERIX_API void set_I021_076_TMRV_HP_raw(I021_076 * item, const uint32_t raw_value);

/**
 * @brief Set the Time of Message Reception of Position–High Precision (TMRV_HP)
 *        value in seconds into I021/076.
 *
 * @param item Pointer to I021_076 structure.
 * @param seconds Time in seconds (will be converted to 1/2^30 second units)
 */
ASTERIX_API void set_I021_076_TMRV_HP_seconds(I021_076 * item, const double seconds);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of I021/076.
 * 
 * Prints both the Full Second Indication (FSI) value, and the raw value and 
 * converted time in seconds of Time of Message Reception of Position–High
 * Precision (TMRV_HP).
 * 
 * @param item Pointer to I021_076 structure.
 */
ASTERIX_API void print_I021_076(const I021_076 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_076_H */