/**
 * @file main.c
 * @author Viacheslav (viacheslav@mcublog.ru)
 * @brief
 * @version 0.1
 * @date 2025-07-20
 *
 * @copyright mcublog Copyright (c) 2025
 *
 */
#include <cassert>
#include <cstdio>

#include "bitarray.hpp"

int main()
{
    uint8_t bitfield_array[2] = {0};
    bitarray bits {bitfield_array, sizeof(bitfield_array) * 8};

    bits[0] = 1;
    bits[15] = 1;

    uint16_t by_bits = bits[15] << 15 | bits[0];

    uint16_t *value = (uint16_t *)bitfield_array;

    printf("15 and 0 bits == 0x%0x == 0x%0x\r\n", *value, by_bits);

    // b1000_0000_0000_0001 -- 15 bit and 0 bit
    assert((*value) == by_bits);
    assert(by_bits == 0x8001);

    return 0;
}