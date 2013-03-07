#include <stdio.h>
#define M 10001
char buffer[M];
int count[26];
int seq[26];

int main () {
	int i;
	int min;
	while (scanf ("%s", buffer) != EOF) {
		for (i = 0; i < 26; i++) {
			count[i] = 0;
			seq[i] = M;
		}
			
		for (i = 0; buffer[i] != '\0'; i++) {
			count[buffer[i] - 'A']++;
			if (count[buffer[i] - 'A'] == 1) {
				seq[buffer[i] - 'A'] = i;
			}
		}
		min = M;
		for (i = 0; i < 26; i++) {
			if (count[i] == 1 && seq[i] < min)
				min = seq[i];
		}
		if (min == M)
			printf ("-1\n");
		else
			printf ("%d\n", min);
		
	}
	return 0;
}
			
			
