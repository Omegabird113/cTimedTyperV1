#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

uint32_t getRandomIntInclusive(const uint32_t min, const uint32_t max) {
    if (min > max) {
        printf("getRandomIntInclusive ERROR: max must be greater than min\n");
        exit(1);
    }
    return (rand() % (max - min + 1)) + min;
}

double logBase(const double b, const double y) {
    return log(y) / log(b);
}

uint16_t getWordCount(const char *s) {
    uint16_t count = 0;
    bool inWord = false;

    while (*s) {
        if (*s == ' ') {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            count++;
        }
        s++;
    }

    return count;
}