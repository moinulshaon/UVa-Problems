// http://uva.onlinejudge.org/external/1/112.html

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
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;

string input;
int totalVal;
bool positive;

int make_Tree ( int start, int sum )
{
    if ( input [start + 1] == ')' ) return -1;

    char number [50];
    int index = 0;
    start++; // eliminate first paren

    while ( input [start] != '(' ) {
        number [index] = input [start];
        index++;
        start++;
    }

    number [index] = 0;
    int num = atoi (number);

    int start1, start2; // starting of two child
    int left, right = 0; // count left & right parenthesis

    start1 = start++;
    left = 1;

    while ( left != right ) {
        if ( input [start] == '(' ) left++;
        else if ( input [start] == ')' ) right++;
        start++;
    }

    start2 = start++;
    right = 0;
    left = 1;

    while ( left != right ) {
        if ( input [start] == '(' ) left++;
        else if ( input [start] == ')' ) right++;
        start++;
    }

    int x = make_Tree( start1, sum + num);
    int y = make_Tree( start2, sum + num);

    if ( x == -1 && y == -1 && sum + num == totalVal ) positive = true;

    return 0;
}


int main ()
{
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);

    while ( scanf ("%d", &totalVal) != EOF ) {
        positive = false;
        char ch;

        while ( scanf ("%c", &ch) && ch != '(' ); // eliminate spaces

        int leftParenthesis = 1;
        int rightParenthesis = 0;

        // building actual input, without spaces, in a string : input
        input = "(";

        while ( leftParenthesis != rightParenthesis ) {
            cin >> ch;
            if ( ch == '(' ) leftParenthesis++;
            else if ( ch == ')' ) rightParenthesis++;

            if ( ch != ' ' ) input += ch;
        }

        make_Tree (0, 0);

        if ( positive ) printf ("yes\n");
        else printf ("no\n");

    }

	return 0;
}
