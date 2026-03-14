/**
 * @file I021_010.c
 * @brief 
 * @version 0.1
 * @date 2026-02-11
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/I021/I021_010.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_010(BitStream *bs, const I021_010 *item)
{
    encode_SAC_SIC(bs, item);
}

void decode_I021_010(BitStream *bs, I021_010 *item)
{
    decode_SAC_SIC(bs, item);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_010(const I021_010 *item)
{
    printf("I021/010 - Data Source Identification\n");
    if (!item)
    {
        printf("I021/010: <null>\n");
        return;
    }
    printf("- SAC = 0x%02X / SIC = 0x%02X\n", item->SAC, item->SIC);
}
