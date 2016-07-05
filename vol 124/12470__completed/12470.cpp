#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

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

typedef long long LL;
typedef vector< vector<LL> > MATRIX;

#define DIM 3

LL mod=1000000009;



MATRIX multiply(MATRIX &a, MATRIX &b) {

    MATRIX res;
    res.resize( a.size() );
    for (int i=0;i<res.size();++i){
        res[i].resize( b[0].size() );
    }

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[i].size(); j++)
            for (int k = 0; k < a[i].size() ; k++) //col of A and row of B must be same which is equal to a[i].size()
                res[i][j] = ( res[i][j] + ( ( (a[i][k] % mod ) * (b[k][j] % mod))) % mod ) %mod;

    return res;

}

MATRIX powerMatrix(MATRIX mat,LL n){

    if(n == 1)  return mat;
    else if(n % 2 == 0){
        MATRIX tmp=powerMatrix( mat,n/2 );
        return  multiply(tmp,tmp);
    }
    else{
        MATRIX tmp=powerMatrix( mat,n/2 );
        tmp=multiply(tmp,tmp);
        return  multiply(  tmp ,mat);
    }
}


void printMatrix(MATRIX mat){
    for (int i=0;i<mat.size();++i){
        for (int j=0;j<mat[i].size();++j){
            printf("%3d",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



int main(){

    LL n;

    MATRIX ini;
    ini.resize(DIM);
    for (int i=0;i<DIM;++i){
        ini[i].resize(DIM);
    }

    ini[0][0]=ini[0][1]=ini[0][2]=ini[1][0]=ini[2][1]=1;
    //printMatrix(ini);
    while( true ){

        n=fastIn<LL>();
        if ( !n )break;

        if ( n == 1 )printf("0\n");
        else if ( n == 2 )printf("1\n");
        else if ( n==3 )printf("2\n");
        else{
            MATRIX rr=powerMatrix( ini,n-3 );
            //printMatrix(rr);
            printf("%lld\n",(2*rr[0][0]+rr[0][1])%mod );
        }
    }
    return 0;
}
