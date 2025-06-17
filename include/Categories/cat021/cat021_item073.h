/**
 * @file cat021_item073.h
 * @brief Definition of CAT 021 Item 073, and related functions and values
 */

#ifndef CAT021_ITEM073_H
#define CAT021_ITEM073_H

#include <stdint.h>
#include "visibility.h"

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * MACROS
 ******************************************************************************/

/** 
 * @brief LSB (1/128 s) Time of Message Reception for Position
 */
#define LSB_CAT021_ITEM073                (double) (1/P2_7)

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item073
 * @brief Category 021 / Item 073 - Time of Message Reception for Position
 * 
 * Time of reception of the latest position squitter in the Ground
 * Station, in the form of elapsed time since last midnight, 
 * expressed as UTC.
 */
typedef struct cat021_item073 {
    /** 
     * @brief Time of Message Reception for Position (TMRP)
     * 
     * Raw 3-bytes as received (LSB = 1/128 sec)
     * 
     */
    uint8_t raw[3];
} cat021_item073;

/*******************************************************************************
 * Function headers
 ******************************************************************************/

ASTERIX_API uint32_t get_cat021_item073_TMRP_raw(const cat021_item073 * item);
ASTERIX_API double get_cat021_item073_TMRP_seconds(const cat021_item073 * item);

ASTERIX_API void set_cat021_item073_TMRP_raw(cat021_item073 * item, uint32_t raw_value);
ASTERIX_API void set_cat021_item073_TMRP_seconds(cat021_item073 * item, double seconds);

ASTERIX_API void print_cat021_item073(const cat021_item073 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM073_H */