/**
 * @file I021_130.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_130.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_130(BitStream *bs, const I021_130 *item)
{
    bs_serialize_sfloat(bs, item->LAT, I021_130_LSB_LAT, 24U);
    bs_serialize_sfloat(bs, item->LON, I021_130_LSB_LON, 24U);
}

void decode_I021_130(BitStream *bs, I021_130 *item)
{
    item->LAT = bs_deserialize_sfloat(bs, I021_130_LSB_LAT, 24U);
    item->LON = bs_deserialize_sfloat(bs, I021_130_LSB_LON, 24U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_130(const I021_130 * item)
{
    printf("I021/130 - Position in WGS-84 Co-ordinates\n");
    if (!item)
    {
        printf("I021/130: <null>\n");
        return;
    }
    printf("- LAT (degrees) = %f\n", item->LAT);
    printf("- LON (degrees) = %f\n", item->LON);
}
