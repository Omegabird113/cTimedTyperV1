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
    time_t timeLimit;
    char prompt[768];
    time_t timeTaken;
    char input[778];
    uint32_t score;
} RoundData;

typedef struct GameState {
    uint16_t roundNum;
    RoundData* roundData;
    uint64_t totalScore;
    float scoreMultiplier;
    Difficulty difficulty;
} GameState;

RoundData* runRound(RoundData* pRData);

void play(Difficulty difficulty, uint16_t rounds, float scoreMultiplier);

#endif