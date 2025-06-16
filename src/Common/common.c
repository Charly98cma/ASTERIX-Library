/**
 * @file common.c
 * @brief Implementation of the function to read CAT and LEN
 */

#include "common.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Message Category (CAT) from the ASTERIX header.
 * 
 * Portable access to the CAT bits, independent of compiler and endianness.
 * 
 * @param item Pointer to header_t structure.
 * @return uint8_t Value of CAT
 */
uint8_t get_header_CAT(const header * item)
{
    return ((item)->CAT);
}

/**
 * @brief Get the Message Length (LEN) from the ASTERIX header.
 * 
 * Portable access to the LEN field, independent of compiler and endianness.
 * 
 * @param item Pointer to header_t structure.
 * @return uint8_t Value of LEN (total length of the ASTERIX message)
 */
uint16_t get_header_LEN(const header * item)
{
    return ((item)->LEN);
}

/*******************************************************************************
 * Other Functions
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
uint8_t get_CAT(const uint8_t * data)
{
    return (data == NULL) ? 0 : data[0];
}

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
uint16_t get_LEN(const uint8_t * data)
{
    return (data == NULL) ? 0 : (uint16_t) ((data[1] << 8) | data[2]);
}

/**
 * @brief Print the contents of ASTERIX message header.
 *
 * This function prints the category (CAT) and total length (LEN)
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a header structure.
 */
void print_header(const header * item)
{
    printf("ASTERIX header\n");
    printf("  CAT = %d\n", get_header_CAT(item));
    printf("  LEN = %d\n", get_header_LEN(item));
}