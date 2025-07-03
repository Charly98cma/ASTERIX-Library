/**
 * @file cat021_item110.c
 * @brief Implementation of the Category 21 Item 110 functions
 */

#include "Categories/cat021/cat021_item110.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

uint8_t get_cat021_item110_TIS(const cat021_item110 * item)
{
    return GET_BITS((item)->raw, 8, MASK_01_BITS);
}

uint8_t get_cat021_item110_TID(const cat021_item110 * item)
{
    return GET_BITS((item)->raw, 7, MASK_01_BITS);
}

uint8_t get_cat021_item110_FX(const cat021_item110 * item)
{
    return GET_BITS((item)->raw, 1, MASK_01_BITS);
}


/* ============================= FIRST EXTENSION ============================ */

uint8_t get_cat021_item110_ext1_NAV(const cat021_item110_ext1 * item)
{
    return GET_BITS((item)->raw, 8, MASK_01_BITS);
}

uint8_t get_cat021_item110_ext1_NVB(const cat021_item110_ext1 * item)
{
    return GET_BITS((item)->raw, 7, MASK_01_BITS);
}

uint8_t get_cat021_item110_ext1_FX(const cat021_item110_ext1 * item)
{
    return GET_BITS((item)->raw, 1, MASK_01_BITS);
}


/* ============================ SECOND EXTENSION ============================ */

#define TIP_BYTE(index, offset) (1 + ((index) * NUM_BYTES_CAT021_ITEM110_EXT2) + (offset))

uint8_t get_cat021_item110_ext2_REP(const cat021_item110_ext2 * item)
{
    return GET_BITS((item)->raw[0], 1, MASK_08_BITS);
}

uint8_t get_cat021_item110_ext2_TCA(const cat021_item110_ext2 * item,
                                    const uint8_t index)
{
    return GET_BITS((item)->raw[TIP_BYTE(index, 0)], 8, MASK_01_BITS);
}

uint8_t get_cat021_item110_ext2_NC(const cat021_item110_ext2 * item,
                                   const uint8_t index)
{
    return GET_BITS((item)->raw[TIP_BYTE(index, 0)], 7, MASK_01_BITS);
}

uint8_t get_cat021_item110_ext2_TCP_NUM(const cat021_item110_ext2 * item,
                                     const uint8_t index)
{
    return GET_BITS((item)->raw[TIP_BYTE(index, 0)], 1, MASK_06_BITS);
}

int32_t get_cat021_item110_ext2_ALT(const cat021_item110_ext2 * item,
                                     const uint8_t index)
{
    int32_t alt_raw = 
        ((int32_t) (GET_BITS((item)->raw[TIP_BYTE(index, 1)], 1, MASK_08_BITS) << 8) |
         (int32_t) (GET_BITS((item)->raw[TIP_BYTE(index, 2)], 1, MASK_08_BITS)     ));
    return alt_raw * LSB_CAT021_ITEM110_ALT; 
}

double get_cat021_item110_ext2_LAT(const cat021_item110_ext2 * item,
                                   const uint8_t index)
{
    uint32_t lat_raw = 
        ((uint32_t) (GET_BITS((item)->raw[TIP_BYTE(index, 3)], 1, MASK_08_BITS) << 16) |
         (uint32_t) (GET_BITS((item)->raw[TIP_BYTE(index, 4)], 1, MASK_08_BITS) <<  8) |
         (uint32_t) (GET_BITS((item)->raw[TIP_BYTE(index, 5)], 1, MASK_08_BITS)      ));
    return lat_raw * LSB_CAT021_ITEM110_LAT;
}

double get_cat021_item110_ext2_LON(const cat021_item110_ext2 * item,
                                   const uint8_t index)
{
    uint32_t lon_raw = 
        ((uint32_t) (GET_BITS((item)->raw[TIP_BYTE(index, 6)], 1, MASK_08_BITS) << 16) |
         (uint32_t) (GET_BITS((item)->raw[TIP_BYTE(index, 7)], 1, MASK_08_BITS) <<  8) |
         (uint32_t) (GET_BITS((item)->raw[TIP_BYTE(index, 8)], 1, MASK_08_BITS)      ));
    return lon_raw * LSB_CAT021_ITEM110_LON;
}

uint8_t get_cat021_item110_ext2_PT(const cat021_item110_ext2 * item,
                                   const uint8_t index)
{
    return GET_BITS((item)->raw[TIP_BYTE(index, 9)], 5, MASK_04_BITS);
}

uint8_t get_cat021_item110_ext2_TD(const cat021_item110_ext2 * item,
                                    const uint8_t index)
{
    return GET_BITS((item)->raw[TIP_BYTE(index, 9)], 3, MASK_02_BITS);
}

uint8_t get_cat021_item110_ext2_TRA(const cat021_item110_ext2 * item,
                                    const uint8_t index)
{
    return GET_BITS((item)->raw[TIP_BYTE(index, 9)], 2, MASK_01_BITS);
}

uint8_t get_cat021_item110_ext2_TOA(const cat021_item110_ext2 * item,
                                    const uint8_t index)
{
    return GET_BITS((item)->raw[TIP_BYTE(index, 9)], 1, MASK_01_BITS);
}

uint32_t get_cat021_item110_ext2_TOV(const cat021_item110_ext2 * item,
                                     const uint8_t index)
{
    uint32_t tov_raw =
        ((uint32_t) (GET_BITS((item)->raw[TIP_BYTE(index, 10)], 1, MASK_08_BITS) << 16) |
         (uint32_t) (GET_BITS((item)->raw[TIP_BYTE(index, 11)], 1, MASK_08_BITS) <<  8) |
         (uint32_t) (GET_BITS((item)->raw[TIP_BYTE(index, 12)], 1, MASK_08_BITS)      ));
    return tov_raw * LSB_CAT021_ITEM110_TOV;
}

double get_cat021_item110_ext2_TTR(const cat021_item110_ext2 * item,
                                   const uint8_t index)
{
    uint16_t ttr_raw =
        ((uint16_t) (GET_BITS((item)->raw[TIP_BYTE(index, 13)], 1, MASK_08_BITS) << 8) |
         (uint16_t) (GET_BITS((item)->raw[TIP_BYTE(index, 14)], 1, MASK_08_BITS)     ));
    return ttr_raw * LSB_CAT021_ITEM110_TTR;
}


/*******************************************************************************
* Setters
******************************************************************************/

/* =============================== MAIN BYTE =============================== */

void set_cat021_item110_TIS(cat021_item110 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 8);
}

void set_cat021_item110_TID(cat021_item110 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 7);
}

void set_cat021_item110_FX(cat021_item110 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 1);
}


/* ============================= FIRST EXTENSION ============================ */

void set_cat021_item110_ext1_NAV(cat021_item110_ext1 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 8);
}

void set_cat021_item110_ext1_NVB(cat021_item110_ext1 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 7);
}

void set_cat021_item110_ext1_FX(cat021_item110_ext1 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 1);
}


/* ============================ SECOND EXTENSION ============================ */

void set_cat021_item110_ext2_REP(cat021_item110_ext2 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw[0]), value, MASK_08_BITS, 1);
}

void set_cat021_item110_ext2_TCA(cat021_item110_ext2 * item, const uint8_t index, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw[TIP_BYTE(index, 0)]), value, MASK_01_BITS, 8);
}

void set_cat021_item110_ext2_NC(cat021_item110_ext2 * item, const uint8_t index, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw[TIP_BYTE(index, 0)]), value, MASK_01_BITS, 7);
}

void set_cat021_item110_ext2_TCP_NUM(cat021_item110_ext2 * item, const uint8_t index, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw[TIP_BYTE(index, 0)]), value, MASK_01_BITS, 1);
}

void set_cat021_item110_ext2_ALT(cat021_item110_ext2 * item, const uint8_t index, double value)
{
    uint16_t alt_raw;

    // TODO: Check value is in valid range

    alt_raw = value / LSB_CAT021_ITEM110_ALT;
    SET_BITS(&((item)->raw[TIP_BYTE(index, 1)]), (alt_raw >> 8), MASK_08_BITS, 8);
    SET_BITS(&((item)->raw[TIP_BYTE(index, 2)]), (alt_raw     ), MASK_08_BITS, 1);
}

void set_cat021_item110_ext2_LAT(cat021_item110_ext2 * item, const uint8_t index, uint32_t value)
{
    uint16_t lat_raw;

    // TODO: Check value is in valid range

    lat_raw = value / LSB_CAT021_ITEM110_LAT;
    SET_BITS(&((item)->raw[TIP_BYTE(index, 3)]), (lat_raw >> 16), MASK_08_BITS, 16);
    SET_BITS(&((item)->raw[TIP_BYTE(index, 4)]), (lat_raw >>  8), MASK_08_BITS,  8);
    SET_BITS(&((item)->raw[TIP_BYTE(index, 5)]), (lat_raw      ), MASK_08_BITS,  1);
}

void set_cat021_item110_ext2_LON(cat021_item110_ext2 * item, const uint8_t index, uint32_t value)
{
    uint16_t lon_raw;

    // TODO: Check value is in valid range

    lon_raw = value / LSB_CAT021_ITEM110_LON;
    SET_BITS(&((item)->raw[TIP_BYTE(index, 6)]), (lon_raw >> 16), MASK_08_BITS, 16);
    SET_BITS(&((item)->raw[TIP_BYTE(index, 7)]), (lon_raw >>  8), MASK_08_BITS,  8);
    SET_BITS(&((item)->raw[TIP_BYTE(index, 8)]), (lon_raw      ), MASK_08_BITS,  1);
}

void set_cat021_item110_ext2_PT(cat021_item110_ext2 * item, const uint8_t index, uint8_t value)
{    
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw[TIP_BYTE(index, 9)]), value, MASK_04_BITS, 5);
}

void set_cat021_item110_ext2_TD(cat021_item110_ext2 * item, const uint8_t index, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw[TIP_BYTE(index, 9)]), value, MASK_02_BITS, 3);
}

void set_cat021_item110_ext2_TRA(cat021_item110_ext2 * item, const uint8_t index, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw[TIP_BYTE(index, 9)]), value, MASK_01_BITS, 2);
}

void set_cat021_item110_ext2_TOA(cat021_item110_ext2 * item, const uint8_t index, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw[TIP_BYTE(index, 9)]), value, MASK_01_BITS, 1);
}

void set_cat021_item110_ext2_TOV(cat021_item110_ext2 * item, const uint8_t index, uint32_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw[TIP_BYTE(index, 10)]), (value >> 16), MASK_08_BITS, 1);
    SET_BITS(&((item)->raw[TIP_BYTE(index, 11)]), (value >>  8), MASK_08_BITS, 1);
    SET_BITS(&((item)->raw[TIP_BYTE(index, 12)]), (value      ), MASK_08_BITS, 1);
}

void set_cat021_item110_ext2_TTR(cat021_item110_ext2 * item, const uint8_t index, double value)
{
    uint16_t ttr_raw;

    // TODO: Check value is in valid range

    ttr_raw = value / LSB_CAT021_ITEM110_TTR;
    SET_BITS(&((item)->raw[TIP_BYTE(index, 13)]), (ttr_raw >> 8), MASK_08_BITS, 1);
    SET_BITS(&((item)->raw[TIP_BYTE(index, 14)]), (ttr_raw     ), MASK_08_BITS, 1);
}


/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item110(const cat021_item110 * item)
{
    uint8_t i, rep = 0;

    printf("Category 021 Item 110 - Trajectory Intent\n");
    printf("  TIS = %d\n", get_cat021_item110_TIS(item));
    printf("  TID = %d\n", get_cat021_item110_TID(item));
    printf("  FX = %d\n", get_cat021_item110_FX(item));

    if (get_cat021_item110_TIS(item))
    {
        printf("  ext1_NAV = %d\n", get_cat021_item110_ext1_NAV(&(item)->ext1));
        printf("  ext1_NVB = %d\n", get_cat021_item110_ext1_NVB(&(item)->ext1));
        printf("  ext1_FX = %d\n", get_cat021_item110_ext1_FX(&(item)->ext1));
    }

    if (get_cat021_item110_TID(item))
    {
        rep = get_cat021_item110_ext2_REP(&(item->ext2));
        printf("  REP = %d\n", rep);
        for (i = 0; i < rep; i++)
        {
            printf("  (TIP %d) ext2_TCA = %d\n", 
                i, get_cat021_item110_ext2_TCA(&(item->ext2), i));
            printf("  (TIP %d) ext2_NC = %d\n", 
                i, get_cat021_item110_ext2_NC(&(item->ext2), i));
            printf("  (TIP %d) ext2_TCP_NUM = %d\n", 
                i, get_cat021_item110_ext2_TCP_NUM(&(item->ext2), i));
            printf("  (TIP %d) ext2_ALT = %d\n", 
                i, get_cat021_item110_ext2_ALT(&(item->ext2), i));
            printf("  (TIP %d) ext2_LAT = %f\n", 
                i, get_cat021_item110_ext2_LAT(&(item->ext2), i));
            printf("  (TIP %d) ext2_LON = %f\n", 
                i, get_cat021_item110_ext2_LON(&(item->ext2), i));
            printf("  (TIP %d) ext2_TYPE = %d\n", 
                i, get_cat021_item110_ext2_TYPE(&(item->ext2), i));
            printf("  (TIP %d) ext2_TD = %d\n", 
                i, get_cat021_item110_ext2_TD(&(item->ext2), i));
            printf("  (TIP %d) ext2_TRA = %d\n", 
                i, get_cat021_item110_ext2_TRA(&(item->ext2), i));
            printf("  (TIP %d) ext2_TOA = %d\n", 
                i, get_cat021_item110_ext2_TOA(&(item->ext2), i));
            printf("  (TIP %d) ext2_TOV = %d\n", 
                i, get_cat021_item110_ext2_TOV(&(item->ext2), i));
            printf("  (TIP %d) ext2_TTR = %f\n", 
                i, get_cat021_item110_ext2_TTR(&(item->ext2), i));
        }
    }
}