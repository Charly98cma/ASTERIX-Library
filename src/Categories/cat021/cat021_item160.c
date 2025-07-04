/**
 * @file cat021_item160.c
 * @brief Implementation of the Category 21 Item 160 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/cat021/cat021_item160.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item160_RE(const cat021_item160 * item)
{
    return GET_BITS(item->raw[0], 8, MASK_01_BITS);
}

double get_cat021_item160_GRDSPD(const cat021_item160 * item)
{
    uint16_t gs_raw = (uint16_t) (
        (GET_BITS(item->raw[0], 1, MASK_07_BITS) << 8) |
        (GET_BITS(item->raw[1], 1, MASK_08_BITS)     )
    );

    return (double) (gs_raw * CAT021_ITEM160_LSB_GRDSPD);
}

double get_cat021_item160_TRKANG(const cat021_item160 * item)
{
    uint16_t ta_raw = (uint16_t) (
        (GET_BITS(item->raw[2], 1, MASK_08_BITS) << 8) |
        (GET_BITS(item->raw[3], 1, MASK_08_BITS)     )
    );

    return (double) (ta_raw * CAT021_ITEM160_LSB_TRKANG);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item160_RE(cat021_item160 * item, const uint8_t re)
{
    SET_BITS(&(item->raw[0]), re, MASK_01_BITS, 8);
}

void set_cat021_item160_GRDSPD(cat021_item160 * item, const double ground_speed)
{
    uint16_t gs_raw = 0;

    // TODO: Check ground_speed value in range
    if (ground_speed > 0)
        gs_raw = (ground_speed / CAT021_ITEM160_LSB_GRDSPD + 0.5);

    SET_BITS(&(item->raw[0]), (gs_raw >> 8), MASK_07_BITS, 1);
    SET_BITS(&(item->raw[1]), (gs_raw     ), MASK_08_BITS, 1);
}

void set_cat021_item160_TRKANG(cat021_item160 * item, const double track_angle)
{
    uint16_t ta_raw = 0;

    // TODO: Check track_angle value in range
    if (track_angle > 0)
        ta_raw = (track_angle / CAT021_ITEM160_LSB_TRKANG + 0.5);

    SET_BITS(&(item->raw[2]), (ta_raw >> 8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[3]), (ta_raw     ), MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item160(const cat021_item160 * item)
{
    printf("Category 021 Item 160 - Airborne Ground Vector\n");
    printf("  RE = %d\n", get_cat021_item160_RE(item));
}