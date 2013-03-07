#include<stdio.h>
#include<stdlib.h>
#define M 100000

int array[M];
int len;
long long merge (int left, int right) {
	int *tmp;
	int i, j, k;
	long long count = 0;
	int mid = (right + left) / 2;
	
	if (left >= right)
		return 0;
	count += merge (left, mid);
	count += merge (mid + 1, right);
	tmp = (int *)malloc (sizeof (int) * (right - left + 1));
	i = 0;
	j = left; 
	k = mid + 1;
	while (j <= mid && k <= right) {
		if (array[j] <= array[k])
			tmp[i++] = array[j++];
		else {
			count += (mid - j + 1);
			tmp[i++] = array[k++];
		}
	}
	while (j <= mid) {
		tmp[i++] = array[j++];
	}
	while (k <= right) {
		tmp[i++] = array[k++];
	}
	for (i = 0; i < right - left + 1; i++)
		array[left + i] = tmp[i];
	free (tmp);
	return count;
}

int main () {
	int i;
	while (scanf ("%d", &len) != EOF) {
		for (i = 0; i < len; i++)
			scanf ("%d", &array[i]);
		printf ("%ld\n", merge (0, len - 1));
	}
	return 0;
}
