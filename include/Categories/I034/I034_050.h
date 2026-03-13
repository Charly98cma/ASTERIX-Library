/**
 * @file I034_050.h
 * @brief 
 * @version 0.1
 * @date 2026-02-10
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef I034_050_H
#define I034_050_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>
#include <Common/common_types.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* ================================= MACROS ================================= */

/* ================================= ENUMS ================================= */

/* === SUBFIELD #1 === */

typedef enum eI034_050_EXT1_NOGO
{
    eI034_050_EXT1_NOGO_OPR = 0,    /* Operational */
    eI034_050_EXT1_NOGO_INH,        /* Inhibited */
} eI034_050_EXT1_NOGO;

typedef enum eI034_050_EXT1_RDPC
{
    eI034_050_EXT1_RDPC_1 = 0,   /* RDPC-1 */
    eI034_050_EXT1_RDPC_2,       /* RDPC-2 */
} eI034_050_EXT1_RDPC;

typedef enum eI034_050_EXT1_RDPR
{
    eI034_050_EXT1_RDPR_DEFAULT = 0, /* Default */
    eI034_050_EXT1_RDPR_RESET,       /* Reset RDPC */
} eI034_050_EXT1_RDPR;

typedef enum eI034_050_EXT1_OVLRDP
{
    eI034_050_EXT1_OVLRDP_NOTOVL = 0,   /* Not overloaded */
    eI034_050_EXT1_OVLRDP_OVL,          /* Overloaded */
} eI034_050_EXT1_OVLRDP;

typedef enum eI034_050_EXT1_OVLXMT
{
    eI034_050_EXT1_OVLXMT_NOTOVL = 0,   /* Not overloaded */
    eI034_050_EXT1_OVLXMT_OVL,          /* Overloaded */
} eI034_050_EXT1_OVLXMT;

typedef enum eI034_050_EXT1_MSC
{
    eI034_050_EXT1_MSC_CONN = 0,    /* Connected */
    eI034_050_EXT1_MSC_NOTCONN,     /* Not conencted */
} eI034_050_EXT1_MSC;

typedef enum eI034_050_EXT1_TSV
{
    eI034_050_EXT1_TSV_VAL = 0,     /* Valid */
    eI034_050_EXT1_TSV_INV,         /* Invalid */
} eI034_050_EXT1_TSV;

/* === SUBFIELD #4 & #5 === */

typedef enum eI034_050_EXT45_ANT
{
    eI034_050_EXT45_ANT_1 = 0,       /* Antenna 1 */
    eI034_050_EXT45_ANT_2,           /* Antenna 2 */
} eI034_050_EXT45_ANT;

typedef enum eI034_050_EXT45_CHAB
{
    eI034_050_EXT45_CHAB_NOCH = 0,   /* No channel */
    eI034_050_EXT45_CHAB_CHA,        /* Channel A */
    eI034_050_EXT45_CHAB_CHB,        /* Channel B */
    eI034_050_EXT45_CHAB_DIV,        /* Diversity mode */
} eI034_050_EXT45_CHAB;

typedef enum eI034_050_EXT45_OVL
{
    eI034_050_EXT45_OVL_NOTOVL = 0,  /* Not overloaded */
    eI034_050_EXT45_OVL_OVL,         /* Overloaded */
} eI034_050_EXT45_OVL;

typedef enum eI034_050_EXT45_MSC
{
    eI034_050_EXT45_MSC_CONN = 0, /* Connected */
    eI034_050_EXT45_MSC_NOTCONN,  /* Not conencted */
} eI034_050_EXT45_MSC;

/* === SUBFIELD #6 === */

typedef enum eI034_050_EXT6_ANT
{
    eI034_050_EXT6_ANT_1 = 0, /* Antenna 1 */
    eI034_050_EXT6_ANT_2,     /* Antenna 2 */
} eI034_050_EXT6_ANT;

typedef enum eI034_050_EXT6_CHAB
{
    eI034_050_EXT6_CHAB_NOCH = 0, /* No channel */
    eI034_050_EXT6_CHAB_CHA,      /* Channel A */
    eI034_050_EXT6_CHAB_CHB,      /* Channel B */
    eI034_050_EXT6_CHAB_DIV,      /* Diversity mode */
} eI034_050_EXT6_CHAB;

typedef enum eI034_050_EXT6_OVLSUR
{
    eI034_050_EXT6_OVLSUR_NOTOVL = 0, /* Not overloaded */
    eI034_050_EXT6_OVLSUR_OVL,        /* Overloaded */
} eI034_050_EXT6_OVLSUR;

typedef enum eI034_050_EXT6_MSC
{
    eI034_050_EXT6_MSC_CONN = 0, /* Connected */
    eI034_050_EXT6_MSC_NOTCONN,  /* Not conencted */
} eI034_050_EXT6_MSC;

typedef enum eI034_050_EXT6_SCF
{
    eI034_050_EXT6_SCF_CHA = 0, /* Channel A */
    eI034_050_EXT6_SCF_CHAB,    /* Channel B */
} eI034_050_EXT6_SCF;

typedef enum eI034_050_EXT6_DLF
{
    eI034_050_EXT6_DLF_CHA = 0, /* Channel A */
    eI034_050_EXT6_DLF_CHAB,    /* Channel B */
} eI034_050_EXT6_DLF;

typedef enum eI034_050_EXT6_OVLSCF
{
    eI034_050_EXT6_OVLSCF_NOTOVL = 0,   /* Not overloaded */
    eI034_050_EXT6_OVLSCF_OVL,          /* Overloaded */
} eI034_050_EXT6_OVLSCF;

typedef enum eI034_050_EXT6_OVLDLF
{
    eI034_050_EXT6_OVLDLF_NOTOVL = 0, /* Not overloaded */
    eI034_050_EXT6_OVLDLF_OVL,        /* Overloaded */
} eI034_050_EXT6_OVLDLF;

/* ================================= STRUCTS ================================= */

/**
 * @brief I034_050_EXT1
 *
 * Information of the common elements of the system
 */
typedef struct I034_050_EXT1_T
{
    /// @brief Operational Release Status of the System (0: operational, 1: inhibited)
    eI034_050_EXT1_NOGO NOGO;
    /// @brief Radar Data Processor Chain Selection Status (0: RDPC-1, 1: RDPC-2)
    eI034_050_EXT1_RDPC RDPC;
    /// @brief RDPC Reset (0: default, 1: reset of RDPC)
    eI034_050_EXT1_RDPR RDPR;
    /// @brief Radar Data Processor Overload Indicator (0: not overloaded, 1: overloaded)
    eI034_050_EXT1_OVLRDP OVLRDP;
    /// @brief Transmission Subsystem Overload Status (0: not overloaded, 1: overloaded)
    eI034_050_EXT1_OVLXMT OVLXMT;
    /// @brief Monitoring System Connected Status (0: connected, 1: not connected)
    eI034_050_EXT1_MSC MSC;
    /// @brief Time Source Validity (0: valid, 1: invalid)
    eI034_050_EXT1_TSV TSV;
    /// @brief Spare bit set to zero
    ePresenceFlag spare;
} I034_050_EXT1;

/**
 * @brief I034_050_EXT45
 *
 * Specific Status information for a PSR sensor (Subfield #4) or SSR sensor (Subfield #5)
 */
typedef struct I034_050_EXT45_T
{
    /// @brief Selected Antenna (0: Antenna 1, 1: Antenna 2)
    eI034_050_EXT45_ANT ANT;
    /// @brief Channel A/B selection status (0: No channel, 1: Channel A, 2: Channel B, 3: Diversity mode)
    eI034_050_EXT45_CHAB CHAB;
    /// @brief Overload condition (0: no overload, 1: overload)
    eI034_050_EXT45_OVL OVL;
    /// @brief Monitoring System Connected Status (0: connected, 1: not connected)
    eI034_050_EXT45_MSC MSC;
    /// @brief Spare bits set to zero
    ePresenceFlag spare;
} I034_050_EXT45;

/**
 * @brief I034_050_EXT6
 *
 * Specific Status information for a Mode S sensor
 */
typedef struct I034_050_EXT6
{
    /// @brief Selected Antenna (0: Antenna 1, 1: Antenna 2)
    eI034_050_EXT6_ANT ANT;
    /// @brief Channel A/B selection status (0: No channel, 1: Channel A, 2: Channel B, 3: Illegal combination)
    eI034_050_EXT6_CHAB CHAB;
    /// @brief Overload condition (0: no overload, 1: overload)
    eI034_050_EXT6_OVLSUR OVLSUR;
    /// @brief Monitoring System Connected Status (0: connected, 1: not connected)
    eI034_050_EXT6_MSC MSC;
    /// @brief Channel A/B selection status for Surveillance Co-ordination Function (0: Channel A, 1: Channel B)
    eI034_050_EXT6_SCF SCF;
    /// @brief Channel A/B selection status for Data Link Function (0: Channel A, 1: Channel B)
    eI034_050_EXT6_DLF DLF;
    /// @brief Overload in Surveillance Co-ordination Function (0: no overload, 1: overload)
    eI034_050_EXT6_OVLSCF OVLSCF;
    /// @brief Overload in Data Link Function (0: no overload, 1: overload)
    eI034_050_EXT6_OVLDLF OVLDLF;
    /// @brief Spare bits set to zero
    ePresenceFlag spare;
} I034_050_EXT6;

/**
 * @typedef I034_050
 * @brief Data Item 034/050 - System Configuration and Status
 *
 * Information concerning the configuration and status of a System.
 */
typedef struct I034_050
{
    /// @brief Subfield #1: Common Part (0: absent, 1: present)
    ePresenceFlag COM;
    /// @brief Subfield #2: Spare bits set to zero
    ePresenceFlag spare1;
    /// @brief Subfield #3: Spare bits set to zero
    ePresenceFlag spare2;
    /// @brief Subfield #4: Specific Status for PSR Sensor (0: absent, 1: present)
    ePresenceFlag PSR;
    /// @brief Subfield #5: Specific Status for SSR Sensor (0: absent, 1: present)
    ePresenceFlag SSR;
    /// @brief Subfield #6: Specific Status for Mode S Sensor (0: absent, 1: present)
    ePresenceFlag MDS;
    /// @brief Subfield #7: Spare bits set to zero
    ePresenceFlag spare3;
    /// @brief Field Extension (0: last octet, 1: more to come)
    ePresenceFlag FX;

    /// @brief Subfield #1: Common Part
    I034_050_EXT1 ext1;
    /// @brief Subfield #4: Specific Status for PSR Sensor
    I034_050_EXT45 ext4;
    /// @brief Subfield #5: Specific Status for SSR Sensor
    I034_050_EXT45 ext5;
    /// @brief Subfield #6: Specific Status for Mode S Sensor
    I034_050_EXT6 ext6;
} I034_050;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode item I034/050 (System Configuration and Status) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_050 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_050(BitStream *bs, const I034_050 *item);

/** @brief Decode item I034/050 (System Configuration and Status) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_050 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_050(BitStream *bs, I034_050 *item);

/* ============================== EXTRA FUNCS ============================== */

/** @brief Print the contents of the given I034/050 data item.
 *
 * @param[in] item Pointer to a I034_050 structure.
 */
ASTERIX_LIB void print_I034_050(const I034_050 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_050_H */