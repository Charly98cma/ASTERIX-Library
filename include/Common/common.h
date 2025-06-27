/**
 * @file common.h
 * @brief Values, types and function headers used troughout the project
 */

#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/*******************************************************************************
 * Structures and types
 ******************************************************************************/

/**
 * @typedef header_t
 * @brief Header type of ASTERIX messages
 * 
 * Type used to represent the header of any ASTERIX message,
 * with the category and length (in Bytes) of the message.
 */
typedef struct header {
    /// @brief Asterix category (range from 0 to 255)
    uint8_t CAT;
    /// @brief Full length of the message
    uint16_t LEN;
} header;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Extracts the ASTERIX Category from a raw data array.
 * 
 * The ASTERIX Category is always the first octet of the ASTERIX message.
 * This function safely reads the category from a received data block.
 * 
 * @param data Pointer to the received data array (minimum 1 byte).
 * @return uint8_t The category number (CAT). Returns 0 if data is NULL.
 * 
 * @note The category identifies the type of ASTERIX message,
 *       such as CAT021, CAT048, etc.
 */
ASTERIX_API uint8_t  get_header_CAT(const header * item);

/**
 * @brief Extracts the total length of the ASTERIX message from a raw data array.
 * 
 * The length of the ASTERIX message is always located in octets 2 and 3 and is encoded
 * in **big-endian** format (most significant byte first). This function reads and combines
 * those two bytes into a 16-bit length.
 * 
 * @param data Pointer to the received data array (minimum 3 bytes).
 * @return uint16_t Total length of the ASTERIX message in bytes. Returns 0 if data is NULL.
 * 
 * @note The length includes the category byte and the length field itself.
 */
ASTERIX_API uint16_t get_header_LEN(const header * item);

/*******************************************************************************
 * Getters
 ******************************************************************************/

// TODO: Setters for header CAT and LEN

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Get the Message Category (CAT) from the ASTERIX header.
 * 
 * Portable access to the CAT bits, independent of compiler and endianness.
 * 
 * @param item Pointer to header_t structure.
 * @return uint8_t Value of CAT
 */
ASTERIX_API uint8_t  get_CAT(const uint8_t * data);

/**
 * @brief Get the Message Length (LEN) from the ASTERIX header.
 * 
 * Portable access to the LEN field, independent of compiler and endianness.
 * 
 * @param item Pointer to header_t structure.
 * @return uint8_t Value of LEN (total length of the ASTERIX message)
 */
ASTERIX_API uint16_t get_LEN(const uint8_t * data);

/**
 * @brief Print the contents of ASTERIX message header.
 *
 * This function prints the category (CAT) and total length (LEN)
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a header structure.
 */
ASTERIX_API void print_header(const header * item);

#ifdef __cplusplus
}
#endif

#endif // COMMON_H