/**
 * @file I021_145.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_145.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_145(BitStream *bs, const I021_145 *item)
{
    bs_serialize_sfloat(bs, item->FL, I021_145_LSB_FL, 16U);
}

void decode_I021_145(BitStream *bs, I021_145 *item)
{
    item->FL = bs_deserialize_sfloat(bs, I021_145_LSB_FL, 16U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_145(const I021_145 * item)
{
    printf("I021/145 - Flight Level\n");
    if (!item)
    {
        printf("I021/145 <null>\n");
        return;
    }
    printf("- FL = %f\n", item->FL);
}