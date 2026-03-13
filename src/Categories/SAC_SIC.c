/**
 * @file SAC_SIC.c
 * @brief 
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/SAC_SIC.h>

/* =============================== DE/ENCODE =============================== */

void encode_SAC_SIC(BitStream *bs, const SAC_SIC *item)
{
    bs_serialize_u32(bs, item->SAC, 8U);
    bs_serialize_u32(bs, item->SIC, 8U);
}

void decode_SAC_SIC(BitStream *bs, SAC_SIC *item)
{
    item->SAC = bs_deserialize_u32(bs, 8U);
    item->SIC = bs_deserialize_u32(bs, 8U);
}

/* ============================== EXTRA FUNCS ============================== */
