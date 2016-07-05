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

#define SIZE 10000

void addBin(char *toadd,int val){
    char tt[5];
    for (int i=0;i<4;++i){
        tt[i] = val%2;
        val/=2;
    }

    for (int i=0;i<4;++i){
        toadd[i]=tt[3-i]+'0';
    }
}

char ini[SIZE],fin[SIZE];
char tmp1[SIZE],tmp2[SIZE];

int main(){

    FRO

    for (int kk=1; scanf("%s %s",ini,fin)==2 ;++kk ){
        if ( strcmp(ini,"0") == 0 && strcmp(fin,"0") == 0 )break;
        if ( kk != 1 )break;

        int ccc=0;
        for (int i=0;ini[i];++i){
            addBin(&tmp1[ccc],ini[i]-'0');
            ccc+= 4;
        }
        tmp1[ccc++]='\0';

        int sss=0;
        for (int i=0;fin[i];++i){
            addBin(&tmp2[sss],fin[i]-'0');
            sss+= 4;
        }
        tmp2[sss++]='\0';

        printf("%s %s\n",tmp1,tmp2);

    }


    return 0;
}
