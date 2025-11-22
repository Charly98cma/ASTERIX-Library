/**
 * @file I021.h
 * @brief Values, types and function headers of Category 021 messages
 */

#ifndef I021_H
#define I021_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Common/constants.h"
#include "Categories/Header.h"
#include "Categories/SAC_SIC.h"

#include "Categories/I021/I021_008.h"
#include "Categories/I021/I021_010.h"
#include "Categories/I021/I021_015.h"
#include "Categories/I021/I021_016.h"
#include "Categories/I021/I021_020.h"
#include "Categories/I021/I021_040.h"
#include "Categories/I021/I021_070.h"
#include "Categories/I021/I021_071.h"
#include "Categories/I021/I021_072.h"
#include "Categories/I021/I021_073.h"
#include "Categories/I021/I021_074.h"
#include "Categories/I021/I021_075.h"
#include "Categories/I021/I021_076.h"
#include "Categories/I021/I021_077.h"
#include "Categories/I021/I021_080.h"
#include "Categories/I021/I021_090.h"
#include "Categories/I021/I021_110.h"
#include "Categories/I021/I021_130.h"
#include "Categories/I021/I021_131.h"
#include "Categories/I021/I021_132.h"
#include "Categories/I021/I021_140.h"
#include "Categories/I021/I021_145.h"
#include "Categories/I021/I021_146.h"
#include "Categories/I021/I021_148.h"
#include "Categories/I021/I021_150.h"
#include "Categories/I021/I021_151.h"
#include "Categories/I021/I021_152.h"
#include "Categories/I021/I021_155.h"
#include "Categories/I021/I021_157.h"
#include "Categories/I021/I021_160.h"
#include "Categories/I021/I021_161.h"
#include "Categories/I021/I021_165.h"
#include "Categories/I021/I021_170.h"
#include "Categories/I021/I021_200.h"
#include "Categories/I021/I021_210.h"
#include "Categories/I021/I021_220.h"
#include "Categories/I021/I021_230.h"
#include "Categories/I021/I021_250.h"
#include "Categories/I021/I021_260.h"
#include "Categories/I021/I021_271.h"
#include "Categories/I021/I021_295.h"
#include "Categories/I021/I021_400.h"
#include "Categories/I021/I021_RE.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/

/// @brief FSPEc max. number of octets
#define I021_FSPEC_MAX_OCTETS         7

/* Index of items on the lookup tables */

#define I021_FSPEC_ITEM010              0
#define I021_FSPEC_ITEM040              1
#define I021_FSPEC_ITEM161              2
#define I021_FSPEC_ITEM015              3
#define I021_FSPEC_ITEM071              4
#define I021_FSPEC_ITEM130              5
#define I021_FSPEC_ITEM131              6

#define I021_FSPEC_ITEM072              7
#define I021_FSPEC_ITEM150              8
#define I021_FSPEC_ITEM151              9
#define I021_FSPEC_ITEM080              10
#define I021_FSPEC_ITEM073              11
#define I021_FSPEC_ITEM074              12
#define I021_FSPEC_ITEM075              13

#define I021_FSPEC_ITEM076              14
#define I021_FSPEC_ITEM140              15
#define I021_FSPEC_ITEM090              16
#define I021_FSPEC_ITEM210              17
#define I021_FSPEC_ITEM070              18
#define I021_FSPEC_ITEM230              19
#define I021_FSPEC_ITEM145              20

#define I021_FSPEC_ITEM152              21
#define I021_FSPEC_ITEM200              22
#define I021_FSPEC_ITEM155              23
#define I021_FSPEC_ITEM157              24
#define I021_FSPEC_ITEM160              25
#define I021_FSPEC_ITEM165              26
#define I021_FSPEC_ITEM077              27

#define I021_FSPEC_ITEM170              28
#define I021_FSPEC_ITEM020              29
#define I021_FSPEC_ITEM220              30
#define I021_FSPEC_ITEM146              31
#define I021_FSPEC_ITEM148              32
#define I021_FSPEC_ITEM110              33
#define I021_FSPEC_ITEM016              34

#define I021_FSPEC_ITEM008              35
#define I021_FSPEC_ITEM271              36
#define I021_FSPEC_ITEM132              37
#define I021_FSPEC_ITEM250              38
#define I021_FSPEC_ITEM260              39
#define I021_FSPEC_ITEM400              40
#define I021_FSPEC_ITEM295              41

#define I021_FSPEC_RE                   42

/* Index of Field Extension fields */
#define I021_FSPEC_FX_1                 1
#define I021_FSPEC_FX_2                 2
#define I021_FSPEC_FX_3                 3
#define I021_FSPEC_FX_4                 4
#define I021_FSPEC_FX_5                 5
#define I021_FSPEC_FX_6                 6
#define I021_FSPEC_FX_7                 7

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_FSPEC
 * @brief FSPEC of Category 21 messages
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
 * @typedef I021
 * @brief Category 021 message composed of Header, FSPEC and all items
 * 
 * This structure contains the Header (CAT and LEN), full FSPEC (all fields,
 * 7 bytes) and all items present, since no dynamic memory is used, regardless
 * of the content. Reading the FSPEC is necessary to know which items are used. 
 * 
 * @note Accesing item bitfields directly is discouraged, instead use the
 *       defined getters/setter functions  
 */
typedef struct I021 {
    Header header;
    I021_FSPEC fspec;
    struct {
        I021_008 I021_008;
        I021_010 I021_010;
        I021_015 I021_015;
        I021_016 I021_016;
        I021_020 I021_020;
        I021_040 I021_040;
        I021_070 I021_070;
        I021_071 I021_071;
        I021_072 I021_072;
        I021_073 I021_073;
        I021_074 I021_074;
        I021_075 I021_075;
        I021_076 I021_076;
        I021_077 I021_077;
        I021_080 I021_080;
        I021_090 I021_090;
        I021_110 I021_110;
        I021_130 I021_130;
        I021_131 I021_131;
        I021_132 I021_132;
        I021_140 I021_140;
        I021_145 I021_145;
        I021_146 I021_146;
        I021_148 I021_148;
        I021_150 I021_150;
        I021_151 I021_151;
        I021_152 I021_152;
        I021_155 I021_155;
        I021_157 I021_157;
        I021_160 I021_160;
        I021_161 I021_161;
        I021_165 I021_165;
        I021_170 I021_170;
        I021_200 I021_200;
        I021_210 I021_210;
        I021_220 I021_220;
        I021_230 I021_230;
        I021_250 I021_250;
        I021_260 I021_260;
        I021_271 I021_271;
        I021_295 I021_295;
        I021_400 I021_400;
        I021_RE  I021_RE;
    } items;
} I021;

/*******************************************************************************
 * FSPEC Getters
 ******************************************************************************/

/**
 * @brief
 * 
 * @param
 * @param
 * 
 * @return
 */
ASTERIX_API uint8_t has_I021_FSPEC_item(const I021_FSPEC * fspec, uint8_t item_number);

/**
 * @brief
 * 
 * @param
 * @param
 * 
 * @return
 */
ASTERIX_API uint8_t has_I021_FSPEC_fx(const I021_FSPEC * fspec, uint8_t fx_number);

/*******************************************************************************
 * FSPEC Setters
 ******************************************************************************/

/**
 * @brief
 * 
 * @param
 * @param
 * 
 * @return
 */
ASTERIX_API void set_I021_FSPEC_item(I021_FSPEC * fspec, uint8_t item_number, uint8_t value);

/**
 * @brief
 * 
 * @param
 * @param
 * 
 * @return
 */
ASTERIX_API void set_I021_FSPEC_fx(I021_FSPEC * fspec, uint8_t fx_number, uint8_t value);
    
/*******************************************************************************
 * Encode / Decode functions
 ******************************************************************************/

/**
 * @brief
 * 
 * @param
 * @param
 */
ASTERIX_API uint16_t encode_I021(const I021 * msg_in, unsigned char * msg_out);

/**
 * @brief
 * 
 * @param
 * @param
 */
ASTERIX_API uint16_t decode_I021(const unsigned char * msg_in, I021 * msg_out);

#ifdef __cplusplus
}
#endif

#endif /* I021_H */
