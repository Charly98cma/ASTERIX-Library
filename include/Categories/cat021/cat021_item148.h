/**
 * @file cat021_item148.h
 * @brief Definition of CAT 021 Item 148, and related functions and values
 */

#ifndef CAT021_ITEM148_H
#define CAT021_ITEM148_H

#include <stdio.h>
#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * Macros
 ******************************************************************************/

#define LSB_CAT021_ITEM148_ALT                        25         /// LSB = 25 ft

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

 /**
 * @typedef cat021_item148
 * @brief Category 021 Item 148 - Final State Selected Altitude
 * 
 * The vertical intent value that corresponds with the ATC cleared altitude,
 * as derived from the Altitude Control Panel (MCP/FCU).
 */
typedef struct cat021_item148 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint16_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** @brief Manage Vertical Mode
             * 
             * = 0 Not active / Unknown |
             * = 1 Active
             */
            uint16_t MV         :1;
            /** @brief Altitude Hold Mode
             * 
             * = 0 Not active / Unknown |
             * = 1 Active
             */
            uint16_t AH         :1;
            /** @brief Approach Mode
             * 
             * = 0 Not active / Unknown |
             * = 1 Active
             */
            uint16_t AM         :1;
            /** @brief Altitude in two's complement form (LSB = 25 ft)
             * 
             * -1300ft <= Altitude <= 100000ft
             */
            uint16_t ALT        :13;
        };
    };
} cat021_item148;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Manage Vertical Mode (MV) value from Cat 021 Item 148
 * 
 * @param item Pointer to cat021_item148 structure
 * 
 * @return uint8_t MV value (0: no source, 1: source provided)
 */
ASTERIX_API uint8_t get_cat021_item148_MV(const cat021_item148 * item);

/**
 * @brief Get the Approach Hold (AH) value from Cat 021 Item 148 
 * 
 * @param item Pointer to cat021_item148 structure
 * 
 * @return uint8_t AH value (0: not active / unknown, 1: active)
 */
ASTERIX_API uint8_t get_cat021_item148_AH(const cat021_item148 * item);

/**
 * @brief Get the Approach Mode (AM) value from Cat 021 Item 148 
 * 
 * @param item Pointer to cat021_item148 structure
 * 
 * @return uint8_t AM value (0: not active / unknown, 1: active)
 */
ASTERIX_API uint8_t get_cat021_item148_AM(const cat021_item148 * item);

/**
 * @brief Get the Altitude (ALT) value in feets (LSB = 25 ft)
 *        from Cat 021 Item 148 
 * 
 * @param item Pointer to cat021_item148 structure
 * 
 * @return int32_t Altitude in feets (-1300ft <= ALT <= 100000 ft)
 */
ASTERIX_API int32_t get_cat021_item148_ALT(const cat021_item148 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Manage Vertical Mode (MV) into Cat 021 Item 148
 * 
 * @param item Pointer to cat021_item148 structure
 * @param value New MV value (0: not active / unknown, 1: active)
 */
ASTERIX_API void set_cat021_item148_MV(cat021_item148 * item, uint8_t sas);

/**
 * @brief Set the given Approach Hold (AH) into Cat 021 Item 148
 * 
 * @param item Pointer to cat021_item148 structure
 * @param value New AH value (0: not active / unknown, 1: active)
 */
ASTERIX_API void set_cat021_item148_AH(cat021_item148 * item, uint8_t src);

/**
 * @brief Set the given Approach Mode (AM) into
 *        Cat 021 Item 148
 * 
 * @param item Pointer to cat021_item148 structure
 * @param value New AM value (0: not active / unknown, 1: active)
 */
ASTERIX_API void set_cat021_item148_AM(cat021_item148 * item, uint8_t src);

/**
 * @brief Set the given Altitude (ALT) (LSB = 25 ft) into
 *        Cat 021 Item 148
 * 
 * @param item Pointer to cat021_item148 structure
 * @param value New ALT value (LSB = 25 ft)
 */
ASTERIX_API void set_cat021_item148_ALT(cat021_item148 * item, int32_t alt);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Final State Selected Altitude fields of the Cat 021 Item 148
 * 
 * @param item Pointer to cat021_item148 structure
 */
ASTERIX_API void print_cat021_item148(const cat021_item148 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM148_H */