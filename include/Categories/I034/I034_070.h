/**
 * @file I034_070.h
 * @brief Definition of I034/070, and related functions and values
 */

#ifndef I034_070_H
#define I034_070_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/// @brief Max. number of Message Count Values (change as needed)
#define I034_070_MAX_REP                255

/// @brief Octets of Message Count Values (TYP and COUNTER)
#define I034_070_N_OCTETS               2

#define I034_070_TYP_MISSES             0 /* No detection (number of misses) */
#define I034_070_TYP_SING_PSR_REP       1 /* Single PSR target reports */
#define I034_070_TYP_SING_SSR_REP       2 /* Single SSR target reports (Non-Mode S) */
#define I034_070_TYP_SSR_PSR_REP        3 /* SSR+PSR target reports (Non-Mode S) */
#define I034_070_TYP_SING_ACALL_REP     4 /* Single All-Call target reports (Mode S) */
#define I034_070_TYP_SING_RCALL_REP     5 /* Single Roll-Call target reports (Mode S) */
#define I034_070_TYP_ACALL_PSR_REP      6 /* All-Call + PSR (Mode S) target reports */
#define I034_070_TYP_RCALL_PSR_REP      7 /* Roll-Call + PSR (Mode S) target reports */
#define I034_070_TYP_FIL_WEATHER        8 /* Filter for Weather data */
#define I034_070_TYP_FIL_JAMM_STR       9 /* Filter for Jamming Strobe */
#define I034_070_TYP_FIL_PSR            10 /* Filter for PSR data */
#define I034_070_TYP_FIL_SSR_MS         11 /* Filter for SSR/Mode S data */
#define I034_070_TYP_FIL_SSR_MS_PSR     12 /* Filter for SSR/Mode S+PSR data */
#define I034_070_TYP_FIL_ENHS           13 /* Filter for Enhanced Surveillance data */
#define I034_070_TYP_FIL_PSR_ENHS       14 /* Filter for PSR+Enhanced Surveillance */
#define I034_070_TYP_FIL_PSR_ENHS_SSRMS 15 /* Filter for PSR+Enhanced Surveillance + SSR/Mode S data not in Area of Prime Interest */
#define I034_070_TYP_FIL_PSR_ENHS_MS    16 /* Filter for PSR+Enhanced Surveillance + all SSR/Mode S data */
#define I034_070_TYP_REINT              17 /* Re-Interrogations (per sector) */
#define I034_070_TYP_BDSSWAP_WRONGDFREP 18 /* BDS Swap and wrong DF replies (per sector) */
#define I034_070_TYP_MODEAC_FRUIT       19 /* Mode A/C FRUIT (per sector) */
#define I034_070_TYP_MS_FRUIT           20 /* Mode S FRUIT (per sector) */

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I034_070
 * @brief Category 034 / Item 070 - Message Count Values
 *
 * Message Count values, according the various types of messages. The values
 * are collected for the last completed antenna revolution, counted between two
 * North crossings unless otherwise stated in the TYP definition below.
 */
typedef struct
{
    union
    {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[I034_070_MAX_REP * I034_070_N_OCTETS + 1];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct
        {
            /// @brief Repetition Factor of counters following (bits-24/17)
            uint8_t REP;

            struct
            {
                /// @brief Type of message counter
                uint16_t TYP        :5;
                /// @brief 11-bit counter value
                uint16_t COUNTER    :11;
            } COUNTER[I034_070_MAX_REP];
        };
    };
} I034_070;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/** @brief Get the Repetition Factor (REP) of Counter values from I034/070.
 *
 * @param item Pointer to an I034_070 structure (must not be NULL).
 * 
 * @return Number of counters present in the item (REP).
 */
ASTERIX_API uint8_t get_I034_070_REP(const I034_070 * item);

/** @brief Get the Message Counter Type (TYP) for a specific counter index.
 *
 * @param item Pointer to an I034_070 structure (must not be NULL).
 * @param counter_index Index of the counter (0..REP-1).
 * 
 * @return Message Counter Type value (see specification for encoding).
 */
ASTERIX_API uint8_t get_I034_070_TYP(const I034_070 * item, uint8_t counter_index);

/** @brief Get the counter value (COUNTER) for a specific counter index.
 *
 * @param item Pointer to an I034_070 structure (must not be NULL).
 * @param counter_index Index of the counter (0..REP-1).
 * 
 * @return 11-bit counter value as uint16_t.
 */
ASTERIX_API uint16_t get_I034_070_COUNTER(const I034_070 *item, uint8_t counter_index);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/** @brief Set the Repetition Factor (REP) of Message Counters in I034/070.
 *
 * @param item Pointer to an I034_070 structure to modify (must not be NULL).
 * @param rep New REP value.
 */
ASTERIX_API void set_I034_070_REP(I034_070 *item, uint8_t rep);

/** @brief Set the Message Counter Type (TYP) for a specific counter index.
 *
 * @param item Pointer to an I034_070 structure to modify (must not be NULL).
 * @param counter_index Index of the counter to set (0..REP-1).
 * @param typ New Message Counter Type value.
 */
ASTERIX_API void set_I034_070_TYP(I034_070 *item,
                                  uint8_t counter_index,
                                  uint8_t typ);

/** @brief Set the counter value (COUNTER) for a specific counter index.
 *
 * @param item Pointer to an I034_070 structure to modify (must not be NULL).
 * @param counter_index Index of the counter to set (0..REP-1).
 * @param counter_value New 11-bit counter value.
 */
ASTERIX_API void set_I034_070_COUNTER(I034_070 *item,
                                      uint8_t counter_index,
                                      uint16_t counter_value);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I034/070 (Message Count Values) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I034_070 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I034_070(void *item_in,
                                     unsigned char *msg_out,
                                     uint16_t out_index);

/** @brief Decode item I034/070 (Message Count Values) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I034_070 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I034_070(void *item_out,
                                     const unsigned char *msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/** @brief Print the contents of item 034/070.
 *
 * @param item Pointer to a I034_070 structure.
 */
ASTERIX_API void print_I034_070(const I034_070 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_070_H */