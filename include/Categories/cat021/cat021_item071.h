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
     * 
     */
    uint8_t raw[3];
} cat021_item071;

/*******************************************************************************
 * Function headers
 ******************************************************************************/

ASTERIX_API uint32_t get_cat021_item071_TAP_raw(const cat021_item071 * item);
ASTERIX_API double get_cat021_item071_TAP_seconds(const cat021_item071 * item);

ASTERIX_API void set_cat021_item071_TAP_raw(cat021_item071 * item, uint32_t raw_value);
ASTERIX_API void set_cat021_item071_TAP_seconds(cat021_item071 * item, double seconds);

ASTERIX_API void print_cat021_item071(const cat021_item071 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM071_H */