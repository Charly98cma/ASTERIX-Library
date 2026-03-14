/**
 * @file I021_020.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I021_020_H
#define I021_020_H

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

typedef enum eI021_020_ECAT
{
    eI021_020_ECAT_NO_INFO,                 /// No information
    eI021_020_ECAT_LIGHT_AC,                /// Light aircraft (MTOW < 15500 lb / 7000 kg)
    eI021_020_ECAT_SMALL_AC,                /// Small aircraft (7000 kg < MTOW < 136000 kg)
    eI021_020_ECAT_MEDIUM_AC,               /// Medium aircraft (136000 kg < MTOW < 255000 kg)
    eI021_020_ECAT_HIGH_VORTEX_LARGE_AC,    /// High Vortex Large
    eI021_020_ECAT_HEAVY_AC,                /// Heavy aircraft (MTOW > 136000 kg)
    eI021_020_ECAT_HIGHLY_MANEUVERABLE_AC,  /// Highly maneuverable (e.g. acrobatic)
    eI021_020_ECAT_ROTOCRAFT = 10,          /// Rotorcraft
    eI021_020_ECAT_GLIDER,                  /// Glider / Sailplane
    eI021_020_ECAT_LTA_AIRCRAFT,            /// Lighter-than-air aircraft (LTA)
    eI021_020_ECAT_UNMANNED_AIRCRAFT,       /// Unmanned Aerial Vehicle (UAV) / Drone
    eI021_020_ECAT_SPACE_VEHICLE,           /// Space / Transatmospheric Vehicle
    eI021_020_ECAT_UL_HGL_PGL,              /// Ultra-light / hang-glider / paraglider
    eI021_020_ECAT_PARA_SKYDIVER,           /// Parachute / Skydiver
    eI021_020_ECAT_SURF_EM_VEH = 20,        /// Surface emergency vehicle
    eI021_020_ECAT_SER_VEH,                 /// Service vehicle
    eI021_020_ECAT_GROUND_OBS,              /// Ground obstruction
    eI021_020_ECAT_CLUSTER_OBS,             /// Cluster obstacle
    eI021_020_ECAT_LINE_OBS,                /// Line obstacle
} eI021_020_ECAT;

/* ================================= STRUCTS ================================= */

/**
 * @typedef I021_020
 * @brief Data Item I021/020 - Emitter Category
 * 
 * Characteristics of the originating ADS-B unit
 */
typedef struct I021_020
{
    /// @brief Emitter Category
    eI021_020_ECAT ECAT;
} I021_020;

/* =============================== DE/ENCODE =============================== */

/** @brief Encode the data item I021/020 (Emitter Category) into a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the I021_020 structure (must not be NULL)
 */
ASTERIX_LIB void encode_I021_020(BitStream *bs, const I021_020 *item);

/** @brief Decode the data item I021/020 (Emitter Category) from a raw ASTERIX message.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the I021_020 structure (must not be NULL)
 */
ASTERIX_LIB void decode_I021_020(BitStream *bs, I021_020 *item);

/* ============================== EXTRA FUNCS ============================== */

/** @brief Print the contents of data item I021/020.
 *
 * @param[in] item Pointer to a I021_020 structure.
 */
ASTERIX_LIB void print_I021_020(const I021_020 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_020_H */