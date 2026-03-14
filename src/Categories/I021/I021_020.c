/**
 * @file I021_020.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_020.h>

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

void encode_I021_020(BitStream *bs, const I021_020 *item)
{
    bs_serialize_u8(bs, item->ECAT, 8U);
}

void decode_I021_020(BitStream *bs, I021_020 *item)
{
    item->ECAT = bs_deserialize_u8(bs, 8U);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_020(const I021_020 *item)
{
    printf("I021/020 - Emitter Category\n");
    if (!item)
    {
        printf("I021/020: <null>\n");
        return;
    }
    printf("- ECAT: %u\n\n", item->ECAT);
}
