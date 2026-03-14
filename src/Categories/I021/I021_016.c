/**
 * @file I021_016.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_016.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_016(BitStream *bs, const I021_016 *item)
{
    bs_serialize_ufloat(bs, item->RP, I021_016_LSB_RP, 8U);
}

void decode_I021_016(BitStream *bs, I021_016 *item)
{
    item->RP = bs_deserialize_ufloat(bs, I021_016_LSB_RP, 8U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_016(const I021_016 *item)
{
    printf("I021/016 - Service Management\n");
    if (!item)
    {
        printf("I021/016: <null>\n");
        return;
    }
    printf("- RP (seconds): %f\n", item->RP);
}