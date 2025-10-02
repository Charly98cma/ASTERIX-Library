/**
 * @file I021_400.c
 * @brief Implementation of the Category 21 Item 400 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_400.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_400_RID(const I021_400 * item) {
    return item->raw;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_400_RID(I021_400 * item, uint8_t rid) {
    item->raw = rid;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_400(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_400 * item = (I021_400 *) item_in;
    msg_out[out_index++] = item->raw;
    return out_index;
}

uint16_t decode_I021_400(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_400 * item = (I021_400 *) item_out;
    item->raw = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_400(const I021_400 * item) {
    printf("Category 021 Item 400 - Receiver ID\n");
    printf("  RID = %d\n", get_I021_400_RID(item));
}