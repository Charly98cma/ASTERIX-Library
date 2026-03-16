/**
 * @file I021_040.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-16
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#include <Categories/I021/I021_040.h>

/* =============================== DE/ENCODE =============================== */

void encode_I021_040(BitStream *bs, const I021_040 *item)
{
    bs_serialize_u8(bs, item->ATP, 3U);
    bs_serialize_u8(bs, item->ARC, 2U);
    bs_serialize_u8(bs, item->RC,  1U);
    bs_serialize_u8(bs, item->RAB, 1U);
    bs_serialize_u8(bs, item->FX,  1U);

    if (item->FX != ePresenceFlag_PRESENT) return;

    /* First extension */
    bs_serialize_u8(bs, item->ext1.DCR, 1U);
    bs_serialize_u8(bs, item->ext1.GBS, 1U);
    bs_serialize_u8(bs, item->ext1.SIM, 1U);
    bs_serialize_u8(bs, item->ext1.TST, 1U);
    bs_serialize_u8(bs, item->ext1.SAA, 1U);
    bs_serialize_u8(bs, item->ext1.CL,  1U);
    bs_serialize_u8(bs, item->ext1.FX,  1U);

    if (item->ext1.FX != ePresenceFlag_PRESENT) return;

    /* Second extension */
    bs_inc_pos(bs, 0U, 1U); /* Spare 1 bit */
    bs_serialize_u8(bs, item->ext2.LLC,  1U);
    bs_serialize_u8(bs, item->ext2.IPC,  1U);
    bs_serialize_u8(bs, item->ext2.NOGO, 1U);
    bs_serialize_u8(bs, item->ext2.CPR,  1U);
    bs_serialize_u8(bs, item->ext2.LDPJ, 1U);
    bs_serialize_u8(bs, item->ext2.RCF,  1U);
    bs_serialize_u8(bs, item->ext2.FX,   1U);

    if (item->ext2.FX != ePresenceFlag_PRESENT) return;

    /* Third extension */
    bs_serialize_u8(bs, item->ext3.TBC_EP,  1U);
    /* Skip TBC value if not populated */
    if (item->ext3.TBC_EP == ePresenceFlag_PRESENT)
        bs_serialize_u8(bs, item->ext3.TBC_VAL, 6U);
    else
        bs_inc_pos(bs, 0, 6U);
    bs_serialize_u8(bs, item->ext3.FX, 1U);

    if (item->ext3.FX != ePresenceFlag_PRESENT) return;

    /* Fourth extension */
    bs_serialize_u8(bs, item->ext4.MBC_EP, 1U);
    /* Skip MBC value if not populated */
    if (item->ext4.MBC_EP == ePresenceFlag_PRESENT)
        bs_serialize_u8(bs, item->ext4.MBC_VAL, 6U);
    else
        bs_inc_pos(bs, 0, 6U);
    bs_serialize_u8(bs, item->ext4.FX, 1U);
}

void decode_I021_040(BitStream *bs, I021_040 *item)
{
    item->ATP = bs_deserialize_u8(bs, 3U);
    item->ARC = bs_deserialize_u8(bs, 2U);
    item->RC  = bs_deserialize_u8(bs, 1U);
    item->RAB = bs_deserialize_u8(bs, 1U);
    item->FX  = bs_deserialize_u8(bs, 1U);

    if (item->FX != ePresenceFlag_PRESENT) return;

    /* First extension */
    item->ext1.DCR = bs_deserialize_u8(bs, 1U);
    item->ext1.GBS = bs_deserialize_u8(bs, 1U);
    item->ext1.SIM = bs_deserialize_u8(bs, 1U);
    item->ext1.TST = bs_deserialize_u8(bs, 1U);
    item->ext1.SAA = bs_deserialize_u8(bs, 1U);
    item->ext1.CL  = bs_deserialize_u8(bs, 1U);
    item->ext1.FX  = bs_deserialize_u8(bs, 1U);

    if (item->ext1.FX != ePresenceFlag_PRESENT) return;

    /* Second extension */
    bs_inc_pos(bs, 0U, 1U); /* Spare 1 bit */
    item->ext2.LLC  = bs_deserialize_u8(bs, 1U);
    item->ext2.IPC  = bs_deserialize_u8(bs, 1U);
    item->ext2.NOGO = bs_deserialize_u8(bs, 1U);
    item->ext2.CPR  = bs_deserialize_u8(bs, 1U);
    item->ext2.LDPJ = bs_deserialize_u8(bs, 1U);
    item->ext2.RCF  = bs_deserialize_u8(bs, 1U);
    item->ext2.FX   = bs_deserialize_u8(bs, 1U);

    if (item->ext2.FX != ePresenceFlag_PRESENT) return;

    /* Third extension */
    item->ext3.TBC_EP = bs_deserialize_u8(bs, 1U);
    /* Skip TBC value if not populated */
    if (item->ext3.TBC_EP == ePresenceFlag_PRESENT)
        item->ext3.TBC_VAL = bs_deserialize_u8(bs, 6U);
    else
        bs_inc_pos(bs, 0, 6U);
    item->ext3.FX = bs_deserialize_u8(bs, 1U);

    if (item->ext3.FX != ePresenceFlag_PRESENT)
        return;

    /* Fourth extension */
    item->ext4.MBC_EP = bs_deserialize_u8(bs, 1U);
    /* Skip MBC value if not populated */
    if (item->ext4.MBC_EP == ePresenceFlag_PRESENT)
        item->ext4.MBC_VAL = bs_deserialize_u8(bs, 6U);
    else
        bs_inc_pos(bs, 0, 6U);
    item->ext4.FX = bs_deserialize_u8(bs, 1U);
}

/* ============================== EXTRA FUNCS ============================== */

void print_I021_040(const I021_040 *item)
{
    printf("I021/040 - Target Report Descriptor\n");
    printf("- ATP = %d\n", item->ATP);
    printf("- ARC = %d\n", item->ARC);
    printf("- RC  = %d\n", item->RC);
    printf("- RAB = %d\n", item->RAB);
    printf("- FX  = %d\n", item->FX);

    if (item->FX != ePresenceFlag_PRESENT) return;

    printf("- EXT1_DCR = %d\n", item->ext1.DCR);
    printf("- EXT1_GBS = %d\n", item->ext1.GBS);
    printf("- EXT1_SIM = %d\n", item->ext1.SIM);
    printf("- EXT1_TST = %d\n", item->ext1.TST);
    printf("- EXT1_SAA = %d\n", item->ext1.SAA);
    printf("- EXT1_CL  = %d\n", item->ext1.CL);
    printf("- EXT1_FX  = %d\n", item->ext1.FX);

    if (item->ext1.FX != ePresenceFlag_PRESENT) return;

    printf("- EXT2_LLC  = %d\n", item->ext2.LLC);
    printf("- EXT2_IPC  = %d\n", item->ext2.IPC);
    printf("- EXT2_NOGO = %d\n", item->ext2.NOGO);
    printf("- EXT2_CPR  = %d\n", item->ext2.CPR);
    printf("- EXT2_LDPJ = %d\n", item->ext2.LDPJ);
    printf("- EXT2_RCF  = %d\n", item->ext2.RCF);
    printf("- EXT2_FX   = %d\n", item->ext2.FX);

    if (item->ext2.FX != ePresenceFlag_PRESENT) return;

    printf("- EXT3_TBC_EP  = %d\n", item->ext3.TBC_EP);
    if (item->ext3.TBC_VAL == ePresenceFlag_PRESENT)
        printf("- EXT3_TBC_VAL = %d\n", item->ext3.TBC_VAL);
    printf("- EXT3_FX      = %d\n", item->ext3.FX);

    if(item->ext3.FX != ePresenceFlag_PRESENT) return;

    printf("- EXT4_MBC_EP  = %d\n", item->ext4.MBC_EP);
    if (item->ext4.MBC_VAL == ePresenceFlag_PRESENT)
        printf("- EXT4_MBC_VAL = %d\n", item->ext4.MBC_VAL);
    printf("- EXT4_FX      = %d\n", item->ext4.FX);

}