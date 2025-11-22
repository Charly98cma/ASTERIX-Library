/**
 * @file I034.h
 * @brief Values, types and function headers of Category 034 messages
 */

#ifndef I034_H
#define I034_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Common/constants.h"
#include "Categories/Header.h"
#include "Categories/SAC_SIC.h"

#include "Categories/I034/I034_010.h"
#include "Categories/I034/I034_000.h"
#include "Categories/I034/I034_030.h"
#include "Categories/I034/I034_020.h"
#include "Categories/I034/I034_041.h"
#include "Categories/I034/I034_050.h"
#include "Categories/I034/I034_060.h"
#include "Categories/I034/I034_070.h"
#include "Categories/I034/I034_100.h"
#include "Categories/I034/I034_110.h"
#include "Categories/I034/I034_120.h"
#include "Categories/I034/I034_090.h"
#include "Categories/I034/I034_RE.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/

/// @brief FSPEc max. number of octets
#define I034_FSPEC_MAX_OCTETS         2

/* Index of items on the lookup tables */

#define I021_FSPEC_ITEM010              0
#define I021_FSPEC_ITEM000              1
#define I021_FSPEC_ITEM030              2
#define I021_FSPEC_ITEM020              3
#define I021_FSPEC_ITEM041              4
#define I021_FSPEC_ITEM050              5
#define I021_FSPEC_ITEM060              6

#define I021_FSPEC_ITEM070              7
#define I021_FSPEC_ITEM100              8
#define I021_FSPEC_ITEM110              9
#define I021_FSPEC_ITEM120              10
#define I021_FSPEC_ITEM090              11
#define I021_FSPEC_RE                   12

#define I021_FSPEC_FX_1                 1
#define I021_FSPEC_FX_2                 2


/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I034_FSPEC
 * @brief FSPEC of Category 034 messages
 * 
 * Field Specification Type of CAT034 messages
 */
typedef struct I034_FSPEC {
    union {

        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[I034_FSPEC_MAX_OCTETS];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            // Octet 1
            uint8_t I034_010    :1; // I034/010 - Data Source Identifier
            uint8_t I034_000    :1; // I034/000 - Message Type
            uint8_t I034_030    :1; // I034/030 - Time-of-Day
            uint8_t I034_020    :1; // I034/020 - Sector Number
            uint8_t I034_041    :1; // I034/041 - Antenna Rotation Speed
            uint8_t I034_050    :1; // I034/050 - System Configuration and Status
            uint8_t I034_060    :1; // I034/060 - System Processing Mode
            uint8_t FX_1        :1; // FX - Field Extension

            // Octet 2
            uint8_t I034_070    :1; // I034/070 - Message Count Values
            uint8_t I034_100    :1; // I034/100 - Generic Polar Filter
            uint8_t I034_110    :1; // I034/110 - Data Filter
            uint8_t I034_120    :1; // I034/120 - 3D-Position of Data Source 
            uint8_t I034_090    :1; // I034/090 - Colimation Error
            uint8_t I034_RE     :1; // I034/RE - Reserved Expansion Field
            uint8_t I034_SP     :1; // I034/SP - Special Purpose Field
            uint8_t FX_2        :1; // FX - Field Extension
        };
    };
} I034_FSPEC;

/**
* @typedef I034
* @brief Category 034 message composed of Header, FSPEC and all items
* 
* This structure contains the Header (CAT and LEN), full FSPEC
* and all items present, since no dynamic memory is used, regardless
* of the content. Reading the FSPEC is necessary to know which items are used. 
* 
* @note Accesing item bitfields directly is discouraged, instead use the
*       defined getter/setter functions  
*/
typedef struct I034 {
    Header header;
    I034_FSPEC fspec;
    struct {
        I034_010 I034_010;
        I034_000 I034_000;
        I034_030 I034_030;
        I034_020 I034_020;
        I034_041 I034_041;
        I034_050 I034_050;
        I034_060 I034_060;

        I034_070 I034_070;
        I034_100 I034_100;
        I034_110 I034_110;
        I034_120 I034_120;
        I034_090 I034_090;
        I034_RE I034_RE;
    } items;
} I034;

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
ASTERIX_API uint8_t has_I034_FSPEC_item(const I034_FSPEC * fspec, uint8_t item_number);

/**
* @brief
* 
* @param
* @param
* 
* @return
*/
ASTERIX_API uint8_t has_I034_FSPEC_fx(const I034_FSPEC * fspec, uint8_t fx_number);

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
ASTERIX_API void set_I034_FSPEC_item(I034_FSPEC * fspec, uint8_t item_number, uint8_t value);

/**
* @brief
* 
* @param
* @param
* 
* @return
*/
ASTERIX_API void set_I034_FSPEC_fx(I034_FSPEC * fspec, uint8_t fx_number, uint8_t value);

/*******************************************************************************
* Encode / Decode functions
******************************************************************************/

/**
* @brief
* 
* @param
* @param
*/
ASTERIX_API uint16_t encode_I034(const I034 * msg_in, unsigned char * msg_out);

/**
* @brief
* 
* @param
* @param
*/
ASTERIX_API uint16_t decode_I034(const unsigned char * msg_in, I034 * msg_out);

#ifdef __cplusplus
}
#endif

#endif /* I034_H */