/**
 * @file Header.c
 * @brief Implementation of the functions to read CAT and LEN from ASTERIX
 *        headers
 */

#include <stdio.h>
#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"
#include "Categories/Header.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_Header_CAT(const Header * header) {
    return (header->cat);
}

uint8_t get_Header_CAT_raw_data(const unsigned char * raw_data) {
    return (raw_data[0]);
}

uint16_t get_Header_LEN(const Header * header) {
    return (uint16_t) ((header->len[0] << 8) | (header->len[1]));
}

uint16_t get_Header_LEN_raw_data(const unsigned char * raw_data) {
    return (uint16_t) ((raw_data[1] << 8) | (raw_data[2]));
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_Header_CAT(Header * item, const uint8_t cat)
{
    item->cat = cat;
}

void set_Header_LEN(Header * item, const uint16_t len)
{
    SET_BITS(&(item->len[0]), (len >> 8), MASK_08_BITS, 1);
    SET_BITS(&(item->len[0]), (len     ), MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_Header(const Header * header) {
    printf("ASTERIX header\n");
    printf("  CAT = %d\n", get_Header_CAT(header));
    printf("  LEN = %d\n", get_Header_LEN(header));
}