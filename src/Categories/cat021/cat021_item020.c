/**
 * @file cat021_item020.c
 * @brief Implementation of the Category 21 Item 020 functions
 */

#include "cat021_item020.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Emitter Category (ECAT) from I021/020.
 * 
 * Portable access to the ECAT bits, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item020 structure.
 * @return uint8_t Value of ECAT (0: not active, 1: active)
 */
uint8_t get_cat021_item020_ECAT(const cat021_item020 * item)
{
    return GET_BITS((item)->raw, 1, MASK_08_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/



/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 020.
 *
 * This function prints the values of the main byte.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a cat021_item020 structure.
 */
void print_cat021_item020(const cat021_item020 *item)
{
    printf("Category 021 / Item 020 - Emitter Category\n");
    printf("  ECAT: %d\n\n", get_cat021_item020_ECAT(item));  
}
