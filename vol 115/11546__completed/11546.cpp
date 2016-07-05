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

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 50100
#define LIM 100000

struct tt{
    int diff[35];
}arr[SIZE];

mint hash;
int lane;

unsigned int fnv_hash ( void *key, int len ){
    unsigned char *p = static_cast<unsigned char*> (key);
    unsigned int h = 2166136261U;

    for (int i = 0; i < len; i++ )
        h = ( h * 16777619 ) ^ p[i];
    return h;
}


unsigned djb_hash ( void *key, int len )
{
    unsigned char *p = static_cast<unsigned char*> (key);
    unsigned h = 0;
    int i;

    for ( i = 0; i < len; i++ )
        h = 33 * h + p[i];
    return h;
}

unsigned oat_hash ( void *key, int len ){
    unsigned char *p = static_cast<unsigned char*> (key);
    unsigned h = 0;
    int i;

    for ( i = 0; i < len; i++ ) {
        h += p[i];
        h += ( h << 10 );
        h ^= ( h >> 6 );
    }

    h += ( h << 3 );
    h ^= ( h >> 11 );
    h += ( h << 15 );

    return h;
}

int main(){

    int len;
    for (int kk=1;scanf("%d %d",&len,&lane)==2 && (len+lane);++kk){


        CLR( arr );

        for (int i=0;i<lane;++i){
            int u,tmp;
            scanf("%d",&tmp);

            while ( tmp-- ){
                scanf("%d",&u);
                arr[u+1].diff[i] ++;
            }
        }

        for (int i=1;i<=len;++i){
            for (int j=0;j<lane;++j){
                arr[i].diff[j] += arr[i-1].diff[j];
            }
        }

        for (int i=0;i<=len;++i){
            int mn=(1<<29);
            for (int j=0;j<lane;++j){
                if ( arr[i].diff[j]<mn ){
                    mn=arr[i].diff[j];
                }
            }
            for (int j=0;j<lane;++j){
                arr[i].diff[j] -= mn;
            }
        }

        //NEG(hash);
        hash.clear();
        int ans=0;
        for (int i=0;i<=len;++i){
            int vv=djb_hash( arr[i].diff,sizeof(tt) ) ^ fnv_hash(  arr[i].diff,sizeof(tt) ) ;
            //printf("%d %d\n",i,vv);
            if ( hash.find(vv)==hash.end() ){
                hash[vv]= i;
            }else{
                ans=max( ans,i-hash[vv] );
                //printf("%d %d\n",i,i-hash[vv]+1);
            }
        }

        printf("Case #%d: %d meter(s)\n",kk,ans);
    }


    return 0;
}
