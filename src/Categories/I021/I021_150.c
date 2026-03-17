/**
 * @file I021_150.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_150.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_150(BitStream *bs, const I021_150 *item)
{
    bs_serialize_u8(bs, item->IM, 1U);
    if (item->IM == eI021_150_IM_IAS)
        bs_serialize_ufloat(bs, item->AIRSPD, I021_150_LSB_IAS, 15U);
    else
        bs_serialize_ufloat(bs, item->AIRSPD, I021_150_LSB_MACH, 15U);
}

void decode_I021_150(BitStream *bs, I021_150 *item)
{
    item->IM = bs_deserialize_u8(bs, 1U);
    if (item->IM == eI021_150_IM_IAS)
        item->AIRSPD = bs_deserialize_ufloat(bs, I021_150_LSB_IAS, 15U);
    else
        item->AIRSPD = bs_deserialize_ufloat(bs, I021_150_LSB_MACH, 15U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_150(const I021_150 * item)
{
    printf("I021/150 - Air Speed\n");
    if (!item)
    {
        printf("I021/150 <null>\n");
        return;
    }
    printf("- IM = %u\n", item->IM);
    if (item->IM == eI021_150_IM_IAS)
        printf("- IAS = %f\n", item->AIRSPD);
    else
        printf("- MACH = %f\n", item->AIRSPD);
}