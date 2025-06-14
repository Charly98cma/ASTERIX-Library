/**
 * @file cat021_item010.h
 * @brief Definition of item 020 of CAT 021, and related functions and values
 */

#ifndef CAT021_ITEM010_H
#define CAT021_ITEM010_H

#include <stdint.h>

#include "constants.h"
#include "item010.h"
#include "visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

 /**
 * @typedef cat021_item010
 * @brief Category 021 / Item 010 - Data Source Identification
 * 
 * Identification of the ADS-B station providing information.
 * 
 * Item present in every ASTERIX record
 */
typedef item010 cat021_item010;
 
/*******************************************************************************
 * Function headers
 ******************************************************************************/

ASTERIX_API uint8_t get_cat021_item010_SAC(const cat021_item010 * item);
ASTERIX_API uint8_t get_cat021_item010_SIC(const cat021_item010 * item);

ASTERIX_API void print_cat021_item010(const cat021_item010 *item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM010_H */