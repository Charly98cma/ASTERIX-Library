/**
 * @file I021_020.c
 * @brief Implementation of the Category 21 Item 020 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_020.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_020_ECAT_MIN I021_020_ECAT_NO_INFO
#define I021_020_ECAT_MAX I021_020_ECAT_LINE_OBS

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_020_ECAT(const I021_020 * item)
{
    if (!item) return 0;
    return read_unsigned_8bit(&item->raw);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_020_ECAT(I021_020 * item, uint8_t ecat)
{
    if (!item) return;
    /* Value out of range, set to default */
    if (ecat > I021_020_ECAT_MAX)
        ecat = I021_020_ECAT_NO_INFO;
    write_unsigned_8bit(&item->raw, ecat);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_020(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_020 * item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_020 *) item_in;
    msg_out[out_index++] = item->raw;
    return out_index;
}

uint16_t decode_I021_020(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_020 * item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_020 *) item_out;
    item->raw = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_020(const I021_020 *item)
{
    printf("I021/020 - Emitter Category\n");
    if (!item)
    {
        printf("I021/020: <null>\n");
        return;
    }
    printf("- ECAT: %d\n\n", get_I021_020_ECAT(item));
}
