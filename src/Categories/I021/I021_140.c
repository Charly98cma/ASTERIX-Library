/**
 * @file I021_140.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_140.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_140(BitStream *bs, const I021_140 *item)
{
    bs_serialize_sfloat(bs, item->GH, I021_140_LSB_GH, 16U);
}

void decode_I021_140(BitStream *bs, I021_140 *item)
{
    item->GH = bs_deserialize_sfloat(bs, I021_140_LSB_GH, 16U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_140(const I021_140 * item)
{
    printf("I021/140 - Geometric Height\n");
    if (!item)
    {
        printf("I021/140 <null>");
        return;
    }
    printf("- GH (feets) = %f\n", item->GH);
}