/**
 * @file cat021_item400.h
 * @brief Definition of CAT 021 Item 400, and related functions and values
 */

#ifndef CAT021_ITEM400_H
#define CAT021_ITEM400_H

#include <stdint.h>
#include "Common/visibility.h"

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
 * @typedef cat021_item400
 * @brief Category 021 Item 400 - Receiver ID
 * 
 * Designator of Ground Station in Distributed System
 */
typedef struct cat021_item400 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            uint8_t RID;
        };
    };
} cat021_item400;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Receiver ID (RID) value from Cat 021 Item 400
 * 
 * @param item pointer to cat021_item400 structure
 * 
 * @return value of the Received ID
 */
ASTERIX_API uint8_t get_cat021_item400_RID(const cat021_item400 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the new Receiver ID (RID) value into Cat 021 Item 400
 * 
 * @param item pointer to cat021_item400 structure
 * @param rid new RID value
 */
ASTERIX_API void set_cat021_item400_RID(cat021_item400 * item,
                                        const uint8_t rid);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the contents of Cat 021 Item 400 and its extension if present
 * 
 * @param item pointer to cat021_item400 structure
 */
ASTERIX_API void print_cat021_item400(const cat021_item400 * item);


#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM400_H */