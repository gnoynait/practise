#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define M 200001
int array[M];
int len;
inline void swap (int a, int b) {
	int tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}
int intcmp (const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}
int partion (int left, int right) {
	int l = left, r = right;
	int key = array[left];
	int rd = rand () % (right - left + 1) + left;
	swap (rd, left);
	while (l < r) {
		while (array[l + 1] <= key)
			l++;
		while (array[r] > key)
			r--;
		if (l < r)
			swap (l + 1, r);
	}
	swap (l, left);
	return l;
}
void nth_element (int n) {
	int s = -1;
	int left = 0, right = len - 1;
	srand (time (NULL));
	while (s != n) {
		s = partion (left, right);
		if (s > n) {
			right = s - 1;
		} else if (s == n) {
			return;
		} else {
			left = s + 1;
		}
	}
}

int main () {
	int k;
	int i;
	int left, right;
	while (scanf ("%d%d", &len, &k) != EOF) {
		for (i = 0; i < len; i++) {
			scanf ("%d", &array[i]);
		}
		nth_element (k - 1);
		qsort (array, k, sizeof(int), intcmp);
		printf ("%d", array[0]);
		for (i = 1; i < k; i++) {
			printf (" %d", array[i]);
		}
		printf ("\n");
	}
	return 0;
}

