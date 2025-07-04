/**
 * @file cat021_item074.h
 * @brief Definition of CAT 021 Item 074, and related functions and values
 */

#ifndef CAT021_ITEM074_H
#define CAT021_ITEM074_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define CAT021_ITEM074_LSB_TMRP_HP   (1.0/P2_30) /// @brief LSB = 1/2^30 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item074
 * @brief Category 021 / Item 074 - Time of Message Reception of Position–High Precision
 * 
 * Time at which the latest ADS-B position information was received
 * by the ground station, expressed as fraction of the second of the UTC Time.
 */
typedef struct cat021_item074 {
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
             * = 2 - TOMRp whole seconds = (Cat 021 Item 073) Whole seconds - 1 |
             * = 1 - TOMRp whole seconds = (Cat 021 Item 073) Whole seconds + 1 |
             * = 0 - TOMRp whole seconds = (Cat 021 Item 073) Whole seconds
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
} cat021_item074;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get Full Second Indication (FSI) value from Cat 021 Item 074.
 *
 * @param item Pointer to cat021_item074 structure.
 * @return uint32_t FSI value (0: I021/073, 1: I021/073+1 sec, 2: I021/073-1 sec, 3: Reserved).
 */
ASTERIX_API uint8_t get_cat021_item074_FSI(const cat021_item074 * item);

/**
 * @brief Get Time of Message Reception of Position–High Precision (TMRP_HP)
 *        raw value from Cat 021 Item 074.
 *
 * @param item Pointer to cat021_item074 structure.
 * @return uint32_t TMRP_HP value (number of 1/2^30 seconds jumps)
 */
ASTERIX_API uint32_t get_cat021_item074_TMRP_HP_raw(const cat021_item074 * item);

/**
 * @brief Get Time of Message Reception of Position–High Precision (TMRP_HP)
 *        value in seconds from Cat 021 Item 074.
 *
 * @param item Pointer to cat021_item074 structure.
 * @return uint32_t TMRP_HP value (in seconds).
 */
ASTERIX_API double get_cat021_item074_TMRP_HP_seconds(const cat021_item074 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Full Second Indication (FSI) value into Cat 021 Item 074.
 *
 * @param item Pointer to cat021_item074 structure.
 * @param raw_value Raw 2-bit to store.
 */
ASTERIX_API void set_cat021_item074_FSI(cat021_item074 * item,
                                        const uint8_t raw_value);

/**
 * @brief Set the Time of Message Reception of Position–High Precision (TMRP_HP)
 *        raw value into Cat 021 Item 074.
 *
 * Stores the 30-bit value into the raw array.
 *
 * @param item Pointer to cat021_item074 structure.
 * @param raw_value Raw 30-bit time value to store (units of 1/2^30 seconds).
 */
ASTERIX_API void set_cat021_item074_TMRP_HP_raw(cat021_item074 * item,
                                                const uint32_t raw_value);

/**
 * @brief Set the Time of Message Reception of Position–High Precision (TMRP_HP)
 *        value in seconds into Cat 021 Item 074.
 *
 * @param item Pointer to cat021_item074 structure.
 * @param seconds Time in seconds (will be converted to 1/2^30 second units)
 */
ASTERIX_API void set_cat021_item074_TMRP_HP_seconds(cat021_item074 * item,
                                                    const double seconds);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT021 Item 074.
 * 
 * Prints both the Full Second Indication (FSI) value, and the raw value and 
 * converted time in seconds of Time of Message Reception of Position–High
 * Precision (TMRP_HP).
 * 
 * @param item Pointer to cat021_item074 structure.
 */
ASTERIX_API void print_cat021_item074(const cat021_item074 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM074_H */