/**
 * @file cat021_item015.c
 * @brief Implementation of the Category 21 Item 015 functions
 */

#include "cat021_item015.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Service Identification value (SI) from I021/015.
 * 
 * Portable access to the SI bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item015 structure.
 * @return uint8_t Value of SI
 */
uint8_t get_cat021_item015_SI(const cat021_item015 * item)
{
    return ((item)->raw & MASK_08_BITS);
}


/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 015.
 *
 * This function prints the values of the main byte.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a cat021_item015 structure.
 */
void print_cat021_item015(const cat021_item015 *item)
{
    printf("CAT021 / Item 015 - Service Identification\n");
    printf("  SI: 0x%02X\n", get_cat021_item015_SI(item));
}
