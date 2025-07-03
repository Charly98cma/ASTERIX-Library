/**
 * @file cat021_item250.c
 * @brief Implementation of the Category 21 Item 250 functions
 */

#include <stdio.h>
#include "Categories/cat021/cat021_item250.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

#define BDS_BYTE(index, offset) (1 + ((index) * CAT021_ITEM250_BDSREG_N_OCTETS) + (offset))

uint8_t get_cat021_item250_REP(const cat021_item250 * item)
{
    return GET_BITS(item->raw[0], 1, MASK_08_BITS);
}

uint64_t get_cat021_item250_BDSDATA(const cat021_item250 * item,
                                    const uint8_t bds_index)
{
    uint64_t bds_register = (
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 0)], 1, MASK_08_BITS)) << 48) |
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 1)], 1, MASK_08_BITS)) << 40) |
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 2)], 1, MASK_08_BITS)) << 32) |
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 3)], 1, MASK_08_BITS)) << 24) |
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 4)], 1, MASK_08_BITS)) << 16) |
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 5)], 1, MASK_08_BITS)) <<  8) |
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 6)], 1, MASK_08_BITS))      )
    );
    return bds_register;
}

uint8_t get_cat021_item250_BDS1(const cat021_item250 * item,
                                const uint8_t bds_index)
{
    return GET_BITS((item->raw[BDS_BYTE(bds_index, 7)]), 5, MASK_04_BITS);
}

uint8_t get_cat021_item250_BDS2(const cat021_item250 * item,
                                const uint8_t bds_index)
{
    return GET_BITS((item->raw[BDS_BYTE(bds_index, 7)]), 1, MASK_04_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item250_REP(cat021_item250 * item, uint8_t rep)
{
    SET_BITS(&(item->raw[0]), rep, MASK_08_BITS, 1);
}

void set_cat021_item250_BDSDATA(cat021_item250 * item,
                                const uint8_t bds_index,
                                const uint64_t bds_data)
{
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 0)]), (bds_data >> 48), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 1)]), (bds_data >> 40), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 2)]), (bds_data >> 32), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 3)]), (bds_data >> 24), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 4)]), (bds_data >> 16), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 5)]), (bds_data >>  8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 6)]), (bds_data      ), MASK_08_BITS, 1);
}

void set_cat021_item250_BDS1(cat021_item250 * item,
                             const uint8_t bds_index,
                             const uint8_t bds1)
{
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 7)]), bds1, MASK_04_BITS, 5);
}

void set_cat021_item250_BDS2(cat021_item250 * item,
                             const uint8_t bds_index,
                             const uint8_t bds2)
{
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 7)]), bds2, MASK_04_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item250(const cat021_item250 * item)
{
    uint8_t i, rep = 0;
    uint64_t bds_reg = 0;

    rep = get_cat021_item250_REP(item);

    printf("Category 021 Item 250 - BDS Register Data\n");
    printf("  REP = %d\n", rep);

    for (i = 0; i < rep; i++)
    {
        bds_reg = get_cat021_item250_BDSDATA(item, i);
        printf(" BDS Reg. Data (%d) = 0x%03X%04X\n", i,
                                                    (uint32_t)(bds_reg >> 32),
                                                    (uint32_t)(bds_reg      ));
        printf(" BDS Reg. Addr. 1 (%d) = 0x%X\n", i, get_cat021_item250_BDS1(item, i));
        printf(" BDS Reg. Addr. 1 (%d) = 0x%X\n", i, get_cat021_item250_BDS2(item, i));
    }
}