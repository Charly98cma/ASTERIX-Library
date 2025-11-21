/**
 * @file I021_250.c
 * @brief Implementation of the Category 21 Item 250 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_250.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

#define BDS_BYTE(index, offset) (1 + ((index) * I021_250_BDSREG_N_OCTETS) + (offset))

uint8_t get_I021_250_REP(const I021_250 * item)
{
    if (!item) return 0;
    return read_unsigned_8bit(item->raw);
}

uint64_t get_I021_250_BDSDATA(const I021_250 * item, uint8_t bds_index)
{
    if (!item) return 0;
    uint64_t bds_register = (
        (((uint64_t) item->raw[BDS_BYTE(bds_index, 0)]) << 48) |
        (((uint64_t) item->raw[BDS_BYTE(bds_index, 1)]) << 40) |
        (((uint64_t) item->raw[BDS_BYTE(bds_index, 2)]) << 32) |
        (((uint64_t) item->raw[BDS_BYTE(bds_index, 3)]) << 24) |
        (((uint64_t) item->raw[BDS_BYTE(bds_index, 4)]) << 16) |
        (((uint64_t) item->raw[BDS_BYTE(bds_index, 5)]) <<  8) |
        (((uint64_t) item->raw[BDS_BYTE(bds_index, 6)])      )
    );
    return bds_register;
}

uint8_t get_I021_250_BDS1(const I021_250 * item, uint8_t bds_index)
{
    if (!item) return 0;
    return read_bits(&item->raw[BDS_BYTE(bds_index, 7)], MASK_04_BITS, 4);
}

uint8_t get_I021_250_BDS2(const I021_250 * item, uint8_t bds_index)
{
    if (!item) return 0;
    return read_bits(&item->raw[BDS_BYTE(bds_index, 7)], MASK_04_BITS, 0);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_250_REP(I021_250 * item, uint8_t rep)
{
    if (!item) return;
    write_unsigned_8bit(item->raw, rep);
}

void set_I021_250_BDSDATA(I021_250 * item, uint8_t bds_index, const uint64_t bds_data)
{
    if (!item) return;
    item->raw[BDS_BYTE(bds_index, 0)] = bds_data >> 48;
    item->raw[BDS_BYTE(bds_index, 1)] = bds_data >> 40;
    item->raw[BDS_BYTE(bds_index, 2)] = bds_data >> 32;
    item->raw[BDS_BYTE(bds_index, 3)] = bds_data >> 24;
    item->raw[BDS_BYTE(bds_index, 4)] = bds_data >> 16;
    item->raw[BDS_BYTE(bds_index, 5)] = bds_data >>  8;
    item->raw[BDS_BYTE(bds_index, 6)] = bds_data;
}

void set_I021_250_BDS1(I021_250 * item, uint8_t bds_index, uint8_t bds1)
{
    if (!item) return;
    write_bits(&item->raw[BDS_BYTE(bds_index, 7)], MASK_04_BITS, 4, bds1);
}

void set_I021_250_BDS2(I021_250 * item, uint8_t bds_index, uint8_t bds2)
{
    if (!item) return;
    write_bits(&item->raw[BDS_BYTE(bds_index, 7)], MASK_04_BITS, 0, bds2);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_250(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    uint8_t i;
    I021_250 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_250 *) item_in;
    /* Encode number of BDS Registers */
    msg_out[out_index++] = item->REP;
    /* Encode each register */
    for (i = 0; i < item->REP; i++)
    {
        /* Copy BDS DATA, BDS1 and BDS2 */
        memcpy(&msg_out[out_index], item->BDS_REGISTER[i].BDS, I021_250_BDSDATA_N_OCTETS + 1);
        out_index += I021_250_BDSDATA_N_OCTETS + 1;
    }

    return out_index;
}

uint16_t decode_I021_250(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    uint8_t i;
    I021_250 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_250 *) item_out;
    /* Decode the number of BDS Registers */
    item->REP = msg_in[in_index++];
    /* Decode each register */
    for (i = 0; i < item->REP; i++)
    {
        memcpy(item->BDS_REGISTER[i].BDS, &msg_in[in_index], I021_250_BDSDATA_N_OCTETS + 1);
        in_index += I021_250_BDSDATA_N_OCTETS + 1;
    }
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_250(const I021_250 * item)
{
    uint8_t i, rep = 0;
    uint64_t bds_reg = 0;
    
    printf("I021/250 - BDS Register Data\n");
    if (!item)
    {
        printf("I021/250 <null>\n");
        return;
    }

    rep = get_I021_250_REP(item);
    printf("- REP = %d\n", rep);
    for (i = 0; i < rep; i++)
    {
        bds_reg = get_I021_250_BDSDATA(item, i);
        printf("- BDS Reg. Data (%d) = 0x%08X%08X\n",
                i, (uint32_t) (bds_reg >> 32), (uint32_t) bds_reg);
        printf("- BDS Reg. Addr. 1 (%d) = 0x%X\n", i, get_I021_250_BDS1(item, i));
        printf("- BDS Reg. Addr. 1 (%d) = 0x%X\n", i, get_I021_250_BDS2(item, i));
    }
}