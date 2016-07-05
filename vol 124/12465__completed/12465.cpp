#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}


#define SIZE 32000

bool prime[SIZE];
vector<int> pp;

int div(int x){
    int cnt;
    int rr=1;
    for (int i=0;pp[i]*pp[i]<=x && x!=1 ;++i){
        cnt=0;
        while(x%pp[i]==0){
            x/=pp[i];
            cnt++;
        }
        rr*=(cnt+1);
    }
    if ( x!=1 ){
        return rr*2;
    }else{
        return rr;
    }
}

int main(){

    for (int i=2;i<=178;++i){
        if ( !prime[i] ){
            for (int j=2*i;j<SIZE;j+=i){
                prime[j]=true;
            }
        }
    }
    for (int i=2;i<SIZE;++i){
        if ( !prime[i] ){
            pp.push_back(i);
        }
    }
    //printf("%d\n",pp.back());
    int a,b,n;
    while(true){
        a=fastIn<int>();
        b=fastIn<int>();
        if ( !a && !b )return 0;
        n=abs(a-b);
        printf("%d\n",div(n));
    }
}
