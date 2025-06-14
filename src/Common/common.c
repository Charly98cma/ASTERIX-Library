/**
 * @file common.c
 * @brief Implementation of the function to read CAT and LEN
 */

#include "common.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Message Category (CAT) from the ASTERIX header.
 * 
 * Portable access to the CAT bits, independent of compiler and endianness.
 * 
 * @param item Pointer to header_t structure.
 * @return uint8_t Value of CAT
 */
uint8_t get_header_CAT(const header * item)
{
    return ((item)->CAT);
}

/**
 * @brief Get the Message Length (LEN) from the ASTERIX header.
 * 
 * Portable access to the LEN field, independent of compiler and endianness.
 * 
 * @param item Pointer to header_t structure.
 * @return uint8_t Value of LEN (total length of the ASTERIX message)
 */
uint16_t get_header_LEN(const header * item)
{
    return ((item)->LEN);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of ASTERIX message header.
 *
 * This function prints the category (CAT) and total length (LEN)
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a header structure.
 */
void print_header(const header * item)
{
    printf("ASTERIX header\n");
    printf("  CAT = %d\n", get_header_CAT(item));
    printf("  LEN = %d\n", get_header_LEN(item));
}