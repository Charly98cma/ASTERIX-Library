/**
 * @file I021_040.c
 * @brief Implementation of the Category 21 Item 040 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_040.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_040_ATP(const I021_040 *item) {
    return GET_BITS(item->raw, 6, MASK_03_BITS); // Bits 8-6
}

uint8_t get_I021_040_ARC(const I021_040 *item) {
    return GET_BITS(item->raw, 4, MASK_02_BITS); // Bits 5-4
}

uint8_t get_I021_040_RC(const I021_040 *item) {
    return GET_BITS(item->raw, 3, MASK_01_BITS); // Bit 3
}

uint8_t get_I021_040_RAB(const I021_040 *item) {
    return GET_BITS(item->raw, 2, MASK_01_BITS); // Bit 2
}

uint8_t get_I021_040_FX(const I021_040 *item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS); // Bit 1
}

uint8_t get_I021_040_EXT1_DCR(const I021_040_EXT1 *item) {
    return GET_BITS(item->raw, 8, MASK_01_BITS); // Bit 8
}

uint8_t get_I021_040_EXT1_GBS(const I021_040_EXT1 *item) {
    return GET_BITS(item->raw, 7, MASK_01_BITS); // Bit 7
}

uint8_t get_I021_040_EXT1_SIM(const I021_040_EXT1 *item) {
    return GET_BITS(item->raw, 6, MASK_01_BITS); // Bit 6
}

uint8_t get_I021_040_EXT1_TST(const I021_040_EXT1 *item) {
    return GET_BITS(item->raw, 5, MASK_01_BITS); // Bit 5
}

uint8_t get_I021_040_EXT1_SAA(const I021_040_EXT1 *item) {
    return GET_BITS(item->raw, 4, MASK_01_BITS); // Bit 4
}

uint8_t get_I021_040_EXT1_CL(const I021_040_EXT1 *item) {
    return GET_BITS(item->raw, 2, MASK_02_BITS); // Bit 2
}

uint8_t get_I021_040_EXT1_FX(const I021_040_EXT1 *item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS); // Bit 1
}

uint8_t get_I021_040_EXT2_LLC(const I021_040_EXT2 *item) {
    return GET_BITS(item->raw, 7, MASK_01_BITS); // Bit 7
}

uint8_t get_I021_040_EXT2_IPC(const I021_040_EXT2 *item) {
    return GET_BITS(item->raw, 6, MASK_01_BITS); // Bit 6
}

uint8_t get_I021_040_EXT2_NOGO(const I021_040_EXT2 *item) {
    return GET_BITS(item->raw, 5, MASK_01_BITS); // Bit 5
}

uint8_t get_I021_040_EXT2_CPR(const I021_040_EXT2 *item) {
    return GET_BITS(item->raw, 4, MASK_01_BITS); // Bit 4
}

uint8_t get_I021_040_EXT2_LDPJ(const I021_040_EXT2 *item) {
    return GET_BITS(item->raw, 3, MASK_01_BITS); // Bit 3
}

uint8_t get_I021_040_EXT2_RCF(const I021_040_EXT2 *item) {
    return GET_BITS(item->raw, 2, MASK_01_BITS); // Bit 2
}

uint8_t get_I021_040_EXT2_FX(const I021_040_EXT2 *item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS); // Bit 1
}

uint8_t get_I021_040_EXT3_TBC(const I021_040_EXT3 *item) {
    return GET_BITS(item->raw, 2, MASK_07_BITS); // Bits 8-2
}

uint8_t get_I021_040_EXT3_TBC_EP(const I021_040_EXT3 *item) {
    return GET_BITS(item->raw, 8, MASK_01_BITS); // Bit 8
}

uint8_t get_I021_040_EXT3_TBC_VAL(const I021_040_EXT3 *item) {
    return GET_BITS(item->raw, 2, MASK_06_BITS); // Bit 7-2
}

uint8_t get_I021_040_EXT3_FX(const I021_040_EXT3 *item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS); // Bit 1
}

uint8_t get_I021_040_EXT4_MBC(const I021_040_EXT4 *item) {
    return GET_BITS(item->raw, 2, MASK_07_BITS); // Bits 8-2
}

uint8_t get_I021_040_EXT4_MBC_EP(const I021_040_EXT4 *item) {
    return GET_BITS(item->raw, 8, MASK_01_BITS); // Bit 8
}

uint8_t get_I021_040_EXT4_MBC_VAL(const I021_040_EXT4 *item) {
    return GET_BITS(item->raw, 2, MASK_06_BITS); // Bit 7-2
}

uint8_t get_I021_040_EXT4_FX(const I021_040_EXT4 *item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS); // Bit 1
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_040_ATP(I021_040 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_03_BITS, 6); // Bits 8-6
}

void set_I021_040_ARC(I021_040 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_02_BITS, 4); // Bits 5-4
}

void set_I021_040_RC(I021_040 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 3);
}

void set_I021_040_RAB(I021_040 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 2);
}

void set_I021_040_FX(I021_040 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}

void set_I021_040_EXT1_DCR(I021_040_EXT1 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 8);
}

void set_I021_040_EXT1_GBS(I021_040_EXT1 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 7);
}

void set_I021_040_EXT1_SIM(I021_040_EXT1 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 6);
}

void set_I021_040_EXT1_TST(I021_040_EXT1 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 5);
}

void set_I021_040_EXT1_SAA(I021_040_EXT1 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 4);
}

void set_I021_040_EXT1_CL(I021_040_EXT1 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_02_BITS, 2); // Bits 3-2
}

void set_I021_040_EXT1_FX(I021_040_EXT1 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}

void set_I021_040_EXT2_LLC(I021_040_EXT2 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 7);
}

void set_I021_040_EXT2_IPC(I021_040_EXT2 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 6); // Bit 6
}

void set_I021_040_EXT2_NOGO(I021_040_EXT2 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 5); // Bit 5
}

void set_I021_040_EXT2_CPR(I021_040_EXT2 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 4); // Bit 4
}

void set_I021_040_EXT2_LDPJ(I021_040_EXT2 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 3); // Bit 3
}

void set_I021_040_EXT2_RCF(I021_040_EXT2 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 2); // Bit 2
}

void set_I021_040_EXT2_FX(I021_040_EXT2 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1); // Bit 1
}

void set_I021_040_EXT3_TBC(I021_040_EXT3 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_07_BITS, 2); // Bit 8-2
}

void set_I021_040_EXT3_TBC_EP(I021_040_EXT3 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 8); // Bit 8
}

void set_I021_040_EXT3_TBC_VAL(I021_040_EXT3 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_06_BITS, 2); // Bits 7-2
}

void set_I021_040_EXT3_FX(I021_040_EXT3 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1); // Bit 1
}

void set_I021_040_EXT4_MBC(I021_040_EXT4 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_07_BITS, 2); // Bit 8-2
}

void set_I021_040_EXT4_MBC_EP(I021_040_EXT4 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 8); // Bit 8
}

void set_I021_040_EXT4_MBC_VAL(I021_040_EXT4 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_06_BITS, 2); // Bits 7-2
}

void set_I021_040_EXT4_FX(I021_040_EXT4 *item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1); // Bit 1
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

uint8_t count_I021_040_extensions(const I021_040 *item) {
    uint8_t counter = 0;
    
    if (get_I021_040_FX(item)) {
    
        counter++;
        if (get_I021_040_EXT1_FX(&(item->ext1))) {
        
            counter++;
            if (get_I021_040_EXT2_FX(&(item->ext2))) {
            
                counter++;
                if (get_I021_040_EXT3_FX(&(item->ext3))) {
                
                    counter++;
                }
            }
        }
    }

    return counter;
}

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