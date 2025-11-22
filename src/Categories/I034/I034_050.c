/**
 * @file I034_050.c
 * @brief Implementation of I041/000 - System Configuration and Status
 */

#include <stdio.h>
#include <string.h>

#include "Aux_Funcs/aux_funcs.h"
#include "Common/constants.h"

#include "Categories/I034/I034_050.h"

/*****************************************************************************
 * Getters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

uint8_t get_I034_050_COM(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 7);
}

uint8_t get_I034_050_PSR(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 4);
}

uint8_t get_I034_050_SSR(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 3);
}

uint8_t get_I034_050_MDS(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 2);
}

uint8_t get_I034_050_FX(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* =============================== SUBFIELD 1 =============================== */

uint8_t get_I034_050_EXT1_NOGO(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext1.raw, MASK_01_BITS, 7);
}

uint8_t get_I034_050_EXT1_RDPC(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext1.raw, MASK_01_BITS, 6);
}

uint8_t get_I034_050_EXT1_RDPR(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext1.raw, MASK_01_BITS, 5);
}

uint8_t get_I034_050_EXT1_OVLRDP(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext1.raw, MASK_01_BITS, 4);
}

uint8_t get_I034_050_EXT1_OVLXMT(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext1.raw, MASK_01_BITS, 3);
}

uint8_t get_I034_050_EXT1_MSC(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext1.raw, MASK_01_BITS, 2);
}

uint8_t get_I034_050_EXT1_TSV(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext1.raw, MASK_01_BITS, 1);
}

/* =============================== SUBFIELD 4 =============================== */

uint8_t get_I034_050_EXT4_ANT(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext4.raw, MASK_01_BITS, 7);
}

uint8_t get_I034_050_EXT4_CHAB(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext4.raw, MASK_02_BITS, 5);
}

uint8_t get_I034_050_EXT4_OVL(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext4.raw, MASK_01_BITS, 4);
}

uint8_t get_I034_050_EXT4_MSC(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext4.raw, MASK_01_BITS, 3);
}

/* =============================== SUBFIELD 5 =============================== */

uint8_t get_I034_050_EXT5_ANT(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext5.raw, MASK_01_BITS, 7);
}

uint8_t get_I034_050_EXT5_CHAB(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext5.raw, MASK_02_BITS, 5);
}

uint8_t get_I034_050_EXT5_OVL(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext5.raw, MASK_01_BITS, 4);
}

uint8_t get_I034_050_EXT5_MSC(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext5.raw, MASK_01_BITS, 3);
}

/* =============================== SUBFIELD 6 =============================== */

uint8_t get_I034_050_EXT6_ANT(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(item->ext6.raw, MASK_01_BITS, 7);
}

uint8_t get_I034_050_EXT6_CHAB(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(item->ext6.raw, MASK_02_BITS, 5);
}

uint8_t get_I034_050_EXT6_OVLSUR(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(item->ext6.raw, MASK_01_BITS, 4);
}

uint8_t get_I034_050_EXT6_MSC(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(item->ext6.raw, MASK_01_BITS, 3);
}

uint8_t get_I034_050_EXT6_SCF(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(item->ext6.raw, MASK_01_BITS, 2);
}

uint8_t get_I034_050_EXT6_DLF(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(item->ext6.raw, MASK_01_BITS, 1);
}

uint8_t get_I034_050_EXT6_OVLSCF(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(item->ext6.raw, MASK_01_BITS, 0);
}

uint8_t get_I034_050_EXT6_OVLDLF(const I034_050 *item)
{
    if (!item) return 0;
    return read_bits(&item->ext6.raw[1], MASK_01_BITS, 7);
}

/******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

void set_I034_050_COM(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 7, val);
}

void set_I034_050_PSR(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 4, val);
}

void set_I034_050_SSR(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 3, val);
}

void set_I034_050_MDS(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 2, val);
}

void set_I034_050_FX(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, val);
}

/* =============================== SUBFIELD 1 =============================== */

void set_I034_050_EXT1_NOGO(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext1.raw, MASK_01_BITS, 7, val);
}

void set_I034_050_EXT1_RDPC(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext1.raw, MASK_01_BITS, 6, val);
}

void set_I034_050_EXT1_RDPR(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext1.raw, MASK_01_BITS, 5, val);
}

void set_I034_050_EXT1_OVLRDP(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext1.raw, MASK_01_BITS, 4, val);
}

void set_I034_050_EXT1_OVLXMT(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext1.raw, MASK_01_BITS, 3, val);
}

void set_I034_050_EXT1_MSC(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext1.raw, MASK_01_BITS, 2, val);
}

void set_I034_050_EXT1_TSV(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext1.raw, MASK_01_BITS, 1, val);
}

/* =============================== SUBFIELD 4 =============================== */

void set_I034_050_EXT4_ANT(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext4.raw, MASK_01_BITS, 7, val);
}

void set_I034_050_EXT4_CHAB(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext4.raw, MASK_02_BITS, 5, val);
}

void set_I034_050_EXT4_OVL(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext4.raw, MASK_01_BITS, 4, val);
}

void set_I034_050_EXT4_MSC(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext4.raw, MASK_01_BITS, 3, val);
}

/* =============================== SUBFIELD 5 =============================== */

void set_I034_050_EXT5_ANT(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext5.raw, MASK_01_BITS, 7, val);
}

void set_I034_050_EXT5_CHAB(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext5.raw, MASK_02_BITS, 5, val);
}

void set_I034_050_EXT5_OVL(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext5.raw, MASK_01_BITS, 4, val);
}

void set_I034_050_EXT5_MSC(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext5.raw, MASK_01_BITS, 3, val);
}

/* =============================== SUBFIELD 6 =============================== */

void set_I034_050_EXT6_ANT(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(item->ext6.raw, MASK_01_BITS, 7, val);
}

void set_I034_050_EXT6_CHAB(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(item->ext6.raw, MASK_02_BITS, 5, val);
}

void set_I034_050_EXT6_OVLSUR(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(item->ext6.raw, MASK_01_BITS, 4, val);
}

void set_I034_050_EXT6_MSC(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(item->ext6.raw, MASK_01_BITS, 3, val);
}

void set_I034_050_EXT6_SCF(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(item->ext6.raw, MASK_01_BITS, 2, val);
}

void set_I034_050_EXT6_DLF(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(item->ext6.raw, MASK_01_BITS, 1, val);
}

void set_I034_050_EXT6_OVLSCF(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(item->ext6.raw, MASK_01_BITS, 0, val);
}

void set_I034_050_EXT6_OVLDLF(I034_050 *item, uint8_t val)
{
    if (!item) return;
    write_bits(&item->ext6.raw[1], MASK_01_BITS, 7, val);
}

/*****************************************************************************
 * Encoding and Decoding
 ******************************************************************************/

uint16_t encode_I034_050(void *item_in, unsigned char *msg_out, uint16_t out_index)
{
    I034_050 *item;

    if (!item_in || !msg_out) return out_index;

    item = (I034_050 *)item_in;

    /* Write main octet */
    msg_out[out_index++] = item->raw;

    /* If COM present, write ext1 */
    if (get_I034_050_COM(item)) msg_out[out_index++] = item->ext1.raw;

    /* If PSR present, write ext4 */
    if (get_I034_050_PSR(item)) msg_out[out_index++] = item->ext4.raw;

    /* If SSR present, write ext5 */
    if (get_I034_050_SSR(item)) msg_out[out_index++] = item->ext5.raw;

    /* If MDS present, write ext6 (2 octets) */
    if (get_I034_050_MDS(item))
    {
        msg_out[out_index++] = item->ext6.raw[0];
        msg_out[out_index++] = item->ext6.raw[1];
    }
    return out_index;
}

uint16_t decode_I034_050(void *item_out, const unsigned char *msg_in, uint16_t in_index)
{
    I034_050 *item;

    if (!item_out || !msg_in) return in_index;
    item = (I034_050 *)item_out;

    /* Read main octet */
    item->raw = msg_in[in_index++];

    /* If COM present, read ext1 */
    if (get_I034_050_COM(item)) item->ext1.raw = msg_in[in_index++];

    /* If PSR present, read ext4 */
    if (get_I034_050_PSR(item)) item->ext4.raw = msg_in[in_index++];

    /* If SSR present, read ext5 */
    if (get_I034_050_SSR(item)) item->ext5.raw = msg_in[in_index++];

    /* If MDS present, read ext6 (2 octets) */
    if (get_I034_050_MDS(item))
    {
        item->ext6.raw[0] = msg_in[in_index++];
        item->ext6.raw[1] = msg_in[in_index++];
    }

    return in_index;
}

/*****************************************************************************
 * Print
 ******************************************************************************/

void print_I034_050(const I034_050 *item)
{
    printf("I034/050 - System Configuration and Status\n");
    if (!item)
    {
        printf("I034/050: <null>\n");
        return;
    }

    printf("- COM = %u\n", get_I034_050_COM(item));
    if (get_I034_050_COM(item))
    {
        printf("-- NOGO = %u\n", get_I034_050_EXT1_NOGO(item));
        printf("-- RDPC = %u\n", get_I034_050_EXT1_RDPC(item));
        printf("-- RDPR = %u\n", get_I034_050_EXT1_RDPR(item));
        printf("-- OVLRDP = %u\n", get_I034_050_EXT1_OVLRDP(item));
        printf("-- OVLXMT = %u\n", get_I034_050_EXT1_OVLXMT(item));
        printf("-- MSC = %u\n", get_I034_050_EXT1_MSC(item));
        printf("-- TSV = %u\n",get_I034_050_EXT1_TSV(item));
    }

    printf("- PSR = %u\n", get_I034_050_PSR(item));
    if (get_I034_050_PSR(item))
    {
        printf("-- ANT = %u\n", get_I034_050_EXT4_ANT(item));
        printf("-- CHAB = %u\n", get_I034_050_EXT4_CHAB(item));
        printf("-- OVL = %u\n", get_I034_050_EXT4_OVL(item));
        printf("-- MSC = %u\n", get_I034_050_EXT4_MSC(item));
    }

    printf("- SSR = %u\n", get_I034_050_SSR(item));
    if (get_I034_050_SSR(item))
    {
        printf("-- ANT = %u\n", get_I034_050_EXT5_ANT(item));
        printf("-- CHAB = %u\n", get_I034_050_EXT5_CHAB(item));
        printf("-- OVL = %u\n", get_I034_050_EXT5_OVL(item));
        printf("-- MSC = %u\n", get_I034_050_EXT5_MSC(item));
    }

    printf("- MDS = %u\nn", get_I034_050_MDS(item));
    if (get_I034_050_MDS(item))
    {
        printf("-- ANT = %u\n", get_I034_050_EXT6_ANT(item));
        printf("-- CHAB = %u\n", get_I034_050_EXT6_CHAB(item));
        printf("-- OVLSUR = %u\n", get_I034_050_EXT6_OVLSUR(item));
        printf("-- MSC = %u\n", get_I034_050_EXT6_MSC(item));
        printf("-- SCF = %u\n", get_I034_050_EXT6_SCF(item));
        printf("-- DLF = %u\n", get_I034_050_EXT6_DLF(item));
        printf("-- OVLSCF = %u\n", get_I034_050_EXT6_OVLSCF(item));
        printf("-- OVLDLF = %u\n", get_I034_050_EXT6_OVLDLF(item));
    }
}
