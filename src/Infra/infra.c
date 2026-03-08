/**
 * @file infra.c
 * @brief 
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 */
#include <Infra/infra.h>

////////////////////////////////////////////////////////////////////////////////

void _bs_serialize(BitStream * bs, u64 value, size_t n_bits)
{
    u8 bit = 0U;
    size_t i = 0U;

    for (i = 0; i < n_bits; ++i) {
        bit = (value >> (n_bits - 1U - i)) & 1U;

        bs->buffer[bs->byte_pos] &= ~(1U << (7U - bs->bit_pos));
        bs->buffer[bs->byte_pos] |=  (bit << (7U - bs->bit_pos));

        bs->bit_pos++;
        if (bs->bit_pos == 8U) {
            bs->bit_pos = 0U;
            bs->byte_pos++;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

u64 _bs_deserialize(BitStream * bs, size_t nbits)
{
    u64 value = 0U;
    size_t i = 0U;
    u8 bit = 0U;

    for (i = 0U; i < nbits; i++) {
        bit = ((bs->buffer[bs->byte_pos]) >> (7U - bs->bit_pos)) & 1U;

        value = (value << 1U) | bit;
        bs->bit_pos++;
        if (bs->bit_pos == 8U) {
            bs->bit_pos = 0U;
            bs->byte_pos++;
        }
    }

    return value;
}

////////////////////////////////////////////////////////////////////////////////
