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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

char arr[12];

int main(){

    int kase;
    scanf("%d",&kase);
    while( kase-- ){
        scanf("%s",arr);

        int len=strlen(arr);
        sort( arr,arr+len );
        do{
            printf("%s\n",arr);
        }while( next_permutation(arr,arr+len) );
        printf("\n");
    }

    return 0;
}
