/**
 * @file cat021_item076.c
 * @brief Implementation of the Category 21 Item 076 functions
 */

#include "Categories/cat021/cat021_item076.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item076_FSI(const cat021_item076 * item)
{
    return GET_BITS(((item)->raw[0]), 7, MASK_02_BITS);
}

uint32_t get_cat021_item076_TMRV_HP_raw(const cat021_item076 * item)
{
    return (uint32_t) ((GET_BITS(((item)->raw[0]), 1, MASK_06_BITS) << 24) |
                       (GET_BITS(((item)->raw[1]), 1, MASK_08_BITS) << 16) |
                       (GET_BITS(((item)->raw[2]), 1, MASK_08_BITS) <<  8) |
                       (GET_BITS(((item)->raw[3]), 1, MASK_08_BITS)      ));
}

double get_cat021_item076_TMRV_HP_seconds(const cat021_item076 * item)
{
    return (double) get_cat021_item076_TMRV_HP_raw(item) * LSB_CAT021_ITEM076;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item076_FSI(cat021_item076 * item, uint8_t raw_value)
{
    SET_BITS(&(item->raw[0]), raw_value, MASK_02_BITS, 7);
}

void set_cat021_item076_TMRV_HP_raw(cat021_item076 * item, uint32_t raw_value)
{
    SET_BITS(&(item->raw[0]), (raw_value >> 24), MASK_06_BITS, 1); // 1st octet
    SET_BITS(&(item->raw[1]), (raw_value >> 16), MASK_08_BITS, 1); // 2nd octet
    SET_BITS(&(item->raw[2]), (raw_value >>  8), MASK_08_BITS, 1); // 3rd octet
    SET_BITS(&(item->raw[3]), (raw_value      ), MASK_08_BITS, 1); // 4th octet
}

void set_cat021_item076_TMRV_HP_seconds(cat021_item076 * item, double seconds)
{
    uint32_t raw_value = 0;

    // Turn to raw format and round to nearest unit if bigger than 0
    if (seconds > 0)
        raw_value = (uint32_t) (seconds / LSB_CAT021_ITEM076 + 0.5);

    set_cat021_item076_TMRV_HP_raw(item, raw_value);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item076(const cat021_item076 * item)
{
    printf("Category 021 / Item 076 - Time of Message Reception of Velocity-High Precision\n");
    printf("  TMRV_HP_FSI = %d\n", get_cat021_item076_FSI(item));
    printf("  TMRV_HP (raw) = 0x%04X\n", get_cat021_item076_TMRV_HP_raw(item));
    printf("  TMRV_HP (seconds) = %f\n\n", get_cat021_item076_TMRV_HP_seconds(item));
}
