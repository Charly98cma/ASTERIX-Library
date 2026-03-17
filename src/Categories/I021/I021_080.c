/**
 * @file I021_080.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-16
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_080.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_080(BitStream *bs, const I021_080 *item)
{
    bs_serialize_u32(bs, item->TGTADDR, 24U);
}

void decode_I021_080(BitStream *bs, I021_080 *item)
{
    item->TGTADDR = bs_deserialize_u32(bs, 24U);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_080(const I021_080 * item)
{
    printf("I021/080 - Target ICAO Address (24 bits)\n");
    if (!item)
    {
        printf("I021/080: <null>\n");
        return;
    }
    printf("- ICAO Addr = 0x%04X\n", item->TGTADDR);
}