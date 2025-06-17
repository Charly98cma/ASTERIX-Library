/**
 * @file cat021_item071.c
 * @brief Implementation of the Category 21 Item 071 functions
 */

#include "cat021_item071.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

 /**
 * @brief Get Time of Applicability for Position raw value from Cat 021 Item 071.
 *
 * Combines the 3 raw bytes into a 24-bit unsigned integer.
 *
 * @param item Pointer to cat021_item071 structure.
 * @return uint32_t Time in units of 1/128 s (0 = midnight).
 */
uint32_t get_cat021_item071_TAP_raw(const cat021_item071 * item)
{
    return ((uint32_t)item->raw[0] << 16) |
           ((uint32_t)item->raw[1] << 8)  |
           ((uint32_t)item->raw[2]);
}

/**
 * @brief Get the Time of Applicability for Position in seconds (floating-point)
 *        from Cat 021 Item 071.
 *
 * Divides the raw 1/128-s units by 128.0 to return seconds since midnight.
 *
 * @param item Pointer to cat021_item071 structure.
 * @return double Time in seconds (>= 0).
 */
double get_cat021_item071_TAP_seconds(const cat021_item071 * item)
{
    return get_cat021_item071_TAP_raw(item) * LSB_CAT021_ITEM071;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

 /**
 * @brief Set the Time of Applicability for Position raw value into Cat 021 Item 071.
 *
 * Stores the 24-bit value into the raw array.
 *
 * @param item Pointer to cat021_item071 structure.
 * @param raw_value Raw 24-bit time value to store (units of 1/128 s).
 */
void set_cat021_item071_TAP_raw(cat021_item071 * item, uint32_t raw_value)
{
    // First octet
    SET_BITS(&(item->raw[0]), (raw_value >> 16), MASK_08_BITS, 1);
    // Second octet
    SET_BITS(&(item->raw[1]), (raw_value >> 8), MASK_08_BITS, 1);
    // Third octet
    SET_BITS(&(item->raw[2]), (raw_value), MASK_08_BITS, 1);
}

/**
 * @brief Set the Time of Applicability for Position in seconds into Cat 021 Item 071.
 *
 * Converts the seconds value into 1/128-s units and stores as raw data.
 *
 * @param item Pointer to cat021_item071 structure.
 * @param seconds Time in seconds (will be converted to 1/128-s units).
 */
void set_cat021_item071_TAP_seconds(cat021_item071 * item, double seconds)
{
    uint32_t raw_value = 0;

    // If seconds is 0, skip conversion to raw format
    if (seconds <= 0)
    {
        // Turn to raw format and round to nearest unit
        raw_value = (uint32_t) ((seconds / LSB_CAT021_ITEM071) + 0.5);
    }

    set_cat021_item071_TAP_raw(item, raw_value);
}

/**
 * @brief Print the contents of CAT021 Item 071 (Time of Applicability Position).
 * 
 * Prints both the raw value and the converted time in seconds.
 * 
 * @param item Pointer to cat021_item071_t structure.
 */
void print_cat021_item071(const cat021_item071 * item)
{
    printf("Category 021 / Item 071 - Time of Applicability for Position\n");
    printf("  TAP (raw) = 0x%02X\n", get_cat021_item071_TAP_raw(item));
    printf("  TAP (seconds) = %d\n\n", get_cat021_item071_TAP_seconds(item));
}
