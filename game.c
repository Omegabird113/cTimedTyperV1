#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include "words.h"
#include "game.h"


RoundData* runRound(RoundData* pRData) {
    const time_t start = time(nullptr);
    printf("Round #%d:\nEnter the following:\n%s\n", pRData->roundNum, pRData->prompt);
    if (scanf("%s", pRData->input) != 1) {
        exit(1);
    }
    const time_t end = time(nullptr);
    pRData->timeTaken = end - start;
    return pRData;
}

int getRandomIntInclusive(const int min, const int max) {
    return (rand() % (max - min + 1)) + min;
}

uint16_t getSafeWordLength(const uint8_t length, const Difficulty difficulty) {
    constexpr uint16_t maxChars = 768;
    uint16_t possibleChars = 0;

    if (difficulty == EASY) {
        constexpr uint8_t easySize = 4; // 3-letter words + null byte
        possibleChars = (easySize+2) * length; // +2 because spaces around words
        if (possibleChars > maxChars) {
            return floor((double) maxChars / (easySize + 2));
        }
    } else if (difficulty == MEDIUM) {
        constexpr uint8_t mediumSize = 7;
        possibleChars = (mediumSize+2) * length;
        if (possibleChars > maxChars) {
            return floor((double) maxChars / (mediumSize + 2));
        }
    } else if (difficulty == HARD) {
        constexpr uint8_t hardSize = 16;
        possibleChars = (hardSize+2) * length;
        if (possibleChars > maxChars) {
            return floor((double) maxChars / (hardSize + 2));
        }
    }

    return length;
}

void getRandomPrompt(char *buffer, const size_t bufferSize, uint8_t length, const Difficulty difficulty) {
    length = getSafeWordLength(length, difficulty);

    buffer[0] = '\0';

    for (uint8_t i = 0; i < length; i++) {
        char *rWord;

        switch (difficulty) {
            case EASY:
                rWord = EASY_WORDS[getRandomIntInclusive(0, LEN_EASY_WORDS - 1)];
                break;
            case MEDIUM:
                rWord = MEDIUM_WORDS[getRandomIntInclusive(0, LEN_MEDIUM_WORDS - 1)];
                break;
            case HARD:
                rWord = HARD_WORDS[getRandomIntInclusive(0, LEN_HARD_WORDS - 1)];
                break;
            default:
                return;
        }

        // printf("WORD: '%s'\n", rWord);

        strncat(buffer, rWord, bufferSize - strlen(buffer) - 1);
        if (i + 1 < length) {
            strncat(buffer, " ", bufferSize - strlen(buffer) - 1);
        }
    }
}

RoundData genRoundData(const uint16_t roundNum, const Difficulty difficulty, const uint8_t promptLength) {
    RoundData roundData = {};

    char prompt[768];
    getRandomPrompt(prompt, sizeof(prompt), promptLength, difficulty);
    // printf("DEBUG: '%s'\n", prompt);

    strcpy((&roundData)->prompt, prompt);

    const time_t timeLimit = (time_t) getRandomIntInclusive(5, 8) + (promptLength * difficulty);
    roundData.timeLimit = timeLimit;

    roundData.roundNum = roundNum;

    memset(roundData.input, 0, sizeof(roundData.input));

    roundData.timeTaken = (time_t) 0;
    roundData.score = 0;
    return roundData;
}

double logBase(const double b, const double y) {
    return log(y) / log(b);
}

void play(const Difficulty difficulty, const uint16_t rounds, const float scoreMultiplier) {
    GameState* pGameState = (GameState*)malloc(sizeof(GameState));

    pGameState->roundNum = 1;
    pGameState->totalScore = 0;
    pGameState->scoreMultiplier = scoreMultiplier;
    pGameState->difficulty = difficulty;

    for (uint16_t r = 0; r < rounds; r++) {
        const uint8_t promptLength = ((uint8_t) logBase(2.079, (pGameState->totalScore) + 6.4) + 4);
        // printf("promptLength: '%hhu'\n", promptLength);
        pGameState->roundData[r] = genRoundData(r + 1, difficulty, promptLength);
        runRound(&(pGameState->roundData[r]));
        pGameState->roundNum++;
    }

    free(pGameState);
    pGameState = nullptr;
}