#include<stdio.h>
#include<string.h>
#define M 81
char buffer[M];
int len;
void print () {
	int width = (len + 2) / 3;
	int hight;
	int i, j;
	if ((len + 2) % 3 != 0)
		width++;
	if ((len + 2 - width) % 2 != 0)
		width++;
	hight = (len - width) / 2;
	for (i = 0; i < hight; i++) {
		printf ("%c", buffer[i]);
		for (j = 0; j < width - 2; j++)
			printf("%c", ' ');
		printf ("%c\n", buffer[len - 1 - i]);
	}
	for (j = 0; j < width; j++)
		printf ("%c", buffer[i + j]);
	printf ("\n");
}

int main () {
	while (scanf ("%s", buffer) != EOF) {
		len = strlen (buffer);
		print ();
	}
	return 0;
}
