/**
 * @file I034_010.c
 * @brief 
 * @version 0.1
 * @date 2026-02-11
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/I034/I034_010.h>

/* =============================== DE/ENCODE =============================== */

void encode_I034_010(BitStream *bs, const I034_010 *item)
{
    encode_SAC_SIC(bs, item);
}

void decode_I034_010(BitStream *bs, I034_010 *item)
{
    decode_SAC_SIC(bs, item);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I034_010(const I034_010 *item)
{
    printf("I034/010 - Data Source Identification\n");
    if (!item)
    {
        printf("I034/010: <null>\n");
        return;
    }
    printf("- SAC = 0x%02X / SIC = 0x%02X\n", item->SAC, item->SIC);
}
