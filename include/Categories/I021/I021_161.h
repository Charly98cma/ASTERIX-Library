/**
 * @file I021_161.h
 * @brief Definition of I021/161, and related functions and values
 */

#ifndef I021_161_H
#define I021_161_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_161_MIN_TRKNUM       (0)     /// @brief Min. track number = 0
#define I021_161_MAX_TRKNUM       (4095)  /// @brief Min. track number = 4095

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_161
 * @brief Category 021 / Item 161 - Airborne Ground Vector
 * 
 * An integer value representing a unique reference to a track record within a
 * particular track file
 */
typedef struct I021_161 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bits-16/13 set to 0
            uint16_t spare      :4;
            /// @brief Track number (0 to 4095)
            uint16_t TRKNUM     :12;
        };
    };
} I021_161;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Track Number (TRKNUM) from I021/161
 * 
 * @param item pointer to I021_161 structure
 * 
 * @return uint16_t track number value
 */
ASTERIX_API uint16_t get_I021_161_TRKNUM(const I021_161 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Track Number (TRKNUM) into I021/161
 * 
 * @param item pointer to I021_161 structure
 * @param track_number New Track Number (0 to 4095)
 */
ASTERIX_API void set_I021_161_TRKNUM(I021_161 * item, uint16_t track_number);

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
ASTERIX_API uint16_t encode_I021_161(void * item_in,
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
ASTERIX_API uint16_t decode_I021_161(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Track Number of the I021/161
 * 
 * @param item pointer to I021_161 structure
 */
ASTERIX_API void print_I021_161(const I021_161 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_161_H */