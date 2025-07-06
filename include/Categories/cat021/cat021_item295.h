/**
 * @file cat021_item295.h
 * @brief Definition of CAT 021 Item 295, and related functions and values
 */

#ifndef CAT021_ITEM295_H
#define CAT021_ITEM295_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define CAT021_ITEM295_N_OCTETS     8   /// Number of octets of Primary Subfield

#define CAT021_ITEM295_LSB_EXT1_AOS       (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT2_TRD       (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT3_M3A       (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT4_QI        (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT5_TI        (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT6_MAM       (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT7_GH        (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT8_FL        (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT9_SAL       (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT10_FSA      (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT11_AS       (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT12_TAS      (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT13_MH       (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT14_BVR      (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT15_GVR      (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT16_GV       (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT17_TAR      (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT18_TID      (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT19_TS       (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT20_MET      (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT21_ROA      (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT22_ARA      (0.1)   /// LSB = 0.1 seconds
#define CAT021_ITEM295_LSB_EXT23_SCC      (0.1)   /// LSB = 0.1 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item295_ext1
 * @brief Category 021 Item 295 Subfield #1 - Aircraft Operational Status age
 */
typedef struct cat021_item295_ext1 {
    uint8_t AOS;
} cat021_item295_ext1;

/**
 * @typedef cat021_item295_ext2
 * @brief Category 021 Item 295 Subfield #2 - Target Report Descriptor age
 */
typedef struct cat021_item295_ext2 {
    uint8_t TRD;
} cat021_item295_ext2;

/**
 * @typedef cat021_item295_ext3
 * @brief Category 021 Item 295 Subfield #3 - Mode 3/A Code age
 */
typedef struct cat021_item295_ext3 {
    uint8_t M3A;
} cat021_item295_ext3;

/**
 * @typedef cat021_item295_ext4
 * @brief Category 021 Item 295 Subfield #4 - Quality Indicators age
 */
typedef struct cat021_item295_ext4 {
    uint8_t QI;
} cat021_item295_ext4;

/**
 * @typedef cat021_item295_ext5
 * @brief Category 021 Item 295 Subfield #5 - Trajectory Intent age
 */
typedef struct cat021_item295_ext5 {
    uint8_t TI;
} cat021_item295_ext5;

/**
 * @typedef cat021_item295_ext6
 * @brief Category 021 Item 295 Subfield #6 - Message Amplitude age
 */
typedef struct cat021_item295_ext6 {
    uint8_t MAM;
} cat021_item295_ext6;

/**
 * @typedef cat021_item295_ext7
 * @brief Category 021 Item 295 Subfield #7 - Geometric Height age
 */
typedef struct cat021_item295_ext7 {
    uint8_t GH;
} cat021_item295_ext7;

/**
 * @typedef cat021_item295_ext8
 * @brief Category 021 Item 295 Subfield #8 - Flight Level age
 */
typedef struct cat021_item295_ext8 {
    uint8_t FL;
} cat021_item295_ext8;

/**
 * @typedef cat021_item295_ext9
 * @brief Category 021 Item 295 Subfield #9 - Selected Altitude age
 */
typedef struct cat021_item295_ext9 {
    uint8_t SAL;
} cat021_item295_ext9;

/**
 * @typedef cat021_item295_ext10
 * @brief Category 021 Item 295 Subfield #10 - Final State Selected Altitude age
 */
typedef struct cat021_item295_ext10 {
    uint8_t FSA;
} cat021_item295_ext10;

/**
 * @typedef cat021_item295_ext11
 * @brief Category 021 Item 295 Subfield #11 - Air Speed age
 */
typedef struct cat021_item295_ext11 {
    uint8_t AS;
} cat021_item295_ext11;

/**
 * @typedef cat021_item295_ext12
 * @brief Category 021 Item 295 Subfield #12 - True Air Speed age
 */
typedef struct cat021_item295_ext12 {
    uint8_t TAS;
} cat021_item295_ext12;

/**
 * @typedef cat021_item295_ext13
 * @brief Category 021 Item 295 Subfield #13 - Magnetic Heading age
 */
typedef struct cat021_item295_ext13 {
    uint8_t MH;
} cat021_item295_ext13;

/**
 * @typedef cat021_item295_ext14
 * @brief Category 021 Item 295 Subfield #14 - Barometric Vertical Rate age
 */
typedef struct cat021_item295_ext14 {
    uint8_t BVR;
} cat021_item295_ext14;

/**
 * @typedef cat021_item295_ext15
 * @brief Category 021 Item 295 Subfield #15 - Geometric Vertical Rate age
 */
typedef struct cat021_item295_ext15 {
    uint8_t GVR;
} cat021_item295_ext15;

/**
 * @typedef cat021_item295_ext16
 * @brief Category 021 Item 295 Subfield #16 - Ground Vector age
 */
typedef struct cat021_item295_ext16 {
    uint8_t GV;
} cat021_item295_ext16;

/**
 * @typedef cat021_item295_ext17
 * @brief Category 021 Item 295 Subfield #17 - Track Angle Rate age
 */
typedef struct cat021_item295_ext17 {
    uint8_t TAR;
} cat021_item295_ext17;

/**
 * @typedef cat021_item295_ext18
 * @brief Category 021 Item 295 Subfield #18 - Target Identification age
 */
typedef struct cat021_item295_ext18 {
    uint8_t TID;
} cat021_item295_ext18;

/**
 * @typedef cat021_item295_ext19
 * @brief Category 021 Item 295 Subfield #19 - Target Status age
 */
typedef struct cat021_item295_ext19 {
    uint8_t TS;
} cat021_item295_ext19;

/**
 * @typedef cat021_item295_ext20
 * @brief Category 021 Item 295 Subfield #20 - Met Information age
 */
typedef struct cat021_item295_ext20 {
    uint8_t MET;
} cat021_item295_ext20;

/**
 * @typedef cat021_item295_ext21
 * @brief Category 021 Item 295 Subfield #21 - Roll Angle age
 */
typedef struct cat021_item295_ext21 {
    uint8_t ROA;
} cat021_item295_ext21;

/**
 * @typedef cat021_item295_ext22
 * @brief Category 021 Item 295 Subfield #22 - ACAS Resolution Advisory age
 */
typedef struct cat021_item295_ext22 {
    uint8_t ARA;
} cat021_item295_ext22;

/**
 * @typedef cat021_item295_ext23
 * @brief Category 021 Item 295 Subfield #23 - Surface Capabilities and Characteristics age
 */
typedef struct cat021_item295_ext23 {
    uint8_t SCC;
} cat021_item295_ext23;


/**
 * @typedef cat021_item295
 * @brief Category 021 Item 295 - Data Ages
 * 
 * Ages of the data provided
 */
typedef struct cat021_item295 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[CAT021_ITEM295_N_OCTETS];

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
    cat021_item295_ext1 ext1;
    /// @brief Subfield #2 - Target Report Descriptor age
    cat021_item295_ext2 ext2;
    /// @brief Subfield #3 - Mode 3/A Code age
    cat021_item295_ext3 ext3;
    /// @brief Subfield #4 - Quality Indicators age
    cat021_item295_ext4 ext4;
    /// @brief Subfield #5 - Trajectory Intent age
    cat021_item295_ext5 ext5;
    /// @brief Subfield #6 - Message Amplitude age
    cat021_item295_ext6 ext6;
    /// @brief Subfield #7 - Geometric Height age
    cat021_item295_ext7 ext7;
    /// @brief Subfield #8 - Flight Level age
    cat021_item295_ext8 ext8;
    /// @brief Subfield #9 - Selected Altitude age
    cat021_item295_ext9 ext9;
    /// @brief Subfield #10 - Final State Selected Altitude age
    cat021_item295_ext10 ext10;
    /// @brief Subfield #11 - Air Speed age
    cat021_item295_ext11 ext11;
    /// @brief Subfield #12 - True Air Speed age
    cat021_item295_ext12 ext12;
    /// @brief Subfield #13 - Magnetic Heading age
    cat021_item295_ext13 ext13;
    /// @brief Subfield #14 - Barometric Vertical Rate age
    cat021_item295_ext14 ext14;
    /// @brief Subfield #15 - Geometric Vertical Rate age
    cat021_item295_ext15 ext15;
    /// @brief Subfield #16 - Ground Vector age
    cat021_item295_ext16 ext16;
    /// @brief Subfield #17 - Track Angle Rate age
    cat021_item295_ext17 ext17;
    /// @brief Subfield #18 - Target Identification age
    cat021_item295_ext18 ext18;
    /// @brief Subfield #19 - Target Status age
    cat021_item295_ext19 ext19;
    /// @brief Subfield #20 - Met Information age
    cat021_item295_ext20 ext20;
    /// @brief Subfield #21 - Roll Angle age
    cat021_item295_ext21 ext21;
    /// @brief Subfield #22 - ACAS Resolution Advisory age
    cat021_item295_ext22 ext22;
    /// @brief Subfield #23 - Surface Capabilities and Characteristics age
    cat021_item295_ext23 ext23;
} cat021_item295;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

/**
 * @brief Get the presence of Aircraft Operational Status age (AOS) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of AOS subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_AOS(const cat021_item295 * item);

/**
 * @brief Get the presence of Target Report Descriptor age (TRD) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of TRD subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_TRD(const cat021_item295 * item);

/**
 * @brief Get the presence of Mode 3/A Code age (M3A) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of M3A subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_M3A(const cat021_item295 * item);

/**
 * @brief Get the presence of Quality Indicators age (QI) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of QI subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_QI(const cat021_item295 * item);

/**
 * @brief Get the presence of Trajectory Intent age (TI) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of TI subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_TI(const cat021_item295 * item);

/**
 * @brief Get the presence of Message Amplitude age (MAM) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of MAM subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_MAM(const cat021_item295 * item);

/**
 * @brief Get the presence of Geometric Height age (GH) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of GH subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_GH(const cat021_item295 * item);

/**
 * @brief  Get the Field Extension (FX1) value from Cat 021 Item 295
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of FX1 subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_FX1(const cat021_item295 * item);


/**
 * @brief Get the presence of Flight Level age (FL) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of FL subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_FL(const cat021_item295 * item);

/**
 * @brief Get the presence of Selected Altitude age (SAL) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of SAL subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_SAL(const cat021_item295 * item);

/**
 * @brief Get the presence of Final State Selected Altitude age (FSA) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of FSA subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_FSA(const cat021_item295 * item);

/**
 * @brief Get the presence of Air Speed age (AS) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of AS subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_AS(const cat021_item295 * item);

/**
 * @brief Get the presence of True Air Speed age (TAS) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of TAS subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_TAS(const cat021_item295 * item);

/**
 * @brief Get the presence of Magnetic Heading age (MH) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of MH subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_MH(const cat021_item295 * item);

/**
 * @brief Get the presence of Barometric Vertical Rate age (BVR) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of BVR subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_BVR(const cat021_item295 * item);

/**
 * @brief  Get the Field Extension (FX2) value from Cat 021 Item 295
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of FX2 subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_FX2(const cat021_item295 * item);


/**
 * @brief Get the presence of Geometric Vertical Rate age (GVR) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of GVR subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_GVR(const cat021_item295 * item);

/**
 * @brief Get the presence of Ground Vector age (GV) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of GV subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_GV(const cat021_item295 * item);

/**
 * @brief Get the presence of Track Angle Rate age (TAR) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of TAR subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_TAR(const cat021_item295 * item);

/**
 * @brief Get the presence of Target Identification age (TID) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of TID subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_TID(const cat021_item295 * item);

/**
 * @brief Get the presence of Target Status age (TS) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of TS subfield (0: subfield absence;
 *                                          1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_TS(const cat021_item295 * item);

/**
 * @brief Get the presence of Met Information age (MET) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of MET subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_MET(const cat021_item295 * item);

/**
 * @brief Get the presence of Roll Angle age (ROA) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of ROA subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_ROA(const cat021_item295 * item);

/**
 * @brief  Get the Field Extension (FX3) value from Cat 021 Item 295
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of FX3 subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_FX3(const cat021_item295 * item);


/**
 * @brief Get the presence of ACAS Resolution Advisory age (ARA) Subfield from Cat 021
 *        Item 195 
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of ARA subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_ARA(const cat021_item295 * item);

/**
 * @brief Get the presence of Surface Capabilities and Characteristics age (SCC) Subfield from Cat 021
 *        Item 195
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of SCC subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_SCC(const cat021_item295 * item);

/**
 * @brief  Get the Field Extension (FX4) value from Cat 021 Item 295
 * 
 * @param item pointer to cat021_item295 structure
 * 
 * @return uint8_t presence of FX4 subfield (0: subfield absence;
 *                                           1: subfield present)
 */
ASTERIX_API uint8_t get_cat021_item295_FX4(const cat021_item295 * item);

/* =============================== SUBFIELD 1 =============================== */

/**
 * @brief Get the age of Aircraft Operational Status (AOS) in seconds
 *        from Cat 021 Item 295 Subfield #1
 * 
 * @param item pointer to cat021_item295_ext1 structure
 * 
 * @return double age of AOS in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext1_AOS(const cat021_item295_ext1 * item);

/* =============================== SUBFIELD 2 =============================== */

/**
 * @brief Get the age of Target Report Descriptor (TRD) in seconds
 *        from Cat 021 Item 295 Subfield #2
 * 
 * @param item pointer to cat021_item295_ext2 structure
 * 
 * @return double age of TRD in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext2_TRD(const cat021_item295_ext2 * item);

/* =============================== SUBFIELD 3 =============================== */

/**
 * @brief Get the age of Mode 3/A Code (M3A) in seconds
 *        from Cat 021 Item 295 Subfield #3
 * 
 * @param item pointer to cat021_item295_ext3 structure
 * 
 * @return double age of M3A in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext3_M3A(const cat021_item295_ext3 * item);

/* =============================== SUBFIELD 4 =============================== */

/**
 * @brief Get the age of Quality Indicators (QI) in seconds
 *        from Cat 021 Item 295 Subfield #4
 * 
 * @param item pointer to cat021_item295_ext4 structure
 * 
 * @return double age of QI in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext4_QI(const cat021_item295_ext4 * item);

/* =============================== SUBFIELD 5 =============================== */

/**
 * @brief Get the age of Trajectory Intent (TI) in seconds
 *        from Cat 021 Item 295 Subfield #5
 * 
 * @param item pointer to cat021_item295_ext5 structure
 * 
 * @return double age of TI in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext5_TI(const cat021_item295_ext5 * item);

/* =============================== SUBFIELD 6 =============================== */

/**
 * @brief Get the age of Message Amplitude (MAM) in seconds
 *        from Cat 021 Item 295 Subfield #6
 * 
 * @param item pointer to cat021_item295_ext6 structure
 * 
 * @return double age of MAM in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext6_MAM(const cat021_item295_ext6 * item);

/* =============================== SUBFIELD 7 =============================== */

/**
 * @brief Get the age of Geometric Height (GH) in seconds
 *        from Cat 021 Item 295 Subfield #7
 * 
 * @param item pointer to cat021_item295_ext7 structure
 * 
 * @return double age of GH in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext7_GH(const cat021_item295_ext7 * item);

/* =============================== SUBFIELD 8 =============================== */

/**
 * @brief Get the age of Flight Level (FL) in seconds
 *        from Cat 021 Item 295 Subfield #8
 * 
 * @param item pointer to cat021_item295_ext8 structure
 * 
 * @return double age of FL in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext8_FL(const cat021_item295_ext8 * item);

/* =============================== SUBFIELD 9 =============================== */

/**
 * @brief Get the age of Selected Altitude (SAL) in seconds
 *        from Cat 021 Item 295 Subfield #9
 * 
 * @param item pointer to cat021_item295_ext9 structure
 * 
 * @return double age of SAL in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext9_SAL(const cat021_item295_ext9 * item);

/* =============================== SUBFIELD 10 ============================== */

/**
 * @brief Get the age of Final State Selected Altitude (FSA) in seconds
 *        from Cat 021 Item 295 Subfield #10
 * 
 * @param item pointer to cat021_item295_ext10 structure
 * 
 * @return double age of FSA in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext10_FSA(const cat021_item295_ext10 * item);

/* =============================== SUBFIELD 11 ============================== */

/**
 * @brief Get the age of Air Speed (AS) in seconds
 *        from Cat 021 Item 295 Subfield #11
 * 
 * @param item pointer to cat021_item295_ext11 structure
 * 
 * @return double age of AS in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext11_AS(const cat021_item295_ext11 * item);

/* =============================== SUBFIELD 12 ============================== */

/**
 * @brief Get the age of True Air Speed (TAS) in seconds
 *        from Cat 021 Item 295 Subfield #12
 * 
 * @param item pointer to cat021_item295_ext12 structure
 * 
 * @return double age of TAS in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext12_TAS(const cat021_item295_ext12 * item);

/* =============================== SUBFIELD 13 ============================== */

/**
 * @brief Get the age of Magnetic Heading (MH) in seconds
 *        from Cat 021 Item 295 Subfield #13
 * 
 * @param item pointer to cat021_item295_ext13 structure
 * 
 * @return double age of MH in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext13_MH(const cat021_item295_ext13 * item);

/* =============================== SUBFIELD 14 ============================== */

/**
 * @brief Get the age of Barometric Vertical Rate (BVR) in seconds
 *        from Cat 021 Item 295 Subfield #14
 * 
 * @param item pointer to cat021_item295_ext14 structure
 * 
 * @return double age of BVR in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext14_BVR(const cat021_item295_ext14 * item);

/* =============================== SUBFIELD 15 ============================== */

/**
 * @brief Get the age of Geometric Vertical Rate (GVR) in seconds
 *        from Cat 021 Item 295 Subfield #15
 * 
 * @param item pointer to cat021_item295_ext15 structure
 * 
 * @return double age of GVR in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext15_GVR(const cat021_item295_ext15 * item);

/* =============================== SUBFIELD 16 ============================== */

/**
 * @brief Get the age of Ground Vector (GV) in seconds
 *        from Cat 021 Item 295 Subfield #16
 * 
 * @param item pointer to cat021_item295_ext16 structure
 * 
 * @return double age of GV in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext16_GV(const cat021_item295_ext16 * item);

/* =============================== SUBFIELD 17 ============================== */

/**
 * @brief Get the age of Track Angle Rate (TAR) in seconds
 *        from Cat 021 Item 295 Subfield #17
 * 
 * @param item pointer to cat021_item295_ext17 structure
 * 
 * @return double age of TAR in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext17_TAR(const cat021_item295_ext17 * item);

/* =============================== SUBFIELD 18 ============================== */

/**
 * @brief Get the age of Target Identification (TID) in seconds
 *        from Cat 021 Item 295 Subfield #18
 * 
 * @param item pointer to cat021_item295_ext18 structure
 * 
 * @return double age of TID in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext18_TID(const cat021_item295_ext18 * item);

/* =============================== SUBFIELD 19 ============================== */

/**
 * @brief Get the age of Target Status (TS) in seconds
 *        from Cat 021 Item 295 Subfield #19
 * 
 * @param item pointer to cat021_item295_ext19 structure
 * 
 * @return double age of TS in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext19_TS(const cat021_item295_ext19 * item);

/* =============================== SUBFIELD 20 ============================== */

/**
 * @brief Get the age of Met Information (MET) in seconds
 *        from Cat 021 Item 295 Subfield #20
 * 
 * @param item pointer to cat021_item295_ext20 structure
 * 
 * @return double age of MET in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext20_MET(const cat021_item295_ext20 * item);

/* =============================== SUBFIELD 21 ============================== */

/**
 * @brief Get the age of Roll Angle (ROA) in seconds
 *        from Cat 021 Item 295 Subfield #21
 * 
 * @param item pointer to cat021_item295_ext21 structure
 * 
 * @return double age of ROA in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext21_ROA(const cat021_item295_ext21 * item);

/* =============================== SUBFIELD 22 ============================== */

/**
 * @brief Get the age of ACAS Resolution Advisory (ARA) in seconds
 *        from Cat 021 Item 295 Subfield #22
 * 
 * @param item pointer to cat021_item295_ext22 structure
 * 
 * @return double age of ARA in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext22_ARA(const cat021_item295_ext22 * item);

/* =============================== SUBFIELD 23 ============================== */

/**
 * @brief Get the age of Surface Capabilities and Characteristics (SCC) in seconds
 *        from Cat 021 Item 295 Subfield #23
 * 
 * @param item pointer to cat021_item295_ext23 structure
 * 
 * @return double age of SCC in seconds (LSB = 0.1 seconds)
 */
ASTERIX_API double get_cat021_item295_ext23_SCC(const cat021_item295_ext23 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_AOS(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_TRD(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_M3A(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_QI(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_TI(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_MAM(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_GH(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_FX1(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_FL(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_SAL(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_FSA(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_AS(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_TAS(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_MH(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_BVR(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_FX2(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_GVR(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_GV(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_TAR(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_TID(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_TS(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_MET(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ROA(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_FX3(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ARA(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_SCC(cat021_item295 * item, const uint8_t value);

/**
 * @brief 
 * 
 * @param item pointer to cat021_item295 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_FX4(cat021_item295 * item, const uint8_t value);

/* =============================== SUBFIELD 2 =============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext2 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext2_TRD(cat021_item295_ext2 * item,
                                             const double value);

/* =============================== SUBFIELD 3 =============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext3 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext3_M3A(cat021_item295_ext3 * item,
                                             const double value);

/* =============================== SUBFIELD 4 =============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext4 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext4_QI(cat021_item295_ext4 * item,
                                            const double value);

/* =============================== SUBFIELD 5 =============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext5 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext5_TI(cat021_item295_ext5 * item,
                                            const double value);

/* =============================== SUBFIELD 6 =============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext6 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext6_MAM(cat021_item295_ext6 * item,
                                             const double value);

/* =============================== SUBFIELD 7 =============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext7 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext7_GH(cat021_item295_ext7 * item,
                                            const double value);

/* =============================== SUBFIELD 8 =============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext8 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext8_FL(cat021_item295_ext8 * item,
                                            const double value);

/* =============================== SUBFIELD 9 =============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext9 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext9_SAL(cat021_item295_ext9 * item,
                                             const double value);

/* =============================== SUBFIELD 10 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext10 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext10_FSA(cat021_item295_ext10 * item,
                                              const double value);

/* =============================== SUBFIELD 11 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext11 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext11_AS(cat021_item295_ext11 * item,
                                             const double value);

/* =============================== SUBFIELD 12 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext12 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext12_TAS(cat021_item295_ext12 * item,
                                              const double value);

/* =============================== SUBFIELD 13 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext13 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext13_MH(cat021_item295_ext13 * item,
                                             const double value);

/* =============================== SUBFIELD 14 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext14 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext14_BVR(cat021_item295_ext14 * item,
                                              const double value);

/* =============================== SUBFIELD 15 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext15 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext15_GVR(cat021_item295_ext15 * item,
                                              const double value);

/* =============================== SUBFIELD 16 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext16 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext16_GV(cat021_item295_ext16 * item,
                                             const double value);

/* =============================== SUBFIELD 17 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext17 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext17_TAR(cat021_item295_ext17 * item,
                                              const double value);

/* =============================== SUBFIELD 18 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext18 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext18_TID(cat021_item295_ext18 * item,
                                              const double value);

/* =============================== SUBFIELD 19 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext19 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext19_TS(cat021_item295_ext19 * item,
                                             const double value);

/* =============================== SUBFIELD 20 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext20 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext20_MET(cat021_item295_ext20 * item,
                                              const double value);

/* =============================== SUBFIELD 21 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext21 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext21_ROA(cat021_item295_ext21 * item,
                                             const double value);

/* =============================== SUBFIELD 22 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext22 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext22_ARA(cat021_item295_ext22 * item,
                                              const double value);

/* =============================== SUBFIELD 23 ============================== */

/**
 * @brief
 * 
 * @param item pointer to cat021_item295_ext23 structure
 * @param value
 */
ASTERIX_API void set_cat021_item295_ext23_SCC(cat021_item295_ext23 * item,
                                              const double value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the contents of Cat 021 Item 295 and its extension if present
 * 
 * @param item pointer to cat021_item295 structure
 */
ASTERIX_API void print_cat021_item295(const cat021_item295 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM295_H */