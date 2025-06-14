/**
 * @file cat021_item016.c
 * @brief Implementation of the Category 21 Item 016 functions
 */

#include "cat021_item016.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Report Period value (RP) from I021/016.
 * 
 * Portable access to the RP bits, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item016 structure.
 * @return uint8_t Value of RP
 */
uint8_t get_cat021_item016_RP(const cat021_item016 * item)
{
    return ((item)->raw & MASK_08_BITS);
}

/**
 * @brief Get the Report Period value (RP) from I021/016 in seconds.
 * 
 * Converts the raw RP value to seconds.
 * 
 * @param item Pointer to cat021_item016 structure.
 * @return double Report Period in seconds
 */
double get_cat021_item016_RP_seconds(const cat021_item016 * item)
{
    return get_cat021_item016_RP(item) * LSB_CAT021_ITEM016_RP;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 016.
 *
 * This function prints the values of the main byte.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a cat021_item016 structure.
 */
void print_cat021_item016(const cat021_item016 *item)
{
    printf("Category 021 / Item 016 - Service Management\n");
    printf("  RP: 0x%02X\n", get_cat021_item016_RP(item));
    printf("  RP(seconds): %d\n", get_cat021_item016_RP_seconds(item));
}