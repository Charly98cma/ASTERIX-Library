/**
 * @file I021_295.c
 * @brief Implementation of the Category 21 Item 295 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_295.h"


/*******************************************************************************
 * Getters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

uint8_t get_I021_295_AOS(const I021_295 * item) {
    return (item->raw[0] >> 7) & MASK_01_BITS;
}

uint8_t get_I021_295_TRD(const I021_295 * item) {
    return (item->raw[0] >> 6) & MASK_01_BITS;
}

uint8_t get_I021_295_M3A(const I021_295 * item) {
    return (item->raw[0] >> 5) & MASK_01_BITS;
}

uint8_t get_I021_295_QI(const I021_295 * item) {
    return (item->raw[0] >> 4) & MASK_01_BITS;
}

uint8_t get_I021_295_TI(const I021_295 * item) {
    return (item->raw[0] >> 3) & MASK_01_BITS;
}

uint8_t get_I021_295_MAM(const I021_295 * item) {
    return (item->raw[0] >> 2) & MASK_01_BITS;
}

uint8_t get_I021_295_GH(const I021_295 * item) {
    return (item->raw[0] >> 1) & MASK_01_BITS;
}

uint8_t get_I021_295_FX1(const I021_295 * item) {
    return item->raw[0] & MASK_01_BITS;
}

uint8_t get_I021_295_FL(const I021_295 * item) {
    return (item->raw[1] >> 7) & MASK_01_BITS;
}

uint8_t get_I021_295_SAL(const I021_295 * item) {
    return (item->raw[1] >> 6) & MASK_01_BITS;
}

uint8_t get_I021_295_FSA(const I021_295 * item) {
    return (item->raw[1] >> 5) & MASK_01_BITS;
}

uint8_t get_I021_295_AS(const I021_295 * item) {
    return (item->raw[1] >> 4) & MASK_01_BITS;
}

uint8_t get_I021_295_TAS(const I021_295 * item) {
    return (item->raw[1] >> 3) & MASK_01_BITS;
}

uint8_t get_I021_295_MH(const I021_295 * item) {
    return (item->raw[1] >> 2) & MASK_01_BITS;
}

uint8_t get_I021_295_BVR(const I021_295 * item) {
    return (item->raw[1] >> 1) & MASK_01_BITS;
}

uint8_t get_I021_295_FX2(const I021_295 * item) {
    return item->raw[1] & MASK_01_BITS;
}

uint8_t get_I021_295_GVR(const I021_295 * item) {
    return (item->raw[2] >> 7) & MASK_01_BITS;
}

uint8_t get_I021_295_GV(const I021_295 * item) {
    return (item->raw[2] >> 6) & MASK_01_BITS;
}

uint8_t get_I021_295_TAR(const I021_295 * item) {
    return (item->raw[2] >> 5) & MASK_01_BITS;
}

uint8_t get_I021_295_TID(const I021_295 * item) {
    return (item->raw[2] >> 4) & MASK_01_BITS;
}

uint8_t get_I021_295_TS(const I021_295 * item) {
    return (item->raw[2] >> 3) & MASK_01_BITS;
}

uint8_t get_I021_295_MET(const I021_295 * item) {
    return (item->raw[2] >> 2) & MASK_01_BITS;
}

uint8_t get_I021_295_ROA(const I021_295 * item) {
    return (item->raw[2] >> 1) & MASK_01_BITS;
}

uint8_t get_I021_295_FX3(const I021_295 * item) {
    return item->raw[2] & MASK_01_BITS;
}

uint8_t get_I021_295_ARA(const I021_295 * item) {
    return (item->raw[3] >> 7) & MASK_01_BITS;
}

uint8_t get_I021_295_SCC(const I021_295 * item) {
    return (item->raw[3] >> 6) & MASK_01_BITS;
}

uint8_t get_I021_295_FX4(const I021_295 * item) {
    return item->raw[3] & MASK_01_BITS;
}

/* =============================== SUBFIELD 1 =============================== */

double get_I021_295_EXT1_AOS(const I021_295_EXT1 * item) {
   return (item->AOS * I021_295_LSB_EXT1_AOS);
}

/* =============================== SUBFIELD 2 =============================== */

double get_I021_295_EXT2_TRD(const I021_295_EXT2 * item) {
   return (item->TRD * I021_295_LSB_EXT2_TRD);
}

/* =============================== SUBFIELD 3 =============================== */

double get_I021_295_EXT3_M3A(const I021_295_EXT3 * item) {
   return (item->M3A * I021_295_LSB_EXT3_M3A);
}

/* =============================== SUBFIELD 4 =============================== */

double get_I021_295_EXT4_QI(const I021_295_EXT4 * item) {
   return (item->QI * I021_295_LSB_EXT4_QI);
}

/* =============================== SUBFIELD 5 =============================== */

double get_I021_295_EXT5_TI(const I021_295_EXT5 * item) {
   return (item->TI * I021_295_LSB_EXT5_TI);
}

/* =============================== SUBFIELD 6 =============================== */

double get_I021_295_EXT6_MAM(const I021_295_EXT6 * item) {
   return (item->MAM * I021_295_LSB_EXT6_MAM);
}

/* =============================== SUBFIELD 7 =============================== */

double get_I021_295_EXT7_GH(const I021_295_EXT7 * item) {
   return (item->GH * I021_295_LSB_EXT7_GH);
}

/* =============================== SUBFIELD 8 =============================== */

double get_I021_295_EXT8_FL(const I021_295_EXT8 * item) {
   return (item->FL * I021_295_LSB_EXT8_FL);
}

/* =============================== SUBFIELD 9 =============================== */

double get_I021_295_EXT9_SAL(const I021_295_EXT9 * item) {
   return (item->SAL * I021_295_LSB_EXT9_SAL);
}

/* =============================== SUBFIELD 10 ============================== */

double get_I021_295_EXT10_FSA(const I021_295_EXT10 * item) {
   return (item->FSA * I021_295_LSB_EXT10_FSA);
}

/* =============================== SUBFIELD 11 ============================== */

double get_I021_295_EXT11_AS(const I021_295_EXT11 * item) {
   return (item->AS * I021_295_LSB_EXT11_AS);
}

/* =============================== SUBFIELD 12 ============================== */

double get_I021_295_EXT12_TAS(const I021_295_EXT12 * item) {
   return (item->TAS * I021_295_LSB_EXT12_TAS);
}

/* =============================== SUBFIELD 13 ============================== */

double get_I021_295_EXT13_MH(const I021_295_EXT13 * item) {
   return (item->MH * I021_295_LSB_EXT13_MH);
}

/* =============================== SUBFIELD 14 ============================== */

double get_I021_295_EXT14_BVR(const I021_295_EXT14 * item) {
   return (item->BVR * I021_295_LSB_EXT14_BVR);
}

/* =============================== SUBFIELD 15 ============================== */

double get_I021_295_EXT15_GVR(const I021_295_EXT15 * item) {
   return (item->GVR * I021_295_LSB_EXT15_GVR);
}

/* =============================== SUBFIELD 16 ============================== */

double get_I021_295_EXT16_GV(const I021_295_EXT16 * item) {
   return (item->GV * I021_295_LSB_EXT16_GV);
}

/* =============================== SUBFIELD 17 ============================== */

double get_I021_295_EXT17_TAR(const I021_295_EXT17 * item) {
   return (item->TAR * I021_295_LSB_EXT17_TAR);
}

/* =============================== SUBFIELD 18 ============================== */

double get_I021_295_EXT18_TID(const I021_295_EXT18 * item) {
   return (item->TID * I021_295_LSB_EXT18_TID);
}

/* =============================== SUBFIELD 19 ============================== */

double get_I021_295_EXT19_TS(const I021_295_EXT19 * item) {
   return (item->TS * I021_295_LSB_EXT19_TS);
}

/* =============================== SUBFIELD 20 ============================== */

double get_I021_295_EXT20_MET(const I021_295_EXT20 * item) {
   return (item->MET * I021_295_LSB_EXT20_MET);
}

/* =============================== SUBFIELD 21 ============================== */

double get_I021_295_EXT21_ROA(const I021_295_EXT21 * item) {
   return (item->ROA * I021_295_LSB_EXT21_ROA);
}

/* =============================== SUBFIELD 22 ============================== */

double get_I021_295_EXT22_ARA(const I021_295_EXT22 * item) {
   return (item->ARA * I021_295_LSB_EXT22_ARA);
}

/* =============================== SUBFIELD 23 ============================== */

double get_I021_295_EXT23_SCC(const I021_295_EXT23 * item) {
   return (item->SCC * I021_295_LSB_EXT23_SCC);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

void set_I021_295_AOS(I021_295 * item, uint8_t ads) {
    item->raw[0] |= (ads & MASK_01_BITS) << 7;
}

void set_I021_295_TRD(I021_295 * item, uint8_t trd) {
    item->raw[0] |= (trd & MASK_01_BITS) << 6;
}

void set_I021_295_M3A(I021_295 * item, uint8_t m3a) {
    item->raw[0] |= (m3a & MASK_01_BITS) << 5;
}

void set_I021_295_QI(I021_295 * item, uint8_t qi) {
    item->raw[0] |= (qi & MASK_01_BITS) << 4;
}

void set_I021_295_TI(I021_295 * item, uint8_t ti) {
    item->raw[0] |= (ti & MASK_01_BITS) << 3;
}

void set_I021_295_MAM(I021_295 * item, uint8_t mam) {
    item->raw[0] |= (mam & MASK_01_BITS) << 2;
}

void set_I021_295_GH(I021_295 * item, uint8_t gh) {
    item->raw[0] |= (gh & MASK_01_BITS) << 1;
}

void set_I021_295_FX1(I021_295 * item, uint8_t fx) {
    item->raw[0] |= fx & MASK_01_BITS;
}

void set_I021_295_FL(I021_295 * item, uint8_t fl) {
    item->raw[1] |= (fl & MASK_01_BITS) << 7;
}

void set_I021_295_SAL(I021_295 * item, uint8_t sal) {
    item->raw[1] |= (sal & MASK_01_BITS) << 6;
}

void set_I021_295_FSA(I021_295 * item, uint8_t fsa) {
    item->raw[1] |= (fsa & MASK_01_BITS) << 5;
}

void set_I021_295_AS(I021_295 * item, uint8_t as) {
    item->raw[1] |= (as & MASK_01_BITS) << 4;
}

void set_I021_295_TAS(I021_295 * item, uint8_t tas) {
    item->raw[1] |= (tas & MASK_01_BITS) << 3;
}

void set_I021_295_MH(I021_295 * item, uint8_t mh) {
    item->raw[1] |= (mh & MASK_01_BITS) << 2;
}

void set_I021_295_BVR(I021_295 * item, uint8_t bvr) {
    item->raw[1] |= (bvr & MASK_01_BITS) << 1;
}

void set_I021_295_FX2(I021_295 * item, uint8_t fx) {
    item->raw[1] |= fx & MASK_01_BITS;
}

void set_I021_295_GVR(I021_295 * item, uint8_t gvr) {
    item->raw[2] |= (gvr & MASK_01_BITS) << 7;
}

void set_I021_295_GV(I021_295 * item, uint8_t gv) {
    item->raw[2] |= (gv & MASK_01_BITS) << 6;
}

void set_I021_295_TAR(I021_295 * item, uint8_t tar) {
    item->raw[2] |= (tar & MASK_01_BITS) << 5;
}

void set_I021_295_TID(I021_295 * item, uint8_t tid) {
    item->raw[2] |= (tid & MASK_01_BITS) << 4;
}

void set_I021_295_TS(I021_295 * item, uint8_t ts) {
    item->raw[2] |= (ts & MASK_01_BITS) << 3;
}

void set_I021_295_MET(I021_295 * item, uint8_t met) {
    item->raw[2] |= (met & MASK_01_BITS) << 2;
}

void set_I021_295_ROA(I021_295 * item, uint8_t roa) {
    item->raw[2] |= (roa & MASK_01_BITS) << 1;
}

void set_I021_295_FX3(I021_295 * item, uint8_t fx) {
    item->raw[2] |= (fx & MASK_01_BITS);
}

void set_I021_295_ARA(I021_295 * item, uint8_t ara) {
    item->raw[3] |= (ara & MASK_01_BITS) << 7;
}

void set_I021_295_SCC(I021_295 * item, uint8_t scc) {
    item->raw[3] |= (scc & MASK_01_BITS) << 6;
}

void set_I021_295_FX4(I021_295 * item, uint8_t fx) {
    item->raw[3] |= fx & MASK_01_BITS;
}

/* =============================== SUBFIELD 1 =============================== */

void set_I021_295_EXT1_AOS(I021_295_EXT1 * item, double ads) {
    uint8_t ads_raw = 0;

    if (ads > 0)
        ads_raw = (uint8_t) (ads / I021_295_LSB_EXT1_AOS);

    item->AOS = ads_raw;
}

/* =============================== SUBFIELD 2 =============================== */

void set_I021_295_EXT2_TRD(I021_295_EXT2 * item, double trd) {
    uint8_t trd_raw = 0;

    if (trd > 0)
        trd_raw = (uint8_t) (trd / I021_295_LSB_EXT2_TRD);

    item->TRD = trd_raw;
}

/* =============================== SUBFIELD 3 =============================== */

void set_I021_295_EXT3_M3A(I021_295_EXT3 * item, double m3a) {
    uint8_t m3a_raw = 0;

    if (m3a > 0)
        m3a_raw = (uint8_t) (m3a / I021_295_LSB_EXT3_M3A);

    item->M3A = m3a_raw;
}

/* =============================== SUBFIELD 4 =============================== */

void set_I021_295_EXT4_QI(I021_295_EXT4 * item, double qi) {
    uint8_t qi_raw = 0;

    if (qi > 0)
        qi_raw = (uint8_t) (qi / I021_295_LSB_EXT4_QI);

    item->QI = qi_raw;
}

/* =============================== SUBFIELD 5 =============================== */

void set_I021_295_EXT5_TI(I021_295_EXT5 * item, double ti) {
    uint8_t ti_raw = 0;

    if (ti > 0)
        ti_raw = (uint8_t) (ti / I021_295_LSB_EXT5_TI);

    item->TI = ti_raw;
}

/* =============================== SUBFIELD 6 =============================== */

void set_I021_295_EXT6_MAM(I021_295_EXT6 * item, double mam) {
    uint8_t mam_raw = 0;

    if (mam > 0)
        mam_raw = (uint8_t) (mam / I021_295_LSB_EXT6_MAM);

    item->MAM = mam_raw;
}

/* =============================== SUBFIELD 7 =============================== */

void set_I021_295_EXT7_GH(I021_295_EXT7 * item, double gh) {
    uint8_t gh_raw = 0;

    if (gh > 0)
        gh_raw = (uint8_t) (gh / I021_295_LSB_EXT7_GH);

    item->GH = gh_raw;
}

/* =============================== SUBFIELD 8 =============================== */

void set_I021_295_EXT8_FL(I021_295_EXT8 * item, double fl) {
    uint8_t fl_raw = 0;

    if (fl > 0)
        fl_raw = (uint8_t) (fl / I021_295_LSB_EXT8_FL);

    item->FL = fl_raw;
}

/* =============================== SUBFIELD 9 =============================== */

void set_I021_295_EXT9_SAL(I021_295_EXT9 * item, double sal) {
    uint8_t sal_raw = 0;

    if (sal > 0)
        sal_raw = (uint8_t) (sal / I021_295_LSB_EXT9_SAL);

    item->SAL = sal_raw;
}

/* =============================== SUBFIELD 10 ============================== */

void set_I021_295_EXT10_FSA(I021_295_EXT10 * item, double fsa) {
    uint8_t fsa_raw = 0;

    if (fsa > 0)
        fsa_raw = (uint8_t) (fsa / I021_295_LSB_EXT10_FSA);

    item->FSA = fsa_raw;
}

/* =============================== SUBFIELD 11 ============================== */

void set_I021_295_EXT11_AS(I021_295_EXT11 * item, double as) {
    uint8_t as_raw = 0;

    if (as > 0)
        as_raw = (uint8_t) (as / I021_295_LSB_EXT11_AS);

    item->AS = as_raw;
}

/* =============================== SUBFIELD 12 ============================== */

void set_I021_295_EXT12_TAS(I021_295_EXT12 * item, double tas) {
    uint8_t tas_raw = 0;

    if (tas > 0)
        tas_raw = (uint8_t) (tas / I021_295_LSB_EXT12_TAS);

    item->TAS = tas_raw;
}

/* =============================== SUBFIELD 13 ============================== */

void set_I021_295_EXT13_MH(I021_295_EXT13 * item, double mh) {
    uint8_t mh_raw = 0;

    if (mh > 0)
        mh_raw = (uint8_t) (mh / I021_295_LSB_EXT13_MH);

    item->MH = mh_raw;
}

/* =============================== SUBFIELD 14 ============================== */

void set_I021_295_EXT14_BVR(I021_295_EXT14 * item, double bvr) {
    uint8_t bvr_raw = 0;

    if (bvr > 0)
        bvr_raw = (uint8_t) (bvr / I021_295_LSB_EXT14_BVR);

    item->BVR = bvr_raw;
}

/* =============================== SUBFIELD 15 ============================== */

void set_I021_295_EXT15_GVR(I021_295_EXT15 * item, double gvr) {
    uint8_t gvr_raw = 0;

    if (gvr > 0)
        gvr_raw = (uint8_t) (gvr / I021_295_LSB_EXT15_GVR);

    item->GVR = gvr_raw;
}

/* =============================== SUBFIELD 16 ============================== */

void set_I021_295_EXT16_GV(I021_295_EXT16 * item, double gv) {
    uint8_t gv_raw = 0;

    if (gv > 0)
        gv_raw = (uint8_t) (gv / I021_295_LSB_EXT16_GV);

    item->GV = gv_raw;
}

/* =============================== SUBFIELD 17 ============================== */

void set_I021_295_EXT17_TAR(I021_295_EXT17 * item, double tar) {
    uint8_t tar_raw = 0;

    if (tar > 0)
        tar_raw = (uint8_t) (tar / I021_295_LSB_EXT17_TAR);

    item->TAR = tar_raw;
}

/* =============================== SUBFIELD 18 ============================== */

void set_I021_295_EXT18_TID(I021_295_EXT18 * item, double tid) {
    uint8_t tid_raw = 0;

    if (tid > 0)
        tid_raw = (uint8_t) (tid / I021_295_LSB_EXT18_TID);

    item->TID = tid_raw;
}

/* =============================== SUBFIELD 19 ============================== */

void set_I021_295_EXT19_TS(I021_295_EXT19 * item, double ts) {
    uint8_t ts_raw = 0;

    if (ts > 0)
        ts_raw = (uint8_t) (ts / I021_295_LSB_EXT19_TS);

    item->TS = ts_raw;
}

/* =============================== SUBFIELD 20 ============================== */

void set_I021_295_EXT20_MET(I021_295_EXT20 * item, double met) {
    uint8_t met_raw = 0;

    if (met > 0)
        met_raw = (uint8_t) (met / I021_295_LSB_EXT20_MET);

    item->MET = met_raw;
}

/* =============================== SUBFIELD 21 ============================== */

void set_I021_295_EXT21_ROA(I021_295_EXT21 * item, double roa) {
    uint8_t roa_raw = 0;

    if (roa > 0)
        roa_raw = (uint8_t) (roa / I021_295_LSB_EXT21_ROA);

    item->ROA = roa_raw;
}

/* =============================== SUBFIELD 22 ============================== */

void set_I021_295_EXT22_ARA(I021_295_EXT22 * item, double ara) {
    uint8_t ara_raw = 0;

    if (ara > 0)
        ara_raw = (uint8_t) (ara / I021_295_LSB_EXT22_ARA);

    item->ARA = ara_raw;
}

/* =============================== SUBFIELD 23 ============================== */

void set_I021_295_EXT23_SCC(I021_295_EXT23 * item, double scc) {
    uint8_t scc_raw = 0;

    if (scc > 0)
        scc_raw = (uint8_t) (scc / I021_295_LSB_EXT23_SCC);

    item->SCC = scc_raw;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_295(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_295 * item = (I021_295 *) item_in;

    /* Read subfields presence bits */
    msg_out[out_index++] = item->raw[0];
    if (get_I021_295_FX1(item) != 0) msg_out[out_index++] = item->raw[1];
    if (get_I021_295_FX2(item) != 0) msg_out[out_index++] = item->raw[2];
    if (get_I021_295_FX3(item) != 0) msg_out[out_index++] = item->raw[3];
    /* Exit if no more bytes on item */
    if (get_I021_295_FX4(item) == 0) return out_index;

    /* Encode the subfields based on presence flag */
    if (get_I021_295_AOS(item) != 0) msg_out[out_index++] = item->ext1.AOS;
    if (get_I021_295_TRD(item) != 0) msg_out[out_index++] = item->ext2.TRD;
    if (get_I021_295_M3A(item) != 0) msg_out[out_index++] = item->ext3.M3A;
    if (get_I021_295_QI(item) != 0)  msg_out[out_index++] = item->ext4.QI;
    if (get_I021_295_TI(item) != 0)  msg_out[out_index++] = item->ext5.TI;
    if (get_I021_295_MAM(item) != 0) msg_out[out_index++] = item->ext6.MAM;
    if (get_I021_295_GH(item) != 0)  msg_out[out_index++] = item->ext7.GH;
    if (get_I021_295_FX1(item) != 0) msg_out[out_index++] = item->ext8.FL;
    if (get_I021_295_SAL(item) != 0) msg_out[out_index++] = item->ext9.SAL;
    if (get_I021_295_FSA(item) != 0) msg_out[out_index++] = item->ext10.FSA;
    if (get_I021_295_AS(item) != 0)  msg_out[out_index++] = item->ext11.AS;
    if (get_I021_295_TAS(item) != 0) msg_out[out_index++] = item->ext12.TAS;
    if (get_I021_295_MH(item) != 0)  msg_out[out_index++] = item->ext13.MH;
    if (get_I021_295_BVR(item) != 0) msg_out[out_index++] = item->ext14.BVR;
    if (get_I021_295_GVR(item) != 0) msg_out[out_index++] = item->ext15.GVR;
    if (get_I021_295_GV(item) != 0)  msg_out[out_index++] = item->ext16.GV;
    if (get_I021_295_TAR(item) != 0) msg_out[out_index++] = item->ext17.TAR;
    if (get_I021_295_TID(item) != 0) msg_out[out_index++] = item->ext18.TID;
    if (get_I021_295_TS(item) != 0)  msg_out[out_index++] = item->ext19.TS;
    if (get_I021_295_MET(item) != 0) msg_out[out_index++] = item->ext20.MET;
    if (get_I021_295_ROA(item) != 0) msg_out[out_index++] = item->ext21.ROA;
    if (get_I021_295_ARA(item) != 0) msg_out[out_index++] = item->ext22.ARA;
    if (get_I021_295_SCC(item) != 0) msg_out[out_index++] = item->ext23.SCC;

    return out_index;
}

uint16_t decode_I021_295(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_295 * item = (I021_295 *) item_out;

    /* Read subfields presence bits */
    item->raw[0] = msg_in[in_index++];
    if (get_I021_295_FX1(item) != 0) item->raw[1] = msg_in[in_index++];
    if (get_I021_295_FX2(item) != 0) item->raw[2] = msg_in[in_index++];
    if (get_I021_295_FX3(item) != 0) item->raw[3] = msg_in[in_index++];
    /* Exit if no more bytes on item */
    if (get_I021_295_FX4(item) == 0) return in_index;

    /* Encode the subfields based on presence flag */
    if (get_I021_295_AOS(item) != 0) item->ext1.AOS = msg_in[in_index++];
    if (get_I021_295_TRD(item) != 0) item->ext2.TRD = msg_in[in_index++];
    if (get_I021_295_M3A(item) != 0) item->ext3.M3A = msg_in[in_index++];
    if (get_I021_295_QI(item) != 0)  item->ext4.QI = msg_in[in_index++];
    if (get_I021_295_TI(item) != 0)  item->ext5.TI = msg_in[in_index++];
    if (get_I021_295_MAM(item) != 0) item->ext6.MAM = msg_in[in_index++];
    if (get_I021_295_GH(item) != 0)  item->ext7.GH = msg_in[in_index++];
    if (get_I021_295_FX1(item) != 0) item->ext8.FL = msg_in[in_index++];
    if (get_I021_295_SAL(item) != 0) item->ext9.SAL = msg_in[in_index++];
    if (get_I021_295_FSA(item) != 0) item->ext10.FSA = msg_in[in_index++];
    if (get_I021_295_AS(item) != 0)  item->ext11.AS = msg_in[in_index++];
    if (get_I021_295_TAS(item) != 0) item->ext12.TAS = msg_in[in_index++];
    if (get_I021_295_MH(item) != 0)  item->ext13.MH = msg_in[in_index++];
    if (get_I021_295_BVR(item) != 0) item->ext14.BVR = msg_in[in_index++];
    if (get_I021_295_GVR(item) != 0) item->ext15.GVR = msg_in[in_index++];
    if (get_I021_295_GV(item) != 0)  item->ext16.GV = msg_in[in_index++];
    if (get_I021_295_TAR(item) != 0) item->ext17.TAR = msg_in[in_index++];
    if (get_I021_295_TID(item) != 0) item->ext18.TID = msg_in[in_index++];
    if (get_I021_295_TS(item) != 0)  item->ext19.TS = msg_in[in_index++];
    if (get_I021_295_MET(item) != 0) item->ext20.MET = msg_in[in_index++];
    if (get_I021_295_ROA(item) != 0) item->ext21.ROA = msg_in[in_index++];
    if (get_I021_295_ARA(item) != 0) item->ext22.ARA = msg_in[in_index++];
    if (get_I021_295_SCC(item) != 0) item->ext23.SCC = msg_in[in_index++];

    return in_index;
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
