/**
 * @file I021_008.c
 * @brief Implementation of the Category 21 Item 008 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_008.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_008_RA(const I021_008 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 7);
}

uint8_t get_I021_008_TC(const I021_008 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_02_BITS, 5);
}

uint8_t get_I021_008_TS(const I021_008 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 4);
}

uint8_t get_I021_008_ARV(const I021_008 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 3);
}

uint8_t get_I021_008_CDTI(const I021_008 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 2);
}

uint8_t get_I021_008_NTCAS(const I021_008 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 1);
}

uint8_t get_I021_008_SA(const I021_008 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_008_RA(I021_008 * item, uint8_t ra)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 7, ra);
}

void set_I021_008_TC(I021_008 * item, uint8_t tc)
{
    if (!item) return;
    write_bits(&item->raw, MASK_02_BITS, 5, tc);
}

void set_I021_008_TS(I021_008 * item, uint8_t ts)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 4, ts);
}

void set_I021_008_ARV(I021_008 * item, uint8_t arv)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 3, arv);
}

void set_I021_008_CDTI(I021_008 * item, uint8_t cdti)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 2, cdti);
}

void set_I021_008_NTCAS(I021_008 * item, uint8_t ntcas)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 1, ntcas);
}

void set_I021_008_SA(I021_008 * item, uint8_t sa)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, sa);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_008(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_008 *item;
    if (!item_in) return out_index;
    item = (I021_008 *)item_in;
    msg_out[out_index++] = item->raw;
    return out_index;
}

uint16_t decode_I021_008(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_008 *item;
    if (!item_out) return in_index;
    item = (I021_008 *)item_out;
    item->raw = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_008(const I021_008 *item)
{
    printf("I021/008 - Aircraft Operational Status\n");
    if (!item)
    {
        printf("I021/008: <null>\n");
        return;
    }
    printf("- RA: %d\n", get_I021_008_RA(item));
    printf("- TC: %d\n", get_I021_008_TC(item));
    printf("- TS: %d\n", get_I021_008_TS(item));
    printf("- ARV: %d\n", get_I021_008_ARV(item));
    printf("- CDTI: %d\n", get_I021_008_CDTI(item));
    printf("- NTCAS: %d\n", get_I021_008_NTCAS(item));
    printf("- SA: %d\n\n", get_I021_008_SA(item));
}
