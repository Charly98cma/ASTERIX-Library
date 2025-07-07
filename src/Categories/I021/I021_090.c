/**
 * @file I021_090.c
 * @brief Implementation of the Category 21 Item 090 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_090.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN  BYTE =============================== */

uint8_t get_I021_090_NUCr_NACv(const I021_090 * item) {
    return GET_BITS(item->raw, 6, MASK_03_BITS);
}

uint8_t get_I021_090_NUCp_NIC(const I021_090 * item) {
    return GET_BITS(item->raw, 2, MASK_04_BITS);
}

uint8_t get_I021_090_FX(const I021_090 * item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/* ============================= FIRST EXTENSION ============================ */

uint8_t get_I021_090_EXT1_NICbaro(const I021_090_EXT1 * item) {
    return GET_BITS(item->raw, 8, MASK_01_BITS);
}

uint8_t get_I021_090_EXT1_SIL(const I021_090_EXT1 * item) {
    return GET_BITS(item->raw, 6, MASK_02_BITS);
}

uint8_t get_I021_090_EXT1_NACp(const I021_090_EXT1 * item) {
    return GET_BITS(item->raw, 2, MASK_04_BITS);
}

uint8_t get_I021_090_EXT1_FX(const I021_090_EXT1 * item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/* ============================ SECOND EXTENSION ============================ */

uint8_t get_I021_090_EXT2_SILS(const I021_090_EXT2 * item) {
    return GET_BITS(item->raw, 6, MASK_01_BITS);
}

uint8_t get_I021_090_EXT2_SDA(const I021_090_EXT2 * item) {
    return GET_BITS(item->raw, 4, MASK_02_BITS);
}

uint8_t get_I021_090_EXT2_GVA(const I021_090_EXT2 * item) {
    return GET_BITS(item->raw, 2, MASK_02_BITS);
}

uint8_t get_I021_090_EXT2_FX(const I021_090_EXT2 * item) {
    return GET_BITS(item->raw, 1, MASK_02_BITS);
}

/* ============================ THIRD EXTENSION ============================  */

uint8_t get_I021_090_EXT3_PIC(const I021_090_EXT3 * item) {
    return GET_BITS(item->raw, 5, MASK_04_BITS);
}

#if (CAT021_ED >= 2 && CAT021_VN >= 7)
uint8_t get_I021_090_EXT3_SRC(const I021_090_EXT3 * item) {
    return GET_BITS(item->raw, 4, MASK_01_BITS);
}
#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)

uint8_t get_I021_090_EXT3_FX(const I021_090_EXT3 * item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

#if (CAT021_ED >= 2 && CAT021_VN >= 7)
/* ============================ FOURTH EXTENSION ===========================  */

uint8_t get_I021_090_EXT4_VALSTATE(const I021_090_EXT4 * item) {
    return GET_BITS(item->raw, 4, MASK_03_BITS);
}

uint8_t get_I021_090_EXT4_VD(const I021_090_EXT4 * item) {
    return GET_BITS(item->raw, 3, MASK_01_BITS);
}

uint8_t get_I021_090_EXT4_VQ(const I021_090_EXT4 * item) {
    return GET_BITS(item->raw, 2, MASK_01_BITS);
}

uint8_t get_I021_090_EXT4_FX(const I021_090_EXT4 * item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/* ============================ FIFTH EXTENSION ============================  */

uint16_t get_I021_090_EXT5_VALDISTP1(const I021_090_EXT5 * item) {
    return (uint16_t) (GET_BITS(item->raw, 2, MASK_07_BITS) * I021_090_EXT5_LSB_VAL_DIST_P1);
}

uint8_t get_I021_090_EXT5_FX(const I021_090_EXT5 * item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/* ============================ SIXTH EXTENSION ============================  */

uint8_t get_I021_090_EXT6_VALDISTP2(const I021_090_EXT6 * item) {
    return GET_BITS(item->raw, 2, MASK_07_BITS) * I021_090_EXT6_LSB_VAL_DIST_P2;
}

uint8_t get_I021_090_EXT6_FX(const I021_090_EXT6 * item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/* =========================== SEVENTH EXTENSION ===========================  */

uint16_t get_I021_090_EXT7_VALDISTQUALP1(const I021_090_EXT7 * item) {
    return (uint16_t) (GET_BITS(item->raw, 2, MASK_07_BITS) * I021_090_EXT7_LSB_VAL_DIST_QUAL_P1);
}

uint8_t get_I021_090_EXT7_FX(const I021_090_EXT7 * item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/* =========================== EIGHT EXTENSION ===========================  */

uint16_t get_I021_090_EXT8_VALDISTQUALP1(const I021_090_EXT8 * item) {
    return (GET_BITS(item->raw, 2, MASK_07_BITS) * I021_090_EXT8_LSB_VAL_DIST_QUAL_P2);
}

uint8_t get_I021_090_EXT8_FX(const I021_090_EXT8 * item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}
#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

void set_I021_090_NUCrNACv(I021_090 * item, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_03_BITS, 6);
}

void set_I021_090_NUCp_NIC(I021_090 * item, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_04_BITS, 2);
}

void set_I021_090_FX(I021_090 * item, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}

/* ============================= FIRST EXTENSION ============================ */

void set_I021_090_EXT1_NICbaro(I021_090_EXT1 * item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 8);
}

void set_I021_090_EXT1_SIL(I021_090_EXT1 * item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_02_BITS, 6);
}

void set_I021_090_EXT1_NACp(I021_090_EXT1 * item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_04_BITS, 2);
}

void set_I021_090_EXT1_FX(I021_090_EXT1 * item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}

/* ============================ SECOND EXTENSION ============================ */

void set_I021_090_EXT2_SILS(I021_090_EXT2 * item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 6);
}

void set_I021_090_EXT2_SDA(I021_090_EXT2 * item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_02_BITS, 4);
}

void set_I021_090_EXT2_GVA(I021_090_EXT2 * item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_02_BITS, 2);
}

void set_I021_090_EXT2_FX(I021_090_EXT2 * item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_02_BITS, 1);
}

/* ============================ THIRD EXTENSION ============================  */

void set_I021_090_EXT3_PIC(I021_090_EXT3 * item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_04_BITS, 5);
}

#if (CAT021_ED >= 2 && CAT021_VN >= 7)
void set_I021_090_EXT3_SRC(I021_090_EXT3 * item, const uint8_t pic_src) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), pic_src, MASK_01_BITS, 4);
}
#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)

void set_I021_090_EXT3_FX(I021_090_EXT3 * item, const uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}

#if (CAT021_ED >= 2 && CAT021_VN >= 7)
/* ============================ FOURTH EXTENSION ===========================  */

void set_I021_090_EXT4_VALSTATE(I021_090_EXT4 * item, const uint8_t val_state) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), val_state, MASK_03_BITS, 4);
}

void set_I021_090_EXT4_VD(I021_090_EXT4 * item, const uint8_t vd) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), vd, MASK_01_BITS, 3);
}

void set_I021_090_EXT4_VQ(I021_090_EXT4 * item, const uint8_t vq) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), vq, MASK_01_BITS, 2);
}

void set_I021_090_EXT4_FX(I021_090_EXT4 * item, const uint8_t fx) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

/* ============================ FIFTH EXTENSION ============================  */

void set_I021_090_EXT5_VALDISTP1(I021_090_EXT5 * item, const uint16_t val_dist_p1) {
    uint8_t val_dist_p1_raw = 0;
    
    // TODO: Check value is in valid range

    if (val_dist_p1 > 0)
        val_dist_p1_raw = (uint8_t)(val_dist_p1 / I021_090_EXT5_LSB_VAL_DIST_P1);

    SET_BITS(&(item->raw), val_dist_p1_raw, MASK_07_BITS, 2);
}

void set_I021_090_EXT5_FX(I021_090_EXT5 * item, const uint8_t fx) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

/* ============================ SIXTH EXTENSION ============================  */

void set_I021_090_EXT6_VALDISTP2(I021_090_EXT6 * item, const uint8_t val_dist_p2) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), val_dist_p2, MASK_07_BITS, 2);
}

void set_I021_090_EXT6_FX(I021_090_EXT6 * item, const uint8_t fx) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

/* =========================== SEVENTH EXTENSION ===========================  */

void set_I021_090_EXT7_VALDISTQUALP1(I021_090_EXT7 * item, const uint16_t val_dist_qual_p1) {
    uint8_t val_dist_qual_p1_raw = 0;
    
    // TODO: Check value is in valid range

    if (val_dist_qual_p1 > 0)
        val_dist_qual_p1_raw = (uint8_t)(val_dist_qual_p1 / I021_090_EXT7_LSB_VAL_DIST_QUAL_P1);

    SET_BITS(&(item->raw), val_dist_qual_p1_raw, MASK_07_BITS, 2);
}

void set_I021_090_EXT7_FX(I021_090_EXT7 * item, const uint8_t fx) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

/* =========================== EIGHT EXTENSION ===========================  */

void set_I021_090_EXT8_VALDISTQUALP2(I021_090_EXT8 * item, const uint8_t val_dist_qual_p2) {
    SET_BITS(&(item->raw), val_dist_qual_p2, MASK_07_BITS, 2);
}

void set_I021_090_EXT8_FX(I021_090_EXT8 * item, const uint8_t fx) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)


/*******************************************************************************
 * Other Functions
 ******************************************************************************/

uint8_t count_I021_090_extensions(const I021_090 *item) {
    uint8_t counter = 0;
    
    if (!get_I021_090_FX(item)) return counter;
    counter = 1;
    if (!get_I021_090_EXT1_FX(&(item->ext1))) return counter;
    counter = 2;
    if (!get_I021_090_EXT2_FX(&(item->ext2))) return counter;
    counter = 3;
    if (!get_I021_090_EXT3_FX(&(item->ext3))) return counter;
    counter = 4;
#if (CAT021_ED >= 2 && CAT021_VN >= 7)
    if (!get_I021_090_EXT4_FX(&(item->ext4))) return counter;
    counter = 5;
    if (!get_I021_090_EXT5_FX(&(item->ext5))) return counter;
    counter = 6;
    if (!get_I021_090_EXT6_FX(&(item->ext6))) return counter;
    counter = 7;
    if (!get_I021_090_EXT7_FX(&(item->ext7))) return counter;
#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)
    return counter;
}

void print_I021_090(const I021_090 * item) {
    printf("Category 021 Item 090 - Quality Indicators\n");
    printf("  NUCr_NACv = %d\n", get_I021_090_NUCr_NACv(item));
    printf("  NUCp_NIC = %d\n", get_I021_090_NUCp_NIC(item));
    printf("  FX = %d\n", get_I021_090_FX(item));

    if(!get_I021_090_FX(item)) return;

    printf("  EXT1_NICbaro = %d\n", get_I021_090_EXT1_NICbaro(&(item->ext1)));
    printf("  EXT1_SIL = %d\n", get_I021_090_EXT1_SIL(&(item->ext1)));
    printf("  EXT1_NACp = %d\n", get_I021_090_EXT1_NACp(&(item->ext1)));
    printf("  EXT1_FX = %d\n", get_I021_090_EXT1_FX(&(item->ext1)));

    if(!get_I021_090_EXT1_FX(&(item->ext1))) return;

    printf("  EXT2_SILS = %d\n", get_I021_090_EXT2_SILS(&(item->ext2)));
    printf("  EXT2_SDA = %d\n", get_I021_090_EXT2_SDA(&(item->ext2)));
    printf("  EXT2_GVA = %d\n", get_I021_090_EXT2_GVA(&(item->ext2)));
    printf("  EXT2_FX = %d\n", get_I021_090_EXT2_FX(&(item->ext2)));

    if(!get_I021_090_EXT2_FX(&(item->ext2))) return;

    printf("  EXT3_PIC = %d\n", get_I021_090_EXT3_PIC(&(item->ext3)));
#if (CAT021_ED >= 2 && CAT021_VN >= 7)
    printf("  EXT3_SRC = %d\n", get_I021_090_EXT3_SRC(&(item->ext3)));
#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)
    printf("  EXT3_FX = %d\n", get_I021_090_EXT3_FX(&(item->ext3)));

#if (CAT021_ED >= 2 && CAT021_VN >= 7)
    printf("  EXT4_VALSTATE = %d\n", get_I021_090_EXT4_VALSTATE(&(item->ext4)));
    printf("  EXT4_VD = %d\n", get_I021_090_EXT4_VD(&(item->ext4)));
    printf("  EXT4_VQ = %d\n", get_I021_090_EXT4_VQ(&(item->ext4)));
    printf("  EXT4_FX = %d\n", get_I021_090_EXT4_FX(&(item->ext4)));

    if (!get_I021_090_EXT4_FX(&(item->ext4))) return;

    printf("  EXT5_VALDISTP1 = %d\n", get_I021_090_EXT5_VALDISTP1(&(item->ext5)));
    printf("  EXT5_FX = %d\n", get_I021_090_EXT5_FX(&(item->ext5)));

    if (!get_I021_090_EXT5_FX(&(item->ext5))) return;

    printf("  EXT6_VALDISTP2 = %d\n", get_I021_090_EXT6_VALDISTP2(&(item->ext6)));
    printf("  EXT6_FX = %d\n", get_I021_090_EXT6_FX(&(item->ext6)));

    if (!get_I021_090_EXT6_FX(&(item->ext6))) return;

    printf("  EXT7_VALDISTQUALP1 = %d\n", get_I021_090_EXT7_VALDISTQUALP1(&(item->ext7)));
    printf("  EXT7_FX = %d\n", get_I021_090_EXT7_FX(&(item->ext7)));
#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)
}
