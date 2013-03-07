/*
ID: gnoynai1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
const int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool isleap (int year) {
        if ((year % 4 == 0 && year % 100 != 0 )
                || (year % 400 == 0))
                return true;
        return false;
}

/* compute all days within n years since 1900 */ 
int calculatedays (int n) {
        int alldays = 0;
        for (int i = 1900; i < 1900 + n; i++) {
		if (isleap (i))
			alldays += 366;
		else
			alldays += 365;
        }
        return alldays;
}
/* number of days since 1900.1.1 within y years months and 13 days */
int countdays (int y, int m) {
        int d = calculatedays (y);
        for (int i = 0; i < m; i++) {
                d += month[i];
        }
        if (isleap (1900 + y) && m >= 2)
                d++;
        return d + 13;
}
/* statics n years since 1900 */
int statics13 (int n, vector<int> &days) {
        for (int y = 0; y < n; y++) {
                for (int m = 0; m < 12; m++) {
                        int d = ((countdays (y, m)) % 7 + 1) % 7;
                        days[d]++;
                }
        }
}

int main () {
        int n;
	ofstream fout ("friday.out");
	ifstream fin ("friday.in");
        vector<int> days(7, 0);
        while (fin >> n) {
                statics13 (n, days);
		vector<int>::iterator it = days.begin ();
		fout << *it++;
		for ( ;it != days.end (); it++) { 
			fout << " " << *it;
		}
                fout << endl;
		fill (days.begin (), days.end (), 0);
        }
        return 0;
}

