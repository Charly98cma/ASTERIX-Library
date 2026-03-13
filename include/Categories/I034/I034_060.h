/**
 * @file I034_060.h
 * @brief 
 * @version 0.1
 * @date 2026-02-10
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef I034_060_H
#define I034_060_H

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

typedef enum eI034_060_EXT4_POL
{
    eI034_060_EXT4_POL_LINEAR = 0,
    eI034_060_EXT4_POL_CIRCULAR,
} eI034_060_EXT4_POL;

typedef enum eI034_060_EXT4_STC
{
    eI034_060_EXT4_STC_MAP1 = 0,
    eI034_060_EXT4_STC_MAP2,
    eI034_060_EXT4_STC_MAP3,
    eI034_060_EXT4_STC_MAP4,
} eI034_060_EXT4_STC;

typedef enum eI034_060_EXT6_CLU
{
    eI034_060_EXT6_CLU_AUTO = 0,
    eI034_060_EXT6_CLU_NOT_AUTO,
} eI034_060_EXT6_CLU;

/* ================================= STRUCTS ================================= */

/**
 * @brief I034_060_EXT1
 *
 * Information of the common elements of the system
 */
typedef struct I034_060_EXT1
{
    /// @brief Spare bits set to zero
    ePresenceFlag spare1;
    /// @brief Reduction Steps in use for an overload of the RDP (Reduction step N active)
    u8 REDRDP;
    /// @brief Reduction Steps in use for an overload of the Transmission subsystem (Reduction step N active)
    u8 REDXMT;
    /// @brief Spare bit set to zero
    ePresenceFlag spare2;
} I034_060_EXT1;

/**
 * @brief I034_060_EXT4
 *
 * Specific Status information for a PSR sensor
 */
typedef struct I034_060_EXT4
{
    /// @brief Polarization in use by PSR (0: Linear, 1: Circular)
    eI034_060_EXT4_POL POL;
    /// @brief Reduction Steps in use as a result of an overload of the PSR subsystem (Reduction step N active)
    u8 REDRAD;
    /// @brief Sensitivity Time Control Map in use (0: STC map 1, 1: STC map 2, 2: STC map 3, 3: STC map 4)
    eI034_060_EXT4_STC STC;
    /// @brief Spare bits set to zero
    ePresenceFlag spare;
} I034_060_EXT4;

/**
 * @brief I034_060_EXT5
 *
 * Specific Status information for a SSR sensor
 */
typedef struct I034_060_EXT5
{
    /// @brief Reduction Steps in use as a result of an overload of the SSR subsystem (Reduction step N active)
    u8 REDRAD;
    /// @brief Spare bits set to zero
    ePresenceFlag spare;
} I034_060_EXT5;

/**
 * @brief I034_060_EXT6
 *
 * Specific Status information for a Mode S sensor
 */
typedef struct I034_060_EXT6
{
    /// @brief Reduction Steps in use as a result of an overload of the SSR subsystem (Reduction step N active)
    u8 REDRAD;
    /// @brief Cluster State (0: autonomous, 1: not autonomous)
    eI034_060_EXT6_CLU CLU;
    /// @brief Spare bits set to zero
    ePresenceFlag spare;
} I034_060_EXT6;

/**
 * @typedef I034_060
 * @brief Data Item 034/060 - System Configuration and Status
 *
 * Status concerning the processing options, in use during the last antenna
 * revolution, for the various Sensors, composing the System.
 */
typedef struct I034_060
{
    /// @brief Subfield #1: Common Part (0: absent, 1: present)
    ePresenceFlag COM;
    /// @brief Subfield #2: Spare subfield
    ePresenceFlag spare1;
    /// @brief Subfield #3: Spare subfield
    ePresenceFlag spare2;
    /// @brief Subfield #4: Specific Status for PSR Sensor (0: absent, 1: present)
    ePresenceFlag PSR;
    /// @brief Subfield #5: Specific Status for SSR Sensor (0: absent, 1: present)
    ePresenceFlag SSR;
    /// @brief Subfield #6: Specific Status for Mode S Sensor (0: absent, 1: present)
    ePresenceFlag MDS;
    /// @brief Subfield #7: Spare Subfield
    ePresenceFlag spare3;
    /// @brief Field Extension (0: last octet, 1: more to come)
    ePresenceFlag FX;

    /// @brief Subfield #1: Common Part
    I034_060_EXT1 ext1;
    /// @brief Subfield #4: Specific Status for PSR Sensor
    I034_060_EXT4 ext4;
    /// @brief Subfield #5: Specific Status for SSR Sensor
    I034_060_EXT5 ext5;
    /// @brief Subfield #6: Specific Status for Mode S Sensor
    I034_060_EXT6 ext6;
} I034_060;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode item I034/060 (System Configuration and Status) into a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I034_060 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I034_060(BitStream *bs, const I034_060 *item);

/** @brief Decode item I034/060 (System Configuration and Status) from a raw ASTERIX message.
 * 
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I034_060 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I034_060(BitStream *bs, I034_060 *item);

/* ============================== EXTRA FUNCS ============================== */

/** @brief Print the contents of given 034/060 data item.
 *
 * @param[in] item Pointer to a I034_060 structure.
 */
ASTERIX_LIB void print_I034_060(const I034_060 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_060_H */