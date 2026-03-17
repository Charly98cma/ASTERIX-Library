/**
 * @file I021_131.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2026-03-17
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>

#include <Categories/I021/I021_131.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_131(BitStream *bs, const I021_131 *item)
{
    bs_serialize_sfloat(bs, item->LAT, I021_131_LSB_LAT, 32U);
    bs_serialize_sfloat(bs, item->LON, I021_131_LSB_LON, 32U);
}

void decode_I021_131(BitStream *bs, I021_131 *item)
{
    item->LAT = bs_deserialize_sfloat(bs, I021_131_LSB_LAT, 32U);
    item->LON = bs_deserialize_sfloat(bs, I021_131_LSB_LON, 32U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_131(const I021_131 *item)
{
    printf("I021/131 - High-Resolution Position in WGS-84 Co-ordinates\n");
    if (!item)
    {
        printf("I021/131: <null>\n");
        return;
    }
    printf("- LAT (degrees) = %f\n", item->LAT);
    printf("- LON (degrees) = %f\n", item->LON);
}
