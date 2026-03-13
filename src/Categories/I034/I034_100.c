/**
 * @file I034_100.c
 * @brief 
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/I034/I034_100.h>

/* =============================== DE/ENCODE =============================== */

void encode_I034_100(BitStream *bs, const I034_100 *item)
{
    bs_serialize_ufloat(bs, item->RHO_START, I034_100_LSB_RHO, 16U);
    bs_serialize_ufloat(bs, item->RHO_END, I034_100_LSB_RHO, 16U);
    bs_serialize_ufloat(bs, item->THETA_START, I034_100_LSB_THETA, 16U);
    bs_serialize_ufloat(bs, item->THETA_END, I034_100_LSB_THETA, 16U);
}

void decode_I034_100(BitStream *bs, I034_100 *item)
{
    item->RHO_START = bs_deserialize_ufloat(bs, I034_100_LSB_RHO, 16U);
    item->RHO_END = bs_deserialize_ufloat(bs, I034_100_LSB_RHO, 16U);
    item->THETA_START = bs_deserialize_ufloat(bs, I034_100_LSB_THETA, 16U);
    item->THETA_END = bs_deserialize_ufloat(bs, I034_100_LSB_THETA, 16U);    
}

/* ============================== EXTRA FUNCS ============================== */

void print_I034_100(const I034_100 *item)
{
    printf("I034/100 - Generic Polar Window:\n");
    if (!item)
    {
        printf("I034/100: <null>\n");
        return;
    }
    printf("- RHO START: %.3f NM\n", item->RHO_START);
    printf("- RHO END: %.3f NM\n", item->RHO_END);
    printf("- THETA START: %.4f degrees\n", item->THETA_START);
    printf("- THETA END: %.4f degrees\n", item->THETA_END);
}