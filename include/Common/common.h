/**
 * @file common.h
 * @brief Values, types and function headers used troughout the project
 */

#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include "visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * MACROS
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
 * Function headers
 ******************************************************************************/

ASTERIX_API uint8_t  get_CAT(const uint8_t * data);
ASTERIX_API uint16_t get_LEN(const uint8_t * data);

ASTERIX_API uint8_t  get_header_CAT(const header * item);
ASTERIX_API uint16_t get_header_LEN(const header * item);

ASTERIX_API void print_header(const header * item);

#ifdef __cplusplus
}
#endif

#endif // COMMON_H