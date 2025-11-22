/**
 * @file I034_060.c
 * @brief Implementation of I060/000 - System Configuration and Status
 */

#include <stdio.h>

#include "Aux_Funcs/aux_funcs.h"
#include "Common/constants.h"

#include "Categories/I034/I034_060.h"

/*****************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

uint8_t get_I034_060_COM(const I034_060 *item)
{
    if(!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 7);
}

uint8_t get_I034_060_PSR(const I034_060 *item)
{
    if(!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 4);
}

uint8_t get_I034_060_SSR(const I034_060 *item)
{
    if(!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 3);
}

uint8_t get_I034_060_MDS(const I034_060 *item)
{
    if(!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 2);
}

uint8_t get_I034_060_FX(const I034_060 *item)
{
    if(!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* ============================== SUBFIELD #1 ============================== */

uint8_t get_I034_060_EXT1_REDRDP(const I034_060 *item)
{
    if(!item) return 0;
    return read_bits(&item->ext1.raw, MASK_03_BITS, 4);
}

uint8_t get_I034_060_EXT1_REDXMT(const I034_060 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext1.raw, MASK_03_BITS, 1);
}

/* ============================== SUBFIELD #4 ============================== */

uint8_t get_I034_060_EXT4_POL(const I034_060 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext4.raw, MASK_01_BITS, 7);
}

uint8_t get_I034_060_EXT4_REDRAD(const I034_060 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext4.raw, MASK_03_BITS, 4);
}

uint8_t get_I034_060_EXT4_STC(const I034_060 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext4.raw, MASK_02_BITS, 2);
}

/* ============================== SUBFIELD #5 ============================== */

uint8_t get_I034_060_EXT5_REDRAD(const I034_060 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext5.raw, MASK_03_BITS, 5);
}

/* ============================== SUBFIELD #6 ============================== */

uint8_t get_I034_060_EXT6_REDRAD(const I034_060 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext6.raw, MASK_03_BITS, 5);
}

uint8_t get_I034_060_EXT6_CLU(const I034_060 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext6.raw, MASK_01_BITS, 4);
}

/*****************************************************************************
 * Setters
 ******************************************************************************/

 /* =============================== MAIN BYTE =============================== */

void set_I034_060_COM(I034_060 *item, uint8_t com)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 7, com);
}

void set_I034_060_PSR(I034_060 *item, uint8_t psr)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 4, psr);
}

void set_I034_060_SSR(I034_060 *item, uint8_t ssr)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 3, ssr);
}

void set_I034_060_MDS(I034_060 *item, uint8_t mds)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 2, mds);
}

void set_I034_060_FX(I034_060 *item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* ============================== SUBFIELD #1 ============================== */

void set_I034_060_EXT1_REDRDP(I034_060 *item, uint8_t redrdp)
{
    if (!item) return;
    write_bits(&item->ext1.raw, MASK_03_BITS, 4, redrdp);
}

void set_I034_060_EXT1_REDXMT(I034_060 *item, uint8_t redxmt)
{
    if (!item) return;
    write_bits(&item->ext1.raw, MASK_03_BITS, 1, redxmt);
}

/* ============================== SUBFIELD #4 ============================== */

void set_I034_060_EXT4_POL(I034_060 *item, uint8_t pol)
{
    if(!item) return;
    write_bits(&item->ext4.raw, MASK_01_BITS, 7, pol);
}

void set_I034_060_EXT4_REDRAD(I034_060 *item, uint8_t redrad)
{
    if (!item) return;
    write_bits(&item->ext4.raw, MASK_03_BITS, 4, redrad);
}

void set_I034_060_EXT4_STC(I034_060 *item, uint8_t stc)
{
    if (!item) return;
    write_bits(&item->ext4.raw, MASK_02_BITS, 2, stc);
}

/* ============================== SUBFIELD #5 ============================== */

void set_I034_060_EXT5_REDRAD(I034_060 *item, uint8_t redrad)
{
    if (!item) return;
    write_bits(&item->ext5.raw, MASK_03_BITS, 5, redrad);
}

/* ============================== SUBFIELD #6 ============================== */

void set_I034_060_EXT6_REDRAD(I034_060 *item, uint8_t redrad)
{
    if (!item) return;
    write_bits(&item->ext6.raw, MASK_03_BITS, 5, redrad);
}

void set_I034_060_EXT6_CLU(I034_060 *item, uint8_t clu)
{
    if (!item) return;
    write_bits(&item->ext6.raw, MASK_01_BITS, 4, clu);
}

/*****************************************************************************
 * Encoding and Decoding
 ******************************************************************************/

uint16_t encode_I034_060(void *item_in, unsigned char *msg_out, uint16_t out_index)
{
    I034_060 *item;

    if (!item_in || !msg_out) return out_index;

    item = (I034_060 *)item_in;
    
    /* Write main octet */
    msg_out[out_index++] = item->raw;

    /* If COM present, write ext1 */
    if (get_I034_060_COM(item)) msg_out[out_index++] = item->ext1.raw;

    /* If PSR present, write ext4 */
    if (get_I034_060_PSR(item)) msg_out[out_index++] = item->ext4.raw;

    /* If SSR present, write ext5 */
    if (get_I034_060_SSR(item)) msg_out[out_index++] = item->ext5.raw;

    /* If MDS present, write ext6 (2 octets) */
    if (get_I034_060_MDS(item)) msg_out[out_index++] = item->ext6.raw;

    return out_index;
}
           
uint16_t decode_I034_060(void *item_out, const unsigned char *msg_in, uint16_t in_index)
{
    I034_060 *item;

    if (!item_out || !msg_in) return in_index;

    item = (I034_060 *)item_out;

    /* Read main octet */
    item->raw = msg_in[in_index++];

    /* If COM present, read ext1 */
    if (get_I034_060_COM(item)) item->ext1.raw = msg_in[in_index++];

    /* If PSR present, read ext4 */
    if (get_I034_060_PSR(item)) item->ext4.raw = msg_in[in_index++];

    /* If SSR present, read ext5 */
    if (get_I034_060_SSR(item)) item->ext5.raw = msg_in[in_index++];

    /* If MDS present, read ext6 (2 octets) */
    if (get_I034_060_MDS(item)) item->ext6.raw = msg_in[in_index++];

    return in_index;
}

/*****************************************************************************
 * Print
 ******************************************************************************/

void print_I034_060(const I034_060 *item)
{
    printf("I034/060 - System Configuration and Status:\n");
    if (!item)
    {
        printf("I034/060: <null>\n");
        return;
    }

    printf("- COM: %u\n", get_I034_060_COM(item));
    if (get_I034_060_COM(item))
    {
        printf("-- REDRDP: %u\n", get_I034_060_EXT1_REDRDP(item));
        printf("-- REDXMT: %u\n", get_I034_060_EXT1_REDXMT(item));
    }

    printf("- PSR: %u\n", get_I034_060_PSR(item));
    if (get_I034_060_PSR(item))
    {
        printf("-- POL: %u\n", get_I034_060_EXT4_POL(item));
        printf("-- REDRAD: %u\n", get_I034_060_EXT4_REDRAD(item));
        printf("-- STC: %u\n", get_I034_060_EXT4_STC(item));
    }

    printf("- SSR: %u\n", get_I034_060_SSR(item));
    if (get_I034_060_SSR(item))
    {
        printf("-- REDRAD: %u\n", get_I034_060_EXT5_REDRAD(item));
    }

    printf("- MDS: %u\n", get_I034_060_MDS(item));
    if (get_I034_060_MDS(item))
    {
        printf("-- REDRAD: %u\n", get_I034_060_EXT6_REDRAD(item));
        printf("-- CLU: %u\n", get_I034_060_EXT6_CLU(item));
    }
}