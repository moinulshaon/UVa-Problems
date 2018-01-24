#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}


LL makeCeil(LL num, LL den) {
    return ( num/den ) + ( num%den != 0 );
}

int main() {

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk) {
        LL e,p,k,r;
        e=fastIn<LL>();
        p=fastIn<LL>();
        k=fastIn<LL>();
        r=fastIn<LL>();

        LL ans = 0;
        if (e <= p*k) {
            ans = makeCeil(e,p);
        } else {
            if (p*k <= r) {
                ans = -1;
            } else {
                LL rounds = makeCeil(e-r, p*k -r) - 1;
                LL leftOver = e + rounds * r - rounds * p * k;

                ans = rounds * k + makeCeil( leftOver, p );
            }
        }

        printf("Case %d: %lld\n", kk, ans);
    }
    return 0;
}
