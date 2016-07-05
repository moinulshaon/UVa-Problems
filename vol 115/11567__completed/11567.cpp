// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;

LL choice (LL s)
{
	LL s1 = s + 1;
	LL s2 = s - 1;
	int ret = 0;

	if ( s == 3 ) return 2;
	if ( s2 == 0 ) return s2;

	while ( s1 % 2 == 0 && s1 != 0 ) {
		s1 /= 2;
		ret++;
	}

	while ( s2 % 2 == 0 && s2 != 0 ) {
		s2 /= 2;
		ret--;
	}

	if ( ret > 0 ) return s + 1;
	return s - 1;
}

int main ()
{
    LL s;

    while ( cin >> s ) {
		int cnt = 0;

		while ( s != 0 ) {
			if ( s % 2 == 0 ) s /= 2;
			else s = choice (s);
			cnt++;
		}

		printf ("%d\n", cnt);
    }

	return 0;
}

// @END_OF_SOURCE_CODE
