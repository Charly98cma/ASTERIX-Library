/**
 * @file Header.c
 * @brief Implementation of the functions to read CAT and LEN from ASTERIX
 *        headers
 */

#include <stdio.h>
#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"
#include "Categories/Header.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_Header_CAT(const Header * header) {
    return header->CAT;
}

uint8_t get_Header_CAT_raw_data(const unsigned char * raw_data) {
    return raw_data[0];
}

uint16_t get_Header_LEN(const Header * header) {
    return (header->LEN[0] << 8) | (header->LEN[1]);
}

uint16_t get_Header_LEN_raw_data(const unsigned char * raw_data) {
    return (raw_data[1] << 8) | (raw_data[2]);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_Header_CAT(Header * item, uint8_t cat) {
    item->CAT = cat;
}

void set_Header_LEN(Header * item, uint16_t len) {
    item->LEN[0] = (len >> 8) & MASK_08_BITS;
    item->LEN[1] = len & MASK_08_BITS;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_Header(const Header * header) {
    printf("ASTERIX header\n");
    printf("  CAT = %d\n", get_Header_CAT(header));
    printf("  LEN = %d\n", get_Header_LEN(header));
}