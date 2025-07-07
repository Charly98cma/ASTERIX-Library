/**
 * @file I021_076.c
 * @brief Implementation of the Category 21 Item 076 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_076.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_076_FSI(const I021_076 * item) {
    return GET_BITS((item->raw[0]), 7, MASK_02_BITS);
}

uint32_t get_I021_076_TMRV_HP_raw(const I021_076 * item) {
    return ((uint32_t) (GET_BITS((item->raw[0]), 1, MASK_06_BITS) << 24) |
            (uint32_t) (GET_BITS((item->raw[1]), 1, MASK_08_BITS) << 16) |
            (uint32_t) (GET_BITS((item->raw[2]), 1, MASK_08_BITS) <<  8) |
            (uint32_t) (GET_BITS((item->raw[3]), 1, MASK_08_BITS)      ));
}

double get_I021_076_TMRV_HP_seconds(const I021_076 * item) {
    return (double) get_I021_076_TMRV_HP_raw(item) * I021_076_LSB_TMRV_HP;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_076_FSI(I021_076 * item, const uint8_t raw_value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw[0]), raw_value, MASK_02_BITS, 7);
}

void set_I021_076_TMRV_HP_raw(I021_076 * item, const uint32_t raw_value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw[0]), (raw_value >> 24), MASK_06_BITS, 1); // 1st octet
    SET_BITS(&(item->raw[1]), (raw_value >> 16), MASK_08_BITS, 1); // 2nd octet
    SET_BITS(&(item->raw[2]), (raw_value >>  8), MASK_08_BITS, 1); // 3rd octet
    SET_BITS(&(item->raw[3]), (raw_value      ), MASK_08_BITS, 1); // 4th octet
}

void set_I021_076_TMRV_HP_seconds(I021_076 * item, const double seconds) {
    uint32_t raw_value = 0;

    // TODO: Check value is in valid range

    // Turn to raw format and round to nearest unit if bigger than 0
    if (seconds > 0)
        raw_value = (uint32_t) (seconds / I021_076_LSB_TMRV_HP + 0.5);

    set_I021_076_TMRV_HP_raw(item, raw_value);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_076(const I021_076 * item) {
    printf("Category 021 Item 076 - Time of Message Reception of Velocity-High Precision\n");
    printf("  TMRV_HP_FSI = %d\n", get_I021_076_FSI(item));
    printf("  TMRV_HP (raw) = 0x%04X\n", get_I021_076_TMRV_HP_raw(item));
    printf("  TMRV_HP (seconds) = %f\n\n", get_I021_076_TMRV_HP_seconds(item));
}
