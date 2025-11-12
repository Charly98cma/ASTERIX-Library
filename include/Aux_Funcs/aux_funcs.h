/**
 * @file aux_funcs.h
 * @brief Auxiliar functions and macros
 */

#ifndef AUX_FUNCS_H
#define AUX_FUNCS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/* FIXME: Review this macros and its uses */

/**
 * @brief Macro to check if the value is in the defines range
 * 
 * @param min Minimum value of the range
 * @param val Value to check
 * @param max Maximum value of the range.
 * 
 * @return True if the given value is in the range, False otherwhise
 */
#define IS_IN_RANGE(min, val, max) ((min <= val) && (val <= max))

/**
 * @brief Macro to check if the value is out of the defines range
 * 
 * @param val Value to check
 * @param min Minimum value of the range
 * @param max Maximum value of the range.
 * 
 * @return True if the given value is out of the range, False otherwhise
 */
#define IS_OUT_OF_RANGE(val, min, max) ((val < min) || (val > max))

/*******************************************************************************
 * Read functions
 ******************************************************************************/

 /**
 * @brief Read signed magnitude 8-bit value
 *
 * @param data Pointer to the data
 * @return int8_t Signed magnitude 8-bit value
 */
static __inline__ int8_t read_signmag_8bit(const uint8_t *data)
{
    if (!(data[0] & 0x80))
        return (int8_t)data[0];
    return (int8_t)(-(int8_t)data[0]);
}

/**
 * @brief Read two's complement 8-bit value
 * 
 * @param data Pointer to the data
 * @return int8_t Two's complement 8-bit value
 */
static __inline__ int8_t read_twocomp_8bit(const uint8_t *data)
{
    return (int8_t)(data[0]);
}

/**
 * @brief Read unsigned 8-bit value
 * 
 * @param data Pointer to the data
 * @return uint8_t Unsigned 8-bit value
 */
static __inline__ uint8_t read_unsigned_8bit(const uint8_t *data)
{
    return data[0];
}

/**
 * @brief Read signed magnitude 16-bit value
 * 
 * @param data Pointer to the data
 * @return int8_t Signed magnitude 16-bit value
 */
static __inline__ int16_t read_signmag_16bit(const uint8_t *data)
{
    if (!(data[0] & 0x80))
        return (int16_t)((data[0] << 8) | data[1]);
    return (int16_t)(-((data[0] & 0x7F) << 8 | data[1]));
}

/**
 * @brief Read two's complement 16-bit value
 * 
 * @param data Pointer to the data
 * @return int8_t Two's complement 16-bit value
 */
int16_t read_twocomp_16bit(const uint8_t *data)
{
    return (int16_t)((data[0] << 8) | data[1]);
}

/**
 * @brief Read unsigned 16-bit value
 * 
 * @param data Pointer to the data
 * @return uint8_t Unsigned 16-bit value
 */
static __inline__ uint16_t read_unsigned_16bit(const uint8_t *data)
{
    return (uint16_t)((data[0] << 8) | data[1]);
}

/**
 * @brief Read signed magnitude 24-bit value
 * 
 * @param data Pointer to the data
 * @return int8_t Signed magnitude 24-bit value
 */
static __inline__ int32_t read_signmag_24bit(const uint8_t *data)
{
    if (!(data[0] & 0x80))
        return (int32_t)((data[0] << 16) | (data[1] << 8) | data[2]);
    return (int32_t)(-((data[0] & 0x7F) << 16 | (data[1] << 8) | data[2]));
}

/**
 * @brief Read two's complement 24-bit value
 * 
 * @param data Pointer to the data
 * @return int8_t Two's complement 24-bit value
 */
static __inline__ int32_t read_twocomp_24bit(const uint8_t *data)
{
    return (int32_t)((data[0] << 16) | (data[1] << 8) | data[2]);
}

/**
 * @brief Read unsigned 24-bit value
 * 
 * @param data Pointer to the data
 * @return uint8_t Unsigned 24-bit value
 */
static __inline__ uint32_t read_unsigned_24bit(const uint8_t *data)
{
    return (uint32_t)((data[0] << 16) | (data[1] << 8) | data[2]);
}

/**
 * @brief Read signed magnitude 32-bit value
 * 
 * @param data Pointer to the data
 * @return int8_t Signed magnitude 32-bit value
 */
static __inline__ int32_t read_signmag_32bit(const uint8_t *data)
{
    if (!(data[0] & 0x80))
        return (int32_t)((data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3]);
    return (int32_t)(-((data[0] & 0x7F) << 24 | (data[1] << 16) | (data[2] << 8) | data[3]));
}

/**
 * @brief Read two's complement 32-bit value
 * 
 * @param data Pointer to the data
 * @return int8_t Two's complement 32-bit value
 */
static __inline__ int32_t read_twocomp_32bit(const uint8_t *data)
{
    return (int32_t)((data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3]);
}

/**
 * @brief Read unsigned 32-bit value
 * 
 * @param data Pointer to the data
 * @return uint8_t Unsigned328-bit value
 */
static __inline__ uint32_t read_unsigned_32bit(const uint8_t *data)
{
    return (uint32_t)((data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3]);
}

/*******************************************************************************
 * Write functions
 ******************************************************************************/

/** 
 * @brief Write signed magnitude 8-bit value
 * 
 * @param data Pointer to the data
 * @param value Signed magnitude 8-bit value
 */
static __inline__ void write_signmag_8bit(uint8_t *data, int8_t value)
{
    if (value < 0)
        data[0] = (uint8_t)(-value | 0x80);
    else
        data[0] = (uint8_t)(value);
}

/**
 * @brief Write two's complement 8-bit value
 * 
 * @param data Pointer to the data
 * @param value Two's complement 8-bit value
 */
static __inline__ void write_twocomp_8bit(uint8_t *data, int8_t value)
{
    data[0] = (uint8_t)(value);
}

/**
 * @brief Write unsigned 8-bit value
 * 
 * @param data Pointer to the data
 * @param value Unsigned 8-bit value
 */
static __inline__ void write_unsigned_8bit(uint8_t *data, uint8_t value)
{
    data[0] = (uint8_t)(value);
}

/**
 * @brief Write signed magnitude 16-bit value
 * 
 * @param data Pointer to the data
 * @param value Signed magnitude 16-bit value
 */
static __inline__ void write_signmag_16bit(uint8_t *data, int16_t value)
{
    if (value < 0)
    {
        uint16_t abs_value = (uint16_t)(-value);
        data[0] = (uint8_t)((abs_value >> 8) | 0x80);
        data[1] = (uint8_t)(abs_value & 0xFF);
    }
    else
    {
        data[0] = (uint8_t)(value >> 8);
        data[1] = (uint8_t)(value & 0xFF);
    }
}

/**
 * @brief Write two's complement 16-bit value
 * 
 * @param data Pointer to the data
 * @param value Two's complement 16-bit value
 */
static __inline__ void write_twocomp_16bit(uint8_t *data, int16_t value)
{
    data[0] = (uint8_t)(value >> 8);
    data[1] = (uint8_t)(value & 0xFF);
}

/**
 * @brief Write unsigned 16-bit value
 * 
 * @param data Pointer to the data
 * @param value Unsigned 16-bit value
 */
static __inline__ void write_unsigned_16bit(uint8_t *data, uint16_t value)
{
    data[0] = (uint8_t)(value >> 8);
    data[1] = (uint8_t)(value & 0xFF);
}

/**
 * @brief Write signed magnitude 24-bit value
 * 
 * @param data Pointer to the data
 * @param value Signed magnitude 24-bit value
 */
static __inline__ void write_signmag_24bit(uint8_t *data, int32_t value)
{
    if (value < 0)
    {
        uint32_t abs_value = (uint32_t)(-value);
        data[0] = (uint8_t)((abs_value >> 16) | 0x80);
        data[1] = (uint8_t)((abs_value >> 8) & 0xFF);
        data[2] = (uint8_t)(abs_value & 0xFF);
    }
    else
    {
        data[0] = (uint8_t)(value >> 16);
        data[1] = (uint8_t)((value >> 8) & 0xFF);
        data[2] = (uint8_t)(value & 0xFF);
    }
}

/**
 * @brief Write two's complement 24-bit value
 * 
 * @param data Pointer to the data
 * @param value Two's complement 24-bit value
 */
static __inline__ void write_twocomp_24bit(uint8_t *data, int32_t value)
{
    data[0] = (uint8_t)(value >> 16);
    data[1] = (uint8_t)((value >> 8) & 0xFF);
    data[2] = (uint8_t)(value & 0xFF);
}

/**
 * @brief Write unsigned 24-bit value
 * 
 * @param data Pointer to the data
 * @param value Unsigned 24-bit value
 */
static __inline__ void write_unsigned_24bit(uint8_t *data, uint32_t value)
{
    data[0] = (uint8_t)(value >> 16);
    data[1] = (uint8_t)((value >> 8) & 0xFF);
    data[2] = (uint8_t)(value & 0xFF);
}

/**
 * @brief Write signed magnitude 32-bit value
 * 
 * @param data Pointer to the data
 * @param value Signed magnitude 32-bit value
 */
static __inline__ void write_signmag_32bit(uint8_t *data, int32_t value)
{
    if (value < 0)
    {
        uint32_t abs_value = (uint32_t)(-value);
        data[0] = (uint8_t)((abs_value >> 24) | 0x80);
        data[1] = (uint8_t)((abs_value >> 16) & 0xFF);
        data[2] = (uint8_t)((abs_value >> 8) & 0xFF);
        data[3] = (uint8_t)(abs_value & 0xFF);
    }
    else
    {
        data[0] = (uint8_t)(value >> 24);
        data[1] = (uint8_t)((value >> 16) & 0xFF);
        data[2] = (uint8_t)((value >> 8) & 0xFF);
        data[3] = (uint8_t)(value & 0xFF);
    }
}

/**
 * @brief Write two's complement 32-bit value
 * 
 * @param data Pointer to the data
 * @param value Two's complement 32-bit value
 */
static __inline__ void write_twocomp_32bit(uint8_t *data, int32_t value)
{
    data[0] = (uint8_t)(value >> 24);
    data[1] = (uint8_t)((value >> 16) & 0xFF);
    data[2] = (uint8_t)((value >> 8) & 0xFF);
    data[3] = (uint8_t)(value & 0xFF);
}

/**
 * @brief Write unsigned 32-bit value
 * 
 * @param data Pointer to the data
 * @param value Unsigned 32-bit value
 */
static __inline__ void write_unsigned_32bit(uint8_t *data, uint32_t value)
{
    data[0] = (uint8_t)(value >> 24);
    data[1] = (uint8_t)((value >> 16) & 0xFF);
    data[2] = (uint8_t)((value >> 8) & 0xFF);
    data[3] = (uint8_t)(value & 0xFF);
}

#ifdef __cplusplus
}
#endif

#endif // AUX_FUNCS_H