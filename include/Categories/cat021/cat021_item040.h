/**
 * @file cat021_item040.h
 * @brief Definition of item 040 of CAT 021, and related functions and values
 */

#ifndef cat021_item040_H
#define cat021_item040_H

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
 * Function headers
 ******************************************************************************/

ASTERIX_API uint8_t get_cat021_item040_ATP(const cat021_item040 *item);
ASTERIX_API uint8_t get_cat021_item040_ARC(const cat021_item040 *item);
ASTERIX_API uint8_t get_cat021_item040_RC(const cat021_item040 *item);
ASTERIX_API uint8_t get_cat021_item040_RAB(const cat021_item040 *item);
ASTERIX_API uint8_t get_cat021_item040_FX(const cat021_item040 *item);
ASTERIX_API uint8_t get_cat021_item040_ext1_DCR(const cat021_item040_ext1 *item);
ASTERIX_API uint8_t get_cat021_item040_ext1_GBS(const cat021_item040_ext1 *item);
ASTERIX_API uint8_t get_cat021_item040_ext1_SIM(const cat021_item040_ext1 *item);
ASTERIX_API uint8_t get_cat021_item040_ext1_TST(const cat021_item040_ext1 *item);
ASTERIX_API uint8_t get_cat021_item040_ext1_SAA(const cat021_item040_ext1 *item);
ASTERIX_API uint8_t get_cat021_item040_ext1_CL(const cat021_item040_ext1 *item);
ASTERIX_API uint8_t get_cat021_item040_ext1_FX(const cat021_item040_ext1 *item);
ASTERIX_API uint8_t get_cat021_item040_ext2_LLC(const cat021_item040_ext2 *item);
ASTERIX_API uint8_t get_cat021_item040_ext2_IPC(const cat021_item040_ext2 *item);
ASTERIX_API uint8_t get_cat021_item040_ext2_NOGO(const cat021_item040_ext2 *item);
ASTERIX_API uint8_t get_cat021_item040_ext2_CPR(const cat021_item040_ext2 *item);
ASTERIX_API uint8_t get_cat021_item040_ext2_LDPJ(const cat021_item040_ext2 *item);
ASTERIX_API uint8_t get_cat021_item040_ext2_RCF(const cat021_item040_ext2 *item);
ASTERIX_API uint8_t get_cat021_item040_ext2_FX(const cat021_item040_ext2 *item);
ASTERIX_API uint8_t get_cat021_item040_ext3_TBC(const cat021_item040_ext3 *item);
ASTERIX_API uint8_t get_cat021_item040_ext3_TBC_EP(const cat021_item040_ext3 *item);
ASTERIX_API uint8_t get_cat021_item040_ext3_TBC_VAL(const cat021_item040_ext3 *item);
ASTERIX_API uint8_t get_cat021_item040_ext3_FX(const cat021_item040_ext3 *item);
ASTERIX_API uint8_t get_cat021_item040_ext4_MBC(const cat021_item040_ext4 *item);
ASTERIX_API uint8_t get_cat021_item040_ext4_MBC_EP(const cat021_item040_ext4 *item);
ASTERIX_API uint8_t get_cat021_item040_ext4_MBC_VAL(const cat021_item040_ext4 *item);
ASTERIX_API uint8_t get_cat021_item040_ext4_FX(const cat021_item040_ext4 *item);

ASTERIX_API void print_cat021_item040(const cat021_item040 *item)


#ifdef __cplusplus
}
#endif

#endif /* cat021_item040_H */