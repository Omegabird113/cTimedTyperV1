#include "ldistance.h"

#include <stdlib.h>
#include <string.h>

static uint16_t min3(const uint16_t a, const uint16_t b, const uint16_t c) {
    uint16_t min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

uint16_t getLevenshteinDistance(const char *s1, const char *s2) {
    const uint16_t len1 = strlen(s1);
    const uint16_t len2 = strlen(s2);

    uint16_t table[len1 + 1][len2 + 1];

    for (uint16_t row = 0; row <= len1; row++) {
        table[row][0] = row;
    }

    for (uint16_t col = 0; col <= len2; col++) {
        table[0][col] = col;
    }

    for (uint16_t row = 1; row <= len1; row++) {
        for (uint16_t col = 1; col <= len2; col++) {
            const uint16_t strRow = row - 1;
            const uint16_t strCol = col - 1;

            const uint16_t deleteCost = table[strRow][col] + 1;
            const uint16_t insertCost = table[row][strCol] + 1;
            const uint16_t substituteCost = table[strRow][strCol] + (s1[strRow] != s2[strCol]);

            table[row][col] = min3(deleteCost, insertCost, substituteCost);
        }
    }

    return table[len1][len2];
}

double getAccuracy(const char *prompt, const char *input) {
    const uint16_t distance = getLevenshteinDistance(prompt, input);
    const uint16_t inputLen = strlen(input);
    const uint16_t maxLen = (strlen(prompt) > inputLen) ? strlen(prompt) : inputLen;
    if (maxLen == 0) {
        return 1.0;
    }
    double accuracy = 1.0 - ((double) distance / maxLen);
    if (accuracy < 0.0) {
        accuracy = 0.0;
    }
    return accuracy;
}
