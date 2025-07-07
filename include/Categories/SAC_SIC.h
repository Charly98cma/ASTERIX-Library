/**
 * @file SAC_SIC.h
 * @brief Definition of Item 010 and SAC/SIC values
 */

#ifndef SAC_SIC_H
#define SAC_SIC_H

#include <stdint.h>

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
 * @typedef SAC_SIC
 * @brief Data Source Identification
 * 
 * Identification of the ADS-B station providing information.
 * 
 * Item present in every ASTERIX record
 */
typedef struct SAC_SIC {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief System Area Code (8 bits)
            uint8_t sac;
            /// @brief System Identification Code (8 bits)
            uint8_t sic;
        };
    };
} SAC_SIC;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the System Area Code (SAC) from item 010.
 * 
 * Portable access to the SAC bits, independent of compiler and endianness.
 * 
 * @param item Pointer to SAC_SIC structure.
 * @return uint8_t Value of SAC
 */
uint8_t get_SAC(const SAC_SIC * item);

/**
 * @brief Get the System Identification Code (SIC) from item 010.
 * 
 * Portable access to the SIC bits, independent of compiler and endianness.
 * 
 * @param item Pointer to SAC_SIC structure.
 * @return uint8_t Value of SIC
 */
uint8_t get_SIC(const SAC_SIC * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the System Area Code (SAC) into the raw field.
 * 
 * @param item Pointer to SAC_SIC structure.
 * @param sac_value Value of the SAC
 */
void set_SAC(SAC_SIC * item, uint8_t sac_value);

/**
 * @brief Set the System Identification Code (SIC) into the raw field.
 * 
 * @param item Pointer to SAC_SIC structure.
 * @param sic_value Value of the SIC
 */
void set_SIC(SAC_SIC * item, const uint8_t sic_value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* SAC_SIC_H */