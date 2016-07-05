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
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define LL long long

using namespace std;



double power (int b, int p)

{

    double ret = 1;



    for ( int i = 1; i <= p; i++ )

        ret *= b;



    return ret;

}



int main ()
{
    int stones;
    int cases = 0;

    while ( scanf ("%d", &stones) && stones ) {
        int x [200 + 10];
        int y [200 + 10];

        for ( int i = 0; i < stones; i++ ) scanf ("%d %d", &x [i], &y [i]);

        double d [200 + 10] [200 + 10];

        for ( int i = 0; i < stones; i++ ) {
            for ( int j = i + 1; j < stones; j++ )
                d [i] [j] = d [j] [i] = sqrt (power (x [i] - x [j], 2) + power (y [i] - y [j], 2));
        }



        for ( int k = 0; k < stones; k++ ) {
            for ( int i = 0; i < stones; i++ ) {
                for ( int j = 0; j < stones; j++ )
                    d [i] [j] = min (d [i] [j], max (d [i] [k], d [k] [j]));
            }
        }

        printf ("Scenario #%d\n", ++cases);
        printf ("Frog Distance = %.3lf\n\n", d [0] [1]);

    }



    return 0;

}
