#ifndef __WALLYING_LIB_H__
#define __WALLYING_LIB_H__

#include "stdint.h"


void hexdump(const char *name, const void *buf, uint16_t len);


int32_t rand_number(int32_t min, int32_t max);


void    bit_set(uint8_t *data, uint32_t bit_idx, uint8_t bit_value);

uint8_t bit_get(const uint8_t *data, uint32_t bit_idx);

uint32_t bits_count(const uint8_t *data, uint32_t bit_num);

void bits_reverse(uint8_t *data, uint32_t bit_num);


void array_reverse(uint8_t *array, uint16_t length);


uint32_t check_sum8(const uint8_t *buf, uint32_t cnt);

uint32_t check_sum16(const uint16_t *buf, uint32_t cnt);

uint32_t check_sum32(const uint32_t *buf, uint32_t cnt);


uint32_t crc32_compute(const uint8_t *p_data, uint32_t size, const uint32_t *p_crc);


#endif /* __WALLYING_LIB_H__ */
