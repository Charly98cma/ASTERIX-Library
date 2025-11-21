/**
 * @file I021_074.h
 * @brief Definition of I021/074, and related functions and values
 */

#ifndef I021_074_H
#define I021_074_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_074_LSB_TMRP_HP   (1.0/P2_30) /// @brief LSB = 1/2^30 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_074
 * @brief Category 021 / Item 074 - Time of Message Reception of Position–High Precision
 * 
 * Time at which the latest ADS-B position information was received
 * by the ground station, expressed as fraction of the second of the UTC Time.
 */
typedef struct I021_074 {
    /** 
     * @brief Time of Message Reception of Position–High Precision (TMRP_HP)
     * 
     * Raw 4-bytes as received
     */
    uint8_t raw[4];
    
    union {
        struct {
            /** 
             * @brief Full Second Indication
             * 
             * = 3 - RESERVED |
             * = 2 - TOMRp whole seconds = (I021/073) Whole seconds - 1 |
             * = 1 - TOMRp whole seconds = (I021/073) Whole seconds + 1 |
             * = 0 - TOMRp whole seconds = (I021/073) Whole seconds
             */
            uint32_t FSI        :2;
            /** 
             * @brief Time of Message Reception of Position–High Precision
             * 
             * Fractional part of the time of message reception
             * for position in the ground station (LSB = 1/2^30)
             */
            uint32_t TMRP_HP    :30;
        };
    };
} I021_074;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get Full Second Indication (FSI) value from I021/074.
 *
 * @param item Pointer to I021_074 structure.
 * @return uint8_t FSI value (0: I021/073,
 *                            1: I021/073+1 sec;
 *                            2: I021/073-1 sec;
 *                            3: Reserved).
 */
ASTERIX_API uint8_t get_I021_074_FSI(const I021_074 * item);

/**
 * @brief Get Time of Message Reception of Position–High Precision (TMRP_HP)
 *        value in seconds from I021/074.
 *
 * @param item Pointer to I021_074 structure.
 * @return double TMRP_HP value (in seconds).
 */
ASTERIX_API double get_I021_074_TMRP_HP(const I021_074 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Full Second Indication (FSI) value into I021/074.
 *
 * @param item Pointer to I021_074 structure.
 * @param raw_value Raw 2-bit to store.
 */
ASTERIX_API void set_I021_074_FSI(I021_074 * item, uint8_t fsi);

/**
 * @brief Set the Time of Message Reception of Position–High Precision (TMRP_HP)
 *        value in seconds into I021/074.
 *
 * @param item Pointer to I021_074 structure.
 * @param tmrp_hp_seconds Time in seconds (will be converted to 1/2^30 second units)
 */
ASTERIX_API void set_I021_074_TMRP_HP(I021_074 * item, double tmrp_hp_seconds);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/074 (Time of Message Reception of Position-High Precision) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/074 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_074(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/074 (Time of Message Reception of Position-High Precision) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/074 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_074(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of I021/074.
 * 
 * Prints both the Full Second Indication (FSI) value, and the raw value and 
 * converted time in seconds of Time of Message Reception of Position–High
 * Precision (TMRP_HP).
 * 
 * @param item Pointer to I021_074 structure.
 */
ASTERIX_API void print_I021_074(const I021_074 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_074_H */