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
#include <assert.h>
#include <stdio.h>

#include "bitarray.h"

int main()
{
    uint8_t bitarray_place[16] = {0};
    uint8_t bitfield_array[2] = {0};
    void *bits =
        bitarray_create(bitarray_place, bitfield_array, sizeof(bitfield_array) * 8);

    bitarray_set(bits, 0);
    bitarray_set(bits, 15);

    uint16_t *value = (uint16_t *)bitfield_array;

    printf("15 and 0 bits == 0x%0x\r\n", *value);

    // b1000_0000_0000_0001 -- 15 bit and 0 bit
    assert((*value) == 0x8001);

    return 0;
}
