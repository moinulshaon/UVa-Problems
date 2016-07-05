#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector< vector<LL> > MATRIX;

#define DIM 2
LL mod;

LL mult(LL a, LL b){
    LL ret = 0;

    while(b){
        if(b & 1) ret += a;
        if(ret >=mod) ret -= mod;

        a <<= 1;
        if(a >= mod) a -= mod;

        b >>= 1;
    }

    return ret;
}



MATRIX multiply(MATRIX &a, MATRIX &b) {

    MATRIX res;
    res.resize( a.size() );
    for (int i=0;i<res.size();++i){
        res[i].resize( b[0].size() );
    }

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[i].size(); j++)
            for (int k = 0; k < a[i].size() ; k++) //col of A and row of B must be same which is equal to a[i].size()
                res[i][j] = ( res[i][j] + ( mult( a[i][k] % mod  , b[k][j] % mod ) ) % mod ) %mod;

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


int main(){
    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);
    LL n,b,d;
    MATRIX ini;
    ini.resize(DIM);
    for (int i=0;i<ini.size();++i){
        ini[i].resize(DIM);
    }


    ini[0][1]=1;
    ini[1][1]=1;
    ini[1][0]=0;

    for (int kk=1;kase--;++kk){
        scanf("%lld %lld %lld %lld",&n,&b,&d,&mod);
        printf("Case %d: ",kk);

        ini[0][0]=b;

        d%=mod;

        if ( n==1 ){
            printf("%lld\n",d);
        }else if (n==2 ){
            printf("%lld\n",(d*( (1+b)%mod ) ) %mod);
        }else{
            MATRIX rr=powerMatrix(ini,n-2);
            //printf("shaon %lld\n",rr[0][1]);
            printf("%lld\n", mult( d , mult( rr[0][0]%mod,(1+b)%mod ) %mod + ( rr[0][1]*1 )%mod )%mod    );
        }
    }
    return 0;
}
