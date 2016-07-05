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

#define MAX_N 110010

char str [MAX_N];
LL N, m, SA [MAX_N], LCP [MAX_N];
LL x [MAX_N], y [MAX_N], w [MAX_N], c [MAX_N];

inline bool cmp (const LL a, const LL b, const LL l) { return (y [a] == y [b] && y [a + l] == y [b + l]); }

void Sort () {
    for (LL i = 0; i < m; ++i) w [i] = 0;
    for (LL i = 0; i < N; ++i) ++w [x [y [i]]];
    for (LL i = 0; i < m - 1; ++i) w [i + 1] += w [i];
    for (LL i = N - 1; i >= 0; --i) SA [--w [x [y [i]]]] = y [i];
}

void DA () {
    for (LL i = 0; i < N; ++i) x [i] = str [i], y[i] = i;
    Sort ();
    for (LL i, j = 1, p = 1; p < N; j <<= 1, m = p) {
        for (p = 0, i = N - j; i < N; i++) y [p++] = i;
        for (LL k = 0; k < N; ++k) if (SA [k] >= j) y [p++] = SA [k] - j;
        Sort ();
        for (swap (x, y), p = 1, x [SA [0]] = 0, i = 1; i < N; ++i) x [SA [i]] = cmp (SA [i - 1], SA [i], j) ? p - 1 : p++;
    }
}

void kasaiLCP () {
    for (LL i = 0; i < N; i++) c [SA [i]] = i;
    for (LL i = 0, j, k = 0; i < N; LCP [c [i++]] = k)
        if (c [i] > 0) for (k ? k-- : 0, j = SA [c [i] - 1]; str [i + k] == str [j + k]; k++);
        else k = 0;
}

LL suffixArray () {
    m = 256;
    N = strlen (str)+1;
    DA ();
    kasaiLCP ();

    LL rr=0;
    for(LL i = 1; i < N; i++){
        //cout << LCP[i] << ' '<<B[i]<<endl;
        rr+=LL(SA[i])-LCP[i]+1;
    }
    //printf("%d\n",rr);
    return rr;

}

char another[MAX_N];

int main(){

    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%s",str);

        LL ans=suffixArray();
        strcpy(another,str);
        strcat(str,another);
        LL me = suffixArray()-ans;

        LL pp;
        scanf("%lld",&pp);

        ans+=me*(pp-1);

        printf("Case %d: %lld\n",kk,ans);

    }
    return 0;

}
