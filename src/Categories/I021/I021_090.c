/**
 * @file I021_090.c
 * @brief Implementation of the Category 21 Item 090 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_090.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN  BYTE =============================== */

uint8_t get_I021_090_NUCr_NACv(const I021_090 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_03_BITS, 5);
}

uint8_t get_I021_090_NUCp_NIC(const I021_090 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_04_BITS, 1);
}

uint8_t get_I021_090_FX(const I021_090 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* ============================= FIRST EXTENSION ============================ */

uint8_t get_I021_090_EXT1_NICbaro(const I021_090_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 7);
}

uint8_t get_I021_090_EXT1_SIL(const I021_090_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_02_BITS, 5);
}

uint8_t get_I021_090_EXT1_NACp(const I021_090_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_04_BITS, 1);
}

uint8_t get_I021_090_EXT1_FX(const I021_090_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* ============================ SECOND EXTENSION ============================ */

uint8_t get_I021_090_EXT2_SILS(const I021_090_EXT2 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 5);
}

uint8_t get_I021_090_EXT2_SDA(const I021_090_EXT2 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_02_BITS, 3);
}

uint8_t get_I021_090_EXT2_GVA(const I021_090_EXT2 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_02_BITS, 1);
}

uint8_t get_I021_090_EXT2_FX(const I021_090_EXT2 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* ============================ THIRD EXTENSION ============================  */

uint8_t get_I021_090_EXT3_PIC(const I021_090_EXT3 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_04_BITS, 4);
}

#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
uint8_t get_I021_090_EXT3_SRC(const I021_090_EXT3 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 3);
}
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */

uint8_t get_I021_090_EXT3_FX(const I021_090_EXT3 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
/* ============================ FOURTH EXTENSION ===========================  */

uint8_t get_I021_090_EXT4_VALSTATE(const I021_090_EXT4 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_03_BITS, 3);
}

uint8_t get_I021_090_EXT4_VD(const I021_090_EXT4 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 2);
}

uint8_t get_I021_090_EXT4_VQ(const I021_090_EXT4 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 1);
}

uint8_t get_I021_090_EXT4_FX(const I021_090_EXT4 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* ============================ FIFTH EXTENSION ============================  */

uint16_t get_I021_090_EXT5_VALDISTP1(const I021_090_EXT5 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_07_BITS, 1) * I021_090_EXT5_LSB_VAL_DIST_P1;
}

uint8_t get_I021_090_EXT5_FX(const I021_090_EXT5 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* ============================ SIXTH EXTENSION ============================  */

uint8_t get_I021_090_EXT6_VALDISTP2(const I021_090_EXT6 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_07_BITS, 1) * I021_090_EXT6_LSB_VAL_DIST_P2;
}

uint8_t get_I021_090_EXT6_FX(const I021_090_EXT6 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* =========================== SEVENTH EXTENSION ===========================  */

uint16_t get_I021_090_EXT7_VALDISTQUALP1(const I021_090_EXT7 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_07_BITS, 1) * I021_090_EXT7_LSB_VAL_DIST_QUAL_P1;
}

uint8_t get_I021_090_EXT7_FX(const I021_090_EXT7 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* =========================== EIGHT EXTENSION ===========================  */

uint16_t get_I021_090_EXT8_VALDISTQUALP2(const I021_090_EXT8 *item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_07_BITS, 1) * I021_090_EXT8_LSB_VAL_DIST_QUAL_P2;
}

uint8_t get_I021_090_EXT8_FX(const I021_090_EXT8 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

void set_I021_090_NUCrNACv(I021_090 * item, uint8_t nucr_nacv)
{
    if (!item) return;
    write_bits(&item->raw, MASK_03_BITS, 5, nucr_nacv);
}

void set_I021_090_NUCp_NIC(I021_090 * item, uint8_t nucp_nic)
{
    if (!item) return;
    write_bits(&item->raw, MASK_04_BITS, 1, nucp_nic);
}

void set_I021_090_FX(I021_090 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* ============================= FIRST EXTENSION ============================ */

void set_I021_090_EXT1_NICbaro(I021_090_EXT1 * item, uint8_t nic_baro)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 7, nic_baro);
}

void set_I021_090_EXT1_SIL(I021_090_EXT1 * item, uint8_t sil)
{
    if (!item) return;
    write_bits(&item->raw, MASK_02_BITS, 5, sil);
}

void set_I021_090_EXT1_NACp(I021_090_EXT1 * item, uint8_t nacp)
{
    if (!item) return;
    write_bits(&item->raw, MASK_04_BITS, 1, nacp);
}

void set_I021_090_EXT1_FX(I021_090_EXT1 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* ============================ SECOND EXTENSION ============================ */

void set_I021_090_EXT2_SILS(I021_090_EXT2 * item, uint8_t sils)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 5, sils);
}

void set_I021_090_EXT2_SDA(I021_090_EXT2 * item, uint8_t sda)
{
    if (!item) return;
    write_bits(&item->raw, MASK_02_BITS, 3, sda);
}

void set_I021_090_EXT2_GVA(I021_090_EXT2 * item, uint8_t gva)
{
    if (!item) return;
    write_bits(&item->raw, MASK_02_BITS, 1, gva);
}

void set_I021_090_EXT2_FX(I021_090_EXT2 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* ============================ THIRD EXTENSION ============================  */

void set_I021_090_EXT3_PIC(I021_090_EXT3 * item, uint8_t pic)
{
    if (!item) return;
    write_bits(&item->raw, MASK_04_BITS, 4, pic);
}

#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
void set_I021_090_EXT3_SRC(I021_090_EXT3 * item, uint8_t pic_src)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 3, pic_src);
}
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */

void set_I021_090_EXT3_FX(I021_090_EXT3 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
/* ============================ FOURTH EXTENSION ===========================  */

void set_I021_090_EXT4_VALSTATE(I021_090_EXT4 * item, uint8_t val_state)
{
    if (!item) return;
    write_bits(&item->raw, MASK_03_BITS, 3, val_state);
}

void set_I021_090_EXT4_VD(I021_090_EXT4 * item, uint8_t vd)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 2, vd);
}

void set_I021_090_EXT4_VQ(I021_090_EXT4 * item, uint8_t vq)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 1, vq);
}

void set_I021_090_EXT4_FX(I021_090_EXT4 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* ============================ FIFTH EXTENSION ============================  */

void set_I021_090_EXT5_VALDISTP1(I021_090_EXT5 * item, uint16_t val_dist_p1)
{
    uint8_t val_dist_p1_raw = 0;
    if (!item) return;
    if (val_dist_p1 > 0)
        val_dist_p1_raw = (uint8_t)(val_dist_p1 / I021_090_EXT5_LSB_VAL_DIST_P1);
    write_bits(&item->raw, MASK_07_BITS, 1, val_dist_p1_raw);
}

void set_I021_090_EXT5_FX(I021_090_EXT5 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* ============================ SIXTH EXTENSION ============================  */

void set_I021_090_EXT6_VALDISTP2(I021_090_EXT6 * item, uint8_t val_dist_p2)
{
    if (!item) return;
    write_bits(&item->raw, MASK_07_BITS, 1, val_dist_p2);
}

void set_I021_090_EXT6_FX(I021_090_EXT6 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* =========================== SEVENTH EXTENSION ===========================  */

void set_I021_090_EXT7_VALDISTQUALP1(I021_090_EXT7 * item, uint16_t val_dist_qual_p1)
{
    uint8_t val_dist_qual_p1_raw = 0;    
    if (!item) return;
    if (val_dist_qual_p1 > 0)
        val_dist_qual_p1_raw = (uint8_t)(val_dist_qual_p1 / I021_090_EXT7_LSB_VAL_DIST_QUAL_P1);
    write_bits(&item->raw, MASK_07_BITS, 1, val_dist_qual_p1_raw);
}

void set_I021_090_EXT7_FX(I021_090_EXT7 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* =========================== EIGHT EXTENSION ===========================  */

void set_I021_090_EXT8_VALDISTQUALP2(I021_090_EXT8 * item, uint8_t val_dist_qual_p2)
{
    if (!item) return;
    write_bits(&item->raw, MASK_07_BITS, 1, val_dist_qual_p2);
}

void set_I021_090_EXT8_FX(I021_090_EXT8 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_090(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_090 * item = (I021_090 *) item_in;
    msg_out[out_index++] = item->raw;
    if (get_I021_090_FX(item) == 0) return out_index;
    msg_out[out_index++] = item->ext1.raw;
    if (get_I021_090_EXT1_FX(&(item->ext1)) == 0) return out_index;
    msg_out[out_index++] = item->ext2.raw;
    if (get_I021_090_EXT2_FX(&(item->ext2)) == 0) return out_index;
    msg_out[out_index++] = item->ext3.raw;
#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
    if (get_I021_090_EXT3_FX(&(item->ext3)) == 0) return out_index;
    msg_out[out_index++] = item->ext4.raw;
    if (get_I021_090_EXT4_FX(&(item->ext4)) == 0) return out_index;
    msg_out[out_index++] = item->ext5.raw;
    if (get_I021_090_EXT5_FX(&(item->ext5)) == 0) return out_index;
    msg_out[out_index++] = item->ext6.raw;
    if (get_I021_090_EXT6_FX(&(item->ext6)) == 0) return out_index;
    msg_out[out_index++] = item->ext7.raw;
    if (get_I021_090_EXT7_FX(&(item->ext7)) == 0) return out_index;
    msg_out[out_index++] = item->ext8.raw;
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */
    return out_index;
}

uint16_t decode_I021_090(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_090 * item = (I021_090 *) item_out;
    item->raw = msg_in[in_index++];
    if (get_I021_090_FX(item) == 0) return in_index;
    item->ext1.raw = msg_in[in_index++];
    if (get_I021_090_EXT1_FX(&(item->ext1)) == 0) return in_index;
    item->ext2.raw = msg_in[in_index++];
    if (get_I021_090_EXT2_FX(&(item->ext2)) == 0) return in_index;
    item->ext3.raw = msg_in[in_index++];
#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
    if (get_I021_090_EXT3_FX(&(item->ext3)) == 0) return in_index;
    item->ext4.raw = msg_in[in_index++];
    if (get_I021_090_EXT4_FX(&(item->ext4)) == 0) return in_index;
    item->ext5.raw = msg_in[in_index++];
    if (get_I021_090_EXT5_FX(&(item->ext5)) == 0) return in_index;
    item->ext6.raw = msg_in[in_index++];
    if (get_I021_090_EXT6_FX(&(item->ext6)) == 0) return in_index;
    item->ext7.raw = msg_in[in_index++];
    if (get_I021_090_EXT7_FX(&(item->ext7)) == 0) return in_index;
    item->ext8.raw = msg_in[in_index++];
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

uint8_t count_I021_090_extensions(const I021_090 *item)
{
    uint8_t counter = 0;
    
    if (!get_I021_090_FX(item)) return counter;
    counter = 1;
    if (!get_I021_090_EXT1_FX(&(item->ext1))) return counter;
    counter = 2;
    if (!get_I021_090_EXT2_FX(&(item->ext2))) return counter;
    counter = 3;
    if (!get_I021_090_EXT3_FX(&(item->ext3))) return counter;
    counter = 4;
#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
    if (!get_I021_090_EXT4_FX(&(item->ext4))) return counter;
    counter = 5;
    if (!get_I021_090_EXT5_FX(&(item->ext5))) return counter;
    counter = 6;
    if (!get_I021_090_EXT6_FX(&(item->ext6))) return counter;
    counter = 7;
    if (!get_I021_090_EXT7_FX(&(item->ext7))) return counter;
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */
    return counter;
}

void print_I021_090(const I021_090 * item)
{
    printf("I021/090 - Quality Indicators\n");
    if (!item)
    {
        printf("I021/090: <null>\n");
        return;
    }
    printf("- NUCr_NACv = %d\n", get_I021_090_NUCr_NACv(item));
    printf("- NUCp_NIC = %d\n", get_I021_090_NUCp_NIC(item));
    printf("- FX = %d\n", get_I021_090_FX(item));

    if(!get_I021_090_FX(item)) return;

    printf("- EXT1_NICbaro = %d\n", get_I021_090_EXT1_NICbaro(&(item->ext1)));
    printf("- EXT1_SIL = %d\n", get_I021_090_EXT1_SIL(&(item->ext1)));
    printf("- EXT1_NACp = %d\n", get_I021_090_EXT1_NACp(&(item->ext1)));
    printf("- EXT1_FX = %d\n", get_I021_090_EXT1_FX(&(item->ext1)));

    if(!get_I021_090_EXT1_FX(&(item->ext1))) return;

    printf("- EXT2_SILS = %d\n", get_I021_090_EXT2_SILS(&(item->ext2)));
    printf("- EXT2_SDA = %d\n", get_I021_090_EXT2_SDA(&(item->ext2)));
    printf("- EXT2_GVA = %d\n", get_I021_090_EXT2_GVA(&(item->ext2)));
    printf("- EXT2_FX = %d\n", get_I021_090_EXT2_FX(&(item->ext2)));

    if(!get_I021_090_EXT2_FX(&(item->ext2))) return;

    printf("- EXT3_PIC = %d\n", get_I021_090_EXT3_PIC(&(item->ext3)));
#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
    printf("- EXT3_SRC = %d\n", get_I021_090_EXT3_SRC(&(item->ext3)));
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */
    printf("- EXT3_FX = %d\n", get_I021_090_EXT3_FX(&(item->ext3)));

#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
    printf("- EXT4_VALSTATE = %d\n", get_I021_090_EXT4_VALSTATE(&(item->ext4)));
    printf("- EXT4_VD = %d\n", get_I021_090_EXT4_VD(&(item->ext4)));
    printf("- EXT4_VQ = %d\n", get_I021_090_EXT4_VQ(&(item->ext4)));
    printf("- EXT4_FX = %d\n", get_I021_090_EXT4_FX(&(item->ext4)));

    if (!get_I021_090_EXT4_FX(&(item->ext4))) return;

    printf("- EXT5_VALDISTP1 = %d\n", get_I021_090_EXT5_VALDISTP1(&(item->ext5)));
    printf("- EXT5_FX = %d\n", get_I021_090_EXT5_FX(&(item->ext5)));

    if (!get_I021_090_EXT5_FX(&(item->ext5))) return;

    printf("- EXT6_VALDISTP2 = %d\n", get_I021_090_EXT6_VALDISTP2(&(item->ext6)));
    printf("- EXT6_FX = %d\n", get_I021_090_EXT6_FX(&(item->ext6)));

    if (!get_I021_090_EXT6_FX(&(item->ext6))) return;

    printf("- EXT7_VALDISTQUALP1 = %d\n", get_I021_090_EXT7_VALDISTQUALP1(&(item->ext7)));
    printf("- EXT7_FX = %d\n", get_I021_090_EXT7_FX(&(item->ext7)));
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */
}
