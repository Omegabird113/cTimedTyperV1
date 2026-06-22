#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include "words.h"
#include "game.h"

#include <inttypes.h>

#include "ldistance.h"

int getRandomIntInclusive(const int min, const int max) {
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

uint16_t getRoundScore(const time_t limit, const time_t taken, const char *prompt, const char *input,
                       const Difficulty difficulty) {
    const double timeRelative = (double) taken / (double) limit;
    const double accuracy = getAccuracy(prompt, input);

    const double baseScore = difficulty * accuracy * pow(getWordCount(prompt), 1.5) * (1 / timeRelative);
    const double randomFactor = getRandomIntInclusive(12500, 7500) / 10000.0;
    const double finalScore = baseScore * randomFactor;

    return ceil(finalScore);
}

RoundData *runRound(RoundData *pRData) {
    const time_t start = time(nullptr);
    printf("Round #%d:\nEnter the following within %ld seconds:\n%s\n", pRData->roundNum, pRData->timeLimit,
           pRData->prompt);
    if (fgets(pRData->input, sizeof(pRData->input), stdin) == NULL) {
        return pRData;
    }
    pRData->input[strcspn(pRData->input, "\n")] = '\0';
    const time_t end = time(nullptr);
    pRData->timeTaken = end - start;
    pRData->roundScore = getRoundScore(pRData->timeLimit, pRData->timeTaken, pRData->prompt, pRData->input,
                                       pRData->difficulty);
    return pRData;
}

uint16_t getSafeWordLength(const uint8_t length, const Difficulty difficulty) {
    constexpr uint16_t maxChars = 768;
    uint16_t possibleChars = 0;

    if (difficulty == EASY) {
        constexpr uint8_t easySize = 4; // 3-letter words + null byte
        possibleChars = (easySize + 2) * length; // +2 because spaces around words
        if (possibleChars > maxChars) {
            return floor((double) maxChars / (easySize + 2));
        }
    } else if (difficulty == MEDIUM) {
        constexpr uint8_t mediumSize = 7;
        possibleChars = (mediumSize + 2) * length;
        if (possibleChars > maxChars) {
            return floor((double) maxChars / (mediumSize + 2));
        }
    } else if (difficulty == HARD) {
        constexpr uint8_t hardSize = 16;
        possibleChars = (hardSize + 2) * length;
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
        const char *rWord;

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

    roundData.difficulty = difficulty;

    char prompt[768];
    getRandomPrompt(prompt, sizeof(prompt), promptLength, difficulty);
    // printf("DEBUG: '%s'\n", prompt);

    strcpy((&roundData)->prompt, prompt);

    const time_t timeLimit = (time_t) getRandomIntInclusive(5, 8) + (promptLength * difficulty);
    roundData.timeLimit = timeLimit;

    roundData.roundNum = roundNum;

    memset(roundData.input, 0, sizeof(roundData.input));
    roundData.timeTaken = (time_t) 0;
    roundData.roundScore = 0;
    return roundData;
}

void askForNextRound(const bool start) {
    while (true) {
        if (start) {
            printf("Are you ready to play?: (y/N)\n");
        } else {
            printf("Do you want to play another round? (y/N):\n");
        }
        char buffer[4];
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            const char answer = buffer[0];
            if ((answer == 'N' || answer == 'n') && !start) {
                exit(0);
            }
            if (answer == 'Y' || answer == 'y') {
                break;
            }
        }
    }
}

Difficulty genDifficulty(const uint64_t totalScore) {
    if (totalScore > 2450) {
        return HARD;
    }
    if (totalScore > 520) {
        return MEDIUM;
    }
    return EASY;
}

void play(const uint64_t startScore, const uint16_t rounds, const float scoreMultiplier) {
    auto pGameState = (GameState *) malloc(sizeof(GameState));
    pGameState->roundData = malloc(rounds * sizeof(RoundData));

    if (!pGameState->roundData) {
        free(pGameState);
        return;
    }

    pGameState->roundNum = 1;
    pGameState->totalScore = startScore;
    pGameState->scoreMultiplier = scoreMultiplier;

    askForNextRound(true);

    for (uint16_t r = 0; r < rounds; r++) {
        const uint8_t promptLength = ((uint8_t) logBase(2.079, (pGameState->totalScore) + 6.4) + 4);
        pGameState->currentDifficulty = genDifficulty(pGameState->totalScore);
        // printf("promptLength: '%hhu'\n", promptLength);
        pGameState->roundData[r] = genRoundData(r + 1, pGameState->currentDifficulty, promptLength);
        runRound(&(pGameState->roundData[r]));
        pGameState->totalScore += ceil(pGameState->roundData[r].roundScore * pGameState->scoreMultiplier);
        printf("You're total score is now %" PRIu64 "!\n", pGameState->totalScore);
        askForNextRound(false);
        pGameState->roundNum++;
    }

    free(pGameState->roundData);
    free(pGameState);
    pGameState = nullptr;
}
