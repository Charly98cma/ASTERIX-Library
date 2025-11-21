/**
 * @file I021_132.h
 * @brief Definition of I021/132, and related functions and values
 */

#ifndef I021_132_H
#define I021_132_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_132_LSB_MAM              (1.0)                /// LSB = 1 dBm

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_132
 * @brief Category 021 / Item 132 - Message Amplitude
 * 
 * Amplitude, in dBm, of ADS-B messages received by the ground  station,
 * coded in two's complement.
 */
typedef struct I021_132 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Message Amplitude (LSB = 1 dBm)
            uint8_t MAM;
        };
    };
} I021_132;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Message Amplitude (MAM) from I021/131 
 * 
 * @param item Pointer to I021_132 structure
 * @return double Message Amplitude in dBm (LSB = 1 dBm)
 */
ASTERIX_API uint8_t get_I021_132_MAM(const I021_132 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Message Amplitude (MAM) new value into I021/131 
 * 
 * @param item Pointer to I021_132 structure
 * @param mam_dBm New MAM value in dBm's (LSB = 1 dBm)
 */
ASTERIX_API void set_I021_132_MAM(I021_132 * item, uint8_t mam_dBm);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/132 (Message Amplitude) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/132 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_132(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/132 (Message Amplitude) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/132 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_132(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of I021/132
 * 
 * @param item Pointer to I021_132 structure.
 */
ASTERIX_API void print_I021_132(const I021_132 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_132_H */