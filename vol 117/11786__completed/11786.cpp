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

#define SIZE 20100

const int mid=10050;

char ins[SIZE];
int on[SIZE];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        scanf("%s",ins);

        int now = mid;
        NEG(on);

        int ans = 0;

        for (int i=0;ins[i];++i){
            if ( ins[i] == '\\' ){
                on[now] = i;
                now--;
            }else if ( ins[i] == '/' ){
                now++;
                if ( on[now] != -1 ){
                    ans+= i-on[now];

                    //printf("%d\n",i-on[now]);
                    on[now] = -1;
                }

            }
            //cout<<now<<endl;
        }
        printf("%d\n",ans);

    }

    return 0;
}
