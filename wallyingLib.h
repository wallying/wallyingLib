
void hexdump(const char *name, const void *buf, uint16_t len);

int32_t rand_number(int32_t min, int32_t max);

void    bit_set(uint8_t *data, uint32_t bit_idx, uint8_t bit_value);

uint8_t bit_get(const uint8_t *data, uint32_t bit_idx);

uint32_t bits_count(const uint8_t *data, uint32_t bit_num);

void bits_reverse(uint8_t *data, uint32_t bit_num);

void array_reverse(uint8_t *array, uint16_t length);


