#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint32_t crc32_compute(const uint8_t *p_data, uint32_t size, const uint32_t *p_crc)
{
    uint32_t i, j, crc;

    crc = (p_crc == NULL) ? 0xFFFFFFFF : ~(*p_crc);
    for (i = 0; i < size; i++) {
        crc = crc ^ p_data[i];
        for (j = 8; j > 0; j--) {
            crc = (crc >> 1) ^ (0xEDB88320U & ((crc & 1) ? 0xFFFFFFFF : 0));
        }
    }

    return ~crc;
}
