/**
 * @file cat021_item090.c
 * @brief Implementation of the Category 21 Item 090 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/cat021/cat021_item090.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN  BYTE =============================== */

uint8_t get_cat021_item090_NUCr_NACv(const cat021_item090 * item)
{
    return GET_BITS(item->raw, 6, MASK_03_BITS);
}

uint8_t get_cat021_item090_NUCp_NIC(const cat021_item090 * item)
{
    return GET_BITS(item->raw, 2, MASK_04_BITS);
}

uint8_t get_cat021_item090_FX(const cat021_item090 * item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/* ============================= FIRST EXTENSION ============================ */

uint8_t get_cat021_item090_ext1_NICbaro(const cat021_item090_ext1 * item)
{
    return GET_BITS(item->raw, 8, MASK_01_BITS);
}

uint8_t get_cat021_item090_ext1_SIL(const cat021_item090_ext1 * item)
{
    return GET_BITS(item->raw, 6, MASK_02_BITS);
}

uint8_t get_cat021_item090_ext1_NACp(const cat021_item090_ext1 * item)
{
    return GET_BITS(item->raw, 2, MASK_04_BITS);
}

uint8_t get_cat021_item090_ext1_FX(const cat021_item090_ext1 * item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/* ============================ SECOND EXTENSION ============================ */

uint8_t get_cat021_item090_ext2_SILS(const cat021_item090_ext2 * item)
{
    return GET_BITS(item->raw, 6, MASK_01_BITS);
}

uint8_t get_cat021_item090_ext2_SDA(const cat021_item090_ext2 * item)
{
    return GET_BITS(item->raw, 4, MASK_02_BITS);
}

uint8_t get_cat021_item090_ext2_GVA(const cat021_item090_ext2 * item)
{
    return GET_BITS(item->raw, 2, MASK_02_BITS);
}

uint8_t get_cat021_item090_ext2_FX(const cat021_item090_ext2 * item)
{
    return GET_BITS(item->raw, 1, MASK_02_BITS);
}

/* ============================ THIRD EXTENSION ============================  */

uint8_t get_cat021_item090_ext3_PIC(const cat021_item090_ext3 * item)
{
    return GET_BITS(item->raw, 5, MASK_04_BITS);
}

#if (CAT021_ED >= 2 && CAT021_VN >= 7)
uint8_t get_cat021_item090_ext3_SRC(const cat021_item090_ext3 * item)
{
    return GET_BITS(item->raw, 4, MASK_01_BITS);
}
#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)

uint8_t get_cat021_item090_ext3_FX(const cat021_item090_ext3 * item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

#if (CAT021_ED >= 2 && CAT021_VN >= 7)
/* ============================ FOURTH EXTENSION ===========================  */

uint8_t get_cat021_item090_ext4_VALSTATE(const cat021_item090_ext4 * item)
{
    return GET_BITS(item->raw, 4, MASK_03_BITS);
}

uint8_t get_cat021_item090_ext4_VD(const cat021_item090_ext4 * item)
{
    return GET_BITS(item->raw, 3, MASK_01_BITS);
}

uint8_t get_cat021_item090_ext4_VQ(const cat021_item090_ext4 * item)
{
    return GET_BITS(item->raw, 2, MASK_01_BITS);
}

uint8_t get_cat021_item090_ext4_FX(const cat021_item090_ext4 * item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/* ============================ FIFTH EXTENSION ============================  */

uint16_t get_cat021_item090_ext5_VALDISTP1(const cat021_item090_ext5 * item)
{
    return (uint16_t) (GET_BITS(item->raw, 2, MASK_07_BITS) * CAT021_ITEM090_EXT5_LSB_VAL_DIST_P1);
}

uint8_t get_cat021_item090_ext5_FX(const cat021_item090_ext5 * item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/* ============================ SIXTH EXTENSION ============================  */

uint8_t get_cat021_item090_ext6_VALDISTP2(const cat021_item090_ext6 * item)
{
    return GET_BITS(item->raw, 2, MASK_07_BITS) * CAT021_ITEM090_EXT6_LSB_VAL_DIST_P2;
}

uint8_t get_cat021_item090_ext6_FX(const cat021_item090_ext6 * item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/* =========================== SEVENTH EXTENSION ===========================  */

uint16_t get_cat021_item090_ext7_VALDISTQUALP1(const cat021_item090_ext7 * item)
{
    return (uint16_t) (GET_BITS(item->raw, 2, MASK_07_BITS) * CAT021_ITEM090_EXT7_LSB_VAL_DIST_QUAL_P1);
}

uint8_t get_cat021_item090_ext7_FX(const cat021_item090_ext7 * item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/* =========================== EIGHT EXTENSION ===========================  */

uint16_t get_cat021_item090_ext8_VALDISTQUALP1(const cat021_item090_ext8 * item)
{
    return (GET_BITS(item->raw, 2, MASK_07_BITS) * CAT021_ITEM090_EXT8_LSB_VAL_DIST_QUAL_P2);
}

uint8_t get_cat021_item090_ext8_FX(const cat021_item090_ext8 * item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}
#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

void set_cat021_item09_NUCrNACv(cat021_item090 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_03_BITS, 6);
}

void set_cat021_item09_NUCp_NIC(cat021_item090 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_04_BITS, 2);
}

void set_cat021_item09_FX(cat021_item090 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}

/* ============================= FIRST EXTENSION ============================ */

void set_cat021_item090_ext1_NICbaro(cat021_item090_ext1 * item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 8);
}

void set_cat021_item090_ext1_SIL(cat021_item090_ext1 * item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_02_BITS, 6);
}

void set_cat021_item090_ext1_NACp(cat021_item090_ext1 * item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_04_BITS, 2);
}

void set_cat021_item090_ext1_FX(cat021_item090_ext1 * item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}

/* ============================ SECOND EXTENSION ============================ */

void set_cat021_item090_ext2_SILS(cat021_item090_ext2 * item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 6);
}

void set_cat021_item090_ext2_SDA(cat021_item090_ext2 * item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_02_BITS, 4);
}

void set_cat021_item090_ext2_GVA(cat021_item090_ext2 * item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_02_BITS, 2);
}

void set_cat021_item090_ext2_FX(cat021_item090_ext2 * item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_02_BITS, 1);
}

/* ============================ THIRD EXTENSION ============================  */

void set_cat021_item090_ext3_PIC(cat021_item090_ext3 * item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_04_BITS, 5);
}

#if (CAT021_ED >= 2 && CAT021_VN >= 7)
void set_cat021_item090_ext3_SRC(cat021_item090_ext3 * item,
                                     const uint8_t pic_src)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), pic_src, MASK_01_BITS, 4);
}
#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)

void set_cat021_item090_ext3_FX(cat021_item090_ext3 * item, const uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}

#if (CAT021_ED >= 2 && CAT021_VN >= 7)
/* ============================ FOURTH EXTENSION ===========================  */

void set_cat021_item090_ext4_VALSTATE(cat021_item090_ext4 * item,
                                      const uint8_t val_state)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), val_state, MASK_03_BITS, 4);
}

void set_cat021_item090_ext4_VD(cat021_item090_ext4 * item, const uint8_t vd)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), vd, MASK_01_BITS, 3);
}

void set_cat021_item090_ext4_VQ(cat021_item090_ext4 * item, const uint8_t vq)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), vq, MASK_01_BITS, 2);
}

void set_cat021_item090_ext4_FX(cat021_item090_ext4 * item, const uint8_t fx)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

/* ============================ FIFTH EXTENSION ============================  */

void set_cat021_item090_ext5_VALDISTP1(cat021_item090_ext5 * item,
                                       const uint16_t val_dist_p1)
{
    uint8_t val_dist_p1_raw = 0;
    
    // TODO: Check value is in valid range

    if (val_dist_p1 > 0)
        val_dist_p1_raw = (uint8_t)(val_dist_p1 / CAT021_ITEM090_EXT5_LSB_VAL_DIST_P1);

    SET_BITS(&(item->raw), val_dist_p1_raw, MASK_07_BITS, 2);
}

void set_cat021_item090_ext5_FX(cat021_item090_ext5 * item, const uint8_t fx)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

/* ============================ SIXTH EXTENSION ============================  */

void set_cat021_item090_ext6_VALDISTP2(cat021_item090_ext6 * item,
                                       const uint8_t val_dist_p2)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), val_dist_p2, MASK_07_BITS, 2);
}

void set_cat021_item090_ext6_FX(cat021_item090_ext6 * item, const uint8_t fx)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

/* =========================== SEVENTH EXTENSION ===========================  */

void set_cat021_item090_ext7_VALDISTQUALP1(cat021_item090_ext7 * item,
                                           const uint16_t val_dist_qual_p1)
{
    uint8_t val_dist_qual_p1_raw = 0;
    
    // TODO: Check value is in valid range

    if (val_dist_qual_p1 > 0)
        val_dist_qual_p1_raw = (uint8_t)(val_dist_qual_p1 / CAT021_ITEM090_EXT7_LSB_VAL_DIST_QUAL_P1);

    SET_BITS(&(item->raw), val_dist_qual_p1_raw, MASK_07_BITS, 2);
}

void set_cat021_item090_ext7_FX(cat021_item090_ext7 * item, const uint8_t fx)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

/* =========================== EIGHT EXTENSION ===========================  */

void set_cat021_item090_ext8_VALDISTQUALP2(cat021_item090_ext8 * item,
                                           const uint8_t val_dist_qual_p2)
{
    SET_BITS(&(item->raw), val_dist_qual_p2, MASK_07_BITS, 2);
}

void set_cat021_item090_ext8_FX(cat021_item090_ext8 * item, const uint8_t fx)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)


/*******************************************************************************
 * Other Functions
 ******************************************************************************/

uint8_t count_cat021_item090_extensions(const cat021_item090 *item)
{
    uint8_t counter = 0;
    
    if (!get_cat021_item090_FX(item)) return counter;
    counter = 1;
    if (!get_cat021_item090_ext1_FX(&(item->ext1))) return counter;
    counter = 2;
    if (!get_cat021_item090_ext2_FX(&(item->ext2))) return counter;
    counter = 3;
    if (!get_cat021_item090_ext3_FX(&(item->ext3))) return counter;
    counter = 4;
#if (CAT021_ED >= 2 && CAT021_VN >= 7)
    if (!get_cat021_item090_ext4_FX(&(item->ext4))) return counter;
    counter = 5;
    if (!get_cat021_item090_ext5_FX(&(item->ext5))) return counter;
    counter = 6;
    if (!get_cat021_item090_ext6_FX(&(item->ext6))) return counter;
    counter = 7;
    if (!get_cat021_item090_ext7_FX(&(item->ext7))) return counter;
#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)
    return counter;
}

void print_cat021_item090(const cat021_item090 * item)
{
    printf("Category 021 Item 090 - Quality Indicators\n");
    printf("  NUCr_NACv = %d\n", get_cat021_item090_NUCr_NACv(item));
    printf("  NUCp_NIC = %d\n", get_cat021_item090_NUCp_NIC(item));
    printf("  FX = %d\n", get_cat021_item090_FX(item));

    if(!get_cat021_item090_FX(item)) return;

    printf("  ext1_NICbaro = %d\n", get_cat021_item090_ext1_NICbaro(&(item->ext1)));
    printf("  ext1_SIL = %d\n", get_cat021_item090_ext1_SIL(&(item->ext1)));
    printf("  ext1_NACp = %d\n", get_cat021_item090_ext1_NACp(&(item->ext1)));
    printf("  ext1_FX = %d\n", get_cat021_item090_ext1_FX(&(item->ext1)));

    if(!get_cat021_item090_ext1_FX(&(item->ext1))) return;

    printf("  ext2_SILS = %d\n", get_cat021_item090_ext2_SILS(&(item->ext2)));
    printf("  ext2_SDA = %d\n", get_cat021_item090_ext2_SDA(&(item->ext2)));
    printf("  ext2_GVA = %d\n", get_cat021_item090_ext2_GVA(&(item->ext2)));
    printf("  ext2_FX = %d\n", get_cat021_item090_ext2_FX(&(item->ext2)));

    if(!get_cat021_item090_ext2_FX(&(item->ext2))) return;

    printf("  ext3_PIC = %d\n", get_cat021_item090_ext3_PIC(&(item->ext3)));
#if (CAT021_ED >= 2 && CAT021_VN >= 7)
    printf("  ext3_SRC = %d\n", get_cat021_item090_ext3_SRC(&(item->ext3)));
#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)
    printf("  ext3_FX = %d\n", get_cat021_item090_ext3_FX(&(item->ext3)));

#if (CAT021_ED >= 2 && CAT021_VN >= 7)
    printf("  ext4_VALSTATE = %d\n", get_cat021_item090_ext4_VALSTATE(&(item->ext4)));
    printf("  ext4_VD = %d\n", get_cat021_item090_ext4_VD(&(item->ext4)));
    printf("  ext4_VQ = %d\n", get_cat021_item090_ext4_VQ(&(item->ext4)));
    printf("  ext4_FX = %d\n", get_cat021_item090_ext4_FX(&(item->ext4)));

    if (!get_cat021_item090_ext4_FX(&(item->ext4))) return;

    printf("  ext5_VALDISTP1 = %d\n", get_cat021_item090_ext5_VALDISTP1(&(item->ext5)));
    printf("  ext5_FX = %d\n", get_cat021_item090_ext5_FX(&(item->ext5)));

    if (!get_cat021_item090_ext5_FX(&(item->ext5))) return;

    printf("  ext6_VALDISTP2 = %d\n", get_cat021_item090_ext6_VALDISTP2(&(item->ext6)));
    printf("  ext6_FX = %d\n", get_cat021_item090_ext6_FX(&(item->ext6)));

    if (!get_cat021_item090_ext6_FX(&(item->ext6))) return;

    printf("  ext7_VALDISTQUALP1 = %d\n", get_cat021_item090_ext7_VALDISTQUALP1(&(item->ext7)));
    printf("  ext7_FX = %d\n", get_cat021_item090_ext7_FX(&(item->ext7)));
#endif // (CAT021_ED >= 2 && CAT021_VN >= 7)
}
