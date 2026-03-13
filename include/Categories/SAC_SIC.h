/**
 * @file SAC_SIC.h
 * @brief 
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef SAC_SIC_H
#define SAC_SIC_H

/* Project libraries */
#include <Infra/infra.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

/* ================================= ENUMS ================================= */

/* ================================= STRUCTS ================================= */

/**
 * @typedef SAC_SIC
 * @brief Data Source Identification
 * 
 * Identification of the ADS-B station providing information.
 * 
 * Item present in every ASTERIX record
 */
typedef struct SAC_SIC
{
    /// @brief System Area Code
    u8 SAC;
    /// @brief System Identification Code
    u8 SIC;
} SAC_SIC;

/* =============================== DE/ENCODE =============================== */

/**
 * @brief Encode the SAC/SIC data item of the calling category.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in] item Pointer to the SAC_SIC structure (must not be NULL)
 */
void encode_SAC_SIC(BitStream *bs, const SAC_SIC *item);

/**
 * @brief Decode the SAC/SIC data item of the calling category.
 *
 * @param[in/out] bs Pointer to the BitStream (must not be NULL)
 * @param[in/out] item Pointer to the SAC_SIC structure (must not be NULL)
 */
void decode_SAC_SIC(BitStream *bs, SAC_SIC *item);

#ifdef __cplusplus
}
#endif

#endif /* SAC_SIC_H */