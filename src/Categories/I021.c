/**
 * @file I021.c
 * @brief Implementation of I021 functions to read FSPEC and encode/decode
 *        Category 021 messages
 */
#include <string.h>

#include "Aux_Funcs/aux_funcs.h"
#include "Categories/I021.h"

/*******************************************************************************
 * Private macros
 ******************************************************************************/

#define I021_MIN_FSPEC_ITEM     I021_FSPEC_ITEM010
#define I021_MAX_FSPEC_ITEM     I021_FSPEC_RE

#define I021_MIN_FSPEC_FX       I021_FSPEC_FX_1
#define I021_MAX_FSPEC_FX       I021_FSPEC_FX_7

/*******************************************************************************
 * Private structures/types
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

typedef uint16_t (*encode_f_t)(void * item_in, unsigned char * msg_out, uint16_t out_index);
typedef uint16_t (*decode_f_t)(void * item_out, const unsigned char * msg_in,  uint16_t in_index);

typedef struct LT_Entry {
    uint8_t  byte;
    uint8_t  pos;
    encode_f_t encode; 
    decode_f_t decode; 
} LT_Entry;

const LT_Entry lookup_table[I021_MAX_FSPEC_ITEM+1] = {
    [I021_FSPEC_ITEM010] = {0, 7, encode_I021_010, decode_I021_010},
    [I021_FSPEC_ITEM040] = {0, 6, encode_I021_040, decode_I021_040},
    [I021_FSPEC_ITEM161] = {0, 5, encode_I021_161, decode_I021_161},
    [I021_FSPEC_ITEM015] = {0, 4, encode_I021_015, decode_I021_015},
    [I021_FSPEC_ITEM071] = {0, 3, encode_I021_071, decode_I021_071},
    [I021_FSPEC_ITEM130] = {0, 2, encode_I021_130, decode_I021_130},
    [I021_FSPEC_ITEM131] = {0, 1, encode_I021_131, decode_I021_131},

    [I021_FSPEC_ITEM072] = {1, 7, encode_I021_072, decode_I021_072},
    [I021_FSPEC_ITEM150] = {1, 6, encode_I021_150, decode_I021_150},
    [I021_FSPEC_ITEM151] = {1, 5, encode_I021_151, decode_I021_151},
    [I021_FSPEC_ITEM080] = {1, 4, encode_I021_080, decode_I021_080},
    [I021_FSPEC_ITEM073] = {1, 3, encode_I021_073, decode_I021_073},
    [I021_FSPEC_ITEM074] = {1, 2, encode_I021_074, decode_I021_074},
    [I021_FSPEC_ITEM075] = {1, 1, encode_I021_075, decode_I021_075},

    [I021_FSPEC_ITEM076] = {2, 7, encode_I021_076, decode_I021_076},
    [I021_FSPEC_ITEM140] = {2, 6, encode_I021_140, decode_I021_140},
    [I021_FSPEC_ITEM090] = {2, 5, encode_I021_090, decode_I021_090},
    [I021_FSPEC_ITEM210] = {2, 4, encode_I021_210, decode_I021_210},
    [I021_FSPEC_ITEM070] = {2, 3, encode_I021_070, decode_I021_070},
    [I021_FSPEC_ITEM230] = {2, 2, encode_I021_230, decode_I021_230},
    [I021_FSPEC_ITEM145] = {2, 1, encode_I021_145, decode_I021_145},

    [I021_FSPEC_ITEM152] = {3, 7, encode_I021_152, decode_I021_152},
    [I021_FSPEC_ITEM200] = {3, 6, encode_I021_200, decode_I021_200},
    [I021_FSPEC_ITEM155] = {3, 5, encode_I021_155, decode_I021_155},
    [I021_FSPEC_ITEM157] = {3, 4, encode_I021_157, decode_I021_157},
    [I021_FSPEC_ITEM160] = {3, 3, encode_I021_160, decode_I021_160},
    [I021_FSPEC_ITEM165] = {3, 2, encode_I021_165, decode_I021_165},
    [I021_FSPEC_ITEM077] = {3, 1, encode_I021_077, decode_I021_077},

    [I021_FSPEC_ITEM170] = {4, 7, encode_I021_170, decode_I021_170},
    [I021_FSPEC_ITEM020] = {4, 6, encode_I021_020, decode_I021_020},
    [I021_FSPEC_ITEM220] = {4, 5, encode_I021_220, decode_I021_220},
    [I021_FSPEC_ITEM146] = {4, 4, encode_I021_146, decode_I021_146},
    [I021_FSPEC_ITEM148] = {4, 3, encode_I021_148, decode_I021_148},
    [I021_FSPEC_ITEM110] = {4, 2, encode_I021_110, decode_I021_110},
    [I021_FSPEC_ITEM016] = {4, 1, encode_I021_016, decode_I021_016},

    [I021_FSPEC_ITEM008] = {5, 7, encode_I021_008, decode_I021_008},
    [I021_FSPEC_ITEM271] = {5, 6, encode_I021_271, decode_I021_271},
    [I021_FSPEC_ITEM132] = {5, 5, encode_I021_132, decode_I021_132},
    [I021_FSPEC_ITEM250] = {5, 4, encode_I021_250, decode_I021_250},
    [I021_FSPEC_ITEM260] = {5, 3, encode_I021_260, decode_I021_260},
    [I021_FSPEC_ITEM400] = {5, 2, encode_I021_400, decode_I021_400},
    [I021_FSPEC_ITEM295] = {5, 1, encode_I021_295, decode_I021_295},

    [I021_FSPEC_RE]      = {6, 7, encode_I021_RE , decode_I021_RE }
};

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * FSPEC Getters
 ******************************************************************************/

uint8_t has_I021_FSPEC_item(const I021_FSPEC * fspec, uint8_t item_number)
{
    uint8_t value = -1;
    LT_Entry item_lt_data;
    if(item_number <= I021_MAX_FSPEC_ITEM)
    {
        item_lt_data = lookup_table[item_number];
        value = (fspec->raw[item_lt_data.byte] >> item_lt_data.pos) & MASK_01_BITS;
    }
    return value;
}

uint8_t has_I021_FSPEC_fx(const I021_FSPEC * fspec, uint8_t fx_number)
{
    uint8_t value = -1;
    if (IS_IN_RANGE(I021_MIN_FSPEC_FX, fx_number, I021_MAX_FSPEC_FX))
        value = (fspec->raw[fx_number-1]) & MASK_01_BITS;
    return value;
}

uint8_t get_I021_FSPEC_byte(const I021_FSPEC * fspec, uint8_t n_byte)
{
    uint8_t byte = 0;
    if (n_byte < (I021_FSPEC_FX_7)) byte = fspec->raw[n_byte];
    return byte;
}

/*******************************************************************************
 * FSPEC Setters
 ******************************************************************************/

void set_I021_FSPEC_item(I021_FSPEC * fspec, uint8_t item_number, uint8_t value)
{
    LT_Entry item_lt_data;
    if(item_number <= I021_MAX_FSPEC_ITEM)
    {
        item_lt_data = lookup_table[item_number];
        write_bits(&fspec->raw[item_lt_data.byte], MASK_01_BITS, item_lt_data.pos, value);
    }
}

void set_I021_FSPEC_fx(I021_FSPEC * fspec, uint8_t fx_number, uint8_t value)
{
    if (IS_IN_RANGE(I021_MIN_FSPEC_FX, fx_number, I021_MAX_FSPEC_FX))
        write_bits(&fspec->raw[fx_number - 1], MASK_01_BITS, 0, value);
}

void set_I021_FSPEC_byte(I021_FSPEC * fspec, uint8_t n_byte, uint8_t byte)
{
    if (n_byte < I021_MAX_FSPEC_FX)
        fspec->raw[n_byte] = byte;
}

/*******************************************************************************
 * Encode / Decode functions
 ******************************************************************************/

uint16_t encode_I021(const I021 * item_in, unsigned char * msg_out)
{
    uint16_t len, out_index, item_number, fx_number;

    fx_number = 0;
    out_index = 0;

    msg_out[out_index++] = get_Header_CAT(&(item_in->header));
    len = get_Header_LEN(&(item_in->header));
    memcpy(&msg_out[out_index], &len, 2);

    /* First byte of the FSPEC */
    msg_out[out_index++] = get_I021_FSPEC_byte(&(item_in->fspec), fx_number);

    /* Read subsequent bytes only if corresponding FX is active */
    for (fx_number = 1; fx_number < I021_FSPEC_MAX_OCTETS; fx_number++)
        if (has_I021_FSPEC_fx(&(item_in->fspec), fx_number))
            msg_out[out_index++] = get_I021_FSPEC_byte(&(item_in->fspec), fx_number);
        else
            break;

    /* Encode each item based on the FSPEC contents */
    for (item_number = 0, fx_number = 1; item_number <= I021_MAX_FSPEC_ITEM; item_number++)
    {
        /* If item present, use its encode function from the lookup table */
        if (has_I021_FSPEC_item(&(item_in->fspec), item_number))
            out_index = lookup_table[item_number].encode((void *) item_in, msg_out, out_index);
        /* Stop decoding if FX says there are no more items */
        if (((item_number+1)%7 == 0) && has_I021_FSPEC_fx(&(item_in->fspec), fx_number++) == 0)
            break;
    }

    /* The "Special Purpose Field" (SPI) must be encoded by the user */

    return out_index;
}

uint16_t decode_I021(const unsigned char * msg_in, I021 * item_out)
{
    uint16_t in_index, item_number, fx_number;

    in_index = 0; /* Pointer to next byte to read from "msg_in" */

    /* Extract message header (CAT and LEN) */
    set_Header_CAT(&(item_out->header), msg_in[in_index++]);
    set_Header_LEN(&(item_out->header), read_unsigned_16bit(&msg_in[in_index]));
    in_index += 2;

    /* Write first byte of FSPEC */
    set_I021_FSPEC_byte(&(item_out->fspec), 0, msg_in[in_index++]);

    /* Write subsequent bytes only if corresponding FX is active */
    for (fx_number = 1; fx_number < I021_FSPEC_MAX_OCTETS; fx_number++)
    {
        /* Check presence of next FSPEC byte, or exit if finished FSPEC */
        if (has_I021_FSPEC_fx(&(item_out->fspec), fx_number))
            set_I021_FSPEC_byte(&(item_out->fspec), fx_number, msg_in[in_index++]);
        else
            break;
    }

    /* Decode each item if the FSPEC says its present */
    for (item_number = 0, fx_number = 1; item_number <= I021_MAX_FSPEC_ITEM; item_number++)
    {
        /* If item present, use its decode function from the lookup table */
        if (has_I021_FSPEC_item(&(item_out->fspec), item_number))
            lookup_table[item_number].decode((void *) item_out, msg_in, in_index);
        /* Stop decoding if FX says there are no more items */
        if (((item_number+1)%7 == 0) && has_I021_FSPEC_fx(&(item_out->fspec), fx_number++) == 0)
            break;
    }

    /* The "Special Purpose Field" (SPI) must be decoded by the user */

    return in_index;
}
