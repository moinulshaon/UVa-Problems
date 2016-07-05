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

#define SIZE 210

char line[SIZE];

int func( char c ){
    if ( isalpha(c) ){
        return c-'A';
    }else {
        return c-'0'+26;
    }
}

int cnt[100];

bool cmp( int a,int b ){
    return a>b;
}

vector<int> ss;

int shaon[]={5,4,3,2,1};

int main(){

    for (int i=2;i<=7;++i){
        for (int j=1;j<i;++j){
            ss.PB( i );
            //cout<<i<<endl;
        }
    }
    for (int i=8;i<=12;++i){
        for (int j=0;j<shaon[i-8];++j){
            ss.PB( i );
            //cout<<i<<endl;
        }
    }

    //cout<<ss.size()<<endl;

    FRO

    int kase;
    scanf("%d",&kase);
    gets(line);
    while ( kase-- ){
        gets( line );

        //puts(line);

        CLR(cnt);

        for (int i=0;line[i];++i){
            if ( line[i] != ' ' ){
                cnt[ func( line[i] )  ] ++ ;
            }
        }

        sort( cnt,cnt+100,cmp );


        int ans = 0;
        for (int i=0;cnt[i] > 0;++i){
            ans+= cnt[i] * ss[ i ];
        }

        printf("%d\n",ans);
    }

    return 0;
}
