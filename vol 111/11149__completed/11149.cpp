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

int MOD=10;
class Matrix
{
public:
    int N;

    int **matrix;
    Matrix(int n) {
        N = n;
        matrix=new (int*[n]);
        for (int i=0;i<n;++i)
            matrix[i]=new int[n];
    }
    Matrix( const Matrix&tmp ){
        N=tmp.N;
        matrix=new (int*[N]);
        for (int i=0;i<N;++i){
            matrix[i]=new int[N];
        }
        for (int i=0;i<N;++i){
            for (int j=0;j<N;++j){
                matrix[i][j]=tmp.matrix[i][j];
            }
        }
    }
    Matrix operator = ( const Matrix&tmp ){
        for (int i=0;i<N;++i){
            delete matrix[i];
        }
        delete matrix;


        N=tmp.N;
        matrix=new (int*[N]);
        for (int i=0;i<N;++i){
            matrix[i]=new int[N];
        }
        for (int i=0;i<N;++i){
            for (int j=0;j<N;++j){
                matrix[i][j]=tmp.matrix[i][j];
            }
        }
        return *this;
    }

    ~Matrix(){
        for (int i=0;i<N;++i){
            delete matrix[i];
        }
        delete matrix;
    }
    int getDim() {return N;}

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
}base(2);
Matrix bigmod(Matrix A, int K)
{
    if (K==1) return base;
    if (K&1){
        Matrix ret = bigmod(A, K-1);
        ret = ret * base;
        return ret;
    }
    Matrix ret = bigmod(A, K>>1);
    ret = ret*ret;
    return ret;
}

Matrix func(Matrix A, int K ){
    if (K==1) return base;
    if (K&1){
        Matrix ret = func(A, K-1);
        Matrix tmp= bigmod(A,K);
        return ret+tmp;
    }
    Matrix ret = func(A, K>>1);
    Matrix tmp=bigmod(base,K>>1)*ret;
    ret = ret + tmp;
    return ret;
}

int main(){
    FRO

    int n,k;
    while( scanf("%d %d",&n,&k)==2 && n ){
        Matrix bb(n);

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                scanf("%d",&bb.matrix[i][j]);
                bb.matrix[i][j]%= 10;
            }
        }


        base=bb;

        //base.printMatrix();
        //bb.printMatrix();

        Matrix ans=func( bb,k );


        //ans.printMatrix();

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                if ( j )printf(" ");
                printf("%d",ans.matrix[i][j]%10);
            }
            printf("\n");
        }
        printf("\n");
    }


    return 0;
}
