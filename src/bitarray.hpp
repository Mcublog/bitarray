#pragma once

#include <cstdint>

class bitarray
{
  private:
    class bit_proxy
    {
      public:
        bit_proxy(bitarray &bitarray, uint32_t bit) : m_bits(bitarray), m_bit(bit)
        {
        }

        operator bool() const;
        void operator=(bool state);

      private:
        bitarray &m_bits;
        uint32_t m_bit;
    };

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
    bool get(uint32_t bit) const;
    void clear(uint32_t bit);
    void reverse();

    // Overload for read/write access
    bit_proxy operator[](uint32_t bit);

  protected:
    uint32_t m_num_bits;
    uint8_t *m_array;
};