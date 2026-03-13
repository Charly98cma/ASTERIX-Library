/**
 * @file I021_008.c
 * @brief 
 * @version 0.1
 * @date 2026-03-13
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_008.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_008(BitStream *bs, const I021_008 *item)
{
    bs_serialize_u8(bs, item->RA, 1U);
    bs_serialize_u8(bs, item->TC, 2U);
    bs_serialize_u8(bs, item->TS, 1U);
    bs_serialize_u8(bs, item->ARV, 1U);
    bs_serialize_u8(bs, item->CDTI, 1U);
    bs_serialize_u8(bs, item->NTCAS, 1U);
    bs_serialize_u8(bs, item->SA, 1U);
}

void decode_I021_008(BitStream *bs, I021_008 *item)
{
    item->RA = bs_deserialize_u8(bs, 1U);
    item->TC = bs_deserialize_u8(bs, 2U);
    item->TS = bs_deserialize_u8(bs, 1U);
    item->ARV = bs_deserialize_u8(bs, 1U);
    item->CDTI = bs_deserialize_u8(bs, 1U);
    item->NTCAS = bs_deserialize_u8(bs, 1U);
    item->SA = bs_deserialize_u8(bs, 1U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_008(const I021_008 *item)
{
    printf("I021/008 - Aircraft Operational Status\n");
    if (!item)
    {
        printf("I021/008: <null>\n");
        return;
    }
    printf("- RA: %d\n", item->RA);
    printf("- TC: %d\n", item->TC);
    printf("- TS: %d\n", item->TS);
    printf("- ARV: %d\n", item->ARV);
    printf("- CDTI: %d\n", item->CDTI);
    printf("- NTCAS: %d\n", item->NTCAS);
    printf("- SA: %d\n\n", item->SA);
}
