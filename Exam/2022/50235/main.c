#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define STR_LEN 20
#define TABLESIZE 1000
#define CAP 3

typedef struct s_info {
	char s[STR_LEN];
	int count;
} STR_INFO;

int hash_function(char s[STR_LEN]); 
void hash_table_init(STR_INFO hash_table[TABLESIZE][CAP]);
int hash_table_query(STR_INFO hash_table[TABLESIZE][CAP], char s[STR_LEN]);
void hash_table_insert(STR_INFO hash_table[TABLESIZE][CAP], char s[STR_LEN]);
bool check_ava(char s[STR_LEN]);

int main(void) {
	char temp[STR_LEN] = {'\0'};
	STR_INFO hash_table[TABLESIZE][CAP];
	hash_table_init(hash_table);
	while (scanf("%s", temp) != EOF) {
		if (check_ava(temp)) {
			int occurance = hash_table_query(hash_table, temp);
			if (occurance != -1){
				printf("%s %d\n", temp, occurance);
			}
			else {
				hash_table_insert(hash_table, temp);
				printf("%s %d\n", temp, 1);
			}
		}
	}
	return 0;
}

int hash_function(char s[STR_LEN]) {
	int idx = -1;
	int len = strlen(s);
	int count = 0;
	for (int i = 0; i < len; i++) {
		count += s[i];
	}
	return count % 1000;
}

bool check_ava(char s[STR_LEN]) {
	bool flag = false;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			if (!(isalpha(s[i])) && (s[i] != '_')) {
				return false;
			}
		}
		else {
			if (!(isalpha(s[i])) && !(isdigit(s[i])) && (s[i] != '_')) {
				return false;
			}
		}
	}
	return true;
}

void hash_table_init(STR_INFO hash_table[TABLESIZE][CAP]) {
	for (int i = 0; i < TABLESIZE; i++) {
		for (int j = 0; j < CAP; j++) {
			hash_table[i][j].count = 0;
			strcpy(hash_table[i][j].s, "\0");
		}
	}
	return;
}

int hash_table_query(STR_INFO hash_table[TABLESIZE][CAP], char s[STR_LEN]) {
	int idx = hash_function(s);
	for (int i = 0; i < CAP; i++) {
		if (strcmp(hash_table[idx][i].s, s) == 0) {
			hash_table[idx][i].count++;
			return hash_table[idx][i].count;
		}
	}
	return -1;
}

void hash_table_insert(STR_INFO hash_table[TABLESIZE][CAP], char s[STR_LEN]) {
	int idx = hash_function(s);
	for (int i = 0; i < CAP; i++) {
		if (hash_table[idx][i].count == 0) {
			strcpy(hash_table[idx][i].s, s);
			hash_table[idx][i].count++;
			return;
		}
	}
	return;
}
