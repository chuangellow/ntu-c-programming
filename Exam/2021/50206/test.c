#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LEN 100001
#define TABLE_SIZE 26*26*26

typedef struct {
    char pattern[4];
    int count;
} Pattern;

Pattern patterns[TABLE_SIZE];

int hash_function(char three_pattern[4]) {
	int idx = 0;
	int multiplier = 1;
	for (int i = 2; i >= 0; i--) {
		idx += (three_pattern[i] - 'a') * multiplier;
		multiplier *= 26;
	}
	return idx;
}

int compare(const void *a, const void *b) {
    Pattern *p1 = (Pattern *)a;
    Pattern *p2 = (Pattern *)b;
    if(p1->count != p2->count)
        return p2->count - p1->count;
    return strcmp(p1->pattern, p2->pattern);
}

int main(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        patterns[i].count = 0;
        strcpy(patterns[i].pattern, "");
    }
    char input[STR_LEN];
    fgets(input, STR_LEN, stdin);
    const char delim[3] = " \n";
    char *token;
    token = strtok(input, delim);
    while (token != NULL) {
        int tok_len = strlen(token);
        if (tok_len >= 3) {
            for (int i = 0; i <= tok_len - 3; i++) {
                char three_pattern[4] = {'\0'};
                strncpy(three_pattern, token+i, 3);
                int idx = hash_function(three_pattern);
                if (patterns[idx].count == 0) {
                    strcpy(patterns[idx].pattern, three_pattern);
                }
                patterns[idx].count++;
            }
        }
        token = strtok(NULL, delim);
    }
    qsort(patterns, TABLE_SIZE, sizeof(Pattern), compare);
    for (int i = 0; i < 3; i++) {
        printf("%s\n", patterns[i].pattern);
    }
    return 0;
}
