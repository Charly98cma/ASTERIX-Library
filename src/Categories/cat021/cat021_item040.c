/**
 * @file cat021_item040.c
 * @brief Implementation of the Category 21 Item 040 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/cat021/cat021_item040.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item040_ATP(const cat021_item040 *item)
{
    return GET_BITS(item->raw, 6, MASK_03_BITS); // Bits 8-6
}

uint8_t get_cat021_item040_ARC(const cat021_item040 *item)
{
    return GET_BITS(item->raw, 4, MASK_02_BITS); // Bits 5-4
}

uint8_t get_cat021_item040_RC(const cat021_item040 *item)
{
    return GET_BITS(item->raw, 3, MASK_01_BITS); // Bit 3
}

uint8_t get_cat021_item040_RAB(const cat021_item040 *item)
{
    return GET_BITS(item->raw, 2, MASK_01_BITS); // Bit 2
}

uint8_t get_cat021_item040_FX(const cat021_item040 *item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS); // Bit 1
}

uint8_t get_cat021_item040_ext1_DCR(const cat021_item040_ext1 *item)
{
    return GET_BITS(item->raw, 8, MASK_01_BITS); // Bit 8
}

uint8_t get_cat021_item040_ext1_GBS(const cat021_item040_ext1 *item)
{
    return GET_BITS(item->raw, 7, MASK_01_BITS); // Bit 7
}

uint8_t get_cat021_item040_ext1_SIM(const cat021_item040_ext1 *item)
{
    return GET_BITS(item->raw, 6, MASK_01_BITS); // Bit 6
}

uint8_t get_cat021_item040_ext1_TST(const cat021_item040_ext1 *item)
{
    return GET_BITS(item->raw, 5, MASK_01_BITS); // Bit 5
}

uint8_t get_cat021_item040_ext1_SAA(const cat021_item040_ext1 *item)
{
    return GET_BITS(item->raw, 4, MASK_01_BITS); // Bit 4
}

uint8_t get_cat021_item040_ext1_CL(const cat021_item040_ext1 *item)
{
    return GET_BITS(item->raw, 2, MASK_02_BITS); // Bit 2
}

uint8_t get_cat021_item040_ext1_FX(const cat021_item040_ext1 *item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS); // Bit 1
}

uint8_t get_cat021_item040_ext2_LLC(const cat021_item040_ext2 *item)
{
    return GET_BITS(item->raw, 7, MASK_01_BITS); // Bit 7
}

uint8_t get_cat021_item040_ext2_IPC(const cat021_item040_ext2 *item)
{
    return GET_BITS(item->raw, 6, MASK_01_BITS); // Bit 6
}

uint8_t get_cat021_item040_ext2_NOGO(const cat021_item040_ext2 *item)
{
    return GET_BITS(item->raw, 5, MASK_01_BITS); // Bit 5
}

uint8_t get_cat021_item040_ext2_CPR(const cat021_item040_ext2 *item)
{
    return GET_BITS(item->raw, 4, MASK_01_BITS); // Bit 4
}

uint8_t get_cat021_item040_ext2_LDPJ(const cat021_item040_ext2 *item)
{
    return GET_BITS(item->raw, 3, MASK_01_BITS); // Bit 3
}

uint8_t get_cat021_item040_ext2_RCF(const cat021_item040_ext2 *item)
{
    return GET_BITS(item->raw, 2, MASK_01_BITS); // Bit 2
}

uint8_t get_cat021_item040_ext2_FX(const cat021_item040_ext2 *item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS); // Bit 1
}

uint8_t get_cat021_item040_ext3_TBC(const cat021_item040_ext3 *item)
{
    return GET_BITS(item->raw, 2, MASK_07_BITS); // Bits 8-2
}

uint8_t get_cat021_item040_ext3_TBC_EP(const cat021_item040_ext3 *item)
{
    return GET_BITS(item->raw, 8, MASK_01_BITS); // Bit 8
}

uint8_t get_cat021_item040_ext3_TBC_VAL(const cat021_item040_ext3 *item)
{
    return GET_BITS(item->raw, 2, MASK_06_BITS); // Bit 7-2
}

uint8_t get_cat021_item040_ext3_FX(const cat021_item040_ext3 *item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS); // Bit 1
}

uint8_t get_cat021_item040_ext4_MBC(const cat021_item040_ext4 *item)
{
    return GET_BITS(item->raw, 2, MASK_07_BITS); // Bits 8-2
}

uint8_t get_cat021_item040_ext4_MBC_EP(const cat021_item040_ext4 *item)
{
    return GET_BITS(item->raw, 8, MASK_01_BITS); // Bit 8
}

uint8_t get_cat021_item040_ext4_MBC_VAL(const cat021_item040_ext4 *item)
{
    return GET_BITS(item->raw, 2, MASK_06_BITS); // Bit 7-2
}

uint8_t get_cat021_item040_ext4_FX(const cat021_item040_ext4 *item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS); // Bit 1
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item040_ATP(cat021_item040 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_03_BITS, 6); // Bits 8-6
}

void set_cat021_item040_ARC(cat021_item040 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_02_BITS, 4); // Bits 5-4
}

void set_cat021_item040_RC(cat021_item040 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 3);
}

void set_cat021_item040_RAB(cat021_item040 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 2);
}

void set_cat021_item040_FX(cat021_item040 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}

void set_cat021_item040_ext1_DCR(cat021_item040_ext1 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 8);
}

void set_cat021_item040_ext1_GBS(cat021_item040_ext1 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 7);
}

void set_cat021_item040_ext1_SIM(cat021_item040_ext1 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 6);
}

void set_cat021_item040_ext1_TST(cat021_item040_ext1 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 5);
}

void set_cat021_item040_ext1_SAA(cat021_item040_ext1 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 4);
}

void set_cat021_item040_ext1_CL(cat021_item040_ext1 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_02_BITS, 2); // Bits 3-2
}

void set_cat021_item040_ext1_FX(cat021_item040_ext1 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}

void set_cat021_item040_ext2_LLC(cat021_item040_ext2 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 7);
}

void set_cat021_item040_ext2_IPC(cat021_item040_ext2 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 6); // Bit 6
}

void set_cat021_item040_ext2_NOGO(cat021_item040_ext2 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 5); // Bit 5
}

void set_cat021_item040_ext2_CPR(cat021_item040_ext2 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 4); // Bit 4
}

void set_cat021_item040_ext2_LDPJ(cat021_item040_ext2 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 3); // Bit 3
}

void set_cat021_item040_ext2_RCF(cat021_item040_ext2 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 2); // Bit 2
}

void set_cat021_item040_ext2_FX(cat021_item040_ext2 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1); // Bit 1
}

void set_cat021_item040_ext3_TBC(cat021_item040_ext3 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_07_BITS, 2); // Bit 8-2
}

void set_cat021_item040_ext3_TBC_EP(cat021_item040_ext3 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 8); // Bit 8
}

void set_cat021_item040_ext3_TBC_VAL(cat021_item040_ext3 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_06_BITS, 2); // Bits 7-2
}

void set_cat021_item040_ext3_FX(cat021_item040_ext3 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1); // Bit 1
}

void set_cat021_item040_ext4_MBC(cat021_item040_ext4 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_07_BITS, 2); // Bit 8-2
}

void set_cat021_item040_ext4_MBC_EP(cat021_item040_ext4 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 8); // Bit 8
}

void set_cat021_item040_ext4_MBC_VAL(cat021_item040_ext4 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_06_BITS, 2); // Bits 7-2
}

void set_cat021_item040_ext4_FX(cat021_item040_ext4 *item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1); // Bit 1
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

uint8_t count_cat021_item040_extensions(const cat021_item040 *item)
{
    uint8_t counter = 0;
    
    if (get_cat021_item040_FX(item))
    {
        counter++;
        if (get_cat021_item040_ext1_FX(&(item->ext1)))
        {
            counter++;
            if (get_cat021_item040_ext2_FX(&(item->ext2)))
            {
                counter++;
                if (get_cat021_item040_ext3_FX(&(item->ext3)))
                {
                    counter++;
                }
            }
        }
    }

    return counter;
}

void print_cat021_item040(const cat021_item040 *item)
{
    printf("Category 021 Item 040 - Target Report Descriptor\n");
    printf("  ATP = %d\n", get_cat021_item040_ATP(item));
    printf("  ARC = %d\n", get_cat021_item040_ARC(item));
    printf("  RC = %d\n", get_cat021_item040_RC(item));
    printf("  RAB = %d\n", get_cat021_item040_RAB(item));
    printf("  FX = %d\n", get_cat021_item040_FX(item));

    if (!get_cat021_item040_FX(item)) return;

    printf("  ext1_DCR = %d", get_cat021_item040_ext1_DCR(&(item->ext1)));
    printf("  ext1_GBS = %d", get_cat021_item040_ext1_GBS(&(item->ext1)));
    printf("  ext1_SIM = %d", get_cat021_item040_ext1_SIM(&(item->ext1)));
    printf("  ext1_TST = %d", get_cat021_item040_ext1_TST(&(item->ext1)));
    printf("  ext1_SAA = %d", get_cat021_item040_ext1_SAA(&(item->ext1)));
    printf("  ext1_CL = %d", get_cat021_item040_ext1_CL(&(item->ext1)));
    printf("  ext1_FX = %d", get_cat021_item040_ext1_FX(&(item->ext1)));

    if (!get_cat021_item040_ext1_FX(&(item->ext1))) return;

    printf("  ext2_LLC = %d", get_cat021_item040_ext2_LLC(&(item->ext2)));
    printf("  ext2_IPC = %d", get_cat021_item040_ext2_IPC(&(item->ext2)));
    printf("  ext2_NOGO = %d", get_cat021_item040_ext2_NOGO(&(item->ext2)));
    printf("  ext2_CPR = %d", get_cat021_item040_ext2_CPR(&(item->ext2)));
    printf("  ext2_LDPJ = %d", get_cat021_item040_ext2_LDPJ(&(item->ext2)));
    printf("  ext2_RCF = %d", get_cat021_item040_ext2_RCF(&(item->ext2)));
    printf("  ext2_FX = %d", get_cat021_item040_ext2_FX(&(item->ext2)));

    if (!get_cat021_item040_ext2_FX(&(item->ext2))) return;

    printf("  ext3_TBC = %d\n", get_cat021_item040_ext3_TBC(&(item->ext3)));
    printf("  ext3_FX = %d\n", get_cat021_item040_ext3_FX(&(item->ext3)));

    if(!get_cat021_item040_ext3_FX(&(item->ext3))) return;

    printf("  ext4_MBC = %d\n", get_cat021_item040_ext4_MBC(&(item->ext4)));
    printf("  ext4_FX = %d\n\n", get_cat021_item040_ext4_FX(&(item->ext4)));
}