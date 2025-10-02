/**
 * @file I021_146.h
 * @brief Definition of I021/146, and related functions and values
 */

#ifndef I021_146_H
#define I021_146_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_146_LSB_ALT                        25         /// LSB = 25 ft

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

 /**
 * @typedef I021_146
 * @brief Category 021 / Item 146 - Flight Level
 * 
 * The Selected Altitude as provided by the avionics and
 * corresponding either to the MCP/FCU Selected Altitude (the ATC
 * cleared altitude entered by the flight crew into the avionics) or to
 * the FMS Selected Altitude
 */
typedef struct I021_146 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** @brief Source Availability
             * 
             * = 0 No source information provided |
             * = 1 Source Information provided
             */
            uint16_t SAS        :1;
            /** @brief Selected Altitude Source
             * 
             * = 00 Unknown |
             * = 01 Aircraft Altitude (Holding Altitude) |
             * = 10 MCP/FCU Selected Altitude |
             * = 11 FMS Selected Altitude
             */
            uint16_t SRC        :2;
            /** @brief Altitude in two’s complement form (LSB = 25 ft)
             * 
             * -1300ft <= Altitude <= 100000ft
             */
            uint16_t ALT        :13;
        };
    };
} I021_146;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Source Availability (SAS) value from I021/146
 * 
 * @param item Pointer to I021_146 structure
 * 
 * @return uint8_t SAS value (0: no source, 1: source provided)
 */
ASTERIX_API uint8_t get_I021_146_SAS(const I021_146 * item);

/**
 * @brief Get the altitude Source (SRC) value from I021/146 
 * 
 * @param item Pointer to I021_146 structure
 * 
 * @return uint8_t Source value (0: unknown,
 *                               1: A/C holding alt.,
 *                               2: MCP/FCU sel. alt.,
 *                               3: FMS sel. alt.)
 */
ASTERIX_API uint8_t get_I021_146_SRC(const I021_146 * item);

/**
 * @brief Get the Altitude (ALT) value in feets (LSB = 25 ft)
 *        from I021/146 
 * 
 * @param item Pointer to I021_146 structure
 * 
 * @return int32_t altitude in feets
 */
ASTERIX_API int32_t get_I021_146_ALT(const I021_146 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given altitude Source Availability (SAS) value into
 *        I021/146
 * 
 * @param item Pointer to I021_146 structure
 * @param value New SAS value
 */
ASTERIX_API void set_I021_146_SAS(I021_146 * item, uint8_t sas);

/**
 * @brief Set the given altitude Source (SRC) value into
 *        I021/146
 * 
 * @param item Pointer to I021_146 structure
 * @param value New SRC value (see values correspondance)
 */
ASTERIX_API void set_I021_146_SRC(I021_146 * item, uint8_t src);

/**
 * @brief Set the given Altitude (ALT) value (LSB = 25 ft) into
 *        I021/146
 * 
 * @param item Pointer to I021_146 structure
 * @param value New ALT value (LSB = 25 ft)
 */
ASTERIX_API void set_I021_146_ALT(I021_146 * item, const int32_t alt);

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
ASTERIX_API uint16_t encode_I021_146(void * item_in,
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
ASTERIX_API uint16_t decode_I021_146(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Selected Altitude fields of the I021/146
 * 
 * @param item Pointer to I021_146 structure
 */
ASTERIX_API void print_I021_146(const I021_146 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_146_H */