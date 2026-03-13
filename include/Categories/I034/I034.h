/**
 * @file I034.h
 * @brief 
 * @version 0.1
 * @date 2026-02-13
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef I034_H
#define I034_H

#ifdef __cplusplus
extern "C" {
#endif

/* Project libraries */
#include <Infra/infra.h>
#include <Categories/Header.h>
#include <Categories/SAC_SIC.h>
#include <Common/common_types.h>

#include <Categories/I034/I034_010.h>
#include <Categories/I034/I034_000.h>
#include <Categories/I034/I034_030.h>
#include <Categories/I034/I034_020.h>
#include <Categories/I034/I034_041.h>
#include <Categories/I034/I034_050.h>
#include <Categories/I034/I034_060.h>
#include <Categories/I034/I034_070.h>
#include <Categories/I034/I034_100.h>
#include <Categories/I034/I034_110.h>
#include <Categories/I034/I034_120.h>
#include <Categories/I034/I034_090.h>
#include <Categories/I034/I034_RE.h>
#include <Categories/I034/I034_SP.h>

/* ================================= ENUMS ================================= */

/* ================================= MACROS ================================= */

/* ================================= STRUCT ================================= */

 /**
 * @typedef I034_FSPEC
 * @brief FSPEC of Category 034 messages
 * 
 * Field Specification Type of CAT034 messages
 */
typedef struct I034_FSPEC
{
    ePresenceFlag I034_010; /* I034/010 - Data Source Identifier */
    ePresenceFlag I034_000; /* I034/000 - Message Type */
    ePresenceFlag I034_030; /* I034/030 - Time-of-Day */
    ePresenceFlag I034_020; /* I034/020 - Sector Number */
    ePresenceFlag I034_041; /* I034/041 - Antenna Rotation Speed */
    ePresenceFlag I034_050; /* I034/050 - System Configuration and Status */
    ePresenceFlag I034_060; /* I034/060 - System Processing Mode */
    ePresenceFlag FX_1;     /* FX - Field Extension */

    ePresenceFlag I034_070; /* I034/070 - Message Count Values */
    ePresenceFlag I034_100; /* I034/100 - Generic Polar Filter */
    ePresenceFlag I034_110; /* I034/110 - Data Filter */
    ePresenceFlag I034_120; /* I034/120 - 3D-Position of Data Source  */
    ePresenceFlag I034_090; /* I034/090 - Colimation Error */
    ePresenceFlag I034_RE;  /* I034/RE - Reserved Expansion Field */
    ePresenceFlag I034_SP;  /* I034/SP - Special Purpose Field */
    ePresenceFlag FX_2;     /* FX - Field Extension */
} I034_FSPEC;

/**
* @typedef I034
* @brief Category 034 message composed of Header, FSPEC and all items
* 
* This structure contains the Header (CAT and LEN), full FSPEC
* and all items present, since no dynamic memory is used, regardless
* of the content. Reading the FSPEC is necessary to know which items are used. 
* 
* @note Accesing bitfields directly is discouraged, instead use the
*       defined getter/setter functions  
*/
typedef struct I034
{
    Header      HEADER;
    I034_FSPEC  FSPEC;
    I034_010    I034_010;
    I034_000    I034_000;
    I034_030    I034_030;
    I034_020    I034_020;
    I034_041    I034_041;
    I034_050    I034_050;
    I034_060    I034_060;
    I034_070    I034_070;
    I034_100    I034_100;
    I034_110    I034_110;
    I034_120    I034_120;
    I034_090    I034_090;
    I034_RE     I034_RE;
    I034_SP     I034_SP;
} I034;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode the Category 034 message (Header, FSPEC and data items) into a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034(BitStream * bs, const I034 * item);

/** @brief Decode the Category 034 message (Header, FSPEC and data items) from a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034(BitStream * bs, I034 * item);

#ifdef __cplusplus
}
#endif

#endif /* I034_H */