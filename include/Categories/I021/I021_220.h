/**
 * @file I021_220.h
 * @brief Definition of I021/220, and related functions and values
 */

#ifndef I021_220_H
#define I021_220_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/// @brief I021/220 Ext1 - Wind Speed LSB = 1 knot
#define I021_220_EXT1_LSB_WS     (1.0)
/// @brief I021/220 Ext2 - Wind Direction LSB = 1 degree
#define I021_220_EXT2_LSB_WD     (1.0)
/// @brief I021/220 Ext3 - Temperature LSB = 0.25 Celsius
#define I021_220_EXT3_LSB_TEMP        (0.25)

/// @brief Minimum value of Wind Speed
#define I021_220_EXT1_MIN_WS        0
/// @brief Maximum value of Wind Speed
#define I021_220_EXT1_MAX_WS        360
/// @brief Minimum value of Wind Direction
#define I021_220_EXT1_MIN_WD        1
/// @brief Maximum value of Wind Direction
#define I021_220_EXT1_MAX_WD        360
/// @brief Minimum value of Temperature
#define I021_220_EXT1_MIN_TEMP      -100.0
/// @brief Maximum value of Temperature
#define I021_220_EXT1_MAX_TEMP      100.0
/// @brief Minimum value of Turbulance
#define I021_220_EXT1_MIN_TRB       0
/// @brief Maximum value of Turbulance
#define I021_220_EXT1_MAX_TRB       15

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_220_EXT1
 * @brief Category 021 / Item 220 Subfield #1 - Wind Speed
 */
typedef struct I021_220_EXT1 {
    /**
     * @brief Wind Speed
     * 
     * Range: 0 <= WS <= 300
     * 
     * LSB = 1 knot
     */
    uint8_t WS[2];
} I021_220_EXT1;

/**
 * @typedef I021_220_EXT2
 * @brief Category 021 / Item 220 Subfield #2 - Wind Direction
 */
typedef struct I021_220_EXT2 {
    /**
     * @brief Wind Direction
     * 
     * Range: 1 <= WD <= 360
     * 
     * LSB = 1 degree
     */
    uint8_t WD[2];
} I021_220_EXT2;

/**
 * @typedef I021_220_EXT3
 * @brief Category 021 / Item 220 Subfield #3 - Temperature
 */
typedef struct I021_220_EXT3 {
    /**
     * @brief Temperature
     * 
     * Range: -100 <= TEMP <= 100
     * 
     * LSB = 0.25 Celsius
     */
    int8_t TEMP[2];
} I021_220_EXT3;

/**
 * @typedef I021_220_EXT4
 * @brief Category 021 / Item 220 Subfield #4 - Turbulance
 */
typedef struct I021_220_EXT4 {
    /**
     * @brief Turbulance
     * 
     * Range: 0 <= TRB <= 15
     */
    uint8_t TRB;
} I021_220_EXT4;

/**
 * @typedef I021_220
 * @brief Category 021 / Item 220 - Met Information
 * 
 * Meteorological information.
 */
typedef struct I021_220 {
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
    I021_220_EXT1 ext1;
    /// @brief Subfield #2
    I021_220_EXT2 ext2;
    /// @brief Subfield #3
    I021_220_EXT3 ext3;
    /// @brief Subfield #4
    I021_220_EXT4 ext4;
} I021_220;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

/**
 * @brief Get Wind Speed (WS) subfield presence from I021/220
 *        Primary Subfield
 * 
 * @param item pointer to I021_220 structure
 * 
 * @return uint8_t (0: absence of subfield #1; 1: presence of subfield #1)
 */
ASTERIX_API uint8_t get_I021_220_WS(const I021_220 * item);

/**
 * @brief Get Wind Direction (WD) subfield presence from I021/220
 *        Primary Subfield
 * 
 * @param item pointer to I021_220 structure
 * 
 * @return uint8_t (0: absence of subfield #2; 1: presence of subfield #2)
 */
ASTERIX_API uint8_t get_I021_220_WD(const I021_220 * item);

/**
 * @brief Get Temperature (TEMP) subfield presence from I021/220
 *        Primary Subfield
 * 
 * @param item pointer to I021_220 structure
 * 
 * @return uint8_t (0: absence of subfield #3; 1: presence of subfield #3)
 */
ASTERIX_API uint8_t get_I021_220_TEMP(const I021_220 * item);

/**
 * @brief Get Turbulance (TRB) subfield presence from I021/220
 *        Primary Subfield
 * 
 * @param item pointer to I021_220 structure
 * 
 * @return uint8_t (0: absence of subfield #4; 1: presence of subfield #4)
 */
ASTERIX_API uint8_t get_I021_220_TRB(const I021_220 * item);

/**
 * @brief Get Extension Indicator (FX) value from I021/220
 *        Primary Subfield
 * 
 * @param item pointer to I021_220 structure
 * 
 * @return uint8_t (0: no extension; 1: extension)
 */
ASTERIX_API uint8_t get_I021_220_FX(const I021_220 * item);

/* ============================== SUBFIELD #1 ============================== */

/**
 * @brief Get Wind Speed (in knots) the from I021/220 Subfield #1
 * 
 * @param item pointer to I021_220_EXT1 structure
 * 
 * @return uint16_t value of the wind speed in knots (LSB = 1 knots)
 */
ASTERIX_API uint16_t get_I021_220_EXT1_WS(const I021_220_EXT1 * item);

/* ============================== SUBFIELD #2 ============================== */

/**
 * @brief Get Wind Direction (in degrees) the from I021/220 Subfield #2
 * 
 * @param item pointer to I021_220_EXT2 structure
 * 
 * @return uint16_t value of the wind direction in degrees (LSB = 1 degree)
 */
ASTERIX_API uint16_t get_I021_220_EXT2_WD(const I021_220_EXT2 * item);

/* ============================== SUBFIELD #3 ============================== */

/**
 * @brief Get Temperature the from I021/220 Subfield #3
 * 
 * @param item pointer to I021_220_EXT3 structure
 * 
 * @return double vaue of the temperature in Celsius (LSB = 0.25 Celsius)
 */
ASTERIX_API double get_I021_220_EXT3_TEMP(const I021_220_EXT3 * item);

/* ============================== SUBFIELD #4 ============================== */

/**
 * @brief Get Turbulance the from I021/220 Subfield #4
 * 
 * @param item pointer to I021_220_EXT4 structure
 * 
 * @return uint8_t value of the turbulance level (from 0 to 15)
 */
ASTERIX_API uint8_t get_I021_220_EXT4_TRB(const I021_220_EXT4 * item);


/*******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================== MAIN BYTE ============================== */

/**
 * @brief Set Wind Speed (WS) subfield presence into I021/220
 *        Primary Subfield
 * 
 * @param item pointer to I021_220 structure
 * @param ws value of new Wind Speed subfield presence indicator
 */
ASTERIX_API void set_I021_220_WS(I021_220 * item, uint8_t ws);

/**
 * @brief Set Wind Direction (WD) subfield presence into I021/220
 *        Primary Subfield
 * 
 * @param item pointer to I021_220 structure
 * @param wd value of new Wind Direction subfield presence indicator
 */
ASTERIX_API void set_I021_220_WD(I021_220 * item, uint8_t wd);

/**
 * @brief Set Temperature (TEMP) subfield presence into I021/220
 *        Primary Subfield
 * 
 * @param item pointer to I021_220 structure
 * @param temp_celsius value of new Teperature subfield presence indicator
 */
ASTERIX_API void set_I021_220_TEMP(I021_220 * item, uint8_t temp_celsius);

/**
 * @brief Set Turbulance (TRB) subfield presence into I021/220
 *        Primary Subfield
 * 
 * @param item pointer to I021_220 structure
 * @param trb value of new Turbulance subfield presence indicator
 */
ASTERIX_API void set_I021_220_TRB(I021_220 * item, uint8_t trb);

/**
 * @brief Set Extension Indicator (FX) value into I021/220
 *        Primary Subfield
 * 
 * @param item pointer to I021_220 structure
 * @param fx new value of extension presence (0: no extension;
 *                                            1: extension present)
 */
ASTERIX_API void set_I021_220_FX(I021_220 * item, uint8_t fx);

/* ============================== SUBFIELD #1 ============================== */

/**
 * @brief Set the given Wind Speed (in knots) the into I021/220 Subfield #1
 * 
 * @param item pointer to I021_220_EXT1 structure
 * @param ws value of new Wind Speed in knots (LSB = 1 knot)
 */
ASTERIX_API void set_I021_220_EXT1_WS(I021_220_EXT1 * item, uint16_t wind_spd);

/* ============================== SUBFIELD #2 ============================== */

/**
 * @brief Set the given Wind Direction (in degrees) the into I021/220 Subfield #2
 * 
 * @param item pointer to I021_220_EXT2 structure
 * @param wd value of new Wind Direction in degrees (LSB = 1 degree)
 */
ASTERIX_API void set_I021_220_EXT2_WD(I021_220_EXT2 * item, uint16_t wind_dir);

/* ============================== SUBFIELD #3 ============================== */

/**
 * @brief Set the given Temperature the into I021/220 Subfield #3
 * 
 * @param item pointer to I021_220_EXT3 structure
 * @param temp value of new Teperature in Celsius (LSB = 0.25 Celsius)
 */
ASTERIX_API void set_I021_220_EXT3_TEMP(I021_220_EXT3 * item, double temp);

/* ============================== SUBFIELD #4 ============================== */

/**
 * @brief Set the given Turbulance the into I021/220 Subfield #4
 * 
 * @param item pointer to I021_220_EXT4 structure
 * @param trb value of new Turbulance level (from 0 to 15)
 */
ASTERIX_API void set_I021_220_EXT4_TRB(I021_220_EXT4 * item, uint8_t TRB);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/220 (MET Information) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/220 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_220(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/220 (MET Information) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/220 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_220(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Met Information primary and subfields values from the
 *        I021/155
 * 
 * @param item Pointer to I021_220 structure
 */
ASTERIX_API void print_I021_220(const I021_220 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_220_H */