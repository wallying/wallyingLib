#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* CRC16/MODBUS POLY=0x8005 (x16+x15+x2+1) */
uint16_t crc16_compute(const uint8_t *p_data, uint16_t size, const uint16_t *p_crc)
{
    uint16_t poly[2] = {0x0000, 0xA001};            //0x8005 <==> 0xA001
    uint16_t crc;
    int i, j;
	crc = (p_crc == NULL) ? 0xFFFF: *p_crc;

    for (j = size; j > 0; j--) {
        uint8_t ds = *p_data++;
        for(i = 0; i < 8; i++) {
            crc = (crc >> 1) ^ poly[(crc ^ ds) & 1];
            ds = ds >> 1;
        }
    }

    return crc;
}

/* CRC32 POLY=0x04C11DB7 (x32+x26+x23+x22+x16+x12+x11+x10+x8+x7+x5+x4+x2+x+1) */
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
