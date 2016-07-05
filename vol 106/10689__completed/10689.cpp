#include <cstdio>
#include <vector>

using namespace std;

typedef vector< vector<int> > MATRIX;


int mod;

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
            printf("%3d",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(){

    int kase,a,b,n,m;

    scanf("%d",&kase);

    MATRIX initial;
    initial.resize(2);
    for (int i=0;i<2;++i){
        initial[i].resize(2,1);
    }
    initial[1][1]=0;

    while (kase--){
        scanf("%d %d %d %d",&a,&b,&n,&m);

        if ( m==1 ){
            mod=10;
        }else if ( m==2 ){
            mod=100;
        }else if ( m==3 ){
            mod=1000;
        }else{
            mod=10000;
        }

        if ( n==0 ){
            printf("%d\n",a%mod);
        }else if ( n==1 ){
            printf("%d\n",b%mod);
        }else{
            MATRIX result=powerMatrix( initial ,n-1);
            printf("%d\n", (result[0][0]*b+result[0][1]*a)%mod );
        }

    }
    return 0;
}
