/**
 * @file I034_050.c
 * @brief 
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>

#include <Categories/I034/I034_050.h>

/* =============================== DE/ENCODE =============================== */


void encode_I034_050(BitStream *bs, const I034_050 *item)
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
        bs_serialize_u32(bs, item->ext1.NOGO, 1U);
        bs_serialize_u32(bs, item->ext1.RDPC, 1U);
        bs_serialize_u32(bs, item->ext1.RDPR, 1U);
        bs_serialize_u32(bs, item->ext1.OVLRDP, 1U);
        bs_serialize_u32(bs, item->ext1.OVLXMT, 1U);
        bs_serialize_u32(bs, item->ext1.MSC, 1U);
        bs_serialize_u32(bs, item->ext1.TSV, 1U);
        bs_inc_pos(bs, 0U, 1U); /* Spare 1 bit */
    }

    /* Subfield #4: Specific Status for PSR Sensor */
    if(item->PSR == ePresenceFlag_PRESENT)
    {
        bs_serialize_u32(bs, item->ext4.ANT, 1U);
        bs_serialize_u32(bs, item->ext4.CHAB, 2U);
        bs_serialize_u32(bs, item->ext4.OVL, 1U);
        bs_serialize_u32(bs, item->ext4.MSC, 1U);
        bs_inc_pos(bs, 0U, 3); /* Spare 1 bit */
    }

    /* Subfield #5: Specific Status for SSR Sensor */
    if(item->SSR == ePresenceFlag_PRESENT)
    {
        bs_serialize_u32(bs, item->ext5.ANT, 1U);
        bs_serialize_u32(bs, item->ext5.CHAB, 2U);
        bs_serialize_u32(bs, item->ext5.OVL, 1U);
        bs_serialize_u32(bs, item->ext5.MSC, 1U);
        bs_inc_pos(bs, 0U, 3); /* Spare 3 bits */
    }

    /* Subfield #6: Specific Status for Mode S Sensor */
    if(item->MDS == ePresenceFlag_PRESENT)
    {
        bs_serialize_u32(bs, item->ext6.ANT, 1U);
        bs_serialize_u32(bs, item->ext6.CHAB, 1U);
        bs_serialize_u32(bs, item->ext6.OVLSUR, 1U);
        bs_serialize_u32(bs, item->ext6.MSC, 1U);
        bs_serialize_u32(bs, item->ext6.SCF, 1U);
        bs_serialize_u32(bs, item->ext6.DLF, 1U);
        bs_serialize_u32(bs, item->ext6.OVLSCF, 1U);
        bs_serialize_u32(bs, item->ext6.OVLDLF, 1U);
        bs_inc_pos(bs, 0U, 7); /* Spare 7 bit */
    }
}

void decode_I034_050(BitStream *bs, I034_050 *item)
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
        item->ext1.NOGO = bs_deserialize_u32(bs, 1U);
        item->ext1.RDPC = bs_deserialize_u32(bs, 1U);
        item->ext1.RDPR = bs_deserialize_u32(bs, 1U);
        item->ext1.OVLRDP = bs_deserialize_u32(bs, 1U);
        item->ext1.OVLXMT = bs_deserialize_u32(bs, 1U);
        item->ext1.MSC = bs_deserialize_u32(bs, 1U);
        item->ext1.TSV = bs_deserialize_u32(bs, 1U);
        bs_inc_pos(bs, 0U, 1U); /* Spare 1 bit */
    }

    /* Subfield #4: Specific Status for PSR Sensor */
    if(item->PSR == ePresenceFlag_PRESENT)
    {
        item->ext4.ANT = bs_deserialize_u32(bs, 1U);
        item->ext4.CHAB = bs_deserialize_u32(bs, 2U);
        item->ext4.OVL = bs_deserialize_u32(bs, 1U);
        item->ext4.MSC = bs_deserialize_u32(bs, 1U);
        bs_inc_pos(bs, 0U, 3); /* Spare 1 bit */
    }

    /* Subfield #5: Specific Status for SSR Sensor */
    if(item->SSR == ePresenceFlag_PRESENT)
    {
        item->ext5.ANT = bs_deserialize_u32(bs, 1U);
        item->ext5.CHAB = bs_deserialize_u32(bs, 2U);
        item->ext5.OVL = bs_deserialize_u32(bs, 1U);
        item->ext5.MSC = bs_deserialize_u32(bs, 1U);
        bs_inc_pos(bs, 0U, 3); /* Spare 3 bits */
    }

    /* Subfield #6: Specific Status for Mode S Sensor */
    if(item->MDS == ePresenceFlag_PRESENT)
    {
        item->ext6.ANT = bs_deserialize_u32(bs, 1U);
        item->ext6.CHAB = bs_deserialize_u32(bs, 1U);
        item->ext6.OVLSUR = bs_deserialize_u32(bs, 1U);
        item->ext6.MSC = bs_deserialize_u32(bs, 1U);
        item->ext6.SCF = bs_deserialize_u32(bs, 1U);
        item->ext6.DLF = bs_deserialize_u32(bs, 1U);
        item->ext6.OVLSCF = bs_deserialize_u32(bs, 1U);
        item->ext6.OVLDLF = bs_deserialize_u32(bs, 1U);
        bs_inc_pos(bs, 0U, 7); /* Spare 7 bit */
    }
}

/* ============================== EXTRA FUNCS ============================== */

void print_I034_050(const I034_050 *item)
{
    printf("I034/050 - System Configuration and Status\n");
    if (!item)
    {
        printf("I034/050: <null>\n");
        return;
    }

    printf("- COM = %u\n", item->COM);
    if (item->COM == ePresenceFlag_PRESENT)
    {
        printf("-- NOGO = %u\n", item->ext1.NOGO);
        printf("-- RDPC = %u\n", item->ext1.RDPC);
        printf("-- RDPR = %u\n", item->ext1.RDPR);
        printf("-- OVLRDP = %u\n", item->ext1.OVLRDP);
        printf("-- OVLXMT = %u\n", item->ext1.OVLXMT);
        printf("-- MSC = %u\n", item->ext1.MSC);
        printf("-- TSV = %u\n", item->ext1.TSV);
    }

    printf("- PSR = %u\n", item->PSR);
    if (item->PSR == ePresenceFlag_PRESENT)
    {
        printf("-- ANT = %u\n", item->ext4.ANT);
        printf("-- CHAB = %u\n", item->ext4.CHAB);
        printf("-- OVL = %u\n", item->ext4.OVL);
        printf("-- MSC = %u\n", item->ext4.MSC);
    }

    printf("- SSR = %u\n", item->SSR);
    if (item->SSR == ePresenceFlag_PRESENT)
    {
        printf("-- ANT = %u\n", item->ext5.ANT);
        printf("-- CHAB = %u\n",item->ext5.CHAB);
        printf("-- OVL = %u\n", item->ext5.OVL);
        printf("-- MSC = %u\n", item->ext5.MSC);
    }

    printf("- MDS = %u\nn", item->MDS);
    if (item->MDS == ePresenceFlag_PRESENT)
    {
        printf("-- ANT = %u\n", item->ext6.ANT);
        printf("-- CHAB = %u\n", item->ext6.CHAB);
        printf("-- OVLSUR = %u\n", item->ext6.OVLSUR);
        printf("-- MSC = %u\n", item->ext6.MSC);
        printf("-- SCF = %u\n", item->ext6.SCF);
        printf("-- DLF = %u\n", item->ext6.DLF);
        printf("-- OVLSCF = %u\n", item->ext6.OVLSCF);
        printf("-- OVLDLF = %u\n", item->ext6.OVLDLF);
    }
}
