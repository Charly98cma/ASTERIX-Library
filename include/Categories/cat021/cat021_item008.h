/**
 * @file cat021_item008.h
 * @brief Definition of item 008 of CAT 021, and related functions and values
 */

#ifndef CAT021_ITEM008_H
#define CAT021_ITEM008_H

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
 * @typedef cat021_item008
 * @brief Category 21 / Item 008 - Aircraft Operational Status
 * 
 * Identification of the operational services available in the
 * aircraft while airborne
 */
typedef struct cat021_item008 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** @brief TCAS Resolution Advisory active
             * 
             * = 0 not active |
             * = 1 active
             */
            uint8_t RA      :1;
            /** @brief Target Trajectory Change Report Capability
             * 
             * = 0 no capability for Trajectory Change Reports |
             * = 1 support for TC+0 reports only |
             * = 2 support for multiple TC reports |
             * = 3 reserved
             */
            uint8_t TC      :2;
            /** @brief Target State Report Capability
             * 
             * = 0 no capability to support Target State Reports |
             * = 1 capable of supporting Target State Reports
             */
            uint8_t TS      :1;
            /** @brief Air-Referenced Velocity Report Capability
             * 
             * = 0 no capability to generate ARV-reports |
             * = 1 capable of generate ARV-reports */
            uint8_t ARV     :1;
            /** @brief Cockpit Display of Traffic Information airborne
             * 
             * = 0 CDTI not operational |
             * = 1 CDTI operational
             */
            uint8_t CDTI    :1;
            /** @brief Not TCAS System Status
             * 
             * = 0 NTCAS operational |
             * = 1 NTCAS not operational
             */
            uint8_t NTCAS    :1;
            /** @brief Single Antenna
             * 
             * = 0 Antenna Diversity |
             * = 1 Single Antenna only
             */
            uint8_t SA      :1;
        };
    };
} cat021_item008;

/*******************************************************************************
 * Function headers
 ******************************************************************************/

ASTERIX_API uint8_t get_cat021_item008_RA(const cat021_item008 * item);
ASTERIX_API uint8_t get_cat021_item008_TC(const cat021_item008 * item);
ASTERIX_API uint8_t get_cat021_item008_TS(const cat021_item008 * item);
ASTERIX_API uint8_t get_cat021_item008_ARV(const cat021_item008 * item);
ASTERIX_API uint8_t get_cat021_item008_CDTI(const cat021_item008 * item);
ASTERIX_API uint8_t get_cat021_item008_NTCAS(const cat021_item008 * item);
ASTERIX_API uint8_t get_cat021_item008_SA(const cat021_item008 * item);

ASTERIX_API void print_cat021_item008(const cat021_item008 *item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM008_H */