#include <stdint.h>

const char EASY_WORDS[98][4] = {
    "bat\0", "dog\0", "toy\0", "cat\0", "rat\0", "law\0", "mud\0", "boy\0", "the\0", "she\0",
    "red\0", "pop\0", "lie\0", "bay\0", "hay\0", "can\0", "sad\0", "mad\0", "cap\0", "rap\0",
    "met\0", "fad\0", "hop\0", "top\0", "tap\0", "lap\0", "bag\0", "ham\0", "ray\0",
    "say\0", "tie\0", "bit\0", "hit\0", "hat\0", "bet\0", "bid\0", "lid\0", "pad\0", "and\0",
    "tan\0", "tar\0", "eat\0", "ate\0", "lag\0", "rag\0", "tag\0", "kid\0", "dip\0", "rip\0",
    "lip\0", "pod\0", "rod\0", "nod\0", "his\0", "sis\0", "gem\0", "ant\0", "wad\0", "win\0",
    "nap\0", "way\0", "pay\0", "day\0", "van\0", "mom\0", "dad\0", "dot\0", "rot\0", "tip\0",
    "hen\0", "tin\0", "fee\0", "pee\0", "tee\0", "tea\0", "pea\0", "bee\0", "sea\0", "see\0",
    "men\0", "man\0", "did\0", "sim\0", "pin\0", "fib\0", "yay\0", "may\0", "pot\0", "pan\0",
    "run\0", "ran\0", "ton\0", "put\0", "hut\0", "but\0", "cut\0", "pit\0", "vat\0"
};

const uint8_t LEN_EASY_WORDS = sizeof(EASY_WORDS) / sizeof(EASY_WORDS[0]);

const char MEDIUM_WORDS[75][7] = {
    "lemon\0", "cheese\0", "happy\0", "angry\0", "tomato\0", "carve\0", "tattoo\0",
    "water\0", "walks\0", "visit\0", "liver\0", "flight\0", "height\0", "skirts\0",
    "house\0", "train\0", "spoon\0", "tiger\0", "zebra\0", "doctor\0", "teach\0",
    "study\0", "juice\0", "bottle\0", "never\0", "peace\0", "donor\0", "python\0",
    "coding\0", "uncle\0", "sleeps\0", "table\0", "wonder\0", "growth\0", "forest\0",
    "river\0", "yellow\0", "purple\0", "cycle\0", "pillow\0", "school\0", "queen\0",
    "yogurt\0", "bouncy\0", "flavor\0", "guitar\0", "piano\0", "breeze\0", "sunny\0",
    "window\0", "marvel\0", "gloves\0", "framed\0", "sweet\0", "dirty\0", "clean\0",
    "apple\0", "coffee\0", "button\0", "refer\0", "climb\0", "minute\0", "light\0",
    "shelf\0", "wobble\0", "tired\0", "party\0", "brain\0", "vault\0", "tennis\0",
    "winter\0", "cover\0", "paper\0", "pencil\0", "hello\0"
};

const uint8_t LEN_MEDIUM_WORDS = sizeof(MEDIUM_WORDS) / sizeof(MEDIUM_WORDS[0]);

const char HARD_WORDS[122][16] = {
    "congratulations\0", "absolutely\0", "photosynthesis\0", "monstrosity\0",
    "university\0", "cheeseburger\0", "accommodate\0", "suburban\0", "pizazz\0",
    "assuming\0", "stewardess\0", "xylophone\0", "overzealous\0", "withdrawal\0",
    "wednesday\0", "vulnerable\0", "visualization\0", "versatile\0", "veterinary\0",
    "vaccination\0", "vegetarian\0", "unanimous\0", "transmission\0", "trajectory\0",
    "temporary\0", "tournament\0", "temperature\0", "surveillance\0", "psychology\0",
    "responsibility\0", "recommendation\0", "pronunciation\0", "practitioner\0",
    "plagiarism\0", "pilgrimage\0", "philosophy\0", "participation\0",
    "nutritious\0", "necessarily\0", "miscellaneous\0", "marshmallows\0",
    "mayonnaise\0", "leprechaun\0", "limousine\0", "kindergarten\0",
    "knowledgeable\0", "interference\0", "inflammation\0", "handkerchief\0",
    "fluorescent\0", "extraordinary\0", "pharmaceutical\0", "exhilaration\0",
    "environmental\0", "disappointment\0", "choreography\0", "circumstantial\0",
    "cauliflower\0", "cantaloupe\0", "auditorium\0", "apostrophe\0",
    "amphitheater\0", "advantageous\0", "acknowledgement\0", "abbreviation\0",
    "abundant\0", "accommodation\0", "adjustment\0", "ambidextrous\0",
    "asymmetrical\0", "auxiliary\0", "bachelorette\0", "bureaucracy\0",
    "behavioral\0", "boulevard\0", "camouflage\0", "determination\0",
    "differentiation\0", "description\0", "dysfunctional\0", "impressionable\0",
    "enthusiastic\0", "entrepreneur\0", "eavesdropping\0", "exaggerated\0",
    "fascinating\0", "governmental\0", "hygienic\0", "immediately\0",
    "individuality\0", "interpretation\0", "laboratory\0", "labyrinth\0",
    "lieutenant\0", "lightning\0", "legitimate\0", "likelihood\0", "maintenance\0",
    "masquerade\0", "medicinal\0", "mezzanine\0", "medieval\0", "mischievous\0",
    "misunderstood\0", "pneumonia\0", "noticeable\0", "opportunity\0",
    "overwhelming\0", "picturesque\0", "prohibitive\0",
    "quadruple\0", "ridiculous\0", "sacrilegious\0", "rudimentary\0", "chandelier\0",
    "sophomore\0", "superfluous\0", "susceptible\0", "suspicious\0", "synonymous\0",
    "tomorrow\0", "zucchini\0"
};

const uint8_t LEN_HARD_WORDS = sizeof(HARD_WORDS) / sizeof(HARD_WORDS[0]);