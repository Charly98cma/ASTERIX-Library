/**
 * @file I021_RE.h
 * @brief Definition of item RE of CAT 021, and related functions and values
 */

#ifndef I021_RE_H
#define I021_RE_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_RE_LSB_BSP         (0.1)           /// LSB = 0.1 hPa
#define I021_RE_LSB_SELH        (0.703125)
#define I021_RE_LSB_GAO_LAT     (2.0)           /// LSB = 2 meters
#define I021_RE_LSB_GAO_LON     (2.0)           /// LSB = 2 meters
#define I021_RE_LSB_SGV_GSS     (0.125)         /// LSB = 0.125 knots
#define I021_RE_LSB_SGV_HGT     (2.8125)        /// LSB = 2.8125 degrees
#define I021_RE_LSB_TNH         (360.0/P2_14)   /// LSB = 360/2^14 degrees

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

typedef struct I021_RE_FSPEC {
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
             * @brief Barometric Pressure Setting presence
             * 
             * 0: not present; 1: present
             */
            uint8_t BPS             :1;
            /**
             * @brief Selected Heading presence presence
             * 
             * 0: not present; 1: present
             */
            uint8_t SELH            :1;
            /**
             * @brief Navigation Mode presence
             * 
             * 0: not present; 1: present
             */
            uint8_t NAV             :1;
            /**
             * @brief GPS Antenna Offset presence
             * 
             * 0: not present; 1: present
             */
            uint8_t GAO             :1;
            /**
             * @brief Surface Ground Vector presence
             * 
             * 0: not present; 1: present
             */
            uint8_t SGV             :1;
            /**
             * @brief Aircraft Status Informatio presence
             * 
             * 0: not present; 1: present
             */
            uint8_t STA             :1;
            /**
             * @brief True North Headin presence
             * 
             * 0: not present; 1: present
             */
            uint8_t TNH             :1;
            /**
             * @brief Military Extended Squitter presence
             * 
             * 0: not present; 1: present
             */
            uint8_t MES             :1;
        };
    };
} I021_RE_FSPEC;

/**
 * @brief Barometric Pressure Setting (LSB = 0.1 hPa)
 * 
 * Range: 0 <= BPS <= 409.5 hPa
 * 
 * @note 1. BPS is the barometric pressure setting of the aircraft
 *          minus 800 hPa.
 * @note 2. A value of "0" indicates that in the aircraft a value of
 *          800 hPa or less has been selected
 * @note 3. A value of "409.5" indicates that in the aircraft a
 *          value of 1209.5 hPa or more has been selected
 */
typedef struct I021_RE_BPS {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bits-16/13 set to 0
            uint16_t spare_1        :4;
            /// @brief Barometric Preassure Setting
            uint16_t BPS            :12;
        };
    };
} I021_RE_BPS;

/**
 * @brief Selected Heading (LSB = 0.703125)
 * 
 * @note On many aircraft, the ADS-B Transmitting Subsystem receives 
 * Selected Heading from a Mode Control Panel / Flight Control Unit 
 * (MCP / FCU).  Users of this data are cautioned that the Selected 
 * Heading value transmitted by the ADS-B Transmitting Subsystem 
 * does not necessarily reflect the true intention of the airplane during 
 * certain flight modes (e.g., during LNAV mode).
 */
typedef struct I021_RE_SELH {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bits-16/13 set t0 0
            uint16_t spare          :4;
            /// @brief Horizontal Ref. Dir. (0: True North; 1: Magnetic North)
            uint16_t HRD            :1;
            /// @brief SELH Status (0: data unavail./invalid; 1: data avail./valid)
            uint16_t STAT           :1;
            /// @brief  Selected Heading
            uint16_t SELH           :10;
        };
    };
} I021_RE_SELH;

/**
 * @brief Navigation Mode
 * 
 * @note 1. The status of the LNAV indication is contained in Data Item I021/200,
 *          bit-7. Please also consider Note 2 to Data Item I021/200. 
 * @note 2. MFM (Status of MCP/FCU Mode Bits) is contained in the Target 
 *          State and Status Message (Register 6216, Format Type Code 29,
 *          Subtype Code 1) as defined in EUROCAE ED-102B/RTCA DO-260C 
 *          Ref. chapter 2.2.3.2.7.1.3.11. If set to "1", MFM#VAL indicates that 
 *          the bits for "AP", "VN", "AH", "AM" (in I021/REF/NAV) and for LNAV
 *          (in I021/200) have been actively populated. 
 * @note 3. If MFM#VAL = 0, AP, VN, AH, and AM (in I021/REF/NAV) shall be 
 *          set to 0 and LNAV (in I021/200) shall be set to 1.
 */
typedef struct I021_RE_NAV {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Autopilot engaged (0: false; 1: true)
            uint8_t AP              :1;
            /// @brief Vertical NAVigation Active
            uint8_t VN              :1;
            /// @brief Altitude Hold engaged
            uint8_t AH              :1;
            /// @brief Approach Mode active
            uint8_t AM              :1;
            /// @brief Status of MCP/FCU Mode bits
            uint8_t MFM             :2;
            /// @brief Spare bits-2/1 set to 0
            uint8_t spare           :2;
        };
    };
} I021_RE_NAV;

/**
 * @brief GPS Antenna Offset
 */
typedef struct I021_RE_GAO {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Lateral axis GAO
            uint8_t LATERAL         :3;
            /// @brief Longitudinal axis GAO
            uint8_t LONGITUDINAL    :5;
        };
    };
} I021_RE_GAO;

/**
 * @brief Heading/Ground Tracking information
 */
typedef struct I021_RE_SGV_EXT1 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Heading/ground Track info. (LSB = 2.8125)
            uint8_t HGT             :7;
            /// @brief Field extension (0: no extension; 1: next field present)
            uint8_t FX              :1;
        };
    };
} I021_RE_SGV_EXT1;

/**
 * @brief Surface Ground Vector
 * 
 * Ground Speed and Track Angle elements of the Surface Ground Vector
 */
typedef struct I021_RE_SGV {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief A/C stopped (0: not stopped; 1: stopped)
            uint16_t STP            :1;
            /// @brief Heading/Ground Track validity (0: not valid; 1: valid)
            uint16_t HTS            :1;
            /// @brief Heading/Ground Track provided (0: Heading; 1: Ground Track)
            uint16_t HTT            :1;
            /// @brief Heading (0: True North; 1: Magnetic North)
            uint16_t HRD            :1;
            /// @brief Ground Speed (LSB = 0.125 knots)
            uint16_t GSS            :11;
            /// @brief Field extension (0: no extension; 1: next field present)
            uint16_t FX             :1;
        };
    };
    /// @brief First extension
    I021_RE_SGV_EXT1 ext1;
} I021_RE_SGV;

/**
 * @brief Additional Target Characteristics 1
 */
typedef struct I021_RE_STA_EXT1 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Priority Status for Version 3 ADS-B Systems
            uint8_t PS3             :4;
            /// @brief Transmit Power
            uint8_t TPW             :3;
            /// @brief Field Extension (0: end of data item; 1: next extension)
            uint8_t FX              :1;
        };
    };
} I021_RE_STA_EXT1;

/**
 * @brief Additional Target Characteristics 2
 */
typedef struct I021_RE_STA_EXT2 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Transponder Side Indication
            uint8_t TSI             :3;
            /// @brief Manned / Unmanned Operation
            uint8_t MUO             :2;
            /// @brief Remain Well Clear Corrective Alert
            uint8_t RWC             :2;
            /// @brief Field Extension (0: end of data item; 1: next extension)
            uint8_t FX              :1;
        };
    };
} I021_RE_STA_EXT2;

/**
 * @brief Additional Target Characteristics 3
 */
typedef struct I021_RE_STA_EXT3 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Detect and Avoid Capabilities
            uint8_t DAA             :3;
            /// @brief Transponder Capability
            uint8_t DF17CA          :4;
            /// @brief Field Extension (0: end of data item; 1: next extension)
            uint8_t FX              :1;
        };
    };
} I021_RE_STA_EXT3;

/**
 * @brief Collision Avoidance Capabilities
 */
typedef struct I021_RE_STA_EXT4 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Sense Vertical & Horizontal
            uint8_t SVH             :3;
            /// @brief CAS Type & Capability
            uint8_t CATC            :4;
            /// @brief Field Extension (0: end of data item; 1: next extension)
            uint8_t FX              :1;
        };
    };
} I021_RE_STA_EXT4;

/**
 * @brief Additional Target Characteristics 4
 */
typedef struct I021_RE_STA_EXT5 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Transponder Antenna Offset
            uint8_t TAO             :4;
            /// @brief Spare bit-2 set to 0
            uint8_t spare           :1;
            /// @brief Field Extension (0: end of data item; 1: next extension)
            uint8_t FX              :1;
        };
    };
} I021_RE_STA_EXT5;

/**
 * @brief Aircraft Status Information
 * 
 * This item contains information on the status of a target.
 */
typedef struct I021_RE_STA {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief ES IN Capability (0: capable; 1: not capable)
            uint8_t ES              :1;
            /// @brief UAT IN Capability (0: capable; 1: not capable)
            uint8_t UAT             :1;
            /// @brief Reduced Capability Equipment
            uint8_t RCE             :3;
            /// @brief Reply Rate Limiting
            uint8_t RRL             :2;
            /// @brief Field Extension (0: end of data item; 1: next extension)
            uint8_t FX              :1;
        };
    };
    /// @brief
    I021_RE_STA_EXT1 ext1;
    /// @brief
    I021_RE_STA_EXT2 ext2;
    /// @brief
    I021_RE_STA_EXT3 ext3;
    /// @brief
    I021_RE_STA_EXT4 ext4;
    /// @brief
    I021_RE_STA_EXT5 ext5;
} I021_RE_STA;

/**
 * @brief True North Heading
 * 
 * True North Heading (Element of Air Vector)
 * 
 * LSB = 360 degrees / 2^16
 * 
 * @note Magnetic Heading is defined in I021/152
 */
typedef struct I021_RE_TNH {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief True North Heading
            uint16_t TNH;
        };
    };
} I021_RE_TNH;

/** @brief Mode 5 Summary
 * 
 * @note 1. The flag M2 refers to the contents of Subfield #6 below, M3, MC 
 *          refer to the contents of data items I021/070 and I021/145
 *          respectively. The flag M1 refers to the contents of Subfield #3
 *          below (Extended Mode 1 Code in Octal Representation).
 * @note 2. If a Mode 5 reply/report is received with the Emergency bit set,
 *          then the Military Emergency bit (ME) in Data Item I021/200,
 *          Target Status, shall be set.
 * @note 3. If a Mode 5 reply/report is received with the Identification of
 *          Position bit set, then the Special Position Identification bit
 *          (SPI) in Data Item I021/200, Target Status, shall be set.
 * @note 4. If a Mode 5 report (ID or Data) is received and fulfils the
 *          authentication criteria the corresponding authentication bit shall
 *          be set.
 * 
 */
typedef struct I021_RE_MES_EXT1 {
        union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Mode 5 interrogation (0: No; 1: Yes)
            uint8_t M5              :1;
            /// @brief Authenticated Mode 5 ID Reply/Report (0: No; 1: Yes)
            uint8_t ID              :1;
            /// @brief Authenticated Mode 5 Data Reply/Report (0: No; 1: Yes)
            uint8_t DA              :1;
            /// @brief Mode 1 Code from M5 Reply/report (0: No; 1: Yes)
            uint8_t M1              :1;
            /// @brief Mode 2 Code from M5 Reply/report (0: No; 1: Yes)
            uint8_t M2              :1;
            /// @brief Mode 3 Code from M5 Reply/report (0: No; 1: Yes)
            uint8_t M3              :1;
            /// @brief FL from M5 Reply/report (0: No; 1: Yes)
            uint8_t MC              :1;
            /// @brief Position from M5 Reply/report (0: No; 1: Yes)
            uint8_t PO              :1;
        };
    };
} I021_RE_MES_EXT1;

/// @brief Mode 5 PIN / National Origin
typedef struct I021_RE_MES_EXT2 {
        union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[4];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bits-32/31 set to 0
            uint32_t spare_1        :2;
            /// @brief PIN Code
            uint32_t PIN            :14;
            /// @brief Spare bits-32/31 set to 0
            uint32_t spare_2        :5;
            /// @brief National Origin Code
            uint32_t NO             :11;
        };
    };
} I021_RE_MES_EXT2;

/**
 * @brief Extended Mode 1 Code in Octal Representation
 * 
 * @note 1. If Subfield #1 is present, the M1 bit in Subfield #1 indicates
 *          whether the Extended Mode 1 Code is from a Mode 5 reply or a Mode 1
 *          reply.If Subfield #1 is not present, the Extended Mode 1 Code is
 *          from a Mode 1 reply.
 * @note 2. If Subfield #3 is not present the Mode 1 Code was not reported or
 *          all Code Bits were equal to 0.
 * @note 3. The valid bit is set if the Code was only reported once for
 *          that target.
 */
typedef struct I021_RE_MES_EXT3 {
        union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Code validity (0: valid; 1: invalid)
            uint16_t V              :1;
            /// @brief Spare bit-15 set to 0
            uint16_t spare_1        :1;
            /// @brief Mode 1 Code origin (0: report of TXP; 1: provided by local tracker)
            uint16_t L              :1;
            /// @brief Spare bit-14 set to 0
            uint16_t spare_2        :1;
            uint16_t A4             :1;
            uint16_t A2             :1;
            uint16_t A1             :1;
            uint16_t B4             :1;
            uint16_t B2             :1;
            uint16_t B1             :1;
            uint16_t C4             :1;
            uint16_t C2             :1;
            uint16_t C1             :1;
            uint16_t D4             :1;
            uint16_t D2             :1;
            uint16_t D1             :1;
        };
    };
} I021_RE_MES_EXT3;

/**
 * @brief X Pulse Reference
 * 
 * @note NOTES to Subfield #4 (X Pulse Presence): Within Mode 5 reports, the
 *       X-Pulse can be set for the following cases:
 * @note 1. In a combined Mode 1 and Mode 2 report: in this case the X5 bit and
 *       the X2 bit shall be set;
 * @note 2. In a combined Mode 3 and Mode C report: in this case the X5 bit and
 *       the X3 bit shall be set;
 * @note 3. In a Mode 5 PIN data report: in this case the X5 bit and the XP bit
 *       shall be set.
 * @note The X1 bit and the XC bit are meaningless as in Mode 1 and Mode C 
 *       replies/reports the X Pulse is not defined.  They are kept for 
 *       compatibility reasons.
 */
typedef struct I021_RE_MES_EXT4 {
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
            /// @brief X-Pulse from M5 Pin Reply/Report (0: not present; 1: present)
            uint8_t XP              :1;
            /// @brief X-Pulse from M5 Data Reply/Report (0: not present or set to 0; 1: present)
            uint8_t X5              :1;
            /// @brief X-Pulse from MC Reply (0: not present or set to 0; 1: present)
            uint8_t XC              :1;
            /// @brief X-Pulse from M3/A Reply (0: not present or set to 0; 1: present)
            uint8_t X3              :1;
            /// @brief X-Pulse from M2 Reply (0: not present or set to 0; 1: present)
            uint8_t X2              :1;
            /// @brief X-Pulse from M1 Reply (0: not present or set to 0; 1: present)
            uint8_t X1              :1;
        };
    };
} I021_RE_MES_EXT4;

/// @brief Figure of Merit
typedef struct I021_RE_MES_EXT5 {
        union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bits-8/6 set to 0
            uint8_t spare           :3;
            /** 
             * @brief Figure of Merit
             * 
             * Position Accuracy as extracted and provided by a Mode 5 TXP
             */
            uint8_t FOM             :5;
        };
    };
} I021_RE_MES_EXT5;

/**
 * @brief Mode 2 Code in Octal Representatio
 * 
 * @note If Subfield 6 is not present the Mode 2 Code was no reported or all 
 *       Code Bits were equal to 0.
 */
typedef struct I021_RE_MES_EXT6 {
        union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Code validity (0: valid; 1: invalid)
            uint16_t V              :1;
            /// @brief Spare bit-15 set to 0
            uint16_t spare_1        :1;
            /// @brief Mode 2 Code origin (0: report of TXP; 1: provided by local tracker)
            uint16_t L              :1;
            /// @brief Spare bit-14 set to 0
            uint16_t spare_2        :1;
            uint16_t A4             :1;
            uint16_t A2             :1;
            uint16_t A1             :1;
            uint16_t B4             :1;
            uint16_t B2             :1;
            uint16_t B1             :1;
            uint16_t C4             :1;
            uint16_t C2             :1;
            uint16_t C1             :1;
            uint16_t D4             :1;
            uint16_t D2             :1;
            uint16_t D1             :1;
        };
    };
} I021_RE_MES_EXT6;

/**
 * @brief Military Extended Squitter
 * 
 * Contents of Extended Squitters transmitted by Military Aircraft
 * 
 * @note The information contained in this data item is specific to 
 * 1090MHz Extended Squitter messages transmitted by military 
 * aircraft (Mode 5 Level 2 squitter).
 */
typedef struct I021_RE_MES {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief M5 Summary Subfield #1 presence (0: absence; 1: presence)
            uint8_t SUM             :1;
            /// @brief Mode 5 PIN/NO Subfield #2 presence (0: absence; 1: presence)
            uint8_t PNO             :1;
            /// @brief Extended M1 Code in Octal Representation Subfield #3 presence (0: absence; 1: presence)
            uint8_t EM1             :1;
            /// @brief X Pulse Presence Subfield #4 presence (0: absence; 1: presence)
            uint8_t XP              :1;
            /// @brief Figure of Merit Subfield #5 presence (0: absence; 1: presence)
            uint8_t FOM             :1;
            /// @brief M2 Code Subfield #6 presence (0: absence; 1: presence)
            uint8_t M2              :1;
            /// @brief Spare bit-3 set to 0
            uint8_t spare           :1;
            /// @brief Field extension (0: no extension; 1: next field present)
            uint8_t FX              :1;
        };
    };
    /// @brief Subfield #1
    I021_RE_MES_EXT1 ext1;
    /// @brief Subfield #2
    I021_RE_MES_EXT2 ext2;
    /// @brief Subfield #3
    I021_RE_MES_EXT3 ext3;
    /// @brief Subfield #4
    I021_RE_MES_EXT4 ext4;
    /// @brief Subfield #5
    I021_RE_MES_EXT5 ext5;
    /// @brief Subfield #6
    I021_RE_MES_EXT6 ext6;
} I021_RE_MES;

typedef struct I021_RE {
    /**
     * @brief Length Indicator
     * 
     * This field indicates the total length in octets of the Reserved
     * Expansion Field (including the REF length indicator itself)
     */
    uint8_t LEN;
    /**
     * @brief Items Indicator
     * 
     * This field indicates what are the items encoded in the REF
     */
    I021_RE_FSPEC FSPEC;
    /// @brief Barometris Pressure Setting
    I021_RE_BPS BPS;
    /// @brief Selected Heading
    I021_RE_SELH SELH;
    /// @brief Navigation Mode
    I021_RE_NAV NAV;
    /// @brief GPS Antenna Offset
    I021_RE_GAO GAO;
    /// @brief Surface Ground Vector
    I021_RE_SGV SGV;
    /// @brief Aircraft Status Information
    I021_RE_STA STA;
    /// @brief True North Heading
    I021_RE_TNH TNH;
    /// @brief Military Extended Squitter
    I021_RE_MES MES;
} I021_RE;

/*******************************************************************************
 * Getters
 ******************************************************************************/

ASTERIX_API uint8_t get_I021_RE_LEN(const I021_RE * item);
ASTERIX_API uint8_t get_I021_RE_FSPEC_raw(const I021_RE * item);
ASTERIX_API uint8_t get_I021_RE_FSPEC_BPS(const I021_RE * item);
ASTERIX_API uint8_t get_I021_RE_FSPEC_SELH(const I021_RE * item);
ASTERIX_API uint8_t get_I021_RE_FSPEC_NAV(const I021_RE * item);
ASTERIX_API uint8_t get_I021_RE_FSPEC_GAO(const I021_RE * item);
ASTERIX_API uint8_t get_I021_RE_FSPEC_SGV(const I021_RE * item);
ASTERIX_API uint8_t get_I021_RE_FSPEC_STA(const I021_RE * item);
ASTERIX_API uint8_t get_I021_RE_FSPEC_TNH(const I021_RE * item);
ASTERIX_API uint8_t get_I021_RE_FSPEC_MES(const I021_RE * item);
ASTERIX_API double get_I021_RE_BPS(const I021_RE_BPS * item);
ASTERIX_API uint8_t get_I021_RE_SELH_HRD(const I021_RE_SELH * item);
ASTERIX_API uint8_t get_I021_RE_SELH_STAT(const I021_RE_SELH * item);
ASTERIX_API double get_I021_RE_SELH_SELH(const I021_RE_SELH * item);
ASTERIX_API uint8_t get_I021_RE_NAV_AP(const I021_RE_NAV * item);
ASTERIX_API uint8_t get_I021_RE_NAV_VN(const I021_RE_NAV * item);
ASTERIX_API uint8_t get_I021_RE_NAV_AH(const I021_RE_NAV * item);
ASTERIX_API uint8_t get_I021_RE_NAV_AM(const I021_RE_NAV * item);
ASTERIX_API uint8_t get_I021_RE_NAV_MFM(const I021_RE_NAV * item);
ASTERIX_API uint8_t get_I021_RE_GAO_LAT(const I021_RE_GAO * item);
ASTERIX_API uint8_t get_I021_RE_GAO_LON(const I021_RE_GAO * item);
ASTERIX_API uint8_t get_I021_RE_SGV_STP(const I021_RE_SGV * item);
ASTERIX_API uint8_t get_I021_RE_SGV_HTS(const I021_RE_SGV * item);
ASTERIX_API uint8_t get_I021_RE_SGV_HTT(const I021_RE_SGV * item);
ASTERIX_API uint8_t get_I021_RE_SGV_HRD(const I021_RE_SGV * item);
ASTERIX_API double get_I021_RE_SGV_GSS(const I021_RE_SGV * item);
ASTERIX_API uint8_t get_I021_RE_SGV_FX(const I021_RE_SGV * item);
ASTERIX_API double get_I021_RE_SGV_EXT1_HGT(const I021_RE_SGV_EXT1 * item);
ASTERIX_API uint8_t get_I021_RE_SGV_EXT1_FX(const I021_RE_SGV_EXT1 * item);
ASTERIX_API uint8_t get_I021_RE_STA_ES(const I021_RE_STA * item);
ASTERIX_API uint8_t get_I021_RE_STA_UAT(const I021_RE_STA * item);
ASTERIX_API uint8_t get_I021_RE_STA_RCE(const I021_RE_STA * item);
ASTERIX_API uint8_t get_I021_RE_STA_RRL(const I021_RE_STA * item);
ASTERIX_API uint8_t get_I021_RE_STA_FX(const I021_RE_STA * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT1_PS3(const I021_RE_STA_EXT1 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT1_RRL(const I021_RE_STA_EXT1 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT1_FX(const I021_RE_STA_EXT1 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT2_TSI(const I021_RE_STA_EXT2 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT2_MUO(const I021_RE_STA_EXT2 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT2_RWC(const I021_RE_STA_EXT2 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT2_FX(const I021_RE_STA_EXT2 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT3_DAA(const I021_RE_STA_EXT3 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT3_DF17CA(const I021_RE_STA_EXT3 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT3_FX(const I021_RE_STA_EXT3 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT4_SVH(const I021_RE_STA_EXT4 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT4_CATC(const I021_RE_STA_EXT4 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT4_FX(const I021_RE_STA_EXT4 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT5_CATC(const I021_RE_STA_EXT5 * item);
ASTERIX_API uint8_t get_I021_RE_STA_EXT5_FX(const I021_RE_STA_EXT5 * item);
ASTERIX_API double get_I021_RE_TNH(const I021_RE_TNH * item);
ASTERIX_API uint8_t get_I021_RE_MES_SUM(const I021_RE_MES * item);
ASTERIX_API uint8_t get_I021_RE_MES_PNO(const I021_RE_MES * item);
ASTERIX_API uint8_t get_I021_RE_MES_EM1(const I021_RE_MES * item);
ASTERIX_API uint8_t get_I021_RE_MES_XP(const I021_RE_MES * item);
ASTERIX_API uint8_t get_I021_RE_MES_FOM(const I021_RE_MES * item);
ASTERIX_API uint8_t get_I021_RE_MES_M2(const I021_RE_MES * item);
ASTERIX_API uint8_t get_I021_RE_MES_FX(const I021_RE_MES * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT1_M5(const I021_RE_MES_EXT1 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT1_ID(const I021_RE_MES_EXT1 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT1_DA(const I021_RE_MES_EXT1 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT1_M1(const I021_RE_MES_EXT1 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT1_M2(const I021_RE_MES_EXT1 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT1_M3(const I021_RE_MES_EXT1 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT1_MC(const I021_RE_MES_EXT1 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT1_PO(const I021_RE_MES_EXT1 * item);
ASTERIX_API uint16_t get_I021_RE_MES_EXT2_PIN(const I021_RE_MES_EXT2 * item);
ASTERIX_API uint16_t get_I021_RE_MES_EXT2_NO(const I021_RE_MES_EXT2 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT3_V(const I021_RE_MES_EXT3 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT3_L(const I021_RE_MES_EXT3 * item);
ASTERIX_API uint16_t get_I021_RE_MES_EXT3_EM1(const I021_RE_MES_EXT3 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT4_XP(const I021_RE_MES_EXT4 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT4_X5(const I021_RE_MES_EXT4 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT4_XC(const I021_RE_MES_EXT4 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT4_X3(const I021_RE_MES_EXT4 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT4_X2(const I021_RE_MES_EXT4 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT4_X1(const I021_RE_MES_EXT4 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT5_FOM(const I021_RE_MES_EXT5 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT6_V(const I021_RE_MES_EXT6 * item);
ASTERIX_API uint8_t get_I021_RE_MES_EXT6_L(const I021_RE_MES_EXT6 * item);
ASTERIX_API uint16_t get_I021_RE_MES_EXT6_M2(const I021_RE_MES_EXT6 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

ASTERIX_API void set_I021_RE_LEN(I021_RE * item, uint8_t len);
ASTERIX_API void set_I021_RE_FSPEC_raw(I021_RE * item, uint8_t fspec);
ASTERIX_API void set_I021_RE_FSPEC_BPS(I021_RE * item, uint8_t bps_presence);
ASTERIX_API void set_I021_RE_FSPEC_SELH(I021_RE * item, uint8_t selh_presence);
ASTERIX_API void set_I021_RE_FSPEC_NAV(I021_RE * item, uint8_t nav_presence);
ASTERIX_API void set_I021_RE_FSPEC_GAO(I021_RE * item, uint8_t gao_presence);
ASTERIX_API void set_I021_RE_FSPEC_SGV(I021_RE * item, uint8_t sgv_presence);
ASTERIX_API void set_I021_RE_FSPEC_STA(I021_RE * item, uint8_t sta_presence);
ASTERIX_API void set_I021_RE_FSPEC_TNH(I021_RE * item, uint8_t tnh_presence);
ASTERIX_API void set_I021_RE_FSPEC_MES(I021_RE * item, uint8_t mes_presence);
ASTERIX_API void set_I021_RE_BPS(I021_RE_BPS * item, double bps_hPa);
ASTERIX_API void set_I021_RE_SELH_HRD(I021_RE_SELH * item, uint8_t hrd);
ASTERIX_API void set_I021_RE_SELH_STAT(I021_RE_SELH * item, uint8_t stat);
ASTERIX_API void set_I021_RE_SELH_SELH(I021_RE_SELH * item, uint8_t selh);
ASTERIX_API void set_I021_RE_NAV_AP(I021_RE_NAV * item, uint8_t nav);
ASTERIX_API void set_I021_RE_NAV_VN(I021_RE_NAV * item, uint8_t vn);
ASTERIX_API void set_I021_RE_NAV_AH(I021_RE_NAV * item, uint8_t ah);
ASTERIX_API void set_I021_RE_NAV_AM(I021_RE_NAV * item, uint8_t am);
ASTERIX_API void set_I021_RE_NAV_MFM(I021_RE_NAV * item, uint8_t mfm);
ASTERIX_API void set_I021_RE_GAO_LAT(I021_RE_GAO * item, uint8_t lateral_m);
ASTERIX_API void set_I021_RE_GAO_LON(I021_RE_GAO * item, uint8_t longitudinal_m);
ASTERIX_API void set_I021_RE_SGV_STP(I021_RE_SGV * item, uint8_t stp);
ASTERIX_API void set_I021_RE_SGV_HTS(I021_RE_SGV * item, uint8_t hts);
ASTERIX_API void set_I021_RE_SGV_HTT(I021_RE_SGV * item, uint8_t htt);
ASTERIX_API void set_I021_RE_SGV_HRD(I021_RE_SGV * item, uint8_t hrd);
ASTERIX_API void set_I021_RE_SGV_GSS(I021_RE_SGV * item, double gss_kts);
ASTERIX_API void set_I021_RE_SGV_FX(I021_RE_SGV * item, uint8_t fx);
ASTERIX_API void set_I021_RE_SGV_EXT1_HGT(I021_RE_SGV_EXT1 * item, double hgt_deg);
ASTERIX_API void set_I021_RE_SGV_EXT1_FX(I021_RE_SGV_EXT1 * item, uint8_t fx);
ASTERIX_API void set_I021_RE_STA_ES(I021_RE_STA * item, uint8_t es);
ASTERIX_API void set_I021_RE_STA_UAT(I021_RE_STA * item, uint8_t uat);
ASTERIX_API void set_I021_RE_STA_RCE(I021_RE_STA * item, uint8_t rce);
ASTERIX_API void set_I021_RE_STA_RRL(I021_RE_STA * item, uint8_t rrl);
ASTERIX_API void set_I021_RE_STA_FX(I021_RE_STA * item, uint8_t fx);
ASTERIX_API void set_I021_RE_STA_EXT1_PS3(I021_RE_STA_EXT1 * item, uint8_t ps3);
ASTERIX_API void set_I021_RE_STA_EXT1_RRL(I021_RE_STA_EXT1 * item, uint8_t tpw);
ASTERIX_API void set_I021_RE_STA_EXT1_FX(I021_RE_STA_EXT1 * item, uint8_t fx);
ASTERIX_API void set_I021_RE_STA_EXT2_TSI(I021_RE_STA_EXT2 * item, uint8_t tsi);
ASTERIX_API void set_I021_RE_STA_EXT2_MUO(I021_RE_STA_EXT2 * item, uint8_t muo);
ASTERIX_API void set_I021_RE_STA_EXT2_RWC(I021_RE_STA_EXT2 * item, uint8_t rwc);
ASTERIX_API void set_I021_RE_STA_EXT2_FX(I021_RE_STA_EXT2 * item, uint8_t fx);
ASTERIX_API void set_I021_RE_STA_EXT3_DAA(I021_RE_STA_EXT3 * item, uint8_t daa);
ASTERIX_API void set_I021_RE_STA_EXT3_DF17CA(I021_RE_STA_EXT3 * item, uint8_t df17ca);
ASTERIX_API void set_I021_RE_STA_EXT3_FX(I021_RE_STA_EXT3 * item, uint8_t fx);
ASTERIX_API void set_I021_RE_STA_EXT4_SVH(I021_RE_STA_EXT4 * item, uint8_t svh);
ASTERIX_API void set_I021_RE_STA_EXT4_CATC(I021_RE_STA_EXT4 * item, uint8_t catc);
ASTERIX_API void set_I021_RE_STA_EXT4_FX(I021_RE_STA_EXT4 * item, uint8_t fx);
ASTERIX_API void set_I021_RE_STA_EXT5_CATC(I021_RE_STA_EXT5 * item, uint8_t tao);
ASTERIX_API void set_I021_RE_STA_EXT5_FX(I021_RE_STA_EXT5 * item, uint8_t fx);
ASTERIX_API void set_I021_RE_TNH(I021_RE_TNH * item, double tnh_deg);
ASTERIX_API void set_I021_MES_SUM(I021_RE_MES * item, uint8_t sum_presence);
ASTERIX_API void set_I021_MES_PNO(I021_RE_MES * item, uint8_t pno_presence);
ASTERIX_API void set_I021_MES_EM1(I021_RE_MES * item, uint8_t em1_presence);
ASTERIX_API void set_I021_MES_XP(I021_RE_MES * item, uint8_t xp_presence);
ASTERIX_API void set_I021_MES_FOM(I021_RE_MES * item, uint8_t fom_presence);
ASTERIX_API void set_I021_MES_M2(I021_RE_MES * item, uint8_t m2_presence);
ASTERIX_API void set_I021_MES_FX(I021_RE_MES * item, uint8_t fx);
ASTERIX_API void set_I021_RE_MES_EXT1_M5(I021_RE_MES_EXT1 * item, uint8_t m5);
ASTERIX_API void set_I021_RE_MES_EXT1_ID(I021_RE_MES_EXT1 * item, uint8_t id);
ASTERIX_API void set_I021_RE_MES_EXT1_DA(I021_RE_MES_EXT1 * item, uint8_t da);
ASTERIX_API void set_I021_RE_MES_EXT1_M1(I021_RE_MES_EXT1 * item, uint8_t m1);
ASTERIX_API void set_I021_RE_MES_EXT1_M2(I021_RE_MES_EXT1 * item, uint8_t m2);
ASTERIX_API void set_I021_RE_MES_EXT1_M3(I021_RE_MES_EXT1 * item, uint8_t m3);
ASTERIX_API void set_I021_RE_MES_EXT1_MC(I021_RE_MES_EXT1 * item, uint8_t mc);
ASTERIX_API void set_I021_RE_MES_EXT1_PO(I021_RE_MES_EXT1 * item, uint8_t fx);
ASTERIX_API void set_I021_RE_MES_EXT2_PIN(I021_RE_MES_EXT2 * item, uint16_t pin);
ASTERIX_API void set_I021_RE_MES_EXT2_NO(I021_RE_MES_EXT2 * item, uint16_t no);
ASTERIX_API void set_I021_RE_MES_EXT3_V(I021_RE_MES_EXT3 * item, uint8_t v);
ASTERIX_API void set_I021_RE_MES_EXT3_L(I021_RE_MES_EXT3 * item, uint8_t l);
ASTERIX_API void set_I021_RE_MES_EXT3_EM1(I021_RE_MES_EXT3 * item, uint16_t em1);
ASTERIX_API void set_I021_RE_MES_EXT4_XP(I021_RE_MES_EXT4 * item, uint8_t xp);
ASTERIX_API void set_I021_RE_MES_EXT4_X5(I021_RE_MES_EXT4 * item, uint8_t x5);
ASTERIX_API void set_I021_RE_MES_EXT4_XC(I021_RE_MES_EXT4 * item, uint8_t x4);
ASTERIX_API void set_I021_RE_MES_EXT4_X3(I021_RE_MES_EXT4 * item, uint8_t x3);
ASTERIX_API void set_I021_RE_MES_EXT4_X2(I021_RE_MES_EXT4 * item, uint8_t x2);
ASTERIX_API void set_I021_RE_MES_EXT4_X1(I021_RE_MES_EXT4 * item, uint8_t x1);
ASTERIX_API void set_I021_RE_MES_EXT5_FOM(I021_RE_MES_EXT5 * item, uint8_t fom);
ASTERIX_API void set_I021_RE_MES_EXT6_V(I021_RE_MES_EXT6 * item, uint8_t v);
ASTERIX_API void set_I021_RE_MES_EXT6_L(I021_RE_MES_EXT6 * item, uint8_t l);
ASTERIX_API void set_I021_RE_MES_EXT6_EM2(I021_RE_MES_EXT6 * item, uint16_t m2);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/RE (Reserved Expansion Field) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/RE structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_RE(void * item_in,
                                    unsigned char * msg_out,
                                    uint16_t out_index);

/** @brief Decode item I021/RE (Reserved Expansion Field) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/RE structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_RE(void * item_out,
                                    const unsigned char * msg_in,
                                    uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

 
#ifdef __cplusplus
}
#endif

#endif /* I021_RE_H */