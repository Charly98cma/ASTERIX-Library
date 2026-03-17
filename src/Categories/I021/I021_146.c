/**
 * @file I021_146.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_146.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_146(BitStream *bs, const I021_146 *item)
{
    bs_serialize_u8(bs, item->SAS, 1U);
    bs_serialize_u8(bs, item->SRC, 2U);
    bs_serialize_u16(bs, item->ALT, 13U);
}

void decode_I021_146(BitStream *bs, I021_146 *item)
{
    item->SAS = bs_deserialize_u8(bs, 1U);
    item->SRC = bs_deserialize_u8(bs, 2U);
    item->ALT = bs_deserialize_u16(bs, 13U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_146(const I021_146 * item)
{
    printf("I021/146 - Selected Altitude\n");
    if (!item)
    {
        printf("I021/146: <null>\n");
        return;
    }
    printf("- SAS = %u\n", item->SAS);
    printf("- SOURCE = %u\n", item->SRC);
    printf("- ALTITUDE = %d\n", item->ALT);
}
