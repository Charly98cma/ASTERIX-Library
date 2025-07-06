/**
 * @file cat021_item010.h
 * @brief Definition of item 020 of CAT 021, and related functions and values
 */

#ifndef CAT021_ITEM010_H
#define CAT021_ITEM010_H

#include <stdint.h>

#include "Common/visibility.h"

#include "Categories/item010.h"

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
 * Getters
 ******************************************************************************/

/**
 * @brief Get the System Area Code (SAC) from CAT 021 / Item 010.
 * 
 * Portable access to the SAC bits, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item010 structure.
 * @return uint8_t Value of SAC
 */
ASTERIX_API uint8_t get_cat021_item010_SAC(const cat021_item010 * item);

/**
 * @brief Get the System Identification Code (SIC) from CAT 021 / Item 010.
 * 
 * Portable access to the SIC bits, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item010 structure.
 * @return uint8_t Value of SIC
 */
ASTERIX_API uint8_t get_cat021_item010_SIC(const cat021_item010 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the System Area Code (SAC) into the raw field.
 * 
 * @param item Pointer to cat021_item010 structure.
 * @param sac_value Value of the SAC
 */
ASTERIX_API void set_cat021_item010_SAC(cat021_item010 * item,
                                        const uint8_t sac_value);

/**
 * @brief Set the System Identification Code (SIC) into the raw field.
 * 
 * @param item Pointer to cat021_item010 structure.
 * @param sic_value Value of the SIC
 */
ASTERIX_API void set_cat021_item010_SIC(cat021_item010 * item,
                                        const uint8_t sic_value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 010.
 *
 * This function prints the values of the main two bytes.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a cat021_item010 structure.
 */
ASTERIX_API void print_cat021_item010(const cat021_item010 *item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM010_H */