#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Position;
#define NotFound -1

void BuildMatch(char* pattern, int* match) {
	Position i, j;
	int m = strlen(pattern);
	match[0] = -1;
	for (j = 1; j < m; j++) {
		i = match[j - 1];

		while (pattern[i + 1] != pattern[j] && i >= 0) {
			i = match[i];
		}

		if (pattern[i + 1] == pattern[j]) {
			match[j] = i + 1;
		}
		else {
			match[j] = -1;
		}

	}
}
Position KMP(char* string, char* pattern) {
	int n = strlen(string);
	int m = strlen(pattern);
	if (n < m)
		return NotFound;

	int s = 0, p = 0,//分别指向两个串
		* match;
	match = (int*)malloc(sizeof(int) * m);
	BuildMatch(pattern, match);
	while (s < n && p < m) {
		if (string[s] == pattern[p]) {
			s++;
			p++;
		}
		else if (p > 0) {
			p = match[p - 1] + 1;
		}
		else {
			s++;
		}
	}
	return (p == m) ? (s - m) : NotFound;
}


int main(void) {
	char string[] = "This is a simple example.";
	char pattern[] = "simple";
	Position p = KMP(string, pattern);

	if (p == NotFound) {
		printf("NotFound.");
	}
	else {
		printf("%s\n", string + p);
	}
	return 0;
}