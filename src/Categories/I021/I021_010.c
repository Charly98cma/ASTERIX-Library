/**
 * @file I021_010.c
 * @brief Implementation of the Category 21 Item 010 functions
 */

#include <stdio.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_010.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_010_SAC(const I021_010 *item)
{
    if (!item) return 0;
    return get_SAC((SAC_SIC *)item);
}

uint8_t get_I021_010_SIC(const I021_010 *item)
{
    if (!item) return 0;
    return get_SIC((SAC_SIC *)item);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_010_SAC(I021_010 *item, uint8_t sac_value)
{
    if (!item) return;
    set_SAC((SAC_SIC *)item, sac_value);
}

void set_I021_010_SIC(I021_010 *item, uint8_t sic_value)
{
    if (!item) return;
    set_SIC((SAC_SIC *)item, sic_value);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_010(void *item_in, unsigned char *msg_out, uint16_t out_index)
{
    if (!item_in || !msg_out) return out_index;
    return encode_SAC_SIC((SAC_SIC *)item_in, msg_out, out_index);
}

uint16_t decode_I021_010(void *item_out, const unsigned char *msg_in, uint16_t in_index)
{
    if (!item_out || !msg_in) return in_index;
    return decode_SAC_SIC((SAC_SIC *)item_out, msg_in, in_index);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_010(const I021_010 *item)
{
    printf("I021/010 - Data Source Identification\n");
    if (!item)
    {
        printf("I021/010: <null>\n");
        return;
    }
    printf("- SAC: 0x%02X\n", get_I021_010_SAC(item));
    printf("- SIC: 0x%02X\n\n", get_I021_010_SIC(item));
}
