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
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 008.
 *
 * This function prints the values of the main byte.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a cat021_item008 structure.
 */
void print_cat021_item008(const item010 *item)
{
    printf("Item 010 - Data Source Identification\n");
    printf("  SAC = %d\n"  , get_item010_SAC(item));
    printf("  SIC = %d\n", get_item010_SIC(item));
}