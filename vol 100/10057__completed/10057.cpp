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

#define SIZE 68536

int cnt[SIZE];

int main() {

    FRO

    int n;
    while ( scanf("%d",&n)==1 ){

        int tmp;

        for (int i=0;i<SIZE;++i){
            cnt[i] = 0;
        }

        for (int i=0;i<n;++i){
            scanf("%d",&tmp);
            cnt[ tmp ]++;
        }

        for (int i=1;i<SIZE;++i){
            cnt[i] += cnt[i-1];
        }

        if ( n&1 ){
            int low = 0,high = SIZE-1;
            int ans = -1;
            while ( low<=high ){
                int mid = (low+high)/2;

                if ( cnt[mid]< n/2+1 ){
                    low = mid+1;
                }else{
                    ans = mid;
                    high = mid-1;
                }
            }
            printf("%d %d %d\n",ans,cnt[ans]-( (ans-1>=0)?cnt[ans-1] :0 ),1);
        }else{
            int low = 0,high = SIZE-1;
            int ans = -1;
            while ( low<=high ){
                int mid = (low+high)/2;

                if ( cnt[mid]< n/2 ){
                    low = mid+1;
                }else{
                    ans = mid;
                    high = mid-1;
                }
            }

            int nxt = ans;
            if ( cnt[ans] < n/2+1 ){
                for (int i=ans+1 ;i<SIZE;++i){
                    if ( cnt[i]-cnt[i-1]>0 ){
                        nxt = i;
                        break;
                    }
                }
            }

            printf("%d %d %d\n",ans,cnt[nxt]-( (ans-1>=0)?cnt[ans-1] :0 ) , nxt-ans+1 );

        }

    }


    return 0;
}
