#include<stdio.h>
#define M 10001
int array[M];
int len;
void minmax () {
	int min, max;
	int i;
	if (len == 1) {
		printf ("%d %d\n", array[0], array[1]);
		return;
	}
	if (array[0] <= array[1]) {
		min = array[0];
		max = array[1];
	}
	
	
int main () {
	int i;
	while (scanf ("%d", &len) != EOF) {
		for (i = 0; i < len; i++) {
			scanf ("%d", &array[i]);
		minmax ();
	}
	return 0;
}
