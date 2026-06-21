#include <stdint.h>

const char EASY_WORDS[98][4] = {
    "bat", "dog", "toy", "cat", "rat", "law", "mud", "boy", "the", "she",
    "red", "pop", "lie", "bay", "hay", "can", "sad", "mad", "cap", "rap",
    "met", "fad", "hop", "top", "tap", "lap", "bag", "ham", "ray",
    "say", "tie", "bit", "hit", "hat", "bet", "bid", "lid", "pad", "and",
    "tan", "tar", "eat", "ate", "lag", "rag", "tag", "kid", "dip", "rip",
    "lip", "pod", "rod", "nod", "his", "sis", "gem", "ant", "wad", "win",
    "nap", "way", "pay", "day", "van", "mom", "dad", "dot", "rot", "tip",
    "hen", "tin", "fee", "pee", "tee", "tea", "pea", "bee", "sea", "see",
    "men", "man", "did", "sim", "pin", "fib", "yay", "may", "pot", "pan",
    "run", "ran", "ton", "put", "hut", "but", "cut", "pit", "vat"
};

const uint8_t LEN_EASY_WORDS = sizeof(EASY_WORDS) / sizeof(EASY_WORDS[0]);

const char MEDIUM_WORDS[75][7] = {
    "lemon", "cheese", "happy", "angry", "tomato", "carve", "tattoo",
    "water", "walks", "visit", "liver", "flight", "height", "skirts",
    "house", "train", "spoon", "tiger", "zebra", "doctor", "teach",
    "study", "juice", "bottle", "never", "peace", "donor", "python",
    "coding", "uncle", "sleeps", "table", "wonder", "growth", "forest",
    "river", "yellow", "purple", "cycle", "pillow", "school", "queen",
    "yogurt", "bouncy", "flavor", "guitar", "piano", "breeze", "sunny",
    "window", "marvel", "gloves", "framed", "sweet", "dirty", "clean",
    "apple", "coffee", "button", "refer", "climb", "minute", "light",
    "shelf", "wobble", "tired", "party", "brain", "vault", "tennis",
    "winter", "cover", "paper", "pencil", "hello"
};

const uint8_t LEN_MEDIUM_WORDS = sizeof(MEDIUM_WORDS) / sizeof(MEDIUM_WORDS[0]);

const char HARD_WORDS[122][16] = {
    "congratulations", "absolutely", "photosynthesis", "monstrosity",
    "university", "cheeseburger", "accommodate", "suburban", "pizazz",
    "assuming", "stewardess", "xylophone", "overzealous", "withdrawal",
    "wednesday", "vulnerable", "visualization", "versatile", "veterinary",
    "vaccination", "vegetarian", "unanimous", "transmission", "trajectory",
    "temporary", "tournament", "temperature", "surveillance", "psychology",
    "responsibility", "recommendation", "pronunciation", "practitioner",
    "plagiarism", "pilgrimage", "philosophy", "participation",
    "nutritious", "necessarily", "miscellaneous", "marshmallows",
    "mayonnaise", "leprechaun", "limousine", "kindergarten",
    "knowledgeable", "interference", "inflammation", "handkerchief",
    "fluorescent", "extraordinary", "pharmaceutical", "exhilaration",
    "environmental", "disappointment", "choreography", "circumstantial",
    "cauliflower", "cantaloupe", "auditorium", "apostrophe",
    "amphitheater", "advantageous", "acknowledgement", "abbreviation",
    "abundant", "accommodation", "adjustment", "ambidextrous",
    "asymmetrical", "auxiliary", "bachelorette", "bureaucracy",
    "behavioral", "boulevard", "camouflage", "determination",
    "differentiation", "description", "dysfunctional", "impressionable",
    "enthusiastic", "entrepreneur", "eavesdropping", "exaggerated",
    "fascinating", "governmental", "hygienic", "immediately",
    "individuality", "interpretation", "laboratory", "labyrinth",
    "lieutenant", "lightning", "legitimate", "likelihood", "maintenance",
    "masquerade", "medicinal", "mezzanine", "medieval", "mischievous",
    "misunderstood", "pneumonia", "noticeable", "opportunity",
    "overwhelming", "picturesque", "prohibitive",
    "quadruple", "ridiculous", "sacrilegious", "rudimentary", "chandelier",
    "sophomore", "superfluous", "susceptible", "suspicious", "synonymous",
    "tomorrow", "zucchini"
};

const uint8_t LEN_HARD_WORDS = sizeof(HARD_WORDS) / sizeof(HARD_WORDS[0]);