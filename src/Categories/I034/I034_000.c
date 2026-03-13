/**
 * @file I034_000.c
 * @brief 
 * @version 0.1
 * @date 2026-02-11
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/I034/I034_000.h>

/* =============================== DE/ENCODE =============================== */

void encode_I034_000(BitStream *bs, const I034_000 *item)
{
    bs_serialize_u32(bs, item->MSGTYPE, 8U);
}

void decode_I034_000(BitStream *bs, I034_000 *item)
{
    item->MSGTYPE = bs_deserialize_u32(bs, 8U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I034_000(const I034_000 *item)
{
    printf("I034/000 - Message Type\n");
    if (!item)
    {
        printf("I034/000: <null>\n");
        return;
    }
    printf("- MSGTYPE = %u\n", item->MSGTYPE);
}