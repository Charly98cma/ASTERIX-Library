/**
 * @file I034_050.h
 * @brief Definition of I034/050, and related functions and values
 */

#ifndef I034_050_H
#define I034_050_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I034_050_PSR_CHAB_NOCHN 0 /* No channel selected */
#define I034_050_PSR_CHAB_CHA   1 /* Channel A selected */
#define I034_050_PSR_CHAB_CHB   2 /* Channel B selected */
#define I034_050_PSR_CHAB_DIV   3 /* Diversity mode (both channels selected) */

#define I034_050_SSR_CHAB_NOCHN 0 /* No channel selected */
#define I034_050_SSR_CHAB_CHA   1 /* Channel A selected */
#define I034_050_SSR_CHAB_CHB   2 /* Channel B selected */
#define I034_050_SSR_CHAB_INV   3 /* Invalid combination */

#define I034_050_MDS_CHAB_NOCHN 0 /* No channel selected */
#define I034_050_MDS_CHAB_CHA   1 /* Channel A selected */
#define I034_050_MDS_CHAB_CHB   2 /* Channel B selected */
#define I034_050_MDS_CHAB_INV   3 /* Invalid combination */

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @brief I034_050_EXT1
 *
 * Information of the common elements of the system
 */
typedef struct
{
    union
    {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct
        {
            /// @brief Operational Release Status of the System (0: operational, 1: inhibited)
            uint8_t NOGO        : 1;
            /// @brief Radar Data Processor Chain Selection Status (0: RDPC-1, 1: RDPC-2)
            uint8_t RDPC        : 1;
            /// @brief RDPC Reset (0: default, 1: reset of RDPC)
            uint8_t RDPR        : 1;
            /// @brief Radar Data Processor Overload Indicator (0: not overloaded, 1: overloaded)
            uint8_t OVLRDP      : 1;
            /// @brief Transmission Subsystem Overload Status (0: not overloaded, 1: overloaded)
            uint8_t OVLXMT      : 1;
            /// @brief Monitoring System Connected Status (0: connected, 1: not connected)
            uint8_t MSC         : 1;
            /// @brief Time Source Validity (0: valid, 1: invalid)
            uint8_t TSV         : 1;
            /// @brief Spare bit set to zero
            uint8_t spare       : 1;
        };
    };
} I034_050_EXT1;

/**
 * @brief I034_050_EXT4
 *
 * Specific Status information for a PSR sensor
 */
typedef struct
{
    union
    {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct
        {
            /// @brief Selected Antenna (0: Antenna 1, 1: Antenna 2)
            uint8_t ANT         : 1;
            /// @brief Channel A/B selection status (0: No channel, 1: Channel A, 2: Channel B, 3: Diversity mode)
            uint8_t CHAB        : 2;
            /// @brief Overload condition (0: no overload, 1: overload)
            uint8_t OVL         : 1;
            /// @brief Monitoring System Connected Status (0: connected, 1: not connected)
            uint8_t MSC         : 1;
            /// @brief Spare bits set to zero
            uint8_t spare       : 3;
        };
    };
} I034_050_EXT4;

/**
 * @brief I034_050_EXT5
 *
 * Specific Status information for a SSR sensor
 */
typedef struct
{
    union
    {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct
        {
            /// @brief Selected Antenna (0: Antenna 1, 1: Antenna 2)
            uint8_t ANT     : 1;
            /// @brief Channel A/B selection status (0: No channel, 1: Channel A, 2: Channel B, 3: Diversity mode)
            uint8_t CHAB    : 2;
            /// @brief Overload condition (0: no overload, 1: overload)
            uint8_t OVL     : 1;
            /// @brief Monitoring System Connected Status (0: connected, 1: not connected)
            uint8_t MSC     : 1;
            /// @brief Spare bits set to zero
            uint8_t spare   : 3;
        };
    };
} I034_050_EXT5;

/**
 * @brief I034_050_EXT6
 *
 * Specific Status information for a Mode S sensor
 */
typedef struct
{
    union
    {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct
        {
            /// @brief Selected Antenna (0: Antenna 1, 1: Antenna 2)
            uint8_t ANT         : 1;
            /// @brief Channel A/B selection status (0: No channel, 1: Channel A, 2: Channel B, 3: Illegal combination)
            uint8_t CHAB        : 2;
            /// @brief Overload condition (0: no overload, 1: overload)
            uint8_t OVLSUR      : 1;
            /// @brief Monitoring System Connected Status (0: connected, 1: not connected)
            uint8_t MSC         : 1;
            /// @brief Channel A/B selection status for Surveillance Co-ordination Function (0: Channel A, 1: Channel B)
            uint8_t SCF         : 1;
            /// @brief Channel A/B selection status for Data Link Function (0: Channel A, 1: Channel B)
            uint8_t DLF         : 1;
            /// @brief Overload in Surveillance Co-ordination Function (0: no overload, 1: overload)
            uint8_t OVLSCF      : 1;
            /// @brief Overload in Data Link Function (0: no overload, 1: overload)
            uint8_t OVLDLF      : 1;
            /// @brief Spare bits set to zero
            uint8_t spare       : 7;
        };
    };
} I034_050_EXT6;

/**
 * @typedef I034_050
 * @brief Category 034 / Item 050 - System Configuration and Status
 *
 * Information concerning the configuration and status of a System.
 */
typedef struct
{
    union
    {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct
        {
            /// @brief Subfield #1: Common Part (0: absent, 1: present)
            uint8_t COM         : 1;
            /// @brief Subfield #2: Spare subfield (0: absent, 1: present)
            uint8_t spare1      : 1;
            /// @brief Subfield #3: Spare subfield (0: absent, 1: present)
            uint8_t spare2      : 1;
            /// @brief Subfield #4: Specific Status for PSR Sensor (0: absent, 1: present)
            uint8_t PSR         : 1;
            /// @brief Subfield #5: Specific Status for SSR Sensor (0: absent, 1: present)
            uint8_t SSR         : 1;
            /// @brief Subfield #6: Specific Status for Mode S Sensor (0: absent, 1: present)
            uint8_t MDS         : 1;
            /// @brief Subfield #7: Spare Subfield
            uint8_t spare3      : 1;
            /// @brief Field Extension (0: last octet, 1: more to come)
            uint8_t fx          : 1;
        };
    };
    /// @brief Subfield #1: Common Part
    I034_050_EXT1 ext1;
    /// @brief Subfield #4: Specific Status for PSR Sensor
    I034_050_EXT4 ext4;
    /// @brief Subfield #5: Specific Status for SSR Sensor
    I034_050_EXT5 ext5;
    /// @brief Subfield #6: Specific Status for Mode S Sensor
    I034_050_EXT6 ext6;
} I034_050;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

/** @brief Get presence flag for Subfield #1 (Common Part).
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 if absent, 1 if present.
 */
ASTERIX_API uint8_t get_I034_050_COM(const I034_050 *item);

/** @brief Get presence flag for PSR-specific subfield.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 if absent, 1 if present.
 */
ASTERIX_API uint8_t get_I034_050_PSR(const I034_050 *item);

/** @brief Get presence flag for SSR-specific subfield.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 if absent, 1 if present.
 */
ASTERIX_API uint8_t get_I034_050_SSR(const I034_050 *item);

/** @brief Get presence flag for Mode S-specific subfield.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 if absent, 1 if present.
 */
ASTERIX_API uint8_t get_I034_050_MDS(const I034_050 *item);

/** @brief Get the Field Extension (FX) bit indicating more octets follow.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 if last octet, 1 if more extension octets follow.
 */
ASTERIX_API uint8_t get_I034_050_FX(const I034_050 *item);

/* ============================== SUBFIELD #1 ============================== */

/** @brief Get the Operational Release Status (NOGO) from Subfield #1.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = operational, 1 = inhibited.
 */
ASTERIX_API uint8_t get_I034_050_EXT1_NOGO(const I034_050 *item);

/** @brief Get the Radar Data Processor Chain Selection Status (RDPC) from Subfield #1.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = RDPC-1, 1 = RDPC-2.
 */
ASTERIX_API uint8_t get_I034_050_EXT1_RDPC(const I034_050 *item);

/** @brief Get the RDPC Reset flag (RDPR) from Subfield #1.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = default, 1 = reset of RDPC.
 */
ASTERIX_API uint8_t get_I034_050_EXT1_RDPR(const I034_050 *item);

/** @brief Get the Radar Data Processor Overload Indicator (OVLRDP) from Subfield #1.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = not overloaded, 1 = overloaded.
 */
ASTERIX_API uint8_t get_I034_050_EXT1_OVLRDP(const I034_050 *item);

/** @brief Get the Transmission Subsystem Overload Status (OVLXMT) from Subfield #1.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = not overloaded, 1 = overloaded.
 */
ASTERIX_API uint8_t get_I034_050_EXT1_OVLXMT(const I034_050 *item);

/** @brief Get the Monitoring System Connected Status (MSC) from Subfield #1.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = connected, 1 = not connected.
 */
ASTERIX_API uint8_t get_I034_050_EXT1_MSC(const I034_050 *item);

/** @brief Get the Time Source Validity (TSV) from Subfield #1.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = valid, 1 = invalid.
 */
ASTERIX_API uint8_t get_I034_050_EXT1_TSV(const I034_050 *item);

/* ============================== SUBFIELD #4 ============================== */

/** @brief Get the selected antenna (ANT) for PSR sensor Subfield #4.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = Antenna 1, 1 = Antenna 2.
 */
ASTERIX_API uint8_t get_I034_050_EXT4_ANT(const I034_050 *item);

/** @brief Get Channel A/B selection status (CHAB) for PSR sensor Subfield #4.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = No channel, 1 = Channel A, 2 = Channel B, 3 = Diversity mode.
 */
ASTERIX_API uint8_t get_I034_050_EXT4_CHAB(const I034_050 *item);

/** @brief Get overload condition (OVL) for PSR sensor Subfield #4.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = no overload, 1 = overload.
 */
ASTERIX_API uint8_t get_I034_050_EXT4_OVL(const I034_050 *item);

/** @brief Get Monitoring System Connected status (MSC) for PSR sensor Subfield #4.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = connected, 1 = not connected.
 */
ASTERIX_API uint8_t get_I034_050_EXT4_MSC(const I034_050 *item);

/* ============================== SUBFIELD #5 ============================== */

/** @brief Get the selected antenna (ANT) for SSR sensor Subfield #5.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = Antenna 1, 1 = Antenna 2.
 */
ASTERIX_API uint8_t get_I034_050_EXT5_ANT(const I034_050 *item);

/** @brief Get Channel A/B selection status (CHAB) for SSR sensor Subfield #5.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = No channel, 1 = Channel A, 2 = Channel B, 3 = Diversity mode.
 */
ASTERIX_API uint8_t get_I034_050_EXT5_CHAB(const I034_050 *item);

/** @brief Get overload condition (OVL) for SSR sensor Subfield #5.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = no overload, 1 = overload.
 */
ASTERIX_API uint8_t get_I034_050_EXT5_OVL(const I034_050 *item);

/** @brief Get Monitoring System Connected status (MSC) for SSR sensor Subfield #5.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = connected, 1 = not connected.
 */
ASTERIX_API uint8_t get_I034_050_EXT5_MSC(const I034_050 *item);

/* ============================== SUBFIELD #6 ============================== */

/** @brief Get the selected antenna (ANT) for Mode S sensor Subfield #6.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = Antenna 1, 1 = Antenna 2.
 */
ASTERIX_API uint8_t get_I034_050_EXT6_ANT(const I034_050 *item);

/** @brief Get Channel A/B selection status (CHAB) for Mode S sensor Subfield #6.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = No channel, 1 = Channel A, 2 = Channel B, 3 = Illegal combination.
 */
ASTERIX_API uint8_t get_I034_050_EXT6_CHAB(const I034_050 *item);

/** @brief Get overload condition for the surveillance function (OVLSUR) in Subfield #6.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = no overload, 1 = overload.
 */
ASTERIX_API uint8_t get_I034_050_EXT6_OVLSUR(const I034_050 *item);

/** @brief Get Monitoring System Connected status (MSC) for Mode S sensor Subfield #6.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = connected, 1 = not connected.
 */
ASTERIX_API uint8_t get_I034_050_EXT6_MSC(const I034_050 *item);

/** @brief Get the Surveillance Co-ordination Function antenna selection (SCF) in Subfield #6.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = Channel A, 1 = Channel B.
 */
ASTERIX_API uint8_t get_I034_050_EXT6_SCF(const I034_050 *item);

/** @brief Get the Data Link Function antenna selection (DLF) in Subfield #6.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = Channel A, 1 = Channel B.
 */
ASTERIX_API uint8_t get_I034_050_EXT6_DLF(const I034_050 *item);

/** @brief Get overload indicator for Surveillance Co-ordination Function (OVLSCF) in Subfield #6.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = no overload, 1 = overload.
 */
ASTERIX_API uint8_t get_I034_050_EXT6_OVLSCF(const I034_050 *item);

/** @brief Get overload indicator for Data Link Function (OVLDLF) in Subfield #6.
 *
 * @param item Pointer to an I034_050 structure (must not be NULL).
 * 
 * @return 0 = no overload, 1 = overload.
 */
ASTERIX_API uint8_t get_I034_050_EXT6_OVLDLF(const I034_050 *item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

/** @brief Set/clear presence flag for Subfield #1 (Common Part).
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 to clear (absent), 1 to set (present).
 */
ASTERIX_API void set_I034_050_COM(I034_050 *item, uint8_t val);

/** @brief Set/clear presence flag for PSR-specific subfield.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 to clear (absent), 1 to set (present).
 */
ASTERIX_API void set_I034_050_PSR(I034_050 *item, uint8_t val);

/** @brief Set/clear presence flag for SSR-specific subfield.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 to clear (absent), 1 to set (present).
 */
ASTERIX_API void set_I034_050_SSR(I034_050 *item, uint8_t val);

/** @brief Set/clear presence flag for Mode S-specific subfield.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 to clear (absent), 1 to set (present).
 */
ASTERIX_API void set_I034_050_MDS(I034_050 *item, uint8_t val);

/** @brief Set/clear the Field Extension (FX) bit.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 to indicate last octet, 1 to indicate more extension octets.
 */
ASTERIX_API void set_I034_050_FX(I034_050 *item, uint8_t val);

/* ============================== SUBFIELD #1 ============================== */

/** @brief Set the Operational Release Status (NOGO) in Subfield #1.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = operational, 1 = inhibited.
 */
ASTERIX_API void set_I034_050_EXT1_NOGO(I034_050 *item, uint8_t val);

/** @brief Set the Radar Data Processor Chain Selection Status (RDPC) in SUbfield #1.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = RDPC-1, 1 = RDPC-2.
 */
ASTERIX_API void set_I034_050_EXT1_RDPC(I034_050 *item, uint8_t val);

/** @brief Set the RDPC Reset flag (RDPR) in SUbfield #1.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = default, 1 = reset of RDPC.
 */
ASTERIX_API void set_I034_050_EXT1_RDPR(I034_050 *item, uint8_t val);

/** @brief Set the Radar Data Processor Overload Indicator (OVLRDP) in SUbfield #1.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = not overloaded, 1 = overloaded.
 */
ASTERIX_API void set_I034_050_EXT1_OVLRDP(I034_050 *item, uint8_t val);

/** @brief Set the Transmission Subsystem Overload Status (OVLXMT) in SUbfield #1.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = not overloaded, 1 = overloaded.
 */
ASTERIX_API void set_I034_050_EXT1_OVLXMT(I034_050 *item, uint8_t val);

/** @brief Set the Monitoring System Connected Status (MSC) in SUbfield #1.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = connected, 1 = not connected.
 */
ASTERIX_API void set_I034_050_EXT1_MSC(I034_050 *item, uint8_t val);

/** @brief Set the Time Source Validity (TSV) in SUbfield #1.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = valid, 1 = invalid.
 */
ASTERIX_API void set_I034_050_EXT1_TSV(I034_050 *item, uint8_t val);

/* ============================== SUBFIELD #4 ============================== */

/** @brief Set the selected antenna (ANT) for PSR sensor Subfield #4.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = Antenna 1, 1 = Antenna 2.
 */
ASTERIX_API void set_I034_050_EXT4_ANT(I034_050 *item, uint8_t val);

/** @brief Set the Channel A/B selection status (CHAB) for PSR sensor Subfield #4.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = No channel, 1 = Channel A, 2 = Channel B, 3 = Diversity mode.
 */
ASTERIX_API void set_I034_050_EXT4_CHAB(I034_050 *item, uint8_t val);

/** @brief Set the overload condition (OVL) for PSR sensor Subfield #4.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = no overload, 1 = overload.
 */
ASTERIX_API void set_I034_050_EXT4_OVL(I034_050 *item, uint8_t val);

/** @brief Set the Monitoring System Connected status (MSC) for PSR sensor Subfield #4.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = connected, 1 = not connected.
 */
ASTERIX_API void set_I034_050_EXT4_MSC(I034_050 *item, uint8_t val);

/* ============================== SUBFIELD #5 ============================== */

/** @brief Set the selected antenna (ANT) for SSR sensor Subfield #5.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = Antenna 1, 1 = Antenna 2.
 */
ASTERIX_API void set_I034_050_EXT5_ANT(I034_050 *item, uint8_t val);

/** @brief Set the Channel A/B selection status (CHAB) for SSR sensor Subfield #5.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = No channel, 1 = Channel A, 2 = Channel B, 3 = Diversity mode.
 */
ASTERIX_API void set_I034_050_EXT5_CHAB(I034_050 *item, uint8_t val);

/** @brief Set the overload condition (OVL) for SSR sensor Subfield #5.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = no overload, 1 = overload.
 */
ASTERIX_API void set_I034_050_EXT5_OVL(I034_050 *item, uint8_t val);

/** @brief Set the Monitoring System Connected status (MSC) for SSR sensor Subfield #5.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = connected, 1 = not connected.
 */
ASTERIX_API void set_I034_050_EXT5_MSC(I034_050 *item, uint8_t val);

/* ============================== SUBFIELD #6 ============================== */

/** @brief Set the selected antenna (ANT) for Mode S sensor Subfield #6.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = Antenna 1, 1 = Antenna 2.
 */
ASTERIX_API void set_I034_050_EXT6_ANT(I034_050 *item, uint8_t val);

/** @brief Set the Channel A/B selection status (CHAB) for Mode S sensor Subfield #6.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = No channel, 1 = Channel A, 2 = Channel B, 3 = Illegal combination.
 */
ASTERIX_API void set_I034_050_EXT6_CHAB(I034_050 *item, uint8_t val);

/** @brief Set the overload indicator for the surveillance function (OVLSUR) in Subfield #6.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = no overload, 1 = overload.
 */
ASTERIX_API void set_I034_050_EXT6_OVLSUR(I034_050 *item, uint8_t val);

/** @brief Set the Monitoring System Connected status (MSC) for Mode S sensor Subfield #6.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = connected, 1 = not connected.
 */
ASTERIX_API void set_I034_050_EXT6_MSC(I034_050 *item, uint8_t val);

/** @brief Set the Surveillance Co-ordination Function antenna selection (SCF) in Subfield #6.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = Channel A, 1 = Channel B.
 */
ASTERIX_API void set_I034_050_EXT6_SCF(I034_050 *item, uint8_t val);

/** @brief Set the Data Link Function antenna selection (DLF) in Subfield #6.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = Channel A, 1 = Channel B.
 */
ASTERIX_API void set_I034_050_EXT6_DLF(I034_050 *item, uint8_t val);

/** @brief Set overload indicator for Surveillance Co-ordination Function (OVLSCF) in Subfield #6.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = no overload, 1 = overload.
 */
ASTERIX_API void set_I034_050_EXT6_OVLSCF(I034_050 *item, uint8_t val);

/** @brief Set overload indicator for Data Link Function (OVLDLF) in Subfield #6.
 *
 * @param item Pointer to an I034_050 structure to modify (must not be NULL).
 * @param val 0 = no overload, 1 = overload.
 */
ASTERIX_API void set_I034_050_EXT6_OVLDLF(I034_050 *item, uint8_t val);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I034/050 into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I034_050 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I034_050(void *item_in,
                                     unsigned char *msg_out,
                                     uint16_t out_index);

/** @brief Decode item I034/050 from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I034_050 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I034_050(void *item_out,
                                     const unsigned char *msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/** @brief Print the contents of item 034/050.
 *
 * @param item Pointer to an I034_050 structure.
 */
ASTERIX_API void print_I034_050(const I034_050 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_050_H */