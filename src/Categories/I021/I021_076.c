/**
 * @file I021_076.c
 * @brief Implementation of the Category 21 Item 076 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_076.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_076_FSI(const I021_076 * item) {
    return (item->raw[0] >> 6) & MASK_02_BITS;
}

uint32_t get_I021_076_TMRV_HP_raw(const I021_076 * item) {
    return ((((uint32_t) item->raw[0] & MASK_06_BITS) << 24) |
            (((uint32_t) item->raw[1] & MASK_08_BITS) << 16) |
            (((uint32_t) item->raw[2] & MASK_08_BITS) <<  8) |
            (((uint32_t) item->raw[3] & MASK_08_BITS)      ));
}

double get_I021_076_TMRV_HP(const I021_076 * item) {
    return get_I021_076_TMRV_HP_raw(item) * I021_076_LSB_TMRV_HP;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_076_FSI(I021_076 * item, uint8_t fsi) {
    /* TODO: Check value is in valid range */
    item->raw[0] |= (fsi & MASK_02_BITS) << 6;
}

void set_I021_076_TMRV_HP_raw(I021_076 * item, uint32_t tmrv_hp_raw) {
    item->raw[0] |= (tmrv_hp_raw >> 24) & MASK_06_BITS; /* 1st octet */
    item->raw[1]  = (tmrv_hp_raw >> 16);                /* 2nd octet */
    item->raw[2]  = (tmrv_hp_raw >>  8);                /* 3rd octet */
    item->raw[3]  = tmrv_hp_raw;                        /* 4th octet */
}

void set_I021_076_TMRV_HP(I021_076 * item, double tmrv_hp_seconds) {
    uint32_t tmrv_hp_raw = 0;

    /* TODO: Check value is in valid range */

    /* Turn to raw format and round to nearest unit if bigger than 0 */
    if (tmrv_hp_seconds > 0)
        tmrv_hp_raw = (uint32_t) (tmrv_hp_seconds / I021_076_LSB_TMRV_HP + 0.5);

    set_I021_076_TMRV_HP_raw(item, tmrv_hp_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_076(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_076 * item = (I021_076 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    msg_out[out_index++] = item->raw[2];
    msg_out[out_index++] = item->raw[3];
    return out_index;
}

uint16_t decode_I021_076(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_076 * item = (I021_076 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    item->raw[2] = msg_in[in_index++];
    item->raw[3] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_076(const I021_076 * item) {
    printf("Category 021 Item 076 - Time of Message Reception of Velocity-High Precision\n");
    printf("  TMRV_HP_FSI = %d\n", get_I021_076_FSI(item));
    printf("  TMRV_HP (raw) = 0x%04X\n", get_I021_076_TMRV_HP_raw(item));
    printf("  TMRV_HP (seconds) = %f\n\n", get_I021_076_TMRV_HP(item));
}
