/**
 * @file I034.c
 * @brief 
 * @version 0.1
 * @date 2026-02-13
 * 
 * @copyright Copyright (c) 2026
 */
#include <Categories/I034/I034.h>

/* =============================== DE/ENCODE =============================== */

void encode_I034(BitStream *bs, const I034 *item)
{
    // FSPEC
    bs_serialize_u8(bs, item->FSPEC.I034_010, 1U);
    bs_serialize_u8(bs, item->FSPEC.I034_000, 1U);
    bs_serialize_u8(bs, item->FSPEC.I034_030, 1U);
    bs_serialize_u8(bs, item->FSPEC.I034_020, 1U);
    bs_serialize_u8(bs, item->FSPEC.I034_041, 1U);
    bs_serialize_u8(bs, item->FSPEC.I034_050, 1U);
    bs_serialize_u8(bs, item->FSPEC.I034_060, 1U);
    bs_serialize_u8(bs, item->FSPEC.FX_1,     1U);
    if (item->FSPEC.FX_1 == ePresenceFlag_PRESENT)
    {
        bs_serialize_u8(bs, item->FSPEC.I034_070, 1U);
        bs_serialize_u8(bs, item->FSPEC.I034_100, 1U);
        bs_serialize_u8(bs, item->FSPEC.I034_110, 1U);
        bs_serialize_u8(bs, item->FSPEC.I034_120, 1U);
        bs_serialize_u8(bs, item->FSPEC.I034_090, 1U);
        bs_serialize_u8(bs, item->FSPEC.I034_RE,  1U);
        bs_serialize_u8(bs, item->FSPEC.I034_SP,  1U);
        bs_serialize_u8(bs, item->FSPEC.FX_2,     1U);
    }

    if (item->FSPEC.I034_010 == ePresenceFlag_PRESENT)
        encode_I034_010(bs, &item->I034_010);
    if (item->FSPEC.I034_000 == ePresenceFlag_PRESENT)
        encode_I034_000(bs, &item->I034_000);
    if (item->FSPEC.I034_030 == ePresenceFlag_PRESENT)
        encode_I034_030(bs, &item->I034_030);
    if (item->FSPEC.I034_020 == ePresenceFlag_PRESENT)
        encode_I034_020(bs, &item->I034_020);
    if (item->FSPEC.I034_041 == ePresenceFlag_PRESENT)
        encode_I034_041(bs, &item->I034_041);
    if (item->FSPEC.I034_050 == ePresenceFlag_PRESENT)
        encode_I034_050(bs, &item->I034_050);
    if (item->FSPEC.I034_060 == ePresenceFlag_PRESENT)
        encode_I034_060(bs, &item->I034_060);
    if (item->FSPEC.FX_1 == ePresenceFlag_PRESENT)
    {
        if (item->FSPEC.I034_070 == ePresenceFlag_PRESENT)
            encode_I034_070(bs, &item->I034_070);
        if (item->FSPEC.I034_100 == ePresenceFlag_PRESENT)
            encode_I034_100(bs, &item->I034_100);
        if (item->FSPEC.I034_110 == ePresenceFlag_PRESENT)
            encode_I034_110(bs, &item->I034_110);
        if (item->FSPEC.I034_120 == ePresenceFlag_PRESENT)
            encode_I034_120(bs, &item->I034_120);
        if (item->FSPEC.I034_090 == ePresenceFlag_PRESENT)
            encode_I034_090(bs, &item->I034_090);
        if (item->FSPEC.I034_RE == ePresenceFlag_PRESENT)
            encode_I034_RE(bs, &item->I034_RE);
        if (item->FSPEC.I034_SP == ePresenceFlag_PRESENT)
            encode_I034_SP(bs, &item->I034_SP);
    }

    // HEADER (CAT and LEN)
    bs_serialize_header(bs, 34U);
}

void decode_I034(BitStream *bs, I034 *item)
{
    // FSPEC
    item->FSPEC.I034_010 = bs_deserialize_u8(bs, 1U);
    item->FSPEC.I034_000 = bs_deserialize_u8(bs, 1U);
    item->FSPEC.I034_030 = bs_deserialize_u8(bs, 1U);
    item->FSPEC.I034_020 = bs_deserialize_u8(bs, 1U);
    item->FSPEC.I034_041 = bs_deserialize_u8(bs, 1U);
    item->FSPEC.I034_050 = bs_deserialize_u8(bs, 1U);
    item->FSPEC.I034_060 = bs_deserialize_u8(bs, 1U);
    item->FSPEC.FX_1     = bs_deserialize_u8(bs, 1U);
    if (item->FSPEC.FX_1 == ePresenceFlag_PRESENT)
    {
        item->FSPEC.I034_070 = bs_deserialize_u8(bs, 1U);
        item->FSPEC.I034_100 = bs_deserialize_u8(bs, 1U);
        item->FSPEC.I034_110 = bs_deserialize_u8(bs, 1U);
        item->FSPEC.I034_120 = bs_deserialize_u8(bs, 1U);
        item->FSPEC.I034_090 = bs_deserialize_u8(bs, 1U);
        item->FSPEC.I034_RE  = bs_deserialize_u8(bs, 1U);
        item->FSPEC.I034_SP  = bs_deserialize_u8(bs, 1U);
        item->FSPEC.FX_2     = bs_deserialize_u8(bs, 1U);        
    }

    // ITEMS
    if (item->FSPEC.I034_010 == ePresenceFlag_PRESENT)
        encode_I034_010(bs, &item->I034_010);
    if (item->FSPEC.I034_000 == ePresenceFlag_PRESENT)
        encode_I034_000(bs, &item->I034_000);
    if (item->FSPEC.I034_030 == ePresenceFlag_PRESENT)
        encode_I034_030(bs, &item->I034_030);
    if (item->FSPEC.I034_020 == ePresenceFlag_PRESENT)
        encode_I034_020(bs, &item->I034_020);
    if (item->FSPEC.I034_041 == ePresenceFlag_PRESENT)
        encode_I034_041(bs, &item->I034_041);
    if (item->FSPEC.I034_050 == ePresenceFlag_PRESENT)
        encode_I034_050(bs, &item->I034_050);
    if (item->FSPEC.I034_060 == ePresenceFlag_PRESENT)
        encode_I034_060(bs, &item->I034_060);
    if (item->FSPEC.FX_1 == ePresenceFlag_PRESENT)
    {
        if (item->FSPEC.I034_070 == ePresenceFlag_PRESENT)
            encode_I034_070(bs, &item->I034_070);
        if (item->FSPEC.I034_100 == ePresenceFlag_PRESENT)
            encode_I034_100(bs, &item->I034_100);
        if (item->FSPEC.I034_110 == ePresenceFlag_PRESENT)
            encode_I034_110(bs, &item->I034_110);
        if (item->FSPEC.I034_120 == ePresenceFlag_PRESENT)
            encode_I034_120(bs, &item->I034_120);
        if (item->FSPEC.I034_090 == ePresenceFlag_PRESENT)
            encode_I034_090(bs, &item->I034_090);
        if (item->FSPEC.I034_RE == ePresenceFlag_PRESENT)
            encode_I034_RE(bs, &item->I034_RE);
        if (item->FSPEC.I034_SP == ePresenceFlag_PRESENT)
            encode_I034_SP(bs, &item->I034_SP);
    }

    // HEADER (CAT and LEN)
    bs_serialize_header(bs, 34U);
}

/* ============================== EXTRA FUNCS ============================== */
