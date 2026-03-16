/**
 * @file I021_073.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2026-03-16
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>

#include <Categories/I021/I021_073.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_073(BitStream *bs, const I021_073 *item)
{
    bs_serialize_ufloat(bs, item->TMRP, I021_073_LSB_TMRP, 24U);
}

void decode_I021_073(BitStream *bs, I021_073 *item)
{
    item->TMRP = bs_deserialize_ufloat(bs, I021_073_LSB_TMRP, 24U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_073(const I021_073 *item)
{
    printf("I021/073 - Time of Message Reception of Position\n");
    if (!item)
    {
        printf("I021/073: <null>\n");
        return;
    }
    printf("- TMRP (seconds) = %f\n", item->TMRP);
}
