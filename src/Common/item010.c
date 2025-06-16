/**
 * @file item010.c
 * @brief Implementation of the Item 010 functions
 */

#include "item010.h"
#include "constants.h"

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
uint8_t get_item010_SAC(const item010 * item)
{
    return (((item)->raw >> 8) & MASK_08_BITS);
}

/**
 * @brief Get the System Identification Code (SIC) from item 010.
 * 
 * Portable access to the SIC bits, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item010 structure.
 * @return uint8_t Value of SIC
 */
uint8_t get_item010_SIC(const item010 * item)
{
    return (((item)->raw) & MASK_08_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the System Area Code (SAC) into the raw field.
 * 
 * @param item Pointer to item010 structure.
 * @param sac_value Value of the SAC
 */
void set_item010_SAC(item010 * item, uint8_t sac_value)
{
    SET_BITS(&(item->raw), sac_value, MASK_08_BITS, 9);
}

/**
 * @brief Set the System Identification Code (SIC) into the raw field.
 * 
 * @param item Pointer to item010 structure.
 * @param sic_value Value of the SIC
 */
void set_item010_SIC(item010 * item, uint8_t sic_value)
{
    SET_BITS(&(item->raw), sic_value, MASK_08_BITS, 1);
}

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
void print_cat021_item010(const item010 *item)
{
    printf("Item 010 - Data Source Identification\n");
    printf("  SAC = 0x%02X\n", get_item010_SAC(item));
    printf("  SIC = 0x%02X\n", get_item010_SIC(item));
}