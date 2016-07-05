#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }


LL ncr(int n,int r){
    LL tmp = 1;
    for (int i=0;i<r;++i){
        tmp= tmp*(n-i);
    }
    for (int i=1;i<=r;++i){
        tmp= tmp/r;
    }
    return tmp;
}

int main(){


    int kase;
    scanf("%d",&kase);

    while ( kase-- ){

        int C[4];
        for (int i=0;i<4;++i){
            scanf("%d",&C[i]);
        }
        int q;
        scanf("%d",&q);

        int v,D[4];
        while ( q-- ){
            for (int i=0;i<4;++i){
                scanf("%d",&C[i]);
            }
            scanf("%d",&v);

        }

    }


    return 0;
}
