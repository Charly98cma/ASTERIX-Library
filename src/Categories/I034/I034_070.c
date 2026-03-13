/**
 * @file I034_070.c
 * @brief 
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/I034/I034_070.h>

/* =============================== DE/ENCODE =============================== */

 void encode_I034_070(BitStream *bs, const I034_070 *item)
{
    bs_serialize_u32(bs, item->REP, 8U);
    for (u8 i = 0U; i < item->REP; i++)
    {
        bs_serialize_u32(bs, item->COUNTER[i].TYP, 5U);
        bs_serialize_u32(bs, item->COUNTER[i].COUNTER, 11U);
    }
}

void decode_I034_070(BitStream *bs, I034_070 *item)
{
    item->REP = bs_deserialize_u32(bs, 8);
    for (u8 i = 0U; i < item->REP; i++)
    {
        item->COUNTER[i].TYP = bs_deserialize_u32(bs, 5U);
        item->COUNTER[i].COUNTER = bs_deserialize_u32(bs, 11U);
    }
}

/* ============================== EXTRA FUNCS ============================== */

void print_I034_070(const I034_070 *item)
{
    printf("I034/070 - Message Count Values\n");
    if (!item)
    {
        printf("I034/070: <null>\n");
        return;
    }

    printf("- REP = %u\n", item->REP);
    for (u8 i = 0U; i < item->REP; i++)
    {
        printf("-- COUNTER[%d] : TYP = %u | COUNTER = %u\n",
            i + 1, item->COUNTER[i].TYP, item->COUNTER[i].COUNTER);
    }
}