#ifndef INFRA_H
#define INFRA_H

#include <stdint.h>
#include <stddef.h>

#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

////////////////////////////////////////////////////////////////////////////////

typedef struct {
    u8 *    buffer;
    size_t  buffer_size;
    size_t  byte_pos;
    size_t  bit_pos;
} BitStream;

ASTERIX_LIB inline void bs_init(BitStream * bs, u8 * buffer, size_t buffer_size)
{
    bs->buffer      = buffer;
    bs->buffer_size = buffer_size;
    bs->byte_pos    = 3; /* Start at 3 to write CAT and LEN last */
    bs->bit_pos     = 0;
}
ASTERIX_LIB inline void bs_inc_pos(BitStream * bs, size_t byte_inc, size_t bit_inc)
{
    bs->byte_pos += byte_inc;
    bs->bit_pos  += bit_inc;
    if (bs->bit_pos == 8)
    {
        bs->byte_pos++;
        bs->bit_pos = 0;
    }
}

////////////////////////////////////////////////////////////////////////////////

void _bs_serialize(BitStream * bs, u64 value, size_t n_bits);
u64  _bs_deserialize(BitStream * bs, size_t n_bits);

////////////////////////////////////////////////////////////////////////////////

ASTERIX_LIB static inline void bs_serialize_cat(BitStream * bs, u8 cat)
{
    bs->buffer[0U] = cat;
}
ASTERIX_LIB static inline u8 bs_deserialize_cat(BitStream * bs)
{
    return bs->buffer[0U];
}

////////////////////////////////////////////////////////////////////////////////

ASTERIX_LIB static inline void bs_serialize_len(BitStream * bs)
{
    size_t len = bs->byte_pos + (bs->bit_pos ? 1U : 0U);
    bs->buffer[1U] = (u8)((len >> 8U) & 0xFFU);
    bs->buffer[2U] = (u8)(len & 0xFFU);
}
ASTERIX_LIB static inline u16 bs_deserialize_len(BitStream * bs)
{
    return ((u16)bs->buffer[1U] << 8U) | (u16)bs->buffer[2U];
}

////////////////////////////////////////////////////////////////////////////////

ASTERIX_LIB static inline void bs_serialize_header(BitStream * bs, u8 cat)
{
    bs_serialize_cat(bs, cat);
    bs_serialize_len(bs);
}

////////////////////////////////////////////////////////////////////////////////

ASTERIX_LIB static inline void bs_serialize_u8(BitStream * bs, u8 value, size_t n_bits)
{
    _bs_serialize(bs, (u64)(value), (n_bits > 8U) ? 8U : n_bits);
}
ASTERIX_LIB static inline u8 bs_deserialize_u8(BitStream * bs, size_t n_bits)
{
    return (u8)(_bs_deserialize(bs, (n_bits > 8U) ? 8U : n_bits));
}
ASTERIX_LIB static inline void bs_serialize_s8(BitStream * bs, s8 value, size_t n_bits)
{
    _bs_serialize(bs, (s64)(value), (n_bits > 8U) ? 8U : n_bits);
}
ASTERIX_LIB static inline s8 bs_deserialize_s8(BitStream * bs, size_t n_bits)
{
    return (s8)(_bs_deserialize(bs, (n_bits > 8U) ? 8U : n_bits));
}

////////////////////////////////////////////////////////////////////////////////

ASTERIX_LIB static inline void bs_serialize_u16(BitStream * bs, u16 value, size_t n_bits)
{
    _bs_serialize(bs, (u64)(value), (n_bits > 16U) ? 16U : n_bits);
}
ASTERIX_LIB static inline u16 bs_deserialize_u16(BitStream * bs, size_t n_bits)
{
    return (u16)(_bs_deserialize(bs, (n_bits > 16U) ? 16U : n_bits));
}
ASTERIX_LIB static inline void bs_serialize_s16(BitStream * bs, s16 value, size_t n_bits)
{
    _bs_serialize(bs, (s64)(value), (n_bits > 16U) ? 16U : n_bits);
}
ASTERIX_LIB static inline s16 bs_deserialize_s16(BitStream * bs, size_t n_bits)
{
    return (s16)(_bs_deserialize(bs, (n_bits > 16U) ? 16U : n_bits));
}

////////////////////////////////////////////////////////////////////////////////

ASTERIX_LIB static inline void bs_serialize_u32(BitStream * bs, u32 value, size_t n_bits)
{
    _bs_serialize(bs, (u64)(value), (n_bits > 32U) ? 32U : n_bits);
}
ASTERIX_LIB static inline u32 bs_deserialize_u32(BitStream * bs, size_t n_bits)
{
    return (u32)(_bs_deserialize(bs, (n_bits > 32U) ? 32U : n_bits));
}
ASTERIX_LIB static inline void bs_serialize_s32(BitStream * bs, s32 value, size_t n_bits)
{
    _bs_serialize(bs, (s64)(value), (n_bits > 32U) ? 32U : n_bits);
}
ASTERIX_LIB static inline s32 bs_deserialize_s32(BitStream * bs, size_t n_bits)
{
    return (s32)(_bs_deserialize(bs, (n_bits > 32U) ? 32U : n_bits));
}

////////////////////////////////////////////////////////////////////////////////

ASTERIX_LIB static inline void bs_serialize_u64(BitStream * bs, u64 value, size_t n_bits)
{
    _bs_serialize(bs, (u64)(value), (n_bits > 64U) ? 64U : n_bits);
}
ASTERIX_LIB static inline u64 bs_deserialize_u64(BitStream * bs, size_t n_bits)
{
    return (u64)(_bs_deserialize(bs, (n_bits > 64U) ? 64U : n_bits));
}
ASTERIX_LIB static inline void bs_serialize_s64(BitStream * bs, s64 value, size_t n_bits)
{
    _bs_serialize(bs, (s64)(value), (n_bits > 64U) ? 64U : n_bits);
}
ASTERIX_LIB static inline s64 bs_deserialize_s64(BitStream * bs, size_t n_bits)
{
    return (s64)(_bs_deserialize(bs, (n_bits > 64U) ? 64U : n_bits));
}

////////////////////////////////////////////////////////////////////////////////

ASTERIX_LIB static inline void bs_serialize_ufloat(BitStream * bs, float value, float step, size_t n_bits)
{
    _bs_serialize(bs, (u64)(value / step), n_bits);
}
ASTERIX_LIB static inline float bs_deserialize_ufloat(BitStream * bs, float step, size_t n_bits)
{
    return (float)(_bs_deserialize(bs, n_bits) * step);
}
ASTERIX_LIB static inline void bs_serialize_sfloat(BitStream * bs, float value, float step, size_t n_bits)
{
    _bs_serialize(bs, (u64)((s64)(value / step)), n_bits);
}
ASTERIX_LIB static inline float bs_deserialize_sfloat(BitStream * bs, float step, size_t n_bits)
{
    return (float)(((s64)_bs_deserialize(bs, n_bits)) * step);
}

////////////////////////////////////////////////////////////////////////////////

ASTERIX_LIB static inline void bs_serialize_udouble(BitStream * bs, double value, double step, size_t n_bits)
{
    _bs_serialize(bs, (u64)(value / step), n_bits);
}
ASTERIX_LIB static inline double bs_deserialize_udouble(BitStream * bs, double step, size_t n_bits)
{
    return (double)(_bs_deserialize(bs, n_bits) * step);
}
ASTERIX_LIB static inline void bs_serialize_sdouble(BitStream * bs, double value, double step, size_t n_bits)
{
    _bs_serialize(bs, (u64)((s64)(value / step)), n_bits);
}
ASTERIX_LIB static inline double bs_deserialize_sdouble(BitStream * bs, double step, size_t n_bits)
{
    return (double)(((s64)_bs_deserialize(bs, n_bits)) * step);
}

////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* INFRA_H */