/**
 * @file cat021_item295.c
 * @brief Implementation of the Category 21 Item 295 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/cat021/cat021_item295.h"


/*******************************************************************************
 * Getters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

uint8_t get_cat021_item295_AOS(const cat021_item295 * item)
{
    return GET_BITS(item->raw[0], 8, MASK_01_BITS);
}

uint8_t get_cat021_item295_TRD(const cat021_item295 * item)
{
    return GET_BITS(item->raw[0], 7, MASK_01_BITS);
}

uint8_t get_cat021_item295_M3A(const cat021_item295 * item)
{
    return GET_BITS(item->raw[0], 6, MASK_01_BITS);
}

uint8_t get_cat021_item295_QI(const cat021_item295 * item)
{
    return GET_BITS(item->raw[0], 5, MASK_01_BITS);
}

uint8_t get_cat021_item295_TI(const cat021_item295 * item)
{
    return GET_BITS(item->raw[0], 4, MASK_01_BITS);
}

uint8_t get_cat021_item295_MAM(const cat021_item295 * item)
{
    return GET_BITS(item->raw[0], 3, MASK_01_BITS);
}

uint8_t get_cat021_item295_GH(const cat021_item295 * item)
{
    return GET_BITS(item->raw[0], 2, MASK_01_BITS);
}

uint8_t get_cat021_item295_FX1(const cat021_item295 * item)
{
    return GET_BITS(item->raw[0], 1, MASK_01_BITS);
}

uint8_t get_cat021_item295_FL(const cat021_item295 * item)
{
    return GET_BITS(item->raw[1], 8, MASK_01_BITS);
}

uint8_t get_cat021_item295_SAL(const cat021_item295 * item)
{
    return GET_BITS(item->raw[1], 7, MASK_01_BITS);
}

uint8_t get_cat021_item295_FSA(const cat021_item295 * item)
{
    return GET_BITS(item->raw[1], 6, MASK_01_BITS);
}

uint8_t get_cat021_item295_AS(const cat021_item295 * item)
{
    return GET_BITS(item->raw[1], 5, MASK_01_BITS);
}

uint8_t get_cat021_item295_TAS(const cat021_item295 * item)
{
    return GET_BITS(item->raw[1], 4, MASK_01_BITS);
}

uint8_t get_cat021_item295_MH(const cat021_item295 * item)
{
    return GET_BITS(item->raw[1], 3, MASK_01_BITS);
}

uint8_t get_cat021_item295_BVR(const cat021_item295 * item)
{
    return GET_BITS(item->raw[1], 2, MASK_01_BITS);
}

uint8_t get_cat021_item295_FX2(const cat021_item295 * item)
{
    return GET_BITS(item->raw[1], 1, MASK_01_BITS);
}

uint8_t get_cat021_item295_GVR(const cat021_item295 * item)
{
    return GET_BITS(item->raw[2], 8, MASK_01_BITS);
}

uint8_t get_cat021_item295_GV(const cat021_item295 * item)
{
    return GET_BITS(item->raw[2], 7, MASK_01_BITS);
}

uint8_t get_cat021_item295_TAR(const cat021_item295 * item)
{
    return GET_BITS(item->raw[2], 6, MASK_01_BITS);
}

uint8_t get_cat021_item295_TID(const cat021_item295 * item)
{
    return GET_BITS(item->raw[2], 5, MASK_01_BITS);
}

uint8_t get_cat021_item295_TS(const cat021_item295 * item)
{
    return GET_BITS(item->raw[2], 4, MASK_01_BITS);
}

uint8_t get_cat021_item295_MET(const cat021_item295 * item)
{
    return GET_BITS(item->raw[2], 3, MASK_01_BITS);
}

uint8_t get_cat021_item295_ROA(const cat021_item295 * item)
{
    return GET_BITS(item->raw[2], 2, MASK_01_BITS);
}

uint8_t get_cat021_item295_FX3(const cat021_item295 * item)
{
    return GET_BITS(item->raw[2], 1, MASK_01_BITS);
}

uint8_t get_cat021_item295_ARA(const cat021_item295 * item)
{
    return GET_BITS(item->raw[3], 8, MASK_01_BITS);
}

uint8_t get_cat021_item295_SCC(const cat021_item295 * item)
{
    return GET_BITS(item->raw[3], 7, MASK_01_BITS);
}

uint8_t get_cat021_item295_FX4(const cat021_item295 * item)
{
    return GET_BITS(item->raw[3], 1, MASK_01_BITS);
}

/* =============================== SUBFIELD 1 =============================== */

double get_cat021_item295_ext1_AOS(const cat021_item295_ext1 * item)
{
   return GET_BITS(item->AOS, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT1_AOS;
}

/* =============================== SUBFIELD 2 =============================== */

double get_cat021_item295_ext2_TRD(const cat021_item295_ext2 * item)
{
   return GET_BITS(item->TRD, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT2_TRD;
}

/* =============================== SUBFIELD 3 =============================== */

double get_cat021_item295_ext3_M3A(const cat021_item295_ext3 * item)
{
   return GET_BITS(item->M3A, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT3_M3A;
}

/* =============================== SUBFIELD 4 =============================== */

double get_cat021_item295_ext4_QI(const cat021_item295_ext4 * item)
{
   return GET_BITS(item->QI, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT4_QI;
}

/* =============================== SUBFIELD 5 =============================== */

double get_cat021_item295_ext5_TI(const cat021_item295_ext5 * item)
{
   return GET_BITS(item->TI, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT5_TI;
}

/* =============================== SUBFIELD 6 =============================== */

double get_cat021_item295_ext6_MAM(const cat021_item295_ext6 * item)
{
   return GET_BITS(item->MAM, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT6_MAM;
}

/* =============================== SUBFIELD 7 =============================== */

double get_cat021_item295_ext7_GH(const cat021_item295_ext7 * item)
{
   return GET_BITS(item->GH, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT7_GH;
}

/* =============================== SUBFIELD 8 =============================== */

double get_cat021_item295_ext8_FL(const cat021_item295_ext8 * item)
{
   return GET_BITS(item->FL, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT8_FL;
}

/* =============================== SUBFIELD 9 =============================== */

double get_cat021_item295_ext9_SAL(const cat021_item295_ext9 * item)
{
   return GET_BITS(item->SAL, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT9_SAL;
}

/* =============================== SUBFIELD 10 ============================== */

double get_cat021_item295_ext10_FSA(const cat021_item295_ext10 * item)
{
   return GET_BITS(item->FSA, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT10_FSA;
}

/* =============================== SUBFIELD 11 ============================== */

double get_cat021_item295_ext11_AS(const cat021_item295_ext11 * item)
{
   return GET_BITS(item->AS, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT11_AS;
}

/* =============================== SUBFIELD 12 ============================== */

double get_cat021_item295_ext12_TAS(const cat021_item295_ext12 * item)
{
   return GET_BITS(item->TAS, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT12_TAS;
}

/* =============================== SUBFIELD 13 ============================== */

double get_cat021_item295_ext13_MH(const cat021_item295_ext13 * item)
{
   return GET_BITS(item->MH, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT13_MH;
}

/* =============================== SUBFIELD 14 ============================== */

double get_cat021_item295_ext14_BVR(const cat021_item295_ext14 * item)
{
   return GET_BITS(item->BVR, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT14_BVR;
}

/* =============================== SUBFIELD 15 ============================== */

double get_cat021_item295_ext15_GVR(const cat021_item295_ext15 * item)
{
   return GET_BITS(item->GVR, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT15_GVR;
}

/* =============================== SUBFIELD 16 ============================== */

double get_cat021_item295_ext16_GV(const cat021_item295_ext16 * item)
{
   return GET_BITS(item->GV, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT16_GV;
}

/* =============================== SUBFIELD 17 ============================== */

double get_cat021_item295_ext17_TAR(const cat021_item295_ext17 * item)
{
   return GET_BITS(item->TAR, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT17_TAR;
}

/* =============================== SUBFIELD 18 ============================== */

double get_cat021_item295_ext18_TID(const cat021_item295_ext18 * item)
{
   return GET_BITS(item->TID, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT18_TID;
}

/* =============================== SUBFIELD 19 ============================== */

double get_cat021_item295_ext19_TS(const cat021_item295_ext19 * item)
{
   return GET_BITS(item->TS, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT19_TS;
}

/* =============================== SUBFIELD 20 ============================== */

double get_cat021_item295_ext20_MET(const cat021_item295_ext20 * item)
{
   return GET_BITS(item->MET, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT20_MET;
}

/* =============================== SUBFIELD 21 ============================== */

double get_cat021_item295_ext21_ROA(const cat021_item295_ext21 * item)
{
   return GET_BITS(item->ROA, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT21_ROA;
}

/* =============================== SUBFIELD 22 ============================== */

double get_cat021_item295_ext22_ARA(const cat021_item295_ext22 * item)
{
   return GET_BITS(item->ARA, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT22_ARA;
}

/* =============================== SUBFIELD 23 ============================== */

double get_cat021_item295_ext23_SCC(const cat021_item295_ext23 * item)
{
   return GET_BITS(item->SCC, 1, MASK_08_BITS) * CAT021_ITEM295_LSB_EXT23_SCC;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

void set_cat021_item295_AOS(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 8);
}

void set_cat021_item295_TRD(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 7);
}

void set_cat021_item295_M3A(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 6);
}

void set_cat021_item295_QI(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 5);
}

void set_cat021_item295_TI(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 4);
}

void set_cat021_item295_MAM(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 3);
}

void set_cat021_item295_GH(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 2);
}

void set_cat021_item295_FX1(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 1);
}

void set_cat021_item295_FL(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 8);
}

void set_cat021_item295_SAL(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 7);
}

void set_cat021_item295_FSA(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 6);
}

void set_cat021_item295_AS(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 5);
}

void set_cat021_item295_TAS(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 4);
}

void set_cat021_item295_MH(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 3);
}

void set_cat021_item295_BVR(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 2);
}

void set_cat021_item295_FX2(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 1);
}

void set_cat021_item295_GVR(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 8);
}

void set_cat021_item295_GV(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 7);
}

void set_cat021_item295_TAR(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 6);
}

void set_cat021_item295_TID(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 5);
}

void set_cat021_item295_TS(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 4);
}

void set_cat021_item295_MET(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 3);
}

void set_cat021_item295_ROA(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 2);
}

void set_cat021_item295_FX3(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 1);
}

void set_cat021_item295_ARA(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[3]), value, MASK_01_BITS, 8);
}

void set_cat021_item295_SCC(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[3]), value, MASK_01_BITS, 7);
}

void set_cat021_item295_FX4(cat021_item295 * item, const uint8_t value)
{
    SET_BITS(&(item->raw[3]), value, MASK_01_BITS, 1);
}

/* =============================== SUBFIELD 1 =============================== */

void set_cat021_item295_ext1_AOS(cat021_item295_ext1 * item,
                                 const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT1_AOS);

    SET_BITS(&(item->AOS), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 2 =============================== */

void set_cat021_item295_ext2_TRD(cat021_item295_ext2 * item,
                                 const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT2_TRD);

    SET_BITS(&(item->TRD), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 3 =============================== */

void set_cat021_item295_ext3_M3A(cat021_item295_ext3 * item,
                                 const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT3_M3A);

    SET_BITS(&(item->M3A), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 4 =============================== */

void set_cat021_item295_ext4_QI(cat021_item295_ext4 * item,
                                const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT4_QI);

    SET_BITS(&(item->QI), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 5 =============================== */

void set_cat021_item295_ext5_TI(cat021_item295_ext5 * item,
                                const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT5_TI);

    SET_BITS(&(item->TI), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 6 =============================== */

void set_cat021_item295_ext6_MAM(cat021_item295_ext6 * item,
                                 const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT6_MAM);

    SET_BITS(&(item->MAM), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 7 =============================== */

void set_cat021_item295_ext7_GH(cat021_item295_ext7 * item,
                                const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT7_GH);

    SET_BITS(&(item->GH), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 8 =============================== */

void set_cat021_item295_ext8_FL(cat021_item295_ext8 * item,
                                const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT8_FL);

    SET_BITS(&(item->FL), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 9 =============================== */

void set_cat021_item295_ext9_SAL(cat021_item295_ext9 * item,
                                 const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT9_SAL);

    SET_BITS(&(item->SAL), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 10 ============================== */

void set_cat021_item295_ext10_FSA(cat021_item295_ext10 * item,
                                  const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT10_FSA);

    SET_BITS(&(item->FSA), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 11 ============================== */

void set_cat021_item295_ext11_AS(cat021_item295_ext11 * item,
                                 const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT11_AS);

    SET_BITS(&(item->AS), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 12 ============================== */

void set_cat021_item295_ext12_TAS(cat021_item295_ext12 * item,
                                  const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT12_TAS);

    SET_BITS(&(item->TAS), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 13 ============================== */

void set_cat021_item295_ext13_MH(cat021_item295_ext13 * item,
                                 const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT13_MH);

    SET_BITS(&(item->MH), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 14 ============================== */

void set_cat021_item295_ext14_BVR(cat021_item295_ext14 * item,
                                  const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT14_BVR);

    SET_BITS(&(item->BVR), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 15 ============================== */

void set_cat021_item295_ext15_GVR(cat021_item295_ext15 * item,
                                  const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT15_GVR);

    SET_BITS(&(item->GVR), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 16 ============================== */

void set_cat021_item295_ext16_GV(cat021_item295_ext16 * item,
                                 const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT16_GV);

    SET_BITS(&(item->GV), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 17 ============================== */

void set_cat021_item295_ext17_TAR(cat021_item295_ext17 * item,
                                  const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT17_TAR);

    SET_BITS(&(item->TAR), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 18 ============================== */

void set_cat021_item295_ext18_TID(cat021_item295_ext18 * item,
                                  const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT18_TID);

    SET_BITS(&(item->TID), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 19 ============================== */

void set_cat021_item295_ext19_TS(cat021_item295_ext19 * item,
                                 const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT19_TS);

    SET_BITS(&(item->TS), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 20 ============================== */

void set_cat021_item295_ext20_MET(cat021_item295_ext20 * item,
                                  const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT20_MET);

    SET_BITS(&(item->MET), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 21 ============================== */

void set_cat021_item295_ext21_ROA(cat021_item295_ext21 * item,
                                 const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT21_ROA);

    SET_BITS(&(item->ROA), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 22 ============================== */

void set_cat021_item295_ext22_ARA(cat021_item295_ext22 * item,
                                  const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT22_ARA);

    SET_BITS(&(item->ARA), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 23 ============================== */

void set_cat021_item295_ext23_SCC(cat021_item295_ext23 * item,
                                  const double value)
{
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / CAT021_ITEM295_LSB_EXT23_SCC);

    SET_BITS(&(item->SCC), value_raw, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item295(const cat021_item295 * item)
{
    printf("Category 021 Item 295 - Data Ages\n");
    printf("  AOS = %d\n", get_cat021_item295_AOS(item));
    printf("  TRD = %d\n", get_cat021_item295_TRD(item));
    printf("  M3A = %d\n", get_cat021_item295_M3A(item));
    printf("  QI = %d\n", get_cat021_item295_QI(item));
    printf("  TI = %d\n", get_cat021_item295_TI(item));
    printf("  MAM = %d\n", get_cat021_item295_MAM(item));
    printf("  GH = %d\n", get_cat021_item295_GH(item));
    printf("  FX1 = %d\n", get_cat021_item295_FX1(item));
    printf("  FL = %d\n", get_cat021_item295_FL(item));
    printf("  SAL = %d\n", get_cat021_item295_SAL(item));
    printf("  FSA = %d\n", get_cat021_item295_FSA(item));
    printf("  AS = %d\n", get_cat021_item295_AS(item));
    printf("  TAS = %d\n", get_cat021_item295_TAS(item));
    printf("  MH = %d\n", get_cat021_item295_MH(item));
    printf("  BVR = %d\n", get_cat021_item295_BVR(item));
    printf("  FX2 = %d\n", get_cat021_item295_FX2(item));
    printf("  GVR = %d\n", get_cat021_item295_GVR(item));
    printf("  GV = %d\n", get_cat021_item295_GV(item));
    printf("  TAR = %d\n", get_cat021_item295_TAR(item));
    printf("  TID = %d\n", get_cat021_item295_TID(item));
    printf("  TS = %d\n", get_cat021_item295_TS(item));
    printf("  MET = %d\n", get_cat021_item295_MET(item));
    printf("  ROA = %d\n", get_cat021_item295_ROA(item));
    printf("  FX3 = %d\n", get_cat021_item295_FX3(item));
    printf("  ARA = %d\n", get_cat021_item295_ARA(item));
    printf("  SCC = %d\n", get_cat021_item295_SCC(item));
    printf("  FX4 = %d\n", get_cat021_item295_FX4(item));

    if (get_cat021_item295_AOS(item))
        printf("  ext1_AOS = %f\n", get_cat021_item295_ext1_AOS(&(item->ext1)));

    if (get_cat021_item295_TRD(item))
        printf("  ext2_TRD = %f\n", get_cat021_item295_ext2_TRD(&(item->ext2)));

    if (get_cat021_item295_M3A(item))
        printf("  ext3_M3A = %f\n", get_cat021_item295_ext3_M3A(&(item->ext3)));

    if (get_cat021_item295_QI(item))
        printf("  ext4_QI = %f\n", get_cat021_item295_ext4_QI(&(item->ext4)));

    if (get_cat021_item295_TI(item))
        printf("  ext5_TI = %f\n", get_cat021_item295_ext5_TI(&(item->ext5)));

    if (get_cat021_item295_MAM(item))
        printf("  ext6_MAM = %f\n", get_cat021_item295_ext6_MAM(&(item->ext6)));

    if (get_cat021_item295_GH(item))
        printf("  ext7_GH = %f\n", get_cat021_item295_ext7_GH(&(item->ext7)));

    if (get_cat021_item295_FX1(item))
        printf("  ext8_FL = %f\n", get_cat021_item295_ext8_FL(&(item->ext8)));

    if (get_cat021_item295_SAL(item))
        printf("  ext9_SAL = %f\n", get_cat021_item295_ext9_SAL(&(item->ext9)));

    if (get_cat021_item295_FSA(item))
        printf("  ext10_FSA = %f\n", get_cat021_item295_ext10_FSA(&(item->ext10)));

    if (get_cat021_item295_AS(item))
        printf("  ext11_AS = %f\n", get_cat021_item295_ext11_AS(&(item->ext11)));

    if (get_cat021_item295_TAS(item))
        printf("  ext12_TAS = %f\n", get_cat021_item295_ext12_TAS(&(item->ext12)));

    if (get_cat021_item295_MH(item))
        printf("  ext13_MH = %f\n", get_cat021_item295_ext13_MH(&(item->ext13)));

    if (get_cat021_item295_BVR(item))
        printf("  ext14_BVR = %f\n", get_cat021_item295_ext14_BVR(&(item->ext14)));

    if (get_cat021_item295_GVR(item))
        printf("  ext15_GVR = %f\n", get_cat021_item295_ext15_GVR(&(item->ext15)));

    if (get_cat021_item295_GV(item))
        printf("  ext16_GV = %f\n", get_cat021_item295_ext16_GV(&(item->ext16)));

    if (get_cat021_item295_TAR(item))
        printf("  ext17_TAR = %f\n", get_cat021_item295_ext17_TAR(&(item->ext17)));

    if (get_cat021_item295_TID(item))
        printf("  ext18_TID = %f\n", get_cat021_item295_ext18_TID(&(item->ext18)));

    if (get_cat021_item295_TS(item))
        printf("  ext19_TS = %f\n", get_cat021_item295_ext19_TS(&(item->ext19)));

    if (get_cat021_item295_MET(item))
        printf("  ext20_MET = %f\n", get_cat021_item295_ext20_MET(&(item->ext20)));

    if (get_cat021_item295_ROA(item))
        printf("  ext21_ROA = %f\n", get_cat021_item295_ext21_ROA(&(item->ext21)));

    if (get_cat021_item295_ARA(item))
        printf("  ext22_ARA = %f\n", get_cat021_item295_ext22_ARA(&(item->ext22)));

    if (get_cat021_item295_SCC(item))
        printf("  ext23_SCC = %f\n", get_cat021_item295_ext23_SCC(&(item->ext23)));
}
