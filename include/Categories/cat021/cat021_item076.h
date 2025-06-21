/**
 * @file cat021_item076.h
 * @brief Definition of CAT 021 Item 076, and related functions and values
 */

#ifndef CAT021_ITEM076_H
#define CAT021_ITEM076_H

#include <stdint.h>
#include "visibility.h"

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * MACROS
 ******************************************************************************/

/** 
 * @brief LSB (1/2^30 s) Time of Message Reception of Position–High Precision
 */
#define LSB_CAT021_ITEM076          (double) (1/P2_30)

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item076
 * @brief Category 021 / Item 076 - Time of Message Reception of Position–High Precision
 * 
 * Time at which the latest ADS-B velocity information was received
 * by the ground station, expressed as fraction of the second of the  UTC Time.
 */
typedef struct cat021_item076 {
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
             * = 2 - TOMRv whole seconds = (Cat 021 Item 075) Whole seconds - 1 |
             * = 1 - TOMRv whole seconds = (Cat 021 Item 075) Whole seconds + 1 |
             * = 0 - TOMRv whole seconds = (Cat 021 Item 075) Whole seconds
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
} cat021_item076;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get Full Second Indication (FSI) value from Cat 021 Item 076.
 *
 * @param item Pointer to cat021_item076 structure.
 * @return uint32_t FSI value (0: I021/075, 1: I021/075+1 sec, 2: I021/075-1 sec, 3: Reserved).
 */
ASTERIX_API uint8_t get_cat021_item076_FSI(const cat021_item076 * item);

/**
 * @brief Get Time of Message Reception of Position–High Precision (TMRV_HP)
 *        raw value from Cat 021 Item 076.
 *
 * @param item Pointer to cat021_item076 structure.
 * @return uint32_t TMRV_HP value (number of 1/2^30 seconds jumps)
 */
ASTERIX_API uint32_t get_cat021_item076_TMRV_HP_raw(const cat021_item076 * item);

/**
 * @brief Get Time of Message Reception of Position–High Precision (TMRV_HP)
 *        value in seconds from Cat 021 Item 076.
 *
 * @param item Pointer to cat021_item076 structure.
 * @return uint32_t TMRV_HP value (in seconds).
 */
ASTERIX_API double get_cat021_item076_TMRV_HP_seconds(const cat021_item076 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Full Second Indication (FSI) value into Cat 021 Item 076.
 *
 * @param item Pointer to cat021_item076 structure.
 * @param raw_value Raw 2-bit to store.
 */
ASTERIX_API void set_cat021_item076_FSI(cat021_item076 * item, uint8_t raw_value);

/**
 * @brief Set the Time of Message Reception of Position–High Precision (TMRV_HP)
 *        raw value into Cat 021 Item 076.
 *
 * Stores the 30-bit value into the raw array.
 *
 * @param item Pointer to cat021_item076 structure.
 * @param raw_value Raw 30-bit time value to store (units of 1/2^30 seconds).
 */
ASTERIX_API void set_cat021_item076_TMRV_HP_raw(cat021_item076 * item, uint32_t raw_value);

/**
 * @brief Set the Time of Message Reception of Position–High Precision (TMRV_HP)
 *        value in seconds into Cat 021 Item 076.
 *
 * @param item Pointer to cat021_item076 structure.
 * @param seconds Time in seconds (will be converted to 1/2^30 second units)
 */
ASTERIX_API void set_cat021_item076_TMRV_HP_seconds(cat021_item076 * item, double seconds);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT021 Item 076.
 * 
 * Prints both the Full Second Indication (FSI) value, and the raw value and 
 * converted time in seconds of Time of Message Reception of Position–High
 * Precision (TMRV_HP).
 * 
 * @param item Pointer to cat021_item076 structure.
 */
ASTERIX_API void print_cat021_item076(const cat021_item076 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM076_H */