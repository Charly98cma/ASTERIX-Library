/**
 * @file I021_150.h
 * @brief Definition of I021/150, and related functions and values
 */

#ifndef I021_150_H
#define I021_150_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_150_IM_IAS           0
#define I021_150_IM_MACH          1

#define I021_150_LSB_IAS          (double) (1/P2_14)  /// LSB = 2^-14 NM/s
#define I021_150_LSB_MACH         (double) (0.25)     /// LSB = 0-001

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_150
 * @brief Category 021 / Item 150 - Air Speed
 * 
 * Calculated Air Speed (Element of Air Vector).
 */
typedef struct I021_150 {
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
             * @brief IM
             * 
             * = 0: IAS | = 1: Mach
             */
            uint16_t IM         :1;
            /**
             * @brief Air Speed (IAS or MACH)
             * 
             * if IAS LSB = 2^-14 | if MACH LSB = 0.001
             */
            uint16_t AIRSPD     :15;
        };
    };
} I021_150;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Airspeed Mode (IM) from I021/150
 * 
 * @param item Pointer to I021_150 structure
 * 
 * @return uint8_t Air Speed mode (0: IAS, 1: MACH)
 */
ASTERIX_API uint8_t get_I021_150_IM(const I021_150 * item);

/**
 * @brief Get the Air Speed (AIRSPD) from I021/150 
 * 
 * The data in this fields changes based on the value of the field IM,
 * which can be IAS or MACH Air Speed.
 * 
 * @param item Pointer to I021_150 structure
 * 
 * @return double Air Speed (IAS - LSB 1/2^14 NM/s, or MACH - LSB = 0.001)
 */
ASTERIX_API double get_I021_150_AIRSPD(const I021_150 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Airspeed Mode (IM) value into I021/150
 * 
 * @param item Pointer to I021_150 structure
 * @param value New IM value (0: IAS, 1: MACH)
 */
ASTERIX_API void set_I021_150_IM(I021_150 * item, uint8_t im);

/**
 * @brief Set the given Air Speed (AIRSPD) value (see LSB for each mode) into
 *        I021/150
 * 
 * @param item Pointer to I021_150 structure
 * @param value New Air Speed (IAS LSB = 1/ 2^14 NM/s, MACH LSB = 0.001)
 */
ASTERIX_API void set_I021_150_AIRSPD(I021_150 * item, double airspd);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/150 (Air Speed) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/150 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_150(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/150 (Air Speed) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/150 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_150(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Flight Level of the I021/150
 * 
 * @param item Pointer to I021_150 structure
 */
ASTERIX_API void print_I021_150(const I021_150 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_150_H */