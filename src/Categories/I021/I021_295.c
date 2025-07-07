/**
 * @file I021_295.c
 * @brief Implementation of the Category 21 Item 295 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_295.h"


/*******************************************************************************
 * Getters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

uint8_t get_I021_295_AOS(const I021_295 * item) {
    return GET_BITS(item->raw[0], 8, MASK_01_BITS);
}

uint8_t get_I021_295_TRD(const I021_295 * item) {
    return GET_BITS(item->raw[0], 7, MASK_01_BITS);
}

uint8_t get_I021_295_M3A(const I021_295 * item) {
    return GET_BITS(item->raw[0], 6, MASK_01_BITS);
}

uint8_t get_I021_295_QI(const I021_295 * item) {
    return GET_BITS(item->raw[0], 5, MASK_01_BITS);
}

uint8_t get_I021_295_TI(const I021_295 * item) {
    return GET_BITS(item->raw[0], 4, MASK_01_BITS);
}

uint8_t get_I021_295_MAM(const I021_295 * item) {
    return GET_BITS(item->raw[0], 3, MASK_01_BITS);
}

uint8_t get_I021_295_GH(const I021_295 * item) {
    return GET_BITS(item->raw[0], 2, MASK_01_BITS);
}

uint8_t get_I021_295_FX1(const I021_295 * item) {
    return GET_BITS(item->raw[0], 1, MASK_01_BITS);
}

uint8_t get_I021_295_FL(const I021_295 * item) {
    return GET_BITS(item->raw[1], 8, MASK_01_BITS);
}

uint8_t get_I021_295_SAL(const I021_295 * item) {
    return GET_BITS(item->raw[1], 7, MASK_01_BITS);
}

uint8_t get_I021_295_FSA(const I021_295 * item) {
    return GET_BITS(item->raw[1], 6, MASK_01_BITS);
}

uint8_t get_I021_295_AS(const I021_295 * item) {
    return GET_BITS(item->raw[1], 5, MASK_01_BITS);
}

uint8_t get_I021_295_TAS(const I021_295 * item) {
    return GET_BITS(item->raw[1], 4, MASK_01_BITS);
}

uint8_t get_I021_295_MH(const I021_295 * item) {
    return GET_BITS(item->raw[1], 3, MASK_01_BITS);
}

uint8_t get_I021_295_BVR(const I021_295 * item) {
    return GET_BITS(item->raw[1], 2, MASK_01_BITS);
}

uint8_t get_I021_295_FX2(const I021_295 * item) {
    return GET_BITS(item->raw[1], 1, MASK_01_BITS);
}

uint8_t get_I021_295_GVR(const I021_295 * item) {
    return GET_BITS(item->raw[2], 8, MASK_01_BITS);
}

uint8_t get_I021_295_GV(const I021_295 * item) {
    return GET_BITS(item->raw[2], 7, MASK_01_BITS);
}

uint8_t get_I021_295_TAR(const I021_295 * item) {
    return GET_BITS(item->raw[2], 6, MASK_01_BITS);
}

uint8_t get_I021_295_TID(const I021_295 * item) {
    return GET_BITS(item->raw[2], 5, MASK_01_BITS);
}

uint8_t get_I021_295_TS(const I021_295 * item) {
    return GET_BITS(item->raw[2], 4, MASK_01_BITS);
}

uint8_t get_I021_295_MET(const I021_295 * item) {
    return GET_BITS(item->raw[2], 3, MASK_01_BITS);
}

uint8_t get_I021_295_ROA(const I021_295 * item) {
    return GET_BITS(item->raw[2], 2, MASK_01_BITS);
}

uint8_t get_I021_295_FX3(const I021_295 * item) {
    return GET_BITS(item->raw[2], 1, MASK_01_BITS);
}

uint8_t get_I021_295_ARA(const I021_295 * item) {
    return GET_BITS(item->raw[3], 8, MASK_01_BITS);
}

uint8_t get_I021_295_SCC(const I021_295 * item) {
    return GET_BITS(item->raw[3], 7, MASK_01_BITS);
}

uint8_t get_I021_295_FX4(const I021_295 * item) {
    return GET_BITS(item->raw[3], 1, MASK_01_BITS);
}

/* =============================== SUBFIELD 1 =============================== */

double get_I021_295_EXT1_AOS(const I021_295_EXT1 * item) {
   return GET_BITS(item->AOS, 1, MASK_08_BITS) * I021_295_LSB_EXT1_AOS;
}

/* =============================== SUBFIELD 2 =============================== */

double get_I021_295_EXT2_TRD(const I021_295_EXT2 * item) {
   return GET_BITS(item->TRD, 1, MASK_08_BITS) * I021_295_LSB_EXT2_TRD;
}

/* =============================== SUBFIELD 3 =============================== */

double get_I021_295_EXT3_M3A(const I021_295_EXT3 * item) {
   return GET_BITS(item->M3A, 1, MASK_08_BITS) * I021_295_LSB_EXT3_M3A;
}

/* =============================== SUBFIELD 4 =============================== */

double get_I021_295_EXT4_QI(const I021_295_EXT4 * item) {
   return GET_BITS(item->QI, 1, MASK_08_BITS) * I021_295_LSB_EXT4_QI;
}

/* =============================== SUBFIELD 5 =============================== */

double get_I021_295_EXT5_TI(const I021_295_EXT5 * item) {
   return GET_BITS(item->TI, 1, MASK_08_BITS) * I021_295_LSB_EXT5_TI;
}

/* =============================== SUBFIELD 6 =============================== */

double get_I021_295_EXT6_MAM(const I021_295_EXT6 * item) {
   return GET_BITS(item->MAM, 1, MASK_08_BITS) * I021_295_LSB_EXT6_MAM;
}

/* =============================== SUBFIELD 7 =============================== */

double get_I021_295_EXT7_GH(const I021_295_EXT7 * item) {
   return GET_BITS(item->GH, 1, MASK_08_BITS) * I021_295_LSB_EXT7_GH;
}

/* =============================== SUBFIELD 8 =============================== */

double get_I021_295_EXT8_FL(const I021_295_EXT8 * item) {
   return GET_BITS(item->FL, 1, MASK_08_BITS) * I021_295_LSB_EXT8_FL;
}

/* =============================== SUBFIELD 9 =============================== */

double get_I021_295_EXT9_SAL(const I021_295_EXT9 * item) {
   return GET_BITS(item->SAL, 1, MASK_08_BITS) * I021_295_LSB_EXT9_SAL;
}

/* =============================== SUBFIELD 10 ============================== */

double get_I021_295_EXT10_FSA(const I021_295_EXT10 * item) {
   return GET_BITS(item->FSA, 1, MASK_08_BITS) * I021_295_LSB_EXT10_FSA;
}

/* =============================== SUBFIELD 11 ============================== */

double get_I021_295_EXT11_AS(const I021_295_EXT11 * item) {
   return GET_BITS(item->AS, 1, MASK_08_BITS) * I021_295_LSB_EXT11_AS;
}

/* =============================== SUBFIELD 12 ============================== */

double get_I021_295_EXT12_TAS(const I021_295_EXT12 * item) {
   return GET_BITS(item->TAS, 1, MASK_08_BITS) * I021_295_LSB_EXT12_TAS;
}

/* =============================== SUBFIELD 13 ============================== */

double get_I021_295_EXT13_MH(const I021_295_EXT13 * item) {
   return GET_BITS(item->MH, 1, MASK_08_BITS) * I021_295_LSB_EXT13_MH;
}

/* =============================== SUBFIELD 14 ============================== */

double get_I021_295_EXT14_BVR(const I021_295_EXT14 * item) {
   return GET_BITS(item->BVR, 1, MASK_08_BITS) * I021_295_LSB_EXT14_BVR;
}

/* =============================== SUBFIELD 15 ============================== */

double get_I021_295_EXT15_GVR(const I021_295_EXT15 * item) {
   return GET_BITS(item->GVR, 1, MASK_08_BITS) * I021_295_LSB_EXT15_GVR;
}

/* =============================== SUBFIELD 16 ============================== */

double get_I021_295_EXT16_GV(const I021_295_EXT16 * item) {
   return GET_BITS(item->GV, 1, MASK_08_BITS) * I021_295_LSB_EXT16_GV;
}

/* =============================== SUBFIELD 17 ============================== */

double get_I021_295_EXT17_TAR(const I021_295_EXT17 * item) {
   return GET_BITS(item->TAR, 1, MASK_08_BITS) * I021_295_LSB_EXT17_TAR;
}

/* =============================== SUBFIELD 18 ============================== */

double get_I021_295_EXT18_TID(const I021_295_EXT18 * item) {
   return GET_BITS(item->TID, 1, MASK_08_BITS) * I021_295_LSB_EXT18_TID;
}

/* =============================== SUBFIELD 19 ============================== */

double get_I021_295_EXT19_TS(const I021_295_EXT19 * item) {
   return GET_BITS(item->TS, 1, MASK_08_BITS) * I021_295_LSB_EXT19_TS;
}

/* =============================== SUBFIELD 20 ============================== */

double get_I021_295_EXT20_MET(const I021_295_EXT20 * item) {
   return GET_BITS(item->MET, 1, MASK_08_BITS) * I021_295_LSB_EXT20_MET;
}

/* =============================== SUBFIELD 21 ============================== */

double get_I021_295_EXT21_ROA(const I021_295_EXT21 * item) {
   return GET_BITS(item->ROA, 1, MASK_08_BITS) * I021_295_LSB_EXT21_ROA;
}

/* =============================== SUBFIELD 22 ============================== */

double get_I021_295_EXT22_ARA(const I021_295_EXT22 * item) {
   return GET_BITS(item->ARA, 1, MASK_08_BITS) * I021_295_LSB_EXT22_ARA;
}

/* =============================== SUBFIELD 23 ============================== */

double get_I021_295_EXT23_SCC(const I021_295_EXT23 * item) {
   return GET_BITS(item->SCC, 1, MASK_08_BITS) * I021_295_LSB_EXT23_SCC;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

void set_I021_295_AOS(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 8);
}

void set_I021_295_TRD(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 7);
}

void set_I021_295_M3A(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 6);
}

void set_I021_295_QI(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 5);
}

void set_I021_295_TI(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 4);
}

void set_I021_295_MAM(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 3);
}

void set_I021_295_GH(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 2);
}

void set_I021_295_FX1(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[0]), value, MASK_01_BITS, 1);
}

void set_I021_295_FL(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 8);
}

void set_I021_295_SAL(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 7);
}

void set_I021_295_FSA(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 6);
}

void set_I021_295_AS(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 5);
}

void set_I021_295_TAS(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 4);
}

void set_I021_295_MH(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 3);
}

void set_I021_295_BVR(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 2);
}

void set_I021_295_FX2(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[1]), value, MASK_01_BITS, 1);
}

void set_I021_295_GVR(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 8);
}

void set_I021_295_GV(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 7);
}

void set_I021_295_TAR(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 6);
}

void set_I021_295_TID(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 5);
}

void set_I021_295_TS(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 4);
}

void set_I021_295_MET(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 3);
}

void set_I021_295_ROA(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 2);
}

void set_I021_295_FX3(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[2]), value, MASK_01_BITS, 1);
}

void set_I021_295_ARA(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[3]), value, MASK_01_BITS, 8);
}

void set_I021_295_SCC(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[3]), value, MASK_01_BITS, 7);
}

void set_I021_295_FX4(I021_295 * item, const uint8_t value) {
    SET_BITS(&(item->raw[3]), value, MASK_01_BITS, 1);
}

/* =============================== SUBFIELD 1 =============================== */

void set_I021_295_EXT1_AOS(I021_295_EXT1 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT1_AOS);

    SET_BITS(&(item->AOS), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 2 =============================== */

void set_I021_295_EXT2_TRD(I021_295_EXT2 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT2_TRD);

    SET_BITS(&(item->TRD), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 3 =============================== */

void set_I021_295_EXT3_M3A(I021_295_EXT3 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT3_M3A);

    SET_BITS(&(item->M3A), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 4 =============================== */

void set_I021_295_EXT4_QI(I021_295_EXT4 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT4_QI);

    SET_BITS(&(item->QI), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 5 =============================== */

void set_I021_295_EXT5_TI(I021_295_EXT5 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT5_TI);

    SET_BITS(&(item->TI), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 6 =============================== */

void set_I021_295_EXT6_MAM(I021_295_EXT6 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT6_MAM);

    SET_BITS(&(item->MAM), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 7 =============================== */

void set_I021_295_EXT7_GH(I021_295_EXT7 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT7_GH);

    SET_BITS(&(item->GH), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 8 =============================== */

void set_I021_295_EXT8_FL(I021_295_EXT8 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT8_FL);

    SET_BITS(&(item->FL), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 9 =============================== */

void set_I021_295_EXT9_SAL(I021_295_EXT9 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT9_SAL);

    SET_BITS(&(item->SAL), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 10 ============================== */

void set_I021_295_EXT10_FSA(I021_295_EXT10 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT10_FSA);

    SET_BITS(&(item->FSA), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 11 ============================== */

void set_I021_295_EXT11_AS(I021_295_EXT11 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT11_AS);

    SET_BITS(&(item->AS), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 12 ============================== */

void set_I021_295_EXT12_TAS(I021_295_EXT12 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT12_TAS);

    SET_BITS(&(item->TAS), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 13 ============================== */

void set_I021_295_EXT13_MH(I021_295_EXT13 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT13_MH);

    SET_BITS(&(item->MH), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 14 ============================== */

void set_I021_295_EXT14_BVR(I021_295_EXT14 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT14_BVR);

    SET_BITS(&(item->BVR), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 15 ============================== */

void set_I021_295_EXT15_GVR(I021_295_EXT15 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT15_GVR);

    SET_BITS(&(item->GVR), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 16 ============================== */

void set_I021_295_EXT16_GV(I021_295_EXT16 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT16_GV);

    SET_BITS(&(item->GV), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 17 ============================== */

void set_I021_295_EXT17_TAR(I021_295_EXT17 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT17_TAR);

    SET_BITS(&(item->TAR), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 18 ============================== */

void set_I021_295_EXT18_TID(I021_295_EXT18 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT18_TID);

    SET_BITS(&(item->TID), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 19 ============================== */

void set_I021_295_EXT19_TS(I021_295_EXT19 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT19_TS);

    SET_BITS(&(item->TS), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 20 ============================== */

void set_I021_295_EXT20_MET(I021_295_EXT20 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT20_MET);

    SET_BITS(&(item->MET), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 21 ============================== */

void set_I021_295_EXT21_ROA(I021_295_EXT21 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT21_ROA);

    SET_BITS(&(item->ROA), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 22 ============================== */

void set_I021_295_EXT22_ARA(I021_295_EXT22 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT22_ARA);

    SET_BITS(&(item->ARA), value_raw, MASK_08_BITS, 1);
}

/* =============================== SUBFIELD 23 ============================== */

void set_I021_295_EXT23_SCC(I021_295_EXT23 * item, const double value) {
    uint8_t value_raw = 0;

    if (value > 0)
        value_raw = (uint8_t) (value / I021_295_LSB_EXT23_SCC);

    SET_BITS(&(item->SCC), value_raw, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_295(const I021_295 * item) {
    printf("Category 021 Item 295 - Data Ages\n");
    printf("  AOS = %d\n", get_I021_295_AOS(item));
    printf("  TRD = %d\n", get_I021_295_TRD(item));
    printf("  M3A = %d\n", get_I021_295_M3A(item));
    printf("  QI = %d\n", get_I021_295_QI(item));
    printf("  TI = %d\n", get_I021_295_TI(item));
    printf("  MAM = %d\n", get_I021_295_MAM(item));
    printf("  GH = %d\n", get_I021_295_GH(item));
    printf("  FX1 = %d\n", get_I021_295_FX1(item));
    printf("  FL = %d\n", get_I021_295_FL(item));
    printf("  SAL = %d\n", get_I021_295_SAL(item));
    printf("  FSA = %d\n", get_I021_295_FSA(item));
    printf("  AS = %d\n", get_I021_295_AS(item));
    printf("  TAS = %d\n", get_I021_295_TAS(item));
    printf("  MH = %d\n", get_I021_295_MH(item));
    printf("  BVR = %d\n", get_I021_295_BVR(item));
    printf("  FX2 = %d\n", get_I021_295_FX2(item));
    printf("  GVR = %d\n", get_I021_295_GVR(item));
    printf("  GV = %d\n", get_I021_295_GV(item));
    printf("  TAR = %d\n", get_I021_295_TAR(item));
    printf("  TID = %d\n", get_I021_295_TID(item));
    printf("  TS = %d\n", get_I021_295_TS(item));
    printf("  MET = %d\n", get_I021_295_MET(item));
    printf("  ROA = %d\n", get_I021_295_ROA(item));
    printf("  FX3 = %d\n", get_I021_295_FX3(item));
    printf("  ARA = %d\n", get_I021_295_ARA(item));
    printf("  SCC = %d\n", get_I021_295_SCC(item));
    printf("  FX4 = %d\n", get_I021_295_FX4(item));

    if (get_I021_295_AOS(item))
        printf("  EXT1_AOS = %f\n", get_I021_295_EXT1_AOS(&(item->ext1)));

    if (get_I021_295_TRD(item))
        printf("  EXT2_TRD = %f\n", get_I021_295_EXT2_TRD(&(item->ext2)));

    if (get_I021_295_M3A(item))
        printf("  EXT3_M3A = %f\n", get_I021_295_EXT3_M3A(&(item->ext3)));

    if (get_I021_295_QI(item))
        printf("  EXT4_QI = %f\n", get_I021_295_EXT4_QI(&(item->ext4)));

    if (get_I021_295_TI(item))
        printf("  EXT5_TI = %f\n", get_I021_295_EXT5_TI(&(item->ext5)));

    if (get_I021_295_MAM(item))
        printf("  EXT6_MAM = %f\n", get_I021_295_EXT6_MAM(&(item->ext6)));

    if (get_I021_295_GH(item))
        printf("  EXT7_GH = %f\n", get_I021_295_EXT7_GH(&(item->ext7)));

    if (get_I021_295_FX1(item))
        printf("  EXT8_FL = %f\n", get_I021_295_EXT8_FL(&(item->ext8)));

    if (get_I021_295_SAL(item))
        printf("  EXT9_SAL = %f\n", get_I021_295_EXT9_SAL(&(item->ext9)));

    if (get_I021_295_FSA(item))
        printf("  EXT10_FSA = %f\n", get_I021_295_EXT10_FSA(&(item->ext10)));

    if (get_I021_295_AS(item))
        printf("  EXT11_AS = %f\n", get_I021_295_EXT11_AS(&(item->ext11)));

    if (get_I021_295_TAS(item))
        printf("  EXT12_TAS = %f\n", get_I021_295_EXT12_TAS(&(item->ext12)));

    if (get_I021_295_MH(item))
        printf("  EXT13_MH = %f\n", get_I021_295_EXT13_MH(&(item->ext13)));

    if (get_I021_295_BVR(item))
        printf("  EXT14_BVR = %f\n", get_I021_295_EXT14_BVR(&(item->ext14)));

    if (get_I021_295_GVR(item))
        printf("  EXT15_GVR = %f\n", get_I021_295_EXT15_GVR(&(item->ext15)));

    if (get_I021_295_GV(item))
        printf("  EXT16_GV = %f\n", get_I021_295_EXT16_GV(&(item->ext16)));

    if (get_I021_295_TAR(item))
        printf("  EXT17_TAR = %f\n", get_I021_295_EXT17_TAR(&(item->ext17)));

    if (get_I021_295_TID(item))
        printf("  EXT18_TID = %f\n", get_I021_295_EXT18_TID(&(item->ext18)));

    if (get_I021_295_TS(item))
        printf("  EXT19_TS = %f\n", get_I021_295_EXT19_TS(&(item->ext19)));

    if (get_I021_295_MET(item))
        printf("  EXT20_MET = %f\n", get_I021_295_EXT20_MET(&(item->ext20)));

    if (get_I021_295_ROA(item))
        printf("  EXT21_ROA = %f\n", get_I021_295_EXT21_ROA(&(item->ext21)));

    if (get_I021_295_ARA(item))
        printf("  EXT22_ARA = %f\n", get_I021_295_EXT22_ARA(&(item->ext22)));

    if (get_I021_295_SCC(item))
        printf("  EXT23_SCC = %f\n", get_I021_295_EXT23_SCC(&(item->ext23)));
}
