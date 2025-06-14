/**
 * @file cat021_item015.h
 * @brief Definition of item 015 of CAT 021, and related functions and values
 */

#ifndef cat021_item015_H
#define cat021_item015_H

#include <stdint.h>
#include "visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item015
 * @brief Category 021 / Item 015 - Service Identification
 * 
 * Identification of the service provided to one or more users.
 */
typedef struct cat021_item015 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        struct {
            /// @brief Service Identification (direct access)
            uint8_t SI;
        };
    };
} cat021_item015;

/*******************************************************************************
 * Function headers
 ******************************************************************************/

ASTERIX_API uint8_t get_cat021_item015_SI(const cat021_item015 * item);

void print_cat021_item015(const cat021_item015 *item);

#ifdef __cplusplus
}
#endif

#endif /* cat021_item015_H */