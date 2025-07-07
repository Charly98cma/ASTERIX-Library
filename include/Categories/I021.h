/**
 * @file I021.h
 * @brief Values, types and function headers of Category 021 messages
 */

#ifndef I021_H
#define I021_H

#include "Common/constants.h"
#include "Categories/Header.h"
#include "Categories/SAC_SIC.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_FSPEC_MAX_OCTETS     7       /// FSPEc max. number of octets

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_FSPEC
 * @brief FSPEC of CAT021 messages
 * 
 * Field Specification Type of CAT021 messages, spanning 7 Bytes
 */
typedef struct I021_FSPEC {
    union {

        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[I021_FSPEC_MAX_OCTETS];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            uint8_t item010     :1; /// I021/010 - Data Source Identification
            uint8_t item040     :1; /// I021/040 - Target Report Descriptor
            uint8_t item161     :1; /// I021/161 - Track Number
            uint8_t item015     :1; /// I021/015 - Service Identification
            uint8_t item071     :1; /// I021/071 - Time of Applicability for Position
            uint8_t item130     :1; /// I021/130 - Position in WGS-84 Co-ordinates
            uint8_t item131     :1; /// I021/131 - High-Resolution Position in WGS-84 Co-ordinates
            uint8_t fx_1        :1; /// FX - Field extension indicator
        
            uint8_t item072     :1; /// I021/072 - Time of Applicability for Velocity
            uint8_t item150     :1; /// I021/150 - Air Speed
            uint8_t item151     :1; /// I021/151 - True Airspeed
            uint8_t item080     :1; /// I021/080 - Target Address
            uint8_t item073     :1; /// I021/073 - Time of Message Reception for Position
            uint8_t item074     :1; /// I021/074 - Time of Message Reception of Position-High Precision
            uint8_t item075     :1; /// I021/075 - Time of Message Reception for Velocity
            uint8_t fx_2        :1; /// FX - Field extension indicator
        
            uint8_t item076     :1; /// I021/076 - Time of Message Reception of Velocity-High Precision
            uint8_t item140     :1; /// I021/140 - Geometric Height
            uint8_t item090     :1; /// I021/090 - Quality Indicators
            uint8_t item210     :1; /// I021/210 - MOPS Version
            uint8_t item070     :1; /// I021/070 - Mode 3/A Code in Octal Representation
            uint8_t item230     :1; /// I021/230 - Roll Angle
            uint8_t item145     :1; /// I021/145 - Flight Level
            uint8_t fx_3        :1; /// FX - Field extension indicator
        
            uint8_t item152     :1; /// I021/152 - Magnetic Heading
            uint8_t item200     :1; /// I021/200 - Target Status
            uint8_t item155     :1; /// I021/155 - Barometric Vertical Rate
            uint8_t item157     :1; /// I021/157 - Geometric Vertical Rate
            uint8_t item160     :1; /// I021/160 - Airborne Ground Vector
            uint8_t item165     :1; /// I021/165 - Track Angle Rate
            uint8_t item077     :1; /// I021/077 - Time of ASTERIX Report Transmission
            uint8_t fx_4        :1; /// FX - Field extension indicator
        
            uint8_t item170     :1; /// I021/170 - Target Identification
            uint8_t item020     :1; /// I021/020 - Emitter Category
            uint8_t item220     :1; /// I021/220 - Met Information
            uint8_t item146     :1; /// I021/146 - Selected Altitude
            uint8_t item148     :1; /// I021/148 - Final State Selected Altitude
            uint8_t item110     :1; /// I021/110 - Trajectory Intent
            uint8_t item016     :1; /// I021/016 - Service Management
            uint8_t fx_5        :1; /// FX - Field extension indicator
        
            uint8_t item008     :1; /// I021/008 - Aircraft Operational Status
            uint8_t item271     :1; /// I021/271 - Surface Capabilities and Characteristics
            uint8_t item132     :1; /// I021/132 - Message Amplitude
            uint8_t item250     :1; /// I021/250 - Mode S MB Data
            uint8_t item260     :1; /// I021/260 - ACAS Resolution Advisory Report
            uint8_t item400     :1; /// I021/400 - Receiver ID
            uint8_t item295     :1; /// I021/295 - Data Ages
            uint8_t fx_6        :1; /// FX - Field extension indicator
        
            uint8_t unused_1    :1; /// Spare
            uint8_t unused_2    :1; /// Spare
            uint8_t unused_3    :1; /// Spare
            uint8_t unused_4    :1; /// Spare
            uint8_t unused_5    :1; /// Spare
            uint8_t re          :1; /// I021/RE - Reserved Expansion Field
            uint8_t sp          :1; /// I021/SP - Special Purpose Field
            uint8_t fx_7        :1; /// FX - Field extension indicator
        };
    };
} I021_FSPEC;


/**
 * 
 */
typedef struct cat021_data {
    Header header;
    I021_FSPEC fspec;
    
} cat021_data_t;

#endif // I021_H