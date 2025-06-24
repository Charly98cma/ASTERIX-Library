/**
 * @file cat021_item146.h
 * @brief Definition of CAT 021 Item 146, and related functions and values
 */

#ifndef CAT021_ITEM146_H
#define CAT021_ITEM146_H

#include <stdio.h>
#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * Macros
 ******************************************************************************/

#define LSB_CAT021_ITEM146_ALT                        25         /// LSB = 25 ft

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

 /**
 * @typedef cat021_item146
 * @brief Category 021 Item 146 - Flight Level
 * 
 * The Selected Altitude as provided by the avionics and
 * corresponding either to the MCP/FCU Selected Altitude (the ATC
 * cleared altitude entered by the flight crew into the avionics) or to
 * the FMS Selected Altitude
 */
typedef struct cat021_item146 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint16_t raw;

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
} cat021_item146;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Source Availability (SAS) value from Cat 021 Item 146
 * 
 * @param item Pointer to cat021_item146 structure
 * 
 * @return uint8_t SAS value (0: no source, 1: source provided)
 */
ASTERIX_API uint8_t get_cat021_item146_SAS(const cat021_item146 * item);

/**
 * @brief Get the altitude Source (SRC) value from Cat 021 Item 146 
 * 
 * @param item Pointer to cat021_item146 structure
 * 
 * @return uint8_t Source value (0: unknown,
 *                               1: A/C holding alt.,
 *                               2: MCP/FCU sel. alt.,
 *                               3: FMS sel. alt.)
 */
ASTERIX_API uint8_t get_cat021_item146_SRC(const cat021_item146 * item);

/**
 * @brief Get the Altitude (ALT) value in feets (LSB = 25 ft)
 *        from Cat 021 Item 146 
 * 
 * @param item Pointer to cat021_item146 structure
 * 
 * @return int32_t altitude in feets
 */
ASTERIX_API int32_t get_cat021_item146_ALT(const cat021_item146 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given altitude Source Availability (SAS) value into
 *        Cat 021 Item 146
 * 
 * @param item Pointer to cat021_item146 structure
 * @param value New SAS value
 */
ASTERIX_API void set_cat021_item146_SAS(cat021_item146 * item, uint8_t sas);

/**
 * @brief Set the given altitude Source (SRC) value into
 *        Cat 021 Item 146
 * 
 * @param item Pointer to cat021_item146 structure
 * @param value New SRC value (see values correspondance)
 */
ASTERIX_API void set_cat021_item146_SRC(cat021_item146 * item, uint8_t src);

/**
 * @brief Set the given Altitude (ALT) value (LSB = 25 ft) into
 *        Cat 021 Item 146
 * 
 * @param item Pointer to cat021_item146 structure
 * @param value New ALT value (LSB = 25 ft)
 */
ASTERIX_API void set_cat021_item146_ALT(cat021_item146 * item, int32_t alt);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Selected Altitude fields of the Cat 021 Item 146
 * 
 * @param item Pointer to cat021_item146 structure
 */
ASTERIX_API void print_cat021_item146(const cat021_item146 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM146_H */