/**
 * @file I034_120.c
 * @brief 
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/I034/I034_120.h>

/* =============================== DE/ENCODE =============================== */

void encode_I034_120(BitStream *bs, const I034_120 *item)
{
    bs_serialize_u16(bs, item->HEIGHT, 16U);
    bs_serialize_sfloat(bs, item->LATWGS84, I034_120_LSB_LATWGS84, 24U);
    bs_serialize_sfloat(bs, item->LONWGS84, I034_120_LSB_LONWGS84, 24U);
}

void decode_I034_120(BitStream *bs, I034_120 *item)
{
    item->HEIGHT = bs_deserialize_u16(bs, 16U);
    item->LATWGS84 = bs_deserialize_sfloat(bs, I034_120_LSB_LATWGS84, 24U);
    item->LONWGS84 = bs_deserialize_sfloat(bs, I034_120_LSB_LONWGS84, 24U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I034_120(const I034_120 *item)
{
    printf("I034/120 - 3D-Position of Data Source\n");
    if (!item)
    {
        printf("I034/120: <null>\n");
        return;
    }
    printf("- HEIGHT WGS84 = %d\n", item->HEIGHT);
    printf("- LATITUDE WGS84 = %f\n", item->LATWGS84);
    printf("- LONGITUDE WGS84 = %f\n", item->LONWGS84);
}
