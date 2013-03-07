#include<stdio.h>
void sort2 (int *a, int *b) {
	int tmp;
	if (*a > *b) {
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}
int count1 (int n) {
	int count = 0;
	int base = 1;
	int tn = n, r;
	if (n <= 0)
		return 0;
	while (tn) {
		r = tn % 10;
		if (r == 1)
			count += n / (10 * base) * base + n % base + 1;
		if (r > 1)
			count += (n / (10 * base) + 1) * base;
		if (r == 0)
			count += (n / (10 * base)) * base;
		base *= 10;
		tn = tn / 10;
	}
	return count;
}

int main () {
	int a, b;
	while (scanf ("%d%d", &a, &b) != EOF) {
		sort2 (&a, &b);
		printf ("%d\n", count1 (b) - count1 (a - 1));
	}
	return 0;
}
