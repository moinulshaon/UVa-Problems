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

#define SIZE 300100
#define SQRT 600

LL arr[SIZE];
int bucketNo[SIZE];

vector<LL> bucket[SQRT];
int bucketSize;
int bucketCnt;

int n;
LL u;

int main(){

    FRO

    int qq;
    while ( scanf("%d %d %lld",&n,&qq,&u)==3 ){

        bucketCnt=1;
        bucketSize = int( sqrt(n) );

        for (int i=1;i<SQRT;++i){
            bucket[i].clear();
        }

        int tmp = 0;
        for (int i=1;i<=n;++i){
            scanf("%lld",&arr[i]);

            tmp++;
            if ( tmp == bucketSize ){
                tmp=0;
                bucketCnt++;
            }

            bucketNo[i] = bucketCnt;
            bucket[ bucketCnt ].PB( arr[i] );

        }


        for (int i=1;i<=bucketCnt;++i){
            sort( bucket[i].begin(),bucket[i].end()  );
        }

        int le,ri,ind;
        LL v;


        while ( qq-- ){
            scanf("%d %d %lld %d",&le,&ri,&v,&ind);

            int cnt = 0 ;

            if ( bucketNo[le] == bucketNo[ri] ){
                for (int i=le; i<=ri ;++i){
                    if ( arr[i]< v ){
                        ++cnt;
                    }
                }

            }else{
                for (int i=le; bucketNo[i] == bucketNo[le] ;++i){
                    if ( arr[i]< v ){
                        ++cnt;
                    }
                }
                int now = bucketNo[ le ]+1;
                while ( now != bucketNo[ri] ){

                    int mid,low = 0,high= bucket[now].size()-1;

                    while ( low<=high ){
                        mid= (low+high)/2;
                        if ( bucket[now][mid] < v ){
                            low = mid+1;
                        }else{
                            high= mid-1;
                        }
                    }
                    cnt+= low;
                    now++;
                }
                for (int i=ri; bucketNo[i] == bucketNo[ri] ;--i){
                    if ( arr[i]< v ){
                        ++cnt;
                    }
                }

            }

            //printf("%d\n",cnt);

            arr[ ind ] = u* cnt /( ri-le+1 );

            bucket[ bucketNo[ind] ].clear();
            for (int i=ind; bucketNo[i] == bucketNo[ind] ; ++i ){
                bucket[ bucketNo[i] ].PB( arr[i] );
            }
            for (int i=ind-1; bucketNo[i] == bucketNo[ind] ; --i ){
                bucket[ bucketNo[i] ].PB( arr[i] );
            }
            sort( bucket[ bucketNo[ind] ].begin(),bucket[ bucketNo[ind] ].end() );

        }

        for (int i=1;i<=n;++i){
            printf("%lld\n",arr[i]);
        }

    }


    return 0;
}
