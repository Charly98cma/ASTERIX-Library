/**
 * @file cat021_item074.c
 * @brief Implementation of the Category 21 Item 074 functions
 */

#include "cat021_item074.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item074_FSI(const cat021_item074 * item)
{
    return GET_BITS(((item)->raw[0]), 7, MASK_02_BITS);
}

uint32_t get_cat021_item074_TMRP_HP_raw(const cat021_item074 * item)
{
    return (uint32_t) ((GET_BITS(((item)->raw[0]), 1, MASK_06_BITS) << 24) |
                       (GET_BITS(((item)->raw[1]), 1, MASK_08_BITS) << 16) |
                       (GET_BITS(((item)->raw[2]), 1, MASK_08_BITS) <<  8) |
                       (GET_BITS(((item)->raw[3]), 1, MASK_08_BITS)      ));
}

double get_cat021_item074_TMRP_HP_seconds(const cat021_item074 * item)
{
    double seconds = get_cat021_item074_TMRP_HP_raw(item) * LSB_CAT021_ITEM074;

    switch(get_cat021_item074_FSI(item))
    {
        case 3: break;              // Reserved
        case 2: seconds++; break;   // TOMRp whole seconds = Whole seconds + 1 
        case 1: seconds--; break;   // TOMRp whole seconds = Whole seconds – 1 
        case 0: break;              // TOMRp whole seconds = Whole seconds
    }

    return seconds;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

 void set_cat021_item074_FSI(cat021_item074 * item, uint8_t raw_value)
{
    SET_BITS(&(item->raw[0]), raw_value, MASK_02_BITS, 7);
}

void set_cat021_item074_TMRP_HP_raw(cat021_item074 * item, uint32_t raw_value)
{
    SET_BITS(&(item->raw[0]), (raw_value >> 24), MASK_06_BITS, 1); // 1st octet
    SET_BITS(&(item->raw[1]), (raw_value >> 16), MASK_08_BITS, 1); // 2nd octet
    SET_BITS(&(item->raw[2]), (raw_value >>  8), MASK_08_BITS, 1); // 3rd octet
    SET_BITS(&(item->raw[3]), (raw_value      ), MASK_08_BITS, 1); // 4th octet
}

void set_cat021_item074_TMRP_HP_seconds(cat021_item074 * item, double seconds)
{
    uint32_t raw_value = 0;

    // Turn to raw format and round to nearest unit if bigger than 0
    if (seconds > 0)
        raw_value = (uint32_t) (seconds / LSB_CAT021_ITEM074 + 0.5);

    set_cat021_item074_TMRP_HP_raw(item, raw_value);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item074(const cat021_item074 * item)
{
    printf("Category 021 / Item 074 - Time of Message Reception of Position-High Precision\n");
    printf("  TMRP_HP_FSI = %d\n", get_cat021_item074_FSI(item));
    printf("  TMRP_HP (raw) = 0x%03X\n", get_cat021_item074_TMRP_HP_raw(item));
    printf("  TMRP_HP (seconds) = %f\n\n", get_cat021_item074_TMRP_HP_seconds(item));
}
