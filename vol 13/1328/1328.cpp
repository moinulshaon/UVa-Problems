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

#define SIZE 1000100

char str[SIZE];

int zz[SIZE];
int len;

void zfunction(){

    int left=0,right = 0;

    zz[0]=len;
    for (int i=1;i<len;++i){
        if ( i>right ){
            left=right = i;
            while ( right<len && str[right] == str[right-left] ){
                right ++;
            }
            right --;
            zz[i] = right -left+1;
        }else{
            int tmp = i-left;
            if ( zz[tmp] < right-i+1 ){
                zz[i]= zz[tmp];
            }
            else{
                left = i;
                while ( right<len && str[right] == str[right-left] ){
                    right ++;
                }
                right --;
                zz[i] = right -left+1;
            }
        }
    }
}

vector<int> pre[SIZE];

int main(){

    for (int i=2;i<SIZE;++i){
        for (int j=i;j<SIZE;j+=i){
            pre[j].PB( i );
        }
    }

    return 0;

    for (int kk=1; scanf("%d",&len)==1 ;++kk ){
        scanf("%s",str);

        zfunction();



    }


    return 0;
}
