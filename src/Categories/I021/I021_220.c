/**
 * @file I021_220.c
 * @brief Implementation of the Category 21 Item 220 functions
 */ 

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_220.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/ 

/* ============================== MAIN BYTE ============================== */

uint8_t get_I021_220_WS(const I021_220 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 7);
}

uint8_t get_I021_220_WD(const I021_220 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 6);
}

uint8_t get_I021_220_TEMP(const I021_220 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 5);
}

uint8_t get_I021_220_TRB(const I021_220 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 4);
}

uint8_t get_I021_220_FX(const I021_220 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* ============================== SUBFIELD #1 ============================== */

uint16_t get_I021_220_EXT1_WS(const I021_220_EXT1 * item)
{
    if (!item) return 0;
    return read_unsigned_16bit(item->WS);
}

/* ============================== SUBFIELD #2 ============================== */

uint16_t get_I021_220_EXT2_WD(const I021_220_EXT2 * item)
{
    if (!item) return 0;
    return read_unsigned_16bit(item->WD);
}

/* ============================== SUBFIELD #3 ============================== */

double get_I021_220_EXT3_TEMP(const I021_220_EXT3 * item)
{
    if (!item) return 0;
    return read_twocomp_16bit((uint8_t *)&item->TEMP) * I021_220_EXT3_LSB_TEMP;
}

/* ============================== SUBFIELD #4 ============================== */

uint8_t get_I021_220_EXT4_TRB(const I021_220_EXT4 * item)
{
    if (!item) return 0;
    return read_unsigned_8bit(&item->TRB);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================== MAIN BYTE ============================== */

void set_I021_220_WS(I021_220 * item, uint8_t ws)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 7, ws);
}

void set_I021_220_WD(I021_220 * item, uint8_t wd)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 6, wd);
}

void set_I021_220_TEMP(I021_220 * item, uint8_t temp)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 5, temp);
}

void set_I021_220_TRB(I021_220 * item, uint8_t trb)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 4, trb);
}

void set_I021_220_FX(I021_220 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* ============================== SUBFIELD #1 ============================== */

void set_I021_220_EXT1_WS(I021_220_EXT1 * item, uint16_t wind_spd)
{
    if (!item) return;
    write_unsigned_16bit(item->WS, wind_spd);
}

/* ============================== SUBFIELD #2 ============================== */

void set_I021_220_EXT2_WD(I021_220_EXT2 * item, uint16_t wind_dir)
{
    if (!item) return;
    write_unsigned_16bit(item->WD, wind_dir);
}

/* ============================== SUBFIELD #3 ============================== */

void set_I021_220_EXT3_TEMP(I021_220_EXT3 * item, double temp_celsius)
{
    int16_t temp_raw = 0;
    if (!item) return;
    if (temp_celsius > 0)
    temp_raw = (int16_t) ((temp_celsius / I021_220_EXT3_LSB_TEMP) + 0.5);    
    write_twocomp_16bit((uint8_t *)&item->TEMP, temp_raw);
}

/* ============================== SUBFIELD #4 ============================== */

void set_I021_220_EXT4_TRB(I021_220_EXT4 * item, uint8_t trb)
{
    if (!item) return;
    write_unsigned_8bit(&item->TRB, trb);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_220(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_220 *item;
    if (!item_in) return out_index;
    item = (I021_220 *) item_in;
    msg_out[out_index++] = item->raw;
    if (get_I021_220_WS(item))
    {
        msg_out[out_index++] = item->ext1.WS[0];
        msg_out[out_index++] = item->ext1.WS[1];
        if (get_I021_220_WD(item))
        {
            msg_out[out_index++] = item->ext2.WD[0];
            msg_out[out_index++] = item->ext2.WD[1];
            if (get_I021_220_TEMP(item))
            {
                msg_out[out_index++] = item->ext3.TEMP[0];
                msg_out[out_index++] = item->ext3.TEMP[1];
                if (get_I021_220_TRB(item))
                {
                    msg_out[out_index++] = item->ext4.TRB;
                }
            }
        }
    }
    return out_index;
}

uint16_t decode_I021_220(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_220 *item;
    if (!item_out) return in_index;
    item = (I021_220 *) item_out;
    item->raw = msg_in[in_index++];
    if (get_I021_220_WS(item))
    {
        item->ext1.WS[0] = msg_in[in_index++];
        item->ext1.WS[1] = msg_in[in_index++];
        if (get_I021_220_WD(item))
        {
            item->ext2.WD[0] = msg_in[in_index++];
            item->ext2.WD[1] = msg_in[in_index++];
            if (get_I021_220_TEMP(item))
            {
                item->ext3.TEMP[0] = msg_in[in_index++];
                item->ext3.TEMP[1] = msg_in[in_index++];
                if (get_I021_220_TRB(item))
                {
                    item->ext4.TRB = msg_in[in_index++];
                }
            }
        }
    }
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_220(const I021_220 * item)
{
    printf("I021/220 - Met Information\n");
    printf("- WS = %d\n", get_I021_220_WS(item));
    printf("- WD = %d\n", get_I021_220_WD(item));
    printf("- TEMP = %d\n", get_I021_220_TEMP(item));
    printf("- TRB = %d\n", get_I021_220_TRB(item));
    printf("- FX = %d\n", get_I021_220_FX(item));

    if (get_I021_220_WS(item))
        printf("-- EXT1_WS = %d\n", get_I021_220_EXT1_WS(&(item->ext1)));
    if (get_I021_220_WD(item))
        printf("-- EXT2_WD = %d\n", get_I021_220_EXT2_WD(&(item->ext2)));
    if (get_I021_220_TEMP(item))
        printf("-- EXT3_TEMP = %f\n", get_I021_220_EXT3_TEMP(&(item->ext3)));
    if (get_I021_220_TRB(item))
        printf("-- EXT4_TRB = %d\n", get_I021_220_EXT4_TRB(&(item->ext4)));
}

