/**
 * @file I034_010.h
 * @brief Definition of I034/010, and related functions and values
 */

#ifndef I034_010_H
#define I034_010_H

#include <stdint.h>

#include "Common/visibility.h"

#include "Categories/SAC_SIC.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I034_010
 * @brief Category 034 / Item 010 - Data Source Identification
 *
 * Identification of the radar station from which the data are received.
 *
 * Item present in every ASTERIX record
 */
typedef SAC_SIC I034_010;
 
/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Retrieve the System Area Code (SAC) from the I034/010 item.
 *
 * @param item Pointer to an I034_010 structure (must not be NULL).
 * 
 * @return SAC value (see EUROCONTROL documentation for values).
 */
ASTERIX_API uint8_t get_I034_010_SAC(const I034_010 *item);

/**
 * @brief Retrieve the System Identification Code (SIC) from the I034/010 item.
 *
 * @param item Pointer to an I034_010 structure (must not be NULL).
 * 
 * @return SIC value (see EUROCONTROL documentation for values).
 */
ASTERIX_API uint8_t get_I034_010_SIC(const I034_010 *item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the System Area Code (SAC) in the I034_010 item.
 *
 * @param item Pointer to an I034_010 structure to modify (must not be NULL).
 * @param sac_value New SAC (see EUROCONTROL documentation for values).
 */
ASTERIX_API void set_I034_010_SAC(I034_010 *item, uint8_t sac_value);

/**
 * @brief Set the System Identification Code (SIC) in the I034_010 item.
 *
 * @param item Pointer to an I034_010 structure to modify (must not be NULL).
 * @param sic_value New SIC (see EUROCONTROL documentation for values).
 */
ASTERIX_API void set_I034_010_SIC(I034_010 *item, uint8_t sic_value);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I034/010 (Data Source Identification) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I034_010 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I034_010(void *item_in,
                                     unsigned char *msg_out,
                                     uint16_t out_index);

/** @brief Decode item I034/010 (Data Source Identification) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I034_010 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I034_010(void *item_out,
                                     const unsigned char *msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of the I034/010 item.
 *
 * @param item Pointer to a I034_010 structure.
 */
ASTERIX_API void print_I034_010(const I034_010 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_010_H */