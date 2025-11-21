/**
 * @file I021_RE.c
 * @brief Implementation of the Category 21 Item RE functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_RE.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== Main Byte =============================== */

uint8_t get_I021_RE_LEN(const I021_RE * item)
{
    if (!item) return 0;
    return item->LEN;
}

uint8_t get_I021_RE_FSPEC_raw(const I021_RE * item)
{
    if (!item) return 0;
    return item->FSPEC.raw;
}

uint8_t get_I021_RE_FSPEC_BPS(const I021_RE * item)
{
    if (!item) return 0;
    return read_bits(&item->FSPEC.raw, MASK_01_BITS, 7);
}

uint8_t get_I021_RE_FSPEC_SELH(const I021_RE * item)
{
    if (!item) return 0;
    return read_bits(&item->FSPEC.raw, MASK_01_BITS, 6);
}

uint8_t get_I021_RE_FSPEC_NAV(const I021_RE * item)
{
    if (!item) return 0;
    return read_bits(&item->FSPEC.raw, MASK_01_BITS, 5);
}

uint8_t get_I021_RE_FSPEC_GAO(const I021_RE * item)
{
    if (!item) return 0;
    return read_bits(&item->FSPEC.raw, MASK_01_BITS, 4);
}

uint8_t get_I021_RE_FSPEC_SGV(const I021_RE * item)
{
    if (!item) return 0;
    return read_bits(&item->FSPEC.raw, MASK_01_BITS, 3);
}

uint8_t get_I021_RE_FSPEC_STA(const I021_RE * item)
{
    if (!item) return 0;
    return read_bits(&item->FSPEC.raw, MASK_01_BITS, 2);
}

uint8_t get_I021_RE_FSPEC_TNH(const I021_RE * item)
{
    if (!item) return 0;
    return read_bits(&item->FSPEC.raw, MASK_01_BITS, 1);
}

uint8_t get_I021_RE_FSPEC_MES(const I021_RE * item)
{
    if (!item) return 0;
    return read_bits(&item->FSPEC.raw, MASK_01_BITS, 0);
}

/* ============================= 1st Extension ============================= */

double get_I021_RE_BPS(const I021_RE_BPS * item)
{
    if (!item) return 0.0F;
    return read_unsigned_16bit(item->raw) * I021_RE_LSB_BSP;
}

/* ============================= 2nd Extension ============================= */

uint8_t get_I021_RE_SELH_HRD(const I021_RE_SELH * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 3);
}

uint8_t get_I021_RE_SELH_STAT(const I021_RE_SELH * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 2);
}

double get_I021_RE_SELH_SELH(const I021_RE_SELH * item)
{
    if (!item) return 0.0F;
    return (read_unsigned_16bit(item->raw) & MASK_10_BITS) * I021_RE_LSB_SELH;
}

/* ============================= 3rd Extension ============================= */

uint8_t get_I021_RE_NAV_AP(const I021_RE_NAV * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 7);
}

uint8_t get_I021_RE_NAV_VN(const I021_RE_NAV * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 6);
}

uint8_t get_I021_RE_NAV_AH(const I021_RE_NAV * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 5);
}

uint8_t get_I021_RE_NAV_AM(const I021_RE_NAV * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 4);
}

uint8_t get_I021_RE_NAV_MFM(const I021_RE_NAV * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_02_BITS, 2);
}

/* ============================= 4th Extension ============================= */

uint8_t get_I021_RE_GAO_LAT(const I021_RE_GAO * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_03_BITS, 5) * I021_RE_LSB_GAO_LAT;
}

uint8_t get_I021_RE_GAO_LON(const I021_RE_GAO * item)
{
    if (!item) return 0;
    return read_bits(&item->raw , MASK_05_BITS, 0) * I021_RE_LSB_GAO_LON;
}

/* ============================= 5th Extension ============================= */

uint8_t get_I021_RE_SGV_STP(const I021_RE_SGV * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 7);
}

uint8_t get_I021_RE_SGV_HTS(const I021_RE_SGV * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 6);
}

uint8_t get_I021_RE_SGV_HTT(const I021_RE_SGV * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 5);
}

uint8_t get_I021_RE_SGV_HRD(const I021_RE_SGV * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 4);
}

double get_I021_RE_SGV_GSS(const I021_RE_SGV * item)
{
    if (!item) return 0;
    return ((read_unsigned_16bit(item->raw) >> 1) & MASK_11_BITS) * I021_RE_LSB_SGV_GSS;
}

uint8_t get_I021_RE_SGV_FX(const I021_RE_SGV * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[1], MASK_01_BITS, 0);
}

/* Subfield #1 */

double get_I021_RE_SGV_EXT1_HGT(const I021_RE_SGV_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_07_BITS, 1) * I021_RE_LSB_SGV_HGT;
}

uint8_t get_I021_RE_SGV_EXT1_FX(const I021_RE_SGV_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* ============================= 6th Extension ============================= */

uint8_t get_I021_RE_STA_ES(const I021_RE_STA * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 7);
}

uint8_t get_I021_RE_STA_UAT(const I021_RE_STA * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 6);
}

uint8_t get_I021_RE_STA_RCE(const I021_RE_STA * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_03_BITS, 3);
}

uint8_t get_I021_RE_STA_RRL(const I021_RE_STA * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_02_BITS, 1);
}

uint8_t get_I021_RE_STA_FX(const I021_RE_STA * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* Subfield #1 */

uint8_t get_I021_RE_STA_EXT1_PS3(const I021_RE_STA_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_04_BITS, 4);
}

uint8_t get_I021_RE_STA_EXT1_RRL(const I021_RE_STA_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_03_BITS, 1);
}

uint8_t get_I021_RE_STA_EXT1_FX(const I021_RE_STA_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* Subfield #2 */

uint8_t get_I021_RE_STA_EXT2_TSI(const I021_RE_STA_EXT2 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_03_BITS, 5);
}

uint8_t get_I021_RE_STA_EXT2_MUO(const I021_RE_STA_EXT2 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_02_BITS, 3);
}

uint8_t get_I021_RE_STA_EXT2_RWC(const I021_RE_STA_EXT2 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_02_BITS, 1);
}

uint8_t get_I021_RE_STA_EXT2_FX(const I021_RE_STA_EXT2 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* Subfield #3 */

uint8_t get_I021_RE_STA_EXT3_DAA(const I021_RE_STA_EXT3 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_03_BITS, 5);
}

uint8_t get_I021_RE_STA_EXT3_DF17CA(const I021_RE_STA_EXT3 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_04_BITS, 1);
}

uint8_t get_I021_RE_STA_EXT3_FX(const I021_RE_STA_EXT3 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* Subfield #4 */

uint8_t get_I021_RE_STA_EXT4_SVH(const I021_RE_STA_EXT4 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_03_BITS, 5);
}

uint8_t get_I021_RE_STA_EXT4_CATC(const I021_RE_STA_EXT4 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_04_BITS, 1);
}

uint8_t get_I021_RE_STA_EXT4_FX(const I021_RE_STA_EXT4 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* Subfield #5 */

uint8_t get_I021_RE_STA_EXT5_CATC(const I021_RE_STA_EXT5 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_06_BITS, 2);
}

uint8_t get_I021_RE_STA_EXT5_FX(const I021_RE_STA_EXT5 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* ============================= 7th Extension ============================= */

double get_I021_RE_TNH(const I021_RE_TNH * item)
{
    return read_unsigned_16bit(item->raw) * I021_RE_LSB_TNH;
}

/* ============================= 8th Extension ============================= */

uint8_t get_I021_RE_MES_SUM(const I021_RE_MES * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 7);
}

uint8_t get_I021_RE_MES_PNO(const I021_RE_MES * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 6);
}

uint8_t get_I021_RE_MES_EM1(const I021_RE_MES * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 5);
}

uint8_t get_I021_RE_MES_XP(const I021_RE_MES * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 4);
}

uint8_t get_I021_RE_MES_FOM(const I021_RE_MES * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 3);
}

uint8_t get_I021_RE_MES_M2(const I021_RE_MES * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 2);
}

uint8_t get_I021_RE_MES_FX(const I021_RE_MES * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* Subfield #1 */

uint8_t get_I021_RE_MES_EXT1_M5(const I021_RE_MES_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 7);
}

uint8_t get_I021_RE_MES_EXT1_ID(const I021_RE_MES_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 6);
}

uint8_t get_I021_RE_MES_EXT1_DA(const I021_RE_MES_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 5);
}

uint8_t get_I021_RE_MES_EXT1_M1(const I021_RE_MES_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 4);
}

uint8_t get_I021_RE_MES_EXT1_M2(const I021_RE_MES_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 3);
}

uint8_t get_I021_RE_MES_EXT1_M3(const I021_RE_MES_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 2);
}

uint8_t get_I021_RE_MES_EXT1_MC(const I021_RE_MES_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 1);
}

uint8_t get_I021_RE_MES_EXT1_PO(const I021_RE_MES_EXT1 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* Subfield #2 */

uint16_t get_I021_RE_MES_EXT2_PIN(const I021_RE_MES_EXT2 * item)
{
    if (!item) return 0;
    return read_unsigned_16bit(&item->raw[0]) & MASK_14_BITS;
}

uint16_t get_I021_RE_MES_EXT2_NO(const I021_RE_MES_EXT2 * item)
{
    if (!item) return 0;
    return read_unsigned_16bit(&item->raw[2]) & MASK_11_BITS;
}

/* Subfield #3 */

uint8_t get_I021_RE_MES_EXT3_V(const I021_RE_MES_EXT3 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 7);
}

uint8_t get_I021_RE_MES_EXT3_L(const I021_RE_MES_EXT3 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 5);
}

uint16_t get_I021_RE_MES_EXT3_EM1(const I021_RE_MES_EXT3 * item)
{
    if (!item) return 0;
    return read_unsigned_16bit(&item->raw[0]) & MASK_12_BITS;
}

/* Subfield #4 */

uint8_t get_I021_RE_MES_EXT4_XP(const I021_RE_MES_EXT4 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 5);
}

uint8_t get_I021_RE_MES_EXT4_X5(const I021_RE_MES_EXT4 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 4);
}

uint8_t get_I021_RE_MES_EXT4_XC(const I021_RE_MES_EXT4 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 3);
}

uint8_t get_I021_RE_MES_EXT4_X3(const I021_RE_MES_EXT4 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 2);
}

uint8_t get_I021_RE_MES_EXT4_X2(const I021_RE_MES_EXT4 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 1);
}

uint8_t get_I021_RE_MES_EXT4_X1(const I021_RE_MES_EXT4 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_01_BITS, 0);
}

/* Subfield #5 */

uint8_t get_I021_RE_MES_EXT5_FOM(const I021_RE_MES_EXT5 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw, MASK_05_BITS, 0);
}

/* Subfield #6 */

uint8_t get_I021_RE_MES_EXT6_V(const I021_RE_MES_EXT6 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 7);
}

uint8_t get_I021_RE_MES_EXT6_L(const I021_RE_MES_EXT6 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 5);
}

uint16_t get_I021_RE_MES_EXT6_M2(const I021_RE_MES_EXT6 * item)
{
    if (!item) return 0;
    return read_unsigned_16bit(&item->raw[0]) & MASK_12_BITS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* =============================== Main Byte =============================== */

void set_I021_RE_LEN(I021_RE * item, uint8_t len)
{
    if (!item) return;
    item->LEN = len;
}

void set_I021_RE_FSPEC_raw(I021_RE * item, uint8_t fspec)
{
    if (!item) return;
    item->FSPEC.raw = fspec;
}

void set_I021_RE_FSPEC_BPS(I021_RE * item, uint8_t bps_presence)
{
    if (!item) return;
    write_bits(&item->FSPEC.raw, MASK_01_BITS, 7, bps_presence);
}

void set_I021_RE_FSPEC_SELH(I021_RE * item, uint8_t selh_presence)
{
    if (!item) return;
    write_bits(&item->FSPEC.raw, MASK_01_BITS, 6, selh_presence);
}

void set_I021_RE_FSPEC_NAV(I021_RE * item, uint8_t nav_presence)
{
    if (!item) return;
    write_bits(&item->FSPEC.raw, MASK_01_BITS, 5, nav_presence);
}

void set_I021_RE_FSPEC_GAO(I021_RE * item, uint8_t gao_presence)
{
    if (!item) return;
    write_bits(&item->FSPEC.raw, MASK_01_BITS, 4, gao_presence);
}

void set_I021_RE_FSPEC_SGV(I021_RE * item, uint8_t sgv_presence)
{
    if (!item) return;
    write_bits(&item->FSPEC.raw, MASK_01_BITS, 3, sgv_presence);
}

void set_I021_RE_FSPEC_STA(I021_RE * item, uint8_t sta_presence)
{
    if (!item) return;
    write_bits(&item->FSPEC.raw, MASK_01_BITS, 2, sta_presence);
}

void set_I021_RE_FSPEC_TNH(I021_RE * item, uint8_t tnh_presence)
{
    if (!item) return;
    write_bits(&item->FSPEC.raw, MASK_01_BITS, 1, tnh_presence);
}

void set_I021_RE_FSPEC_MES(I021_RE * item, uint8_t mes_presence)
{
    if (!item) return;
    write_bits(&item->FSPEC.raw, MASK_01_BITS, 0, mes_presence);
}

/* ============================= 1st Extension ============================= */

void set_I021_RE_BPS(I021_RE_BPS * item, double bps_hPa)
{
    uint16_t bps_raw;
    if (!item) return;
    bps_raw = (bps_hPa / I021_RE_LSB_BSP) + 0.5;
    write_unsigned_16bit(item->raw, bps_raw);
}

/* ============================= 2nd Extension ============================= */

void set_I021_RE_SELH_HRD(I021_RE_SELH * item, uint8_t hrd)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 3, hrd);
}

void set_I021_RE_SELH_STAT(I021_RE_SELH * item, uint8_t stat)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 2, stat);
}

void set_I021_RE_SELH_SELH(I021_RE_SELH * item, uint8_t selh)
{
    uint16_t selh_raw;
    if (!item) return;
    selh_raw = (selh / I021_RE_LSB_SELH) + 0.5;
    write_bits(&item->raw[0], MASK_02_BITS, 0, selh_raw >> 8);
    write_unsigned_8bit(&item->raw[1], selh_raw);
}

/* ============================= 3rd Extension ============================= */

void set_I021_RE_NAV_AP(I021_RE_NAV * item, uint8_t nav)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 7, nav);
}

void set_I021_RE_NAV_VN(I021_RE_NAV * item, uint8_t vn)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 6, vn);
}

void set_I021_RE_NAV_AH(I021_RE_NAV * item, uint8_t ah)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 5, ah);
}

void set_I021_RE_NAV_AM(I021_RE_NAV * item, uint8_t am)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 4, am);
}

void set_I021_RE_NAV_MFM(I021_RE_NAV * item, uint8_t mfm)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 2, mfm);
}

/* ============================= 4th Extension ============================= */


void set_I021_RE_GAO_LAT(I021_RE_GAO * item, uint8_t lateral_m)
{
    uint8_t lateral_raw;
    if (!item) return;
    lateral_raw = (lateral_m / I021_RE_LSB_GAO_LAT) + 0.5;
    write_bits(&item->raw, MASK_03_BITS, 5, lateral_raw);
}

void set_I021_RE_GAO_LON(I021_RE_GAO * item, uint8_t longitudinal_m)
{
    uint8_t longitudinal_raw;
    if (!item) return;
    longitudinal_raw = (longitudinal_m / I021_RE_LSB_GAO_LON) + 0.5;
    write_bits(&item->raw, MASK_05_BITS, 0, longitudinal_raw);
}

/* ============================= 5th Extension ============================= */

void set_I021_RE_SGV_STP(I021_RE_SGV * item, uint8_t stp)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 7, stp);
}

void set_I021_RE_SGV_HTS(I021_RE_SGV * item, uint8_t hts)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 6, hts);
}

void set_I021_RE_SGV_HTT(I021_RE_SGV * item, uint8_t htt)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 5, htt);
}

void set_I021_RE_SGV_HRD(I021_RE_SGV * item, uint8_t hrd)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 4, hrd);
}

void set_I021_RE_SGV_GSS(I021_RE_SGV * item, double gss_kts)
{
    uint16_t gss_raw;
    if (!item) return;
    gss_raw = (gss_kts / I021_RE_LSB_SGV_GSS) + 0.5;
    write_bits(&item->raw[0], MASK_04_BITS, 0, gss_raw >> 7);
    write_bits(&item->raw[1], MASK_07_BITS, 1, gss_raw);
}

void set_I021_RE_SGV_FX(I021_RE_SGV * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 0, fx);
}

/* Subfield #1 */

void set_I021_RE_SGV_EXT1_HGT(I021_RE_SGV_EXT1 * item, double hgt_deg)
{
    if (!item) return;
    uint8_t hgt_raw = (hgt_deg / I021_RE_LSB_SGV_HGT) + 0.5;
    write_bits(&item->raw, MASK_07_BITS, 1, hgt_raw);
}

void set_I021_RE_SGV_EXT1_FX(I021_RE_SGV_EXT1 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* ============================= 6th Extension ============================= */

void set_I021_RE_STA_ES(I021_RE_STA * item, uint8_t es)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 7, es);
}

void set_I021_RE_STA_UAT(I021_RE_STA * item, uint8_t uat)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 6, uat);
}

void set_I021_RE_STA_RCE(I021_RE_STA * item, uint8_t rce)
{
    if (!item) return;
    write_bits(&item->raw, MASK_03_BITS, 3, rce);
}

void set_I021_RE_STA_RRL(I021_RE_STA * item, uint8_t rrl)
{
    if (!item) return;
    write_bits(&item->raw, MASK_02_BITS, 1, rrl);
}

void set_I021_RE_STA_FX(I021_RE_STA * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* Subfield #1 */

void set_I021_RE_STA_EXT1_PS3(I021_RE_STA_EXT1 * item, uint8_t ps3)
{
    if (!item) return;
    write_bits(&item->raw, MASK_04_BITS, 4, ps3);
}

void set_I021_RE_STA_EXT1_RRL(I021_RE_STA_EXT1 * item, uint8_t tpw)
{
    if (!item) return;
    write_bits(&item->raw, MASK_03_BITS, 1, tpw);
}

void set_I021_RE_STA_EXT1_FX(I021_RE_STA_EXT1 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* Subfield #2 */

void set_I021_RE_STA_EXT2_TSI(I021_RE_STA_EXT2 * item, uint8_t tsi)
{
    if (!item) return;
    write_bits(&item->raw, MASK_03_BITS, 5, tsi);
}

void set_I021_RE_STA_EXT2_MUO(I021_RE_STA_EXT2 * item, uint8_t muo)
{
    if (!item) return;
    write_bits(&item->raw, MASK_02_BITS, 3, muo);
}

void set_I021_RE_STA_EXT2_RWC(I021_RE_STA_EXT2 * item, uint8_t rwc)
{
    if (!item) return;
    write_bits(&item->raw, MASK_02_BITS, 1, rwc);
}

void set_I021_RE_STA_EXT2_FX(I021_RE_STA_EXT2 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* Subfield #3 */

void set_I021_RE_STA_EXT3_DAA(I021_RE_STA_EXT3 * item, uint8_t daa)
{
    if (!item) return;
    write_bits(&item->raw, MASK_03_BITS, 5, daa);
}

void set_I021_RE_STA_EXT3_DF17CA(I021_RE_STA_EXT3 * item, uint8_t df17ca)
{
    if (!item) return;
    write_bits(&item->raw, MASK_04_BITS, 1, df17ca);
}

void set_I021_RE_STA_EXT3_FX(I021_RE_STA_EXT3 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* Subfield #4 */

void set_I021_RE_STA_EXT4_SVH(I021_RE_STA_EXT4 * item, uint8_t svh)
{
    if (!item) return;
    write_bits(&item->raw, MASK_03_BITS, 5, svh);
}

void set_I021_RE_STA_EXT4_CATC(I021_RE_STA_EXT4 * item, uint8_t catc)
{
    if (!item) return;
    write_bits(&item->raw, MASK_04_BITS, 1, catc);
}

void set_I021_RE_STA_EXT4_FX(I021_RE_STA_EXT4 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* Subfield #5 */

void set_I021_RE_STA_EXT5_CATC(I021_RE_STA_EXT5 * item, uint8_t tao)
{
    if (!item) return;
    write_bits(&item->raw, MASK_06_BITS, 2, tao);
}

void set_I021_RE_STA_EXT5_FX(I021_RE_STA_EXT5 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* ============================= 7th Extension ============================= */

void set_I021_RE_TNH(I021_RE_TNH * item, double tnh_deg)
{
    uint16_t tnh_raw;
    if (!item) return;
    tnh_raw = (tnh_deg / I021_RE_LSB_TNH) + 0.5;
    write_unsigned_16bit(item->raw, tnh_raw);
}

/* ============================= 8th Extension ============================= */

void set_I021_MES_SUM(I021_RE_MES * item, uint8_t sum_presence)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 7, sum_presence);
}

void set_I021_MES_PNO(I021_RE_MES * item, uint8_t pno_presence)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 6, pno_presence);
}

void set_I021_MES_EM1(I021_RE_MES * item, uint8_t em1_presence)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 5, em1_presence);
}

void set_I021_MES_XP(I021_RE_MES * item, uint8_t xp_presence)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 4, xp_presence);
}

void set_I021_MES_FOM(I021_RE_MES * item, uint8_t fom_presence)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 3, fom_presence);
}

void set_I021_MES_M2(I021_RE_MES * item, uint8_t m2_presence)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 2, m2_presence);
}

void set_I021_MES_FX(I021_RE_MES * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* Subfield #1 */

void set_I021_RE_MES_EXT1_M5(I021_RE_MES_EXT1 * item, uint8_t m5)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 7, m5);
}

void set_I021_RE_MES_EXT1_ID(I021_RE_MES_EXT1 * item, uint8_t id)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 6, id);
}

void set_I021_RE_MES_EXT1_DA(I021_RE_MES_EXT1 * item, uint8_t da)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 5, da);
}

void set_I021_RE_MES_EXT1_M1(I021_RE_MES_EXT1 * item, uint8_t m1)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 4, m1);
}

void set_I021_RE_MES_EXT1_M2(I021_RE_MES_EXT1 * item, uint8_t m2)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 3, m2);
}

void set_I021_RE_MES_EXT1_M3(I021_RE_MES_EXT1 * item, uint8_t m3)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 2, m3);
}

void set_I021_RE_MES_EXT1_MC(I021_RE_MES_EXT1 * item, uint8_t mc)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 1, mc);
}

void set_I021_RE_MES_EXT1_PO(I021_RE_MES_EXT1 * item, uint8_t fx)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, fx);
}

/* Subfield #2 */

void set_I021_RE_MES_EXT2_PIN(I021_RE_MES_EXT2 * item, uint16_t pin)
{
    if (!item) return;
    write_unsigned_16bit(&item->raw[0], pin);
}

void set_I021_RE_MES_EXT2_NO(I021_RE_MES_EXT2 * item, uint16_t no)
{
    if (!item) return;
    write_unsigned_16bit(&item->raw[2], no);
}

/* Subfield #3 */

void set_I021_RE_MES_EXT3_V(I021_RE_MES_EXT3 * item, uint8_t v)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 7, v);
}

void set_I021_RE_MES_EXT3_L(I021_RE_MES_EXT3 * item, uint8_t l)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 5, l);
}

void set_I021_RE_MES_EXT3_EM1(I021_RE_MES_EXT3 * item, uint16_t em1)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_04_BITS, 0, em1 >> 8);
    write_unsigned_8bit(&item->raw[1], em1);
}

/* Subfield #4 */

void set_I021_RE_MES_EXT4_XP(I021_RE_MES_EXT4 * item, uint8_t xp)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 5, xp);
}

void set_I021_RE_MES_EXT4_X5(I021_RE_MES_EXT4 * item, uint8_t x5)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 4, x5);
}

void set_I021_RE_MES_EXT4_XC(I021_RE_MES_EXT4 * item, uint8_t x4)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 3, x4);
}

void set_I021_RE_MES_EXT4_X3(I021_RE_MES_EXT4 * item, uint8_t x3)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 2, x3);
}

void set_I021_RE_MES_EXT4_X2(I021_RE_MES_EXT4 * item, uint8_t x2)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 1, x2);
}

void set_I021_RE_MES_EXT4_X1(I021_RE_MES_EXT4 * item, uint8_t x1)
{
    if (!item) return;
    write_bits(&item->raw, MASK_01_BITS, 0, x1);
}

/* Subfield #5 */

void set_I021_RE_MES_EXT5_FOM(I021_RE_MES_EXT5 * item, uint8_t fom)
{
    if (!item) return;
    write_unsigned_8bit(&item->raw, fom);
}

/* Subfield #6 */

void set_I021_RE_MES_EXT6_V(I021_RE_MES_EXT6 * item, uint8_t v)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 7, v);
}

void set_I021_RE_MES_EXT6_L(I021_RE_MES_EXT6 * item, uint8_t l)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_01_BITS, 5, l);
}

void set_I021_RE_MES_EXT6_EM2(I021_RE_MES_EXT6 * item, uint16_t m2)
{
    if (!item) return;
    write_bits(&item->raw[0], MASK_04_BITS, 0, m2 >> 8);
    write_unsigned_8bit(&item->raw[1], m2);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_RE(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    /* ============================= Main Byte ============================= */
    I021_RE *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_RE *) item_in;
    msg_out[out_index++] = item->LEN;
    msg_out[out_index++] = item->FSPEC.raw;
    /* =========================== 1st Extension =========================== */
    if (get_I021_RE_FSPEC_BPS(item))
    {
        memcpy(&msg_out[out_index], item->BPS.raw, 2);
        out_index += 2;
    }
    /* =========================== 2nd Extension =========================== */
    if (get_I021_RE_FSPEC_SELH(item))
    {
        memcpy(&msg_out[out_index], item->SELH.raw, 2);
        out_index += 2;
    }
    /* =========================== 3rd Extension =========================== */
    if (get_I021_RE_FSPEC_NAV(item))
    {
        msg_out[out_index++] = item->NAV.raw;
    }
    /* =========================== 4th Extension =========================== */
    if (get_I021_RE_FSPEC_GAO(item))
    {
        msg_out[out_index++] = item->GAO.raw;
    }
    /* =========================== 5th Extension =========================== */
    if (get_I021_RE_FSPEC_SGV(item))
    {
        memcpy(&msg_out[out_index], item->SGV.raw, 2);
        out_index += 2;
        if (get_I021_RE_SGV_FX(&(item->SGV)))
        {
            msg_out[out_index++] = item->SGV.ext1.raw;
        }
    }
    /* =========================== 6th Extension =========================== */
    if (get_I021_RE_FSPEC_STA(item))
    {
        msg_out[out_index++] = item->STA.raw;
        if (get_I021_RE_STA_FX(&(item->STA)))
        {
            msg_out[out_index++] = item->STA.ext1.raw;
        }
        if (get_I021_RE_STA_EXT1_FX(&(item->STA.ext1)))
        {
            msg_out[out_index++] = item->STA.ext2.raw;
        }
        if (get_I021_RE_STA_EXT2_FX(&(item->STA.ext2)))
        {
            msg_out[out_index++] = item->STA.ext3.raw;
        }
        if (get_I021_RE_STA_EXT3_FX(&(item->STA.ext3)))
        {
            msg_out[out_index++] = item->STA.ext4.raw;
        }
        if (get_I021_RE_STA_EXT4_FX(&(item->STA.ext4)))
        {
            msg_out[out_index++] = item->STA.ext5.raw;
        }
    }
    /* =========================== 7th Extension =========================== */
    if (get_I021_RE_FSPEC_TNH(item))
    {
        memcpy(&msg_out[out_index], item->TNH.raw, 2);
        out_index += 2;
    }
    /* =========================== 8th Extension =========================== */
    if (get_I021_RE_FSPEC_MES(item))
    {
        /* Copy Primary Subfield */
        msg_out[out_index++] = item->MES.raw;
        /* Subfield #1 (1 Byte) */
        if (get_I021_RE_MES_SUM(&(item->MES)))
        {
            msg_out[out_index++] = item->MES.ext1.raw;
        }
        /* Subfield #2 (4 Bytes)*/
        if (get_I021_RE_MES_PNO(&(item->MES)))
        {
            memcpy(&msg_out[out_index], item->MES.ext2.raw, 4);
            out_index += 4;
        }
        /* Subfield #3 (2 Bytes) */
        if (get_I021_RE_MES_EM1(&(item->MES)))
        {
            memcpy(&msg_out[out_index], item->MES.ext3.raw, 2);
            out_index += 2;
        }
        /* Subfield #4 (1 Byte) */
        if (get_I021_RE_MES_XP(&(item->MES)))
        {
            msg_out[out_index++] = item->MES.ext4.raw;
        }
        /* Subfield #5 (1 Byte) */
        if (get_I021_RE_MES_FOM(&(item->MES)))
        {
            msg_out[out_index++] = item->MES.ext5.raw;
        }
        /* Subfield #6 (2 Bytes) */
        if (get_I021_RE_MES_M2(&(item->MES)))
        {
            memcpy(&msg_out[out_index], item->MES.ext6.raw, 2);
            out_index += 2;
        }
    }
    return out_index;
}

uint16_t decode_I021_RE(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    /* ============================= Main Byte ============================= */
    I021_RE *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_RE *) item_out;
    item->LEN = msg_in[in_index++];
    item->FSPEC.raw = msg_in[in_index++];
    /* =========================== 1st Extension =========================== */
    if (get_I021_RE_FSPEC_BPS(item))
    {
        memcpy(item->BPS.raw, &msg_in[in_index], 2);
        in_index += 2;
    }
    /* =========================== 2nd Extension =========================== */
    if (get_I021_RE_FSPEC_SELH(item))
    {
        memcpy(item->SELH.raw, &msg_in[in_index], 2);
        in_index += 2;
    }
    /* =========================== 3rd Extension =========================== */
    if (get_I021_RE_FSPEC_NAV(item))
    {
        item->NAV.raw = msg_in[in_index++];
    }
    /* =========================== 4th Extension =========================== */
    if (get_I021_RE_FSPEC_GAO(item))
    {
        item->GAO.raw = msg_in[in_index++];
    }
    /* =========================== 5th Extension =========================== */
    if (get_I021_RE_FSPEC_SGV(item))
    {
        memcpy(item->SGV.raw, &msg_in[in_index], 2);
        in_index += 2;
        if (get_I021_RE_SGV_FX(&(item->SGV)))
        {
            item->SGV.ext1.raw = msg_in[in_index++];
        }
    }
    /* =========================== 6th Extension =========================== */
    if (get_I021_RE_FSPEC_STA(item))
    {
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
    if (get_I021_RE_FSPEC_TNH(item))
    {
        memcpy(item->TNH.raw, &msg_in[in_index], 2);
        in_index += 2;
    }
    /* =========================== 8th Extension =========================== */
    if (get_I021_RE_FSPEC_MES(item))
    {
        /* Copy Primary Subfield */
        item->MES.raw = msg_in[in_index++];
        /* Subfield #1 (1 Byte) */
        if (get_I021_RE_MES_SUM(&(item->MES)))
        {
            item->MES.ext1.raw = msg_in[in_index++];
        }
        /* Subfield #2 (4 Bytes)*/
        if (get_I021_RE_MES_PNO(&(item->MES)))
        {
            memcpy(item->MES.ext2.raw, &msg_in[in_index], 4);
            in_index += 4;
        }
        /* Subfield #3 (2 Bytes) */
        if (get_I021_RE_MES_EM1(&(item->MES)))
        {
            memcpy(item->MES.ext3.raw, &msg_in[in_index], 2);
            in_index += 2;
        }
        /* Subfield #4 (1 Byte) */
        if (get_I021_RE_MES_XP(&(item->MES)))
        {
            item->MES.ext4.raw = msg_in[in_index++];
        }
        /* Subfield #5 (1 Byte) */
        if (get_I021_RE_MES_FOM(&(item->MES)))
        {
            item->MES.ext5.raw = msg_in[in_index++];
        }
        /* Subfield #6 (2 Bytes) */
        if (get_I021_RE_MES_M2(&(item->MES)))
        {
            memcpy(item->MES.ext6.raw, &msg_in[in_index], 2);
            in_index += 2;
        }
    }
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_RE(const I021_RE * item)
{
    printf("021/RE - Reserved Expansion Field\n");
    if (!item)
    {
        printf("I021/RE <null>\n");
        return;
    }
    printf("- LEN = %d\n", get_I021_RE_LEN(item));
    printf("- FSPEC = 0x%02X\n", get_I021_RE_FSPEC_raw(item));
    if (get_I021_RE_FSPEC_BPS(item))
    {
        printf("- BPS = %f\n", get_I021_RE_BPS(&(item->BPS)));
    }
    if (get_I021_RE_FSPEC_SELH(item))
    {
        printf("- SELH_HRD = %d\n", get_I021_RE_SELH_HRD(&(item->SELH)));
        printf("- SELH_STAT = %d\n", get_I021_RE_SELH_STAT(&(item->SELH)));
        printf("- SELH_SELH = %f\n", get_I021_RE_SELH_SELH(&(item->SELH)));
    }
    if (get_I021_RE_FSPEC_NAV(item))
    {
        printf("- NAV_AP = %d\n", get_I021_RE_NAV_AP(&(item->NAV)));
        printf("- NAV_VN = %d\n", get_I021_RE_NAV_VN(&(item->NAV)));
        printf("- NAV_AH = %d\n", get_I021_RE_NAV_AH(&(item->NAV)));
        printf("- NAV_AM = %d\n", get_I021_RE_NAV_AM(&(item->NAV)));
        printf("- NAV_MFM = %d\n", get_I021_RE_NAV_MFM(&(item->NAV)));
    }
    if (get_I021_RE_FSPEC_GAO(item))
    {
        printf("- GAO_LAT = %d\n", get_I021_RE_GAO_LAT(&(item->GAO)));
        printf("- GAO_LON = %d\n", get_I021_RE_GAO_LON(&(item->GAO)));
    }
    if (get_I021_RE_FSPEC_SGV(item))
    {
        printf("- SGV_STP = %d\n", get_I021_RE_SGV_STP(&(item->SGV)));
        printf("- SGV_HTS = %d\n", get_I021_RE_SGV_HTS(&(item->SGV)));
        printf("- SGV_HTT = %d\n", get_I021_RE_SGV_HTT(&(item->SGV)));
        printf("- SGV_HRD = %d\n", get_I021_RE_SGV_HRD(&(item->SGV)));
        printf("- SGV_GSS = %f\n", get_I021_RE_SGV_GSS(&(item->SGV)));
        printf("- SGV_FX = %d\n", get_I021_RE_SGV_FX(&(item->SGV)));
        if (get_I021_RE_SGV_FX(&(item->SGV)))
        {
            printf("- SGV_EXT1_HGT = %f\n", get_I021_RE_SGV_EXT1_HGT(&(item->SGV.ext1)));
            printf("- SGV_EXT1_FX = %d\n", get_I021_RE_SGV_EXT1_FX(&(item->SGV.ext1)));
        }
    }
    if (get_I021_RE_FSPEC_STA(item))
    {
        printf("- STA_ES = %d\n", get_I021_RE_STA_ES(&(item->STA)));
        printf("- STA_UAT = %d\n", get_I021_RE_STA_UAT(&(item->STA)));
        printf("- STA_RCE = %d\n", get_I021_RE_STA_RCE(&(item->STA)));
        printf("- STA_RRL = %d\n", get_I021_RE_STA_RRL(&(item->STA)));
        printf("- STA_FX = %d\n", get_I021_RE_STA_FX(&(item->STA)));
        if (get_I021_RE_STA_FX(&(item->STA)))
        {
            printf("-- STA_EXT2_TSI = %d\n", get_I021_RE_STA_EXT2_TSI(&(item->STA.ext2)));
            printf("-- STA_EXT2_MUO = %d\n", get_I021_RE_STA_EXT2_MUO(&(item->STA.ext2)));
            printf("-- STA_EXT2_RWC = %d\n", get_I021_RE_STA_EXT2_RWC(&(item->STA.ext2)));
            printf("-- STA_EXT2_FX = %d\n", get_I021_RE_STA_EXT2_FX(&(item->STA.ext2)));
            if (get_I021_RE_STA_EXT2_FX(&(item->STA.ext2)))
            {
                printf("-- STA_EXT3_DAA = %d\n", get_I021_RE_STA_EXT3_DAA(&(item->STA.ext3)));
                printf("-- STA_EXT3_DF17CA = %d\n", get_I021_RE_STA_EXT3_DF17CA(&(item->STA.ext3)));
                printf("-- STA_EXT3_FX = %d\n", get_I021_RE_STA_EXT3_FX(&(item->STA.ext3)));
                if (get_I021_RE_STA_EXT3_FX(&(item->STA.ext3)))
                {
                    printf("-- STA_EXT4_SVH = %d\n", get_I021_RE_STA_EXT4_SVH(&(item->STA.ext4)));
                    printf("-- STA_EXT4_CATC = %d\n", get_I021_RE_STA_EXT4_CATC(&(item->STA.ext4)));
                    printf("-- STA_EXT4_FX = %d\n", get_I021_RE_STA_EXT4_FX(&(item->STA.ext4)));
                    if (get_I021_RE_STA_EXT4_FX(&(item->STA.ext4)))
                    {
                        printf("-- STA_EXT5_CATC = %d\n", get_I021_RE_STA_EXT5_CATC(&(item->STA.ext5)));
                        printf("-- STA_EXT5_FX = %d\n", get_I021_RE_STA_EXT5_FX(&(item->STA.ext5)));
                    }
                }
            }
        }
    }
    if (get_I021_RE_FSPEC_TNH(item))
    {
        printf("- TNH = %f\n", get_I021_RE_TNH((&item->TNH)));
    }
    if (get_I021_RE_FSPEC_MES(item))
    {
        printf("- MES_SUM = %d\n", get_I021_RE_MES_SUM(&(item->MES)));
        printf("- MES_PNO = %d\n", get_I021_RE_MES_PNO(&(item->MES)));
        printf("- MES_EM1 = %d\n", get_I021_RE_MES_EM1(&(item->MES)));
        printf("- MES_XP = %d\n", get_I021_RE_MES_XP(&(item->MES)));
        printf("- MES_FOM = %d\n", get_I021_RE_MES_FOM(&(item->MES)));
        printf("- MES_M2 = %d\n", get_I021_RE_MES_M2(&(item->MES)));
        printf("- MES_FX = %d\n", get_I021_RE_MES_FX(&(item->MES)));
        if(get_I021_RE_MES_SUM(&(item->MES)))
        {
            printf("-- MES_EXT1_M5 = %d\n", get_I021_RE_MES_EXT1_M5(&(item->MES.ext1)));
            printf("-- MES_EXT1_ID = %d\n", get_I021_RE_MES_EXT1_ID(&(item->MES.ext1)));
            printf("-- MES_EXT1_DA = %d\n", get_I021_RE_MES_EXT1_DA(&(item->MES.ext1)));
            printf("-- MES_EXT1_M1 = %d\n", get_I021_RE_MES_EXT1_M1(&(item->MES.ext1)));
            printf("-- MES_EXT1_M2 = %d\n", get_I021_RE_MES_EXT1_M2(&(item->MES.ext1)));
            printf("-- MES_EXT1_M3 = %d\n", get_I021_RE_MES_EXT1_M3(&(item->MES.ext1)));
            printf("-- MES_EXT1_MC = %d\n", get_I021_RE_MES_EXT1_MC(&(item->MES.ext1)));
            printf("-- MES_EXT1_PO = %d\n", get_I021_RE_MES_EXT1_PO(&(item->MES.ext1)));
        }
        if (get_I021_RE_MES_PNO(&(item->MES)))
        {
            printf("-- MES_EXT2_PIN = %d\n", get_I021_RE_MES_EXT2_PIN(&(item->MES.ext2)));
            printf("-- MES_EXT2_NO = %d\n", get_I021_RE_MES_EXT2_NO(&(item->MES.ext2)));
        }
        if (get_I021_RE_MES_EM1(&(item->MES)))
        {
            printf("-- MES_EXT3_V = %d\n", get_I021_RE_MES_EXT3_V(&(item->MES.ext3)));
            printf("-- MES_EXT3_L = %d\n", get_I021_RE_MES_EXT3_L(&(item->MES.ext3)));
            printf("-- MES_EXT3_EM1 = %d\n", get_I021_RE_MES_EXT3_EM1(&(item->MES.ext3)));
        }
        if (get_I021_RE_MES_XP(&(item->MES)))
        {
            printf("-- MES_EXT4_XP = %d\n", get_I021_RE_MES_EXT4_XP(&(item->MES.ext4)));
            printf("-- MES_EXT4_X5 = %d\n", get_I021_RE_MES_EXT4_X5(&(item->MES.ext4)));
            printf("-- MES_EXT4_XC = %d\n", get_I021_RE_MES_EXT4_XC(&(item->MES.ext4)));
            printf("-- MES_EXT4_X3 = %d\n", get_I021_RE_MES_EXT4_X3(&(item->MES.ext4)));
            printf("-- MES_EXT4_X2 = %d\n", get_I021_RE_MES_EXT4_X2(&(item->MES.ext4)));
            printf("-- MES_EXT4_X1 = %d\n", get_I021_RE_MES_EXT4_X1(&(item->MES.ext4)));
        }
        if (get_I021_RE_MES_FOM(&(item->MES)))
        {
            printf("-- MES_EXT5_FOM = %d\n", get_I021_RE_MES_EXT5_FOM(&(item->MES.ext5)));
        }
        if (get_I021_RE_MES_M2(&(item->MES)))
        {
            printf("-- MES_EXT6_V = %d\n", get_I021_RE_MES_EXT6_V(&(item->MES.ext6)));
            printf("-- MES_EXT6_L = %d\n", get_I021_RE_MES_EXT6_L(&(item->MES.ext6)));
            printf("-- MES_EXT6_M2 = %d\n", get_I021_RE_MES_EXT6_M2(&(item->MES.ext6)));
        }
    }
}