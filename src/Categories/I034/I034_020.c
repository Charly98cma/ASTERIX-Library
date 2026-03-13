/**
 * @file I034_020.c
 * @brief 
 * @version 0.1
 * @date 2026-02-11
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/I034/I034_020.h>

/* =============================== DE/ENCODE =============================== */

void encode_I034_020(BitStream *bs, const I034_020 *item)
{
    bs_serialize_ufloat(bs, item->SECTAZ, I034_020_LSB_SECTNUM, 8U);
}

void decode_I034_020(BitStream *bs, I034_020 *item)
{
    item->SECTAZ = bs_deserialize_ufloat(bs, I034_020_LSB_SECTNUM, 8U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I034_020(const I034_020 *item)
{
    printf("I034/020 - Sector Number\n");
    if (!item)
    {
        printf("I034/020: <null>\n");
        return;
    }
    printf("- SECTORNUM = %.4f deg\n", item->SECTAZ);
}
