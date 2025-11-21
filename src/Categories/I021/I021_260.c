/**
 * @file I021_260.c
 * @brief Implementation of the Category 21 Item 260 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_260.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_260_TYP(const I021_260 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_05_BITS, 3);
}

uint8_t get_I021_260_STYP(const I021_260 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_03_BITS, 0);
}

uint16_t get_I021_260_ARA(const I021_260 * item)
{
    if (!item) return 0;
    return (item->raw[1] << 6) | ((item->raw[2] >> 2) & MASK_06_BITS);
}

uint8_t get_I021_260_RAC(const I021_260 * item)
{
    if (!item) return 0;
    return (((item->raw[2] & MASK_02_BITS) << 2) |
            ((item->raw[3] >> 6) & MASK_02_BITS));
}

uint8_t get_I021_260_RAT(const I021_260 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[3], MASK_01_BITS, 5);
}

uint8_t get_I021_260_MTE(const I021_260 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[3], MASK_01_BITS, 4);
}

uint8_t get_I021_260_TTI(const I021_260 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[3], MASK_02_BITS, 2);
}

uint32_t get_I021_260_TID(const I021_260 * item)
{
    if (!item) return 0;
    return (uint32_t) ((read_bits(item->raw, MASK_02_BITS, 0) << 24 ) |
                       (read_unsigned_24bit(&item->raw[4])));
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_260_TYP(I021_260 * item, uint8_t typ)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_05_BITS, 3, typ);
}

void set_I021_260_STYP(I021_260 * item, uint8_t styp)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_03_BITS, 0, styp);
}

void set_I021_260_ARA(I021_260 * item, uint16_t ara)
{
    if (!item) return;
    write_unsigned_8bit(&item->raw[1], ara >> 6);
    write_bits(&item->raw[2], MASK_06_BITS, 2, ara & MASK_06_BITS);
}

void set_I021_260_RAC(I021_260 * item, uint8_t rac)
{
    if (!item) return;
    write_bits(&item->raw[2], MASK_02_BITS, 0, rac >> 2);
    write_bits(&item->raw[3], MASK_02_BITS, 6, rac & MASK_02_BITS);
}

void set_I021_260_RAT(I021_260 * item, uint8_t rat)
{
    if (!item) return;
    write_bits(&item->raw[3], MASK_01_BITS, 5, rat);
}

void set_I021_260_MTE(I021_260 * item, uint8_t mte)
{
    if (!item) return;
    write_bits(&item->raw[3], MASK_01_BITS, 5, mte);
}

void set_I021_260_TTI(I021_260 * item, uint8_t tti)
{
    if (!item) return;
    write_bits(&item->raw[3], MASK_02_BITS, 2, tti);
}

void set_I021_260_TID(I021_260 * item, uint32_t tid)
{
    if (!item) return;
    write_bits(&item->raw[3], MASK_02_BITS, 0, tid >> 24);
    write_unsigned_24bit(&item->raw[4], tid);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_260(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_260 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_260 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 7);
    return out_index + 7;
}

uint16_t decode_I021_260(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_260 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_260 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 7);
    return in_index + 7;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_260(const I021_260 * item)
{
    printf("I021/260 - ACAS Resolution Advisory Report\n");
    if (!item)
    {
        printf("I021/260 <null>\n");
        return;
    }
    printf("- TYP = %d\n", get_I021_260_TYP(item));
    printf("- STYP = %d\n", get_I021_260_STYP(item));
    printf("- ARA = 0x%04X\n", get_I021_260_ARA(item));
    printf("- RAC = 0x%02X\n", get_I021_260_RAC(item));
    printf("- RAT = %d\n", get_I021_260_RAT(item));
    printf("- MTE = %d\n", get_I021_260_MTE(item));
    printf("- TTI = %d\n", get_I021_260_TTI(item));
    printf("- TID = 0x%08X\n", get_I021_260_TID(item));
}
