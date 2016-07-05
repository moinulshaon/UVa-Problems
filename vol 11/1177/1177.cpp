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

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;
#define SIZE 2
class Matrix
{
    int N;
public:
    LL matrix[SIZE][SIZE];
    Matrix(int n) {N = n;}
    int getDim() {return N;}
    void setVal(int array[][SIZE])
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
            for (j=0; j<N; ++j) ret.matrix[i][j] = (matrix[i][j] + A.matrix[i][j]);
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
                    //ret.matrix[i][j] %= MOD;
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
Matrix bigmod(Matrix A, LL p){
    Matrix x= A;
    p--;
    while ( p>0 ){
        if ( p&1 ){
            A= A * x;
        }
        x=x*x;
        p>>=1;
    }
    return A;
}

int main(){

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        Matrix x(2);

        LL f0,f1;
        scanf("%lld %lld",&f0,&f1);

        scanf("%lld %lld",&x.matrix[0][0],&x.matrix[0][1]);

        x.matrix[1][0]=1;
        x.matrix[1][1]=0;


        LL n;
        scanf("%lld",&n);

        if ( n==0 ){
            printf("%lld\n",f0);
        }else if(n==1){
            printf("%lld\n",f1);
        }else{
            Matrix res= bigmod(x,n-1);
            printf("%lld\n",res.matrix[0][0]*f1+res.matrix[0][1]*f0);
        }

    }


    return 0;
}
