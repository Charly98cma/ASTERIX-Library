/**
 * @file I021_090.h
 * @brief Definition of I021/090, and related functions and values
 */

#ifndef I021_090_H
#define I021_090_H

#include <stdint.h>
#include "Common/versions.h"
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
#define I021_090_EXT5_LSB_VAL_DIST_P1       (128.0)    /* LSB = 128 meters */
#define I021_090_EXT6_LSB_VAL_DIST_P2         (1.0)    /* LSB =   1 meters */
#define I021_090_EXT7_LSB_VAL_DIST_QUAL_P1  (128.0)    /* LSB = 128 meters */
#define I021_090_EXT8_LSB_VAL_DIST_QUAL_P2    (1.0)    /* LSB =   1 meters */
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_090_EXT1
 * @brief First extension of the Category 021 / Item 090
 */
typedef struct I021_090_EXT1 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Navigation Integrity Category for Barometric Altitude
            uint8_t NICbaro    :1;
            /// @brief Surveillance (V1) or Source (V2+) Integrity Level
            uint8_t SIL         :2;
            /// @brief Navigation Accuracy Category for Position
            uint8_t NACp        :4;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX          :1;
        };
    };
} I021_090_EXT1;

/**
 * @typedef I021_090_EXT2
 * @brief Second extension of the Category 021 / Item 090
 */
typedef struct I021_090_EXT2 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bits-8/7, set to 0
            uint8_t spare   :2;
            /**
             * @brief SIL-Supplement
             * 
             * = 0: measured per flight-hour | = 1: measured per sample
            */
            uint8_t SILS    :1;
            /// @brief Horizontal Position System Design Assurance Level
            uint8_t SDA     :2;
            /// @brief Geometric Altitude Accuracy
            uint8_t GVA     :2;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX      :1;
        };
    };
} I021_090_EXT2;

/**
 * @typedef I021_090_EXT3
 * @brief Third extension of the Category 021 / Item 090
 */
typedef struct I021_090_EXT3 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** 
             *  @brief Position Integrity Category (check EUROCONTROL table for values)
             *
             *  (check EUROCONTROL conversion table for values explanation)
             */
            uint8_t PIC     :4;

#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
            /**
             * @brief Source of PIC
             * 
             * = 0 PIC mapped from FTC and NICsup
             * = 1 PIC directly received in HVA or Phase Overlay
             */
            uint8_t SRC     :1;
            /// @brief Spare bits-3/2, set to 0
            uint8_t spare   :2;
#else
            /// @brief Spare bits-4/2, set to 0
            uint8_t spare   :3;
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */

            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX      :1;
        };
    };
} I021_090_EXT3;

#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)

/**
 * @typedef I021_090_EXT4
 * @brief Category 021 / Item 090 - Fourth extension subfield (1 byte)
 * 
 * Position Validation Indicators
 */
typedef struct I021_090_EXT4 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bits-8/7 set to 0
            uint8_t spare           :2;
            /**
             * @brief Position Validation State (see Specification Standard)
             */
            uint8_t VALSTATE       :3;
            /**
             * @brief Validation Distance Availability
             * 
             * = 0 Item not available | = 1 Item available
             */
            uint8_t VD              :1;
            /**
             * @brief Validation Distance Quality Availability
             * 
             * = 0 Item not available | = 1 Item available
             */
            uint8_t VQ              :1;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX              :1;
        };
    };
} I021_090_EXT4;

/**
 * @typedef I021_090_EXT5
 * @brief Category 021 / Item 090 - Fifth extension subfield (1 byte)
 * 
 * Position Validation Distance Part 1
 */
typedef struct I021_090_EXT5 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Position Validation Distance Part 1 (steps of 128 meters)
             * 
             * LSB = 128 meters
             * 
             * Range: 0 to 16256
             */
            uint8_t VAL_DIST_P1     :7;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX              :1;
        };
    };
} I021_090_EXT5;

/**
 * @typedef I021_090_EXT6
 * @brief Category 021 / Item 090 - Sixth extension subfield (1 byte)
 * 
 * Position Validation Distance Part 2
 */
typedef struct I021_090_EXT6 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Position Validation Distance Part 2 (steps of 1 meters)
             * 
             * LSB = 1 meters
             * 
             * Range: 0 to 127
             */
            uint8_t VAL_DIST_P2     :7;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX              :1;
        };
    };
} I021_090_EXT6;

/**
 * @typedef I021_090_EXT7
 * @brief Category 021 / Item 090 - Seventh extension subfield (1 byte)
 */
typedef struct I021_090_EXT7 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Position Validation Distance Quality (steps of 128 meters)
             * 
             * LSB = 128 meters
             * 
             * Range: 0 to 16256
             */
            uint8_t VALDISTQUALP1   :7;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX              :1;
        };
    };
} I021_090_EXT7;

/**
 * @typedef I021_090_EXT8
 * @brief Category 021 / Item 090 - Eight extension subfield (1 byte)
 */
typedef struct I021_090_EXT8 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Position Validation Distance Quality (steps of 1 meters)
             * 
             * LSB = 1 meters
             * 
             * Range: 0 to 127
             */
            uint8_t VALDISTQUALP2   :7;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX              :1;
        };
    };
} I021_090_EXT8;
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */

/**
 * @typedef I021_090
 * @brief Category 021 / Item 090 - Quality Indicators
 * 
 * ADS-B quality indicators transmitted by a/c according to MOPS version.
 */
typedef struct I021_090 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Navigation Uncertainty Category for velocity (NUCr)
             * or the Navigation Accuracy Category for Velocity (NACv)
             */
            uint8_t NUCrNACv        :3;
            /**
             * @brief Navigation Uncertainty Category for Position (NUCp)
             * or Navigation Integrity Category (NIC).
             */
            uint8_t NUCp_NIC        :3;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX              :1;
        };
    };
    /// @brief First extension subfield (1 byte)
    I021_090_EXT1 ext1;
    /// @brief Second extension subfield (1 byte)
    I021_090_EXT2 ext2;
    /// @brief Third extension subfield (1 byte)
    I021_090_EXT3 ext3;
#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
    /// @brief Fourth extension subfield (1 byte)
    I021_090_EXT4 ext4;
    /// @brief Fifth extension subfield (1 byte)
    I021_090_EXT5 ext5;
    /// @brief Sixth extension subfield (1 byte)
    I021_090_EXT6 ext6;
    /// @brief Seventh extension subfield (1 byte)
    I021_090_EXT7 ext7;
    /// @brief Eight extension subfield (1 byte)
    I021_090_EXT8 ext8;
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */
} I021_090;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN  BYTE =============================== */

/**
 * @brief Get the value of NUCr or NACv from I021/090
 * 
 * Returns the Navigation Uncertainty Category for velocity (NUCr) or
 * the Navigation Accuracy Category for Velocity (NACv).
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to I021_090 structure
 * 
 * @return uint8_t Value of NUCr or NACv (see MOPS Version and conversion table)
 */
ASTERIX_API uint8_t get_I021_090_NUCr_NACv(const I021_090 * item);

/**
 * @brief Get the value of NUCp or NIC from I021/090
 * 
 * Returns the Navigation Uncertainty Category for Position (NUCp) or
 * Navigation Integrity Category (NIC).
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to I021_090 structure
 * 
 * @return uint8_t Value of NUCp or NIC (see MOPS Version and conversion table)
 */
ASTERIX_API uint8_t get_I021_090_NUCp_NIC(const I021_090 * item);

/**
 * @brief Get the value of Field Extension (FX) from I021/090
 * 
 * @param item Pointer to I021_090 structure
 * 
 * @return uint8_t Value of FX (0: end of item, 1: first extension present)
 */
ASTERIX_API uint8_t get_I021_090_FX(const I021_090 * item);


/* ============================= FIRST EXTENSION ============================ */

/**
 * @brief Get the value of NIC for Barometric Altitude (NICbaro) from Cat 021
 *        Item 090 First Extension
 * 
 * @param item Pointer to I021_090_EXT1 structure
 * 
 * @return uint8_t Value of NICbaro (check conversion table)
 */
ASTERIX_API uint8_t get_I021_090_EXT1_NICbaro(const I021_090_EXT1 * item);

/**
 * @brief Get the value of Surveillance (V1) or Source (V2+) Integrity Level
 *        from I021/090 First Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to I021_090_EXT1 structure
 * 
 * @return uint8_t Value of SIL (check conversion table)
 */
ASTERIX_API uint8_t get_I021_090_EXT1_SIL(const I021_090_EXT1 * item);

/**
 * @brief Get the value of Navigation Accuracy Category for Position (NACp)
 *        from I021/090 First Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to I021_090_EXT1 structure
 * 
 * @return uint8_t Value of NACp (check conversion table)
 */
ASTERIX_API uint8_t get_I021_090_EXT1_NACp(const I021_090_EXT1 * item);

/**
 * @brief Get the value of Field Extension (FX) from I021/090 First Extension
 * 
 * @param item Pointer to I021_090_EXT1 structure
 * 
 * @return uint8_t Value of FX (0: end of item, 1: second extension present)
 */
ASTERIX_API uint8_t get_I021_090_EXT1_FX(const I021_090_EXT1 * item);

/* ============================ SECOND EXTENSION ============================ */

/**
 * @brief Get the SIL-Supplement (SILS) from I021/090 Second Extension
 * 
 * @param item Pointer to I021_090_EXT2 structure
 * 
 * @return uint8_t Value of SIL-Supplement (0: measured per flight-hour,
 *                                          1: measured per sample)
 */
ASTERIX_API uint8_t get_I021_090_EXT2_SILS(const I021_090_EXT2 * item);

/**
 * @brief Get the Horizontal Position System Design Assurance Level (SDA)
 *        from I021/090 Second Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to I021_090_EXT2 structure
 * 
 * @return uint8_t Value of SDA (check conversion table)
 */
ASTERIX_API uint8_t get_I021_090_EXT2_SDA(const I021_090_EXT2 * item);

/**
 * @brief Get the Geometric Altitude Accuracy (GVA) from I021/090 Second Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to I021_090_EXT2 structure
 * 
 * @return uint8_t Value of GVA (check conversion table)
 */
ASTERIX_API uint8_t get_I021_090_EXT2_GVA(const I021_090_EXT2 * item);

/**
 * @brief Get the value of Field Extension (FX) from I021/090 Second Extension
 * 
 * @param item Pointer to I021_090_EXT2 structure
 * 
 * @return uint8_t Value of FX (0: end of item, 1: third extension present)
 */
ASTERIX_API uint8_t get_I021_090_EXT2_FX(const I021_090_EXT2 * item);

/* ============================ THIRD EXTENSION ============================  */

/**
 * @brief Get the Position Integrity Category (PIC) from I021/090 Third Extension
 * 
 * Value used to interpret the other values of this item, referencing the
 * corresponding conversion table.
 * 
 * @param item Pointer to I021_090_EXT3 structure
 * 
 * @return uint8_t Value of PIC
 */
ASTERIX_API uint8_t get_I021_090_EXT3_PIC(const I021_090_EXT3 * item);

#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
/**
 * @brief Get the PIC Source (SRC) from I021/090 Third Extension
 * 
 * @param item Pointer to I021_090_EXT3 structure
 * 
 * @return uint8_t Value of SRC (0: PIC mapped from FTC and NIC Supplements;
 *                               1 PIC directly received in HVA or Phase Overlay)
 */
ASTERIX_API uint8_t get_I021_090_EXT3_SRC(const I021_090_EXT3 * item);
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */

/**
 * @brief Get the value of Field Extension (FX) from I021/090 Third Extension
 * 
 * @param item Pointer to I021_090_EXT3 structure
 * 
 * @return uint8_t Value of FX (0: end of item, 1: fourth extension present)
 */
ASTERIX_API uint8_t get_I021_090_EXT3_FX(const I021_090_EXT3 * item);

#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
/* ============================ FOURTH EXTENSION ===========================  */

/**
 * @brief Get the value of Position Validation State (VALSTATE) from
 *        I021/090 Fourth Extension
 * 
 * @param item pointer to I021_090_EXT4 structure
 * 
 * @return uint8_t value of VALSTATE (see specification Standard)
 */
ASTERIX_API uint8_t get_I021_090_EXT4_VALSTATE(const I021_090_EXT4 * item);

/**
 * @brief Get the value of Validation Distance Availability (VD) from
 *        I021/090 Fourth Extension
 * 
 * @param item pointer to I021_090_EXT4 structure
 * 
 * @return uint8_t value of VD (0: item not available; 1: item available)
 */
ASTERIX_API uint8_t get_I021_090_EXT4_VD(const I021_090_EXT4 * item);

/**
 * @brief Get the value of Validation Distance Quality Availability (VQ) from
 *        I021/090 Fourth Extension
 * 
 * @param item pointer to I021_090_EXT4 structure
 * 
 * @return uint8_t value of VQ (0: item not available; 1: item available)
 */
ASTERIX_API uint8_t get_I021_090_EXT4_VQ(const I021_090_EXT4 * item);

/**
 * @brief Get the value of Field Extension (FX) from I021/090 Fourth Extension
 * 
 * @param item Pointer to I021_090_EXT3 structure
 * 
 * @return uint8_t Value of FX (0: end of item, 1: fifth extension present)
 */
ASTERIX_API uint8_t get_I021_090_EXT4_FX(const I021_090_EXT4 * item);

/* ============================ FIFTH EXTENSION ============================  */

/**
 * @brief Get the Position Validation Distance (VAL_DIST_P1) value in steps of
 *        128 meters from I021/090 Fifth Extension
 * 
 * @param item pointer to I021_090_EXT5 structure
 * 
 * @return uint16_t value of VAL_DIST_P1 in steps of 128 meters (LSB = 128 m)
 */
ASTERIX_API uint16_t get_I021_090_EXT5_VALDISTP1(const I021_090_EXT5 * item);

/**
 * @brief Get the value of Field Extension (FX) from I021/090 Fifth Extension
 * 
 * @param item Pointer to I021_090_EXT3 structure
 * 
 * @return uint8_t Value of FX (0: end of item, 1: sixth extension present)
 */
ASTERIX_API uint8_t get_I021_090_EXT5_FX(const I021_090_EXT5 * item);

/* ============================ SIXTH EXTENSION ============================  */

/**
 * @brief Get the Position Validation Distance (VAL_DIST_P2) value in steps of
 *        1 meters from I021/090 Sixth Extension
 * 
 * @param item pointer to I021_090_EXT6 structure
 * 
 * @return uint16_t value of VAL_DIST_P2 in steps of 1 meters (LSB = 1 m)
 */
ASTERIX_API uint8_t get_I021_090_EXT6_VALDISTP2(const I021_090_EXT6 * item);

/**
 * @brief Get the value of Field Extension (FX) from I021/090 Sixth Extension
 * 
 * @param item Pointer to I021_090_EXT3 structure
 * 
 * @return uint8_t Value of FX (0: end of item, 1: seventh extension present)
 */
ASTERIX_API uint8_t get_I021_090_EXT6_FX(const I021_090_EXT6 * item);

/* =========================== SEVENTH EXTENSION ===========================  */

/**
 * @brief Get the Position Validation Distance Quality (VAL_DIST_QUAL_P1) value
 *       in 128m steps from I021/090 Seventh Extension
 * 
 * @param item pointer to I021_090_EXT7 structure
 * 
 * @return uint16_t value of VAL_DIST_QUAL_P1 in steps of 128 meters (LSB = 128 m)
 */
ASTERIX_API uint16_t get_I021_090_EXT7_VALDISTQUALP1(const I021_090_EXT7 * item);

/**
 * @brief Get the value of Field Extension (FX) from I021/090 Seventh Extension
 * 
 * @param item Pointer to I021_090_EXT3 structure
 * 
 * @return uint8_t Value of FX (0: end of item, 1: eight extension present)
 */
ASTERIX_API uint8_t get_I021_090_EXT7_FX(const I021_090_EXT7 * item);

/* =========================== EIGHT EXTENSION ===========================  */

/**
 * @brief Get the Position Validation Distance Quality (VAL_DIST_QUAL_P2) value
 *       in 1m steps from I021/090 Seventh Extension
 * 
 * @param item pointer to I021_090_EXT8 structure
 * 
 * @return uint8_t value of VAL_DIST_QUAL_P2 in steps of 1 meters (LSB = 1 m)
 */
ASTERIX_API uint16_t get_I021_090_EXT8_VALDISTQUALP2(const I021_090_EXT8 * item);

/**
 * @brief Get the value of Field Extension (FX) from I021/090 Eight Extension
 * 
 * @param item Pointer to I021_090_EXT3 structure
 * 
 * @return uint8_t Value of FX (0: end of item, 1: next extension present)
 */
ASTERIX_API uint8_t get_I021_090_EXT8_FX(const I021_090_EXT8 * item);
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

/**
 * @brief Set the value for NUCr or NACv into I021/090
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to I021_090 structure item
 * @param nucr_nacv New NUCr or NACv value (see MOPS Version and conversion table)
 */
ASTERIX_API void set_I021_090_NUCrNACv(I021_090 * item, uint8_t nucr_nacv);

/**
 * @brief Set the value for NUCp or NIC into I021/090
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to I021_090 structure 
 * @param nucp_nic New NUCp or NIC value (see MOPS Version and conversion table)
 */
ASTERIX_API void set_I021_090_NUCp_NIC(I021_090 * item, uint8_t nucp_nic);

/**
 * @brief Set the value of Field Extension (FX) into I021/090
 * 
 * @param item Pointer to I021_090 structure 
 * @param fx New value of FX (0: end of item, 1: first extension present)
 */
ASTERIX_API void set_I021_090_FX(I021_090 * item, uint8_t fx);

/* ============================= FIRST EXTENSION ============================ */

/**
 * @brief Get the value of NIC for Barometric Altitude (NICbaro) from Cat 021
 *        Item 090 First Extension
 * 
 * @param item Pointer to I021_090_EXT1 structure 
 * @param nic_baro New NICbaro value (check conversion table)
 */

ASTERIX_API void set_I021_090_EXT1_NICbaro(I021_090_EXT1 * item, uint8_t nic_baro);

/**
 * @brief Get the value of Surveillance (V1) or Source (V2+) Integrity Level
 *        from I021/090 First Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to I021_090_EXT1 structure 
 * @param sil New SIL value (check conversion table)
 */
ASTERIX_API void set_I021_090_EXT1_SIL(I021_090_EXT1 * item, uint8_t sil);

/**
 * @brief Get the value of Navigation Accuracy Category for Position (NACp)
 *        from I021/090 First Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to I021_090_EXT1 structure 
 * @param nacp New NACp value (check conversion table)
 */
ASTERIX_API void set_I021_090_EXT1_NACp(I021_090_EXT1 * item, uint8_t nacp);

/**
 * @brief Set the value of Field Extension (FX) into I021/090 First Extension
 * 
 * @param item Pointer to I021_090_EXT1 structure 
 * @param fx New FX value (0: end of item, 1: second extension present)
 */
ASTERIX_API void set_I021_090_EXT1_FX(I021_090_EXT1 * item, uint8_t fx);

/* ============================ SECOND EXTENSION ============================ */

/**
 * @brief Get the SIL-Supplement (SILS) from I021/090 Second Extension
 * 
 * @param item Pointer to I021_090_EXT2 structure 
 * @param sils New SIL-Supplement value (0: measured per flight-hour,
 *                                       1: measured per sample)
 */
ASTERIX_API void set_I021_090_EXT2_SILS(I021_090_EXT2 * item, uint8_t sils);

/**
 * @brief Get the Horizontal Position System Design Assurance Level (SDA)
 *        from I021/090 Second Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to I021_090_EXT2 structure
 * @param sda New SDA value (check conversion table)  
 */
ASTERIX_API void set_I021_090_EXT2_SDA(I021_090_EXT2 * item, uint8_t sda);

/**
 * @brief Get the Geometric Altitude Accuracy (GVA) from I021/090 Second Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to I021_090_EXT2 structure
 * @param gva New GVA value (check conversion table)
 */
ASTERIX_API void set_I021_090_EXT2_GVA(I021_090_EXT2 * item, uint8_t gva);

/**
 * @brief Set the value of Field Extension (FX) into I021/090 Second Extension
 * 
 * @param item Pointer to I021_090_EXT2 structure 
 * @param fx New value of FX (0: end of item, 1: third extension present)
 */
ASTERIX_API void set_I021_090_EXT2_FX(I021_090_EXT2 * item, uint8_t fx);

/* ============================ THIRD EXTENSION ============================  */

/**
 * @brief Set the Position Integrity Category (PIC) into I021/090 Third Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to I021_090_EXT3 structure
 * @param pic New PIC value between 0 and 15 (check conversion table)
 */
ASTERIX_API void set_I021_090_EXT3_PIC(I021_090_EXT3 * item, uint8_t pic);

#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)
/**
 * @brief Set the PIC Source (SRC) value into I021/090 Third Extension
 * 
 * @param item Pointer to I021_090_EXT3 structure
 * @param pic_src Value of SRC (0: PIC mapped from FTC and NIC Supplements;
 *                              1 PIC directly received in HVA or Phase Overlay)
 */
ASTERIX_API void set_I021_090_EXT3_SRC(I021_090_EXT3 * item, uint8_t pic_src);
#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */

/**
 * @brief Set the value of Field Extension (FX) into I021/090 Third Extension
 * 
 * @param item Pointer to I021_090_EXT3 structure 
 * @param fx New value of FX (0: end of item, 1: next extension present)
 */
ASTERIX_API void set_I021_090_EXT3_FX(I021_090_EXT3 * item, uint8_t fx);

#if (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7)

/* ============================ FOURTH EXTENSION ===========================  */

/**
 * @brief Set a new Position Validation State (VALSTATE) value into Cat 021
 *        Item 090 Fourth Extension
 * 
 * @param item pointer to I021_090_EXT4 structure
 * @param val_state new VALSTATE value (see Specification Standard)
 */
ASTERIX_API void set_I021_090_EXT4_VALSTATE(I021_090_EXT4 * item, uint8_t val_state);

/**
 * @brief Set the new Validation Distance Availability )VD) value into
 *        I021/090 Fourth Extension
 * 
 * @param item pointer to I021_090_EXT4 structure
 * @param vd new VD value (0: item not available; 1: item available)
 */
ASTERIX_API void set_I021_090_EXT4_VD(I021_090_EXT4 * item, uint8_t vd);

/**
 * @brief Set the new Validation Distance Quality Availability (VQ) value into
 *        I021/090 Fourth Extension
 * 
 * @param item pointer to I021_090_EXT4 structure
 * @param vq new VQ value (0: item not available; 1: item available)
 */
ASTERIX_API void set_I021_090_EXT4_VQ(I021_090_EXT4 * item, uint8_t vq);

/**
 * @brief Set the value of Field Extension (FX) into I021/090 Forth Extension
 * 
 * @param item Pointer to I021_090_EXT4 structure 
 * @param value New value of FX (0: end of item, 1: next extension present)
 */
ASTERIX_API void set_I021_090_EXT4_FX(I021_090_EXT4 * item, uint8_t fx);

/* ============================ FIFTH EXTENSION ============================  */

/**
 * @brief Set the new Position Validation Distance (VAL_DIST_P1) value into
 *        I021/090 Fifth Extension
 * 
 * @param item pointer to I021_090_EXT5 structure
 * @param val_dist_p1 new VAL_DIST_P1 value in steps of 128 meters (LSB = 128 m)
 */
ASTERIX_API void set_I021_090_EXT5_VALDISTP1(I021_090_EXT5 * item, uint16_t val_dist_p1);

/**
 * @brief Set the value of Field Extension (FX) into I021/090 Fifth Extension
 * 
 * @param item Pointer to I021_090_EXT5 structure 
 * @param value New value of FX (0: end of item, 1: next extension present)
 */
ASTERIX_API void set_I021_090_EXT5_FX(I021_090_EXT5 * item, uint8_t fx);

/* ============================ SIXTH EXTENSION ============================  */

/**
 * @brief Set the new Position Validation Distance (VAL_DIST_P2) value into
 *        I021/090 Sixth Extension
 * 
 * @param item pointer to I021_090_EXT6 structure
 * @param val_dist_p2 new VAL_DIST_P2 value in steps of 1 meter (LSB = 1 m)
 */
ASTERIX_API void set_I021_090_EXT6_VALDISTP2(I021_090_EXT6 * item, uint8_t val_dist_p2);

/**
 * @brief Set the value of Field Extension (FX) into I021/090
 *        Sixth Extension
 * 
 * @param item Pointer to I021_090_EXT6 structure 
 * @param value New value of FX (0: end of item, 1: next extension present)
 */
ASTERIX_API void set_I021_090_EXT6_FX(I021_090_EXT6 * item, uint8_t fx);

/* =========================== SEVENTH EXTENSION ===========================  */

/**
 * @brief Set new Position Validation Distance Quality (VALDISTQUALP1) value
 *        into I021/090 Seventh Extension
 * 
 * @param item pointer to I021_090_EXT7 structure
 * @param val_dist_qual_p1 new VAL_DIST_QUAL_P1 value in steps of 128 meters (LSB = 128 m)
 */
ASTERIX_API void set_I021_090_EXT7_VALDISTQUALP1(I021_090_EXT7 * item, uint16_t val_dist_qual_p1);

/**
 * @brief Set the value of Field Extension (FX) into I021/090
 *        Seventh Extension
 * 
 * @param item Pointer to I021_090_EXT7 structure 
 * @param value New value of FX (0: end of item, 1: next extension present)
 */
ASTERIX_API void set_I021_090_EXT7_FX(I021_090_EXT7 * item, uint8_t fx);

/* ============================ EIGHT EXTENSION ============================  */

/**
 * @brief Set new Position Validation Distance Quality (VALDISTQUALP2) value
 *        into I021/090 Eight Extension
 * 
 * @param item pointer to I021_090_EXT8 structure
 * @param val_dist_qual_p2 new VAL_DIST_QUAL_P2 value in steps of 1 meters (LSB = 1 m)
 */
ASTERIX_API void set_I021_090_EXT8_VALDISTQUALP2(I021_090_EXT8 * item, uint8_t val_dist_qual_p2);

/**
 * @brief Set the value of Field Extension (FX) into I021/090
 *        Eight Extension
 * 
 * @param item Pointer to I021_090_EXT8 structure 
 * @param value New value of FX (0: end of item, 1: next extension present)
 */
ASTERIX_API void set_I021_090_EXT8_FX(I021_090_EXT8 * item, uint8_t fx);

#endif /* (EDITION_NUMBER_I021 >= 2 && VERSION_NUMBER_I021 >= 7) */

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/090 (Quality Indicators) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/090 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_090(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/090 (Quality Indicators) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/090 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_090(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Count the number of extensions present in the I021/090.
 * 
 * Evaluates each FX bit to determine the number of present extensions.
 * 
 * @param item Pointer to the main I021_090 structure.
 * 
 * @return uint8_t Number of present extensions (0 to 3).
 */
ASTERIX_API uint8_t count_I021_090_extensions(const I021_090 *item);

/**
 * @brief Print the contents of I021/090 and its extensions.
 * 
 * @param item Pointer to I021_090 structure.
 */
ASTERIX_API void print_I021_090(const I021_090 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_090_H */