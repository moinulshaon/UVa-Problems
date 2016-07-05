#include <cstdio>
#include <vector>

using namespace std;

typedef long long LLL;
typedef vector< vector<LLL> > MATRIX;


MATRIX multiply(MATRIX &a, MATRIX &b) {

    MATRIX res;
    res.resize( a.size() );
    for (int i=0;i<res.size();++i){
        res[i].resize( b[0].size() );
    }

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[i].size(); j++)
            for (int k = 0; k < a[i].size() ; k++) //col of A and row of B must be same which is equal to a[i].size()
                res[i][j] +=  a[i][k] * b[k][j];

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
            printf("%5d",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(){

    freopen("in.txt","r",stdin);

    LLL p,q;
    int n;

    MATRIX initial;
    initial.resize(2);
    for (int i=0;i<initial.size();++i){
        initial[i].resize(2);
    }
    initial[1][0]=1;

    while (scanf("%lld %lld %d",&p,&q,&n)==3){


        if ( n==0 ){
            printf("2\n");
        }else if ( n==1 ){
            printf("%lld\n",p);
        }else if ( n==2 ){
            printf("%lld\n",p*p-2*q);
        }
        else{
            initial[0][0]=p;
            initial[0][1]= -q;

            MATRIX result=powerMatrix( initial ,n-2 );

            int base1=p;
            int base2=p*p-2*q;

            //printMatrix(result);
            printf("%lld\n",result[0][0]*base2+result[0][1]*base1);
        }
    }
    return 0;

}

