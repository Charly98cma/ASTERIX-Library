/**
 * @file I021_010.h
 * @brief Definition of item 020 of CAT 021, and related functions and values
 */

#ifndef I021_010_H
#define I021_010_H

#include <stdint.h>

#include "Common/visibility.h"

#include "Categories/SAC_SIC.h"

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
 * @typedef I021_010
 * @brief Category 021 / Item 010 - Data Source Identification
 * 
 * Identification of the ADS-B station providing information.
 * 
 * Item present in every ASTERIX record
 */
typedef SAC_SIC I021_010;
 
/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the System Area Code (SAC) from CAT 021 / Item 010.
 * 
 * Portable access to the SAC bits, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_010 structure.
 * @return uint8_t Value of SAC
 */
ASTERIX_API uint8_t get_I021_010_SAC(const I021_010 * item);

/**
 * @brief Get the System Identification Code (SIC) from CAT 021 / Item 010.
 * 
 * Portable access to the SIC bits, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_010 structure.
 * @return uint8_t Value of SIC
 */
ASTERIX_API uint8_t get_I021_010_SIC(const I021_010 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the System Area Code (SAC) into the raw field.
 * 
 * @param item Pointer to I021_010 structure.
 * @param sac_value Value of the SAC
 */
ASTERIX_API void set_I021_010_SAC(I021_010 * item, const uint8_t sac_value);

/**
 * @brief Set the System Identification Code (SIC) into the raw field.
 * 
 * @param item Pointer to I021_010 structure.
 * @param sic_value Value of the SIC
 */
ASTERIX_API void set_I021_010_SIC(I021_010 * item, const uint8_t sic_value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 010.
 *
 * This function prints the values of the main two bytes.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a I021_010 structure.
 */
ASTERIX_API void print_I021_010(const I021_010 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_010_H */