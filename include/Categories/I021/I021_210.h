/**
 * @file I021_210.h
 * @brief Definition of I021/210, and related functions and values
 */

#ifndef I021_210_H
#define I021_210_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_210
 * @brief Category 021 / Item 210 - MOPS Version
 * 
 * Identification of the MOPS version used by a/c to supply ADS-B information
 * 
 * @note (see Specification Standard document for relevant notes regarding
 *        this item)
 */
typedef struct I021_210 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bit set to 0
            uint8_t spare           :1;
            /**
             * @brief Version Not Supported
             * 
             * 0 = The MOPS Version is supported by the GS;
             * 1 = The MOPS Version is not supported by the GS
             */
            uint8_t VNS             :1;
            /**
             * @brief Version Number
             * 
             * @note This sub-field shall contain a value describing the MOPS used
             *       by each aircraft.
             * 
             * @note Currently defined for 1090 ES (LTT=2):
             *       0 = ED102/DO-260 [Ref. 8];
             *       1 = DO-260A [Ref. 9];
             *       2 = ED102A/DO-260B [Ref. 10];
             *       3 = ED-102B/DO-260C [Ref. 11];
             * 
             * @note The versions of other link technologies are assumed to be
             *       in line with the 1090 ES MOPS versions and the
             *       corresponding MASPS versions.
             */
            uint8_t VN              :3;
            /**
             * @brief Link Technology Type
             * 
             * 0 = Other;
             * 1 = UAT;
             * 2 = 1090 ES;
             * 3 = VDL 4;
             * 4-7 = Not assigned
             */
            uint8_t LTT             :3;
        };
    };
} I021_210;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Version Not supported (VNS) flag from I021/210
 * 
 * @param item pointer to I021_210 structure
 * 
 * @return uint8_t value of Version Not supported flag
 */
ASTERIX_API uint8_t get_I021_210_VNS(const I021_210 * item);

/**
 * @brief Get the Version Number (VN) supported MOPS from I021/210
 * 
 * @param item pointer to I021_210 structure
 * 
 * @return uint8_t A/C supported MOPS version 
 */
ASTERIX_API uint8_t get_I021_210_VN(const I021_210 * item);

/**
 * @brief Get the Link Technology type (LTT) from the I021/210
 * 
 * @param item pointer to I021_210 structure
 * 
 * @return uint8_t value of Link Technology Type of the A/C
 */
ASTERIX_API uint8_t get_I021_210_LTT(const I021_210 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the new value of Version Not Supported (VNS) into I021/210
 * 
 * @param item pointer to I021_210 structure
 * @param vns new Version Not Supported value to write
 */
ASTERIX_API void set_I021_210_VNS(I021_210 * item, uint8_t vns);

/**
 * @brief Set the new value of Version Number (VN) into I021/210
 * 
 * @param item pointer to I021_210 structure
 * @param vn new Version Number value to write
 */
ASTERIX_API void set_I021_210_VN(I021_210 * item, uint8_t vn);

/**
 * @brief Set the new value of Link Technology Type (LTS) into I021/210
 * 
 * @param item pointer to I021_210 structure
 * @param ltt new Link Technology Type value to write
 */
ASTERIX_API void set_I021_210_LTT(I021_210 * item, uint8_t ltt);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/210 (MOPS Version) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/210 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_210(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/210 (MOPS Version) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/210 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_210(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the MOPS Version of the I021/210
 * 
 * @param item pointer to I021_210 structure
 */
ASTERIX_API void print_I021_210(const I021_210 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_210_H */