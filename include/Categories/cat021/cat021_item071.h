/**
 * @file cat021_item071.h
 * @brief Definition of item 071 of CAT 021, and related functions and values
 */

#ifndef CAT021_ITEM071_H
#define CAT021_ITEM071_H

#include <stdint.h>
#include "visibility.h"

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * Macros
 ******************************************************************************/

/** 
 * @brief LSB (1/128 s) Time of Applicability for Position of Cat 021 Item 071 
 */
#define LSB_CAT021_ITEM071                (double) (1/P2_7)

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item071
 * @brief Category 021 / Item 071 -  Time of Applicability for Position
 * 
 * Time of applicability of the reported position, in the form of
 * elapsed time since last midnight, expressed as UTC.
 */
typedef struct cat021_item071 {
    /** 
     * @brief Time of Applicability for Position
     * 
     * Raw 3-bytes as received (LSB = 1/128 sec)
     */
    uint8_t raw[3];
} cat021_item071;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get Time of Applicability for Position raw value from Cat 021 Item 071.
 *
 * Combines the 3 raw bytes into a 24-bit unsigned integer.
 *
 * @param item Pointer to cat021_item071 structure.
 * @return uint32_t Time in units of 1/128 s (0 = midnight).
 */
ASTERIX_API uint32_t get_cat021_item071_TAP_raw(const cat021_item071 * item);

/**
 * @brief Get the Time of Applicability for Position in seconds (floating-point)
 *        from Cat 021 Item 071.
 *
 * Divides the raw 1/128-s units by 128.0 to return seconds since midnight.
 *
 * @param item Pointer to cat021_item071 structure.
 * @return double Time in seconds (>= 0).
 */
ASTERIX_API double get_cat021_item071_TAP_seconds(const cat021_item071 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Time of Applicability for Position raw value into Cat 021 Item 071.
 *
 * Stores the 24-bit value into the raw array.
 *
 * @param item Pointer to cat021_item071 structure.
 * @param raw_value Raw 24-bit time value to store (units of 1/128 s).
 */
ASTERIX_API void set_cat021_item071_TAP_raw(cat021_item071 * item, uint32_t raw_value);

/**
 * @brief Set the Time of Applicability for Position in seconds into Cat 021 Item 071.
 *
 * Converts the seconds value into 1/128-s units and stores as raw data.
 *
 * @param item Pointer to cat021_item071 structure.
 * @param seconds Time in seconds (will be converted to 1/128-s units).
 */
ASTERIX_API void set_cat021_item071_TAP_seconds(cat021_item071 * item, double seconds);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT021 Item 071 (Time of Applicability Position).
 * 
 * Prints both the raw value and the converted time in seconds.
 * 
 * @param item Pointer to cat021_item071 structure.
 */
ASTERIX_API void print_cat021_item071(const cat021_item071 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM071_H */