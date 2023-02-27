#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint32_t check_sum8(const uint8_t *buf, uint32_t cnt)
{
    uint32_t i, sum;

    sum = 0x00;
    for (i = 0; i < cnt; i++) {
        sum += *buf++;
    }

    return sum;
}

uint32_t check_sum16(const uint16_t *buf, uint32_t cnt)
{
    uint32_t i, sum;

    sum = 0x00;
    for (i = 0; i < cnt; i++) {
        sum += *buf++;
    }

    return sum;
}

uint32_t check_sum32(const uint32_t *buf, uint32_t cnt)
{
    uint32_t i, sum;

    sum = 0x00;
    for (i = 0; i < cnt; i++) {
        sum += *buf++;
    }

    return sum;
}
