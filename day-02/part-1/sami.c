#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ALPHABET 26

int alphabet[ALPHABET] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

void count(char* s, int* two, int* three) {
    int two_seen, three_seen;
    two_seen = three_seen = 0;

    for (; *s != '\0' && *s != EOF; s++)
        alphabet[*s - 'a']++;

    for (int i = 0; i < ALPHABET; ++i) {
        two_seen = two_seen ? two_seen : (alphabet[i] == 2);
        three_seen = three_seen ? three_seen : (alphabet[i] == 3);
        alphabet[i] = 0;
    }

    *two += two_seen;
    *three += three_seen;
}

int run(char* s) {
    char* token;
    int two, three;
    two = three = 0;

    while ((token = strsep(&s, "\n")) != NULL) {
        count(token, &two, &three);
    }

    return two * three;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Missing one argument\n");
        exit(1);
    }
    clock_t start = clock();
    int answer = run(argv[1]);

    printf("_duration:%f\n%d\n",
        (float)(clock() - start) * 1000.0 / CLOCKS_PER_SEC, answer);
    return 0;
}
