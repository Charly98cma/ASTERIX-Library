/**
 * @file sac_sic.h
 * @brief Definition of Item 010 and SAC/SIC values
 */

#ifndef item010_H
#define item010_H

#include <stdint.h>
#include "visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

// https://www.eurocontrol.int/asterix

/*******************************************************************************
 * Structures and types
 ******************************************************************************/

/**
 * @typedef item010
 * @brief Data Source Identification
 * 
 * Identification of the ADS-B station providing information.
 * 
 * Item present in every ASTERIX record
 */
typedef struct item010 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint16_t raw;
        
        struct {
            /// @brief System Area Code (8 bits)
            uint8_t sac;
            /// @brief System Identification Code (8 bits)
            uint8_t sic;
        };
    };
} item010; // Item 010 for all CATs

/*******************************************************************************
 * Function headers
 ******************************************************************************/

ASTERIX_API uint8_t get_item010_SAC(const item010 * item);
ASTERIX_API uint8_t get_item010_SIC(const item010 * item);

ASTERIX_API void print_cat021_item008(const item010 *item);

#ifdef __cplusplus
}
#endif

#endif /* item010_H */