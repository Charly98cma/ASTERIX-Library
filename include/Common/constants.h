/**
 * @file constants.h
 * @brief Precalculated values to make the code easier to read and use
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Useful values
 ******************************************************************************/

/**
 * Max. length of the whole ASTERIX message set to avoid fragmentation during
 * transmission over ethernet
 */
#define MAX_MESSAGE_LEN     1400

/**
 * Value of the Field Extension (FX) bits
 */
#define FX_INACTIVE     0   /* Field Extension (FX) inactive */
#define FX_ACTIVE       1   /* Field Extension (FX) active */

/**
 * Macros to check presence/absence of subfield
 */
#define SUBFIELD_ABSENT  0 /* Flag of absent subfield */
#define SUBFIELD_PRESENT 1 /* Flag of present subfield */

/*******************************************************************************
 * POWERS OF 2
 ******************************************************************************/
#define P2_0        1.0           ///< 2^0  = 1
#define P2_1        2.0           ///< 2^1  = 2
#define P2_2        4.0           ///< 2^2  = 4
#define P2_3        8.0           ///< 2^3  = 8
#define P2_4        16.0          ///< 2^4  = 16
#define P2_5        32.0          ///< 2^5  = 32
#define P2_6        64.0          ///< 2^6  = 64
#define P2_7        128.0         ///< 2^7  = 128
#define P2_8        256.0         ///< 2^8  = 256
#define P2_9        512.0         ///< 2^9  = 512
#define P2_10       1024.0        ///< 2^10 = 1024
#define P2_11       2048.0        ///< 2^11 = 2048
#define P2_12       4096.0        ///< 2^12 = 4096
#define P2_13       8192.0        ///< 2^13 = 8192
#define P2_14       16384.0       ///< 2^14 = 16384
#define P2_15       32768.0       ///< 2^15 = 32768
#define P2_16       65536.0       ///< 2^16 = 65536
#define P2_17       131072.0      ///< 2^17 = 131072
#define P2_18       262144.0      ///< 2^18 = 262144
#define P2_19       524288.0      ///< 2^19 = 524288
#define P2_20       1048576.0     ///< 2^20 = 1048576
#define P2_21       2097152.0     ///< 2^21 = 2097152
#define P2_22       4194304.0     ///< 2^22 = 4194304
#define P2_23       8388608.0     ///< 2^23 = 8388608
#define P2_24       16777216.0    ///< 2^24 = 16777216
#define P2_25       33554432.0    ///< 2^25 = 33554432
#define P2_26       67108864.0    ///< 2^26 = 67108864
#define P2_27       134217728.0   ///< 2^27 = 134217728
#define P2_28       268435456.0   ///< 2^28 = 268435456
#define P2_29       536870912.0   ///< 2^29 = 536870912
#define P2_30       1073741824.0  ///< 2^30 = 1073741824
#define P2_31       2147483648.0  ///< 2^31 = 2147483648
#define P2_32       4294967296.0  ///< 2^32 = 4294967296


/*******************************************************************************
 * POWERS OF 10
 ******************************************************************************/
#define P10_0   1.0                         ///< 10^0  = 1
#define P10_1   10.0                        ///< 10^1  = 10
#define P10_2   100.0                       ///< 10^2  = 100
#define P10_3   1000.0                      ///< 10^3  = 1000
#define P10_4   10000.0                     ///< 10^4  = 10000
#define P10_5   100000.0                    ///< 10^5  = 100000
#define P10_6   1000000.0                   ///< 10^6  = 1000000
#define P10_7   10000000.0                  ///< 10^7  = 10000000
#define P10_8   100000000.0                 ///< 10^8  = 100000000
#define P10_9   1000000000.0                ///< 10^9  = 1000000000
#define P10_10  10000000000.0               ///< 10^10 = 10000000000
#define P10_11  100000000000.0              ///< 10^11 = 100000000000
#define P10_12  1000000000000.0             ///< 10^12 = 1000000000000
#define P10_13  10000000000000.0            ///< 10^13 = 10000000000000
#define P10_14  100000000000000.0           ///< 10^14 = 100000000000000
#define P10_15  1000000000000000.0          ///< 10^15 = 1000000000000000
#define P10_16  10000000000000000.0         ///< 10^16 = 10000000000000000
#define P10_17  100000000000000000.0        ///< 10^17 = 100000000000000000
#define P10_18  1000000000000000000.0       ///< 10^18 = 1000000000000000000
#define P10_19  10000000000000000000.0      ///< 10^19 = 10000000000000000000
#define P10_20  100000000000000000000.0     ///< 10^20 = 100000000000000000000


/*******************************************************************************
 * BIT MASKS
 ******************************************************************************/
#define MASK_01_BITS    0x00000001U          ///< 1 bits mask
#define MASK_02_BITS    0x00000003U          ///< 2 bits mask
#define MASK_03_BITS    0x00000007U          ///< 3 bits mask
#define MASK_04_BITS    0x0000000FU          ///< 4 bits mask
#define MASK_05_BITS    0x0000001FU          ///< 5 bits mask
#define MASK_06_BITS    0x0000003FU          ///< 6 bits mask
#define MASK_07_BITS    0x0000007FU          ///< 7 bits mask
#define MASK_08_BITS    0x000000FFU          ///< 8 bits mask
#define MASK_09_BITS    0x000001FFU          ///< 9 bits mask
#define MASK_10_BITS    0x000003FFU          ///< 10 bits mask
#define MASK_11_BITS    0x000007FFU          ///< 11 bits mask
#define MASK_12_BITS    0x00000FFFU          ///< 12 bits mask
#define MASK_13_BITS    0x00001FFFU          ///< 13 bits mask
#define MASK_14_BITS    0x00003FFFU          ///< 14 bits mask
#define MASK_15_BITS    0x00007FFFU          ///< 15 bits mask
#define MASK_16_BITS    0x0000FFFFU          ///< 16 bits mask
#define MASK_17_BITS    0x0001FFFFU          ///< 17 bits mask
#define MASK_18_BITS    0x0003FFFFU          ///< 18 bits mask
#define MASK_19_BITS    0x0007FFFFU          ///< 19 bits mask
#define MASK_20_BITS    0x000FFFFFU          ///< 20 bits mask
#define MASK_21_BITS    0x001FFFFFU          ///< 21 bits mask
#define MASK_22_BITS    0x003FFFFFU          ///< 22 bits mask
#define MASK_23_BITS    0x007FFFFFU          ///< 23 bits mask
#define MASK_24_BITS    0x00FFFFFFU          ///< 24 bits mask
#define MASK_25_BITS    0x01FFFFFFU          ///< 25 bits mask
#define MASK_26_BITS    0x03FFFFFFU          ///< 26 bits mask
#define MASK_27_BITS    0x07FFFFFFU          ///< 27 bits mask
#define MASK_28_BITS    0x0FFFFFFFU          ///< 28 bits mask
#define MASK_29_BITS    0x1FFFFFFFU          ///< 29 bits mask
#define MASK_30_BITS    0x3FFFFFFFU          ///< 30 bits mask
#define MASK_31_BITS    0x7FFFFFFFU          ///< 31 bits mask
#define MASK_32_BITS    0xFFFFFFFFU          ///< 32 bits mask


/*******************************************************************************
 * BIT MASKS
 ******************************************************************************/
#define MASK_BIT_00     P2_0        ///< Mask of bit  0 
#define MASK_BIT_01     P2_1        ///< Mask of bit  1 
#define MASK_BIT_02     P2_2        ///< Mask of bit  2 
#define MASK_BIT_03     P2_3        ///< Mask of bit  3 
#define MASK_BIT_04     P2_4        ///< Mask of bit  4 
#define MASK_BIT_05     P2_5        ///< Mask of bit  5 
#define MASK_BIT_06     P2_6        ///< Mask of bit  6 
#define MASK_BIT_07     P2_7        ///< Mask of bit  7 
#define MASK_BIT_08     P2_8        ///< Mask of bit  8 
#define MASK_BIT_09     P2_9        ///< Mask of bit  9 
#define MASK_BIT_10     P2_10       ///< Mask of bit 10 
#define MASK_BIT_11     P2_11       ///< Mask of bit 11 
#define MASK_BIT_12     P2_12       ///< Mask of bit 12 
#define MASK_BIT_13     P2_13       ///< Mask of bit 13 
#define MASK_BIT_14     P2_14       ///< Mask of bit 14 
#define MASK_BIT_15     P2_15       ///< Mask of bit 15 
#define MASK_BIT_16     P2_16       ///< Mask of bit 16 
#define MASK_BIT_17     P2_17       ///< Mask of bit 17 
#define MASK_BIT_18     P2_18       ///< Mask of bit 18 
#define MASK_BIT_19     P2_19       ///< Mask of bit 19 
#define MASK_BIT_20     P2_20       ///< Mask of bit 20 
#define MASK_BIT_21     P2_21       ///< Mask of bit 21 
#define MASK_BIT_22     P2_22       ///< Mask of bit 22 
#define MASK_BIT_23     P2_23       ///< Mask of bit 23 
#define MASK_BIT_24     P2_24       ///< Mask of bit 24 
#define MASK_BIT_25     P2_25       ///< Mask of bit 25 
#define MASK_BIT_26     P2_26       ///< Mask of bit 26 
#define MASK_BIT_27     P2_27       ///< Mask of bit 27 
#define MASK_BIT_28     P2_28       ///< Mask of bit 28 
#define MASK_BIT_29     P2_29       ///< Mask of bit 29 
#define MASK_BIT_30     P2_30       ///< Mask of bit 30 
#define MASK_BIT_31     P2_31       ///< Mask of bit 31 
#define MASK_BIT_32     P2_32       ///< Mask of bit 32 


#ifdef __cplusplus
}
#endif

#endif /* CONSTANTS_H */
