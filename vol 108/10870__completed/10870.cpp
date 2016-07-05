#include <cstdio>
#include <vector>

using namespace std;

typedef long long LLL;

typedef vector< vector<LLL> > MATRIX;

LLL mod;

MATRIX multiply(MATRIX &a, MATRIX &b) {

    MATRIX res;
    res.resize( a.size() );
    for (int i=0;i<res.size();++i){
        res[i].resize( b[0].size() );
    }

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            for (int k = 0; k < a[i].size() ; k++) //col of A and row of B must be same which is equal to a[i].size()
                res[i][j] = ( res[i][j] +  ( (a[i][k] % mod ) * (b[k][j] % mod)) % mod ) %mod;

    return res;

}


MATRIX powerMatrix(MATRIX mat,int n){

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
            printf("%3lld",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    freopen("in.txt","r",stdin);

    LLL d,n;

    MATRIX initial[16];

    for (int i=1;i<16;++i){
        initial[i].resize(i);
        for (int j=0;j<initial[i].size();++j){
            initial[i][j].resize(i);
        }

        for (int j=0;j<initial[i].size();++j){

            for (int k=0;k<initial[i][j].size() ;++k){

                if ( k+1==j ){
                    initial[i][j][k]=1;
                }

            }

        }
        //printMatrix(initial[i]);
    }

    LLL save[16];

    while (true){

        scanf("%lld %lld %lld",&d,&n,&mod);

        if ( !d && !n && !mod )return 0;
        for (int i=0;i<d;++i){
            scanf("%lld",&initial[d][0][i]);
        }
        //printMatrix(initial[d]);
        for (int i=0;i<d;++i){
            scanf("%lld",&save[i]);
        }

        if ( n-d<1 ){
            printf("%lld\n",save[d-1]);
            continue;
        }

        MATRIX result=powerMatrix( initial[d] , n-d);
        //printMatrix(result);

        LLL sum=0;
        for (int i=0;i<d;++i){
            sum+= save[d-i-1]*result[0][i];
            //printf("%lld %lld\n",save[d-i-1],result[0][i]);
        }
        printf("%lld\n",sum%mod);

    }
}
