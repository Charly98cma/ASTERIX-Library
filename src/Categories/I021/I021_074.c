/**
 * @file I021_074.c
 * @brief Implementation of the Category 21 Item 074 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_074.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_074_FSI(const I021_074 * item) {
    return (item->raw[0] >> 6) & MASK_02_BITS;
}

uint32_t get_I021_074_TMRP_HP_raw(const I021_074 * item) {
    return (((((uint32_t) item->raw[0]) & MASK_06_BITS) << 24) |
            ((((uint32_t) item->raw[1])               ) << 16) |
            ((((uint32_t) item->raw[2])               ) <<  8) |
            ((((uint32_t) item->raw[3])               )      ));
}

double get_I021_074_TMRP_HP(const I021_074 * item) {
    return get_I021_074_TMRP_HP_raw(item) * I021_074_LSB_TMRP_HP;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

 void set_I021_074_FSI(I021_074 * item, uint8_t fsi) {
    /* TODO: Check value is in valid range */
    item->raw[0] |= (fsi & MASK_02_BITS) << 6;
}

void set_I021_074_TMRP_HP_raw(I021_074 * item, uint32_t tmrp_hp_raw) {
    item->raw[0] |= (tmrp_hp_raw >> 24) & MASK_06_BITS; /* 1st octet */
    item->raw[1]  = (tmrp_hp_raw >> 16);                /* 2nd octet */
    item->raw[2]  = (tmrp_hp_raw >>  8);                /* 3rd octet */
    item->raw[3]  =tmrp_hp_raw;                /* 4th octet */
}

void set_I021_074_TMRP_HP(I021_074 * item, double tmrp_hp_seconds) {
    uint32_t tmrp_hp_raw = 0;

    /* TODO: Check value is in valid range */

    /* Turn to raw format and round to nearest unit if bigger than 0 */
    if (tmrp_hp_seconds > 0)
        tmrp_hp_raw = (uint32_t) (tmrp_hp_seconds / I021_074_LSB_TMRP_HP + 0.5);

    set_I021_074_TMRP_HP_raw(item, tmrp_hp_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_074(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_074 * item = (I021_074 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    msg_out[out_index++] = item->raw[2];
    msg_out[out_index++] = item->raw[3];
    return out_index;
}

uint16_t decode_I021_074(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_074 * item = (I021_074 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    item->raw[2] = msg_in[in_index++];
    item->raw[3] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_074(const I021_074 * item) {
    printf("Category 021 Item 074 - Time of Message Reception of Position-High Precision\n");
    printf("  TMRP_HP_FSI = %d\n", get_I021_074_FSI(item));
    printf("  TMRP_HP (raw) = 0x%08X\n", get_I021_074_TMRP_HP_raw(item));
    printf("  TMRP_HP (seconds) = %f\n\n", get_I021_074_TMRP_HP(item));
}
