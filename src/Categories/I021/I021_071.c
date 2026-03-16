/**
 * @file I021_071.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-16
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_071.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_071(BitStream *bs, const I021_071 *item)
{
    bs_serialize_ufloat(bs, item->TAP, I021_071_LSB_TAP, 24U);
}

void decode_I021_071(BitStream *bs, I021_071 *item)
{
    item->TAP = bs_deserialize_ufloat(bs, I021_071_LSB_TAP, 24U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_071(const I021_071 * item)
{
    printf("I021/071 - Time of Applicability for Position\n");
    if (!item)
    {
        printf("I021/071: <null>\n");
        return;
    }
    printf("- TAP (seconds) = %f\n", item->TAP);
}
