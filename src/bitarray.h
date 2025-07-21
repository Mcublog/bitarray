
#ifndef APP_UTILS_DATA_BITARRAY_H
#define APP_UTILS_DATA_BITARRAY_H

#include <stdbool.h>
#include <stdint.h>

#define BITARRAY_PLACE_SIZE (16U)

#ifdef __cplusplus
extern "C" {
#endif

    void *bitarray_create(uint8_t *mem, uint8_t *array, uint32_t numBits);

    uint32_t bitarray_size(const void *handle);

    void bitarray_set_all(void *handle);
    void bitarray_clear_all(void *handle);
    void bitarray_set(void *handle, uint32_t bit);
    bool bitarray_get(const void *handle, uint32_t bit);
    void bitarray_clear(void *handle, uint32_t bit);
    void bitarray_reverse(void *handle);

#ifdef __cplusplus
}
#endif

#endif // APP_UTILS_DATA_BITARRAY_H