/**
 * @file I021_RE.c
 * @brief Implementation of the Category 21 Item RE functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_RE.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== Main Byte =============================== */

uint8_t get_I021_RE_LEN(const I021_RE * item) {
    return item->LEN;
}

uint8_t get_I021_RE_FSPEC_raw(const I021_RE * item) {
    return item->FSPEC.raw;
}

uint8_t get_I021_RE_FSPEC_BPS(const I021_RE * item) {
    return (item->FSPEC.raw >> 7) & MASK_01_BITS;
}

uint8_t get_I021_RE_FSPEC_SELH(const I021_RE * item) {
    return (item->FSPEC.raw >> 6) & MASK_01_BITS;
}

uint8_t get_I021_RE_FSPEC_NAV(const I021_RE * item) {
    return (item->FSPEC.raw >> 5) & MASK_01_BITS;
}

uint8_t get_I021_RE_FSPEC_GAO(const I021_RE * item) {
    return (item->FSPEC.raw >> 4) & MASK_01_BITS;
}

uint8_t get_I021_RE_FSPEC_SGV(const I021_RE * item) {
    return (item->FSPEC.raw >> 3) & MASK_01_BITS;
}

uint8_t get_I021_RE_FSPEC_STA(const I021_RE * item) {
    return (item->FSPEC.raw >> 2) & MASK_01_BITS;
}

uint8_t get_I021_RE_FSPEC_TNH(const I021_RE * item) {
    return (item->FSPEC.raw >> 1) & MASK_01_BITS;
}

uint8_t get_I021_RE_FSPEC_MES(const I021_RE * item) {
    return (item->FSPEC.raw) & MASK_01_BITS;
}

/* ============================= 1st Extension ============================= */

double get_I021_RE_BPS(const I021_RE_BPS * item) {
    uint16_t bps_raw = (((item->raw[0] & MASK_04_BITS) << 8) | item->raw[1]);
    return bps_raw * I021_RE_LSB_BSP;
}

/* ============================= 2nd Extension ============================= */

uint8_t get_I021_RE_SELH_HRD(const I021_RE_SELH * item) {
    return (item->raw[0] >> 3) & MASK_01_BITS;
}

uint8_t get_I021_RE_SELH_STAT(const I021_RE_SELH * item) {
    return (item->raw[0] >> 2) & MASK_01_BITS;
}

double get_I021_RE_SELH_SELH(const I021_RE_SELH * item) {
    uint16_t selh_raw = (
        (((item->raw[0] >> 1) & MASK_02_BITS) << 8) | item->raw[1]);
    return selh_raw * I021_RE_LSB_SELH;
}

/* ============================= 3rd Extension ============================= */

uint8_t get_I021_RE_NAV_AP(const I021_RE_NAV * item) {
    return (item->raw >> 7) & MASK_01_BITS;
}

uint8_t get_I021_RE_NAV_VN(const I021_RE_NAV * item) {
    return (item->raw >> 6) & MASK_01_BITS;
}

uint8_t get_I021_RE_NAV_AH(const I021_RE_NAV * item) {
    return (item->raw >> 5) & MASK_01_BITS;
}

uint8_t get_I021_RE_NAV_AM(const I021_RE_NAV * item) {
    return (item->raw >> 4) & MASK_01_BITS;
}

uint8_t get_I021_RE_NAV_MFM(const I021_RE_NAV * item) {
    return (item->raw >> 2) & MASK_02_BITS;
}

/* ============================= 4th Extension ============================= */

uint8_t get_I021_RE_GAO_LAT(const I021_RE_GAO * item) {
    return ((item->raw >> 5) & MASK_03_BITS) * I021_RE_LSB_GAO_LAT;
}

uint8_t get_I021_RE_GAO_LON(const I021_RE_GAO * item) {
    return (item->raw & MASK_05_BITS) * I021_RE_LSB_GAO_LON;
}

/* ============================= 5th Extension ============================= */

uint8_t get_I021_RE_SGV_STP(const I021_RE_SGV * item) {
    return (item->raw[0] >> 7) & MASK_01_BITS;
}

uint8_t get_I021_RE_SGV_HTS(const I021_RE_SGV * item) {
    return (item->raw[0] >> 6) & MASK_01_BITS;
}

uint8_t get_I021_RE_SGV_HTT(const I021_RE_SGV * item) {
    return (item->raw[0] >> 5) & MASK_01_BITS;
}

uint8_t get_I021_RE_SGV_HRD(const I021_RE_SGV * item) {
    return (item->raw[0] >> 4) & MASK_01_BITS;
}

double get_I021_RE_SGV_GSS(const I021_RE_SGV * item) {
    uint16_t gsv_raw = (((item->raw[0] & MASK_04_BITS) << 7) | (item->raw[1] >> 1));
    return gsv_raw * I021_RE_LSB_SGV_GSS;
}

uint8_t get_I021_RE_SGV_FX(const I021_RE_SGV * item) {
    return (item->raw[1] & MASK_01_BITS);
}

/* Subfield #1 */

double get_I021_RE_SGV_EXT1_HGT(const I021_RE_SGV_EXT1 * item) {
    return (item->raw & MASK_07_BITS) * I021_RE_LSB_SGV_HGT;
}

uint8_t get_I021_RE_SGV_EXT1_FX(const I021_RE_SGV_EXT1 * item) {
    return (item->raw & MASK_01_BITS);
}

/* ============================= 6th Extension ============================= */

uint8_t get_I021_RE_STA_ES(const I021_RE_STA * item) {
    return (item->raw >> 7) & MASK_01_BITS;
}

uint8_t get_I021_RE_STA_UAT(const I021_RE_STA * item) {
    return (item->raw >> 6) & MASK_01_BITS;
}

uint8_t get_I021_RE_STA_RCE(const I021_RE_STA * item) {
    return (item->raw >> 3) & MASK_03_BITS;
}

uint8_t get_I021_RE_STA_RRL(const I021_RE_STA * item) {
    return (item->raw >> 1) & MASK_02_BITS;
}

uint8_t get_I021_RE_STA_FX(const I021_RE_STA * item) {
    return item->raw & MASK_01_BITS;
}

/* Subfield #1 */

uint8_t get_I021_RE_STA_EXT1_PS3(const I021_RE_STA_EXT1 * item) {
    return (item->raw >> 4) & MASK_04_BITS;
}

uint8_t get_I021_RE_STA_EXT1_RRL(const I021_RE_STA_EXT1 * item) {
    return (item->raw >> 1) & MASK_03_BITS;
}

uint8_t get_I021_RE_STA_EXT1_FX(const I021_RE_STA_EXT1 * item) {
    return item->raw & MASK_01_BITS;
}

/* Subfield #2 */

uint8_t get_I021_RE_STA_EXT2_TSI(const I021_RE_STA_EXT2 * item) {
    return (item->raw >> 5) & MASK_03_BITS;
}

uint8_t get_I021_RE_STA_EXT2_MUO(const I021_RE_STA_EXT2 * item) {
    return (item->raw >> 3) & MASK_02_BITS;
}

uint8_t get_I021_RE_STA_EXT2_RWC(const I021_RE_STA_EXT2 * item) {
    return (item->raw >> 1) & MASK_02_BITS;
}

uint8_t get_I021_RE_STA_EXT2_FX(const I021_RE_STA_EXT2 * item) {
    return item->raw & MASK_01_BITS;
}

/* Subfield #3 */

uint8_t get_I021_RE_STA_EXT3_DAA(const I021_RE_STA_EXT3 * item) {
    return (item->raw >> 5) & MASK_03_BITS;
}

uint8_t get_I021_RE_STA_EXT3_DF17CA(const I021_RE_STA_EXT3 * item) {
    return (item->raw >> 1) & MASK_04_BITS;
}

uint8_t get_I021_RE_STA_EXT3_FX(const I021_RE_STA_EXT3 * item) {
    return item->raw & MASK_01_BITS;
}

/* Subfield #4 */

uint8_t get_I021_RE_STA_EXT4_SVH(const I021_RE_STA_EXT4 * item) {
    return (item->raw >> 5) & MASK_03_BITS;
}

uint8_t get_I021_RE_STA_EXT4_CATC(const I021_RE_STA_EXT4 * item) {
    return (item->raw >> 1) & MASK_04_BITS;
}

uint8_t get_I021_RE_STA_EXT4_FX(const I021_RE_STA_EXT4 * item) {
    return item->raw & MASK_01_BITS;
}

/* Subfield #5 */

uint8_t get_I021_RE_STA_EXT5_CATC(const I021_RE_STA_EXT5 * item) {
    return (item->raw >> 2) & MASK_06_BITS;
}

uint8_t get_I021_RE_STA_EXT5_FX(const I021_RE_STA_EXT5 * item) {
    return item->raw & MASK_01_BITS;
}

/* ============================= 7th Extension ============================= */

double get_I021_RE_TNH(const I021_RE_TNH * item) {
    uint16_t tnh_raw = (item->raw[0] << 8 | item->raw[0]);
    return (tnh_raw * I021_RE_LSB_TNH);
}

/* ============================= 8th Extension ============================= */

uint8_t get_I021_RE_MES_SUM(const I021_RE_MES * item) {
    return (item->raw >> 7) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_PNO(const I021_RE_MES * item) {
    return (item->raw >> 6) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EM1(const I021_RE_MES * item) {
    return (item->raw >> 5) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_XP(const I021_RE_MES * item) {
    return (item->raw >> 4) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_FOM(const I021_RE_MES * item) {
    return (item->raw >> 3) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_M2(const I021_RE_MES * item) {
    return (item->raw >> 2) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_FX(const I021_RE_MES * item) {
    return item->raw & MASK_01_BITS;
}

/* Subfield #1 */

uint8_t get_I021_RE_MES_EXT1_M5(const I021_RE_MES_EXT1 * item) {
    return (item->raw >> 7) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT1_ID(const I021_RE_MES_EXT1 * item) {
    return (item->raw >> 6) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT1_DA(const I021_RE_MES_EXT1 * item) {
    return (item->raw >> 5) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT1_M1(const I021_RE_MES_EXT1 * item) {
    return (item->raw >> 4) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT1_M2(const I021_RE_MES_EXT1 * item) {
    return (item->raw >> 3) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT1_M3(const I021_RE_MES_EXT1 * item) {
    return (item->raw >> 2) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT1_MC(const I021_RE_MES_EXT1 * item) {
    return (item->raw >> 1) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT1_PO(const I021_RE_MES_EXT1 * item) {
    return item->raw & MASK_01_BITS;
}

/* Subfield #2 */

uint16_t get_I021_RE_MES_EXT2_PIN(const I021_RE_MES_EXT2 * item) {
    return ((item->raw[0] & MASK_06_BITS) << 8) | (item->raw[1]);
}

uint16_t get_I021_RE_MES_EXT2_NO(const I021_RE_MES_EXT2 * item) {
    return ((item->raw[2] & MASK_03_BITS) << 8) | (item->raw[3]);
}

/* Subfield #3 */

uint8_t get_I021_RE_MES_EXT3_V(const I021_RE_MES_EXT3 * item) {
    return (item->raw[0] >> 7) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT3_L(const I021_RE_MES_EXT3 * item) {
    return (item->raw[0] >> 5) & MASK_01_BITS;
}

uint16_t get_I021_RE_MES_EXT3_EM1(const I021_RE_MES_EXT3 * item) {
    return ((item->raw[0] & MASK_04_BITS) << 8) | (item->raw[1]);
}

/* Subfield #4 */

uint8_t get_I021_RE_MES_EXT4_XP(const I021_RE_MES_EXT4 * item) {
    return (item->raw >> 5) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT4_X5(const I021_RE_MES_EXT4 * item) {
    return (item->raw >> 4) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT4_XC(const I021_RE_MES_EXT4 * item) {
    return (item->raw >> 3) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT4_X3(const I021_RE_MES_EXT4 * item) {
    return (item->raw >> 2) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT4_X2(const I021_RE_MES_EXT4 * item) {
    return (item->raw >> 1) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT4_X1(const I021_RE_MES_EXT4 * item) {
    return item->raw & MASK_01_BITS;
}

/* Subfield #5 */

uint8_t get_I021_RE_MES_EXT5_FOM(const I021_RE_MES_EXT5 * item) {
    return item->raw & MASK_05_BITS;
}

/* Subfield #6 */

uint8_t get_I021_RE_MES_EXT6_V(const I021_RE_MES_EXT6 * item) {
    return (item->raw[0] >> 7) & MASK_01_BITS;
}

uint8_t get_I021_RE_MES_EXT6_L(const I021_RE_MES_EXT6 * item) {
    return (item->raw[0] >> 5) & MASK_01_BITS;
}

uint16_t get_I021_RE_MES_EXT6_M2(const I021_RE_MES_EXT6 * item) {
    return ((item->raw[0] & MASK_04_BITS) << 8) | (item->raw[1]);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* =============================== Main Byte =============================== */

void set_I021_RE_LEN(I021_RE * item, uint8_t len) {
    item->LEN = len;
}

void set_I021_RE_FSPEC_raw(I021_RE * item, uint8_t fspec) {
    item->FSPEC.raw = fspec;
}

void set_I021_RE_FSPEC_BPS(I021_RE * item, uint8_t bps_presence) {
    item->FSPEC.raw |= (bps_presence & MASK_01_BITS) << 7;
}

void set_I021_RE_FSPEC_SELH(I021_RE * item, uint8_t selh_presence) {
    item->FSPEC.raw |= (selh_presence & MASK_01_BITS) << 6;
}

void set_I021_RE_FSPEC_NAV(I021_RE * item, uint8_t nav_presence) {
    item->FSPEC.raw |= (nav_presence & MASK_01_BITS) << 5;
}

void set_I021_RE_FSPEC_GAO(I021_RE * item, uint8_t gao_presence) {
    item->FSPEC.raw |= (gao_presence & MASK_01_BITS) << 4;
}

void set_I021_RE_FSPEC_SGV(I021_RE * item, uint8_t sgv_presence) {
    item->FSPEC.raw |= (sgv_presence & MASK_01_BITS) << 3;
}

void set_I021_RE_FSPEC_STA(I021_RE * item, uint8_t sta_presence) {
    item->FSPEC.raw |= (sta_presence & MASK_01_BITS) << 2;
}

void set_I021_RE_FSPEC_TNH(I021_RE * item, uint8_t tnh_presence) {
    item->FSPEC.raw |= (tnh_presence & MASK_01_BITS) << 1;
}

void set_I021_RE_FSPEC_MES(I021_RE * item, uint8_t mes_presence) {
    item->FSPEC.raw |= (mes_presence & MASK_01_BITS);
}

/* ============================= 1st Extension ============================= */

void set_I021_RE_BPS(I021_RE_BPS * item, double bps_hPa) {
    uint16_t bps_raw = (bps_hPa / I021_RE_LSB_BSP) + 0.5;
    item->raw[0] |= (bps_raw >> 8) & MASK_04_BITS;
    item->raw[1]  =  bps_raw & MASK_08_BITS;
}

/* ============================= 2nd Extension ============================= */

void set_I021_RE_SELH_HRD(I021_RE_SELH * item, uint8_t hrd) {
    item->raw[0] |= (hrd & MASK_01_BITS) << 3;
}

void set_I021_RE_SELH_STAT(I021_RE_SELH * item, uint8_t stat) {
    item->raw[0] |= (stat & MASK_01_BITS) << 2;
}

void set_I021_RE_SELH_SELH(I021_RE_SELH * item, uint8_t selh) {
    uint16_t selh_raw = (selh / I021_RE_LSB_SELH) + 0.5;
    item->raw[0] |= (selh_raw >> 8) & MASK_02_BITS;
    item->raw[1]  =  selh_raw & MASK_08_BITS;
}

/* ============================= 3rd Extension ============================= */

void set_I021_RE_NAV_AP(I021_RE_NAV * item, uint8_t nav) {
    item->raw |= (nav & MASK_01_BITS) << 7;
}

void set_I021_RE_NAV_VN(I021_RE_NAV * item, uint8_t vn) {
    item->raw |= (vn & MASK_01_BITS) << 6;
}

void set_I021_RE_NAV_AH(I021_RE_NAV * item, uint8_t ah) {
    item->raw |= (ah & MASK_01_BITS) << 5;
}

void set_I021_RE_NAV_AM(I021_RE_NAV * item, uint8_t am) {
    item->raw |= (am & MASK_01_BITS) << 4;
}

void set_I021_RE_NAV_MFM(I021_RE_NAV * item, uint8_t mfm) {
    item->raw |= (mfm & MASK_01_BITS) << 2;
}

/* ============================= 4th Extension ============================= */


void set_I021_RE_GAO_LAT(I021_RE_GAO * item, uint8_t lateral_m) {
    uint8_t lateral_raw = (lateral_m / I021_RE_LSB_GAO_LAT) + 0.5;
    item->raw |= (lateral_raw & MASK_03_BITS) << 5;
}

void set_I021_RE_GAO_LON(I021_RE_GAO * item, uint8_t longitudinal_m) {
    uint8_t longitudinal_raw = (longitudinal_m / I021_RE_LSB_GAO_LON) + 0.5;
    item->raw |= longitudinal_raw & MASK_05_BITS;
}

/* ============================= 5th Extension ============================= */

void set_I021_RE_SGV_STP(I021_RE_SGV * item, uint8_t stp) {
    item->raw[0] |= (stp & MASK_01_BITS) << 7;
}

void set_I021_RE_SGV_HTS(I021_RE_SGV * item, uint8_t hts) {
    item->raw[0] |= (hts & MASK_01_BITS) << 6;
}

void set_I021_RE_SGV_HTT(I021_RE_SGV * item, uint8_t htt) {
    item->raw[0] |= (htt & MASK_01_BITS) << 5;
}

void set_I021_RE_SGV_HRD(I021_RE_SGV * item, uint8_t hrd) {
    item->raw[0] |= (hrd & MASK_01_BITS) << 4;
}

void set_I021_RE_SGV_GSS(I021_RE_SGV * item, double gss_kts) {
    uint16_t gss_raw = (gss_kts / I021_RE_LSB_SGV_GSS) + 0.5;

    item->raw[0] |= (gss_raw >> 7) & MASK_04_BITS;
    item->raw[1] |= (gss_raw << 1) & MASK_08_BITS;
}

void set_I021_RE_SGV_FX(I021_RE_SGV * item, uint8_t fx) {
    item->raw[1] |= fx & MASK_01_BITS;
}

/* Subfield #1 */

void set_I021_RE_SGV_EXT1_HGT(I021_RE_SGV_EXT1 * item, double hgt_deg) {
    uint8_t hgt_raw = (hgt_deg / I021_RE_LSB_SGV_HGT) + 0.5;
    item->raw |= (hgt_raw & MASK_07_BITS) << 1;
}

void set_I021_RE_SGV_EXT1_FX(I021_RE_SGV_EXT1 * item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

/* ============================= 6th Extension ============================= */

void set_I021_RE_STA_ES(I021_RE_STA * item, uint8_t es) {
    item->raw |= (es & MASK_01_BITS) << 7;
}

void set_I021_RE_STA_UAT(I021_RE_STA * item, uint8_t uat) {
    item->raw |= (uat & MASK_01_BITS) << 6;
}

void set_I021_RE_STA_RCE(I021_RE_STA * item, uint8_t rce) {
    item->raw |= (rce & MASK_03_BITS) << 3;
}

void set_I021_RE_STA_RRL(I021_RE_STA * item, uint8_t rrl) {
    item->raw |= (rrl & MASK_02_BITS) << 1;
}

void set_I021_RE_STA_FX(I021_RE_STA * item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

/* Subfield #1 */

void set_I021_RE_STA_EXT1_PS3(I021_RE_STA_EXT1 * item, uint8_t ps3) {
    item->raw |= (ps3 & MASK_04_BITS) << 4;
}

void set_I021_RE_STA_EXT1_RRL(I021_RE_STA_EXT1 * item, uint8_t tpw) {
    item->raw |= (tpw & MASK_03_BITS) << 1;
}

void set_I021_RE_STA_EXT1_FX(I021_RE_STA_EXT1 * item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

/* Subfield #2 */

void set_I021_RE_STA_EXT2_TSI(I021_RE_STA_EXT2 * item, uint8_t tsi) {
    item->raw |= (tsi & MASK_03_BITS) << 5;
}

void set_I021_RE_STA_EXT2_MUO(I021_RE_STA_EXT2 * item, uint8_t muo) {
    item->raw |= (muo & MASK_02_BITS) << 3;
}

void set_I021_RE_STA_EXT2_RWC(I021_RE_STA_EXT2 * item, uint8_t rwc) {
    item->raw |= (rwc & MASK_02_BITS) << 1;
}

void set_I021_RE_STA_EXT2_FX(I021_RE_STA_EXT2 * item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

/* Subfield #3 */

void set_I021_RE_STA_EXT3_DAA(I021_RE_STA_EXT3 * item, uint8_t daa) {
    item->raw |= (daa & MASK_03_BITS) << 5;
}

void set_I021_RE_STA_EXT3_DF17CA(I021_RE_STA_EXT3 * item, uint8_t df17ca) {
    item->raw |= (df17ca & MASK_04_BITS) << 1;
}

void set_I021_RE_STA_EXT3_FX(I021_RE_STA_EXT3 * item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

/* Subfield #4 */

void set_I021_RE_STA_EXT4_SVH(I021_RE_STA_EXT4 * item, uint8_t svh) {
    item->raw |= (svh & MASK_03_BITS) << 5;
}

void set_I021_RE_STA_EXT4_CATC(I021_RE_STA_EXT4 * item, uint8_t catc) {
    item->raw |= (catc & MASK_04_BITS) << 1;
}

void set_I021_RE_STA_EXT4_FX(I021_RE_STA_EXT4 * item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

/* Subfield #5 */

void set_I021_RE_STA_EXT5_CATC(I021_RE_STA_EXT5 * item, uint8_t tao) {
    item->raw |= (tao & MASK_06_BITS) << 2;
}

void set_I021_RE_STA_EXT5_FX(I021_RE_STA_EXT5 * item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

/* ============================= 7th Extension ============================= */

void set_I021_RE_TNH(I021_RE_TNH * item, double tnh_deg) {
    uint16_t tnh_raw = (tnh_deg / I021_RE_LSB_TNH) + 0.5;
    item->raw[0] = tnh_raw >> 8;
    item->raw[1] = tnh_raw & MASK_08_BITS;
}

/* ============================= 8th Extension ============================= */

void set_I021_MES_SUM(I021_RE_MES * item, uint8_t sum_presence) {
    item->raw |= (sum_presence & MASK_01_BITS) << 7;
}

void set_I021_MES_PNO(I021_RE_MES * item, uint8_t pno_presence) {
    item->raw |= (pno_presence & MASK_01_BITS) << 6;
}

void set_I021_MES_EM1(I021_RE_MES * item, uint8_t em1_presence) {
    item->raw |= (em1_presence & MASK_01_BITS) << 5;
}

void set_I021_MES_XP(I021_RE_MES * item, uint8_t xp_presence) {
    item->raw |= (xp_presence & MASK_01_BITS) << 4;
}

void set_I021_MES_FOM(I021_RE_MES * item, uint8_t fom_presence) {
    item->raw |= (fom_presence & MASK_01_BITS) << 3;
}

void set_I021_MES_M2(I021_RE_MES * item, uint8_t m2_presence) {
    item->raw |= (m2_presence & MASK_01_BITS) << 2;
}

void set_I021_MES_FX(I021_RE_MES * item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

/* Subfield #1 */

void set_I021_RE_MES_EXT1_M5(I021_RE_MES_EXT1 * item, uint8_t m5) {
    item->raw |= (m5 & MASK_01_BITS) << 7;
}

void set_I021_RE_MES_EXT1_ID(I021_RE_MES_EXT1 * item, uint8_t id) {
    item->raw |= (id & MASK_01_BITS) << 6;
}

void set_I021_RE_MES_EXT1_DA(I021_RE_MES_EXT1 * item, uint8_t da) {
    item->raw |= (da & MASK_01_BITS) << 5;
}

void set_I021_RE_MES_EXT1_M1(I021_RE_MES_EXT1 * item, uint8_t m1) {
    item->raw |= (m1 & MASK_01_BITS) << 4;
}

void set_I021_RE_MES_EXT1_M2(I021_RE_MES_EXT1 * item, uint8_t m2) {
    item->raw |= (m2 & MASK_01_BITS) << 3;
}

void set_I021_RE_MES_EXT1_M3(I021_RE_MES_EXT1 * item, uint8_t m3) {
    item->raw |= (m3 & MASK_01_BITS) << 2;
}

void set_I021_RE_MES_EXT1_MC(I021_RE_MES_EXT1 * item, uint8_t mc) {
    item->raw |= (mc & MASK_01_BITS) << 1;
}

void set_I021_RE_MES_EXT1_PO(I021_RE_MES_EXT1 * item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

/* Subfield #2 */

void set_I021_RE_MES_EXT2_PIN(I021_RE_MES_EXT2 * item, uint16_t pin) {
    item->raw[0] |= (pin >> 8) & MASK_06_BITS;
    item->raw[1] = pin & MASK_08_BITS;
}

void set_I021_RE_MES_EXT2_NO(I021_RE_MES_EXT2 * item, uint16_t no) {
    item->raw[2] |= (no >> 8) & MASK_03_BITS;
    item->raw[3] = no & MASK_08_BITS;
}

/* Subfield #3 */

void set_I021_RE_MES_EXT3_V(I021_RE_MES_EXT3 * item, uint8_t v) {
    item->raw[0] |= (v & MASK_01_BITS) << 7;
}

void set_I021_RE_MES_EXT3_L(I021_RE_MES_EXT3 * item, uint8_t l) {
    item->raw[0] |= (l & MASK_01_BITS) << 5;
}

void set_I021_RE_MES_EXT3_EM1(I021_RE_MES_EXT3 * item, uint16_t em1) {
    item->raw[0] |= (em1 >> 8) & MASK_04_BITS;
    item->raw[1] = em1 & MASK_08_BITS;
}

/* Subfield #4 */

void set_I021_RE_MES_EXT4_XP(I021_RE_MES_EXT4 * item, uint8_t xp) {
    item->raw |= (xp & MASK_01_BITS) << 5;
}

void set_I021_RE_MES_EXT4_X5(I021_RE_MES_EXT4 * item, uint8_t x5) {
    item->raw |= (x5 & MASK_01_BITS) << 4;
}

void set_I021_RE_MES_EXT4_XC(I021_RE_MES_EXT4 * item, uint8_t x4) {
    item->raw |= (x4 & MASK_01_BITS) << 3;
}

void set_I021_RE_MES_EXT4_X3(I021_RE_MES_EXT4 * item, uint8_t x3) {
    item->raw |= (x3 & MASK_01_BITS) << 2;
}

void set_I021_RE_MES_EXT4_X2(I021_RE_MES_EXT4 * item, uint8_t x2) {
    item->raw |= (x2 & MASK_01_BITS) << 1;
}

void set_I021_RE_MES_EXT4_X1(I021_RE_MES_EXT4 * item, uint8_t x1) {
    item->raw |= x1 & MASK_01_BITS;
}

/* Subfield #5 */

void set_I021_RE_MES_EXT5_FOM(I021_RE_MES_EXT5 * item, uint8_t fom) {
    item->raw = fom & MASK_05_BITS;
}

/* Subfield #6 */

void set_I021_RE_MES_EXT6_V(I021_RE_MES_EXT6 * item, uint8_t v) {
    item->raw[0] |= (v & MASK_01_BITS) << 7;
}

void set_I021_RE_MES_EXT6_L(I021_RE_MES_EXT6 * item, uint8_t l) {
    item->raw[0] |= (l & MASK_01_BITS) << 5;
}

void set_I021_RE_MES_EXT6_EM2(I021_RE_MES_EXT6 * item, uint16_t m2) {
    item->raw[0] |= (m2 >> 8) & MASK_04_BITS;
    item->raw[1] = m2 & MASK_08_BITS;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_RE(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    /* ============================= Main Byte ============================= */
    I021_RE * item = (I021_RE *) item_in;
    msg_out[out_index++] = item->LEN;
    msg_out[out_index++] = item->FSPEC.raw;
    /* =========================== 1st Extension =========================== */
    if (get_I021_RE_FSPEC_BPS(item)) {
        msg_out[out_index++] = item->BPS.raw[0];
        msg_out[out_index++] = item->BPS.raw[1];
    }
    /* =========================== 2nd Extension =========================== */
    if (get_I021_RE_FSPEC_SELH(item)) {
        msg_out[out_index++] = item->SELH.raw[0];
        msg_out[out_index++] = item->SELH.raw[1];
    }
    /* =========================== 3rd Extension =========================== */
    if (get_I021_RE_FSPEC_NAV(item)) {
        msg_out[out_index++] = item->NAV.raw;
    }
    /* =========================== 4th Extension =========================== */
    if (get_I021_RE_FSPEC_GAO(item)) {
        msg_out[out_index++] = item->GAO.raw;
    }
    /* =========================== 5th Extension =========================== */
    if (get_I021_RE_FSPEC_SGV(item)) {
        msg_out[out_index++] = item->SGV.raw[0];
        msg_out[out_index++] = item->SGV.raw[1];
        if (get_I021_RE_SGV_FX(&(item->SGV))) {
            msg_out[out_index++] = item->SGV.ext1.raw;
        }
    }
    /* =========================== 6th Extension =========================== */
    if (get_I021_RE_FSPEC_STA(item)) {
        msg_out[out_index++] = item->STA.raw;
        if (get_I021_RE_STA_FX(&(item->STA))) {
            msg_out[out_index++] = item->STA.ext1.raw;
        }
        if (get_I021_RE_STA_EXT1_FX(&(item->STA.ext1))) {
            msg_out[out_index++] = item->STA.ext2.raw;
        }
        if (get_I021_RE_STA_EXT2_FX(&(item->STA.ext2))) {
            msg_out[out_index++] = item->STA.ext3.raw;
        }
        if (get_I021_RE_STA_EXT3_FX(&(item->STA.ext3))) {
            msg_out[out_index++] = item->STA.ext4.raw;
        }
        if (get_I021_RE_STA_EXT4_FX(&(item->STA.ext4))) {
            msg_out[out_index++] = item->STA.ext5.raw;
        }
    }
    /* =========================== 7th Extension =========================== */
    if (get_I021_RE_FSPEC_TNH(item)) {
        msg_out[out_index++] = item->TNH.raw[0];
        msg_out[out_index++] = item->TNH.raw[1];
    }
    /* =========================== 8th Extension =========================== */
    if (get_I021_RE_FSPEC_MES(item)) {
        /* Copy Primary Subfield */
        msg_out[out_index++] = item->MES.raw;
        /* Subfield #1 (1 Byte) */
        if (get_I021_RE_MES_SUM(&(item->MES))) {
            msg_out[out_index++] = item->MES.ext1.raw;
        }
        /* Subfield #2 (4 Bytes)*/
        if (get_I021_RE_MES_PNO(&(item->MES))) {
            msg_out[out_index++] = item->MES.ext2.raw[0];
            msg_out[out_index++] = item->MES.ext2.raw[1];
            msg_out[out_index++] = item->MES.ext2.raw[2];
            msg_out[out_index++] = item->MES.ext2.raw[3];
        }
        /* Subfield #3 (2 Bytes) */
        if (get_I021_RE_MES_EM1(&(item->MES))) {
            msg_out[out_index++] = item->MES.ext3.raw[0];
            msg_out[out_index++] = item->MES.ext3.raw[1];
        }
        /* Subfield #4 (1 Byte) */
        if (get_I021_RE_MES_XP(&(item->MES))) {
            msg_out[out_index++] = item->MES.ext4.raw;
        }
        /* Subfield #5 (1 Byte) */
        if (get_I021_RE_MES_FOM(&(item->MES))) {
            msg_out[out_index++] = item->MES.ext5.raw;
        }
        /* Subfield #6 (2 Bytes) */
        if (get_I021_RE_MES_M2(&(item->MES))) {
            msg_out[out_index++] = item->MES.ext6.raw[0];
            msg_out[out_index++] = item->MES.ext6.raw[1];
        }
    }
    return out_index;
}

uint16_t decode_I021_RE(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    /* ============================= Main Byte ============================= */
    I021_RE * item = (I021_RE *) item_out;
    item->LEN = msg_in[in_index++];
    item->FSPEC.raw = msg_in[in_index++];
    /* =========================== 1st Extension =========================== */
    if (get_I021_RE_FSPEC_BPS(item)) {
        item->BPS.raw[0] = msg_in[in_index++];
        item->BPS.raw[1] = msg_in[in_index++];
    }
    /* =========================== 2nd Extension =========================== */
    if (get_I021_RE_FSPEC_SELH(item)) {
        item->SELH.raw[0] = msg_in[in_index++];
        item->SELH.raw[1] = msg_in[in_index++];
    }
    /* =========================== 3rd Extension =========================== */
    if (get_I021_RE_FSPEC_NAV(item)) {
        item->NAV.raw = msg_in[in_index++];
    }
    /* =========================== 4th Extension =========================== */
    if (get_I021_RE_FSPEC_GAO(item)) {
        item->GAO.raw = msg_in[in_index++];
    }
    /* =========================== 5th Extension =========================== */
    if (get_I021_RE_FSPEC_SGV(item)) {
        item->SGV.raw[0] = msg_in[in_index++];
        item->SGV.raw[1] = msg_in[in_index++];
        if (get_I021_RE_SGV_FX(&(item->SGV))) {
            item->SGV.ext1.raw = msg_in[in_index++];
        }
    }
    /* =========================== 6th Extension =========================== */
    if (get_I021_RE_FSPEC_STA(item)) {
        item->STA.raw = msg_in[in_index++];
        if (get_I021_RE_STA_FX(&(item->STA)))
            item->STA.ext1.raw = msg_in[in_index++];
        if (get_I021_RE_STA_EXT1_FX(&(item->STA.ext1)))
            item->STA.ext2.raw = msg_in[in_index++];
        if (get_I021_RE_STA_EXT2_FX(&(item->STA.ext2)))
            item->STA.ext3.raw = msg_in[in_index++];
        if (get_I021_RE_STA_EXT3_FX(&(item->STA.ext3)))
            item->STA.ext4.raw = msg_in[in_index++];
        if (get_I021_RE_STA_EXT4_FX(&(item->STA.ext4)))
            item->STA.ext5.raw = msg_in[in_index++];
    }
    /* =========================== 7th Extension =========================== */
    if (get_I021_RE_FSPEC_TNH(item)) {
        item->TNH.raw[0] = msg_in[in_index++];
        item->TNH.raw[1] = msg_in[in_index++];
    }
    /* =========================== 8th Extension =========================== */
    if (get_I021_RE_FSPEC_MES(item)) {
        /* Copy Primary Subfield */
        item->MES.raw = msg_in[in_index++];
        /* Subfield #1 (1 Byte) */
        if (get_I021_RE_MES_SUM(&(item->MES))) {
            item->MES.ext1.raw = msg_in[in_index++];
        }
        /* Subfield #2 (4 Bytes)*/
        if (get_I021_RE_MES_PNO(&(item->MES))) {
            item->MES.ext2.raw[0] = msg_in[in_index++];
            item->MES.ext2.raw[1] = msg_in[in_index++];
            item->MES.ext2.raw[2] = msg_in[in_index++];
            item->MES.ext2.raw[3] = msg_in[in_index++];
        }
        /* Subfield #3 (2 Bytes) */
        if (get_I021_RE_MES_EM1(&(item->MES))) {
            item->MES.ext3.raw[0] = msg_in[in_index++];
            item->MES.ext3.raw[1] = msg_in[in_index++];
        }
        /* Subfield #4 (1 Byte) */
        if (get_I021_RE_MES_XP(&(item->MES))) {
            item->MES.ext4.raw = msg_in[in_index++];
        }
        /* Subfield #5 (1 Byte) */
        if (get_I021_RE_MES_FOM(&(item->MES))) {
            item->MES.ext5.raw = msg_in[in_index++];
        }
        /* Subfield #6 (2 Bytes) */
        if (get_I021_RE_MES_M2(&(item->MES))) {
            item->MES.ext6.raw[0] = msg_in[in_index++];
            item->MES.ext6.raw[1] = msg_in[in_index++];
        }
    }
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_RE(const I021_RE * item) {
    printf("Category 021 Item RE - Reserved Expansion Field\n");
    printf("  LEN = %d\n", get_I021_RE_LEN(item));
    printf("  FSPEC = 0x%02X\n", get_I021_RE_FSPEC_raw(item));
    if (get_I021_RE_FSPEC_BPS(item)) {
        printf("  BPS = %f\n", get_I021_RE_BPS(&(item->BPS)));
    }
    if (get_I021_RE_FSPEC_SELH(item)) {
        printf("  SELH_HRD = %d\n", get_I021_RE_SELH_HRD(&(item->SELH)));
        printf("  SELH_STAT = %d\n", get_I021_RE_SELH_STAT(&(item->SELH)));
        printf("  SELH_SELH = %f\n", get_I021_RE_SELH_SELH(&(item->SELH)));
    }
    if (get_I021_RE_FSPEC_NAV(item)) {
        printf("  NAV_AP = %d\n", get_I021_RE_NAV_AP(&(item->NAV)));
        printf("  NAV_VN = %d\n", get_I021_RE_NAV_VN(&(item->NAV)));
        printf("  NAV_AH = %d\n", get_I021_RE_NAV_AH(&(item->NAV)));
        printf("  NAV_AM = %d\n", get_I021_RE_NAV_AM(&(item->NAV)));
        printf("  NAV_MFM = %d\n", get_I021_RE_NAV_MFM(&(item->NAV)));
    }
    if (get_I021_RE_FSPEC_GAO(item)) {
        printf("  GAO_LAT = %d\n", get_I021_RE_GAO_LAT(&(item->GAO)));
        printf("  GAO_LON = %d\n", get_I021_RE_GAO_LON(&(item->GAO)));
    }
    if (get_I021_RE_FSPEC_SGV(item)) {
        printf("  SGV_STP = %d\n", get_I021_RE_SGV_STP(&(item->SGV)));
        printf("  SGV_HTS = %d\n", get_I021_RE_SGV_HTS(&(item->SGV)));
        printf("  SGV_HTT = %d\n", get_I021_RE_SGV_HTT(&(item->SGV)));
        printf("  SGV_HRD = %d\n", get_I021_RE_SGV_HRD(&(item->SGV)));
        printf("  SGV_GSS = %f\n", get_I021_RE_SGV_GSS(&(item->SGV)));
        printf("  SGV_FX = %d\n", get_I021_RE_SGV_FX(&(item->SGV)));
        if (get_I021_RE_SGV_FX(&(item->SGV))) {
            printf("  SGV_EXT1_HGT = %f\n", get_I021_RE_SGV_EXT1_HGT(&(item->SGV.ext1)));
            printf("  SGV_EXT1_FX = %d\n", get_I021_RE_SGV_EXT1_FX(&(item->SGV.ext1)));
        }
    }
    if (get_I021_RE_FSPEC_STA(item)) {
        printf("  STA_ES = %d\n", get_I021_RE_STA_ES(&(item->STA)));
        printf("  STA_UAT = %d\n", get_I021_RE_STA_UAT(&(item->STA)));
        printf("  STA_RCE = %d\n", get_I021_RE_STA_RCE(&(item->STA)));
        printf("  STA_RRL = %d\n", get_I021_RE_STA_RRL(&(item->STA)));
        printf("  STA_FX = %d\n", get_I021_RE_STA_FX(&(item->STA)));
        if (get_I021_RE_STA_FX(&(item->STA))) {
            printf("  STA_EXT2_TSI = %d\n", get_I021_RE_STA_EXT2_TSI(&(item->STA.ext2)));
            printf("  STA_EXT2_MUO = %d\n", get_I021_RE_STA_EXT2_MUO(&(item->STA.ext2)));
            printf("  STA_EXT2_RWC = %d\n", get_I021_RE_STA_EXT2_RWC(&(item->STA.ext2)));
            printf("  STA_EXT2_FX = %d\n", get_I021_RE_STA_EXT2_FX(&(item->STA.ext2)));
            if (get_I021_RE_STA_EXT2_FX(&(item->STA.ext2))) {
                printf("  STA_EXT3_DAA = %d\n", get_I021_RE_STA_EXT3_DAA(&(item->STA.ext3)));
                printf("  STA_EXT3_DF17CA = %d\n", get_I021_RE_STA_EXT3_DF17CA(&(item->STA.ext3)));
                printf("  STA_EXT3_FX = %d\n", get_I021_RE_STA_EXT3_FX(&(item->STA.ext3)));
                if (get_I021_RE_STA_EXT3_FX(&(item->STA.ext3))) {
                    printf("  STA_EXT4_SVH = %d\n", get_I021_RE_STA_EXT4_SVH(&(item->STA.ext4)));
                    printf("  STA_EXT4_CATC = %d\n", get_I021_RE_STA_EXT4_CATC(&(item->STA.ext4)));
                    printf("  STA_EXT4_FX = %d\n", get_I021_RE_STA_EXT4_FX(&(item->STA.ext4)));
                    if (get_I021_RE_STA_EXT4_FX(&(item->STA.ext4))) {
                        printf("  STA_EXT5_CATC = %d\n", get_I021_RE_STA_EXT5_CATC(&(item->STA.ext5)));
                        printf("  STA_EXT5_FX = %d\n", get_I021_RE_STA_EXT5_FX(&(item->STA.ext5)));
                    }
                }
            }
        }
    }
    if (get_I021_RE_FSPEC_TNH(item)) {
        printf("   TNH = %f\n", get_I021_RE_TNH((&item->TNH)));
    }
    if (get_I021_RE_FSPEC_MES(item)) {
        printf("  MES_SUM = %d\n", get_I021_RE_MES_SUM(&(item->MES)));
        printf("  MES_PNO = %d\n", get_I021_RE_MES_PNO(&(item->MES)));
        printf("  MES_EM1 = %d\n", get_I021_RE_MES_EM1(&(item->MES)));
        printf("  MES_XP = %d\n", get_I021_RE_MES_XP(&(item->MES)));
        printf("  MES_FOM = %d\n", get_I021_RE_MES_FOM(&(item->MES)));
        printf("  MES_M2 = %d\n", get_I021_RE_MES_M2(&(item->MES)));
        printf("  MES_FX = %d\n", get_I021_RE_MES_FX(&(item->MES)));
        if(get_I021_RE_MES_SUM(&(item->MES))) {
            printf("  MES_EXT1_M5 = %d\n", get_I021_RE_MES_EXT1_M5(&(item->MES.ext1)));
            printf("  MES_EXT1_ID = %d\n", get_I021_RE_MES_EXT1_ID(&(item->MES.ext1)));
            printf("  MES_EXT1_DA = %d\n", get_I021_RE_MES_EXT1_DA(&(item->MES.ext1)));
            printf("  MES_EXT1_M1 = %d\n", get_I021_RE_MES_EXT1_M1(&(item->MES.ext1)));
            printf("  MES_EXT1_M2 = %d\n", get_I021_RE_MES_EXT1_M2(&(item->MES.ext1)));
            printf("  MES_EXT1_M3 = %d\n", get_I021_RE_MES_EXT1_M3(&(item->MES.ext1)));
            printf("  MES_EXT1_MC = %d\n", get_I021_RE_MES_EXT1_MC(&(item->MES.ext1)));
            printf("  MES_EXT1_PO = %d\n", get_I021_RE_MES_EXT1_PO(&(item->MES.ext1)));
        }
        if (get_I021_RE_MES_PNO(&(item->MES))) {
            printf("  MES_EXT2_PIN = %d\n", get_I021_RE_MES_EXT2_PIN(&(item->MES.ext2)));
            printf("  MES_EXT2_NO = %d\n", get_I021_RE_MES_EXT2_NO(&(item->MES.ext2)));
        }
        if (get_I021_RE_MES_EM1(&(item->MES))) {
            printf("  MES_EXT3_V = %d\n", get_I021_RE_MES_EXT3_V(&(item->MES.ext3)));
            printf("  MES_EXT3_L = %d\n", get_I021_RE_MES_EXT3_L(&(item->MES.ext3)));
            printf("  MES_EXT3_EM1 = %d\n", get_I021_RE_MES_EXT3_EM1(&(item->MES.ext3)));
        }
        if (get_I021_RE_MES_XP(&(item->MES))) {
            printf("  MES_EXT4_XP = %d\n", get_I021_RE_MES_EXT4_XP(&(item->MES.ext4)));
            printf("  MES_EXT4_X5 = %d\n", get_I021_RE_MES_EXT4_X5(&(item->MES.ext4)));
            printf("  MES_EXT4_XC = %d\n", get_I021_RE_MES_EXT4_XC(&(item->MES.ext4)));
            printf("  MES_EXT4_X3 = %d\n", get_I021_RE_MES_EXT4_X3(&(item->MES.ext4)));
            printf("  MES_EXT4_X2 = %d\n", get_I021_RE_MES_EXT4_X2(&(item->MES.ext4)));
            printf("  MES_EXT4_X1 = %d\n", get_I021_RE_MES_EXT4_X1(&(item->MES.ext4)));
        }
        if (get_I021_RE_MES_FOM(&(item->MES))) {
            printf("  MES_EXT5_FOM = %d\n", get_I021_RE_MES_EXT5_FOM(&(item->MES.ext5)));
        }
        if (get_I021_RE_MES_M2(&(item->MES))) {
            printf("  MES_EXT6_V = %d\n", get_I021_RE_MES_EXT6_V(&(item->MES.ext6)));
            printf("  MES_EXT6_L = %d\n", get_I021_RE_MES_EXT6_L(&(item->MES.ext6)));
            printf("  MES_EXT6_M2 = %d\n", get_I021_RE_MES_EXT6_M2(&(item->MES.ext6)));
        }
    }
}