/**
 * @file cat021_item250.h
 * @brief Definition of CAT 021 Item 250, and related functions and values
 */

#ifndef CAT021_ITEM250_H
#define CAT021_ITEM250_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/// @brief Max. number of BDS Registers (change as needed)
#define CAT021_ITEM250_MAX_REP              256

/// @brief Octets of BDS DATA
#define CAT021_ITEM250_BDSDATA_N_OCTETS     7

/// @brief Octets of a BDS Registers (BDSDATA (7) + BDS1-2 (1))
#define CAT021_ITEM250_BDSREG_N_OCTETS      CAT021_ITEM250_BDSDATA_N_OCTETS + 1

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item250
 * @brief Category 021 Item 250 - BDS Register Data
 * 
 * BDS Register Data as extracted from the aircraft transponder.
 */
typedef struct cat021_item250 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[CAT021_ITEM250_MAX_REP * CAT021_ITEM250_BDSREG_N_OCTETS + 1];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Repetition Factor (number of BDS Registers) (bits-75/65)
            uint8_t REP;

            struct {
                /**
                 * @brief BDS Data (bits-64/9)
                 * 
                 * 56-bit message conveying BDS Register Data
                 */
                uint8_t BDS[CAT021_ITEM250_BDSDATA_N_OCTETS];
                /**
                 * @brief BDS Register Address 1 (bits-8/5)
                 */
                uint8_t BDS1        :4;
                /**
                 * @brief BDS Register Address 1 (bits-4/1)
                 */
                uint8_t BDS2        :4;
            } BDS_REGISTER[CAT021_ITEM250_MAX_REP];
        };
    };
} cat021_item250;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Repetition Factor (REP) of BDS Registers from Cat 021 Item 250
 * 
 * @param item pointer to cat021_item250 structure
 * 
 * @return uint8_t number of BDS registers present in the item
 */
ASTERIX_API uint8_t get_cat021_item250_REP(const cat021_item250 * item);

/**
 * @brief Get the given 56-bit BDS Register Data (BDSDATA) from Cat 021 Item 250
 * 
 * @param item pointer to cat021_item250 structure
 * @param bds_index index of the BDS Register Data
 * 
 * @return uint64_t value of the BDSDATA (56-bits up-for interpretation)
 */
ASTERIX_API uint64_t get_cat021_item250_BDSDATA(const cat021_item250 * item,
                                                const uint8_t bds_index);

/**
 * @brief Get the BD Register Address 1 (BDS1) from Cat 021 Item 250
 * 
 * Used with BDS Register Address 2 forms the full ID of the BDS.
 * 
 * @param item pointer to cat021_item250 structure
 * @param bds_index index of the BDS Register Data
 * 
 * @return uint8_t value of BDS1
 */
ASTERIX_API uint8_t get_cat021_item250_BDS1(const cat021_item250 * item,
                                            const uint8_t bds_index);

/**
 * @brief Get the BD Register Address 2 (BDS2) from Cat 021 Item 250
 * 
 * Used with BDS Register Address 1 forms the full ID of the BDS.
 * 
 * @param item pointer to cat021_item250 structure
 * @param bds_index index of the BDS Register Data
 * 
 * @return uint8_t value of BDS2
 */
ASTERIX_API uint8_t get_cat021_item250_BDS2(const cat021_item250 * item,
                                            const uint8_t bds_index);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set a new Repetition Factor (REP) value of BDS Registers into Cat 021 Item 250
 * 
 * @param item pointer to cat021_item250 structure
 * @param rep new RP value
 */
ASTERIX_API void set_cat021_item250_REP(cat021_item250 * item,
                                        const uint8_t rep);

/**
 * @brief Set a new BDS Register Data (BDSDATA) into Cat 021 Item 250
 * 
 * @param item pointer to cat021_item250 structure
 * @param bds_index index of the desired BDS Register Data
 * @param bds_data new BDS Register Data
 */
ASTERIX_API void set_cat021_item250_BDSDATA(cat021_item250 * item,
                                            const uint8_t bds_index,
                                            const uint64_t bds_data);

/**
 * @brief Set a new BD Register Address 1 (BDS1) into Cat 021 Item 250
 * 
 * @param item pointer to cat021_item250 structure
 * @param bds1 new BDS Register Address 1
 */
ASTERIX_API void set_cat021_item250_BDS1(cat021_item250 * item,
                                         const uint8_t bds_index,
                                         const uint8_t bds1);

/**
 * @brief Set a new BD Register Address 2 (BDS2) into Cat 021 Item 250
 * 
 * @param item pointer to cat021_item250 structure
 * @param bds2 new BDS Register Address 2
 */
ASTERIX_API void set_cat021_item250_BDS2(cat021_item250 * item, 
                                         const uint8_t bds_index,
                                         const uint8_t bds2);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints all BDS Registers from cat 021 Item 250 
 * 
 * @param item pointer to cat021_item250 structure
 */
ASTERIX_API void print_cat021_item250(const cat021_item250 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM250_H */