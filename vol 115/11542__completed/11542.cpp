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

bool prime[510];
int num[510];
vector<int> p;


int mat[101][101],save[101][101];
int val[101];

bool used[101];
int gauss(int eqn,int var){

    for (int i=0;i<eqn;++i){
        used[i] = false;
    }

    int rank= 0;
    for (int j=0;j<var;++j){
        int i = 0;
        while ( ( i<eqn ) && (used[i] || (mat[i][j] == 0) ) ) {
            i++;
        }
        if(i == eqn) continue;
        rank++;
        used[i] = true;
        for (int k=0; k<eqn; k++){
            if(!used[k]){
                int coef = 0;
                while ( (mat[i][j] * coef + mat[k][j]) % 2 != 0) {
                    coef++;
                }

                for (int l=0; l<var; l++) {
                    mat[k][l] = mat[k][l] ^ ( mat[i][l] & coef );
                }
                val[k] = val[k] ^ ( val[i] & coef ) ;
            }
        }
    }

    for (int i=0; i<eqn; i++) {
         if(!used[i] && val[i] != 0) {
              return -1;
         }
    }
    return rank;
}

bool shaon[101];

void fact( LL x,int c ){

    for (int i=0;p[i]*p[i]<= x ; ++i ){
        if ( x%p[i] == 0 ){
            int cnt = 0;
            while ( x%p[i] == 0 ){
                cnt++;
                x/=p[i];
            }
            shaon[ num[ p[i] ] ] = true;
            save[c][ num[ p[i] ] ] = cnt%2;
        }
    }
    if ( x!= 1 ){
        shaon[ num[x] ] = true;
        save[c][ num[ x ] ] = 1;
    }

}

long long BigMod ( long long a, long long p ){
    long long res = 1;
    long long x = a;

    while ( p ){
        if ( p & 1 ){
            res = ( res * x );
        }
        x = ( x * x );
        p = p >> 1;
    }

    return res;
}

int main(){

    FRO

    for (int i=2;i<=24;++i){
        if ( !prime[i] ){
            for (int j=i+i;j<510;j+=i){
                prime[j] = true;
            }
        }
    }

    for ( int i=2;i<510;++i ){
        if ( !prime[i] ){
            p.PB( i );
        }
    }

    //cout<<p.back()<<" "<<p.size()<<endl;

    int cnt = 0;
    for (int i=2;i<510;++i){
        if ( !prime[i] ){
            num[ i ] = cnt++;
        }
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n;
        scanf("%d",&n);
        LL tmp;
        CLR(shaon);
        for (int i=0;i<n;++i){
            for (int j=0;j<p.size();++j){
                mat[i][j] = 0;
                save[i][j] = 0;
            }

            scanf("%lld",&tmp);
            fact( tmp, i );
        }

        cnt = 0;
        for (int j=0;j<101;++j){
            if ( shaon[j] ){
                for (int i=0;i<n;++i){
                    mat[i][ cnt ] = save[i][j];
                }
                cnt++;
            }
        }

        int rank = gauss( n, cnt );

        printf("%lld\n",BigMod( 2 , n- rank )-1 );
    }

    return 0;
}
