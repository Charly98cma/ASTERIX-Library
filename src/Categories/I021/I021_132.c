/**
 * @file I021_132.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_132.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_132(BitStream *bs, const I021_132 *item)
{
    bs_serialize_u8(bs, item->MAM, 8U);
}

void decode_I021_132(BitStream *bs, I021_132 *item)
{
    item->MAM = bs_deserialize_u8(bs, 8U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_132(const I021_132 * item)
{
    printf("I021/132 - Message Amplitude\n");
    if (!item)
    {
        printf("I021/132 <null>");
        return;
    }
    printf("- MAM (dBm) = %d\n", item->MAM);
}