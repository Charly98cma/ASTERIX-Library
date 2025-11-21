/**
 * @file I021_210.c
 * @brief Implementation of the Category 21 Item 210 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_210.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_210_VNS(const I021_210 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 6);
}

uint8_t get_I021_210_VN(const I021_210 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_03_BITS, 3);
}

uint8_t get_I021_210_LTT(const I021_210 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_03_BITS, 0);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_210_VNS(I021_210 * item, uint8_t vns)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 6, vns);
}

void set_I021_210_VN(I021_210 * item, uint8_t vn)
{
    if (!item) return;
    write_bits(&item->raw, MASK_03_BITS, 3, vn);
}

void set_I021_210_LTT(I021_210 * item, uint8_t ltt)
{
    if (!item) return;
    write_bits(&item->raw, MASK_03_BITS, 0, ltt);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_210(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_210 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_210 *) item_in;
    memcpy(&msg_out[out_index], &item->raw, 1);
    return out_index + 1;
}

uint16_t decode_I021_210(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_210 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_210 *) item_out;
    memcpy(&item->raw, &msg_in[in_index], 1);
    return in_index + 1;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_210(const I021_210 * item)
{
    printf("I021/200 - MOPS Version\n");
    if (!item)
    {
        printf("I021/200 <null>\n");
        return;
    }
    printf("- VNS = %d\n", get_I021_210_VNS(item));
    printf("- VN = %d\n", get_I021_210_VN(item));
    printf("- LTT = %d\n", get_I021_210_LTT(item));
}