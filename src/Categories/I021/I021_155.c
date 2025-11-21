/**
 * @file I021_155.c
 * @brief Implementation of the Category 21 Item 155 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_155.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_155_RE(const I021_155 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 7);
}

double get_I021_155_BVR(const I021_155 * item)
{
    if (!item) return 0.0F;
    return (read_twocomp_16bit(item->raw) & MASK_15_BITS) * I021_155_LSB_BVR;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_155_RE(I021_155 * item, uint8_t re)
{
    if (!item) return;
    write_bits(item->raw, MASK_01_BITS, 7, re & MASK_01_BITS);
}

void set_I021_155_BVR(I021_155 * item, double bvr_ftpmin)
{
    int16_t bvr_raw = 0;
    if (!item) return;
    if (bvr_ftpmin > 0)
        bvr_raw = (int16_t) ((bvr_ftpmin / I021_155_LSB_BVR) + 0.5);
    /* Write top 7 bits */
    write_bits(&item->raw[0], MASK_07_BITS, 0, bvr_raw >> 8);
    /* Write remaining 8 bits */
    write_unsigned_8bit(&item->raw[1], bvr_raw & MASK_08_BITS);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_155(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_155 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_155 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I021_155(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_155 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_155 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_155(const I021_155 * item)
{
    printf("I021/155 - Barometric Vertical Rate\n");
    if (!item)
    {
        printf("I021/155 <null>\n");
        return;
    }
    printf("- RE = %d\n", get_I021_155_RE(item));
    printf("- BVR (feet/minute) = %f\n", get_I021_155_BVR(item));
}