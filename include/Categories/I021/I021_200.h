/**
 * @file I021_200.h
 * @brief Definition of I021/200, and related functions and values
 */

#ifndef I021_200_H
#define I021_200_H

#include <stdint.h>
#include "Common/visibility.h"

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
 * @typedef I021_200
 * @brief Category 021 / Item 200 - Target Status
 * 
 * Status of the target
 */
typedef struct I021_200 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Intent Change Flag
             * 
             * =0 No intent change active | =1 Intent change flag raised
             * 
             * @note See Note 1 in ASTERIX Specification
             */
            uint8_t ICF         :1;
            /**
             * @brief Lateral NAVigation Mode
             * 
             * =0 LNAV Mode engaged | =1 LNAV Mode not engaged
             * 
             * @note See Note 2 in ASTERIX Specification Standard
             */
            uint8_t LNAV        :1;
            /**
             * @brief Military Emergency
             * 
             * =0 No emergency | =1 Emergency
             */
            uint8_t ME          :1;
            /**
             * @brief Priority Status
             * 
             * =0 No emergency / not reported |
             * =1 General emergency |
             * =2 Lifeguard / medical emergency |
             * =3 Minimum fuel |
             * =4 No communications |
             * =5 Unlawful interference |
             * =6 “Downed” Aircraft
             * 
             * @note See Note 3 in ASTERIX Specification Standard
             */
            uint8_t PS          :3;
            /**
             * @brief Surveillance Status
             * 
             * = 0 No condition reported |
             * = 1 Permanent Alert (Emergency condition) |
             * = 2 Temporary Alert (change in M3/A Code other than emergency) |
             * = 3 SPI set
             */
            uint8_t SS          :2;
        };
    };
} I021_200;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Intent Change Flag (ICF) value from I021/200
 * 
 * @param item pointer to I021_200 structure
 * 
 * @return uint8_t value of ICF (0: No intent change active;
 *                               1: Intent change flag raised)
 */
ASTERIX_API uint8_t get_I021_200_ICF(const I021_200 * item);

/**
 * @brief Get the Laterl NAVigation Mode (LNAV) value from I021/200
 * 
 * @param item pointer to I021_200 structure
 * 
 * @return uint8_t value of LNAV (0: LNAV Mode engaged;
 *                                1: LNAV Mode not engaged)
 */
ASTERIX_API uint8_t get_I021_200_LNAV(const I021_200 * item);

/** @brief Get the Military Emergency (EM) value from I021/200
 * 
 * @param item pointer to I021_200 structure
 * 
 * @return uint8_t value of ME (0: No emergency; 1: Emergency)
 */
ASTERIX_API uint8_t get_I021_200_ME(const I021_200 * item);

/**
 * @brief Get the Priority Status (PS) value from I021/200
 * 
 * @param item pointer to I021_200 structure
 * 
 * @return uint8_t value of PS (0: No emergency / not reported;
 *                              1: General emergency;
 *                              2: Lifeguard / medical emergency;
 *                              3: Minimum fuel;
 *                              4: No communications;
 *                              5: Unlawful interference;
 *                              6: “Downed” Aircraft)
 */
ASTERIX_API uint8_t get_I021_200_PS(const I021_200 * item);

/**
 * @brief Get the Special Surveillance Status (SS) value from I021/200
 * 
 * @param item pointer to I021_200 structure
 * 
 * @return uint8_t value of SS (0: No condition reported;
*                               1: Permanent Alert (Emergency condition);
*                               2: Temporary Alert (change in M3/A Code
                                                    other than emergency);
*                               3: SPI set)
 */
ASTERIX_API uint8_t get_I021_200_SS(const I021_200 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the new Intent Change Flag (ICF) value into I021/200 
 * 
 * @param item pointer to I021_200 structure
 * @param icf new value to write into the item (0: No intent change active;
 *                                              1: Intent change flag raised)
 */
ASTERIX_API void set_I021_200_ICF(I021_200 * item, uint8_t icf);

/**
 * @brief Set the new Lateral NAVigation Mode (LNAV) value into I021/200 
 * 
 * @param item pointer to I021_200 structure
 * @param lnav new value to write into the item (0: LNAV Mode engaged;
 *                                               1: LNAV Mode not engaged)
 */
ASTERIX_API void set_I021_200_LNAV(I021_200 * item, uint8_t lnav);

/**
 * @brief Set the new Military Emergency (ME) value into I021/200 
 * 
 * @param item pointer to I021_200 structure
 * @param me new value to write into the item (0: No emergency; 1: Emergency)
 */
ASTERIX_API void set_I021_200_ME(I021_200 * item, uint8_t me);

/**
 * @brief Set the new Priority Status (PS) value into I021/200 
 * 
 * @param item pointer to I021_200 structure
 * @param ps new value to write into the item (0: No emergency / not reported;
 *                                             1: General emergency;
 *                                             2: Lifeguard / medical emergency;
 *                                             3: Minimum fuel;
 *                                             4: No communications;
 *                                             5: Unlawful interference;
 *                                             6: “Downed” Aircraft)
 */
ASTERIX_API void set_I021_200_PS(I021_200 * item, uint8_t ps);

/**
 * @brief Set the new Surveillance Status (SS) value into I021/200 
 * 
 * @param item pointer to I021_200 structure
 * @param ss new value to write into the item (0: No condition reported;
 *                                             1: Permanent Alert
                                                  (Emergency condition);
 *                                             2: Temporary Alert
                                                  (change in M3/A Code other
                                                  than emergency);
 *                                             3: SPI set)
 */
ASTERIX_API void set_I021_200_SS(I021_200 * item, uint8_t ss);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/200 (Target Status) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/200 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_200(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/200 (Target Status) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/200 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_200(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Target Status of the I021/200
 * 
 * @param item pointer to I021_200 structure
 */
ASTERIX_API void print_I021_200(const I021_200 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_200_H */