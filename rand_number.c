#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*******************************************************************************
方法: 生成[a, b)区间的整数随机数
算法: random = (rand() % (b - a)) + a;
证明: 由于rand()函数可以生成[0, RAND_MAX]区间的整随机数,
      所以(rand() % N)可以生成[0, N)区间的整随机数,
      因此[a, N + a)区间的整随机数,可以通过(rand() % N) + a表达式生成,
      如果令b = N + a,则N = b - a,
      所以[a, b)区间的整随机数,就可以通过(rand() % (b - a)) + a表达式生成.
*******************************************************************************/
int32_t rand_number(int32_t min, int32_t max)
{
	static uint8_t inited = 0;
    int32_t random = 0;

    if (!inited) {
    	inited = 1;
    	srand(time(NULL));
    }

    if (min == max) {
        random = min;
    } else {
        if (min > max) {
            random = min;
            min = max;
            max = random;
        }
        random = rand() % (max - min + 1) + min;
    }

    return random; /* min <= random <= max */
}
