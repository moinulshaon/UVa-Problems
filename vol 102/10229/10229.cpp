#include <cstdio>
#include <vector>

using namespace std;
typedef long long LLL;
typedef vector< vector<LLL> > MATRIX;

#define DIM 2

LLL mod;

MATRIX multiply(MATRIX &a, MATRIX &b) {

    MATRIX res;
    res.resize( a.size() );
    for (int i=0;i<res.size();++i){
        res[i].resize( b[i].size() );
    }

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            for (int k = 0; k < a[i].size() ; k++) //col of A and row of B must be same which is equal to a[i].size()
                res[i][j] = ( res[i][j] + ( ( (a[i][k] % mod ) * (b[k][j] % mod))) % mod ) %mod;

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

    int n,m;

    MATRIX initial;
    initial.resize(DIM);
    for (int i=0;i<initial.size();++i){
        initial[i].resize(DIM);
    }

    for (int i=0;i<DIM;++i){
        for (int j=0;j<DIM;++j){
           initial[i][j]=1;
        }
    }
    initial[1][1]=0;


    while (scanf("%d %d",&n,&m)==2){

        mod=1<<m;

        if( n==0 || m==0 ){
            printf("0\n");
            continue;
        }else if ( n==1 ){
            printf("%d\n",n%mod);
            continue;
        }

        MATRIX result=powerMatrix( initial , n-1 );

        printf("%lld\n",result[0][0]%mod);

    }
    return 0;

}
