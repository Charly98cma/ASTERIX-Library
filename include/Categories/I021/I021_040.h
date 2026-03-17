/**
 * @file I021_040.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-16
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_040_H
#define I021_040_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>
#include <Common/common_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

/* ================================= ENUMS ================================= */

typedef enum eI021_040_ATP
{
    eI021_040_ATP_ICAO_ADDR,       /// 24-Bit ICAO address
    eI021_040_ATP_DUP_ADDR,        /// Duplicate address
    eI021_040_ATP_SURFACE_VEHICLE, /// Surface vehicle address
    eI021_040_ATP_ANON_ADDR,       /// Anonymous address
} eI021_040_ATP;

typedef enum eI021_040_ARC
{
    I021_040_ARC_25FT,      /// 25 ft
    I021_040_ARC_100FT,     /// 100 ft
    I021_040_ARC_UNKNOWN,   /// Unknown
    I021_040_ARC_INVALID,   /// Invalid
} eI021_040_ARC;

typedef enum eI021_040_RC
{
    eI021_040_RC_DEFAULT,   /// Default
    eI021_040_RC_PASSED,    /// Range Check passed, CPR validation pending
} eI021_040_RC;

typedef enum eI021_040_RAB
{
    eI021_040_RAB_TRANSPONDER,  // Report from target transponder
    eI021_040_RAB_FIELD_MONITOR // Report from field
} eI021_040_RAB;

typedef enum eI021_040_EXT1_DCR
{
    I021_040_EXT1_DCR_NO_DIFF,  // No differential correction (ADS-B)
    I021_040_EXT1_DCR_DIFF,     // Differential correction (ADS-B)
} eI021_040_EXT1_DCR;

typedef enum eI021_040_EXT1_GBS
{
    eI021_040_EXT1_GBS_NOT_SET,  // Ground Bit not set
    eI021_040_EXT1_GBS_SET,      // Ground Bit set
} eI021_040_EXT1_GBS;

typedef enum eI021_040_EXT1_SIM
{
    eI021_040_EXT1_SIM_ACTUAL,      // Actual target report
    eI021_040_EXT1_SIM_SIMULATED,   // Simulated target report
} eI021_040_EXT1_SIM;

typedef enum eI021_040_EXT1_TST
{
    eI021_040_EXT1_TST_DEFAULT, // Default
    eI021_040_EXT1_TST_TEST,    // Test Target
} eI021_040_EXT1_TST;

typedef enum eI021_040_EXT1_SAA
{
    eI021_040_EXT1_SAA_CAPABLE,     // Capable to provide Selected Altitude
    eI021_040_EXT1_SAA_NOT_CAPABLE, // Not capable to provide Selected Altitude
} eI021_040_EXT1_SAA;

typedef enum eI021_040_EXT1_CL
{
    eI021_040_EXT1_CL_VALID,    // Report valid
    eI021_040_EXT1_CL_SUSPECT,  // Report suspect
    eI021_040_EXT1_CL_NO_INFO,  // No information
    eI021_040_EXT1_CL_RESERVED, // Reserved for future use
} eI021_040_EXT1_CL;

typedef enum eI021_040_EXT2_LLC
{
    eI021_040_EXT2_LLC_DEFAULT, // Default
    eI021_040_EXT2_LLC_SUSPECT, // Target is suspect
} eI021_040_EXT2_LLC;

typedef enum eI021_040_EXT2_IPC
{
    eI021_040_EXT2_IPC_DEFAULT, // Default
    eI021_040_EXT2_IPC_FAILED,  // Independent Position Check failed
} eI021_040_EXT2_IPC;

typedef enum eI021_040_EXT2_NOGO
{
    eI021_040_EXT2_NOGO_NOT_SET,// NOGO-bit not set
    eI021_040_EXT2_NOGO_SET,    // NOGO-bit set
} eI021_040_EXT2_NOGO;

typedef enum eI021_040_EXT2_CPR
{
    eI021_040_EXT2_CPR_VALID,   // CPR Validation correct
    eI021_040_EXT2_CPR_FAILED,  // CPR Validation failed
} eI021_040_EXT2_CPR;

typedef enum eI021_040_EXT2_LDPJ
{
    eI021_040_EXT2_LDPJ_NOT_DET,// LDPJ not detected
    eI021_040_EXT2_LDPJ_DET,    // LDPJ detected
} eI021_040_EXT2_LDPJ;

typedef enum eI021_040_EXT2_RCF
{
    eI021_040_EXT2_RCF_DEFAULT, // Default
    eI021_040_EXT2_RCF_FAILED,  // Range Check failed
} eI021_040_EXT2_RCF;

/* ================================= STRUCTS ================================= */

/**
 * @typedef I021_040_EXT1
 * @brief First extension of the Category 021 / Item 040
 */
typedef struct I021_040_EXT1
{
    /// @brief Differential Correction
    eI021_040_EXT1_DCR  DCR;
    /// @brief Ground Bit Setting
    eI021_040_EXT1_GBS  GBS;
    /// @brief Simulated Target
    eI021_040_EXT1_SIM  SIM;
    /// @brief Test Target
    eI021_040_EXT1_TST  TST;
    /// @brief Selected Altitude Available
    eI021_040_EXT1_SAA  SAA;
    /// @brief Confidence Level
    eI021_040_EXT1_CL   CL;
    /// @brief Field Extension
    ePresenceFlag FX;
} I021_040_EXT1;

/**
 * @typedef I021_040_EXT2
 * @brief Second extension of the Category 021 / Item 040
 */
typedef struct I021_040_EXT2
{
    /// @brief Spare bit, set to "0"
    eBoolean            spare;
    /// @brief List Lookup Check
    eI021_040_EXT2_LLC  LLC;
    /// @brief Independent Position Check
    eI021_040_EXT2_IPC  IPC;
    /// @brief No-go Bit Status
    eI021_040_EXT2_NOGO NOGO;
    /// @brief Compact Position Reporting
    eI021_040_EXT2_CPR  CPR;
    /// @brief Local Decoding Position Jump
    eI021_040_EXT2_LDPJ LDPJ;
    /// @brief Range Check
    eI021_040_EXT2_RCF  RCF;
    /// @brief Field Extension
    ePresenceFlag       FX;
} I021_040_EXT2;

/**
 * @typedef I021_040_EXT3
 * @brief Third extension of the Category 021 / Item 040
 */
typedef struct I021_040_EXT3
{
    /// @brief TBC Populated
    ePresenceFlag   TBC_EP;
    /// @brief TBC Value
    u8              TBC_VAL;
    /// @brief Field Extension
    ePresenceFlag   FX;
} I021_040_EXT3;

/**
 * @typedef I021_040_EXT4
 * @brief Fourth extension of the Category 021 / Item 040
 */
typedef struct I021_040_EXT4
{
    /// @brief MBC Element populated
    ePresenceFlag   MBC_EP;
    /// @brief MBC Value
    u8              MBC_VAL;
    /// @brief Field Extension
    ePresenceFlag   FX;
} I021_040_EXT4;

/**
 * @typedef I021_040
 * @brief Data Item I021/040 - Target Report Descriptor
 */
typedef struct I021_040
{
    /// @brief Address Type
    eI021_040_ATP   ATP;
    /// @brief Altitude Reporting Capability
    eI021_040_ARC   ARC;
    /// @brief Range Check
    eI021_040_RC    RC;
    /// @brief Report Type
    eI021_040_RAB   RAB;
    /// @brief Field Extension
    ePresenceFlag   FX;

    /// @brief First extension subfield (1 byte)
    I021_040_EXT1   ext1;
    /// @brief Second extension subfield (1 byte)
    I021_040_EXT2   ext2;
    /// @brief Third extension subfield (1 byte)
    I021_040_EXT3   ext3;
    /// @brief Fourth extension subfield (1 byte)
    I021_040_EXT4   ext4;
} I021_040;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/040 (Target Reporter Descriptor) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_040 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_040(BitStream *bs, const I021_040 *item);

/**
 * @brief Decode the data item I021/040 (Target Reporter Descriptor) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_040 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_040(BitStream *bs, I021_040 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given I021/040 data item.
 *
 * @param[in] item Pointer to a I021_040 structure.
 */
ASTERIX_LIB void print_I021_040(const I021_040 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_040_H */
