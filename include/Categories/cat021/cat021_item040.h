/**
 * @file cat021_item040.h
 * @brief Definition of item 040 of CAT 021, and related functions and values
 */

#ifndef CAT021_ITEM040_H
#define CAT021_ITEM040_H

#include <stdint.h>
#include "visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * MACROS
 ******************************************************************************/
 
/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item040
 * @brief Category 021 / Item 040 - Target Report Descriptor
 */
typedef struct cat021_item040 {
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
    cat021_item040_ext1 ext1;
    /// @brief Second extension subfield (1 byte)
    cat021_item040_ext2 ext2;
    /// @brief Third extension subfield (1 byte)
    cat021_item040_ext3 ext3;
    /// @brief Fourth extension subfield (1 byte)
    cat021_item040_ext4 ext4;
} cat021_item040;

/**
 * @typedef cat021_item040_ext1
 * @brief First extension of the Category 021 / Item 040
 */
typedef struct cat021_item040_ext1 {
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
} cat021_item040_ext1;

/**
 * @typedef cat021_item040_ext2
 * @brief Second extension of the Category 021 / Item 040
 */
typedef struct cat021_item040_ext2 {
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
} cat021_item040_ext2;

/**
 * @typedef cat021_item040_ext3
 * @brief Third extension of the Category 021 / Item 040
 */
typedef struct cat021_item040_ext3 {
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
} cat021_item040_ext3;

/**
 * @typedef cat021_item040_ext4
 * @brief Fourth extension of the Category 021 / Item 040
 */
typedef struct cat021_item040_ext4 {
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
} cat021_item040_ext4;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

/**
 * @brief Get the Address Type (ATP) from CAT 021 Item 040 Primary Subfield.
 * 
 * Portable access to the ATP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @return uint8_t Value of ATP (0: ICAO addr,
 *                               1: dup. addr,
 *                               2: surface vehicle addr.
 *                               3: anon. addr,
 *                               4-7: reserved)
 */
ASTERIX_API uint8_t get_cat021_item040_ATP(const cat021_item040 *item);

/**
 * @brief Get the Altitude Reporting Capability (ARC) from CAT 021 Item 040 Primary Subfield.
 * 
 * Portable access to the ARC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @return uint8_t Value of ARC (0: 25 ft, 1: 100 ft, 2: unknown, 3: invalid)
 */
ASTERIX_API uint8_t get_cat021_item040_ARC(const cat021_item040 *item);

/**
 * @brief Get the Differential Correction (RC) from CAT 021 Item 040 Primary Subfield.
 * 
 * Portable access to the RC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @return uint8_t Value of RC (0: default,
 *                              1: range checked passed, pending CPR validation)
 */
ASTERIX_API uint8_t get_cat021_item040_RC(const cat021_item040 *item);

/**
 * @brief Get the Report Type (RAB) from CAT 021 Item 040 Primary Subfield.
 * 
 * Portable access to the RAB bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @return uint8_t Value of RAB (0: report from target transponder,
 *                               1: report from field fixed transponder)
 */
ASTERIX_API uint8_t get_cat021_item040_RAB(const cat021_item040 *item);

/**
 * @brief Get the Field Extension (FX) from CAT 021 Item 040 Primary Subfield.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @return uint8_t Value of FX (0: end of item, 1: first extension present)
 */
ASTERIX_API uint8_t get_cat021_item040_FX(const cat021_item040 *item);

/* === FIRST EXTENSION === */

/**
 * @brief Get the Differential Correction (DCR) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the DCR bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of DCR (0: No differential correction (ADS-B),
 *                               1: Differential correction (ADS-B))
 */
ASTERIX_API uint8_t get_cat021_item040_ext1_DCR(const cat021_item040_ext1 *item);

/**
 * @brief Get the Ground Bit Setting (GBS) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the GBS bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of GBS (0: Ground Bit not set,
 *                               1: Ground Bit set)
 */
ASTERIX_API uint8_t get_cat021_item040_ext1_GBS(const cat021_item040_ext1 *item);

/**
 * @brief Get the Simulated Target (SIM) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the SIM bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of SIM (0: Actual target report,
 *                               1: Simulated target report)
 */
ASTERIX_API uint8_t get_cat021_item040_ext1_SIM(const cat021_item040_ext1 *item);

/**
 * @brief Get the Test Target (TST) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the TST bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of TST (0: Default,
 *                               1: Test Target)
 */
ASTERIX_API uint8_t get_cat021_item040_ext1_TST(const cat021_item040_ext1 *item);

/**
 * @brief Get the Selected Altitude Available (SAA) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the SAA bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of SAA (0: Equipment capable to provide Selected Altitude,
 *                               1: Equipment not capable to provide Selected Altitude)
 */
ASTERIX_API uint8_t get_cat021_item040_ext1_SAA(const cat021_item040_ext1 *item);

/**
 * @brief Get the Confidence Level (CL) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the CL bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of CL (0: Report valid,
 *                              1: Report suspect,
 *                              2: No information,
 *                              3: Reserved for future use)
 */
ASTERIX_API uint8_t get_cat021_item040_ext1_CL(const cat021_item040_ext1 *item);

/**
 * @brief Get the Field Extension (FX) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of FX (0: end of item, 1: second extension present)
 */
ASTERIX_API uint8_t get_cat021_item040_ext1_FX(const cat021_item040_ext1 *item);

/* ============================ SECOND EXTENSION ============================ */

/**
 * @brief Get the List Lookup Check (LL) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the LL bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of LL (0: default,
 *                              1: Target is suspect)
 */
ASTERIX_API uint8_t get_cat021_item040_ext2_LLC(const cat021_item040_ext2 *item);

/**
 * @brief Get the Independent Position Check (IP) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the IP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of IP (0: default,
 *                              1: Independent Position Check failed)
 */
ASTERIX_API uint8_t get_cat021_item040_ext2_IPC(const cat021_item040_ext2 *item);

/**
 * @brief Get the No-go Bit Status (NO) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the NO bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of NO (0: NOGO-bit not set,
 *                              1: NOGO-bit set)
 */
ASTERIX_API uint8_t get_cat021_item040_ext2_NOGO(const cat021_item040_ext2 *item);

/**
 * @brief Get the Compact Position Reporting (CP) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the CP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of CP (0: CPR Validation correct),
 *                              1: CPR Validation failed)
 */
ASTERIX_API uint8_t get_cat021_item040_ext2_CPR(const cat021_item040_ext2 *item);

/**
 * @brief Get the Local Decoding Position Jump (LD) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the LD bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of LD (0: LDPJ not detected,
 *                              1: LDPJ detected)
 */
ASTERIX_API uint8_t get_cat021_item040_ext2_LDPJ(const cat021_item040_ext2 *item);

/**
 * @brief Get the Range Check (RCF) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the RCF bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of RCF (0: default,
 *                              1: Range Check failed)
 */
ASTERIX_API uint8_t get_cat021_item040_ext2_RCF(const cat021_item040_ext2 *item);

/**
 * @brief Get the Field Extension (FX) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of FX (0: end of item, 1: third extension present)
 */
ASTERIX_API uint8_t get_cat021_item040_ext2_FX(const cat021_item040_ext2 *item);

/* ============================ THIRD EXTENSION ============================  */

/**
 * @brief Get the raw Total Bits Corrected (TBC) from CAT 021 Item 040 Third Extension.
 * 
 * Portable access to the TBC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext3 structure.
 * @return uint8_t Raw value of TBC (bit-8 TBC_EP, bits-7/2 TBC_VAL)
 */
ASTERIX_API uint8_t get_cat021_item040_ext3_TBC(const cat021_item040_ext3 *item);

/**
 * @brief Get the TBC Element populated (TBC_EP) from CAT 021 Item 040 Third Extension.
 * 
 * Portable access to the TBC_EP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext3 structure.
 * @return uint8_t Value of TBC_EP (0: element not populated, 1: element populated)
 */
ASTERIX_API uint8_t get_cat021_item040_ext3_TBC_EP(const cat021_item040_ext3 *item);

/**
 * @brief Get the TBC Value (TBC_VAL) from CAT 021 Item 040 Third Extension.
 * 
 * Portable access to the TBC_VAL bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext3 structure.
 * @return uint8_t Value of TBC_VAL
 */
ASTERIX_API uint8_t get_cat021_item040_ext3_TBC_VAL(const cat021_item040_ext3 *item);

/**
 * @brief Get the Field Extension (FX) from CAT 021 Item 040 Third Extension.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext3 structure.
 * @return uint8_t Value of FX (0: end of item, 1: fourth extension present)
 */
ASTERIX_API uint8_t get_cat021_item040_ext3_FX(const cat021_item040_ext3 *item);

/* ============================ FOURTH EXTENSION ============================ */

/**
 * @brief Get the raw Maximum Bits Corrected (MBC) from CAT 021 Item 040 Fourth Extension.
 * 
 * Portable access to the MBC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext4 structure.
 * @return uint8_t Raw value of MBC (bit-8 MBC_EP, bits-7/2 MBC_VAL)
 */
ASTERIX_API uint8_t get_cat021_item040_ext4_MBC(const cat021_item040_ext4 *item);

/**
 * @brief Get the MBC Element populated (MBC_EP) from CAT 021 Item 040 Fourth Extension.
 * 
 * Portable access to the MBC_EP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext4 structure.
 * @return uint8_t Value of MBC_EP (0: element not populated, 1: element populated)
 */
ASTERIX_API uint8_t get_cat021_item040_ext4_MBC_EP(const cat021_item040_ext4 *item);

/**
 * @brief Get the MBC Value (MBC_VAL) from CAT 021 Item 040 Fourth Extension.
 * 
 * Portable access to the MBC_VAL bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext4 structure.
 * @return uint8_t Value of MBC_VAL
 */
ASTERIX_API uint8_t get_cat021_item040_ext4_MBC_VAL(const cat021_item040_ext4 *item);

/**
 * @brief Get the Field Extension (FX) from CAT 021 Item 040 Fourth Extension.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext4 structure.
 * @return uint8_t Value of FX (0: end of item, 1: extension present)
 */ASTERIX_API uint8_t get_cat021_item040_ext4_FX(const cat021_item040_ext4 *item);


/*******************************************************************************
 * Setters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

/**
 * @brief Set the Address Type (ATP) in CAT 021 Item 040.
 * 
 * Modifies the ATP bits (bits 8-6) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @param value New ATP value (0 to 7).
 */
ASTERIX_API void set_cat021_item040_ATP(cat021_item040 *item, uint8_t value);

/**
 * @brief Set the Altitude Reporting Capability (ARC) in CAT 021 Item 040.
 * 
 * Modifies the ARC bits (bits 5-4) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @param value New ARC value (0 to 3).
 */
ASTERIX_API void set_cat021_item040_ARC(cat021_item040 *item, uint8_t value);

/**
 * @brief Set the Range Check (RC) in CAT 021 Item 040.
 * 
 * Modifies the RC bits (bit 3) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @param value New RC value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_RC(cat021_item040 *item, uint8_t value);

/**
 * @brief Set the Report Type (RAB) in CAT 021 Item 040.
 * 
 * Modifies the RAB bits (bit 2) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @param value New RAB value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_RAB(cat021_item040 *item, uint8_t value);

/**
 * @brief Set the Field Extension (FX) in CAT 021 Item 040.
 * 
 * Modifies the FX bits (bit 1) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @param value New FX value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_FX(cat021_item040 *item, uint8_t value);

/* === FIRST EXTENSION === */

/**
 * @brief Set the Differential Correction (DCR) in CAT 021 Item 040 First extension.
 * 
 * Modifies the DCR bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @param value New DCR value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext1_DCR(cat021_item040_ext1 *item, uint8_t value);

/**
 * @brief Set the Ground Bit Setting (GBS) in CAT 021 Item 040 First extension.
 * 
 * Modifies the GBS bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @param value New GBS value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext1_GBS(cat021_item040_ext1 *item, uint8_t value);

/**
 * @brief Set the Simulated Target (SIM) in CAT 021 Item 040 First extension.
 * 
 * Modifies the SIM bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @param value New SIM value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext1_SIM(cat021_item040_ext1 *item, uint8_t value);

/**
 * @brief Set the Test Target (TST) in CAT 021 Item 040 First extension.
 * 
 * Modifies the TST bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @param value New TST value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext1_TST(cat021_item040_ext1 *item, uint8_t value);

/**
 * @brief Set the Selected Altitude Available (SAA) in CAT 021 Item 040 First extension.
 * 
 * Modifies the SAA bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @param value New SAA value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext1_SAA(cat021_item040_ext1 *item, uint8_t value);

/**
 * @brief Set the Confidence Level (CL) in CAT 021 Item 040 First extension.
 * 
 * Modifies the CL bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @param value New CL value (0 to 3).
 */
ASTERIX_API void set_cat021_item040_ext1_CL(cat021_item040_ext1 *item, uint8_t value);

/**
 * @brief Set the Field Extension (FX) in CAT 021 Item 040 First extension.
 * 
 * Modifies the FX bits (bits X) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @param value New FX value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext1_FX(cat021_item040_ext1 *item, uint8_t value);

/* ============================ SECOND EXTENSION ============================ */

/**
 * @brief Set the List Lookup Check (LLC) in CAT 021 Item 040 Second extension.
 * 
 * Modifies the LLC bits (bit 7) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @param value New LLC value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext2_LLC(cat021_item040_ext2 *item, uint8_t value);

/**
 * @brief Set the Independent Position Check (IPC) in CAT 021 Item 040 Second extension.
 * 
 * Modifies the IPC bits (bit 6) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @param value New IPC value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext2_IPC(cat021_item040_ext2 *item, uint8_t value);

/**
 * @brief Set the No-go Bit Status (NOGO) in CAT 021 Item 040 Second extension.
 * 
 * Modifies the NOGO bits (bit 5) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @param value New NOGO value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext2_NOGO(cat021_item040_ext2 *item, uint8_t value);

/**
 * @brief Set the Compact Position Reporting (CPR) in CAT 021 Item 040 Second extension.
 * 
 * Modifies the CPR bits (bit 4) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @param value New CPR value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext2_CPR(cat021_item040_ext2 *item, uint8_t value);

/**
 * @brief Set the Local Decoding Position Jump (LDPJ) in CAT 021 Item 040 Second extension.
 * 
 * Modifies the LDPJ bits (bit 3) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @param value New LDPJ value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext2_LDPJ(cat021_item040_ext2 *item, uint8_t value);

/**
 * @brief Set the Range Check (RCF) in CAT 021 Item 040 Second extension.
 * 
 * Modifies the RCF bits (bit 2) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @param value New RCF value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext2_RCF(cat021_item040_ext2 *item, uint8_t value);

/**
 * @brief Set the Field Extension (FX) in CAT 021 Item 040 Second extension.
 * 
 * Modifies the FX bits (bit 1) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @param value New FX value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext2_FX(cat021_item040_ext2 *item, uint8_t value);

/* ============================ THIRD EXTENSION ============================  */

/**
 * @brief Set the Total Bits Corrected (TBC) in CAT 021 Item 040 Third extension.
 * 
 * Modifies the TBC bits (bits 8-2) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext3 structure.
 * @param value New TBC value.
 */
ASTERIX_API void set_cat021_item040_ext3_TBC(cat021_item040_ext3 *item, uint8_t value);

/**
 * @brief Set the TBC Element populated (TBC_EP) in CAT 021 Item 040 Third extension.
 * 
 * Modifies the TBC_EP bits (bit 8) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext3 structure.
 * @param value New TBC_EP value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext3_TBC_EP(cat021_item040_ext3 *item, uint8_t value);

/**
 * @brief Set the TBC Value (TBC_VAL) in CAT 021 Item 040 Third extension.
 * 
 * Modifies the TBC_VAL bits (bits 7-2) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext3 structure.
 * @param value New TBC_VAL value.
 */
ASTERIX_API void set_cat021_item040_ext3_TBC_VAL(cat021_item040_ext3 *item, uint8_t value);

/**
 * @brief Set the Field Extension (FX) in CAT 021 Item 040 Third extension.
 * 
 * Modifies the FX bits (bit 1) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext3 structure.
 * @param value New FX value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext3_FX(cat021_item040_ext3 *item, uint8_t value);

/* ============================ FOURTH EXTENSION ============================ */

/**
 * @brief Set the Maximum Bits Corrected (MBC) in CAT 021 Item 040 Fourth extension.
 * 
 * Modifies the MBC bits (bits 8-2) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext4 structure.
 * @param value New MBC value.
 */
ASTERIX_API void set_cat021_item040_ext4_MBC(cat021_item040_ext4 *item, uint8_t value);

/**
 * @brief Set the MBC Element populated (MBC_EP) in CAT 021 Item 040 Fourth extension.
 * 
 * Modifies the MBC_EP bits (bit 8) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext4 structure.
 * @param value New MBC_EP value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext4_MBC_EP(cat021_item040_ext4 *item, uint8_t value);

/**
 * @brief Set the MBC Value (MBC_VAL) in CAT 021 Item 040 Fourth extension.
 * 
 * Modifies the MBC_VAL bits (bits 7-2) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext4 structure.
 * @param value New MBC_VAL value.
 */
ASTERIX_API void set_cat021_item040_ext4_MBC_VAL(cat021_item040_ext4 *item, uint8_t value);

/**
 * @brief Set the Field Extension (FX) in CAT 021 Item 040 Fourth extension.
 * 
 * Modifies the FX bits (bit 1) using a safe bitmask operation.
 * 
 * @param item Pointer to cat021_item040_ext4 structure.
 * @param value New FX value (0 or 1).
 */
ASTERIX_API void set_cat021_item040_ext4_FX(cat021_item040_ext4 *item, uint8_t value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Count the number of extensions present in the CAT 021 Item 040.
 * 
 * Evaluates each FX bit to determine the number of present extensions.
 * 
 * @param item Pointer to the main cat021_item040 structure.
 * 
 * @return uint8_t Number of present extensions (0 to 4).
 */
ASTERIX_API uint8_t count_cat021_item040_extensions(const cat021_item040 *item);

/**
 * @brief Print the contents of CAT 021 / Item 040 including its extensions.
 *
 * This function prints the values of the main byte and each extension
 * (if present according to the FX bits) to the standard output.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a cat021_item040 structure.
 */
ASTERIX_API void print_cat021_item040(const cat021_item040 *item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM040_H */
