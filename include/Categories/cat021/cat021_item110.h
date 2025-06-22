/**
 * @file cat021_item110.h
 * @brief Definition of CAT 021 Item 110, and related functions and values
 */

#ifndef CAT021_ITEM110_H
#define CAT021_ITEM110_H

#include <stdio.h>
#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * Macros
 ******************************************************************************/

/// @brief Max. number of Trajectory Intent Points (change as needed)
#define MAX_NUM_TIP_I021_110            10

/// @brief Bytes on a Trajectory Intent Points
#define NUM_BYTES_CAT021_ITEM110_EXT2   15

#define LSB_CAT021_ITEM110_ALT          10                      /// LSB = 10 ft
#define LSB_CAT021_ITEM110_LAT          (double) (180/P2_23)    /// LSB = 1/2^23 deg
#define LSB_CAT021_ITEM110_LON          (double) (180/P2_23)    /// LSB = 1/2^23 deg
#define LSB_CAT021_ITEM110_TOV          1                       /// LSB = 1 second
#define LSB_CAT021_ITEM110_TTR          (double) (1/P10_2)      /// LSB = 0.01 NM

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * 
 */
typedef struct cat021_item110_ext1 {
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
} cat021_item110_ext1;

/**
 * 
 */
typedef struct cat021_item110_ext2 {
    union {
        uint8_t raw[MAX_NUM_TIP_I021_110 * NUM_BYTES_CAT021_ITEM110_EXT2 + 1];

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
} cat021_item110_ext2;

/**
 * 
 */
typedef struct cat021_item110 {
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
    cat021_item110_ext1 ext1;
    /// @brief 
    cat021_item110_ext2 ext2;
} cat021_item110;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN  BYTE =============================== */

/**
 * 
 */
ASTERIX_API uint8_t get_cat021_item110_TIS(const cat021_item110 * item);

/**
 * 
 */
ASTERIX_API uint8_t get_cat021_item110_TID(const cat021_item110 * item);

/**
 * 
 */
ASTERIX_API uint8_t get_cat021_item110_FX(const cat021_item110 * item);

/* ============================= FIRST EXTENSION ============================ */

/**
 * 
 */
ASTERIX_API uint8_t get_cat021_item110_ext1_NAV(const cat021_item110_ext1 * item);

/**
 * 
 */
ASTERIX_API uint8_t get_cat021_item110_ext1_NVB(const cat021_item110_ext1 * item);

/**
 * 
 */
ASTERIX_API uint8_t get_cat021_item110_ext1_FX(const cat021_item110_ext1 * item);

/* ============================ SECOND EXTENSION ============================ */

/**
 * 
 */
ASTERIX_API uint8_t get_cat021_item110_ext2_REP(const cat021_item110_ext2 * item);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_cat021_item110_ext2_TCA(const cat021_item110_ext2 * item, const uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_cat021_item110_ext2_NC(const cat021_item110_ext2 * item, const uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_cat021_item110_ext2_TCP_NUM(const cat021_item110_ext2 * item, const uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint16_t get_cat021_item110_ext2_ALT(const cat021_item110_ext2 * item, const uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API double get_cat021_item110_ext2_LAT(const cat021_item110_ext2 * item, const uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API double get_cat021_item110_ext2_LON(const cat021_item110_ext2 * item, const uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_cat021_item110_ext2_PT(const cat021_item110_ext2 * item, const uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_cat021_item110_ext2_TD(const cat021_item110_ext2 * item, const uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_cat021_item110_ext2_TRA(const cat021_item110_ext2 * item, const uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint8_t get_cat021_item110_ext2_TOA(const cat021_item110_ext2 * item, const uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API uint32_t get_cat021_item110_ext2_TOV(const cat021_item110_ext2 * item, const uint8_t index);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API double get_cat021_item110_ext2_TTR(const cat021_item110_ext2 * item, const uint8_t index);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* =============================== MAIN  BYTE =============================== */

/**
 * 
 */
ASTERIX_API void set_cat021_item110_TIS(cat021_item110 * item, uint8_t value);

/**
 * 
 */
ASTERIX_API void set_cat021_item110_TID(cat021_item110 * item, uint8_t value);

/**
 * 
 */
ASTERIX_API void set_cat021_item110_FX(cat021_item110 * item, uint8_t value);

/* ============================= FIRST EXTENSION ============================ */

/**
 * 
 */
ASTERIX_API void set_cat021_item110_ext1_NAV(cat021_item110_ext1 * item, uint8_t value);

/**
 * 
 */
ASTERIX_API void set_cat021_item110_ext1_NVB(cat021_item110_ext1 * item, uint8_t value);

/**
 * 
 */
ASTERIX_API void set_cat021_item110_ext1_FX(cat021_item110_ext1 * item, uint8_t value);

/* ============================ SECOND EXTENSION ============================ */

/**
 * 
 */
ASTERIX_API void set_cat021_item110_ext2_REP(cat021_item110_ext2 * item, uint8_t value);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_cat021_item110_ext2_TCA(cat021_item110_ext2 * item, const uint8_t index, uint8_t value);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_cat021_item110_ext2_NC(cat021_item110_ext2 * item, const uint8_t index, uint8_t value);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_cat021_item110_ext2_TCP_NUM(cat021_item110_ext2 * item, const uint8_t index, uint8_t value);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_cat021_item110_ext2_ALT(cat021_item110_ext2 * item, const uint8_t index, double value);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_cat021_item110_ext2_LAT(cat021_item110_ext2 * item, const uint8_t index, uint32_t value);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_cat021_item110_ext2_LON(cat021_item110_ext2 * item, const uint8_t index, uint32_t value);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_cat021_item110_ext2_PT(cat021_item110_ext2 * item, const uint8_t index, uint8_t value);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_cat021_item110_ext2_TD(cat021_item110_ext2 * item, const uint8_t index, uint8_t value);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_cat021_item110_ext2_TRA(cat021_item110_ext2 * item, const uint8_t index, uint8_t value);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_cat021_item110_ext2_TOA(cat021_item110_ext2 * item, const uint8_t index, uint8_t value);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_cat021_item110_ext2_TOV(cat021_item110_ext2 * item, const uint8_t index, uint32_t value);

/**
 * 
 * @param index Index of the Trajectoty Intent Data point (up-to 14 points, from 0 to 14)
 */
ASTERIX_API void set_cat021_item110_ext2_TTR(cat021_item110_ext2 * item, const uint8_t index, double value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * 
 */
ASTERIX_API void print_cat021_item110(const cat021_item110 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM110_H */