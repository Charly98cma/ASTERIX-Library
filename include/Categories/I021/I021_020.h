/**
 * @file I021_020.h
 * @brief Definition of I021/020, and related functions and values
 */

#ifndef I021_020_H
#define I021_020_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_020_ECAT_NO_INFO                    0 // No information
#define I021_020_ECAT_LIGHT_AC                   1 // Light aircraft (MTOW < 15500 lb / 7000 kg)
#define I021_020_ECAT_SMALL_AC                   2 // Small aircraft (7000 kg < MTOW < 136000 kg)
#define I021_020_ECAT_MEDIUM_AC                  3 // Medium aircraft (136000 kg < MTOW < 255000 kg)
#define I021_020_ECAT_HIGH_VORTEX_LARGE_AC       4 // High Vortex Large
#define I021_020_ECAT_HEAVY_AC                   5 // Heavy aircraft (MTOW > 136000 kg)
#define I021_020_ECAT_HIGHLY_MANEUVERABLE_AC     6 // Highly maneuverable (e.g. acrobatic)
#define I021_020_ECAT_ROTOCRAFT                 10 // Rotorcraft
#define I021_020_ECAT_GLIDER                    11 // Glider / Sailplane
#define I021_020_ECAT_LTA_AIRCRAFT              12 // Lighter-than-air aircraft (LTA)
#define I021_020_ECAT_UNMANNED_AIRCRAFT         13 // Unmanned Aerial Vehicle (UAV) / Drone
#define I021_020_ECAT_SPACE_VEHICLE             14 // Space / Transatmospheric Vehicle
#define I021_020_ECAT_UL_HGL_PGL                15 // Ultra-light / hang-glider / paraglider
#define I021_020_ECAT_PARACHUTE                 16 // Parachute / Skydiver
#define I021_020_ECAT_SURF_EM_VEH               20 // Surface emergency vehicle
#define I021_020_ECAT_SER_VEH                   21 // Service vehicle
#define I021_020_ECAT_GROUND_OBS                22 // Ground obstruction
#define I021_020_ECAT_CLUSTER_OBS               23 // Cluster obstacle
#define I021_020_ECAT_LINE_OBS                  24 // Line obstacle

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_020
 * @brief Category 021 / Item 020 - Emitter Category
 * 
 * Characteristics of the originating ADS-B unit
 */
typedef struct I021_020 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** 
             * @brief Emitter Category
             * 
             * Refer to category codes for detailed meaning.
             */
            uint8_t ECAT;
        };
    };
} I021_020;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Emitter Category (ECAT) from I021/020.
 * 
 * Portable access to the ECAT bits, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_020 structure.
 * @return uint8_t Value of ECAT (0: not active, 1: active)
 */
ASTERIX_API uint8_t get_I021_020_ECAT(const I021_020 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Emitter Category (ECAT) value into I021/020
 * 
 * If the provided value is out of range, it will be set to NO_INFO (0).
 * 
 * @param item Pointer to I021_020 structure.
 * @param sic_value Value of ECAT
 */
ASTERIX_API void set_I021_020_ECAT(I021_020 * item, uint8_t ecat);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/**
 * @brief
 * 
 * @param item_in
 * @param msg_out
 * @param out_index
 * 
 * @return uint16_t
 */
ASTERIX_API uint16_t encode_I021_020(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/**
 * @brief
 * 
 * @param item_in
 * @param msg_in
 * @param in_index
 * 
 * @return uint16_t
 */
ASTERIX_API uint16_t decode_I021_020(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 020.
 *
 * This function prints the values of the main byte.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a I021_020 structure.
 */
ASTERIX_API void print_I021_020(const I021_020 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_020_H */