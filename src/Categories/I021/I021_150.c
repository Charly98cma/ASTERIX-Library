/**
 * @file I021_150.c
 * @brief Implementation of the Category 21 Item 150 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_150.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_150_IM(const I021_150 * item) {
    return GET_BITS(item->raw, 16, MASK_01_BITS);
}

double get_I021_150_AIRSPD(const I021_150 * item) {
    double real_speed = 0;
    uint16_t raw_speed = GET_BITS(item->raw, 1, MASK_15_BITS);

    if (get_I021_150_IM(item) == I021_150_IM_IAS)
        real_speed = raw_speed * I021_150_LSB_IAS;
    else
        real_speed = raw_speed * I021_150_LSB_MACH;

    return real_speed;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_150_IM(I021_150 * item, const uint8_t im) {
    SET_BITS(&(item->raw), im, MASK_01_BITS, 16);
}

void set_I021_150_FL(I021_150 * item, const double value) {
    uint16_t raw_value = 0;

    if (get_I021_150_IM(item) == I021_150_IM_IAS)
        raw_value = value / I021_150_LSB_IAS;
    else
        raw_value = value / I021_150_LSB_MACH;

    SET_BITS(&(item->raw), raw_value, MASK_15_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_150(const I021_150 * item) {
    uint8_t im = get_I021_150_IM(item);

    printf("Category 021 Item 150 - Air Speed\n");
    printf("  IM = %d\n", im);
    if (im == I021_150_IM_IAS)
        printf("  IAS = %f\n", get_I021_150_AIRSPD(item));
    else
        printf("  MACH = %f\n", get_I021_150_AIRSPD(item));
}