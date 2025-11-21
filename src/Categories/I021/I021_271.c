/**
 * @file I021_271.c
 * @brief Implementation of the Category 21 Item 271 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_271.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_271_POA(const I021_271 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 5);
}

uint8_t get_I021_271_CDTIS(const I021_271 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 4);
}

uint8_t get_I021_271_B2(const I021_271 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 3);
}

uint8_t get_I021_271_RAS(const I021_271 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 2);
}

uint8_t get_I021_271_IDENT(const I021_271 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 1);
}

uint8_t get_I021_271_FX(const I021_271 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

uint8_t get_I021_271_EXT1_LW(const I021_271_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_04_BITS, 4);
}

uint8_t get_I021_271_EXT1_FX(const I021_271_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_271_POA(I021_271 * item, uint8_t poa)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 5, poa);
}

void set_I021_271_CDTIS(I021_271 * item, uint8_t cdtis)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 4, cdtis);
}

void set_I021_271_B2(I021_271 * item, uint8_t b2)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 3, b2);
}

void set_I021_271_RAS(I021_271 * item, uint8_t ras)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 2, ras);
}

void set_I021_271_IDENT(I021_271 * item, uint8_t ident)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 1, ident);
}

void set_I021_271_FX(I021_271 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

void set_I021_271_EXT1_LW(I021_271_EXT1 * item, uint8_t lw)
{
    if (!item) return;
    write_bits(&item->raw, MASK_04_BITS, 4, lw);
}

void set_I021_271_EXT1_FX(I021_271_EXT1 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_271(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_271 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_271 *) item_in;
    memcpy(&msg_out[out_index], &item->raw, 1);
    return out_index + 1;
}

uint16_t decode_I021_271(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_271 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_271 *) item_out;
    memcpy(&item->raw, &msg_in[in_index], 1);
    return in_index + 1;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_271(const I021_271 * item)
{
    printf("I021/271 - Surface Capabilities and Characteristics\n");
    if (!item)
    {
        printf("I021/271 <null>\n");
        return;
    }
    printf("- POA = %d\n", get_I021_271_POA(item));
    printf("- CDTIS = %d\n", get_I021_271_CDTIS(item));
    printf("- B2 = %d\n", get_I021_271_B2(item));
    printf("- RAS = %d\n", get_I021_271_RAS(item));
    printf("- IDENT = %d\n", get_I021_271_IDENT(item));
    printf("- FX = %d\n", get_I021_271_FX(item));

    if (get_I021_271_FX(item))
    {
        printf("-- EXT1_LW = %d\n", get_I021_271_EXT1_LW(&(item->ext1)));
        printf("-- EXT1_FX = %d\n", get_I021_271_EXT1_FX(&(item->ext1)));
    }
}