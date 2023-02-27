#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void bit_set(uint8_t *data, uint32_t bit_idx, uint8_t bit_value)
{
    uint8_t byte_idx;
    uint8_t bit_mask;

    byte_idx = bit_idx >> 3;
    bit_mask = 1 << (bit_idx & 0x07);

    if (bit_value) {
        data[byte_idx] |= bit_mask;
    } else {
        data[byte_idx] &= ~bit_mask;
    }
}

uint8_t bit_get(const uint8_t *data, uint32_t bit_idx)
{
    uint8_t byte_idx;
    uint8_t bit_mask;

    byte_idx = bit_idx >> 3;
    bit_mask = 1 << (bit_idx & 0x07);

    return ((data[byte_idx] & bit_mask) ? 1 : 0);
}

uint32_t bits_count(const uint8_t *data, uint32_t bit_num)
{
    uint32_t i, cnt;

    cnt = 0;

    for (i = 0; i < bit_num; i++) {
        if (bit_get(data, i)) {
            cnt++;
        }
    }

    return cnt;
}

void bits_reverse(uint8_t *data, uint32_t bit_num)
{
    uint8_t a, b;
    uint32_t i, j;

    if (bit_num == 0) {
        return;
    }

    for (i = 0, j = bit_num - 1; i < j; i++, j--) {
        a = bit_get(data, i);
        b = bit_get(data, j);
        bit_set(data, i, b);
        bit_set(data, j, a);
    }
}
