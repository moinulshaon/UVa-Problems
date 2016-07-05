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

#define SIZE 2
LL MOD=1000000;
class Matrix
{
    int N;
public:
    LL matrix[SIZE][SIZE];
    Matrix(int n) {N = n;}
    int getDim() {return N;}
    void setVal(LL array[][SIZE])
    {
        int i,j;
        for (i=0; i<N; ++i)
        {
            for (j=0; j<N; ++j) matrix[i][j] = array[i][j];
        }
    }
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
} base(2);
Matrix bigmod(Matrix A, LL K)
{
    if (K==1) return base;
    if (K&1)
    {
        Matrix ret = bigmod(A, K-1);
        ret = ret * base;
        return ret;
    }
    Matrix ret = bigmod(A, K>>1);
    ret = ret*ret;
    return ret;
}

int main(){

    LL n,b,m;

    while ( scanf("%lld %lld %lld",&n,&m,&b) == 3  ){

        n/=5;

        m%= MOD;
        b%= MOD;

        if ( n== 1 ){
            printf("%06lld\n",m);
            continue;
        }

        base.matrix[0][0]=m;
        base.matrix[0][1]=b;
        base.matrix[1][0]=1;
        base.matrix[1][1]=0;

        Matrix result(2);
        result = bigmod( base,n-1 );

        LL ans = result.matrix[0][0] * m + result.matrix[0][1];
        ans%= MOD;

        printf("%06lld\n",ans);
    }


    return 0;
}
