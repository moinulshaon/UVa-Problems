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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

char arr[1050];

int len ;

bool func( int x ){
    if ( x==1 )return true;
    else if ( x== 2 )return ( (arr[len-1]-'0')%2 )== 0;
    else if ( x== 5 ){
        if ( arr[len-1]=='0' || arr[len-1] == '5' ){
            return true;
        }else {
            return false;
        }
    }

    int m =0;
    for (int i=0;arr[i];++i){
        m=(  10*m+ ( arr[i]-'0' ) )%x;
    }
    return m==0;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        scanf("%s",arr);
        len = strlen( arr );

        int n;
        scanf("%d",&n);

        bool ok=true;
        while ( n-- ){
            int x;
            scanf("%d",&x);
            if ( ok ){
                ok= func( x );
            }
        }

        printf("%s - ",arr);
        if ( ok ){
            printf("Wonderful.\n");
        }else{
            printf("Simple.\n");
        }

    }


    return 0;
}
