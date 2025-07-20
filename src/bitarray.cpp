/**
 * @file bitarray.cpp
 * @author Viacheslav (viacheslav@mcublog.ru)
 * @brief
 * @version 0.1
 * @date 2025-07-20
 *
 * @copyright mcublog Copyright (c) 2025
 *
 */
#include <algorithm>
#include <climits>
#include <cstring>

#include "bitarray.h"
#include "bitarray.hpp"

//>>---------------------- Locals
#define BIT_CHAR(bit) ((bit) / CHAR_BIT)
#define BIT_IN_CHAR(bit) (1 << ((bit) % CHAR_BIT))
#define BITS_TO_CHARS(bits) ((((bits) - 1) / CHAR_BIT) + 1)
//<<----------------------

void bitarray::set()
{
    uint32_t size = BITS_TO_CHARS(m_num_bits);

    /* set bits in all bytes to 1 */
    std::memset(m_array, UCHAR_MAX, size);

    /* zero any spare bits so increment and decrement are consistent */
    uint32_t bits = m_num_bits % CHAR_BIT;
    if (bits != 0)
    {
        uint8_t mask = UCHAR_MAX << (CHAR_BIT - bits);
        m_array[BIT_CHAR(m_num_bits - 1)] = mask;
    }
}

void bitarray::clear()
{
    uint32_t size = BITS_TO_CHARS(m_num_bits);

    /* set bits in all bytes to 0 */
    std::memset(m_array, 0, size);
}

void bitarray::set(uint32_t bit)
{
    if (m_num_bits <= bit)
    {
        return; /* bit out of range */
    }

    m_array[BIT_CHAR(bit)] |= BIT_IN_CHAR(bit);
}

void bitarray::clear(uint32_t bit)
{
    if (m_num_bits <= bit)
    {
        return; /* bit out of range */
    }

    /* create a mask to zero out desired bit */
    uint8_t mask = BIT_IN_CHAR(bit);
    mask = ~mask;

    m_array[BIT_CHAR(bit)] &= mask;
}

void bitarray::reverse()
{
    uint32_t size = BITS_TO_CHARS(m_num_bits);
    uint8_t *istart = m_array, *iend = m_array + size;
    std::reverse(istart, iend);
}

//>>---------------------- C Api
/**
 * @brief C array for bitarray class, size >= sizeof(bitarray)
 *
 * @param mem
 * @param array
 * @param numBits
 * @return void*
 */
void *bitarray_create(uint8_t *mem, uint8_t *array, uint32_t numBits)
{
    bitarray bits{array, numBits};
    std::memcpy(mem, &bits, sizeof(bits));
    return mem;
}

uint32_t bitarray_size(const void *handle)
{
    return static_cast<const bitarray *>(handle)->size();
}

void bitarray_set_all(void *handle)
{
    static_cast<bitarray *>(handle)->set();
}

void bitarray_clear_all(void *handle)
{
    static_cast<bitarray *>(handle)->clear();
}
void bitarray_set(void *handle, uint32_t bit)
{
    static_cast<bitarray *>(handle)->set(bit);
}

void bitarray_clear(void *handle, uint32_t bit)
{
    static_cast<bitarray *>(handle)->clear(bit);
}

void bitarray_reverse(void *handle)
{
    static_cast<bitarray *>(handle)->reverse();
}
//<<----------------------