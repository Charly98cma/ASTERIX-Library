/**
 * @file cat021_item220.c
 * @brief Implementation of the Category 21 Item 220 functions
 */ 

#include <stdio.h>
#include "Categories/cat021/cat021_item220.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/ 

/* ============================== MAIN BYTE ============================== */

uint8_t get_cat021_item220_WS(const cat021_item220 * item)
{
    return GET_BITS((item)->raw, 8, MASK_01_BITS);
}    

uint8_t get_cat021_item220_WD(const cat021_item220 * item)
{
    return GET_BITS((item)->raw, 7, MASK_01_BITS);
}    

uint8_t get_cat021_item220_TEMP(const cat021_item220 * item)
{
    return GET_BITS((item)->raw, 6, MASK_01_BITS);
}    

uint8_t get_cat021_item220_TRB(const cat021_item220 * item)
{
    return GET_BITS((item)->raw, 5, MASK_01_BITS);
}    

uint8_t get_cat021_item220_FX(const cat021_item220 * item)
{
    return GET_BITS((item)->raw, 1, MASK_01_BITS);
}    

/* ============================== SUBFIELD #1 ============================== */

uint16_t get_cat021_item220_ext1_WINDSPD(const cat021_item220_ext1 * item)
{
    return GET_BITS((item)->WINDSPD, 1, MASK_16_BITS);
}    

/* ============================== SUBFIELD #2 ============================== */

uint16_t get_cat021_item220_ext2_WINDDIR(const cat021_item220_ext2 * item)
{
    return GET_BITS((item)->WINDDIR, 1, MASK_16_BITS);
}    

/* ============================== SUBFIELD #3 ============================== */

double get_cat021_item220_ext3_TEMP(const cat021_item220_ext3 * item)
{
    double temp = 
        GET_BITS((item)->TEMP, 1, MASK_16_BITS) * CAT021_ITEM220_LSB_EXT3_TEMP;
    return temp;
}

/* ============================== SUBFIELD #4 ============================== */

uint8_t get_cat021_item220_ext4_TURB(const cat021_item220_ext4 * item)
{
    return GET_BITS((item)->TURB, 1, MASK_08_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================== MAIN BYTE ============================== */

void set_cat021_item220_WS(cat021_item220 * item, uint8_t ws)
{
    SET_BITS(&((item)->raw), ws, 8, MASK_01_BITS);
}

void set_cat021_item220_WD(cat021_item220 * item, uint8_t wd)
{
    SET_BITS(&((item)->raw), wd, 7, MASK_01_BITS);
}

void set_cat021_item220_TEMP(cat021_item220 * item, uint8_t temp)
{
    SET_BITS(&((item)->raw), temp, 6, MASK_01_BITS);
}

void set_cat021_item220_TRB(cat021_item220 * item, uint8_t trb)
{
    SET_BITS(&((item)->raw), trb, 5, MASK_01_BITS);
}

void set_cat021_item220_FX(cat021_item220 * item, uint8_t fx)
{
    SET_BITS(&((item)->raw), fx, 1, MASK_01_BITS);
}

/* ============================== SUBFIELD #1 ============================== */

void set_cat021_item220_ext1_WINDSPD(cat021_item220_ext1 * item, uint16_t wind_spd)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->WINDSPD), wind_spd, MASK_16_BITS, 1);
}

/* ============================== SUBFIELD #2 ============================== */

void set_cat021_item220_ext2_WINDDIR(cat021_item220_ext2 * item, uint16_t wind_dir)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->WINDDIR), wind_dir, MASK_16_BITS, 1);
}

/* ============================== SUBFIELD #3 ============================== */

void set_cat021_item220_ext3_TEMP(cat021_item220_ext3 * item, double temp)
{
    int16_t temp_raw = 0;

    // TODO: Check value is in valid range
    if (temp > 0)
        temp_raw = (int16_t) ((temp / CAT021_ITEM220_LSB_EXT3_TEMP) + 0.5);

    SET_BITS(&((item)->TEMP), temp_raw, MASK_16_BITS, 1);
}

/* ============================== SUBFIELD #4 ============================== */

void set_cat021_item220_ext4_TURB(cat021_item220_ext4 * item, uint8_t turb)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->TURB), turb, MASK_16_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item220(const cat021_item220 * item)
{
    printf("Category 021 / Item 220 - Met Information\n");

    printf("  WS = %d\n", get_cat021_item220_WS(item));
    printf("  WD = %d\n", get_cat021_item220_WD(item));
    printf("  TEMP = %d\n", get_cat021_item220_TEMP(item));
    printf("  TRB = %d\n", get_cat021_item220_TRB(item));
    printf("  FX = %d\n", get_cat021_item220_FX(item));

    if (get_cat021_item220_WS(item))
    {
        printf("  ext1_WS = %d\n", get_cat021_item220_ext1_WINDSPD(&((item)->ext1)));
    }

    if (get_cat021_item220_WD(item))
    {
        printf("  ext2_WD = %d\n", get_cat021_item220_ext2_WINDDIR(&((item)->ext2)));
    }

    if (get_cat021_item220_TEMP(item))
    {
        printf("  ext3_TEMP = %f\n", get_cat021_item220_ext3_TEMP(&((item)->ext3)));
    }

    if (get_cat021_item220_TRB(item))
    {
        printf("  ext4_TRB = %d\n", get_cat021_item220_ext4_TURB(&((item)->ext4)));
    }
}

