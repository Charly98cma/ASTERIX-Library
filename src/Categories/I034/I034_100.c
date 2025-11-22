/**
 * @file I034_100.c
 * @brief Implementation of I100/000 - Generic Polar Window
 */

#include <stdio.h>
#include <string.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I034/I034_100.h"

/*****************************************************************************
 * Getters
 ******************************************************************************/

float get_I034_100_RHO_START(const I034_100 *item)
{
    if (!item) return 0.0f;
    return read_unsigned_16bit(item->raw) * I034_100_LSB_RHO;
}

float get_I034_100_RHO_END(const I034_100 *item)
{
    if (!item) return 0.0f;
    return read_unsigned_16bit(&item->raw[2]) * I034_100_LSB_RHO;
}

float get_I034_100_THETA_START(const I034_100 *item)
{
    if (!item) return 0.0f;
    return read_unsigned_16bit(&item->raw[4]) * I034_100_LSB_THETA;
}

float get_I034_100_THETA_END(const I034_100 *item)
{
    if (!item) return 0.0f;
    return read_unsigned_16bit(&item->raw[6]) * I034_100_LSB_THETA;
}

/*****************************************************************************
 * Setters
 ******************************************************************************/

void set_I034_100_RHO_START(I034_100 *item, float rho_start)
{
    uint16_t raw_value;
    if (!item) return;
    raw_value = (uint16_t)(rho_start / I034_100_LSB_RHO + 0.5f);
    write_unsigned_16bit(item->raw, raw_value);
}

void set_I034_100_RHO_END(I034_100 *item, float rho_end)
{
    uint16_t raw_value;
    if (!item) return;
    raw_value = (uint16_t)(rho_end / I034_100_LSB_RHO + 0.5f);
    write_unsigned_16bit(&item->raw[2], raw_value);
}

void set_I034_100_THETA_START(I034_100 *item, float theta_start)
{
    uint16_t raw_value;
    if (!item) return;
    raw_value = (uint16_t)(theta_start / I034_100_LSB_THETA + 0.5f);
    write_unsigned_16bit(&item->raw[4], raw_value);
}

void set_I034_100_THETA_END(I034_100 *item, float theta_end)
{
    uint16_t raw_value;
    if (!item) return;
    raw_value = (uint16_t)(theta_end / I034_100_LSB_THETA + 0.5f);
    write_unsigned_16bit(&item->raw[6], raw_value);
}

/*****************************************************************************
 * Encoding and Decoding
 ******************************************************************************/

uint16_t encode_I034_100(void *item_in, unsigned char *msg_out, uint16_t out_index)
{
    I034_100 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I034_100 *)item_in;
    memcpy(&msg_out[out_index], item->raw, 8);
    return out_index + 8;
}

uint16_t decode_I034_100(void *item_out, const unsigned char *msg_in, uint16_t in_index)
{
    I034_100 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I034_100 *)item_out;
    memcpy(item->raw, &msg_in[in_index], 8);
    return in_index + 8;
}

/*****************************************************************************
 * Print
 ******************************************************************************/

void print_I034_100(const I034_100 *item)
{
    printf("I034/100 - Generic Polar Window:\n");
    if (!item)
    {
        printf("I034/100: <null>\n");
        return;
    }
    printf("- RHO START: %.3f NM\n", get_I034_100_RHO_START(item));
    printf("- RHO END: %.3f NM\n", get_I034_100_RHO_END(item));
    printf("- THETA START: %.4f degrees\n", get_I034_100_THETA_START(item));
    printf("- THETA END: %.4f degrees\n", get_I034_100_THETA_END(item));
}