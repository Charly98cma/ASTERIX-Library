/**
 * @file I021_008.h
 * @brief 
 * @version 0.1
 * @date 2026-03-13
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_008_H
#define I021_008_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

/* ================================= ENUMS ================================= */

typedef enum eI021_008_RA
{
    eI021_008_RA_NOT_ACTIVE = 0,    /// TCAS II or ACAS RA not active
    eI021_008_RA_ACTIVE     = 1,    /// TCAS RA active
} eI021_008_RA;

typedef enum eI021_008_TC
{
    eI021_008_TC_NO_CAP     = 0,    /// No capability
    eI021_008_TC_TC0        = 1,    /// Support for TC+0 reports only
    eI021_008_TC_MULT_TC    = 2,    /// Support multiple TC reports
    eI021_008_TC_RESERVED   = 3,    /// Reserved
} eI021_008_TC;

typedef enum eI021_008_TS
{
    eI021_008_TS_NO_CAP = 0,    /// No capability to support Target State reports
    eI021_008_TS_CAP    = 1,    /// Capable of supporting Target State reports
} eI021_008_TS;

typedef enum eI021_008_ARV
{
    eI021_008_ARV_NO_CAP = 0,    /// No capability to generate ARV-reports
    eI021_008_ARV_CAP    = 1,    /// Capable of generate ARV-reports 
} eI021_008_ARV;

typedef enum eI021_008_CDTIA
{
    eI021_008_CDTIA_NOT_OP  = 0,    /// CDTI not operational
    eI021_008_CDTIA_OP      = 1,    /// CDTI operational 
} eI021_008_CDTIA;

typedef enum eI021_008_NTCAS
{
    eI021_008_NTCAS_OP      = 0,    /// TCAS operational
    eI021_008_NTCAS_NOT_OP  = 1,    /// TCAS not operational 
} eI021_008_NTCAS;

typedef enum eI021_008_SA
{
    eI021_008_SA_ANT_DIV    = 0,    /// Antenna Diversity
    eI021_008_SA_SINGLE_ANT = 1,    /// Single Antenna only 
} eI021_008_SA;

/* ================================= STRUCTS ================================= */

/**
 * @typedef I021_008
 * @brief Data Item I021/008 - Aircraft Operational Status
 * 
 * Identification of the operational services available in the aircraft while
 * airborne.
 */
typedef struct I021_008
{
    /// @brief TCAS Resolution Advisory active
    eI021_008_RA    RA;
    /// @brief Target Trajectory Change Report Capability
    eI021_008_TC    TC;
    /// @brief Target State Report Capability
    eI021_008_TS    TS;
    /// @brief Air-Referenced Velocity Report Capability
    eI021_008_ARV   ARV;
    /// @brief Cockpit Display of Traffic Information airborne
    eI021_008_CDTIA CDTI;
    /// @brief Not TCAS System Status
    eI021_008_NTCAS NTCAS;
    /// @brief Single Antenna
    eI021_008_SA    SA;
} I021_008;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the data item I021/008 (Aircraft Operational Status) into a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_010 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_008(BitStream *bs, const I021_008 *item);

/**
 * @brief Decode the data item I021/008 (Aircraft Operational Status) from a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_010 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_008(BitStream *bs, I021_008 *item);

/* ============================== EXTRA FUNCS ============================== */

/**
 * @brief Print the contents of the given I021/008 data item.
 *
 * @param[in] item Pointer to a I021_008 structure.
 */
ASTERIX_LIB void print_I021_008(const I021_008 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_008_H */
