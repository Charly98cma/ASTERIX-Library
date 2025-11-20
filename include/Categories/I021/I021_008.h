/**
 * @file I021_008.h
 * @brief Definition of I021/008, and related functions and values
 */

#ifndef I021_008_H
#define I021_008_H

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
 * @typedef I021_008
 * @brief Category 21 / Item 008 - Aircraft Operational Status
 * 
 * Identification of the operational services available in the
 * aircraft while airborne
 */
typedef struct I021_008 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** @brief TCAS Resolution Advisory active
             * 
             * = 0 not active |
             * = 1 active
             */
            uint8_t RA      :1;
            /** @brief Target Trajectory Change Report Capability
             * 
             * = 0 no capability for Trajectory Change Reports |
             * = 1 support for TC+0 reports only |
             * = 2 support for multiple TC reports |
             * = 3 reserved
             */
            uint8_t TC      :2;
            /** @brief Target State Report Capability
             * 
             * = 0 no capability to support Target State Reports |
             * = 1 capable of supporting Target State Reports
             */
            uint8_t TS      :1;
            /** @brief Air-Referenced Velocity Report Capability
             * 
             * = 0 no capability to generate ARV-reports |
             * = 1 capable of generate ARV-reports */
            uint8_t ARV     :1;
            /** @brief Cockpit Display of Traffic Information airborne
             * 
             * = 0 CDTI not operational |
             * = 1 CDTI operational
             */
            uint8_t CDTI    :1;
            /** @brief Not TCAS System Status
             * 
             * = 0 NTCAS operational |
             * = 1 NTCAS not operational
             */
            uint8_t NTCAS    :1;
            /** @brief Single Antenna
             * 
             * = 0 Antenna Diversity |
             * = 1 Single Antenna only
             */
            uint8_t SA      :1;
        };
    };
} I021_008;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the TCAS Resolution Advisory status (RA) from I021/008.
 * 
 * Portable access to the RA bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_008 structure.
 * @return uint8_t Value of RA (0: not active, 1: active)
 */
ASTERIX_API uint8_t get_I021_008_RA(const I021_008 * item);

/**
 * @brief Get the Target Trajectory Change Report Capability (TC) from I021/008.
 * 
 * Portable access to the TC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_008 structure.
 * @return uint8_t Value of TC (0: no capability,
 *                              1: TC+0 reports only,
 *                              2: multiple TC reports,
 *                              3: reserved)
 */
ASTERIX_API uint8_t get_I021_008_TC(const I021_008 * item);

/**
 * @brief Get the Target State Report Capability (TS) from I021/008.
 * 
 * Portable access to the TS bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_008 structure.
 * @return uint8_t Value of TS (0: no capability, 1: capability supported)
 */
ASTERIX_API uint8_t get_I021_008_TS(const I021_008 * item);

/**
 * @brief Get the Air-Referenced Velocity Report Capability (ARV) from I021/008.
 * 
 * Portable access to the ARV bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_008 structure.
 * @return uint8_t Value of ARV (0: no capability. 1: capability supported)
 */
ASTERIX_API uint8_t get_I021_008_ARV(const I021_008 * item);

/**
 * @brief Get the Cockpit Display of Traffic Information airborne (CDTI)
 *        from I021/008.
 * 
 * Portable access to the CDTI bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_008 structure.
 * @return uint8_t Value of CDTI (0: not operational, 1: operational)
 */
ASTERIX_API uint8_t get_I021_008_CDTI(const I021_008 * item);

/**
 * @brief Get the Not TCAS System Status (NTCAS) from I021/008.
 * 
 * Portable access to the NTCAS bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_008 structure.
 * @return uint8_t Value of NTCAS (0: operational, 1: not operational)
 */
ASTERIX_API uint8_t get_I021_008_NTCAS(const I021_008 * item);

/**
 * @brief Get the Single Antenna (SA) from I021/008.
 * 
 * Portable access to the SA bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_008 structure.
 * @return uint8_t Value of SA (0: antenna diversity, 1: single antenna only)
 */
ASTERIX_API uint8_t get_I021_008_SA(const I021_008 * item);


/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the TCAS Resolution Advisory status (RA) into the raw field.
 * 
 * @param item Pointer to I021_008 structure.
 * @param value Value of RA
 */
ASTERIX_API void set_I021_008_RA(I021_008 * item, uint8_t ra);

/**
 * @brief Set the Target Trajectory Change Report Capability (TC) into the
 *        raw field.
 * 
 * @param item Pointer to I021_008 structure.
 * @param value Value of TC
 */
ASTERIX_API void set_I021_008_TC(I021_008 * item, uint8_t tc);

/**
 * @brief Set the Target State Report Capability (TS) into the raw field.
 * 
 * @param item Pointer to I021_008 structure.
 * @param value Value of TS
 */
ASTERIX_API void set_I021_008_TS(I021_008 * item, uint8_t ts);

/**
 * @brief Set the Air-Referenced Velocity Report Capability (ARV) into the
 *        raw field.
 * 
 * @param item Pointer to I021_008 structure.
 * @param value Value of ARV
 */
ASTERIX_API void set_I021_008_ARV(I021_008 * item, uint8_t arv);

/**
 * @brief Set the Cockpit Display of Traffic Information airborne (CDTI)
 *        into the raw field.
 * 
 * @param item Pointer to I021_008 structure.
 * @param value Value of CDTI
 */
ASTERIX_API void set_I021_008_CDTI(I021_008 * item, uint8_t cdti);

/**
 * @brief Set the Not TCAS System Status (NTCAS) into the raw field.
 * 
 * @param item Pointer to I021_008 structure.
 * @param value Value of NTCAS
 */
ASTERIX_API void set_I021_008_NTCAS(I021_008 * item, uint8_t ntcas);

/**
 * @brief Set the Single Antenna (SA) into the raw field.
 * 
 * @param item Pointer to I021_008 structure.
 * @param value Value of SA
 */
ASTERIX_API void set_I021_008_SA(I021_008 * item, uint8_t sa);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/**
 * @brief
 * 
 * @param item_in
 * @param msg_out
 * @param out_index
 * 
 * @return uint16_t
 */
ASTERIX_API uint16_t encode_I021_008(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/**
 * @brief
 * 
 * @param item_in
 * @param msg_in
 * @param in_index
 * 
 * @return uint16_t
 */
ASTERIX_API uint16_t decode_I021_008(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 008.
 *
 * This function prints the values of the main byte.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a I021_008 structure.
 */
ASTERIX_API void print_I021_008(const I021_008 *item);

#ifdef __cplusplus
}
#endif

#endif /* I021_008_H */
