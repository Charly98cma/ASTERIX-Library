/**
 * @file I021_016.h
 * @brief Definition of I021/016, and related functions and values
 */

#ifndef I021_016_H
#define I021_016_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_016_LSB_RP             (0.5)       /// @brief LSB = 0.5 seconds

/// @brief Minimum value of RP in seconds
#define I021_016_RP_MIN             (0.0)
/// @brief Maximum value of RP in seconds
#define I021_016_RP_MAX             (127.5)

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_016
 * @brief Category 021 / Item 016 - Service Management
 * 
 * Identification of services offered by a ground station
 * (identified by a SIC code)
 */
typedef struct I021_016 {
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
             * @brief Report Period (direct access)
             * 
             * Range: 0 … 127.5 seconds (value of 127.5 indicates 127.5 or more)
             * 
             * LSB = 0.5 s
             */
            uint8_t RP;
        };
    };
} I021_016;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Report Period value (RP) from I021/016 in seconds.
 * 
 * Converts the raw RP value to seconds.
 * 
 * Range: 0 … 127.5 seconds (value of 127.5 indicates 127.5 or more)
 * 
 * @param item Pointer to I021_016 structure.
 * @return double Report Period in seconds
 */
ASTERIX_API double get_I021_016_RP(const I021_016 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/
/**
 * @brief Set the Report Period (RP) value in seconds into I021/016 field.
 * 
 * If the value exceeds the maximum (127.5 seconds), it is set to the maximum.
 * 
 * @param item Pointer to I021_016 structure.
 * @param rp_seconds Value of the RP in seconds
 */
ASTERIX_API void set_I021_016_RP(I021_016 * item, double rp_seconds);

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
ASTERIX_API uint16_t encode_I021_016(void * item_in,
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
ASTERIX_API uint16_t decode_I021_016(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 016.
 *
 * This function prints the values of the main byte.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a I021_016 structure.
 */
ASTERIX_API void print_I021_016(const I021_016 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_016_H */