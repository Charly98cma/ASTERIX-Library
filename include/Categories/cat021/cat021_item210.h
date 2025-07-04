/**
 * @file cat021_item210.h
 * @brief Definition of CAT 021 Item 210, and related functions and values
 */

#ifndef CAT021_ITEM210_H
#define CAT021_ITEM210_H

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
 * @typedef cat021_item210
 * @brief Category 021 Item 210 - MOPS Version
 * 
 * Identification of the MOPS version used by a/c to supply ADS-B information
 * 
 * @note (see Specification Standard document for relevant notes regarding
 *        this item)
 */
typedef struct cat021_item210 {
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
} cat021_item210;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Version Not supported (VNS) flag from Cat 021 Item 210
 * 
 * @param item pointer to cat021_item210 structure
 * 
 * @return uint8_t value of Version Not supported flag
 */
ASTERIX_API uint8_t get_cat021_item210_VNS(const cat021_item210 * item);

/**
 * @brief Get the Version Number (VN) supported MOPS from Cat 021 Item 210
 * 
 * @param item pointer to cat021_item210 structure
 * 
 * @return uint8_t A/C supported MOPS version 
 */
ASTERIX_API uint8_t get_cat021_item210_VN(const cat021_item210 * item);

/**
 * @brief Get the Link Technology type (LTT) from the Cat 021 Item 210
 * 
 * @param item pointer to cat021_item210 structure
 * 
 * @return uint8_t value of Link Technology Type of the A/C
 */
ASTERIX_API uint8_t get_cat021_item210_LTT(const cat021_item210 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the new value of Version Not Supported (VNS) into cat 021 Item 210
 * 
 * @param item pointer to cat021_item210 structure
 * @param vns new Version Not Supported value to write
 */
ASTERIX_API void set_cat021_item210_VNS(cat021_item210 * item, const uint8_t vns);

/**
 * @brief Set the new value of Version Number (VN) into cat 021 Item 210
 * 
 * @param item pointer to cat021_item210 structure
 * @param vn new Version Number value to write
 */
ASTERIX_API void set_cat021_item210_VN(cat021_item210 * item, const uint8_t vn);

/**
 * @brief Set the new value of Link Technology Type (LTS) into cat 021 Item 210
 * 
 * @param item pointer to cat021_item210 structure
 * @param ltt new Link Technology Type value to write
 */
ASTERIX_API void set_cat021_item210_LTT(cat021_item210 * item, const uint8_t ltt);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the MOPS Version of the Cat 021 Item 210
 * 
 * @param item pointer to cat021_item210 structure
 */
ASTERIX_API void print_cat021_item210(const cat021_item210 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM210_H */