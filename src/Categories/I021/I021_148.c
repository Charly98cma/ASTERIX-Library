/**
 * @file I021_148.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_148.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_148(BitStream *bs, const I021_148 *item)
{
    bs_serialize_u8(bs, item->MV, 1U);
    bs_serialize_u8(bs, item->AH, 1U);
    bs_serialize_u8(bs, item->AM, 1U);
    bs_serialize_s16(bs, item->ALT, 13U);
}

void decode_I021_148(BitStream *bs, I021_148 *item)
{
    item->MV = bs_deserialize_u8(bs, 1U);
    item->AH = bs_deserialize_u8(bs, 1U);
    item->AM = bs_deserialize_u8(bs, 1U);
    item->ALT = bs_deserialize_s16(bs, 13U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_148(const I021_148 * item)
{
    printf("I021/148 - Final State Selected Altitude\n");
    if (!item)
    {
        printf("I021/148 <null>\n");
        return;
    }
    printf("- MV = %u\n", item->MV);
    printf("- AH = %u\n", item->AH);
    printf("- AM = %u\n", item->AM);
    printf("- ALT = %d\n", item->ALT);
}
