/**
 * @file common.c
 * @brief Implementation of the functions to read CAT and LEN from ASTERIX
 *        headers
 */

#include <stdio.h>
#include "Common/common.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_header_CAT(const header * item)
{
    return ((item)->CAT);
}

uint16_t get_header_LEN(const header * item)
{
    return ((item)->LEN);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

uint8_t get_CAT(const uint8_t * data)
{
    return data[0];
}

uint16_t get_LEN(const uint8_t * data)
{
    return (((uint16_t) (data[1] << 8)) | ((uint16_t) (data[2])));
}

void print_header(const header * item)
{
    printf("ASTERIX header\n");
    printf("  CAT = %d\n", get_header_CAT(item));
    printf("  LEN = %d\n", get_header_LEN(item));
}