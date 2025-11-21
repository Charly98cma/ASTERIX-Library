/**
 * @file I021_145.h
 * @brief Definition of I021/145, and related functions and values
 */

#ifndef I021_145_H
#define I021_145_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_145_LSB_FL                    (0.25)         /// LSB = 1/4 FL

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_145
 * @brief Category 021 / Item 145 - Flight Level
 * 
 * Flight Level from barometric measurements, not QNH corrected,
 * in two's complement form
 */
typedef struct I021_145 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Flight Level (LSB = 0.25 ft)
             * 
             * -15 ft <= Flight Level <= 1500 ft
             */
            uint16_t FL;
        };
    };
} I021_145;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Flight Level (FL) from I021/145
 * 
 * @param item Pointer to I021_145 structure
 * 
 * @return int16_t flight level in steps of 0.25 FL's (see LSB)
 */
ASTERIX_API int16_t get_I021_145_FL_raw(const I021_145 * item);

/**
 * @brief Get the Flight Level (FL) from I021/145 
 * 
 * @param item Pointer to I021_145 structure
 * 
 * @return int16_t flight levels
 */
ASTERIX_API int16_t get_I021_145_FL_feet(const I021_145 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Flight Level (FL) raw value (no LSB) into
 *        I021/145
 * 
 * @param item Pointer to I021_145 structure
 * @param value New FL raw value in steps of 1/4 FL (see LSB)
 */
ASTERIX_API void set_I021_145_FL_raw(I021_145 * item, const int16_t fl_raw);

/**
 * @brief Set the given Flight Level (FL) value (see LSB) into
 *        I021/145
 * 
 * @param item Pointer to I021_145 structure
 * @param value New FL value in Flight Levels
 */
ASTERIX_API void set_I021_145_FL_feet(I021_145 * item, const int16_t fl);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/145 (Flight Level) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/145 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_145(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/145 (Flight Level) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/145 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_145(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Flight Level of the I021/145
 * 
 * @param item Pointer to I021_145 structure
 */
ASTERIX_API void print_I021_145(const I021_145 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_145_H */