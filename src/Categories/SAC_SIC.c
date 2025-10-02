/**
 * @file SAC_SIC.c
 * @brief Implementation of the Item 010 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/SAC_SIC.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_SAC(const SAC_SIC * item) {
    return item->raw[0];
}

uint8_t get_SIC(const SAC_SIC * item) {
    return item->raw[1];
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_SAC(SAC_SIC * item, uint8_t sac_value) {
    item->raw[0] = sac_value;
}

void set_SIC(SAC_SIC * item, uint8_t sic_value) {
    item->raw[1] = sic_value;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_SAC_SIC(SAC_SIC * item_in, unsigned char * msg_out, uint16_t out_index) {
    msg_out[out_index++] = item_in->raw[0];
    msg_out[out_index++] = item_in->raw[1];
    return out_index;
}

uint16_t decode_SAC_SIC(SAC_SIC * item_out, const unsigned char * msg_in, uint16_t in_index) {
    item_out->raw[0] = msg_in[in_index++];
    item_out->raw[1] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/
