#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define HEXDUMP_LINE_WIDTH (16)
#define HEXDUMP_BUF_LEN_MAX (1024)
static char log_buf[HEXDUMP_BUF_LEN_MAX] = {0};

void hexdump(const char *name, const void *buf, uint16_t len)
{
    #define __is_print(ch) ((uint32_t)((ch) - ' ') < 127u - ' ')

    if ((buf == NULL) || (len == 0)) {
        return;
    }

    uint8_t *ptr = (uint8_t *)buf;
    uint16_t i, j;
    uint16_t log_len = 0;

    printf("%s [len = %d] :\r\n", name, len);

    for (i = 0; i < len; i += HEXDUMP_LINE_WIDTH) {
        log_len = snprintf(log_buf, HEXDUMP_BUF_LEN_MAX, "%04X-%04X: ", i, i + HEXDUMP_LINE_WIDTH - 1);

        for (j = 0; j < HEXDUMP_LINE_WIDTH; j++) {
            if (i + j < len) {
                log_len += snprintf(log_buf + log_len, HEXDUMP_BUF_LEN_MAX - log_len, "%02X ", ptr[i + j]);
            } else {
                log_len += snprintf(log_buf + log_len, HEXDUMP_BUF_LEN_MAX - log_len, "   ");
            }
            if ((j + 1) % 8 == 0) {
                log_len += snprintf(log_buf + log_len, HEXDUMP_BUF_LEN_MAX - log_len, " ");
            }
        }
        log_len += snprintf(log_buf + log_len, HEXDUMP_BUF_LEN_MAX - log_len, "  ");

        for (j = 0; j < HEXDUMP_LINE_WIDTH; j++) {
            if (i + j < len) {
                log_len += snprintf(log_buf + log_len, HEXDUMP_BUF_LEN_MAX - log_len, "%c", __is_print(ptr[i + j]) ? ptr[i + j] : '.');
            }
        }

        log_len += snprintf(log_buf + log_len, HEXDUMP_BUF_LEN_MAX - log_len, "\r\n");
        printf(log_buf, log_len);
    }
}
