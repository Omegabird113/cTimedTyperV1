#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include <time.h>

typedef enum Difficulty {
    EASY = 1,
    MEDIUM = 2,
    HARD = 4,
} Difficulty;

typedef struct RoundData {
    uint8_t roundNum;
    Difficulty difficulty;
    time_t timeLimit;
    uint16_t buffSize;
    char* prompt;
    char* input;
    time_t timeTaken;
    uint16_t roundScore;
} RoundData;

typedef struct GameState {
    uint16_t roundNum;
    RoundData *roundData;
    uint64_t totalScore;
    float scoreMultiplier;
    Difficulty currentDifficulty;
} GameState;

RoundData *runRound(RoundData *pRData);

void play(uint64_t startScore, uint16_t rounds, float scoreMultiplier);

#endif
