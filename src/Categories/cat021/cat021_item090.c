/**
 * @file cat021_item090.c
 * @brief Implementation of the Category 21 Item 090 functions
 */

#include "cat021_item090.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN  BYTE =============================== */

uint8_t get_cat021_item090_NUCr_NACv(const cat021_item090 * item)
{
    return GET_BITS((item)->raw, 6, MASK_03_BITS);
}

uint8_t get_cat021_item090_NUCp_NIC(const cat021_item090 * item)
{
    return GET_BITS((item)->raw, 2, MASK_04_BITS);
}

uint8_t get_cat021_item090_FX(const cat021_item090 * item)
{
    return GET_BITS((item)->raw, 1, MASK_01_BITS);
}

/* ============================= FIRST EXTENSION ============================ */

uint8_t get_cat021_item0900_ext1_NICbaro(const cat021_item090_ext1 * item)
{
    return GET_BITS((item)->raw, 8, MASK_01_BITS);
}

uint8_t get_cat021_item0900_ext1_SIL(const cat021_item090_ext1 * item)
{
    return GET_BITS((item)->raw, 6, MASK_02_BITS);
}

uint8_t get_cat021_item0900_ext1_NACp(const cat021_item090_ext1 * item)
{
    return GET_BITS((item)->raw, 2, MASK_04_BITS);
}

uint8_t get_cat021_item0900_ext1_FX(const cat021_item090_ext1 * item)
{
    return GET_BITS((item)->raw, 1, MASK_01_BITS);
}

/* ============================ SECOND EXTENSION ============================ */

uint8_t get_cat021_item0900_ext2_SILS(const cat021_item090_ext2 * item)
{
    return GET_BITS((item)->raw, 6, MASK_01_BITS);
}

uint8_t get_cat021_item0900_ext2_SDA(const cat021_item090_ext2 * item)
{
    return GET_BITS((item)->raw, 4, MASK_02_BITS);
}

uint8_t get_cat021_item0900_ext2_GVA(const cat021_item090_ext2 * item)
{
    return GET_BITS((item)->raw, 2, MASK_02_BITS);
}

uint8_t get_cat021_item0900_ext2_FX(const cat021_item090_ext2 * item)
{
    return GET_BITS((item)->raw, 1, MASK_02_BITS);
}

/* ============================ THIRD EXTENSION ============================  */

uint8_t get_cat021_item0900_ext3_PIC(const cat021_item090_ext3 * item)
{
    return GET_BITS((item)->raw, 5, MASK_04_BITS);
}

uint8_t get_cat021_item0900_ext3_FX(const cat021_item090_ext3 * item)
{
    return GET_BITS((item)->raw, 1, MASK_01_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

void set_cat021_item09_NUCrNACv(cat021_item090 * item, uint8_t value)
{
    SET_BITS(&(item->raw), value, MASK_03_BITS, 6);
}

void set_cat021_item09_NUCp_NIC(cat021_item090 * item, uint8_t value)
{
    SET_BITS(&(item->raw), value, MASK_04_BITS, 2);
}

void set_cat021_item09_FX(cat021_item090 * item, uint8_t value)
{
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}

/* ============================= FIRST EXTENSION ============================ */

void set_cat021_item090_ext1_NICbaro(cat021_item090_ext1 * item, uint8_t value)
{
    SET_BITS(&(item->raw), value, MASK_01_BITS, 8);
}

void set_cat021_item090_ext1_SIL(cat021_item090_ext1 * item, uint8_t value)
{
    SET_BITS(&(item->raw), value, MASK_02_BITS, 6);
}

void set_cat021_item090_ext1_NACp(cat021_item090_ext1 * item, uint8_t value)
{
    SET_BITS(&(item->raw), value, MASK_04_BITS, 2);
}

void set_cat021_item090_ext1_FX(cat021_item090_ext1 * item, uint8_t value)
{
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}

/* ============================ SECOND EXTENSION ============================ */

void set_cat021_item090_ext2_SILS(cat021_item090_ext2 * item, uint8_t value)
{
    SET_BITS(&(item->raw), value, MASK_01_BITS, 6);
}

void set_cat021_item090_ext2_SDA(cat021_item090_ext2 * item, uint8_t value)
{
    SET_BITS(&(item->raw), value, MASK_02_BITS, 4);
}

void set_cat021_item090_ext2_GVA(cat021_item090_ext2 * item, uint8_t value)
{
    SET_BITS(&(item->raw), value, MASK_02_BITS, 2);
}

void set_cat021_item090_ext2_FX(cat021_item090_ext2 * item, uint8_t value)
{
    SET_BITS(&(item->raw), value, MASK_02_BITS, 1);
}

/* ============================ THIRD EXTENSION ============================  */

void set_cat021_item090_ext3_PIC(cat021_item090_ext3 * item, uint8_t value)
{
    SET_BITS(&(item->raw), value, MASK_04_BITS, 5);
}

void set_cat021_item090_ext3_FX(cat021_item090_ext3 * item, uint8_t value)
{
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

uint8_t count_cat021_item090_extensions(const cat021_item090 *item)
{
    uint8_t counter = 0;
    
    if (get_cat021_item090_FX(item))
    {
        counter++;
        if (get_cat021_item090_ext1_FX(&(item->ext1)))
        {
            counter++;
            if (get_cat021_item090_ext2_FX(&(item->ext2)))
            {
                counter++;
                if (get_cat021_item090_ext3_FX(&(item->ext3)))
                {
                    counter++;
                }
            }
        }
    }

    return counter;
}

void print_cat021_item090(const cat021_item090 * item)
{
    printf("Category 021 / Item 090 -  Quality Indicators\n");
    printf("  NUCr_NACv = %d\n", get_cat021_item090_NUCr_NACv(item));
    printf("  NUCp_NIC = %d\n", get_cat021_item090_NUCp_NIC(item));
    printf("  FX = %d\n", get_cat021_item090_FX(item));

    if(!get_cat021_item090_FX(item)) return;

    printf("  ext1_NICbaro = %d\n", get_cat021_item0900_ext1_NICbaro(&(item->ext1)));
    printf("  ext1_SIL = %d\n", get_cat021_item0900_ext1_SIL(&(item->ext1)));
    printf("  ext1_NACp = %d\n", get_cat021_item0900_ext1_NACp(&(item->ext1)));
    printf("  ext1_FX = %d\n", get_cat021_item0900_ext1_FX(&(item->ext1)));

    if(!get_cat021_item0900_ext1_FX(&(item->ext1))) return;

    printf("  ext2_SILS = %d\n", get_cat021_item0900_ext2_SILS(&(item->ext2)));
    printf("  ext2_SDA = %d\n", get_cat021_item0900_ext2_SDA(&(item->ext2)));
    printf("  ext2_GVA = %d\n", get_cat021_item0900_ext2_GVA(&(item->ext2)));
    printf("  ext2_FX = %d\n", get_cat021_item0900_ext2_FX(&(item->ext2)));

    if(!get_cat021_item0900_ext2_FX(&(item->ext2))) return;

    printf("  ext3_PIC = %d\n", get_cat021_item0900_ext3_PIC(&(item->ext3)));
    printf("  ext3_FX = %d\n", get_cat021_item0900_ext3_FX(&(item->ext3)));
}
