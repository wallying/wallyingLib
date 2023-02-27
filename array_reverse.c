#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void array_reverse(uint8_t *array, uint16_t length)
{
    uint8_t temp;
    uint16_t i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
