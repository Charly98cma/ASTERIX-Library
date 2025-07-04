/**
 * @file cat021_item271.h
 * @brief Definition of CAT 021 Item 271, and related functions and values
 */

#ifndef CAT021_ITEM271_H
#define CAT021_ITEM271_H

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
 * @typedef cat021_item271_ext1
 * @brief Category 021 Item 271 First Extension - Length / Width of Aircraft
 */
typedef struct cat021_item271_ext1 {
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
             * @brief Length and width of the aircraft
             *        (see Specification Standard for value encoding)
             */
            uint8_t LW          :4;
            /// @brief Spare its-4/2 set to 0
            uint8_t spare;
            /** 
             * @brief Field Extension
             * 
             * = 0 End of item |
             * = 1 Extension into second extension
             */
            uint8_t FX          :1;
        };
    };
} cat021_item271_ext1;


/**
 * @typedef cat021_item271
 * @brief Category 021 Item 271 - Surface Capabilities and Characteristics
 * 
 *  Operational capabilities of the aircraft while on the ground.
 */
typedef struct cat021_item271 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bits-8/7 set to 0
            uint8_t spare       :2;
            /**
             * @brief Position Offset Applied
             * 
             * = 0 Position transmitted is not ADS-B position reference point |
             * = 1 Position transmitted is the ADS-B position reference point
             */
            uint8_t POA         :1;
            /**
             * @brief Cockpit Display of Traffic Information Surface
             * 
             * = 0 CDTI not operational |
             * = 1 CDTI operational
             */
            uint8_t CDTIS       :1;
            /**
             * @brief Class B2 transmit power less than 70 Watts
             * 
             * = 0 >= 70 Watts |
             * = 1 < 70 Watts
             */
            uint8_t B2          :1;
            /**
             * @brief Receiving ATC Services
             * 
             * = 0 Aircraft not receiving ATC-services |
             * = 1 Aircraft receiving ATC services
             */
            uint8_t RAS         :1;
            /**
             * @brief Setting of "IDENT"-switch
             * 
             * = 0 IDENT switch not active |
             * = 1 IDENT switch active
             */
            uint8_t IDENT       :1;
            /** 
             * @brief Field Extension
             * 
             * = 0 End of item |
             * = 1 Extension into second extension
             */
            uint8_t FX          :1;
        };
    };
    /// @brief First extension of Category 021 Item 271
    cat021_item271_ext1 ext1;
} cat021_item271;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Position Offset Applied (POA) value from Cat 021 Item 271
 * 
 * @param item pointer to cat021_item271 structure
 * 
 * @return uint8_t value of POA (0: pos. not ADS-B ref. point;                                                
 *                               1: pos. is ADS-B ref. point)
 */
ASTERIX_API uint8_t get_cat021_item271_POA(const cat021_item271 * item);

/**
 * @brief Get the Cockpit Display of Traffic Information Surface (CDTIS) value
 *        from Cat 021 Item 271
 * 
 * @param item pointer to cat021_item271 structure
 * 
 * @return uint8_t Value of CDTIS (0: not operational; 1: operational)
 */
ASTERIX_API uint8_t get_cat021_item271_CDTIS(const cat021_item271 * item);

/**
 * @brief Get the Class B2 transmit power less than 70 Watts (B2) value
 *        from Cat 021 Item 271
 * 
 * @param item pointer to cat021_item271 structure
 * 
 * @return uint8_t Value of B2 (0: >= 70 Watts; 1: < 70 Watts)
 */
ASTERIX_API uint8_t get_cat021_item271_B2(const cat021_item271 * item);

/**
 * @brief Get the Receiving ATC Services (RAS) value from Cat 021 Item 271
 * 
 * @param item pointer to cat021_item271 structure
 * 
 * @return uint8_t Value of RAS (0: A/C not rec. ATC-services;
 *                               1: A/C receiving ATC-services)
 */
ASTERIX_API uint8_t get_cat021_item271_RAS(const cat021_item271 * item);

/**
 * @brief Get the Setting of "IDENT"-switch (IDENT) value from Cat 021 Item 271
 * 
 * @param item pointer to cat021_item271 structure
 * 
 * @return uint8_t Value of IDENT (0: not active; 1: active)
 */
ASTERIX_API uint8_t get_cat021_item271_IDENT(const cat021_item271 * item);

/**
 * @brief Get the Field Extension (FX) value from Cat 021 Item 271
 * 
 * @param item pointer to cat021_item271 structure
 * 
 * @return uint8_t Value of FX (0: end of item; 1: first extension present)
 */
ASTERIX_API uint8_t get_cat021_item271_FX(const cat021_item271 * item);


/**
 * @brief Get the Length and width of the aircraft (LW) from Cat 021 Item 171
 * 
 * @param item pointer to cat021_item271 structure
 * 
 * @return uint8_t Value of LW (see Specification Standard for value encoding)
 */
ASTERIX_API uint8_t get_cat021_item271_ext1_LW(const cat021_item271_ext1 * item);

/**
 * @brief Get the Field Extension (FX) value from Cat 021 Item 271 First Extension
 * 
 * @param item pointer to cat021_item271 structure
 * 
 * @return uint8_t Value of FX (0: end of item; 1: second extension present)
 */
ASTERIX_API uint8_t get_cat021_item271_ext1_FX(const cat021_item271_ext1 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================ PRIMARY SUBFIELD ============================ */

/**
 * @brief Set a new value for Position Offset Applied (POA) into Cat 021 Item 271
 * 
 * @param item pointer to cat021_item271 structure
 * @param poa new POA value (0: pos. not ADS-B ref. point;                                                
 *                           1: pos. is ADS-B ref. point)
 */
ASTERIX_API void set_cat021_item271_POA(cat021_item271 * item,
                                        const uint8_t poa);

/**
 * @brief Set a new value for Cockpit Display of Traffic Information Surface
 *        (CDTIS) into cat 021 Item 271
 * 
 * @param item pointer to cat021_item271 structure
 * @param cdtis new CDTIS value (0: not operational; 1: operational)
 */
ASTERIX_API void set_cat021_item271_CDTIS(cat021_item271 * item,
                                          const uint8_t cdtis);

/**
 * @brief Set a new value for Class B2 transmit power less than 70 Watts (B2)
 *        into Cat 021 Item 271
 * 
 * @param item pointer to cat021_item271 structure
 * @param b2 New B2 value (0: >= 70 Watts; 1: < 70 Watts)
 */
ASTERIX_API void set_cat021_item271_B2(cat021_item271 * item,const uint8_t b2);

/**
 * @brief Set a new value for Receiving ATC Services (RAS) value into
 *        Cat 021 Item 271
 * 
 * @param item pointer to cat021_item271 structure
 * @param ras new RAS value (0: A/C not rec. ATC-services;
 *                           1: A/C receiving ATC-services)
 */
ASTERIX_API void set_cat021_item271_RAS(cat021_item271 * item,
                                        const uint8_t ras);

/**
 * @brief Set a new value for Setting of "IDENT"-switch (IDENT) into
 *        Cat 021 Item 271
 * 
 * @param item pointer to cat021_item271 structure
 * @param ident new IDENT value (0: not active; 1: active)
 */
ASTERIX_API void set_cat021_item271_IDENT(cat021_item271 * item,
                                         const uint8_t ident);

/**
 * @brief Set a new value for Field Extension (FX) into Cat 021 Item 271
 * 
 * @param item pointer to cat021_item271 structure
 * @param fx new FX value (0: end of item; 1: first extension present)
 */
ASTERIX_API void set_cat021_item271_FX(cat021_item271 * item, const uint8_t fx);

/* ============================ FIRST EXTENSION ============================ */

/**
 * @brief Set a new value for Length and width of the aircraft (LW) into
 *        Cat 021 Item 171
 * 
 * @param item pointer to cat021_item271 structure
 * @param lw new LW value (see Specification Standard for value encoding)
 */
ASTERIX_API void set_cat021_item271_ext1_LW(cat021_item271_ext1 * item,
                                            const uint8_t lw);

/**
 * @brief Set a new value for Field Extension (FX) into Cat 021 Item 271
 *        First Extension
 * 
 * @param item pointer to cat021_item271 structure
 * @param lw New FX value (0: end of item; 1: second extension present)
 */
ASTERIX_API void set_cat021_item271_ext1_FX(cat021_item271_ext1 * item,
                                            const uint8_t fx);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the contents of Cat 021 Item 271 and its extension if present
 * 
 * @param item pointer to cat021_item271 structure
 */
ASTERIX_API void print_cat021_item271(const cat021_item271 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM271_H */