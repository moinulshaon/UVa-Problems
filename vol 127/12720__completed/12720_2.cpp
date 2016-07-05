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

char str[SIZE];
char ans[SIZE];

LL mod = 1000000007;

int main(){


    FRO

    int kase;
    scanf("%d",&kase);

    for(int kk=1; kase-- ;++kk ){
        scanf("%s",str);

        int len = strlen(str);

        int now=0;

        int left,right;

        if ( len%2==1 ){
            left = len/2;
            right=len/2;
        }else{
            left = len/2-1;
            right=len/2;
        }



        while ( now != len ){

            if ( left == right ){
                ans[now++] = str[left--];
                right++;
            }else{
                if ( left>=0 && str[left]>str[right] ){
                    ans[now++]=str[left--];
                    if ( right<len ){
                        ans[now++]=str[right++];
                    }
                }else{
                    ans[now++]=str[right++];
                    if ( left>=0 ){
                        ans[now++]=str[left--];
                    }
                }
            }
        }

        ans[now++]='\0';
        //printf("%s\n",ans);

        LL val = 0;
        for (int i=0;ans[i];++i){
            val = ( val*2 + ( ans[i]-'0') )%mod;
        }

        printf("Case #%d: %lld\n",kk,val);

    }



    return 0;
}
