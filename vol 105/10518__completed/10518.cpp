#include <cstdio>
#include <vector>

using namespace std;


typedef long long LLL;
typedef vector< vector<int> > MATRIX;

#define DIM 4

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


MATRIX powerMatrix(MATRIX mat,LLL n){

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

    freopen("in.txt","r",stdin);

    LLL n;

    MATRIX initial;

    initial.resize(3);
    for (int i=0;i<3;++i){
        initial[i].resize(3);
    }
    initial[0][0]=initial[0][1]=initial[0][2]=initial[1][0]=initial[2][2]=1;

    MATRIX save;
    save.resize(3);
    for (int i=0;i<save.size();++i){
        save[i].resize(1,1);
    }

    for (int kk=1;true;++kk){
        scanf("%lld %d",&n,&mod);

        if (!n && !mod)return 0;


        printf("Case %d: %lld %d ",kk,n,mod);

        if ( n==0 || n==1 ){
            printf("%d\n", 1%mod  );
            continue;
        }

        MATRIX result=powerMatrix( initial,n-1 );
        result=multiply( result,save );
        printf("%d\n",result[0][0]%mod  );
    }

}

