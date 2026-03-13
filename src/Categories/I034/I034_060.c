/**
 * @file I034_060.c
 * @brief 
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/I034/I034_060.h>

/* =============================== DE/ENCODE =============================== */

void encode_I034_060(BitStream *bs, const I034_060 *item)
{
    /* First octet */
    bs_serialize_u32(bs, item->COM, 1U);
    bs_inc_pos(bs, 0U, 2U); /* Spare 2 bits */
    bs_serialize_u32(bs, item->PSR, 1U);
    bs_serialize_u32(bs, item->SSR, 1U);
    bs_serialize_u32(bs, item->MDS, 1U);
    bs_inc_pos(bs, 0U, 1U); /* Spare 1 bit */
    bs_serialize_u32(bs, item->FX, 1U);

    /* Subfield #1: Common Part */
    if(item->COM == ePresenceFlag_PRESENT)
    {
        bs_inc_pos(bs, 0U, 1U); /* Spare 1 bit */
        bs_serialize_u32(bs, item->ext1.REDRDP, 3U);
        bs_serialize_u32(bs, item->ext1.REDXMT, 3U);
        bs_inc_pos(bs, 0U, 1U); /* Spare 1 bit */
    }

    /* Subfield #4: Specific Status for PSR Sensor */
    if(item->PSR == ePresenceFlag_PRESENT)
    {
        bs_serialize_u32(bs, item->ext4.POL, 1U);
        bs_serialize_u32(bs, item->ext4.REDRAD, 3U);
        bs_serialize_u32(bs, item->ext4.STC, 2U);
        bs_inc_pos(bs, 0U, 2U); /* Spare 2 bit */
    }

    /* Subfield #5: Specific Status for SSR Sensor */
    if(item->SSR == ePresenceFlag_PRESENT)
    {
        bs_serialize_u32(bs, item->ext5.REDRAD, 3U);
        bs_inc_pos(bs, 0U, 5); /* Spare 5 bit */
    }

    /* Subfield #6: Specific Status for Mode S Sensor */
    if(item->MDS == ePresenceFlag_PRESENT)
    {
        bs_serialize_u32(bs, item->ext6.REDRAD, 3U);
        bs_serialize_u32(bs, item->ext6.CLU, 1U);
        bs_inc_pos(bs, 0U, 4); /* Spare 4 bit */
    }
}

void decode_I034_060(BitStream *bs, I034_060 *item)
{
    /* First octet */
    item->COM = bs_deserialize_u32(bs, 1U);
    bs_inc_pos(bs, 0U, 2U); /* Spare 2 bits */
    item->PSR = bs_deserialize_u32(bs, 1U);
    item->SSR = bs_deserialize_u32(bs, 1U);
    item->MDS = bs_deserialize_u32(bs, 1U);
    bs_inc_pos(bs, 0U, 1U); /* Spare 1 bit */
    item->FX = bs_deserialize_u32(bs, 1U);

    /* Subfield #1: Common Part */
    if(item->COM == ePresenceFlag_PRESENT)
    {
        bs_inc_pos(bs, 0U, 1U); /* Spare 1 bit */
        item->ext1.REDRDP = bs_deserialize_u32(bs, 3U);
        item->ext1.REDXMT = bs_deserialize_u32(bs, 3U);
        bs_inc_pos(bs, 0U, 1U); /* Spare 1 bit */
    }

    /* Subfield #4: Specific Status for PSR Sensor */
    if(item->PSR == ePresenceFlag_PRESENT)
    {
        item->ext4.POL = bs_deserialize_u32(bs, 1U);
        item->ext4.REDRAD = bs_deserialize_u32(bs, 3U);
        item->ext4.STC = bs_deserialize_u32(bs, 2U);
        bs_inc_pos(bs, 0U, 2U); /* Spare 2 bit */
    }

    /* Subfield #5: Specific Status for SSR Sensor */
    if(item->SSR == ePresenceFlag_PRESENT)
    {
        item->ext5.REDRAD = bs_deserialize_u32(bs, 3U);
        bs_inc_pos(bs, 0U, 5); /* Spare 5 bit */
    }

    /* Subfield #6: Specific Status for Mode S Sensor */
    if(item->MDS == ePresenceFlag_PRESENT)
    {
        item->ext6.REDRAD = bs_deserialize_u32(bs, 3U);
        item->ext6.CLU = bs_deserialize_u32(bs, 1U);
        bs_inc_pos(bs, 0U, 4); /* Spare 4 bit */
    }
}

/* ============================== EXTRA FUNCS ============================== */

void print_I034_060(const I034_060 *item)
{
    printf("I034/060 - System Configuration and Status:\n");
    if (!item)
    {
        printf("I034/060: <null>\n");
        return;
    }

    printf("- COM: %u\n", item->COM);
    if (item->COM == ePresenceFlag_PRESENT)
    {
        printf("-- REDRDP: %u\n", item->ext1.REDRDP);
        printf("-- REDXMT: %u\n", item->ext1.REDXMT);
    }

    printf("- PSR: %u\n", item->PSR);
    if (item->PSR == ePresenceFlag_PRESENT)
    {
        printf("-- POL: %u\n", item->ext4.POL);
        printf("-- REDRAD: %u\n", item->ext4.REDRAD);
        printf("-- STC: %u\n", item->ext4.STC);
    }

    printf("- SSR: %u\n", item->SSR);
    if (item->SSR == ePresenceFlag_PRESENT)
    {
        printf("-- REDRAD: %u\n", item->ext5.REDRAD);
    }

    printf("- MDS: %u\n", item->MDS);
    if (item->MDS == ePresenceFlag_PRESENT)
    {
        printf("-- REDRAD: %u\n", item->ext6.REDRAD);
        printf("-- CLU: %u\n", item->ext6.CLU);
    }
}