/**
 * @file I034_041.c
 * @brief 
 * @version 0.1
 * @date 2026-02-11
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/I034/I034_041.h>

/* =============================== DE/ENCODE =============================== */

void encode_I034_041(BitStream *bs, const I034_041 *item)
{
    bs_serialize_ufloat(bs, item->ANTROTSPD, I034_042_LSB_ANTROTSPD, 16U);
}

void decode_I034_041(BitStream *bs, I034_041 *item)
{
    item->ANTROTSPD = bs_deserialize_ufloat(bs, I034_042_LSB_ANTROTSPD, 16U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I034_041(const I034_041 *item)
{
    printf("I034/041 - Antenna Rotation Speed\n");
    if (!item)
    {
        printf("I034/041: <null>\n");
        return;
    }
    printf("- ANTROTSPD = %f\n", item->ANTROTSPD);
}
