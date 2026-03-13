/**
 * @file I034_090.c
 * @brief 
 * @version 0.1
 * @date 2026-02-11
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/I034/I034_090.h>

/* =============================== DE/ENCODE =============================== */

void encode_I034_090(BitStream *bs, const I034_090 *item)
{
    bs_serialize_sfloat(bs, item->RANGEERR, I034_090_LSB_RANGEERR, 8U);
    bs_serialize_sfloat(bs, item->AZERR, I034_090_LSB_AZERR, 8U);
}

void decode_I034_090(BitStream *bs, I034_090 *item)
{
    item->RANGEERR = bs_deserialize_sfloat(bs, I034_090_LSB_RANGEERR, 8U);
    item->AZERR = bs_deserialize_sfloat(bs, I034_090_LSB_AZERR, 8U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I034_090(const I034_090 *item)
{
    printf("I034/090 - Collimation Error:\n");
    if (!item)
    {
        printf("I034/090: <null>\n");
        return;
    }
    printf("- RANGE ERROR: %.3f NM\n", item->RANGEERR);
    printf("- AZIMUTH ERROR: %.3f degrees\n", item->AZERR);
}
