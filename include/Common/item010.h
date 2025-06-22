/**
 * @file sac_sic.h
 * @brief Definition of Item 010 and SAC/SIC values
 */

#ifndef COMMON_ITEM010_H
#define COMMON_ITEM010_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

// https://www.eurocontrol.int/asterix

/*******************************************************************************
 * Structures and types
 ******************************************************************************/

/**
 * @typedef item010
 * @brief Data Source Identification
 * 
 * Identification of the ADS-B station providing information.
 * 
 * Item present in every ASTERIX record
 */
typedef struct item010 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint16_t raw;
        
        struct {
            /// @brief System Area Code (8 bits)
            uint8_t sac;
            /// @brief System Identification Code (8 bits)
            uint8_t sic;
        };
    };
} item010; // Item 010 for all CATs

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the System Area Code (SAC) from item 010.
 * 
 * Portable access to the SAC bits, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item010 structure.
 * @return uint8_t Value of SAC
 */
ASTERIX_API uint8_t get_item010_SAC(const item010 * item);

/**
 * @brief Get the System Identification Code (SIC) from item 010.
 * 
 * Portable access to the SIC bits, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item010 structure.
 * @return uint8_t Value of SIC
 */
ASTERIX_API uint8_t get_item010_SIC(const item010 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the System Area Code (SAC) into the raw field.
 * 
 * @param item Pointer to item010 structure.
 * @param sac_value Value of the SAC
 */
void set_item010_SAC(item010 * item, uint8_t sac_value);

/**
 * @brief Set the System Identification Code (SIC) into the raw field.
 * 
 * @param item Pointer to item010 structure.
 * @param sic_value Value of the SIC
 */
void set_item010_SIC(item010 * item, uint8_t sic_value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 010.
 *
 * This function prints the values of the main byte.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a cat021_item010 structure.
 */
ASTERIX_API void print_cat021_item010(const item010 *item);

#ifdef __cplusplus
}
#endif

#endif /* COMMON_ITEM010_H */