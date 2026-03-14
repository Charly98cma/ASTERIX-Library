/**
 * @file I021_015.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_015.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_015(BitStream *bs, const I021_015 *item)
{
    bs_serialize_u32(bs, item->SI, 8U);
}

void decode_I021_015(BitStream *bs, I021_015 *item)
{
    item->SI = bs_deserialize_u32(bs, 8U);
}
/* ============================== EXTRA FUNCS ============================== */

void print_I021_015(const I021_015 *item)
{
    printf("I021/015 - Service Identification\n");
    if (!item)
    {
        printf("I021/015: <null>\n");
        return;
    }
    printf("- SI: 0x%02X\n\n", item->SI);
}
