/**
 * @file I021_040.h
 * @brief Definition of I021/040, and related functions and values
 */

#ifndef I021_040_H
#define I021_040_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_040_ATP_ICAO_ADDR         0 // 24-Bit ICAO address
#define I021_040_ATP_DUP_ADDR          1 // Duplicate address
#define I021_040_ATP_SURFACE_VEHICLE   2 // Surface vehicle address
#define I021_040_ATP_ANON_ADDR         3 // Anonymous address
#define I021_040_ATP_RESERVED_MIN      4 // Reserved for future use
#define I021_040_ATP_RESERVED_MAX      7 // Reserved for future use

#define I021_040_ARC_25FT              0 // 25 ft
#define I021_040_ARC_100FT             1 // 100 ft
#define I021_040_ARC_UNKNOWN           2 // Unknown
#define I021_040_ARC_INVALID           3 // Invalid

#define I021_040_RC_DEFAULT            0 // Default
#define I021_040_RC_PASSED             1 // Range Check passed, pending CPR validation

#define I021_040_RAB_TRANSPONDER       0 // Report from target transponder
#define I021_040_RAB_FIELD_MONITOR     1 // Report from field

#define I021_040_EXT1_DCR_NO_DIFF      0 // No differential correction (ADS-B)
#define I021_040_EXT1_DCR_DIFF         1 // Differential correction (ADS-B)

#define I021_040_EXT1_GBS_NOT_SET      0 // Ground Bit not set
#define I021_040_EXT1_GBS_SET          1 // Ground Bit set

#define I021_040_EXT1_SIM_ACTUAL       0 // Actual target report
#define I021_040_EXT1_SIM_SIMULATED    1 // Simulated target report

#define I021_040_EXT1_TST_DEFAULT      0 // Default
#define I021_040_EXT1_TST_TEST         1 // Test Target

#define I021_040_EXT1_SAA_CAPABLE      0 // Equipment capable to provide Selected Altitude
#define I021_040_EXT1_SAA_NOT_CAPABLE  1 // Equipment not capable to provide Selected Altitude

#define I021_040_EXT1_CL_VALID         0 // Report valid
#define I021_040_EXT1_CL_SUSPECT       1 // Report suspect
#define I021_040_EXT1_CL_NO_INFO       2 // No information
#define I021_040_EXT1_CL_RESERVED      3 // Reserved for future use

#define I021_040_EXT2_LLC_DEFAULT      0 // Default
#define I021_040_EXT2_LLC_SUSPECT      1 // Target is suspect

#define I021_040_EXT2_IPC_DEFAULT      0 // Default
#define I021_040_EXT2_IPC_FAILED       1 // Independent Position Check failed

#define I021_040_EXT2_NOGO_NOT_SET     0 // NOGO-bit not set
#define I021_040_EXT2_NOGO_SET         1 // NOGO-bit set

#define I021_040_EXT2_CPR_VALID        0 // CPR Validation correct
#define I021_040_EXT2_CPR_FAILED       1 // CPR Validation failed

#define I021_040_EXT2_LDPJ_NOT_DET     0 // LDPJ not detected
#define I021_040_EXT2_LDPJ_DET         1 // LDPJ detected

#define I021_040_EXT2_RCF_DEFAULT      0 // Default
#define I021_040_EXT2_RCF_FAILED       1 // Range Check failed

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_040_EXT1
 * @brief First extension of the Category 021 / Item 040
 */
typedef struct I021_040_EXT1 {
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
             * @brief Differential Correction
             * 
             * = 0 No differential correction (ADS-B) |
             * = 1 Differential correction (ADS-B)
             */
            uint8_t DCR     :1;
            /** 
             * @brief Ground Bit Setting
             * 
             * = 0 Ground Bit not set |
             * = 1 Ground Bit set
             */
            uint8_t GBS     :1;
            /** 
             * @brief Simulated Target
             * 
             * = 0 Actual target report |
             * = 1 Simulated target report
             */
            uint8_t SIM     :1;
            /** 
             * @brief Test Target
             * 
             * = 0 Default |
             * = 1 Test Target
             */
            uint8_t TST     :1;
            /** 
             * @brief Selected Altitude Available
             * 
             * = 0 Equipment capable to provide Selected Altitude |
             * = 1 Equipment not capable to provide Selected Altitude
             */
            uint8_t SAA     :1;
            /** 
             * @brief Confidence Level
             * 
             * = 0 Report valid |
             * = 1 Report suspect |
             * = 2 No information |
             * = 3 Reserved for future use
             */
            uint8_t CL      :2;
            /** 
             * @brief Field Extension
             * 
             * = 0 End of item |
             * = 1 Extension into second extension
             */
            uint8_t FX      :1;
        };
    };
} I021_040_EXT1;

/**
 * @typedef I021_040_EXT2
 * @brief Second extension of the Category 021 / Item 040
 */
typedef struct I021_040_EXT2 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bit, set to "0"
            uint8_t spare   :1;
            /** 
             * @brief List Lookup Check
             * 
             * = 0 default |
             * = 1 Target is suspect
             */
            uint8_t LLC     :1;
            /** 
             * @brief Independent Position Check
             * 
             * = 0 default |
             * = 1 Independent Position Check failed
             */
            uint8_t IPC     :1;
            /** 
             * @brief No-go Bit Status
             * 
             * = 0 NOGO-bit not set |
             * = 1 NOGO-bit set
             */
            uint8_t NOGO    :1;
            /** 
             * @brief Compact Position Reporting
             * 
             * = 0 CPR Validation correct |
             * = 1 CPR Validation failed
             */
            uint8_t CPR     :1;
            /** 
             * @brief Local Decoding Position Jump
             * 
             * = 0 LDPJ not detected |
             * = 1 LDPJ detected
             */
            uint8_t LDPJ    :1;
            /** 
             * @brief Range Check
             * 
             * = 0 default |
             * = 1 Range Check failed
             */
            uint8_t RCF     :1;
            /** 
             * @brief Field Extension
             * 
             * = 0 end of data item |
             * = 1 extension into third extension
             */
            uint8_t FX      :1;
        };
    };
} I021_040_EXT2;

/**
 * @typedef I021_040_EXT3
 * @brief Third extension of the Category 021 / Item 040
 */
typedef struct I021_040_EXT3 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            union {
                /** 
                 * @brief Total Bits Corrected
                 * 
                 * bit-8 TBC_EP - Element Populated Bit
                 * 
                 * bit-7/2 TBC_VAL - MBC Value
                 */
                uint8_t TBC             :7;
                struct {
                    /**
                     *  @brief TBC Element populated
                     * 
                     * = 0 Element not populated |
                     * = 1 Element populated
                     * 
                     */
                    uint8_t TBC_EP      :1;
                    /// @brief TBC Value
                    uint8_t TBC_VAL     :6;
                };
            };
            /** 
             * @brief Field Extension
             * 
             * = 0 end of data item |
             * = 1 extension into fourth extension
             */
            uint8_t FX                  :1;
        };
    };
} I021_040_EXT3;

/**
 * @typedef I021_040_EXT4
 * @brief Fourth extension of the Category 021 / Item 040
 */
typedef struct I021_040_EXT4 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            union {
                /** 
                 * @brief Maximum Bits Corrected
                 * 
                 * bit-8 MBC_EP Element Populated Bit
                 * 
                 * bit-7/2 MBC_VAL MBC Value
                 */
                uint8_t MBC             :7;
                struct {
                    /** 
                     * @brief MBC Element populated
                     * 
                     * = 0 Element not populated |
                     * = 1 Element populated
                     */
                    uint8_t MBC_EP      :1;
                    /// @brief MBC Value
                    uint8_t MBC_VAL     :6;
                };
            };
            /** 
             * @brief Field Extension
             * 
             * = 0 end of data item |
             * = 1 extension into fourth extension
             */
            uint8_t FX                  :1;
        };
    };
} I021_040_EXT4;

/**
 * @typedef I021_040
 * @brief Category 021 / Item 040 - Target Report Descriptor
 */
typedef struct I021_040 {
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
             * @brief Address Type
             * 
             * = 0 24-Bit ICAO address |
             * = 1 Duplicate address |
             * = 2 Surface vehicle address |
             * = 3 Anonymous address |
             * = 4-7 Reserved for future use
             */
            uint8_t ATP     :3;
            /** 
             * @brief Altitude Reporting Capability
             * 
             * = 0 25 ft |
             * = 1 100 ft |
             * = 2 Unknown |
             * = 3 Invalid
             */
            uint8_t ARC     :2;
            /** 
             * @brief Range Check
             * 
             * = 0 Default |
             * = 1 Range Check passed, pending CPR validation
             */
            uint8_t RC      :1;
            /** 
             * @brief Report Type
             * 
             * = 0 Report from target transponder |
             * = 1 Report from field monitor (fixed transponder)
             */
            uint8_t RAB     :1;
            /** 
             * @brief Field Extension
             * 
             * = 0 End of item |
             * = 1 Extension into first extension
             */
            uint8_t FX      :1;
        };
    };

    /// @brief First extension subfield (1 byte)
    I021_040_EXT1 ext1;
    /// @brief Second extension subfield (1 byte)
    I021_040_EXT2 ext2;
    /// @brief Third extension subfield (1 byte)
    I021_040_EXT3 ext3;
    /// @brief Fourth extension subfield (1 byte)
    I021_040_EXT4 ext4;
} I021_040;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

/**
 * @brief Get the Address Type (ATP) from I021/040 Primary Subfield.
 * 
 * Portable access to the ATP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040 structure.
 * @return uint8_t Value of ATP (0: ICAO addr,
 *                               1: dup. addr,
 *                               2: surface vehicle addr.
 *                               3: anon. addr,
 *                               4-7: reserved)
 */
ASTERIX_API uint8_t get_I021_040_ATP(const I021_040 *item);

/**
 * @brief Get the Altitude Reporting Capability (ARC) from I021/040 Primary Subfield.
 * 
 * Portable access to the ARC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040 structure.
 * @return uint8_t Value of ARC (0: 25 ft, 1: 100 ft, 2: unknown, 3: invalid)
 */
ASTERIX_API uint8_t get_I021_040_ARC(const I021_040 *item);

/**
 * @brief Get the Differential Correction (RC) from I021/040 Primary Subfield.
 * 
 * Portable access to the RC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040 structure.
 * @return uint8_t Value of RC (0: default,
 *                              1: range checked passed, pending CPR validation)
 */
ASTERIX_API uint8_t get_I021_040_RC(const I021_040 *item);

/**
 * @brief Get the Report Type (RAB) from I021/040 Primary Subfield.
 * 
 * Portable access to the RAB bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040 structure.
 * @return uint8_t Value of RAB (0: report from target transponder,
 *                               1: report from field fixed transponder)
 */
ASTERIX_API uint8_t get_I021_040_RAB(const I021_040 *item);

/**
 * @brief Get the Field Extension (FX) from I021/040 Primary Subfield.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040 structure.
 * @return uint8_t Value of FX (0: end of item, 1: first extension present)
 */
ASTERIX_API uint8_t get_I021_040_FX(const I021_040 *item);

/* === FIRST EXTENSION === */

/**
 * @brief Get the Differential Correction (DCR) from I021/040 First Extension.
 * 
 * Portable access to the DCR bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @return uint8_t Value of DCR (0: No differential correction (ADS-B),
 *                               1: Differential correction (ADS-B))
 */
ASTERIX_API uint8_t get_I021_040_EXT1_DCR(const I021_040_EXT1 *item);

/**
 * @brief Get the Ground Bit Setting (GBS) from I021/040 First Extension.
 * 
 * Portable access to the GBS bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @return uint8_t Value of GBS (0: Ground Bit not set,
 *                               1: Ground Bit set)
 */
ASTERIX_API uint8_t get_I021_040_EXT1_GBS(const I021_040_EXT1 *item);

/**
 * @brief Get the Simulated Target (SIM) from I021/040 First Extension.
 * 
 * Portable access to the SIM bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @return uint8_t Value of SIM (0: Actual target report,
 *                               1: Simulated target report)
 */
ASTERIX_API uint8_t get_I021_040_EXT1_SIM(const I021_040_EXT1 *item);

/**
 * @brief Get the Test Target (TST) from I021/040 First Extension.
 * 
 * Portable access to the TST bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @return uint8_t Value of TST (0: Default,
 *                               1: Test Target)
 */
ASTERIX_API uint8_t get_I021_040_EXT1_TST(const I021_040_EXT1 *item);

/**
 * @brief Get the Selected Altitude Available (SAA) from I021/040 First Extension.
 * 
 * Portable access to the SAA bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @return uint8_t Value of SAA (0: Equipment capable to provide Selected Altitude,
 *                               1: Equipment not capable to provide Selected Altitude)
 */
ASTERIX_API uint8_t get_I021_040_EXT1_SAA(const I021_040_EXT1 *item);

/**
 * @brief Get the Confidence Level (CL) from I021/040 First Extension.
 * 
 * Portable access to the CL bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @return uint8_t Value of CL (0: Report valid,
 *                              1: Report suspect,
 *                              2: No information,
 *                              3: Reserved for future use)
 */
ASTERIX_API uint8_t get_I021_040_EXT1_CL(const I021_040_EXT1 *item);

/**
 * @brief Get the Field Extension (FX) from I021/040 First Extension.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @return uint8_t Value of FX (0: end of item, 1: second extension present)
 */
ASTERIX_API uint8_t get_I021_040_EXT1_FX(const I021_040_EXT1 *item);

/* ============================ SECOND EXTENSION ============================ */

/**
 * @brief Get the List Lookup Check (LL) from I021/040 Second Extension.
 * 
 * Portable access to the LL bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @return uint8_t Value of LL (0: default,
 *                              1: Target is suspect)
 */
ASTERIX_API uint8_t get_I021_040_EXT2_LLC(const I021_040_EXT2 *item);

/**
 * @brief Get the Independent Position Check (IP) from I021/040 Second Extension.
 * 
 * Portable access to the IP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @return uint8_t Value of IP (0: default,
 *                              1: Independent Position Check failed)
 */
ASTERIX_API uint8_t get_I021_040_EXT2_IPC(const I021_040_EXT2 *item);

/**
 * @brief Get the No-go Bit Status (NO) from I021/040 Second Extension.
 * 
 * Portable access to the NO bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @return uint8_t Value of NO (0: NOGO-bit not set,
 *                              1: NOGO-bit set)
 */
ASTERIX_API uint8_t get_I021_040_EXT2_NOGO(const I021_040_EXT2 *item);

/**
 * @brief Get the Compact Position Reporting (CP) from I021/040 Second Extension.
 * 
 * Portable access to the CP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @return uint8_t Value of CP (0: CPR Validation correct),
 *                              1: CPR Validation failed)
 */
ASTERIX_API uint8_t get_I021_040_EXT2_CPR(const I021_040_EXT2 *item);

/**
 * @brief Get the Local Decoding Position Jump (LD) from I021/040 Second Extension.
 * 
 * Portable access to the LD bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @return uint8_t Value of LD (0: LDPJ not detected,
 *                              1: LDPJ detected)
 */
ASTERIX_API uint8_t get_I021_040_EXT2_LDPJ(const I021_040_EXT2 *item);

/**
 * @brief Get the Range Check (RCF) from I021/040 Second Extension.
 * 
 * Portable access to the RCF bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @return uint8_t Value of RCF (0: default,
 *                              1: Range Check failed)
 */
ASTERIX_API uint8_t get_I021_040_EXT2_RCF(const I021_040_EXT2 *item);

/**
 * @brief Get the Field Extension (FX) from I021/040 Second Extension.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @return uint8_t Value of FX (0: end of item, 1: third extension present)
 */
ASTERIX_API uint8_t get_I021_040_EXT2_FX(const I021_040_EXT2 *item);

/* ============================ THIRD EXTENSION ============================  */

/**
 * @brief Get the raw Total Bits Corrected (TBC) from I021/040 Third Extension.
 * 
 * Portable access to the TBC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT3 structure.
 * @return uint8_t Raw value of TBC (bit-8 TBC_EP, bits-7/2 TBC_VAL)
 */
ASTERIX_API uint8_t get_I021_040_EXT3_TBC(const I021_040_EXT3 *item);

/**
 * @brief Get the TBC Element populated (TBC_EP) from I021/040 Third Extension.
 * 
 * Portable access to the TBC_EP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT3 structure.
 * @return uint8_t Value of TBC_EP (0: element not populated, 1: element populated)
 */
ASTERIX_API uint8_t get_I021_040_EXT3_TBC_EP(const I021_040_EXT3 *item);

/**
 * @brief Get the TBC Value (TBC_VAL) from I021/040 Third Extension.
 * 
 * Portable access to the TBC_VAL bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT3 structure.
 * @return uint8_t Value of TBC_VAL
 */
ASTERIX_API uint8_t get_I021_040_EXT3_TBC_VAL(const I021_040_EXT3 *item);

/**
 * @brief Get the Field Extension (FX) from I021/040 Third Extension.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT3 structure.
 * @return uint8_t Value of FX (0: end of item, 1: fourth extension present)
 */
ASTERIX_API uint8_t get_I021_040_EXT3_FX(const I021_040_EXT3 *item);

/* ============================ FOURTH EXTENSION ============================ */

/**
 * @brief Get the raw Maximum Bits Corrected (MBC) from I021/040 Fourth Extension.
 * 
 * Portable access to the MBC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT4 structure.
 * @return uint8_t Raw value of MBC (bit-8 MBC_EP, bits-7/2 MBC_VAL)
 */
ASTERIX_API uint8_t get_I021_040_EXT4_MBC(const I021_040_EXT4 *item);

/**
 * @brief Get the MBC Element populated (MBC_EP) from I021/040 Fourth Extension.
 * 
 * Portable access to the MBC_EP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT4 structure.
 * @return uint8_t Value of MBC_EP (0: element not populated, 1: element populated)
 */
ASTERIX_API uint8_t get_I021_040_EXT4_MBC_EP(const I021_040_EXT4 *item);

/**
 * @brief Get the MBC Value (MBC_VAL) from I021/040 Fourth Extension.
 * 
 * Portable access to the MBC_VAL bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT4 structure.
 * @return uint8_t Value of MBC_VAL
 */
ASTERIX_API uint8_t get_I021_040_EXT4_MBC_VAL(const I021_040_EXT4 *item);

/**
 * @brief Get the Field Extension (FX) from I021/040 Fourth Extension.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_040_EXT4 structure.
 * @return uint8_t Value of FX (0: end of item, 1: extension present)
 */ASTERIX_API uint8_t get_I021_040_EXT4_FX(const I021_040_EXT4 *item);


/*******************************************************************************
 * Setters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

/**
 * @brief Set the Address Type (ATP) in I021/040.
 * 
 * Modifies the ATP bits (bits 8-6) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040 structure.
 * @param atp New ATP value (Range: 0 to 7).
 */
ASTERIX_API void set_I021_040_ATP(I021_040 *item, uint8_t atp);

/**
 * @brief Set the Altitude Reporting Capability (ARC) in I021/040.
 * 
 * Modifies the ARC bits (bits 5-4) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040 structure.
 * @param arc New ARC value (Range: 0 to 3).
 */
ASTERIX_API void set_I021_040_ARC(I021_040 *item, uint8_t arc);

/**
 * @brief Set the Range Check (RC) in I021/040.
 * 
 * Modifies the RC bits (bit 3) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040 structure.
 * @param rc New RC value (0 or 1).
 */
ASTERIX_API void set_I021_040_RC(I021_040 *item, uint8_t rc);

/**
 * @brief Set the Report Type (RAB) in I021/040.
 * 
 * Modifies the RAB bits (bit 2) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040 structure.
 * @param rab New RAB value (0 or 1).
 */
ASTERIX_API void set_I021_040_RAB(I021_040 *item, uint8_t rab);

/**
 * @brief Set the Field Extension (FX) in I021/040.
 * 
 * Modifies the FX bits (bit 1) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040 structure.
 * @param fx New FX value (0 or 1).
 */
ASTERIX_API void set_I021_040_FX(I021_040 *item, uint8_t fx);

/* === FIRST EXTENSION === */

/**
 * @brief Set the Differential Correction (DCR) in I021/040 First extension.
 * 
 * Modifies the DCR bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @param dcr New DCR value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT1_DCR(I021_040_EXT1 *item, uint8_t dcr);

/**
 * @brief Set the Ground Bit Setting (GBS) in I021/040 First extension.
 * 
 * Modifies the GBS bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @param gbs New GBS value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT1_GBS(I021_040_EXT1 *item, uint8_t gbs);

/**
 * @brief Set the Simulated Target (SIM) in I021/040 First extension.
 * 
 * Modifies the SIM bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @param sim New SIM value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT1_SIM(I021_040_EXT1 *item, uint8_t sim);

/**
 * @brief Set the Test Target (TST) in I021/040 First extension.
 * 
 * Modifies the TST bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @param tst New TST value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT1_TST(I021_040_EXT1 *item, uint8_t tst);

/**
 * @brief Set the Selected Altitude Available (SAA) in I021/040 First extension.
 * 
 * Modifies the SAA bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @param saa New SAA value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT1_SAA(I021_040_EXT1 *item, uint8_t saa);

/**
 * @brief Set the Confidence Level (CL) in I021/040 First extension.
 * 
 * Modifies the CL bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @param cl New CL value (0 to 3).
 */
ASTERIX_API void set_I021_040_EXT1_CL(I021_040_EXT1 *item, uint8_t cl);

/**
 * @brief Set the Field Extension (FX) in I021/040 First extension.
 * 
 * Modifies the FX bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT1 structure.
 * @param fx New FX value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT1_FX(I021_040_EXT1 *item, uint8_t fx);

/* ============================ SECOND EXTENSION ============================ */

/**
 * @brief Set the List Lookup Check (LLC) in I021/040 Second extension.
 * 
 * Modifies the LLC bits (bit 7) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @param llc New LLC value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT2_LLC(I021_040_EXT2 *item, uint8_t llc);

/**
 * @brief Set the Independent Position Check (IPC) in I021/040 Second extension.
 * 
 * Modifies the IPC bits (bit 6) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @param ipc New IPC value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT2_IPC(I021_040_EXT2 *item, uint8_t ipc);

/**
 * @brief Set the No-go Bit Status (NOGO) in I021/040 Second extension.
 * 
 * Modifies the NOGO bits (bit 5) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @param nogo New NOGO value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT2_NOGO(I021_040_EXT2 *item, uint8_t nogo);

/**
 * @brief Set the Compact Position Reporting (CPR) in I021/040 Second extension.
 * 
 * Modifies the CPR bits (bit 4) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @param cpr New CPR value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT2_CPR(I021_040_EXT2 *item, uint8_t cpr);

/**
 * @brief Set the Local Decoding Position Jump (LDPJ) in I021/040 Second extension.
 * 
 * Modifies the LDPJ bits (bit 3) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @param ldpj New LDPJ value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT2_LDPJ(I021_040_EXT2 *item, uint8_t ldpj);

/**
 * @brief Set the Range Check (RCF) in I021/040 Second extension.
 * 
 * Modifies the RCF bits (bit 2) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @param rcf New RCF value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT2_RCF(I021_040_EXT2 *item, uint8_t rcf);

/**
 * @brief Set the Field Extension (FX) in I021/040 Second extension.
 * 
 * Modifies the FX bits (bit 1) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT2 structure.
 * @param fx New FX value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT2_FX(I021_040_EXT2 *item, uint8_t fx);

/* ============================ THIRD EXTENSION ============================  */

/**
 * @brief Set the Total Bits Corrected (TBC) in I021/040 Third extension.
 * 
 * Modifies the TBC bits (bits 8-2) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT3 structure.
 * @param tbc New TBC value.
 */
ASTERIX_API void set_I021_040_EXT3_TBC(I021_040_EXT3 *item, uint8_t tbc);

/**
 * @brief Set the TBC Element populated (TBC_EP) in I021/040 Third extension.
 * 
 * Modifies the TBC_EP bits (bit 8) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT3 structure.
 * @param tbc_ep New TBC_EP value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT3_TBC_EP(I021_040_EXT3 *item, uint8_t tbc_ep);

/**
 * @brief Set the TBC Value (TBC_VAL) in I021/040 Third extension.
 * 
 * Modifies the TBC_VAL bits (bits 7-2) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT3 structure.
 * @param tbc_val New TBC_VAL value.
 */
ASTERIX_API void set_I021_040_EXT3_TBC_VAL(I021_040_EXT3 *item, uint8_t tbc_val);

/**
 * @brief Set the Field Extension (FX) in I021/040 Third extension.
 * 
 * Modifies the FX bits (bit 1) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT3 structure.
 * @param fx New FX value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT3_FX(I021_040_EXT3 *item, uint8_t fx);

/* ============================ FOURTH EXTENSION ============================ */

/**
 * @brief Set the Maximum Bits Corrected (MBC) in I021/040 Fourth extension.
 * 
 * Modifies the MBC bits (bits 8-2) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT4 structure.
 * @param mbc New MBC value.
 */
ASTERIX_API void set_I021_040_EXT4_MBC(I021_040_EXT4 *item, uint8_t mbc);

/**
 * @brief Set the MBC Element populated (MBC_EP) in I021/040 Fourth extension.
 * 
 * Modifies the MBC_EP bits (bit 8) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT4 structure.
 * @param mbc_ep New MBC_EP value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT4_MBC_EP(I021_040_EXT4 *item, uint8_t mbc_ep);

/**
 * @brief Set the MBC Value (MBC_VAL) in I021/040 Fourth extension.
 * 
 * Modifies the MBC_VAL bits (bits 7-2) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT4 structure.
 * @param mbc_val New MBC_VAL value.
 */
ASTERIX_API void set_I021_040_EXT4_MBC_VAL(I021_040_EXT4 *item, uint8_t mbc_val);

/**
 * @brief Set the Field Extension (FX) in I021/040 Fourth extension.
 * 
 * Modifies the FX bits (bit 1) using a safe bitmask operation.
 * 
 * @param item Pointer to I021_040_EXT4 structure.
 * @param fx New FX value (0 or 1).
 */
ASTERIX_API void set_I021_040_EXT4_FX(I021_040_EXT4 *item, uint8_t fx);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/040 (Target Reporter Descriptor) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/040 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_040(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/040 (Target Reporter Descriptor) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/040 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_040(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 040 including its extensions.
 *
 * This function prints the values of the main byte and each extension
 * (if present according to the FX bits) to the standard output.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a I021_040 structure.
 */
ASTERIX_API void print_I021_040(const I021_040 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_040_H */
