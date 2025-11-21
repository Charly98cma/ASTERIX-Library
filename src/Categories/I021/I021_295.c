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

uint8_t get_I021_295_AOS(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 7);
}

uint8_t get_I021_295_TRD(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 6);
}

uint8_t get_I021_295_M3A(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 5);
}

uint8_t get_I021_295_QI(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 4);
}

uint8_t get_I021_295_TI(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 3);
}

uint8_t get_I021_295_MAM(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 2);
}

uint8_t get_I021_295_GH(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 1);
}

uint8_t get_I021_295_FX1(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 0);
}

uint8_t get_I021_295_FL(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[1], MASK_01_BITS, 7);
}

uint8_t get_I021_295_SAL(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[1], MASK_01_BITS, 6);
}

uint8_t get_I021_295_FSA(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[1], MASK_01_BITS, 5);
}

uint8_t get_I021_295_AS(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[1], MASK_01_BITS, 4);
}

uint8_t get_I021_295_TAS(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[1], MASK_01_BITS, 3);
}

uint8_t get_I021_295_MH(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[1], MASK_01_BITS, 2);
}

uint8_t get_I021_295_BVR(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[1], MASK_01_BITS, 1);
}

uint8_t get_I021_295_FX2(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[1], MASK_01_BITS, 0);
}

uint8_t get_I021_295_GVR(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[2], MASK_01_BITS, 7);
}

uint8_t get_I021_295_GV(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[2], MASK_01_BITS, 6);
}

uint8_t get_I021_295_TAR(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[2], MASK_01_BITS, 5);
}

uint8_t get_I021_295_TID(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[2], MASK_01_BITS, 4);
}

uint8_t get_I021_295_TS(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[2], MASK_01_BITS, 3);
}

uint8_t get_I021_295_MET(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[2], MASK_01_BITS, 2);
}

uint8_t get_I021_295_ROA(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[2], MASK_01_BITS, 1);
}

uint8_t get_I021_295_FX3(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[2], MASK_01_BITS, 0);
}

uint8_t get_I021_295_ARA(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[3], MASK_01_BITS, 7);
}

uint8_t get_I021_295_SCC(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[3], MASK_01_BITS, 6);
}

uint8_t get_I021_295_FX4(const I021_295 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[3], MASK_01_BITS, 0);
}

/* =============================== SUBFIELD 1 =============================== */

double get_I021_295_EXT1_AOS(const I021_295_EXT1 * item)
{
    if (!item) return 0.0F;
    return (item->AOS * I021_295_LSB_EXT1_AOS);
}

/* =============================== SUBFIELD 2 =============================== */

double get_I021_295_EXT2_TRD(const I021_295_EXT2 * item)
{
    if (!item) return 0.0F;
    return (item->TRD * I021_295_LSB_EXT2_TRD);
}

/* =============================== SUBFIELD 3 =============================== */

double get_I021_295_EXT3_M3A(const I021_295_EXT3 * item)
{
    if (!item) return 0.0F;
    return (item->M3A * I021_295_LSB_EXT3_M3A);
}

/* =============================== SUBFIELD 4 =============================== */

double get_I021_295_EXT4_QI(const I021_295_EXT4 * item)
{
    if (!item) return 0.0F;
    return (item->QI * I021_295_LSB_EXT4_QI);
}

/* =============================== SUBFIELD 5 =============================== */

double get_I021_295_EXT5_TI(const I021_295_EXT5 * item)
{
    if (!item) return 0.0F;
    return (item->TI * I021_295_LSB_EXT5_TI);
}

/* =============================== SUBFIELD 6 =============================== */

double get_I021_295_EXT6_MAM(const I021_295_EXT6 * item)
{
    if (!item) return 0.0F;
    return (item->MAM * I021_295_LSB_EXT6_MAM);
}

/* =============================== SUBFIELD 7 =============================== */

double get_I021_295_EXT7_GH(const I021_295_EXT7 * item)
{
    if (!item) return 0.0F;
    return (item->GH * I021_295_LSB_EXT7_GH);
}

/* =============================== SUBFIELD 8 =============================== */

double get_I021_295_EXT8_FL(const I021_295_EXT8 * item)
{
    if (!item) return 0.0F;
    return (item->FL * I021_295_LSB_EXT8_FL);
}

/* =============================== SUBFIELD 9 =============================== */

double get_I021_295_EXT9_SAL(const I021_295_EXT9 * item)
{
    if (!item) return 0.0F;
    return (item->SAL * I021_295_LSB_EXT9_SAL);
}

/* =============================== SUBFIELD 10 ============================== */

double get_I021_295_EXT10_FSA(const I021_295_EXT10 * item)
{
    if (!item) return 0.0F;
    return (item->FSA * I021_295_LSB_EXT10_FSA);
}

/* =============================== SUBFIELD 11 ============================== */

double get_I021_295_EXT11_AS(const I021_295_EXT11 * item)
{
    if (!item) return 0.0F;
    return (item->AS * I021_295_LSB_EXT11_AS);
}

/* =============================== SUBFIELD 12 ============================== */

double get_I021_295_EXT12_TAS(const I021_295_EXT12 * item)
{
    if (!item) return 0.0F;
    return (item->TAS * I021_295_LSB_EXT12_TAS);
}

/* =============================== SUBFIELD 13 ============================== */

double get_I021_295_EXT13_MH(const I021_295_EXT13 * item)
{
    if (!item) return 0.0F;
    return (item->MH * I021_295_LSB_EXT13_MH);
}

/* =============================== SUBFIELD 14 ============================== */

double get_I021_295_EXT14_BVR(const I021_295_EXT14 * item)
{
    if (!item) return 0.0F;
    return (item->BVR * I021_295_LSB_EXT14_BVR);
}

/* =============================== SUBFIELD 15 ============================== */

double get_I021_295_EXT15_GVR(const I021_295_EXT15 * item)
{
    if (!item) return 0.0F;
    return (item->GVR * I021_295_LSB_EXT15_GVR);
}

/* =============================== SUBFIELD 16 ============================== */

double get_I021_295_EXT16_GV(const I021_295_EXT16 * item)
{
    if (!item) return 0.0F;
    return (item->GV * I021_295_LSB_EXT16_GV);
}

/* =============================== SUBFIELD 17 ============================== */

double get_I021_295_EXT17_TAR(const I021_295_EXT17 * item)
{
    if (!item) return 0.0F;
    return (item->TAR * I021_295_LSB_EXT17_TAR);
}

/* =============================== SUBFIELD 18 ============================== */

double get_I021_295_EXT18_TID(const I021_295_EXT18 * item)
{
    if (!item) return 0.0F;
    return (item->TID * I021_295_LSB_EXT18_TID);
}

/* =============================== SUBFIELD 19 ============================== */

double get_I021_295_EXT19_TS(const I021_295_EXT19 * item)
{
    if (!item) return 0.0F;
    return (item->TS * I021_295_LSB_EXT19_TS);
}

/* =============================== SUBFIELD 20 ============================== */

double get_I021_295_EXT20_MET(const I021_295_EXT20 * item)
{
    if (!item) return 0.0F;
    return (item->MET * I021_295_LSB_EXT20_MET);
}

/* =============================== SUBFIELD 21 ============================== */

double get_I021_295_EXT21_ROA(const I021_295_EXT21 * item)
{
    if (!item) return 0.0F;
    return (item->ROA * I021_295_LSB_EXT21_ROA);
}

/* =============================== SUBFIELD 22 ============================== */

double get_I021_295_EXT22_ARA(const I021_295_EXT22 * item)
{
    if (!item) return 0.0F;
    return (item->ARA * I021_295_LSB_EXT22_ARA);
}

/* =============================== SUBFIELD 23 ============================== */

double get_I021_295_EXT23_SCC(const I021_295_EXT23 * item)
{
    if (!item) return 0.0F;
    return (item->SCC * I021_295_LSB_EXT23_SCC);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

void set_I021_295_AOS(I021_295 * item, uint8_t ads)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 7, ads);
}

void set_I021_295_TRD(I021_295 * item, uint8_t trd)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 6, trd);
}

void set_I021_295_M3A(I021_295 * item, uint8_t m3a)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 5, m3a);
}

void set_I021_295_QI(I021_295 * item, uint8_t qi)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 4, qi);
}

void set_I021_295_TI(I021_295 * item, uint8_t ti)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 3, ti);
}

void set_I021_295_MAM(I021_295 * item, uint8_t mam)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 2, mam);
}

void set_I021_295_GH(I021_295 * item, uint8_t gh)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 1, gh);
}

void set_I021_295_FX1(I021_295 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 0, fx);
}

void set_I021_295_FL(I021_295 * item, uint8_t fl)
{
    if (!item) return;
    write_bits(&item->raw[1], MASK_01_BITS, 7, fl);
}

void set_I021_295_SAL(I021_295 * item, uint8_t sal)
{
    if (!item) return;
    write_bits(&item->raw[1], MASK_01_BITS, 6, sal);
}

void set_I021_295_FSA(I021_295 * item, uint8_t fsa)
{
    if (!item) return;
    write_bits(&item->raw[1], MASK_01_BITS, 5, fsa);
}

void set_I021_295_AS(I021_295 * item, uint8_t as)
{
    if (!item) return;
    write_bits(&item->raw[1], MASK_01_BITS, 4, as);
}

void set_I021_295_TAS(I021_295 * item, uint8_t tas)
{
    if (!item) return;
    write_bits(&item->raw[1], MASK_01_BITS, 3, tas);
}

void set_I021_295_MH(I021_295 * item, uint8_t mh)
{
    if (!item) return;
    write_bits(&item->raw[1], MASK_01_BITS, 2, mh);
}

void set_I021_295_BVR(I021_295 * item, uint8_t bvr)
{
    if (!item) return;
    write_bits(&item->raw[1], MASK_01_BITS, 1, bvr);
}

void set_I021_295_FX2(I021_295 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw[1], MASK_01_BITS, 0, fx);
}

void set_I021_295_GVR(I021_295 * item, uint8_t gvr)
{
    if (!item) return;
    write_bits(&item->raw[2], MASK_01_BITS, 7, gvr);
}

void set_I021_295_GV(I021_295 * item, uint8_t gv)
{
    if (!item) return;
    write_bits(&item->raw[2], MASK_01_BITS, 6, gv);
}

void set_I021_295_TAR(I021_295 * item, uint8_t tar)
{
    if (!item) return;
    write_bits(&item->raw[2], MASK_01_BITS, 5, tar);
}

void set_I021_295_TID(I021_295 * item, uint8_t tid)
{
    if (!item) return;
    write_bits(&item->raw[2], MASK_01_BITS, 4, tid);
}

void set_I021_295_TS(I021_295 * item, uint8_t ts)
{
    if (!item) return;
    write_bits(&item->raw[2], MASK_01_BITS, 3, ts);
}

void set_I021_295_MET(I021_295 * item, uint8_t met)
{
    if (!item) return;
    write_bits(&item->raw[2], MASK_01_BITS, 2, met);
}

void set_I021_295_ROA(I021_295 * item, uint8_t roa)
{
    if (!item) return;
    write_bits(&item->raw[2], MASK_01_BITS, 1, roa);
}

void set_I021_295_FX3(I021_295 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw[1], MASK_01_BITS, 0, fx);
}

void set_I021_295_ARA(I021_295 * item, uint8_t ara)
{
    if (!item) return;
    write_bits(&item->raw[3], MASK_01_BITS, 7, ara);
}

void set_I021_295_SCC(I021_295 * item, uint8_t scc)
{
    if (!item) return;
    write_bits(&item->raw[3], MASK_01_BITS, 6, scc);
}

void set_I021_295_FX4(I021_295 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw[1], MASK_01_BITS, 0, fx);
}

/* =============================== SUBFIELD 1 =============================== */

void set_I021_295_EXT1_AOS(I021_295_EXT1 * item, double ads)
{
    if (!item) return;
    item->AOS = (ads / I021_295_LSB_EXT1_AOS);
}

/* =============================== SUBFIELD 2 =============================== */

void set_I021_295_EXT2_TRD(I021_295_EXT2 * item, double trd)
{
    if (!item) return;
    item->TRD = (trd / I021_295_LSB_EXT2_TRD);
}

/* =============================== SUBFIELD 3 =============================== */

void set_I021_295_EXT3_M3A(I021_295_EXT3 * item, double m3a)
{
    if (!item) return;
    item->M3A = (m3a / I021_295_LSB_EXT3_M3A);
}

/* =============================== SUBFIELD 4 =============================== */

void set_I021_295_EXT4_QI(I021_295_EXT4 * item, double qi)
{
    if (!item) return;
    item->QI =  (qi / I021_295_LSB_EXT4_QI);
}

/* =============================== SUBFIELD 5 =============================== */

void set_I021_295_EXT5_TI(I021_295_EXT5 * item, double ti)
{
    if (!item) return;
    item->TI =  (ti / I021_295_LSB_EXT5_TI);
}

/* =============================== SUBFIELD 6 =============================== */

void set_I021_295_EXT6_MAM(I021_295_EXT6 * item, double mam)
{
    if (!item) return;
    item->MAM = (mam / I021_295_LSB_EXT6_MAM);
}

/* =============================== SUBFIELD 7 =============================== */

void set_I021_295_EXT7_GH(I021_295_EXT7 * item, double gh)
{
    if (!item) return;
    item->GH =  (gh / I021_295_LSB_EXT7_GH);
}

/* =============================== SUBFIELD 8 =============================== */

void set_I021_295_EXT8_FL(I021_295_EXT8 * item, double fl)
{
    if (!item) return;
    item->FL =  (fl / I021_295_LSB_EXT8_FL);
}

/* =============================== SUBFIELD 9 =============================== */

void set_I021_295_EXT9_SAL(I021_295_EXT9 * item, double sal)
{
    if (!item) return;
    item->SAL = (sal / I021_295_LSB_EXT9_SAL);
}

/* =============================== SUBFIELD 10 ============================== */

void set_I021_295_EXT10_FSA(I021_295_EXT10 * item, double fsa)
{
    if (!item) return;
    item->FSA = (fsa / I021_295_LSB_EXT10_FSA);
}

/* =============================== SUBFIELD 11 ============================== */

void set_I021_295_EXT11_AS(I021_295_EXT11 * item, double as)
{
    if (!item) return;
    item->AS =  (as / I021_295_LSB_EXT11_AS);
}

/* =============================== SUBFIELD 12 ============================== */

void set_I021_295_EXT12_TAS(I021_295_EXT12 * item, double tas)
{
    if (!item) return;
    item->TAS = (tas / I021_295_LSB_EXT12_TAS);
}

/* =============================== SUBFIELD 13 ============================== */

void set_I021_295_EXT13_MH(I021_295_EXT13 * item, double mh)
{
    if (!item) return;
    item->MH =  (mh / I021_295_LSB_EXT13_MH);
}

/* =============================== SUBFIELD 14 ============================== */

void set_I021_295_EXT14_BVR(I021_295_EXT14 * item, double bvr)
{
    if (!item) return;
    item->BVR = (bvr / I021_295_LSB_EXT14_BVR);
}

/* =============================== SUBFIELD 15 ============================== */

void set_I021_295_EXT15_GVR(I021_295_EXT15 * item, double gvr)
{
    if (!item) return;
    item->GVR = (gvr / I021_295_LSB_EXT15_GVR);
}

/* =============================== SUBFIELD 16 ============================== */

void set_I021_295_EXT16_GV(I021_295_EXT16 * item, double gv)
{
    if (!item) return;
    item->GV =  (gv / I021_295_LSB_EXT16_GV);
}

/* =============================== SUBFIELD 17 ============================== */

void set_I021_295_EXT17_TAR(I021_295_EXT17 * item, double tar)
{
    if (!item) return;
    item->TAR = (tar / I021_295_LSB_EXT17_TAR);
}

/* =============================== SUBFIELD 18 ============================== */

void set_I021_295_EXT18_TID(I021_295_EXT18 * item, double tid)
{
    if (!item) return;
    item->TID = (tid / I021_295_LSB_EXT18_TID);
}

/* =============================== SUBFIELD 19 ============================== */

void set_I021_295_EXT19_TS(I021_295_EXT19 * item, double ts)
{
    if (!item) return;
    item->TS =  (ts / I021_295_LSB_EXT19_TS);
}

/* =============================== SUBFIELD 20 ============================== */

void set_I021_295_EXT20_MET(I021_295_EXT20 * item, double met)
{
    if (!item) return;
    item->MET = (met / I021_295_LSB_EXT20_MET);
}

/* =============================== SUBFIELD 21 ============================== */

void set_I021_295_EXT21_ROA(I021_295_EXT21 * item, double roa)
{
    if (!item) return;
    item->ROA = (roa / I021_295_LSB_EXT21_ROA);
}

/* =============================== SUBFIELD 22 ============================== */

void set_I021_295_EXT22_ARA(I021_295_EXT22 * item, double ara)
{
    if (!item) return;
    item->ARA = (ara / I021_295_LSB_EXT22_ARA);
}

/* =============================== SUBFIELD 23 ============================== */

void set_I021_295_EXT23_SCC(I021_295_EXT23 * item, double scc)
{
    if (!item) return;
    item->SCC = (scc / I021_295_LSB_EXT23_SCC);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_295(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_295 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_295 *) item_in;

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

uint16_t decode_I021_295(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_295 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_295 *) item_out;

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

void print_I021_295(const I021_295 * item)
{
    printf("I021/295 - Data Ages\n");
    if (!item)
    {
        printf("I021/295 <null>\n");
        return;
    }
    printf("- AOS = %d\n", get_I021_295_AOS(item));
    printf("- TRD = %d\n", get_I021_295_TRD(item));
    printf("- M3A = %d\n", get_I021_295_M3A(item));
    printf("- QI = %d\n", get_I021_295_QI(item));
    printf("- TI = %d\n", get_I021_295_TI(item));
    printf("- MAM = %d\n", get_I021_295_MAM(item));
    printf("- GH = %d\n", get_I021_295_GH(item));
    printf("- FX1 = %d\n", get_I021_295_FX1(item));
    printf("- FL = %d\n", get_I021_295_FL(item));
    printf("- SAL = %d\n", get_I021_295_SAL(item));
    printf("- FSA = %d\n", get_I021_295_FSA(item));
    printf("- AS = %d\n", get_I021_295_AS(item));
    printf("- TAS = %d\n", get_I021_295_TAS(item));
    printf("- MH = %d\n", get_I021_295_MH(item));
    printf("- BVR = %d\n", get_I021_295_BVR(item));
    printf("- FX2 = %d\n", get_I021_295_FX2(item));
    printf("- GVR = %d\n", get_I021_295_GVR(item));
    printf("- GV = %d\n", get_I021_295_GV(item));
    printf("- TAR = %d\n", get_I021_295_TAR(item));
    printf("- TID = %d\n", get_I021_295_TID(item));
    printf("- TS = %d\n", get_I021_295_TS(item));
    printf("- MET = %d\n", get_I021_295_MET(item));
    printf("- ROA = %d\n", get_I021_295_ROA(item));
    printf("- FX3 = %d\n", get_I021_295_FX3(item));
    printf("- ARA = %d\n", get_I021_295_ARA(item));
    printf("- SCC = %d\n", get_I021_295_SCC(item));
    printf("- FX4 = %d\n", get_I021_295_FX4(item));

    if (get_I021_295_AOS(item))
        printf("-- EXT1_AOS = %f\n", get_I021_295_EXT1_AOS(&(item->ext1)));

    if (get_I021_295_TRD(item))
        printf("-- EXT2_TRD = %f\n", get_I021_295_EXT2_TRD(&(item->ext2)));

    if (get_I021_295_M3A(item))
        printf("-- EXT3_M3A = %f\n", get_I021_295_EXT3_M3A(&(item->ext3)));

    if (get_I021_295_QI(item))
        printf("-- EXT4_QI = %f\n", get_I021_295_EXT4_QI(&(item->ext4)));

    if (get_I021_295_TI(item))
        printf("-- EXT5_TI = %f\n", get_I021_295_EXT5_TI(&(item->ext5)));

    if (get_I021_295_MAM(item))
        printf("-- EXT6_MAM = %f\n", get_I021_295_EXT6_MAM(&(item->ext6)));

    if (get_I021_295_GH(item))
        printf("-- EXT7_GH = %f\n", get_I021_295_EXT7_GH(&(item->ext7)));

    if (get_I021_295_FX1(item))
        printf("-- EXT8_FL = %f\n", get_I021_295_EXT8_FL(&(item->ext8)));

    if (get_I021_295_SAL(item))
        printf("-- EXT9_SAL = %f\n", get_I021_295_EXT9_SAL(&(item->ext9)));

    if (get_I021_295_FSA(item))
        printf("-- EXT10_FSA = %f\n", get_I021_295_EXT10_FSA(&(item->ext10)));

    if (get_I021_295_AS(item))
        printf("-- EXT11_AS = %f\n", get_I021_295_EXT11_AS(&(item->ext11)));

    if (get_I021_295_TAS(item))
        printf("-- EXT12_TAS = %f\n", get_I021_295_EXT12_TAS(&(item->ext12)));

    if (get_I021_295_MH(item))
        printf("-- EXT13_MH = %f\n", get_I021_295_EXT13_MH(&(item->ext13)));

    if (get_I021_295_BVR(item))
        printf("-- EXT14_BVR = %f\n", get_I021_295_EXT14_BVR(&(item->ext14)));

    if (get_I021_295_GVR(item))
        printf("-- EXT15_GVR = %f\n", get_I021_295_EXT15_GVR(&(item->ext15)));

    if (get_I021_295_GV(item))
        printf("-- EXT16_GV = %f\n", get_I021_295_EXT16_GV(&(item->ext16)));

    if (get_I021_295_TAR(item))
        printf("-- EXT17_TAR = %f\n", get_I021_295_EXT17_TAR(&(item->ext17)));

    if (get_I021_295_TID(item))
        printf("-- EXT18_TID = %f\n", get_I021_295_EXT18_TID(&(item->ext18)));

    if (get_I021_295_TS(item))
        printf("-- EXT19_TS = %f\n", get_I021_295_EXT19_TS(&(item->ext19)));

    if (get_I021_295_MET(item))
        printf("-- EXT20_MET = %f\n", get_I021_295_EXT20_MET(&(item->ext20)));

    if (get_I021_295_ROA(item))
        printf("-- EXT21_ROA = %f\n", get_I021_295_EXT21_ROA(&(item->ext21)));

    if (get_I021_295_ARA(item))
        printf("-- EXT22_ARA = %f\n", get_I021_295_EXT22_ARA(&(item->ext22)));

    if (get_I021_295_SCC(item))
        printf("-- EXT23_SCC = %f\n", get_I021_295_EXT23_SCC(&(item->ext23)));
}
