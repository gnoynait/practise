#include<stdio.h>
#define M 101
int age[M];
int main () {
	int n;
	int a;
	int i, j;
	while (scanf ("%d", &n) != EOF) {
		for (i = 0; i < M; i++)
			age[i] = 0;
		for (i = 0; i < n; i++) {
			scanf ("%d", &a);
			age[a]++;
		}
		for (i = 0; i < M; i++) {
			for (j = 0; j < age[i]; j++) {
				printf ("%d ", i);
			}
		}
		printf ("\n");
	}
	return 0;
}
