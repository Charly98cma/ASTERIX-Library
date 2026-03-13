/**
 * @file I034_110.c
 * @brief 
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/I034/I034_110.h>

/* =============================== DE/ENCODE =============================== */

void encode_I034_110(BitStream *bs, const I034_110 *item)
{
    bs_serialize_u32(bs, item->TYP, 8U);
}

void decode_I034_110(BitStream *bs, I034_110 *item)
{
    item->TYP = bs_deserialize_u32(bs, 8U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I034_110(const I034_110 *item)
{
    printf("I034/110 - Data Filter\n");
    if (!item)
    {
        printf("I034/110: <NULL POINTER>\n");
        return;
    }

    printf("- Data Filter Type (TYP): %u\n", item->TYP);
}