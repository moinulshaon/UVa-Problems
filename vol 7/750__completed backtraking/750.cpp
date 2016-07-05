

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
#include <bitset>
#include <utility>
#include <set>
#define pi acos(-1.0)
#define N 1000000
using namespace std;

char sol [100] [10];
char temp [10];
bool row [10];
bool rightDiag [20];
bool leftDiag [20];
int length;

void generateSolution (int n)
{
    if ( n == 8 ) {
        temp [8] = 0;
        strcpy (sol [length], temp);
        //printf("%s\n",temp);
        //getchar();
        length++;
        return;
    }

    for ( int i = 0; i < 8; i++ ) { // row
        if ( row [i] && rightDiag [n - i + 8] && leftDiag [n + i] ) {
            row [i] = rightDiag [n - i + 8] = leftDiag [n + i] = false;
            temp [n] = i + '1';
            generateSolution (n + 1);
            row [i] = rightDiag [n - i + 8] = leftDiag [n + i] = true;
        }
    }
}

int main ()
{
    memset (row, true, sizeof (row));
    memset (rightDiag, true, sizeof (rightDiag));
    memset (leftDiag, true, sizeof (leftDiag));
    length = 0;

    generateSolution (0);

    //printf("%d\n",length);

    int testCase;
    scanf ("%d", &testCase);
    bool blank = false;

    while ( testCase-- ) {
        int r, c;
        scanf ("%d %d", &r, &c);
        int cases = 0;

        if ( blank ) cout << endl;
        blank = true;

        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8\n" << endl;

        for ( int i = 0; i < length; i++ ) {
            if ( sol [i] [c - 1] == r + '0' ) {
                printf ("%2d      ", ++cases);
                printf ("%c", sol [i] [0]);
                for ( int j = 1; j < 8; j++ )
                    printf (" %c", sol [i] [j]);
                printf ("\n");
            }
        }
    }

    return 0;
}

// @END_OF_SOURCE_CODE
