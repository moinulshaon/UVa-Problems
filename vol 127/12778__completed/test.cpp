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

#define SIZE 5100

int arr[SIZE];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        /*
        int left = 0;
        int cnt[SIZE]={0};
        for (int i=0;i<n;++i){
            for (int j=i;j<n;++j){
                int tmp = 0;
                for (int k=i;k<=j;++k){
                    tmp += arr[k];
                    //if ( k==0 )cout<<i<<" "<<j<<endl;
                    cnt[k]++;
                }
                left+= tmp;
            }
        }
        */
/*
        for (int i=0;i<n;++i){
            cout<<cnt[i]<<" ";
        }cout<<endl;
*/
        //cout<<left<<endl;

        int right=0;
        for (int i=0;i<n;++i){
            for (int j=i;j<n;++j){
                int tmp = INT_MAX;
                for (int k=i;k<=j;++k){
                    tmp= min( tmp,arr[k] );
                }
                int sum = 0;
                for (int k=i;k<=j;++k){
                    sum += abs( arr[k]-tmp );
                }
                right+= sum;
            }
        }
        cout<<right<<endl;
    }


    return 0;
}
