/**
 * @file I021_040.c
 * @brief Implementation of the Category 21 Item 040 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_040.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN FIELD =============================== */

uint8_t get_I021_040_ATP(const I021_040 *item) {
    return (item->raw >> 5) & MASK_03_BITS;
}

uint8_t get_I021_040_ARC(const I021_040 *item) {
    return (item->raw >> 3) & MASK_02_BITS;
}

uint8_t get_I021_040_RC(const I021_040 *item) {
    return (item->raw >> 2) & MASK_01_BITS;
}

uint8_t get_I021_040_RAB(const I021_040 *item) {
    return (item->raw >> 1) & MASK_01_BITS;
}

uint8_t get_I021_040_FX(const I021_040 *item) {
    return item->raw & MASK_01_BITS;
}

/* ============================== SUBFIELD #1 ============================== */

uint8_t get_I021_040_EXT1_DCR(const I021_040_EXT1 *item) {
    return (item->raw >> 7) & MASK_01_BITS;
}

uint8_t get_I021_040_EXT1_GBS(const I021_040_EXT1 *item) {
    return (item->raw >> 6) & MASK_01_BITS;
}

uint8_t get_I021_040_EXT1_SIM(const I021_040_EXT1 *item) {
    return (item->raw >> 5) & MASK_01_BITS;
}

uint8_t get_I021_040_EXT1_TST(const I021_040_EXT1 *item) {
    return (item->raw >> 4) & MASK_01_BITS;
}

uint8_t get_I021_040_EXT1_SAA(const I021_040_EXT1 *item) {
    return (item->raw >> 3) & MASK_01_BITS;
}

uint8_t get_I021_040_EXT1_CL(const I021_040_EXT1 *item) {
    return (item->raw >> 1) & MASK_02_BITS;
}

uint8_t get_I021_040_EXT1_FX(const I021_040_EXT1 *item) {
    return item->raw & MASK_01_BITS;
}

/* ============================== SUBFIELD #2 ============================== */

uint8_t get_I021_040_EXT2_LLC(const I021_040_EXT2 *item) {
    return (item->raw >> 6) & MASK_01_BITS;
}

uint8_t get_I021_040_EXT2_IPC(const I021_040_EXT2 *item) {
    return (item->raw >> 5) & MASK_01_BITS;
}

uint8_t get_I021_040_EXT2_NOGO(const I021_040_EXT2 *item) {
    return (item->raw >> 4) & MASK_01_BITS;
}

uint8_t get_I021_040_EXT2_CPR(const I021_040_EXT2 *item) {
    return (item->raw >> 3) & MASK_01_BITS;
}

uint8_t get_I021_040_EXT2_LDPJ(const I021_040_EXT2 *item) {
    return (item->raw >> 2) & MASK_01_BITS;
}

uint8_t get_I021_040_EXT2_RCF(const I021_040_EXT2 *item) {
    return (item->raw >> 1) & MASK_01_BITS;
}

uint8_t get_I021_040_EXT2_FX(const I021_040_EXT2 *item) {
    return item->raw & MASK_01_BITS;
}

/* ============================== SUBFIELD #3 ============================== */

uint8_t get_I021_040_EXT3_TBC(const I021_040_EXT3 *item) {
    return item->raw;
}

uint8_t get_I021_040_EXT3_TBC_EP(const I021_040_EXT3 *item) {
    return (item->raw >> 7) & MASK_01_BITS;
}

uint8_t get_I021_040_EXT3_TBC_VAL(const I021_040_EXT3 *item) {
    return (item->raw >> 1) & MASK_06_BITS;
}

uint8_t get_I021_040_EXT3_FX(const I021_040_EXT3 *item) {
    return item->raw & MASK_01_BITS;
}

/* ============================== SUBFIELD #4 ============================== */

uint8_t get_I021_040_EXT4_MBC(const I021_040_EXT4 *item) {
    return item->raw;
}

uint8_t get_I021_040_EXT4_MBC_EP(const I021_040_EXT4 *item) {
    return (item->raw >> 7) & MASK_01_BITS;
}

uint8_t get_I021_040_EXT4_MBC_VAL(const I021_040_EXT4 *item) {
    return (item->raw >> 1) & MASK_06_BITS;
}

uint8_t get_I021_040_EXT4_FX(const I021_040_EXT4 *item) {
    return item->raw & MASK_01_BITS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_040_ATP(I021_040 *item, uint8_t atp) {
    item->raw |= (atp & MASK_03_BITS) << 5;
}

void set_I021_040_ARC(I021_040 *item, uint8_t arc) {
    item->raw |= (arc & MASK_02_BITS) << 3;
}

void set_I021_040_RC(I021_040 *item, uint8_t rc) {
    item->raw |= (rc & MASK_01_BITS) << 2;
}

void set_I021_040_RAB(I021_040 *item, uint8_t rab) {
    item->raw |= (rab & MASK_01_BITS) << 1;
}

void set_I021_040_FX(I021_040 *item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

void set_I021_040_EXT1_DCR(I021_040_EXT1 *item, uint8_t dcr) {
    item->raw |= (dcr & MASK_01_BITS) << 7;
}

void set_I021_040_EXT1_GBS(I021_040_EXT1 *item, uint8_t gbs) {
    item->raw |= (gbs & MASK_01_BITS) << 6;
}

void set_I021_040_EXT1_SIM(I021_040_EXT1 *item, uint8_t sim) {
    item->raw |= (sim & MASK_01_BITS) << 5;
}

void set_I021_040_EXT1_TST(I021_040_EXT1 *item, uint8_t tst) {
    item->raw |= (tst & MASK_01_BITS) << 4;
}

void set_I021_040_EXT1_SAA(I021_040_EXT1 *item, uint8_t saa) {
    item->raw |= (saa & MASK_01_BITS) << 3;
}

void set_I021_040_EXT1_CL(I021_040_EXT1 *item, uint8_t cl) {
    item->raw |= (cl & MASK_02_BITS) << 1;
}

void set_I021_040_EXT1_FX(I021_040_EXT1 *item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

void set_I021_040_EXT2_LLC(I021_040_EXT2 *item, uint8_t llc) {
    item->raw |= (llc & MASK_01_BITS) << 6;
}

void set_I021_040_EXT2_IPC(I021_040_EXT2 *item, uint8_t ipc) {
    item->raw |= (ipc & MASK_01_BITS) << 5;
}

void set_I021_040_EXT2_NOGO(I021_040_EXT2 *item, uint8_t nogo) {
    item->raw |= (nogo & MASK_01_BITS) << 4;
}

void set_I021_040_EXT2_CPR(I021_040_EXT2 *item, uint8_t cpr) {
    item->raw |= (cpr & MASK_01_BITS) << 3;
}

void set_I021_040_EXT2_LDPJ(I021_040_EXT2 *item, uint8_t ldpj) {
    item->raw |= (ldpj & MASK_01_BITS) << 2;
}

void set_I021_040_EXT2_RCF(I021_040_EXT2 *item, uint8_t rcf) {
    item->raw |= (rcf & MASK_01_BITS) << 1;
}

void set_I021_040_EXT2_FX(I021_040_EXT2 *item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

void set_I021_040_EXT3_TBC(I021_040_EXT3 *item, uint8_t tbc) {
    item->raw = tbc;
}

void set_I021_040_EXT3_TBC_EP(I021_040_EXT3 *item, uint8_t tbc_ep) {
    item->raw |= (tbc_ep & MASK_01_BITS) << 7;
}

void set_I021_040_EXT3_TBC_VAL(I021_040_EXT3 *item, uint8_t tbc_val) {
    item->raw |= (tbc_val & MASK_06_BITS) << 1;
}

void set_I021_040_EXT3_FX(I021_040_EXT3 *item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

void set_I021_040_EXT4_MBC(I021_040_EXT4 *item, uint8_t mbc) {
    item->raw = mbc;
}

void set_I021_040_EXT4_MBC_EP(I021_040_EXT4 *item, uint8_t mbc_ep) {
    item->raw |= (mbc_ep & MASK_01_BITS) << 7;
}

void set_I021_040_EXT4_MBC_VAL(I021_040_EXT4 *item, uint8_t mbc_val) {
    item->raw |= (mbc_val & MASK_06_BITS) << 1;
}

void set_I021_040_EXT4_FX(I021_040_EXT4 *item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/
uint16_t encode_I021_040(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_040 * item = (I021_040 *) item_in;
    /* Copy basic info. always present on item */
    msg_out[out_index++] = item->raw;
    /* Copy first extension if present */
    if (get_I021_040_FX(item)) {
        msg_out[out_index++] = item->ext1.raw;
        /* Copy second extension if present */
        if (get_I021_040_EXT1_FX(&(item->ext1))) {
            msg_out[out_index++] = item->ext2.raw;
            /* Copy third extension if present */
            if (get_I021_040_EXT2_FX(&(item->ext2))) {
                msg_out[out_index++] = item->ext3.raw;
                /* Copy fourth extension if present */
                if (get_I021_040_EXT3_FX(&(item->ext3))) {
                    msg_out[out_index++] = item->ext4.raw;
                }
            }
        }
    }
    return out_index;
}

uint16_t decode_I021_040(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_040 * item = (I021_040 *) item_out;
    /* Copy basic info. always present on item */
    item->raw = msg_in[in_index++];
    /* Copy first extension if present */
    if (get_I021_040_FX(item)) {
        item->ext1.raw = msg_in[in_index++];
        /* Copy second extension if present */
        if (get_I021_040_EXT1_FX(&(item->ext1))) {
            item->ext2.raw = msg_in[in_index++];
            /* Copy third extension if present */
            if (get_I021_040_EXT2_FX(&(item->ext2))) {
                item->ext3.raw = msg_in[in_index++];
                /* Copy fourth extension if present */
                if (get_I021_040_EXT3_FX(&(item->ext3))) {
                    item->ext4.raw = msg_in[in_index++];
                }
            }
        }
    }
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_040(const I021_040 *item) {
    printf("Category 021 Item 040 - Target Report Descriptor\n");
    printf("  ATP = %d\n", get_I021_040_ATP(item));
    printf("  ARC = %d\n", get_I021_040_ARC(item));
    printf("  RC = %d\n", get_I021_040_RC(item));
    printf("  RAB = %d\n", get_I021_040_RAB(item));
    printf("  FX = %d\n", get_I021_040_FX(item));

    if (!get_I021_040_FX(item)) return;

    printf("  EXT1_DCR = %d", get_I021_040_EXT1_DCR(&(item->ext1)));
    printf("  EXT1_GBS = %d", get_I021_040_EXT1_GBS(&(item->ext1)));
    printf("  EXT1_SIM = %d", get_I021_040_EXT1_SIM(&(item->ext1)));
    printf("  EXT1_TST = %d", get_I021_040_EXT1_TST(&(item->ext1)));
    printf("  EXT1_SAA = %d", get_I021_040_EXT1_SAA(&(item->ext1)));
    printf("  EXT1_CL = %d", get_I021_040_EXT1_CL(&(item->ext1)));
    printf("  EXT1_FX = %d", get_I021_040_EXT1_FX(&(item->ext1)));

    if (!get_I021_040_EXT1_FX(&(item->ext1))) return;

    printf("  EXT2_LLC = %d", get_I021_040_EXT2_LLC(&(item->ext2)));
    printf("  EXT2_IPC = %d", get_I021_040_EXT2_IPC(&(item->ext2)));
    printf("  EXT2_NOGO = %d", get_I021_040_EXT2_NOGO(&(item->ext2)));
    printf("  EXT2_CPR = %d", get_I021_040_EXT2_CPR(&(item->ext2)));
    printf("  EXT2_LDPJ = %d", get_I021_040_EXT2_LDPJ(&(item->ext2)));
    printf("  EXT2_RCF = %d", get_I021_040_EXT2_RCF(&(item->ext2)));
    printf("  EXT2_FX = %d", get_I021_040_EXT2_FX(&(item->ext2)));

    if (!get_I021_040_EXT2_FX(&(item->ext2))) return;

    printf("  EXT3_TBC = %d\n", get_I021_040_EXT3_TBC(&(item->ext3)));
    printf("  EXT3_FX = %d\n", get_I021_040_EXT3_FX(&(item->ext3)));

    if(!get_I021_040_EXT3_FX(&(item->ext3))) return;

    printf("  EXT4_MBC = %d\n", get_I021_040_EXT4_MBC(&(item->ext4)));
    printf("  EXT4_FX = %d\n\n", get_I021_040_EXT4_FX(&(item->ext4)));
}