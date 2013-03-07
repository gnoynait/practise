#include<iostream>
#include<vector>
const int M = 1500;
using namespace std;

int main () {
	int i2 = 0, i3 = 0, i5 = 0;
	vector<int> numbers;
	numbers.push_back (1);
	for (int i = 1; i < M; i++) {
		int n2 = numbers[i2] * 2, n3 = numbers[i3] * 3, n5 = numbers[i5] * 5;
		int min = 0;
		if (n2 <= n3 && n2 <= n5) {
			min = n2;
			i2++;
		}
		if (n3 <= n2 && n3 <= n5) {
			min = n3;
			i3++;
		}
		if (n5 <= n2 && n5 <= n3) {
			min = n5;
			i5++;
		}
		numbers.push_back (min);
	}
	int n;
	while (cin >> n) {
		cout << numbers[n - 1] << endl;
	}
	return 0;
}

