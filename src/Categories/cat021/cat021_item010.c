/**
 * @file cat021_item010.c
 * @brief Implementation of the Category 21 Item 010 functions
 */

#include "cat021_item010.h"
#include "constants.h"

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
uint8_t get_cat021_item010_SAC(const cat021_item010 * item)
{
    return get_item010_SIC((item010 *) item);
}

/**
 * @brief Get the System Identification Code (SIC) from CAT 021 / Item 010.
 * 
 * Portable access to the SIC bits, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item010 structure.
 * @return uint8_t Value of SIC
 */
uint8_t get_cat021_item010_SIC(const cat021_item010 * item)
{
    return get_item010_SIC((item010 *) item);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the System Area Code (SAC) into the raw field.
 * 
 * @param item Pointer to cat021_item010 structure.
 * @param sac_value Value of the SAC
 */
void set_cat021_item010_SAC(cat021_item010 * item, uint8_t sac_value)
{
    set_item010_SAC((item010 *) item, sac_value);
}

/**
 * @brief Set the System Identification Code (SIC) into the raw field.
 * 
 * @param item Pointer to cat021_item010 structure.
 * @param sic_value Value of the SIC
 */
void set_cat021_item010_SIC(cat021_item010 * item, uint8_t sic_value)
{
    set_item010_SIC((item010 *) item, sic_value);
}

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
void print_cat021_item010(const cat021_item010 *item)
{
    printf("CAT021 / Item 010 - Data Source Identification\n");
    printf("  SAC: 0x%02X\n", get_item010_SAC(item));
    printf("  SIC: 0x%02X\n\n", get_item010_SIC(item));
}
