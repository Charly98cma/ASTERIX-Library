/**
 * @file I021_072.h
 * @brief Definition of I021/072, and related functions and values
 */

#ifndef I021_072_H
#define I021_072_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_072_LSB_TAV    (0.0078125)     /// @brief LSB = 1/128 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_072
 * @brief Category 021 / Item 072 - Time of Applicability for Velocity
 * 
 * Time of applicability (measurement) of the reported velocity, in  
 * the form of elapsed time since last midnight, expressed as UTC.
 */
typedef struct I021_072 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[3];
        
        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
        
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** 
             * @brief Time of Applicability for Velocity (LSB = 1/128 sec)
             */
            uint8_t TAV[3];
        };
    };
} I021_072;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Time of Applicability for Velocity in seconds (floating-point)
 *        from I021/072.
 *
 * @param item Pointer to I021_072 structure.
 * @return double Time in seconds (>= 0).
 */
ASTERIX_API double get_I021_072_TAV(const I021_072 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Time of Applicability for Velocity in seconds into I021/072.
 *
 * @param item Pointer to I021_072 structure.
 * @param tav_seconds Time in seconds (will be converted to 1/128-s units).
 */
ASTERIX_API void set_I021_072_TAV(I021_072 * item, double tav_seconds);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/072 (Time of applicability for Velocity) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/072 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_072(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/072 (Time of applicability for Velocity) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/072 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_072(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of I021/072 (Time of Applicability Velocity).
 * 
 * Prints both the raw value and the converted time in seconds.
 * 
 * @param item Pointer to I021_072_t structure.
 */
ASTERIX_API void print_I021_072(const I021_072 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_072_H */