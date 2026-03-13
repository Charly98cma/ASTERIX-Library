/**
 * @file I034_030.c
 * @brief 
 * @version 0.1
 * @date 2026-02-11
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/I034/I034_030.h>

/* =============================== DE/ENCODE =============================== */

void encode_I034_030(BitStream *bs, const I034_030 *item)
{
    bs_serialize_ufloat(bs, item->TOD, I034_030_LSB_TOD, 24U);
}

void decode_I034_030(BitStream *bs, I034_030 *item)
{
    item->TOD = bs_deserialize_ufloat(bs, I034_030_LSB_TOD, 24U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I034_030(const I034_030 *item)
{
    printf("I034/030 - Time of Day (TOD)\n");
    if (!item)
    {
        printf("I034/030: <null>\n");
        return;
    }
    printf("- TOD = %f\n", item->TOD);
}
