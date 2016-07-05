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

#define SIZE 105

int MOD=10007;
class Matrix
{
    int N;
public:
    int matrix[SIZE][SIZE];
    Matrix(int n= 0) {
        N = n;
    }
    int getDim() {return N;}
    void setDim( int x ){N=x;}
    Matrix operator+ (Matrix &A)
    {
        Matrix ret(N);
        int i,j;
        for (i=0; i<N; ++i)
        {
            for (j=0; j<N; ++j) ret.matrix[i][j] = (matrix[i][j] + A.matrix[i][j])%MOD;
        }
        return ret;
    }
    Matrix operator* (Matrix &A)
    {
        Matrix ret(N);
        int i,j,k;
        for (i=0; i<N; ++i)
        {
            for (j=0; j<N; ++j)
            {
                ret.matrix[i][j] = 0;
                for (k=0; k<N; ++k)
                {
                    ret.matrix[i][j] += matrix[i][k]*A.matrix[k][j];
                    ret.matrix[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
    void printMatrix()
    {
        int i,j;
        puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        for (i=0; i<N; ++i)
        {
            for (j=0; j<N; ++j) printf("%3d ", matrix[i][j]);
            puts("");
        }
        puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    }
};

Matrix tmp;
Matrix A;
void bigmod( int p)
{
    A = tmp;
    p--;

    while ( p>0 ){
        if ( p & 1 ){
            tmp = tmp * A;
            p--;
        }else{
            A = A * A ;
            p = p >> 1;
        }
    }
}

int fact[110];

int main(){

    FRO



    int kase;
    scanf("%d",&kase);
    //kase= 7;
    for (int kk=1;kase--;++kk){
        int n,dim;
        scanf("%d %d",&n,&dim);

        dim++;

        fact[0]= 0 ;
        fact[1] = 1;
        for (int i=2;i<110;++i){
            if ( i<dim )
            fact[i] = ( fact[i-1] + fact[i-2] )%MOD ;
            else
            fact[i] = ( fact[i-1] + fact[i-2] - fact[i-dim+1] )%MOD ;

            if ( fact[i] <0 )fact[i]+=MOD;
        }

        printf("Case %d: ",kk);
        if ( n<=dim+1 ){
            printf("%d\n",(fact[n]*2)%MOD );
            continue;
        }

        tmp.setDim( dim );

        for (int i=0;i<dim;++i){
            for (int j=0;j<dim;++j){
                tmp.matrix[i][j] = 0;
            }
        }

        tmp.matrix[0][0] = tmp.matrix[0][1]= 1;
        tmp.matrix[0][dim-1] = -1;

        for (int i=1;i<dim;++i){
            tmp.matrix[ i ][ i-1 ] = 1;
        }
        /*
        for (int i=0;i<dim;++i){
            for (int j=0;j<dim;++j){
                printf("%3d",tmp.matrix[i][j]);
            }printf("\n");
        }
        */

        //cout<<"doing "<<n-dim-1<<endl;

        bigmod(  n-dim );

        int tt=0;

        for (int i=0;i<dim;++i){
            tt= ( tt+ tmp.matrix[0][i]*fact[dim-i] )%MOD;

            //cout<<fact[ dim-i ]<<endl;
        }


        if ( tt<0 )tt+=MOD;

        printf("%d\n",(tt*2)%MOD);


    }


    return 0;
}
