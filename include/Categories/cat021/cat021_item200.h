/**
 * @file cat021_item200.h
 * @brief Definition of CAT 021 Item 200, and related functions and values
 */

#ifndef CAT021_ITEM200_H
#define CAT021_ITEM200_H

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
 * @typedef cat021_item200
 * @brief Category 021 Item 200 - Target Status
 * 
 * Status of the target
 */
typedef struct cat021_item200 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Intent Change Flag
             * 
             * =0 No intent change active | =1 Intent change flag raised
             * 
             * @note See Note 1 in ASTERIX Specification
             */
            uint8_t ICF         :1;
            /**
             * @brief Lateral NAVigation Mode
             * 
             * =0 LNAV Mode engaged | =1 LNAV Mode not engaged
             * 
             * @note See Note 2 in ASTERIX Specification Standard
             */
            uint8_t LNAV        :1;
            /**
             * @brief Military Emergency
             * 
             * =0 No emergency | =1 Emergency
             */
            uint8_t ME          :1;
            /**
             * @brief Priority Status
             * 
             * =0 No emergency / not reported |
             * =1 General emergency |
             * =2 Lifeguard / medical emergency |
             * =3 Minimum fuel |
             * =4 No communications |
             * =5 Unlawful interference |
             * =6 “Downed” Aircraft
             * 
             * @note See Note 3 in ASTERIX Specification Standard
             */
            uint8_t PS          :3;
            /**
             * @brief Surveillance Status
             * 
             * = 0 No condition reported |
             * = 1 Permanent Alert (Emergency condition) |
             * = 2 Temporary Alert (change in M3/A Code other than emergency) |
             * = 3 SPI set
             */
            uint8_t SS          :2;
        };
    };
} cat021_item200;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Intent Change Flag (ICF) value from Cat 021 Item 200
 * 
 * @param item pointer to cat021_item200 structure
 * 
 * @return uint8_t value of ICF (0: No intent change active;
 *                               1: Intent change flag raised)
 */
ASTERIX_API uint8_t get_cat021_item200_ICF(const cat021_item200 * item);

/**
 * @brief Get the Laterl NAVigation Mode (LNAV) value from Cat 021 Item 200
 * 
 * @param item pointer to cat021_item200 structure
 * 
 * @return uint8_t value of LNAV (0: LNAV Mode engaged;
 *                                1: LNAV Mode not engaged)
 */
ASTERIX_API uint8_t get_cat021_item200_LNAV(const cat021_item200 * item);

/** @brief Get the Military Emergency (EM) value from Cat 021 Item 200
 * 
 * @param item pointer to cat021_item200 structure
 * 
 * @return uint8_t value of ME (0: No emergency; 1: Emergency)
 */
ASTERIX_API uint8_t get_cat021_item200_ME(const cat021_item200 * item);

/**
 * @brief Get the Priority Status (PS) value from Cat 021 Item 200
 * 
 * @param item pointer to cat021_item200 structure
 * 
 * @return uint8_t value of PS (0: No emergency / not reported;
 *                              1: General emergency;
 *                              2: Lifeguard / medical emergency;
 *                              3: Minimum fuel;
 *                              4: No communications;
 *                              5: Unlawful interference;
 *                              6: “Downed” Aircraft)
 */
ASTERIX_API uint8_t get_cat021_item200_PS(const cat021_item200 * item);

/**
 * @brief Get the Special Surveillance Status (SS) value from Cat 021 Item 200
 * 
 * @param item pointer to cat021_item200 structure
 * 
 * @return uint8_t value of SS (0: No condition reported;
*                               1: Permanent Alert (Emergency condition);
*                               2: Temporary Alert (change in M3/A Code
                                                    other than emergency);
*                               3: SPI set)
 */
ASTERIX_API uint8_t get_cat021_item200_SS(const cat021_item200 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the new Intent Change Flag (ICF) value into Cat 021 Item 200 
 * 
 * @param item pointer to cat021_item200 structure
 * @param icf new value to write into the item (0: No intent change active;
 *                                              1: Intent change flag raised)
 */
ASTERIX_API void set_cat021_item200_ICF(cat021_item200 * item, const uint8_t icf);

/**
 * @brief Set the new Lateral NAVigation Mode (LNAV) value into Cat 021 Item 200 
 * 
 * @param item pointer to cat021_item200 structure
 * @param lnav new value to write into the item (0: LNAV Mode engaged;
 *                                               1: LNAV Mode not engaged)
 */
ASTERIX_API void set_cat021_item200_LNAV(cat021_item200 * item, const uint8_t lnav);

/**
 * @brief Set the new Military Emergency (ME) value into Cat 021 Item 200 
 * 
 * @param item pointer to cat021_item200 structure
 * @param me new value to write into the item (0: No emergency; 1: Emergency)
 */
ASTERIX_API void set_cat021_item200_ME(cat021_item200 * item, const uint8_t me);

/**
 * @brief Set the new Priority Status (PS) value into Cat 021 Item 200 
 * 
 * @param item pointer to cat021_item200 structure
 * @param ps new value to write into the item (0: No emergency / not reported;
 *                                             1: General emergency;
 *                                             2: Lifeguard / medical emergency;
 *                                             3: Minimum fuel;
 *                                             4: No communications;
 *                                             5: Unlawful interference;
 *                                             6: “Downed” Aircraft)
 */
ASTERIX_API void set_cat021_item200_PS(cat021_item200 * item, const uint8_t ps);

/**
 * @brief Set the new Surveillance Status (SS) value into Cat 021 Item 200 
 * 
 * @param item pointer to cat021_item200 structure
 * @param ss new value to write into the item (0: No condition reported;
 *                                             1: Permanent Alert
                                                  (Emergency condition);
 *                                             2: Temporary Alert
                                                  (change in M3/A Code other
                                                  than emergency);
 *                                             3: SPI set)
 */
ASTERIX_API void set_cat021_item200_SS(cat021_item200 * item, const uint8_t ss);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Target Status of the Cat 021 Item 200
 * 
 * @param item pointer to cat021_item200 structure
 */
ASTERIX_API void print_cat021_item200(const cat021_item200 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM200_H */