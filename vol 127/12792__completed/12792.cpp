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

int main(){

    int n;
    while ( scanf("%d",&n)==1 ){

        int sum = 1;
        int cnt = 0;
        while ( true ){
            if ( sum>n/2 ){
                sum -= n/2;
                sum = 2*sum-1;
            }else{
                sum += sum;
            }
            cnt++;
            if ( sum == 1 ){
                break;
            }
            //cout<<cnt<<" "<<sum<<endl;
        }
        printf("%d\n",cnt);
    }


    return 0;
}
