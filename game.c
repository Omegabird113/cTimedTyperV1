#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>
#include "words.h"

typedef enum Difficulty {
    EASY = 1,
    MEDIUM = 2,
    HARD = 4,
} Difficulty;

typedef struct RoundData {
    uint16_t roundNum;
    time_t timeLimit;
    char* prompt;
    time_t timeTaken;
    char* input;
    uint32_t score;
} RoundData;

typedef struct GameState {
    uint16_t roundNum;
    RoundData* roundData;
    uint64_t totalScore;
    float scoreMultiplier;
    Difficulty difficulty;
} GameState;

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
    srand(time(nullptr));
    return (rand() % (max - min + 1)) + min;
}

void getRandomPrompt(char *buffer, size_t bufferSize, uint8_t length, Difficulty difficulty)
{
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

        strncat(buffer, rWord, bufferSize - strlen(buffer) - 1);
    }
}

RoundData genRoundData(uint16_t roundNum, Difficulty difficulty, uint8_t promptLength) {
    RoundData roundData = {};

    char prompt[sizeof(HARD_WORDS) * promptLength];
    getRandomPrompt(prompt, sizeof(prompt), promptLength, difficulty);

    roundData.prompt = prompt;

    time_t timeLimit = (time_t) getRandomIntInclusive(5, 8) + (promptLength * difficulty);

    roundData.timeLimit = timeLimit;

    roundData.roundNum = roundNum;

    char inputBuffer[sizeof(prompt)];

    roundData.input = inputBuffer;
    roundData.timeTaken = (time_t) 0;
    roundData.score = 0;
}

double logBase(const double b, const double y) {
    return log(b) / log(y);
}

void play(const Difficulty difficulty, const uint16_t rounds, const float scoreMultiplier) {
    GameState* pGameState = (GameState*)malloc(sizeof(GameState));
    RoundData* pRoundData = (RoundData*)malloc(sizeof(RoundData) * rounds);

    pGameState->roundNum = 1;
    pGameState->roundData = pRoundData;
    pGameState->totalScore = 0;
    pGameState->scoreMultiplier = scoreMultiplier;
    pGameState->difficulty = difficulty;

    for (uint16_t r = 1; r <= rounds; r++) {
        pRoundData[r] = genRoundData(r, difficulty, ((uint8_t) logBase(2.079, (pGameState->totalScore) + 6.4) + 4));
        runRound(&pRoundData[r]);
        pRoundData->roundNum++;
    }

    free(pGameState);
    pGameState = nullptr;
    free(pRoundData);
    pRoundData = nullptr;
}