/**
 * @file I034_100.h
 * @brief Definition of I034/100, and related functions and values
 */

#ifndef I034_100_H
#define I034_100_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I034_100_LSB_RHO    (0.00390625)    /// @brief LSB = 1/256 NM
#define I034_100_LSB_THETA  (360.0/P2_16)   /// @brief LSB = 360/2^16 degrees

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I034_100
 * @brief Category 034 / Item 100 - Generic Polar Window
 *
 * Geographical window defined in polar co-ordinates.
 */
typedef struct
{
    union
    {
    /// @brief Raw octets as received (recommended for portable access)
    uint8_t raw[8];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct
        {
            /// @brief Rho Start (max range = 256 NM)
            uint16_t RHO_START;
            /// @brief Rho End (max range = 256 NM)
            uint16_t RHO_END;
            /// @brief Theta Start (range from 0 to 359.9945 degrees)
            uint16_t THETA_START;
            /// @brief Theta End (range from 0 to 359.9945 degrees)
            uint16_t THETA_END;
        };
    };
} I034_100;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the RHO START value from I034/100
 *
 * @param item Pointer to an I034_100 structure (must not be NULL).
 * 
 * @return RHO start distance in nautical miles as a float.
 */
ASTERIX_API float get_I034_100_RHO_START(const I034_100 *item);

/**
 * @brief Get the RHO END value from I034/100
 *
 * @param item Pointer to an I034_100 structure (must not be NULL).
 * 
 * @return RHO end distance in nautical miles as a float.
 */
ASTERIX_API float get_I034_100_RHO_END(const I034_100 *item);

/**
 * @brief Get the THETA START value from I034/100
 *
 * @param item Pointer to an I034_100 structure (must not be NULL).
 * 
 * @return THETA start angle in degrees as a float.
 */
ASTERIX_API float get_I034_100_THETA_START(const I034_100 *item);

/**
 * @brief Get the THETA END value from I034/100
 *
 * @param item Pointer to an I034_100 structure (must not be NULL).
 * 
 * @return THETA end angle in degrees as a float.
 */
ASTERIX_API float get_I034_100_THETA_END(const I034_100 *item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set a new RHO START value into I034/100
 *
 * @param item Pointer to an I034_100 structure to modify (must not be NULL).
 * @param rho_start RHO start distance in nautical miles.
 */
ASTERIX_API void set_I034_100_RHO_START(I034_100 *item, float rho_start);

/**
 * @brief Set a new RHO END value into I034/100
 *
 * @param item Pointer to an I034_100 structure to modify (must not be NULL).
 * @param rho_end RHO end distance in nautical miles.
 */
ASTERIX_API void set_I034_100_RHO_END(I034_100 *item, float rho_end);

/**
 * @brief Set a new THETA START value into I034/100
 *
 * @param item Pointer to an I034_100 structure to modify (must not be NULL).
 * @param theta_start THETA start angle in degrees.
 */
ASTERIX_API void set_I034_100_THETA_START(I034_100 *item, float theta_start);

/**
 * @brief Set a new THETA END value into I034/100
 *
 * @param item Pointer to an I034_100 structure to modify (must not be NULL).
 * @param theta_end THETA end angle in degrees.
 */
ASTERIX_API void set_I034_100_THETA_END(I034_100 *item, float theta_end);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I034/100 into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I034_100 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I034_100(void *item_in,
                                     unsigned char *msg_out,
                                     uint16_t out_index);

/** @brief Decode item I034/100 from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I034_100 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I034_100(void *item_out,
                                     const unsigned char *msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of item 034/100.
 *
 * @param item Pointer to a I034_100 structure.
 */
ASTERIX_API void print_I034_100(const I034_100 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_100_H */