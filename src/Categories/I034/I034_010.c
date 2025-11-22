/**
 * @file I034_010.c
 * @brief Implementation of the Category 21 Item 010 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I034/I034_010.h"

/******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I034_010_SAC(const I034_010 *item)
{
    return get_SAC((SAC_SIC *)item);
}

uint8_t get_I034_010_SIC(const I034_010 *item)
{
    return get_SIC((SAC_SIC *)item);
}

/******************************************************************************
 * Setters
 ******************************************************************************/

void set_I034_010_SAC(I034_010 *item, uint8_t sac_value)
{
    set_SAC((SAC_SIC *)item, sac_value);
}

void set_I034_010_SIC(I034_010 *item, uint8_t sic_value)
{
    set_SIC((SAC_SIC *)item, sic_value);
}

/******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I034_010(void *item_in, unsigned char *msg_out, uint16_t out_index)
{
    return encode_SAC_SIC((SAC_SIC *)item_in, msg_out, out_index);
}

uint16_t decode_I034_010(void *item_out, const unsigned char *msg_in, uint16_t in_index)
{
    return decode_SAC_SIC((SAC_SIC *)item_out, msg_in, in_index);
}

/******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I034_010(const I034_010 *item)
{
    printf("I034/010 - Data Source Identification\n");
    if (!item)
    {
        printf("I034/010: <null>\n");
        return;
    }
    printf("- SAC = 0x%02X\n", get_I034_010_SAC(item));
    printf("- SIC = 0x%02X\n\n", get_I034_010_SIC(item));
}
