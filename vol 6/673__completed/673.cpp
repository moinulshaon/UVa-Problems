#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

typedef long long LL;

#define SIZE 150

char arr[SIZE];

int main(){

    int kase;
    scanf("%d",&kase);
    gets(arr);

    while ( kase-- ){
        gets(arr);
        stack<char> stk;

        bool pos = true;
        for (int i=0;arr[i] != '\0' && pos ;++i){
            if ( arr[i] == '(' || arr[i] == '['  ){
                stk.push( arr[i] );
            }else if ( arr[i] == ')' ){
                if ( stk.size()>0 && stk.top() == '(' ){
                    stk.pop();
                }else{
                    pos=false;
                }
            }else if ( arr[i] == ']' ){
                if ( stk.size()>0 &&  stk.top() == '[' ){
                    stk.pop();
                }else{
                    pos=false;
                }
            }
        }
        if ( pos && stk.size() == 0 )printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
