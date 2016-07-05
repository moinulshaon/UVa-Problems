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

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 100100

int arr[SIZE];
int nxt[SIZE];

int save[SIZE];

int prv[SIZE];

set<pint> s;
set<int> cache;

int main(){



    int c,n,a;
    while ( ~scanf("%d %d %d",&c,&n,&a) ){

    s.clear();
    cache.clear();

    for (int i=0;i<a;++i){
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<n;++i){
        nxt[i]= SIZE-1;
    }

    for (int i=a-1;i>=0;--i){
        save[i] = nxt[ arr[i] ];
        nxt[ arr[i] ] = i;
    }

    int ans = 0;
    for (int i=0;i<a;++i){
        int x= arr[i];

        if ( cache.find( x )== cache.end() ){
            if ( s.size() ==  c ){
                set<pint>::iterator it = s.end();
                it--;
                s.erase( it );
                cache.erase( cache.find( it->second ) );
                //cout<<"erasing "<<" "<<it->second<<endl;
            }
            ans++;
        }else{
            //cout<<"updating "<<" "<<x<<endl;
            s.erase( s.find( MP( prv[x], x ) ) );
        }
        cache.insert( x );
        //cout<<"inserting "<<" "<<x<<endl;
        s.insert( MP( save[i],x ) );
        prv[x] = save[i];
    }
    printf("%d\n",ans);

    }
    return 0;
}
