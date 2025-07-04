/**
 * @file bitwise_funcs.h
 * @brief Functions and macros to read and write values on raw memory
 */

#ifndef BITWISE_FUNCS_H
#define BITWISE_FUNCS_H

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Read specific bits from a value applying a mask at a given position.
 * 
 * This macro extracts the desired bits from a given field by shifting the bits
 * to the right and applying the provided mask. The bit positions are specified
 * in a **1-based format** (bit 1 is the least significant bit).
 * 
 * This macro is portable and useful for accessing packed bit fields when direct
 * structure access is not recommended due to endianness or compiler-specific layout.
 * 
 * @param value Value from which bits are to be extracted.
 * @param pos Starting bit position (1-based, where bit 1 is the least significant bit).
 * @param mask Bitmask to select the desired bits (unshifted).
 * 
 * @return The extracted bits from the given value, aligned to the least significant bits.
 * 
 * @note The macro assumes that `pos` starts from 1. If `pos` is 1, no shift is applied.
 */
#define GET_BITS(value, pos, mask) (((value) >> (pos-1)) & mask)

/**
 * @brief Macro to set desired bits on a given position in a target field by reference.
 * 
 * @param dst Pointer to the target variable.
 * @param val Value to set.
 * @param mask Mask for the bits to be set.
 * @param pos Bit position (1-based, where 1 is the least significant bit).
 */
#define SET_BITS(dst, val, mask, pos) \
    (*(dst)) |= (((val) & (mask)) << ((pos) - 1))


#ifdef __cplusplus
}
#endif

#endif // BITWISE_FUNCS_H