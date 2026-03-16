/**
 * @file I021_077.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2026-03-16
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>

#include <Categories/I021/I021_077.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_077(BitStream *bs, const I021_077 *item)
{
    bs_serialize_ufloat(bs, item->TART, I021_077_LSB_TART, 24U);
}

void decode_I021_077(BitStream *bs, I021_077 *item)
{
    item->TART = bs_deserialize_ufloat(bs, I021_077_LSB_TART, 24U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_077(const I021_077 *item)
{
    printf("I021/077 - Time of ASTERIX Report Transmission\n");
    if (!item)
    {
        printf("I021/077: <null>\n");
        return;
    }
    printf("- TART (seconds) = %f\n", item->TART);
}
