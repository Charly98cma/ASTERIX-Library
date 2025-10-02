/**
 * @file I021_110.h
 * @brief Definition of I021/110, and related functions and values
 */

#ifndef I021_110_H
#define I021_110_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/// @brief Max. number of Trajectory Intent Points (change as needed)
#define MAX_NUM_TIP_I021_110            10

/// @brief Bytes on a Trajectory Intent Points
#define NUM_BYTES_I021_110_EXT2   15

#define I021_110_LSB_ALT          (10.0)        /// @brief LSB = 10 ft
#define I021_110_LSB_LAT          (180.0/P2_23) /// @brief LSB = 1/2^23 deg
#define I021_110_LSB_LON          (180.0/P2_23) /// @brief LSB = 1/2^23 deg
#define I021_110_LSB_TOV          (1.0)         /// @brief LSB = 1 second
#define I021_110_LSB_TTR          (1.0/P10_2)   /// @brief LSB = 0.01 NM

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * 
 */
typedef struct I021_110_EXT1 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief TID availability (NAV)
             * 
             * = 0 TID is available | = 1: TID is NOT available
             */
            uint8_t NAV         :1;
            /**
             * @brief TID validity (NVB)
             * 
             * = 0 TID is valid | = 1: TID is NOT valid
             */
            uint8_t NVB         :1;
            /// @brief Spare bits-6/2 set t0 0
            uint8_t spare       :5;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX          :1;
        };
    };
} I021_110_EXT1;

/**
 * 
 */
typedef struct I021_110_EXT2 {
    union {
        uint8_t raw[MAX_NUM_TIP_I021_110 * NUM_BYTES_I021_110_EXT2 + 1];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)

        struct {
            /// @brief Repetition Factor (number of Trajectory Intent Points)
            uint8_t REP;
            
            struct {
                /** @brief Trajectory Change Point Number Availability
                 * 
                 * = 0 TCP number available |
                 * = 1 TCP number not available
                 */
                uint8_t TCA     :1;
                /** @brief TCP Compliancy
                 * 
                 * = 0 TCP compliance |
                 * = 1 TCP non-compliance
                 */
                uint8_t NC      :1;
                /// @brief Trajectory Change Point number
                uint8_t TCP_NUM :6;
                /** @brief Altitude in two's complement form (LSB= 10ft)
                 * 
                 * Rang: -1500 ft <= altitude <= 150000 ft
                 */
                uint16_t ALT;
                /** @brief Latitude in WGS.84 in two's complement (LSB = 180/2 23 deg.)
                 * 
                 * Range: -90 <= latitude <= 90 deg.
                 */
                uint8_t LAT[3];
                /** @brief Longitude in WGS.84 in two's complement (LSB = 180/223 deg.)
                 * 
                 * Range: -180 <= longitude < 180
                 */
                uint8_t LON[3];
                /** @brief Pointer Type
                 * 
                 * = 0 Unknown |
                 * = 1 Fly by waypoint (LT) |
                 * = 2 Fly over waypoint (LT) |
                 * = 3 Hold pattern (LT) |
                 * = 4 Procedure hold (LT) |
                 * = 5 Procedure turn (LT) |
                 * = 6 RF leg (LT) |
                 * = 7 Top of climb (VT) |
                 * = 8 Top of descent (VT) |
                 * = 9 Start of level (VT) |
                 * = 10 Cross-over altitude (VT) |
                 * = 11 Transition altitude (VT)
                 */
                uint8_t TYPE    :4;
                /** @brief Turn Direction
                 *  
                 * = 00 N/A |
                 * = 01 Turn right |
                 * = 10 Turn left |
                 * = 11 No turn
                 */
                uint8_t TD      :2;
                /** @brief Turn Radius Availabilty
                 *
                 * = 0 TTR not available |
                 * = 1 TTR available
                 */
                uint8_t TRA     :1;
                /** @brief Time Over Availability
                 * 
                 * = 0 TOV available |
                 * = 1 TOV not available
                 */
                uint8_t TOA     :1;
                /// @brief Time Over Point (LSB = 1 second)
                uint8_t TOV[3];
                /** @brief TCP Turn radius (LSB = 0.01 Nm)
                 * 
                 * 0 <= TTR <= 655.35 Nm
                 */
                uint16_t TTR;
            } TIP[MAX_NUM_TIP_I021_110];
        };
    };
} I021_110_EXT2;

/**
 * 
 */
typedef struct I021_110 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Trajectory Intent Status (TIS)
             * 
             * = 0 Absence of Subfield #1 | = 1: Presence of Subfield #1
             */
            uint8_t TIS         :1;
            /**
             * @brief Trajectory Intent Data (TID)
             * 
             * = 0 Absence of Subfield #2 | = 1: Presence of Subfield #2
             */
            uint8_t TID         :1;
            /// @brief Spare bits-6/2 set t0 0
            uint8_t spare       :5;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX          :1;
        };
    };
    /// @brief 
    I021_110_EXT1 ext1;
    /// @brief 
    I021_110_EXT2 ext2;
} I021_110;

/*******************************************************************************
 * Getters
 ******************************************************************************/

// TODO: Document each function

/* =============================== MAIN  BYTE =============================== */

/**
 * 
 */
ASTERIX_API uint8_t get_I021_110_TIS(const I021_110 * item);

/**
 * 
 */
ASTERIX_API uint8_t get_I021_110_TID(const I021_110 * item);

/**
 * 
 */
ASTERIX_API uint8_t get_I021_110_FX(const I021_110 * item);

/* ============================= FIRST EXTENSION ============================ */

/**
 * 
 */
ASTERIX_API uint8_t get_I021_110_EXT1_NAV(const I021_110_EXT1 * item);

/**
 * 
 */
ASTERIX_API uint8_t get_I021_110_EXT1_NVB(const I021_110_EXT1 * item);

/**
 * 
 */
ASTERIX_API uint8_t get_I021_110_EXT1_FX(const I021_110_EXT1 * item);

/* ============================ SECOND EXTENSION ============================ */

/**
 * 
 */
ASTERIX_API uint8_t get_I021_110_EXT2_REP(const I021_110_EXT2 * item);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_I021_110_EXT2_TCA(const I021_110_EXT2 * item, uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_I021_110_EXT2_NC(const I021_110_EXT2 * item, uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_I021_110_EXT2_TCP_NUM(const I021_110_EXT2 * item, uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API int32_t get_I021_110_EXT2_ALT(const I021_110_EXT2 * item, uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API double get_I021_110_EXT2_LAT(const I021_110_EXT2 * item, uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API double get_I021_110_EXT2_LON(const I021_110_EXT2 * item, uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_I021_110_EXT2_TYPE(const I021_110_EXT2 * item, uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_I021_110_EXT2_TD(const I021_110_EXT2 * item, uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_I021_110_EXT2_TRA(const I021_110_EXT2 * item, uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_I021_110_EXT2_TOA(const I021_110_EXT2 * item, uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint32_t get_I021_110_EXT2_TOV(const I021_110_EXT2 * item, uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API double get_I021_110_EXT2_TTR(const I021_110_EXT2 * item, uint8_t index);

/*******************************************************************************
 * Setters
 ******************************************************************************/

// TODO: Document each function

/* =============================== MAIN  BYTE =============================== */

/**
 * 
 */
ASTERIX_API void set_I021_110_TIS(I021_110 * item, uint8_t tis);

/**
 * 
 */
ASTERIX_API void set_I021_110_TID(I021_110 * item, uint8_t tid);

/**
 * 
 */
ASTERIX_API void set_I021_110_FX(I021_110 * item, uint8_t fx);

/* ============================= FIRST EXTENSION ============================ */

/**
 * 
 */
ASTERIX_API void set_I021_110_EXT1_NAV(I021_110_EXT1 * item, uint8_t nav);

/**
 * 
 */
ASTERIX_API void set_I021_110_EXT1_NVB(I021_110_EXT1 * item, uint8_t nvb);

/**
 * 
 */
ASTERIX_API void set_I021_110_EXT1_FX(I021_110_EXT1 * item, uint8_t fx);

/* ============================ SECOND EXTENSION ============================ */

/**
 * 
 */
ASTERIX_API void set_I021_110_EXT2_REP(I021_110_EXT2 * item, uint8_t rep);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_I021_110_EXT2_TCA(I021_110_EXT2 * item, uint8_t index, uint8_t tca);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_I021_110_EXT2_NC(I021_110_EXT2 * item, uint8_t index, uint8_t nc);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_I021_110_EXT2_TCP_NUM(I021_110_EXT2 * item, uint8_t index, uint8_t num);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_I021_110_EXT2_ALT(I021_110_EXT2 * item, uint8_t index, double alt);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_I021_110_EXT2_LAT(I021_110_EXT2 * item, uint8_t index, uint32_t lat);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_I021_110_EXT2_LON(I021_110_EXT2 * item, uint8_t index, uint32_t lon);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_I021_110_EXT2_PT(I021_110_EXT2 * item, uint8_t index, uint8_t pt);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_I021_110_EXT2_TD(I021_110_EXT2 * item, uint8_t index, uint8_t td);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_I021_110_EXT2_TRA(I021_110_EXT2 * item, uint8_t index, uint8_t tra);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_I021_110_EXT2_TOA(I021_110_EXT2 * item, uint8_t index, uint8_t toa);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_I021_110_EXT2_TOV(I021_110_EXT2 * item, uint8_t index, uint32_t tov);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_I021_110_EXT2_TTR(I021_110_EXT2 * item, uint8_t index, double ttr);

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
ASTERIX_API uint16_t encode_I021_110(void * item_in,
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
ASTERIX_API uint16_t decode_I021_110(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * 
 */
ASTERIX_API void print_I021_110(const I021_110 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_110_H */