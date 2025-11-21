/**
 * @file I021_165.c
 * @brief Implementation of the Category 21 Item 165 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_165.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_165_TAR(const I021_165 * item)
{
    if (!item) return 0;
    return (read_unsigned_16bit(item->raw) & MASK_10_BITS) * I021_165_LSB_TAR;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_165_TAR(I021_165 * item, double tar_degpsec)
{
    int16_t tar_raw = 0;
    if (!item) return;
    if (tar_degpsec > 0)
        tar_raw = (int16_t) ((tar_degpsec / I021_165_LSB_TAR) + 0.5);
    write_unsigned_16bit(item->raw, tar_raw & MASK_10_BITS);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_165(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_165 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_165 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I021_165(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_165 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_165 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_165(const I021_165 * item)
{
    printf("I021/165 - Track Angle Rate\n");
    if (!item)
    {
        printf("I021/165 <null>\n");
        return;
    }
    printf("  TAR = %f\n", get_I021_165_TAR(item));
}