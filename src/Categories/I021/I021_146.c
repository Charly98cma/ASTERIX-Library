/**
 * @file I021_146.c
 * @brief Implementation of the Category 21 Item 146 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_146.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_146_SAS(const I021_146 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 7);
}

uint8_t get_I021_146_SRC(const I021_146 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_02_BITS, 5);
}

int32_t get_I021_146_ALT(const I021_146 * item)
{
    return (read_twocomp_16bit(&item->raw[0]) & MASK_13_BITS) * I021_146_LSB_ALT;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_146_SAS(I021_146 * item, uint8_t sas)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 7, sas);
}

void set_I021_146_SRC(I021_146 * item, uint8_t src)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_02_BITS, 5, src);
}

void set_I021_146_ALT(I021_146 * item, const int32_t alt)
{
    int16_t alt_raw = 0;
    if (!item) return;
    if (alt > 0)
        alt_raw = (int16_t) ((alt / I021_146_LSB_ALT) + 0.5);
    write_twocomp_16bit(item->raw, alt_raw & MASK_13_BITS);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_146(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_146 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_146 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I021_146(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_146 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_146 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_146(const I021_146 * item)
{
    printf("I021/146 - Selected Altitude\n");
    if (!item)
    {
        printf("I021/146: <null>\n");
        return;
    }
    printf("- SAS = %d\n", get_I021_146_SAS(item));
    printf("- SOURCE = %d\n", get_I021_146_SRC(item));
    printf("- ALTITUDE = %d\n", get_I021_146_ALT(item));
}
