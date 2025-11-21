/**
 * @file I021_074.c
 * @brief Implementation of the Category 21 Item 074 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_074.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_074_FSI(const I021_074 * item)
{
    if (!item) return 0;
    return read_bits(item->raw, MASK_02_BITS, 6);
}

double get_I021_074_TMRP_HP(const I021_074 * item)
{
    return (read_unsigned_32bit(item->raw) & MASK_30_BITS) * I021_074_LSB_TMRP_HP;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

 void set_I021_074_FSI(I021_074 * item, uint8_t fsi)
 {
    if (!item) return;
    write_bits(item->raw, MASK_02_BITS, 6, fsi);
}

void set_I021_074_TMRP_HP(I021_074 * item, double tmrp_hp_seconds)
{
    uint32_t tmrp_hp_raw = 0;
    if (!item) return;
    /* Turn to raw format and round to nearest unit if bigger than 0 */
    if (tmrp_hp_seconds > 0)
        tmrp_hp_raw = (uint32_t) (tmrp_hp_seconds / I021_074_LSB_TMRP_HP + 0.5);

    /* Write top 6 bits (without replacing the FSI value) */
    write_bits(&item->raw[0], MASK_06_BITS, 0, tmrp_hp_raw);
    /* Write the remnaining 24 bits */
    write_unsigned_24bit(&item->raw[1], tmrp_hp_raw & MASK_24_BITS);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_074(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_074 * item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_074 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 4);
    return out_index + 4;
}

uint16_t decode_I021_074(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_074 * item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_074 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 4);
    return in_index + 4;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_074(const I021_074 * item)
{
    printf("I021/074 - Time of Message Reception of Position-High Precision\n");
    if (!item)
    {
        printf("I021/074: <null>\n");
        return;
    }
    printf("- TMRP_HP_FSI = %d\n", get_I021_074_FSI(item));
    printf("- TMRP_HP (seconds) = %f\n", get_I021_074_TMRP_HP(item));
}
