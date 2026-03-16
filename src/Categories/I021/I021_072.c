/**
 * @file I021_072.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2026-03-16
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>

#include <Categories/I021/I021_072.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_072(BitStream *bs, const I021_072 *item)
{
    bs_serialize_ufloat(bs, item->TAV, I021_072_LSB_TAV, 24U);
}

void decode_I021_072(BitStream *bs, I021_072 *item)
{
    item->TAV = bs_deserialize_ufloat(bs, I021_072_LSB_TAV, 24U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_072(const I021_072 *item)
{
    printf("I021/072 - Time of Applicability for Velocity\n");
    if (!item)
    {
        printf("I021/072: <null>\n");
        return;
    }
    printf("- TAV (seconds) = %f\n", item->TAV);
}
