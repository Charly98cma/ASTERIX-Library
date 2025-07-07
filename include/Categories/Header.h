/**
 * @file Header.h
 * @brief Structure and functions of the ASTERIX header present in all messages
 */

#ifndef HEADER_H
#define HEADER_H

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
 * @typedef Header
 * @brief Header type of ASTERIX messages
 * 
 * Type used to represent the header of any ASTERIX message,
 * with the category and length (in Bytes) of the message.
 */
typedef struct Header {
    /// @brief Asterix category (range from 0 to 255)
    uint8_t cat;
    /// @brief Full length of the message
    uint8_t len[2];
} Header;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Extracts the ASTERIX Category of the given header.
 * 
 * The ASTERIX Category is always the first octet of the ASTERIX message.
 * This function safely reads the category from a received data block.
 * 
 * @param data Pointer to the received Header sructure
 * @return uint8_t The category number (CAT). Returns 0 if data is NULL.
 * 
 * @note The category identifies the type of ASTERIX message,
 *       such as CAT021, CAT048, etc.
 */
ASTERIX_API uint8_t get_Header_CAT(const Header * item);

/**
 * @brief Extracts the ASTERIX Category of the given raw char array
 * 
 * The ASTERIX Category is always the first octet of the ASTERIX message.
 * This function safely reads the category from a received data block.
 * 
 * @param raw_data Pointer to the received data array (minimum 1 byte).
 * @return uint8_t The category number (CAT). Returns 0 if data is NULL.
 * 
 * @note The category identifies the type of ASTERIX message,
 *       such as CAT021, CAT048, etc.
 */
ASTERIX_API uint8_t get_Header_CAT_raw_data(const unsigned char * raw_data);

/**
 * @brief Extracts the total length of the ASTERIX message.
 * 
 * The length of the ASTERIX message is always located in octets 2 and 3 and is encoded
 * in **big-endian** format (most significant byte first). This function reads and combines
 * those two bytes into a 16-bit length.
 * 
 * @param data Pointer to the received Header structure
 * @return uint16_t Total length of the ASTERIX message in bytes. Returns 0 if data is NULL.
 * 
 * @note The length includes the category byte and the length field itself.
 */
ASTERIX_API uint16_t get_Header_LEN(const Header * item);

/**
 * @brief Extracts the total length of the ASTERIX message from given raw char array
 * 
 * The length of the ASTERIX message is always located in octets 2 and 3 and is encoded
 * in **big-endian** format (most significant byte first). This function reads and combines
 * those two bytes into a 16-bit length.
 * 
 * @param raw_data Pointer to the received data array (minimum 3 bytes).
 * @return uint16_t Total length of the ASTERIX message in bytes. Returns 0 if data is NULL.
 * 
 * @note The length includes the category byte and the length field itself.
 */
ASTERIX_API uint16_t get_Header_LEN_raw_data(const unsigned char * raw_data);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Sets the given ASTERIX Category of the ASTERIX message
 * 
 * The ASTERIX Category is always the first octet of the ASTERIX message.
 * This function safely reads the category from a received data block.
 * 
 * @param data Pointer to the received Header sructure
 * @param cat Category number (CAT) of the message
 * 
 * @note The category identifies the type of ASTERIX message,
 *       such as CAT021, CAT048, etc.
 */
ASTERIX_API void set_Header_CAT(Header * item, const uint8_t cat);

/**
 * @brief Sets the new total length of the ASTERIX message.
 * 
 * The length of the ASTERIX message is always located in octets 2 and 3 and is encoded
 * in **big-endian** format (most significant byte first). This function reads and combines
 * those two bytes into a 16-bit length.
 * 
 * @param data Pointer to the received Header structure
 * @param len New total length of the ASTERIX message in bytes.
 * 
 * @note The length includes the category byte and the length field itself.
 */
ASTERIX_API void set_Header_LEN(Header * item, const uint16_t len);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of ASTERIX message header.
 *
 * This function prints the category (CAT) and total length (LEN)
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to Header structure.
 */
ASTERIX_API void print_Header(const Header * item);

#ifdef __cplusplus
}
#endif

#endif // HEADER_H