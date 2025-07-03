/**
 * @file cat021_item220.h
 * @brief Definition of CAT 021 Item 220, and related functions and values
 */

#ifndef CAT021_ITEM220_H
#define CAT021_ITEM220_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/// @brief Cat 021 Item 220 Ext1 - Wind Speed LSB = 1 knot
#define CAT021_ITEM220_EXT1_LSB_WINDSPD     1
/// @brief Cat 021 Item 220 Ext2 - Wind Direction LSB = 1 degree
#define CAT021_ITEM220_EXT2_LSB_WINDDIR     1
/// @brief Cat 021 Item 220 Ext3 - Temperature LSB = 0.25 Celsius
#define CAT021_ITEM220_EXT3_LSB_TEMP        (double) (0.25)

/// @brief Maximum value of Wind Speed
#define CAT021_ITEM220_EXT1_MIN_WINDSPD     0
/// @brief Minimum value of Wind Speed
#define CAT021_ITEM220_EXT1_MAX_WINDSPD     360
/// @brief Maximum value of Wind Direction
#define CAT021_ITEM220_EXT1_MIN_WINDDIR     1
/// @brief Minimum value of Wind Direction
#define CAT021_ITEM220_EXT1_MAX_WINDDIR     360
/// @brief Maximum value of Temperature
#define CAT021_ITEM220_EXT1_MIN_TEMP        -100.0
/// @brief Minimum value of Temperature
#define CAT021_ITEM220_EXT1_MAX_TEMP        100.0
/// @brief Maximum value of Turbulance
#define CAT021_ITEM220_EXT1_MIN_TURB        0
/// @brief Minimum value of Turbulance
#define CAT021_ITEM220_EXT1_MAX_TURB        15

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item220_ext1
 * @brief Category 021 Item 220 Subfield #1 - Wind Speed
 */
typedef struct cat021_item220_ext1 {
    /**
     * @brief Wind Speed
     * 
     * Range: 0 <= WINDSPD <= 300
     * 
     * LSB = 1 knot
     */
    uint8_t WINDSPD[2];
} cat021_item220_ext1;

/**
 * @typedef cat021_item220_ext2
 * @brief Category 021 Item 220 Subfield #2 - Wind Direction
 */
typedef struct cat021_item220_ext2 {
    /**
     * @brief Wind Direction
     * 
     * Range: 1 <= WINDDIR <= 360
     * 
     * LSB = 1 degree
     */
    uint8_t WINDDIR[2];
} cat021_item220_ext2;

/**
 * @typedef cat021_item220_ext3
 * @brief Category 021 Item 220 Subfield #3 - Temperature
 */
typedef struct cat021_item220_ext3 {
    /**
     * @brief Temperature
     * 
     * Range: -100 <= TEMP <= 100
     * 
     * LSB = 0.25 Celsius
     */
    int8_t TEMP[2];
} cat021_item220_ext3;

/**
 * @typedef cat021_item220_ext4
 * @brief Category 021 Item 220 Subfield #4 - Turbulance
 */
typedef struct cat021_item220_ext4 {
    /**
     * @brief Turbulance
     * 
     * Range: 0 <= TURB <= 15
     */
    uint8_t TURB;
} cat021_item220_ext4;

/**
 * @typedef cat021_item220
 * @brief Category 021 Item 220 - Met Information
 * 
 * Meteorological information.
 */
typedef struct cat021_item220 {
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
             * @brief Wind Speed
             * 
             * 0: absence of Subfield #1 | 1: presence of Subfield #1
             */
            uint8_t WS          :1;
            /**
             * @brief Wind Direction
             * 
             * 0: absence of Subfield #2 | 1: presence of Subfield #2
             */
            uint8_t WD          :1;
            /**
             * @brief Temperature
             * 
             * 0: absence of Subfield #3 | 1: presence of Subfield #3
             */
            uint8_t TEMP        :1;
            /**
             * @brief Turbulance
             * 
             * 0: absence of Subfield #4 | 1: presence of Subfield #4
             */
            uint8_t TRB         :1;
            /// @brief Spare bits-4/2 set to 0
            uint8_t spare       :3;
            /**
             * @brief Extension Indicator
             * 
             * 0: no extension | 1: extension
             */
            uint8_t FX          :1;
        };
    };
    /// @brief Subfield #1
    cat021_item220_ext1 ext1;
    /// @brief Subfield #2
    cat021_item220_ext2 ext2;
    /// @brief Subfield #3
    cat021_item220_ext3 ext3;
    /// @brief Subfield #4
    cat021_item220_ext4 ext4;
} cat021_item220;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

/**
 * @brief Get Wind Speed (WS) subfield presence from Cat 021 Item 220
 *        Primary Subfield
 * 
 * @param item pointer to cat021_item220 structure
 * 
 * @return uint8_t (0: absence of subfield #1; 1: presence of subfield #1)
 */
ASTERIX_API uint8_t get_cat021_item220_WS(const cat021_item220 * item);

/**
 * @brief Get Wind Direction (WINDDIR) subfield presence from Cat 021 Item 220
 *        Primary Subfield
 * 
 * @param item pointer to cat021_item220 structure
 * 
 * @return uint8_t (0: absence of subfield #2; 1: presence of subfield #2)
 */
ASTERIX_API uint8_t get_cat021_item220_WD(const cat021_item220 * item);

/**
 * @brief Get Temperature (TEMP) subfield presence from Cat 021 Item 220
 *        Primary Subfield
 * 
 * @param item pointer to cat021_item220 structure
 * 
 * @return uint8_t (0: absence of subfield #3; 1: presence of subfield #3)
 */
ASTERIX_API uint8_t get_cat021_item220_TEMP(const cat021_item220 * item);

/**
 * @brief Get Turbulance (TURB) subfield presence from Cat 021 Item 220
 *        Primary Subfield
 * 
 * @param item pointer to cat021_item220 structure
 * 
 * @return uint8_t (0: absence of subfield #4; 1: presence of subfield #4)
 */
ASTERIX_API uint8_t get_cat021_item220_TRB(const cat021_item220 * item);

/**
 * @brief Get Extension Indicator (FX) value from Cat 021 Item 220
 *        Primary Subfield
 * 
 * @param item pointer to cat021_item220 structure
 * 
 * @return uint8_t (0: no extension; 1: extension)
 */
ASTERIX_API uint8_t get_cat021_item220_FX(const cat021_item220 * item);

/* ============================== SUBFIELD #1 ============================== */

/**
 * @brief Get Wind Speed (in knots) the from Cat 021 Item 220 Subfield #1
 * 
 * @param item pointer to cat021_item220_ext1 structure
 * 
 * @return uint16_t value of the wind speed in knots (LSB = 1 knots)
 */
ASTERIX_API uint16_t get_cat021_item220_ext1_WINDSPD(const cat021_item220_ext1 * item);

/* ============================== SUBFIELD #2 ============================== */

/**
 * @brief Get Wind Direction (in degrees) the from Cat 021 Item 220 Subfield #2
 * 
 * @param item pointer to cat021_item220_ext2 structure
 * 
 * @return uint16_t value of the wind direction in degrees (LSB = 1 degree)
 */
ASTERIX_API uint16_t get_cat021_item220_ext2_WINDDIR(const cat021_item220_ext2 * item);

/* ============================== SUBFIELD #3 ============================== */

/**
 * @brief Get Temperature the from Cat 021 Item 220 Subfield #3
 * 
 * @param item pointer to cat021_item220_ext3 structure
 * 
 * @return double vaue of the temperature in Celsius (LSB = 0.25 Celsius)
 */
ASTERIX_API double get_cat021_item220_ext3_TEMP(const cat021_item220_ext3 * item);

/* ============================== SUBFIELD #4 ============================== */

/**
 * @brief Get Turbulance the from Cat 021 Item 220 Subfield #4
 * 
 * @param item pointer to cat021_item220_ext4 structure
 * 
 * @return uint8_t value of the turbulance level (from 0 to 15)
 */
ASTERIX_API uint8_t get_cat021_item220_ext4_TURB(const cat021_item220_ext4 * item);


/*******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================== MAIN BYTE ============================== */

/**
 * @brief Set Wind Speed (WINDSPD) subfield presence into Cat 021 Item 220
 *        Primary Subfield
 * 
 * @param item pointer to cat021_item220 structure
 * @param ws value of new Wind Speed subfield presence indicator
 */
ASTERIX_API void set_cat021_item220_WS(cat021_item220 * item, uint8_t ws);

/**
 * @brief Set Wind Direction (WINDDIR) subfield presence into Cat 021 Item 220
 *        Primary Subfield
 * 
 * @param item pointer to cat021_item220 structure
 * @param wd value of new Wind Direction subfield presence indicator
 */
ASTERIX_API void set_cat021_item220_WD(cat021_item220 * item, uint8_t wd);

/**
 * @brief Set Temperature (TEMP) subfield presence into Cat 021 Item 220
 *        Primary Subfield
 * 
 * @param item pointer to cat021_item220 structure
 * @param temp value of new Teperature subfield presence indicator
 */
ASTERIX_API void set_cat021_item220_TEMP(cat021_item220 * item, uint8_t temp);

/**
 * @brief Set Turbulance (TURB) subfield presence into Cat 021 Item 220
 *        Primary Subfield
 * 
 * @param item pointer to cat021_item220 structure
 * @param trb value of new Turbulance subfield presence indicator
 */
ASTERIX_API void set_cat021_item220_TRB(cat021_item220 * item, uint8_t trb);

/**
 * @brief Set Extension Indicator (FX) value into Cat 021 Item 220
 *        Primary Subfield
 * 
 * @param item pointer to cat021_item220 structure
 * @param fx new value of extension presence (0: no extension;
 *                                            1: extension present)
 */
ASTERIX_API void set_cat021_item220_FX(cat021_item220 * item, uint8_t fx);

/* ============================== SUBFIELD #1 ============================== */

/**
 * @brief Set the given Wind Speed (in knots) the into Cat 021 Item 220 Subfield #1
 * 
 * @param item pointer to cat021_item220_ext1 structure
 * @param ws value of new Wind Speed in knots (LSB = 1 knot)
 */
ASTERIX_API void set_cat021_item220_ext1_WINDSPD(cat021_item220_ext1 * item,
                                                 uint16_t wind_spd);

/* ============================== SUBFIELD #2 ============================== */

/**
 * @brief Set the given Wind Direction (in degrees) the into Cat 021 Item 220 Subfield #2
 * 
 * @param item pointer to cat021_item220_ext2 structure
 * @param wd value of new Wind Direction in degrees (LSB = 1 degree)
 */
ASTERIX_API void set_cat021_item220_ext2_WINDDIR(cat021_item220_ext2 * item,
                                                 uint16_t wind_dir);

/* ============================== SUBFIELD #3 ============================== */

/**
 * @brief Set the given Temperature the into Cat 021 Item 220 Subfield #3
 * 
 * @param item pointer to cat021_item220_ext3 structure
 * @param temp value of new Teperature in Celsius (LSB = 0.25 Celsius)
 */
ASTERIX_API void set_cat021_item220_ext3_TEMP(cat021_item220_ext3 * item,
                                              double temp);

/* ============================== SUBFIELD #4 ============================== */

/**
 * @brief Set the given Turbulance the into Cat 021 Item 220 Subfield #4
 * 
 * @param item pointer to cat021_item220_ext4 structure
 * @param trb value of new Turbulance level (from 0 to 15)
 */
ASTERIX_API void set_cat021_item220_ext4_TURB(cat021_item220_ext4 * item,
                                              uint8_t turb);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Met Information primary and subfields values from the
 *        Cat 021 Item 155
 * 
 * @param item Pointer to cat021_item220 structure
 */
ASTERIX_API void print_cat021_item220(const cat021_item220 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM220_H */