/**
 * @file I021_200.c
 * @brief Implementation of the Category 21 Item 200 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_200.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_200_ICF(const I021_200 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 7);
}

uint8_t get_I021_200_LNAV(const I021_200 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 6);
}

uint8_t get_I021_200_ME(const I021_200 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 5);
}

uint8_t get_I021_200_PS(const I021_200 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_03_BITS, 2);
}

uint8_t get_I021_200_SS(const I021_200 * item)
{
    if (!item) return 0;
    return item->raw & MASK_02_BITS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_200_ICF(I021_200 * item, uint8_t icf)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 7, icf);
}

void set_I021_200_LNAV(I021_200 * item, uint8_t lnav)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 6, lnav);
}

void set_I021_200_ME(I021_200 * item, uint8_t me)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 5, me);
}

void set_I021_200_PS(I021_200 * item, uint8_t ps)
{
    if (!item) return;
    write_bits(&item->raw, MASK_03_BITS , 2, ps);
}

void set_I021_200_SS(I021_200 * item, uint8_t ss)
{
    if (!item) return;
    write_bits(&item->raw, MASK_02_BITS, 0, ss);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_200(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_200 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_200 *) item_in;
    memcpy(&msg_out[out_index], &item->raw, 1);
    return out_index + 1;
}

uint16_t decode_I021_200(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_200 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_200 *) item_out;
    memcpy(&item->raw, &msg_in[in_index], 1);
    return in_index + 1;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_200(const I021_200 * item)
{
    printf("I021/200 - Target Status\n");
    if (!item)
    {
        printf("I021/200 <null>\n");
        return;
    }
    printf("- ICF = %d\n", get_I021_200_ICF(item));    
    printf("- LNAV = %d\n", get_I021_200_LNAV(item));    
    printf("- ME = %d\n", get_I021_200_ME(item));    
    printf("- PS = %d\n", get_I021_200_PS(item));    
    printf("- SS = %d\n", get_I021_200_SS(item));
}
