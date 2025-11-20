/**
 * @file I021_250.h
 * @brief Definition of I021/250, and related functions and values
 */

#ifndef I021_250_H
#define I021_250_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/// @brief Max. number of BDS Registers (change as needed)
#define I021_250_MAX_REP              256

/// @brief Octets of BDS DATA
#define I021_250_BDSDATA_N_OCTETS     7

/// @brief Octets of a BDS Registers (BDSDATA (7) + BDS1-2 (1))
#define I021_250_BDSREG_N_OCTETS      I021_250_BDSDATA_N_OCTETS + 1

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_250
 * @brief Category 021 / Item 250 - BDS Register Data
 * 
 * BDS Register Data as extracted from the aircraft transponder.
 */
typedef struct I021_250 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[I021_250_MAX_REP * I021_250_BDSREG_N_OCTETS + 1];

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
                uint8_t BDS[I021_250_BDSDATA_N_OCTETS];
                /**
                 * @brief BDS Register Address 1 (bits-8/5)
                 */
                uint8_t BDS1        :4;
                /**
                 * @brief BDS Register Address 1 (bits-4/1)
                 */
                uint8_t BDS2        :4;
            } BDS_REGISTER[I021_250_MAX_REP];
        };
    };
} I021_250;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Repetition Factor (REP) of BDS Registers from I021/250
 * 
 * @param item pointer to I021_250 structure
 * 
 * @return uint8_t number of BDS registers present in the item
 */
ASTERIX_API uint8_t get_I021_250_REP(const I021_250 * item);

/**
 * @brief Get the given 56-bit BDS Register Data (BDSDATA) from I021/250
 * 
 * @param item pointer to I021_250 structure
 * @param bds_index index of the BDS Register Data
 * 
 * @return uint64_t value of the BDSDATA (56-bits up-for interpretation)
 */
ASTERIX_API uint64_t get_I021_250_BDSDATA(const I021_250 * item, uint8_t bds_index);

/**
 * @brief Get the BD Register Address 1 (BDS1) from I021/250
 * 
 * Used with BDS Register Address 2 forms the full ID of the BDS.
 * 
 * @param item pointer to I021_250 structure
 * @param bds_index index of the BDS Register Data
 * 
 * @return uint8_t value of BDS1
 */
ASTERIX_API uint8_t get_I021_250_BDS1(const I021_250 * item, uint8_t bds_index);

/**
 * @brief Get the BD Register Address 2 (BDS2) from I021/250
 * 
 * Used with BDS Register Address 1 forms the full ID of the BDS.
 * 
 * @param item pointer to I021_250 structure
 * @param bds_index index of the BDS Register Data
 * 
 * @return uint8_t value of BDS2
 */
ASTERIX_API uint8_t get_I021_250_BDS2(const I021_250 * item, uint8_t bds_index);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set a new Repetition Factor (REP) value of BDS Registers into
 *        I021/250
 * 
 * @param item pointer to I021_250 structure
 * @param rep new REP value
 */
ASTERIX_API void set_I021_250_REP(I021_250 * item, uint8_t rep);

/**
 * @brief Set a new BDS Register Data (BDSDATA) into I021/250
 * 
 * @param item pointer to I021_250 structure
 * @param bds_index index of the desired BDS Register Data
 * @param bds_data new BDS Register Data
 */
ASTERIX_API void set_I021_250_BDSDATA(I021_250 * item,
                                      uint8_t bds_index,
                                      const uint64_t bds_data);

/**
 * @brief Set a new BD Register Address 1 (BDS1) into I021/250
 * 
 * @param item pointer to I021_250 structure
 * @param bds1 new BDS Register Address 1
 */
ASTERIX_API void set_I021_250_BDS1(I021_250 * item,
                                   uint8_t bds_index,
                                   uint8_t bds1);

/**
 * @brief Set a new BD Register Address 2 (BDS2) into I021/250
 * 
 * @param item pointer to I021_250 structure
 * @param bds2 new BDS Register Address 2
 */
ASTERIX_API void set_I021_250_BDS2(I021_250 * item, 
                                   uint8_t bds_index,
                                   uint8_t bds2);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/**
 * @brief
 * 
 * @param item_in
 * @param msg_out
 * @param out_index
 * 
 * @return uint16_t
 */
ASTERIX_API uint16_t encode_I021_250(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/**
 * @brief
 * 
 * @param item_in
 * @param msg_in
 * @param in_index
 * 
 * @return uint16_t
 */
ASTERIX_API uint16_t decode_I021_250(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints all BDS Registers from I021/250 
 * 
 * @param item pointer to I021_250 structure
 */
ASTERIX_API void print_I021_250(const I021_250 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_250_H */