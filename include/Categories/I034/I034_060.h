/**
 * @file I034_060.h
 * @brief Definition of I034/060, and related functions and values
 */

#ifndef I034_060_H
#define I034_060_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @brief I034_060_EXT1
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
            /// @brief Spare bits set to zero
            uint8_t spare1      : 1;
            /// @brief Reduction Steps in use for an overload of the RDP (Reduction step N active)
            uint8_t REDRDP      : 3;
            /// @brief Reduction Steps in use for an overload of the Transmission subsystem (Reduction step N active)
            uint8_t REDXMT      : 3;
            /// @brief Spare bit set to zero
            uint8_t spare2      : 1;
        };
    };
} I034_060_EXT1;

/**
 * @brief I034_060_EXT4
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
            /// @brief Polarization in use by PSR (0: Linear, 1: Circular)
            uint8_t POL         : 1;
            /// @brief Reduction Steps in use as a result of an overload of the PSR subsystem (Reduction step N active)
            uint8_t REDRAD      : 3;
            /// @brief Sensitivity Time Control Map in use (0: STC map 1, 1: STC map 2, 2: STC map 3, 3: STC map 4)
            uint8_t STC         : 2;
            /// @brief Spare bits set to zero
            uint8_t spare       : 2;
        };
    };
} I034_060_EXT4;

/**
 * @brief I034_060_EXT5
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
            /// @brief Reduction Steps in use as a result of an overload of the SSR subsystem (Reduction step N active)
            uint8_t REDRAD      : 3;
            /// @brief Spare bits set to zero
            uint8_t spare       : 5;
        };
    };
} I034_060_EXT5;

/**
 * @brief I034_060_EXT6
 *
 * Specific Status information for a Mode S sensor
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
            /// @brief Reduction Steps in use as a result of an overload of the SSR subsystem (Reduction step N active)
            uint8_t REDRAD      : 3;
            /// @brief Cluster State (0: autonomous, 1: not autonomous)
            uint8_t CLU         : 1;
            /// @brief Spare bits set to zero
            uint8_t spare       : 4;
        };
    };
} I034_060_EXT6;

/**
 * @typedef I034_060
 * @brief Category 034 / Item 060 - System Configuration and Status
 *
 * Status concerning the processing options, in use during the last antenna
 * revolution, for the various Sensors, composing the System.
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
    I034_060_EXT1 ext1;
    /// @brief Subfield #4: Specific Status for PSR Sensor
    I034_060_EXT4 ext4;
    /// @brief Subfield #5: Specific Status for SSR Sensor
    I034_060_EXT5 ext5;
    /// @brief Subfield #6: Specific Status for Mode S Sensor
    I034_060_EXT6 ext6;
} I034_060;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

/** @brief Get presence flag for Subfield #1 (Common Part).
 *
 * @param item Pointer to an I034_060 structure (must not be NULL).
 * 
 * @return 0 if absent, 1 if present.
 */
ASTERIX_API uint8_t get_I034_060_COM(const I034_060 *item);

/** @brief Get presence flag for PSR-specific subfield.
 *
 * @param item Pointer to an I034_060 structure (must not be NULL).
 * 
 * @return 0 if absent, 1 if present.
 */
ASTERIX_API uint8_t get_I034_060_PSR(const I034_060 *item);

/** @brief Get presence flag for SSR-specific subfield.
 *
 * @param item Pointer to an I034_060 structure (must not be NULL).
 * 
 * @return 0 if absent, 1 if present.
 */
ASTERIX_API uint8_t get_I034_060_SSR(const I034_060 *item);

/** @brief Get presence flag for Mode S-specific subfield.
 *
 * @param item Pointer to an I034_060 structure (must not be NULL).
 * 
 * @return 0 if absent, 1 if present.
 */
ASTERIX_API uint8_t get_I034_060_MDS(const I034_060 *item);

/** @brief Get the Field Extension (FX) bit indicating more octets follow.
 *
 * @param item Pointer to an I034_060 structure (must not be NULL).
 * 
 * @return 0 if last octet, 1 if more extension octets follow.
 */
ASTERIX_API uint8_t get_I034_060_FX(const I034_060 *item);

/* ============================== SUBFIELD #1 ============================== */

/** @brief Get the Reduction Steps in use for RDP overload (REDRDP) from Subfield #1.
 *
 * @param item Pointer to an I034_060 structure (must not be NULL).
 * 
 * @return Reduction step value (0: no reduction, .., 7: maximum reduction).
 */
ASTERIX_API uint8_t get_I034_060_EXT1_REDRDP(const I034_060 *item);

/** @brief Get the Reduction Steps in use for Transmission overload (REDXMT) from Subfield #1.
 *
 * @param item Pointer to an I034_060 structure (must not be NULL).
 * 
 * @return Reduction step value (0: no reduction, .., 7: maximum reduction).
 */
ASTERIX_API uint8_t get_I034_060_EXT1_REDXMT(const I034_060 *item);

/* ============================== SUBFIELD #4 ============================== */

/** @brief Get the Polarization in use by PSR (POL) from Subfield #4.
 *
 * @param item Pointer to an I034_060 structure (must not be NULL).
 * 
 * @return 0 = Linear, 1 = Circular.
 */
ASTERIX_API uint8_t get_I034_060_EXT4_POL(const I034_060 *item);

/** @brief Get the Reduction Steps used due to PSR overload (REDRAD) from Subfield #4.
 *
 * @param item Pointer to an I034_060 structure (must not be NULL).
 * 
 * @return Reduction step value (0: no reduction, .., 7: maximum reduction).
 */
ASTERIX_API uint8_t get_I034_060_EXT4_REDRAD(const I034_060 *item);

/** @brief Get the Sensitivity Time Control map in use (STC) from Subfield #4.
 *
 * @param item Pointer to an I034_060 structure (must not be NULL).
 * 
 * @return STC map index (0: map 1, 1: map 2, 2: map 3, 3: map 4).
 */
ASTERIX_API uint8_t get_I034_060_EXT4_STC(const I034_060 *item);

/* ============================== SUBFIELD #5 ============================== */

/** @brief Get the Reduction Steps used due to SSR overload (REDRAD) from Subfield #5.
 *
 * @param item Pointer to an I034_060 structure (must not be NULL).
 * 
 * @return Reduction step value (0: no reduction, .., 7: maximum reduction).
 */
ASTERIX_API uint8_t get_I034_060_EXT5_REDRAD(const I034_060 *item);

/* ============================== SUBFIELD #6 ============================== */

/** @brief Get the Reduction Steps used due to Mode S overload (REDRAD) from Subfield #6.
 *
 * @param item Pointer to an I034_060 structure (must not be NULL).
 *
 * @return Reduction step value (0: no reduction, .., 7: maximum reduction).
 */
ASTERIX_API uint8_t get_I034_060_EXT6_REDRAD(const I034_060 *item);

/** @brief Get the Cluster State (CLU) from Subfield #6.
 *
 * @param item Pointer to an I034_060 structure (must not be NULL).
 * 
 * @return 0 = autonomous, 1 = not autonomous.
 */
ASTERIX_API uint8_t get_I034_060_EXT6_CLU(const I034_060 *item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

/** @brief Set/clear presence flag for Subfield #1 (Common Part).
 *
 * @param item Pointer to an I034_060 structure to modify (must not be NULL).
 * @param com 0 to clear (absent), 1 to set (present).
 */
ASTERIX_API void set_I034_060_COM(I034_060 *item, uint8_t com);

/** @brief Set/clear presence flag for PSR-specific subfield.
 *
 * @param item Pointer to an I034_060 structure to modify (must not be NULL).
 * @param psr 0 to clear (absent), 1 to set (present).
 */
ASTERIX_API void set_I034_060_PSR(I034_060 *item, uint8_t psr);

/** @brief Set/clear presence flag for SSR-specific subfield.
 *
 * @param item Pointer to an I034_060 structure to modify (must not be NULL).
 * @param ssr 0 to clear (absent), 1 to set (present).
 */
ASTERIX_API void set_I034_060_SSR(I034_060 *item, uint8_t ssr);

/** @brief Set/clear presence flag for Mode S-specific subfield.
 *
 * @param item Pointer to an I034_060 structure to modify (must not be NULL).
 * @param mds 0 to clear (absent), 1 to set (present).
 */
ASTERIX_API void set_I034_060_MDS(I034_060 *item, uint8_t mds);

/** @brief Set/clear the Field Extension (FX) bit.
 *
 * @param item Pointer to an I034_060 structure to modify (must not be NULL).
 * @param fx 0 to indicate last octet, 1 to indicate more extension octets.
 */
ASTERIX_API void set_I034_060_FX(I034_060 *item, uint8_t fx);

/* ============================== SUBFIELD #1 ============================== */

/** @brief Set the Reduction Steps in use for RDP overload (REDRDP) in Subfield #1.
 *
 * @param item Pointer to an I034_060 structure to modify (must not be NULL).
 * @param redrdp Reduction step value (0: no reduction, .., 7: maximum reduction).
 */
ASTERIX_API void set_I034_060_EXT1_REDRDP(I034_060 *item, uint8_t redrdp);

/** @brief Set the Reduction Steps in use for Transmission overload (REDXMT) in Subfield #1.
 *
 * @param item Pointer to an I034_060 structure to modify (must not be NULL).
 * @param redxmt Reduction step value (0: no reduction, .., 7: maximum reduction).
 */
ASTERIX_API void set_I034_060_EXT1_REDXMT(I034_060 *item, uint8_t redxmt);

/* ============================== SUBFIELD #4 ============================== */

/** @brief Set the Polarization in use by PSR (POL) in Subfield #4.
 *
 * @param item Pointer to an I034_060 structure to modify (must not be NULL).
 * @param pol 0 = Linear, 1 = Circular.
 */
ASTERIX_API void set_I034_060_EXT4_POL(I034_060 *item, uint8_t pol);

/** @brief Set the Reduction Steps used due to PSR overload (REDRAD) in Subfield #4.
 *
 * @param item Pointer to an I034_060 structure to modify (must not be NULL).
 * @param redrad Reduction step value (0: no reduction, .., 7: maximum reduction).
 */
ASTERIX_API void set_I034_060_EXT4_REDRAD(I034_060 *item, uint8_t redrad);

/** @brief Set the Sensitivity Time Control map in use (STC) in Subfield #4.
 *
 * @param item Pointer to an I034_060 structure to modify (must not be NULL).
 * @param stc STC map index (0: map 1, 1: map 2, 2: map 3, 3: map 4).
 */
ASTERIX_API void set_I034_060_EXT4_STC(I034_060 *item, uint8_t stc);

/* ============================== SUBFIELD #5 ============================== */

/** @brief Set the Reduction Steps used due to SSR overload (REDRAD) in Subfield #5.
 *
 * @param item Pointer to an I034_060 structure to modify (must not be NULL).
 * @param redrad Reduction step value (0: no reduction, .., 7: maximum reduction).
 */
ASTERIX_API void set_I034_060_EXT5_REDRAD(I034_060 *item, uint8_t redrad);

/* ============================== SUBFIELD #6 ============================== */

/** @brief Set the Reduction Steps used due to Mode S overload (REDRAD) in Subfield #6.
 *
 * @param item Pointer to an I034_060 structure to modify (must not be NULL).
 * @param redrad Reduction step value (0: no reduction, .., 7: maximum reduction).
 */
ASTERIX_API void set_I034_060_EXT6_REDRAD(I034_060 *item, uint8_t redrad);

/** @brief Set the Cluster State (CLU) in Subfield #6.
 *
 * @param item Pointer to an I034_060 structure to modify (must not be NULL).
 * @param clu 0 = autonomous, 1 = not autonomous.
 */
ASTERIX_API void set_I034_060_EXT6_CLU(I034_060 *item, uint8_t clu);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I034/060 into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I034_060 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I034_060(void *item_in,
                                     unsigned char *msg_out,
                                     uint16_t out_index);

/** @brief Decode item I034/060 from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I034_060 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I034_060(void *item_out,
                                     const unsigned char *msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/** @brief Print the contents of item 034/060.
 *
 * @param item Pointer to a I034_060 structure.
 */
ASTERIX_API void print_I034_060(const I034_060 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_060_H */