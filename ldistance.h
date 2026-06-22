#ifndef LDISTANCE_H
#define LDISTANCE_H

#include <stdint.h>

static uint16_t min3(uint16_t a, uint16_t b, uint16_t c);
uint16_t getLevenshteinDistance(const char *s1, const char *s2);
double accuracy(const char *prompt, const char *input);

#endif //LDISTANCE_H
