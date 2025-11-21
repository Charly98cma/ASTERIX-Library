/**
 * @file I021_170.h
 * @brief Definition of I021/170, and related functions and values
 */

#ifndef I021_170_H
#define I021_170_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/// @brief Number of octets of I021/170
#define I021_170_N_OCTETS         6

/// @brief Number of characters of the Target Identification
#define I021_170_NUM_CHARS        8

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_170
 * @brief Category 021 / Item 170 - Target Identification
 * 
 * Target (aircraft or vehicle) identification in 8 characters, as reported
 * by the target.
 * 
 * @note Characters 1-8 (coded on 6 Bits each) defining target identification
 * when flight plan is available or the registration marking when no flight
 * plan is available.
 */
typedef struct I021_170 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[I021_170_N_OCTETS];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Character 1 (6 bits)
            uint8_t CHAR1           :6;
            /// @brief Character 2 (6 bits)
            uint8_t CHAR2           :6;
            /// @brief Character 3 (6 bits)
            uint8_t CHAR3           :6;
            /// @brief Character 4 (6 bits)
            uint8_t CHAR4           :6;
            /// @brief Character 5 (6 bits)
            uint8_t CHAR5           :6;
            /// @brief Character 6 (6 bits)
            uint8_t CHAR6           :6;
            /// @brief Character 7 (6 bits)
            uint8_t CHAR7           :6;
            /// @brief Character 8 (6 bits)
            uint8_t CHAR8           :6;
        };
    };
} I021_170;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Target Identification string from I021/170
 * 
 * @param item pointer to I021_170 structure
 * @param code_out_str 6 chars pointer to return the Target Identification string
 */
ASTERIX_API void get_I021_170_TI(const I021_170 * item,
                                 unsigned char * code_out_str);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Target Identification string into I021/170
 * 
 * @param item pointer to I021_170 structure
 * @param code_in_str 6-char pointer to the Target Identification string to write
 */
ASTERIX_API void set_I021_170_TI(I021_170 * item,
                                 const unsigned char * code_in_str);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/170 (Target Identification) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/170 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_170(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/170 (Target Identification) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/170 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_170(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Track Identification string of the I021/170
 * 
 * @param item pointer to I021_170 structure
 */
ASTERIX_API void print_I021_170(const I021_170 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_170_H */