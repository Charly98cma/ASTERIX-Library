/**
 * @file I021_073.h
 * @brief Definition of I021/073, and related functions and values
 */

#ifndef I021_073_H
#define I021_073_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_073_LSB_TMRP   (0.0078125)     /// @brief LSB = 1/128 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_073
 * @brief Category 021 / Item 073 - Time of Message Reception for Position
 * 
 * Time of reception of the latest position squitter in the Ground
 * Station, in the form of elapsed time since last midnight, 
 * expressed as UTC.
 */
typedef struct I021_073 {
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
             * @brief Time of Message Reception for Position (TMRP) (LSB = 1/128 sec)
             */
            uint8_t TMRP[3];
        };
    };
} I021_073;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Time of Message Reception for Position in seconds (floating-point)
 *        from I021/073.
 *
 * Divides the raw 1/128-s units by 128.0 to return seconds since midnight.
 *
 * @param item Pointer to I021_073 structure.
 * @return double Time in seconds (>= 0).
 */
ASTERIX_API double get_I021_073_TMRP(const I021_073 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Time of Message Reception for Position in seconds into I021/073.
 *
 * Converts the seconds value into 1/128-s units and stores as raw data.
 *
 * @param item Pointer to I021_073 structure.
 * @param seconds Time in seconds (will be converted to 1/128-s units).
 */
ASTERIX_API void set_I021_073_TMRP(I021_073 * item, double seconds);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/073 (Time of Message Reception for Position) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/073 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_073(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/073 (Time of Message Reception for Position) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/073 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_073(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of I021/073 (Time of Message Reception for Position).
 * 
 * Prints both the raw value and the converted time in seconds.
 * 
 * @param item Pointer to I021_073_t structure.
 */
ASTERIX_API void print_I021_073(const I021_073 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_073_H */