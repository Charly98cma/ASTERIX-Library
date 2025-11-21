/**
 * @file I021_110.c
 * @brief Implementation of the Category 21 Item 110 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_110.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

uint8_t get_I021_110_TIS(const I021_110 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 7);
}

uint8_t get_I021_110_TID(const I021_110 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 6);
}

uint8_t get_I021_110_FX(const I021_110 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}


/* ============================= FIRST EXTENSION ============================ */

uint8_t get_I021_110_EXT1_NAV(const I021_110_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 7);
}

uint8_t get_I021_110_EXT1_NVB(const I021_110_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 6);
    return read_bits(&item->raw, MASK_01_BITS, 6);
}

uint8_t get_I021_110_EXT1_FX(const I021_110_EXT1 * item)
{
    if (!item) return 0;
    return item->raw & MASK_01_BITS;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* ============================ SECOND EXTENSION ============================ */

#define TIP_BYTE(index, offset) (1 + ((index) * NUM_BYTES_I021_110_EXT2) + (offset))

uint8_t get_I021_110_EXT2_REP(const I021_110_EXT2 * item)
{
    if (!item) return 0;
    return read_unsigned_8bit(item->raw);
}

uint8_t get_I021_110_EXT2_TCA(const I021_110_EXT2 * item, uint8_t index)
{
    if (!item) return 0;
    return read_bits(&item->raw[TIP_BYTE(index, 0)], MASK_01_BITS, 7);
}

uint8_t get_I021_110_EXT2_NC(const I021_110_EXT2 * item, uint8_t index)
{
    if (!item) return 0;
    return read_bits(&item->raw[TIP_BYTE(index, 0)], MASK_01_BITS, 6);
}

uint8_t get_I021_110_EXT2_TCP_NUM(const I021_110_EXT2 * item, uint8_t index)
{
    if (!item) return 0;
    return read_bits(&item->raw[TIP_BYTE(index, 0)], MASK_06_BITS, 0);
}

int32_t get_I021_110_EXT2_ALT(const I021_110_EXT2 * item, uint8_t index)
{
    if (!item) return 0;
    return read_unsigned_16bit(&item->raw[TIP_BYTE(index, 1)]) * I021_110_LSB_ALT;
}

double get_I021_110_EXT2_LAT(const I021_110_EXT2 * item, uint8_t index)
{
    if (!item) return 0;
    return read_unsigned_24bit(&item->raw[TIP_BYTE(index, 3)]) * I021_110_LSB_LAT;
}

double get_I021_110_EXT2_LON(const I021_110_EXT2 * item, uint8_t index)
{
    if (!item) return 0;
    return read_unsigned_24bit(&item->raw[TIP_BYTE(index, 6)]) * I021_110_LSB_LON;
}

uint8_t get_I021_110_EXT2_TYPE(const I021_110_EXT2 * item, uint8_t index)
{
    if (!item) return 0;
    return read_bits(&item->raw[TIP_BYTE(index, 9)], MASK_04_BITS, 4);
}

uint8_t get_I021_110_EXT2_TD(const I021_110_EXT2 * item, uint8_t index)
{
    if (!item) return 0;
    return read_bits(&item->raw[TIP_BYTE(index, 9)], MASK_02_BITS, 2);
}

uint8_t get_I021_110_EXT2_TRA(const I021_110_EXT2 * item, uint8_t index)
{
    if (!item) return 0;
    return read_bits(&item->raw[TIP_BYTE(index, 9)], MASK_01_BITS, 1);
}

uint8_t get_I021_110_EXT2_TOA(const I021_110_EXT2 * item, uint8_t index)
{
    if (!item) return 0;
    return read_bits(&item->raw[TIP_BYTE(index, 9)], MASK_01_BITS, 0);
}

uint32_t get_I021_110_EXT2_TOV(const I021_110_EXT2 * item, uint8_t index)
{
    if (!item) return 0;
    return read_unsigned_24bit(&item->raw[TIP_BYTE(index, 10)]) * I021_110_LSB_TOV;
}

double get_I021_110_EXT2_TTR(const I021_110_EXT2 * item, uint8_t index)
{
    if (!item) return 0;
    return read_unsigned_24bit(&item->raw[TIP_BYTE(index, 13)]) * I021_110_LSB_TTR;
}


/*******************************************************************************
* Setters
******************************************************************************/

/* =============================== MAIN BYTE =============================== */

void set_I021_110_TIS(I021_110 * item, uint8_t tis)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 7, tis);
}

void set_I021_110_TID(I021_110 * item, uint8_t tid)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 6, tid);
}

void set_I021_110_FX(I021_110 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}


/* ============================= FIRST EXTENSION ============================ */

void set_I021_110_EXT1_NAV(I021_110_EXT1 * item, uint8_t nav)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 7, nav);
}

void set_I021_110_EXT1_NVB(I021_110_EXT1 * item, uint8_t nvb)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 6, nvb);
}

void set_I021_110_EXT1_FX(I021_110_EXT1 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}


/* ============================ SECOND EXTENSION ============================ */

void set_I021_110_EXT2_REP(I021_110_EXT2 * item, uint8_t rep)
{
    if (!item) return;
    write_unsigned_8bit(item->raw, rep);
}

void set_I021_110_EXT2_TCA(I021_110_EXT2 * item, uint8_t index, uint8_t tca)
{
    if (!item) return;
    write_bits(&item->raw[TIP_BYTE(index, 0)], MASK_01_BITS, 7, tca);
}

void set_I021_110_EXT2_NC(I021_110_EXT2 * item, uint8_t index, uint8_t nc)
{
    if (!item) return;
    write_bits(&item->raw[TIP_BYTE(index, 0)], MASK_01_BITS, 6, nc);
}

void set_I021_110_EXT2_TCP_NUM(I021_110_EXT2 * item, uint8_t index, uint8_t num)
{
    if (!item) return;
    write_bits(&item->raw[TIP_BYTE(index, 0)], MASK_06_BITS, 0, num);
}

void set_I021_110_EXT2_ALT(I021_110_EXT2 * item, uint8_t index, double alt)
{
    uint16_t alt_raw = 0;
    if (!item) return;
    alt_raw = alt / I021_110_LSB_ALT;
    write_twocomp_16bit(&item->raw[TIP_BYTE(index, 1)], alt_raw);
}

void set_I021_110_EXT2_LAT(I021_110_EXT2 * item, uint8_t index, uint32_t lat)
{
    int16_t lat_raw = 0;
    if (!item) return;
    lat_raw = (lat / I021_110_LSB_LAT) + 0.5;
    write_twocomp_24bit(&item->raw[TIP_BYTE(index, 3)], lat_raw);
}

void set_I021_110_EXT2_LON(I021_110_EXT2 * item, uint8_t index, uint32_t lon)
{
    int16_t lon_raw = 0;
    if (!item) return;
    lon_raw = lon / I021_110_LSB_LON;
    write_twocomp_24bit(&item->raw[TIP_BYTE(index, 6)], lon_raw);
}

void set_I021_110_EXT2_PT(I021_110_EXT2 * item, uint8_t index, uint8_t pt)
{
    if (!item) return;    
    write_bits(&item->raw[TIP_BYTE(index, 9)], MASK_04_BITS, 4, pt);
}

void set_I021_110_EXT2_TD(I021_110_EXT2 * item, uint8_t index, uint8_t td)
{
    if (!item) return;
    write_bits(&item->raw[TIP_BYTE(index, 9)], MASK_02_BITS, 2, td);
}

void set_I021_110_EXT2_TRA(I021_110_EXT2 * item, uint8_t index, uint8_t tra)
{
    if (!item) return;
    write_bits(&item->raw[TIP_BYTE(index, 9)], MASK_01_BITS, 1, tra);
}

void set_I021_110_EXT2_TOA(I021_110_EXT2 * item, uint8_t index, uint8_t toa)
{
    if (!item) return;
    write_bits(&item->raw[TIP_BYTE(index, 9)], MASK_01_BITS, 0, toa);
}

void set_I021_110_EXT2_TOV(I021_110_EXT2 * item, uint8_t index, uint32_t tov)
{
    if (!item) return;
    write_unsigned_24bit(&item->raw[TIP_BYTE(index, 10)], tov);
}

void set_I021_110_EXT2_TTR(I021_110_EXT2 * item, uint8_t index, double ttr)
{
    uint16_t ttr_raw = 0;
    if (!item) return;
    ttr_raw = ttr / I021_110_LSB_TTR;
    write_unsigned_24bit(&item->raw[TIP_BYTE(index, 15)], ttr_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_110(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    uint16_t num_bytes = 0;
    I021_110 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_110 *)item_in;    
    msg_out[out_index++] = item->raw;
    if (get_I021_110_TIS(item))
        msg_out[out_index++] = item->ext1.raw;
    if (get_I021_110_TID(item))
    {
        num_bytes = 1 + get_I021_110_EXT2_REP(&item->ext2) * NUM_BYTES_I021_110_EXT2;
        memcpy(&msg_out[out_index], item->ext2.raw, num_bytes);
    }
    return out_index + num_bytes;
}

uint16_t decode_I021_110(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    uint8_t num_bytes = 0;
    I021_110 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_110 *)item_out;
    item->raw = msg_in[in_index++];
    if (get_I021_110_TIS(item))
        item->ext1.raw = msg_in[in_index++];
    if (get_I021_110_TID(item))
    {
        num_bytes = 1 + msg_in[in_index] * NUM_BYTES_I021_110_EXT2;
        memcpy(item->ext2.raw, &msg_in[in_index], num_bytes);
    }
    return in_index + num_bytes;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_110(const I021_110 * item)
{
    uint8_t i, rep = 0;

    printf("I021/110 - Trajectory Intent\n");
    if (!item)
    {
        printf("I021/110: <null>\n");
        return;
    }

    printf("- TIS = %d\n", get_I021_110_TIS(item));
    if (get_I021_110_TIS(item))
    {
    
        printf("-- EXT1_NAV = %d\n", get_I021_110_EXT1_NAV(&item->ext1));
        printf("-- EXT1_NVB = %d\n", get_I021_110_EXT1_NVB(&item->ext1));
        printf("-- EXT1_FX = %d\n", get_I021_110_EXT1_FX(&item->ext1));
    }

    printf("- TID = %d\n", get_I021_110_TID(item));
    if (get_I021_110_TID(item))
    {
        rep = get_I021_110_EXT2_REP(&(item->ext2));
        printf("-- EXT2_REP = %d\n", rep);
        for (i = 0; i < rep; i++)
        {
            printf("-- EXT2_TIP [%d] - TCA = %d\n", 
                i, get_I021_110_EXT2_TCA(&(item->ext2), i));
            printf("-- EXT2_TIP [%d] - NC = %d\n", 
                i, get_I021_110_EXT2_NC(&(item->ext2), i));
            printf("-- EXT2_TIP [%d] - TCP_NUM = %d\n", 
                i, get_I021_110_EXT2_TCP_NUM(&(item->ext2), i));
            printf("-- EXT2_TIP [%d] - ALT = %d\n", 
                i, get_I021_110_EXT2_ALT(&(item->ext2), i));
            printf("-- EXT2_TIP [%d] - LAT = %f\n", 
                i, get_I021_110_EXT2_LAT(&(item->ext2), i));
            printf("-- EXT2_TIP [%d] - LON = %f\n", 
                i, get_I021_110_EXT2_LON(&(item->ext2), i));
            printf("-- EXT2_TIP [%d] - TYPE = %d\n", 
                i, get_I021_110_EXT2_TYPE(&(item->ext2), i));
            printf("-- EXT2_TIP [%d] - TD = %d\n", 
                i, get_I021_110_EXT2_TD(&(item->ext2), i));
            printf("-- EXT2_TIP [%d] - TRA = %d\n", 
                i, get_I021_110_EXT2_TRA(&(item->ext2), i));
            printf("-- EXT2_TIP [%d] - TOA = %d\n", 
                i, get_I021_110_EXT2_TOA(&(item->ext2), i));
            printf("-- EXT2_TIP [%d] - TOV = %d\n", 
                i, get_I021_110_EXT2_TOV(&(item->ext2), i));
            printf("-- EXT2_TIP [%d] - TTR = %f\n", 
                i, get_I021_110_EXT2_TTR(&(item->ext2), i));
        }
    }
    printf("- FX = %d\n", get_I021_110_FX(item));
}