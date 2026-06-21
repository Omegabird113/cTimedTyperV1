#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include <time.h>

typedef enum Difficulty {
    EASY,
    MEDIUM,
    HARD,
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

RoundData* runRound(RoundData* pRData);

void play(const Difficulty difficulty, const uint16_t rounds, const float scoreMultiplier);

#endif