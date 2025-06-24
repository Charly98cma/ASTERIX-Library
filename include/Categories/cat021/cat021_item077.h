/**
 * @file cat021_item077.h
 * @brief Definition of CAT 021 Item 077, and related functions and values
 */

#ifndef CAT021_ITEM077_H
#define CAT021_ITEM077_H

#include <stdio.h>
#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * MACROS
 ******************************************************************************/

/** 
 * @brief LSB (1/128 s) Time of ASTERIX Report Transmission
 */
#define LSB_CAT021_ITEM077                (double) (1/P2_7)

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item077
 * @brief Category 021 / Item 077 -  Time of ASTERIX Report Transmission
 * 
 * Time of the transmission of the ASTERIX category 021 report in 
 * the form of elapsed time since last midnight, expressed as UTC.
 */
typedef struct cat021_item077 {
    /** 
     * @brief  Time of ASTERIX Report Transmission (TART)
     * 
     * Raw 3-bytes as received (LSB = 1/128 sec)
     */
    uint8_t raw[3];
} cat021_item077;


/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get Time of ASTERIX Report Transmission raw value from Cat 021 Item 077.
 *
 * Combines the 3 raw bytes into a 24-bit unsigned integer.
 *
 * @param item Pointer to cat021_item077 structure.
 * @return uint32_t Time in units of 1/128 s (0 = midnight).
 */
ASTERIX_API uint32_t get_cat021_item077_raw(const cat021_item077 * item);

/**
 * @brief Get the Time of ASTERIX Report Transmission in seconds (floating-point)
 *        from Cat 021 Item 077.
 *
 * Divides the raw 1/128-s units by 128.0 to return seconds since midnight.
 *
 * @param item Pointer to cat021_item077 structure.
 * @return double Time in seconds (>= 0).
 */
ASTERIX_API double get_cat021_item077_TART_seconds(const cat021_item077 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Time of ASTERIX Report Transmission raw value into Cat 021 Item 077.
 *
 * Stores the 24-bit value into the raw array.
 *
 * @param item Pointer to cat021_item077 structure.
 * @param raw_value Raw 24-bit time value to store (units of 1/128 s).
 */
ASTERIX_API void set_cat021_item077_TART_raw(cat021_item077 * item, uint32_t raw_value);

/**
 * @brief Set the Time of ASTERIX Report Transmission in seconds into Cat 021 Item 077.
 *
 * Converts the seconds value into 1/128-s units and stores as raw data.
 *
 * @param item Pointer to cat021_item077 structure.
 * @param seconds Time in seconds (will be converted to 1/128-s units).
 */
ASTERIX_API void set_cat021_item077_TART_seconds(cat021_item077 * item, double seconds);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT021 Item 077 (Time of ASTERIX Report Transmission).
 * 
 * Prints both the raw value and the converted time in seconds.
 * 
 * @param item Pointer to cat021_item077_t structure.
 */
ASTERIX_API void print_cat021_item077(const cat021_item077 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM077_H */