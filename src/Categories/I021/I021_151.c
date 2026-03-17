/**
 * @file I021_151.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_151.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_151(BitStream *bs, const I021_151 *item)
{
    bs_serialize_u8(bs, item->RE, 1U);
    bs_serialize_u16(bs, item->TAS, 15U);
}

void decode_I021_151(BitStream *bs, I021_151 *item)
{
    item->RE = bs_deserialize_u8(bs, 1U);
    item->TAS = bs_deserialize_u16(bs, 15U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_151(const I021_151 * item)
{
    printf("I021/151 - True Air Speed\n");
    if (!item)
    {
        printf("I021/151 <null>\n");
        return;
    }
    printf("- RE = %u\n", item->RE);
    printf("- TAS = %u\n", item->TAS);
}