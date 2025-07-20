#pragma once

#include <cstdint>

class bitarray
{
  public:
    bitarray(uint8_t *array, uint32_t numBits)
        : m_num_bits{numBits}, m_array{array} {};

    uint32_t size() const
    {
        return m_num_bits;
    };

    /* set/clear functions */
    void set();
    void clear();
    void set(uint32_t bit);
    void clear(uint32_t bit);
    void reverse();

  protected:
    uint32_t m_num_bits;
    uint8_t *m_array;
};