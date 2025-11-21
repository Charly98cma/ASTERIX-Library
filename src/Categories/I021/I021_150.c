/**
 * @file I021_150.c
 * @brief Implementation of the Category 21 Item 150 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_150.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_150_IM(const I021_150 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 7);
}

double get_I021_150_AIRSPD(const I021_150 * item)
{
    uint16_t air_speed_raw = 0;
    if (!item) return 0.0F;
    air_speed_raw = read_unsigned_16bit(item->raw) & MASK_15_BITS;
    if (get_I021_150_IM(item) == I021_150_IM_IAS)
        return air_speed_raw * I021_150_LSB_IAS;
    return air_speed_raw * I021_150_LSB_MACH;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_150_IM(I021_150 * item, uint8_t im)
{
    if (!item) return;
    write_bits(item->raw, MASK_01_BITS, 7, im & MASK_01_BITS);
}

void set_I021_150_AIRSPD(I021_150 * item, double airspd)
{
    uint16_t airspd_raw = 0;
    if (!item) return;
    if (get_I021_150_IM(item) == I021_150_IM_IAS)
        airspd_raw = airspd / I021_150_LSB_IAS;
    else
        airspd_raw = airspd / I021_150_LSB_MACH;
    /* Write top 7 bits */
    write_bits(&item->raw[0], MASK_07_BITS, 0, (airspd_raw >> 8));
    /* Write remaining 8 bits */
    write_unsigned_8bit(&item->raw[1], airspd_raw & MASK_08_BITS);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_150(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_150 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_150 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I021_150(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_150 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_150 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_150(const I021_150 * item)
{
    uint8_t im = get_I021_150_IM(item);

    printf("I021/150 - Air Speed\n");
    if (!item)
    {
        printf("I021/150 <null>\n");
        return;
    }
    printf("- IM = %d\n", im);
    if (im == I021_150_IM_IAS)
        printf("- IAS = %f\n", get_I021_150_AIRSPD(item));
    else
        printf("- MACH = %f\n", get_I021_150_AIRSPD(item));
}