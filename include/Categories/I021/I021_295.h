/**
 * @file I021_295.h
 * @brief Definition of I021/295, and related functions and values
 */

#ifndef I021_295_H
#define I021_295_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_295_N_OCTETS     8   /// Number of octets of Primary Subfield

#define I021_295_LSB_EXT1_AOS       (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT2_TRD       (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT3_M3A       (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT4_QI        (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT5_TI        (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT6_MAM       (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT7_GH        (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT8_FL        (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT9_SAL       (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT10_FSA      (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT11_AS       (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT12_TAS      (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT13_MH       (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT14_BVR      (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT15_GVR      (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT16_GV       (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT17_TAR      (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT18_TID      (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT19_TS       (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT20_MET      (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT21_ROA      (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT22_ARA      (0.1)   /// LSB = 0.1 seconds
#define I021_295_LSB_EXT23_SCC      (0.1)   /// LSB = 0.1 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_295_EXT1
 * @brief Category 021 Item 295 Subfield #1 - Aircraft Operational Status age
 */
typedef struct I021_295_EXT1 {
    uint8_t AOS;
} I021_295_EXT1;

/**
 * @typedef I021_295_EXT2
 * @brief Category 021 Item 295 Subfield #2 - Target Report Descriptor age
 */
typedef struct I021_295_EXT2 {
    uint8_t TRD;
} I021_295_EXT2;

/**
 * @typedef I021_295_EXT3
 * @brief Category 021 Item 295 Subfield #3 - Mode 3/A Code age
 */
typedef struct I021_295_EXT3 {
    uint8_t M3A;
} I021_295_EXT3;

/**
 * @typedef I021_295_EXT4
 * @brief Category 021 Item 295 Subfield #4 - Quality Indicators age
 */
typedef struct I021_295_EXT4 {
    uint8_t QI;
} I021_295_EXT4;

/**
 * @typedef I021_295_EXT5
 * @brief Category 021 Item 295 Subfield #5 - Trajectory Intent age
 */
typedef struct I021_295_EXT5 {
    uint8_t TI;
} I021_295_EXT5;

/**
 * @typedef I021_295_EXT6
 * @brief Category 021 Item 295 Subfield #6 - Message Amplitude age
 */
typedef struct I021_295_EXT6 {
    uint8_t MAM;
} I021_295_EXT6;

/**
 * @typedef I021_295_EXT7
 * @brief Category 021 Item 295 Subfield #7 - Geometric Height age
 */
typedef struct I021_295_EXT7 {
    uint8_t GH;
} I021_295_EXT7;

/**
 * @typedef I021_295_EXT8
 * @brief Category 021 Item 295 Subfield #8 - Flight Level age
 */
typedef struct I021_295_EXT8 {
    uint8_t FL;
} I021_295_EXT8;

/**
 * @typedef I021_295_EXT9
 * @brief Category 021 Item 295 Subfield #9 - Selected Altitude age
 */
typedef struct I021_295_EXT9 {
    uint8_t SAL;
} I021_295_EXT9;

/**
 * @typedef I021_295_EXT10
 * @brief Category 021 Item 295 Subfield #10 - Final State Selected Altitude age
 */
typedef struct I021_295_EXT10 {
    uint8_t FSA;
} I021_295_EXT10;

/**
 * @typedef I021_295_EXT11
 * @brief Category 021 Item 295 Subfield #11 - Air Speed age
 */
typedef struct I021_295_EXT11 {
    uint8_t AS;
} I021_295_EXT11;

/**
 * @typedef I021_295_EXT12
 * @brief Category 021 Item 295 Subfield #12 - True Air Speed age
 */
typedef struct I021_295_EXT12 {
    uint8_t TAS;
} I021_295_EXT12;

/**
 * @typedef I021_295_EXT13
 * @brief Category 021 Item 295 Subfield #13 - Magnetic Heading age
 */
typedef struct I021_295_EXT13 {
    uint8_t MH;
} I021_295_EXT13;

/**
 * @typedef I021_295_EXT14
 * @brief Category 021 Item 295 Subfield #14 - Barometric Vertical Rate age
 */
typedef struct I021_295_EXT14 {
    uint8_t BVR;
} I021_295_EXT14;

/**
 * @typedef I021_295_EXT15
 * @brief Category 021 Item 295 Subfield #15 - Geometric Vertical Rate age
 */
typedef struct I021_295_EXT15 {
    uint8_t GVR;
} I021_295_EXT15;

/**
 * @typedef I021_295_EXT16
 * @brief Category 021 Item 295 Subfield #16 - Ground Vector age
 */
typedef struct I021_295_EXT16 {
    uint8_t GV;
} I021_295_EXT16;

/**
 * @typedef I021_295_EXT17
 * @brief Category 021 Item 295 Subfield #17 - Track Angle Rate age
 */
typedef struct I021_295_EXT17 {
    uint8_t TAR;
} I021_295_EXT17;

/**
 * @typedef I021_295_EXT18
 * @brief Category 021 Item 295 Subfield #18 - Target Identification age
 */
typedef struct I021_295_EXT18 {
    uint8_t TID;
} I021_295_EXT18;

/**
 * @typedef I021_295_EXT19
 * @brief Category 021 Item 295 Subfield #19 - Target Status age
 */
typedef struct I021_295_EXT19 {
    uint8_t TS;
} I021_295_EXT19;

/**
 * @typedef I021_295_EXT20
 * @brief Category 021 Item 295 Subfield #20 - Met Information age
 */
typedef struct I021_295_EXT20 {
    uint8_t MET;
} I021_295_EXT20;

/**
 * @typedef I021_295_EXT21
 * @brief Category 021 Item 295 Subfield #21 - Roll Angle age
 */
typedef struct I021_295_EXT21 {
    uint8_t ROA;
} I021_295_EXT21;

/**
 * @typedef I021_295_EXT22
 * @brief Category 021 Item 295 Subfield #22 - ACAS Resolution Advisory age
 */
typedef struct I021_295_EXT22 {
    uint8_t ARA;
} I021_295_EXT22;

/**
 * @typedef I021_295_EXT23
 * @brief Category 021 Item 295 Subfield #23 - Surface Capabilities and Characteristics age
 */
typedef struct I021_295_EXT23 {
    uint8_t SCC;
} I021_295_EXT23;


/**
 * @typedef I021_295
 * @brief Category 021 Item 295 - Data Ages
 * 
 * Ages of the data provided
 */
typedef struct I021_295 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[I021_295_N_OCTETS];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Presence of Aircraft Operational Status age Subfield #1
            uint8_t AOS         :1;
            /// @brief Presence of Target Report Descriptor age Subfield #2
            uint8_t TRD         :1;
            /// @brief Presence of Mode 3/A Code age Subfield #3
            uint8_t M3A         :1;
            /// @brief Presence of Quality Indicators age Subfield #4
            uint8_t QI          :1;
            /// @brief Presence of Trajectory Intent age Subfield #5
            uint8_t TI          :1;
            /// @brief Presence of Message Amplitude age Subfield #6
            uint8_t MAM         :1;
            /// @brief Presence of Geometric Height age Subfield #7
            uint8_t GH          :1;
            /// @brief Extension indicator
            uint8_t FX1         :1;

            /// @brief Presence of Flight Level age Subfield #8
            uint8_t FL          :1;
            /// @brief Presence of Selected Altitude age Subfield #9
            uint8_t SAL         :1;
            /// @brief Presence of Final State Selected Altitude age Subfield #10
            uint8_t FSA         :1;
            /// @brief Presence of Air Speed age Subfield #11
            uint8_t AS          :1;
            /// @brief Presence of True Air Speed age Subfield #12
            uint8_t TAS         :1;
            /// @brief Presence of Magnetic Heading age Subfield #13
            uint8_t MH          :1;
            /// @brief Presence of Barometric Vertical Rate age Subfield #14
            uint8_t BVR         :1;
            /// @brief Extension indicator
            uint8_t FX2         :1;

            /// @brief Presence of Geometric Vertical Rate age Subfield #15
            uint8_t GVR         :1;
            /// @brief Presence of Ground Vector age Subfield #16
            uint8_t GV          :1;
            /// @brief Presence of Track Angle Rate age Subfield #17
            uint8_t TAR         :1;
            /// @brief Presence of Target Identification age Subfield #18
            uint8_t TID         :1;
            /// @brief Presence of Target Status age Subfield #19
            uint8_t TS          :1;
            /// @brief Presence of Met Information age Subfield #20
            uint8_t MET         :1;
            /// @brief Presence of Roll Angle age Subfield #21
            uint8_t ROA         :1;
            /// @brief Extension indicator
            uint8_t FX3         :1;

            /// @brief Presence of ACAS Resolution Advisory age Subfield #22
            uint8_t ARA         :1;
            /// @brief Presence of Surface Capabilities and Characteristics age Subfield #23
            uint8_t SCC         :1;
            /// @brief Spare bits-6/2 set to 0
            uint8_t spare       :5;
            /// @brief Extension indicator
            uint8_t FX4         :1;
        };
    };
    /// @brief Subfield #1 - Aircraft Operational Status age
    I021_295_EXT1 ext1;
    /// @brief Subfield #2 - Target Report Descriptor age
    I021_295_EXT2 ext2;
    /// @brief Subfield #3 - Mode 3/A Code age
    I021_295_EXT3 ext3;
    /// @brief Subfield #4 - Quality Indicators age
    I021_295_EXT4 ext4;
    /// @brief Subfield #5 - Trajectory Intent age
    I021_295_EXT5 ext5;
    /// @brief Subfield #6 - Message Amplitude age
    I021_295_EXT6 ext6;
    /// @brief Subfield #7 - Geometric Height age
    I021_295_EXT7 ext7;
    /// @brief Subfield #8 - Flight Level age
    I021_295_EXT8 ext8;
    /// @brief Subfield #9 - Selected Altitude age
    I021_295_EXT9 ext9;
    /// @brief Subfield #10 - Final State Selected Altitude age
    I021_295_EXT10 ext10;
    /// @brief Subfield #11 - Air Speed age
    I021_295_EXT11 ext11;
    /// @brief Subfield #12 - True Air Speed age
    I021_295_EXT12 ext12;
    /// @brief Subfield #13 - Magnetic Heading age
    I021_295_EXT13 ext13;
    /// @brief Subfield #14 - Barometric Vertical Rate age
    I021_295_EXT14 ext14;
    /// @brief Subfield #15 - Geometric Vertical Rate age
    I021_295_EXT15 ext15;
    /// @brief Subfield #16 - Ground Vector age
    I021_295_EXT16 ext16;
    /// @brief Subfield #17 - Track Angle Rate age
    I021_295_EXT17 ext17;
    /// @brief Subfield #18 - Target Identification age
    I021_295_EXT18 ext18;
    /// @brief Subfield #19 - Target Status age
    I021_295_EXT19 ext19;
    /// @brief Subfield #20 - Met Information age
    I021_295_EXT20 ext20;
    /// @brief Subfield #21 - Roll Angle age
    I021_295_EXT21 ext21;
    /// @brief Subfield #22 - ACAS Resolution Advisory age
    I021_295_EXT22 ext22;
    /// @brief Subfield #23 - Surface Capabilities and Characteristics age
    I021_295_EXT23 ext23;
} I021_295;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

/**
 * @brief Get the presence of Aircraft Operational Status age (AOS) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of AOS subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_AOS(const I021_295 * item);

/**
 * @brief Get the presence of Target Report Descriptor age (TRD) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of TRD subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_TRD(const I021_295 * item);

/**
 * @brief Get the presence of Mode 3/A Code age (M3A) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of M3A subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_M3A(const I021_295 * item);

/**
 * @brief Get the presence of Quality Indicators age (QI) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of QI subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_QI(const I021_295 * item);

/**
 * @brief Get the presence of Trajectory Intent age (TI) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of TI subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_TI(const I021_295 * item);

/**
 * @brief Get the presence of Message Amplitude age (MAM) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of MAM subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_MAM(const I021_295 * item);

/**
 * @brief Get the presence of Geometric Height age (GH) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of GH subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_GH(const I021_295 * item);

/**
 * @brief  Get the Field Extension (FX1) value from I021/295
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of FX1 subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_FX1(const I021_295 * item);


/**
 * @brief Get the presence of Flight Level age (FL) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of FL subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_FL(const I021_295 * item);

/**
 * @brief Get the presence of Selected Altitude age (SAL) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of SAL subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_SAL(const I021_295 * item);

/**
 * @brief Get the presence of Final State Selected Altitude age (FSA) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of FSA subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_FSA(const I021_295 * item);

/**
 * @brief Get the presence of Air Speed age (AS) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of AS subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_AS(const I021_295 * item);

/**
 * @brief Get the presence of True Air Speed age (TAS) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of TAS subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_TAS(const I021_295 * item);

/**
 * @brief Get the presence of Magnetic Heading age (MH) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of MH subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_MH(const I021_295 * item);

/**
 * @brief Get the presence of Barometric Vertical Rate age (BVR) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of BVR subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_BVR(const I021_295 * item);

/**
 * @brief  Get the Field Extension (FX2) value from I021/295
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of FX2 subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_FX2(const I021_295 * item);


/**
 * @brief Get the presence of Geometric Vertical Rate age (GVR) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of GVR subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_GVR(const I021_295 * item);

/**
 * @brief Get the presence of Ground Vector age (GV) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of GV subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_GV(const I021_295 * item);

/**
 * @brief Get the presence of Track Angle Rate age (TAR) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of TAR subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_TAR(const I021_295 * item);

/**
 * @brief Get the presence of Target Identification age (TID) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of TID subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_TID(const I021_295 * item);

/**
 * @brief Get the presence of Target Status age (TS) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of TS subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_TS(const I021_295 * item);

/**
 * @brief Get the presence of Met Information age (MET) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of MET subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_MET(const I021_295 * item);

/**
 * @brief Get the presence of Roll Angle age (ROA) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of ROA subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_ROA(const I021_295 * item);

/**
 * @brief  Get the Field Extension (FX3) value from I021/295
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of FX3 subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_FX3(const I021_295 * item);


/**
 * @brief Get the presence of ACAS Resolution Advisory age (ARA) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of ARA subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_ARA(const I021_295 * item);

/**
 * @brief Get the presence of Surface Capabilities and Characteristics age (SCC) Subfield from Cat 021
 *        Item 195
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of SCC subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_SCC(const I021_295 * item);

/**
 * @brief  Get the Field Extension (FX4) value from I021/295
 * 
 * @param item pointer to I021_295 structure
 * 
 * @return uint8_t presence of FX4 subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_I021_295_FX4(const I021_295 * item);

/* =============================== SUBFIELD 1 =============================== */

/**
 * @brief Get the age of Aircraft Operational Status (AOS) in seconds
 *        from I021/295 Subfield #1
 * 
 * @param item pointer to I021_295_EXT1 structure
 * 
 * @return double age of AOS in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT1_AOS(const I021_295_EXT1 * item);

/* =============================== SUBFIELD 2 =============================== */

/**
 * @brief Get the age of Target Report Descriptor (TRD) in seconds
 *        from I021/295 Subfield #2
 * 
 * @param item pointer to I021_295_EXT2 structure
 * 
 * @return double age of TRD in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT2_TRD(const I021_295_EXT2 * item);

/* =============================== SUBFIELD 3 =============================== */

/**
 * @brief Get the age of Mode 3/A Code (M3A) in seconds
 *        from I021/295 Subfield #3
 * 
 * @param item pointer to I021_295_EXT3 structure
 * 
 * @return double age of M3A in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT3_M3A(const I021_295_EXT3 * item);

/* =============================== SUBFIELD 4 =============================== */

/**
 * @brief Get the age of Quality Indicators (QI) in seconds
 *        from I021/295 Subfield #4
 * 
 * @param item pointer to I021_295_EXT4 structure
 * 
 * @return double age of QI in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT4_QI(const I021_295_EXT4 * item);

/* =============================== SUBFIELD 5 =============================== */

/**
 * @brief Get the age of Trajectory Intent (TI) in seconds
 *        from I021/295 Subfield #5
 * 
 * @param item pointer to I021_295_EXT5 structure
 * 
 * @return double age of TI in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT5_TI(const I021_295_EXT5 * item);

/* =============================== SUBFIELD 6 =============================== */

/**
 * @brief Get the age of Message Amplitude (MAM) in seconds
 *        from I021/295 Subfield #6
 * 
 * @param item pointer to I021_295_EXT6 structure
 * 
 * @return double age of MAM in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT6_MAM(const I021_295_EXT6 * item);

/* =============================== SUBFIELD 7 =============================== */

/**
 * @brief Get the age of Geometric Height (GH) in seconds
 *        from I021/295 Subfield #7
 * 
 * @param item pointer to I021_295_EXT7 structure
 * 
 * @return double age of GH in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT7_GH(const I021_295_EXT7 * item);

/* =============================== SUBFIELD 8 =============================== */

/**
 * @brief Get the age of Flight Level (FL) in seconds
 *        from I021/295 Subfield #8
 * 
 * @param item pointer to I021_295_EXT8 structure
 * 
 * @return double age of FL in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT8_FL(const I021_295_EXT8 * item);

/* =============================== SUBFIELD 9 =============================== */

/**
 * @brief Get the age of Selected Altitude (SAL) in seconds
 *        from I021/295 Subfield #9
 * 
 * @param item pointer to I021_295_EXT9 structure
 * 
 * @return double age of SAL in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT9_SAL(const I021_295_EXT9 * item);

/* =============================== SUBFIELD 10 ============================== */

/**
 * @brief Get the age of Final State Selected Altitude (FSA) in seconds
 *        from I021/295 Subfield #10
 * 
 * @param item pointer to I021_295_EXT10 structure
 * 
 * @return double age of FSA in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT10_FSA(const I021_295_EXT10 * item);

/* =============================== SUBFIELD 11 ============================== */

/**
 * @brief Get the age of Air Speed (AS) in seconds
 *        from I021/295 Subfield #11
 * 
 * @param item pointer to I021_295_EXT11 structure
 * 
 * @return double age of AS in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT11_AS(const I021_295_EXT11 * item);

/* =============================== SUBFIELD 12 ============================== */

/**
 * @brief Get the age of True Air Speed (TAS) in seconds
 *        from I021/295 Subfield #12
 * 
 * @param item pointer to I021_295_EXT12 structure
 * 
 * @return double age of TAS in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT12_TAS(const I021_295_EXT12 * item);

/* =============================== SUBFIELD 13 ============================== */

/**
 * @brief Get the age of Magnetic Heading (MH) in seconds
 *        from I021/295 Subfield #13
 * 
 * @param item pointer to I021_295_EXT13 structure
 * 
 * @return double age of MH in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT13_MH(const I021_295_EXT13 * item);

/* =============================== SUBFIELD 14 ============================== */

/**
 * @brief Get the age of Barometric Vertical Rate (BVR) in seconds
 *        from I021/295 Subfield #14
 * 
 * @param item pointer to I021_295_EXT14 structure
 * 
 * @return double age of BVR in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT14_BVR(const I021_295_EXT14 * item);

/* =============================== SUBFIELD 15 ============================== */

/**
 * @brief Get the age of Geometric Vertical Rate (GVR) in seconds
 *        from I021/295 Subfield #15
 * 
 * @param item pointer to I021_295_EXT15 structure
 * 
 * @return double age of GVR in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT15_GVR(const I021_295_EXT15 * item);

/* =============================== SUBFIELD 16 ============================== */

/**
 * @brief Get the age of Ground Vector (GV) in seconds
 *        from I021/295 Subfield #16
 * 
 * @param item pointer to I021_295_EXT16 structure
 * 
 * @return double age of GV in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT16_GV(const I021_295_EXT16 * item);

/* =============================== SUBFIELD 17 ============================== */

/**
 * @brief Get the age of Track Angle Rate (TAR) in seconds
 *        from I021/295 Subfield #17
 * 
 * @param item pointer to I021_295_EXT17 structure
 * 
 * @return double age of TAR in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT17_TAR(const I021_295_EXT17 * item);

/* =============================== SUBFIELD 18 ============================== */

/**
 * @brief Get the age of Target Identification (TID) in seconds
 *        from I021/295 Subfield #18
 * 
 * @param item pointer to I021_295_EXT18 structure
 * 
 * @return double age of TID in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT18_TID(const I021_295_EXT18 * item);

/* =============================== SUBFIELD 19 ============================== */

/**
 * @brief Get the age of Target Status (TS) in seconds
 *        from I021/295 Subfield #19
 * 
 * @param item pointer to I021_295_EXT19 structure
 * 
 * @return double age of TS in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT19_TS(const I021_295_EXT19 * item);

/* =============================== SUBFIELD 20 ============================== */

/**
 * @brief Get the age of Met Information (MET) in seconds
 *        from I021/295 Subfield #20
 * 
 * @param item pointer to I021_295_EXT20 structure
 * 
 * @return double age of MET in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT20_MET(const I021_295_EXT20 * item);

/* =============================== SUBFIELD 21 ============================== */

/**
 * @brief Get the age of Roll Angle (ROA) in seconds
 *        from I021/295 Subfield #21
 * 
 * @param item pointer to I021_295_EXT21 structure
 * 
 * @return double age of ROA in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT21_ROA(const I021_295_EXT21 * item);

/* =============================== SUBFIELD 22 ============================== */

/**
 * @brief Get the age of ACAS Resolution Advisory (ARA) in seconds
 *        from I021/295 Subfield #22
 * 
 * @param item pointer to I021_295_EXT22 structure
 * 
 * @return double age of ARA in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT22_ARA(const I021_295_EXT22 * item);

/* =============================== SUBFIELD 23 ============================== */

/**
 * @brief Get the age of Surface Capabilities and Characteristics (SCC) in seconds
 *        from I021/295 Subfield #23
 * 
 * @param item pointer to I021_295_EXT23 structure
 * 
 * @return double age of SCC in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_I021_295_EXT23_SCC(const I021_295_EXT23 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_AOS(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_TRD(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_M3A(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_QI(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_TI(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_MAM(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_GH(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_FX1(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_FL(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_SAL(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_FSA(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_AS(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_TAS(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_MH(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_BVR(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_FX2(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_GVR(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_GV(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_TAR(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_TID(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_TS(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_MET(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_ROA(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_FX3(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_ARA(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_SCC(I021_295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to I021_295 structure
 * @param value
 */
ASTERIX_API void set_I021_295_FX4(I021_295 * item, const uint8_t value);

/* =============================== SUBFIELD 2 =============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT2 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT2_TRD(I021_295_EXT2 * item, const double value);

/* =============================== SUBFIELD 3 =============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT3 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT3_M3A(I021_295_EXT3 * item, const double value);

/* =============================== SUBFIELD 4 =============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT4 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT4_QI(I021_295_EXT4 * item, const double value);

/* =============================== SUBFIELD 5 =============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT5 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT5_TI(I021_295_EXT5 * item, const double value);

/* =============================== SUBFIELD 6 =============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT6 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT6_MAM(I021_295_EXT6 * item, const double value);

/* =============================== SUBFIELD 7 =============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT7 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT7_GH(I021_295_EXT7 * item, const double value);

/* =============================== SUBFIELD 8 =============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT8 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT8_FL(I021_295_EXT8 * item, const double value);

/* =============================== SUBFIELD 9 =============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT9 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT9_SAL(I021_295_EXT9 * item, const double value);

/* =============================== SUBFIELD 10 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT10 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT10_FSA(I021_295_EXT10 * item, const double value);

/* =============================== SUBFIELD 11 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT11 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT11_AS(I021_295_EXT11 * item, const double value);

/* =============================== SUBFIELD 12 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT12 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT12_TAS(I021_295_EXT12 * item, const double value);

/* =============================== SUBFIELD 13 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT13 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT13_MH(I021_295_EXT13 * item, const double value);

/* =============================== SUBFIELD 14 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT14 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT14_BVR(I021_295_EXT14 * item, const double value);

/* =============================== SUBFIELD 15 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT15 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT15_GVR(I021_295_EXT15 * item, const double value);

/* =============================== SUBFIELD 16 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT16 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT16_GV(I021_295_EXT16 * item, const double value);

/* =============================== SUBFIELD 17 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT17 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT17_TAR(I021_295_EXT17 * item, const double value);

/* =============================== SUBFIELD 18 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT18 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT18_TID(I021_295_EXT18 * item, const double value);

/* =============================== SUBFIELD 19 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT19 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT19_TS(I021_295_EXT19 * item, const double value);

/* =============================== SUBFIELD 20 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT20 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT20_MET(I021_295_EXT20 * item, const double value);

/* =============================== SUBFIELD 21 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT21 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT21_ROA(I021_295_EXT21 * item, const double value);

/* =============================== SUBFIELD 22 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT22 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT22_ARA(I021_295_EXT22 * item, const double value);

/* =============================== SUBFIELD 23 ============================== */

/**
 * @brief
 * 
 * @param item pointer to I021_295_EXT23 structure
 * @param value
 */
ASTERIX_API void set_I021_295_EXT23_SCC(I021_295_EXT23 * item, const double value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the contents of I021/295 and its extension if present
 * 
 * @param item pointer to I021_295 structure
 */
ASTERIX_API void print_I021_295(const I021_295 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_295_H */