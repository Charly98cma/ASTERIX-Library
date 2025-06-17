/**
 * @file cat021_item072.h
 * @brief Definition of item 072 of CAT 021, and related functions and values
 */

#ifndef CAT021_ITEM072_H
#define CAT021_ITEM072_H

#include <stdint.h>
#include "visibility.h"

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * MACROS
 ******************************************************************************/

/** 
 * @brief LSB (1/128 s) Time of Applicability for Velocity of Cat 021 Item 072
 */
#define LSB_CAT021_ITEM072                (double) (1/P2_7)

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item072
 * @brief Category 021 / Item 072 - Time of Applicability for Velocity
 * 
 * Time of applicability (measurement) of the reported velocity, in  
 * the form of elapsed time since last midnight, expressed as UTC.
 */
typedef struct cat021_item072 {
    /** 
     * @brief Time of Applicability for Velocity
     * 
     * Raw 3-bytes as received (LSB = 1/128 sec)
     * 
     */
    uint8_t raw[3];
} cat021_item072;

/*******************************************************************************
 * Function headers
 ******************************************************************************/

ASTERIX_API uint32_t get_cat021_item072_TAV_raw(const cat021_item072 * item);
ASTERIX_API double get_cat021_item072_TAV_seconds(const cat021_item072 * item);

ASTERIX_API void set_cat021_item072_TAV_raw(cat021_item072 * item, uint32_t raw_value);
ASTERIX_API void set_cat021_item072_TAV_seconds(cat021_item072 * item, double seconds);

ASTERIX_API void print_cat021_item072(const cat021_item072 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM072_H */