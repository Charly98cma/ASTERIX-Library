/**
 * @file I021_148.c
 * @brief Implementation of the Category 21 Item 148 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_148.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_148_MV(const I021_148 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 7);
}

uint8_t get_I021_148_AH(const I021_148 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 6);
}

uint8_t get_I021_148_AM(const I021_148 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 5);
}

int32_t get_I021_148_ALT(const I021_148 * item)
{
    if (!item) return 0;
    return (read_twocomp_16bit(&item->raw[0]) & MASK_13_BITS) * I021_148_LSB_ALT;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_148_MV(I021_148 * item, uint8_t sas)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 7, sas);
}

void set_I021_148_AH(I021_148 * item, uint8_t ah)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 6, ah);
}

void set_I021_148_AM(I021_148 * item, uint8_t am)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 5, am);
}

void set_I021_148_ALT(I021_148 * item, int32_t alt)
{
    int16_t alt_raw = 0;
    if (!item) return;
    if (alt > 0)
        alt_raw = (int16_t) ((alt / I021_148_LSB_ALT) + 0.5);
    /* Write top 5 bits */
    write_bits(&item->raw[0], MASK_05_BITS, 0, (alt_raw >> 8));
    /* Write remaining 8 bits */
    write_unsigned_8bit(&item->raw[1], (alt_raw & MASK_08_BITS));
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_148(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_148 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_148 *)item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I021_148(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_148 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_148 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_148(const I021_148 * item)
{
    printf("I021/148 - Final State Selected Altitude\n");
    if (!item)
    {
        printf("I021/148 <null>\n");
        return;
    }
    printf("- MV = %d\n", get_I021_148_MV(item));
    printf("- AH = %d\n", get_I021_148_AH(item));
    printf("- AM = %d\n", get_I021_148_AM(item));
    printf("- ALT = %d\n", get_I021_148_ALT(item));
}
