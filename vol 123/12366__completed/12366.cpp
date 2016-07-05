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

struct tt{
    int a,b,c;
    bool operator<(const tt&x)const{
        if ( a!= x.a )return a<x.a;
        else if ( b!= x.b )return b<x.b;
        else if ( c!= x.c )return c<x.c;
        else return false;
    }
}tmp;

bool three(const tt&x){
    if ( x.a == x.b && x.a == x.c )return true;
    else return false;
}

int two(const tt&x){
    if ( x.a == x.b && x.a != x.c )return x.a;
    else if ( x.a == x.c && x.b != x.c )return x.a;
    else if ( x.b == x.c && x.b != x.a )return x.b;
    else return 0;
}
int sum( const tt&x ){
    return x.a+x.b+x.c;
}


bool cmp( const tt&x,const tt&y ){
    if ( three(x) ){
        if ( three(y) ){
            return x.a>y.a;
        }else{
            return true;
        }
    }else if ( three(y) ){
        return false;
    }

    if ( two(x) ){
        if ( two(y) ){
            if ( two(x)!=two(y) )
                return two(x)>two(y);
            else
                return sum(x)>sum(y);
        }else{
            return true;
        }
    }else if ( two(y) ){
        return false;
    }


    if ( x.c != y.c ){
        return x.c>y.c;
    }else if ( x.b != y.b ){
        return x.b>y.b;
    }else{
        return x.c>y.c;
    }
}


vector<tt> v;
map<tt,int> mp;
int main(){

    FRO

    for (int i=1;i<=13;++i){
        for (int j=i;j<=13;++j){
            for (int k=j;k<=13;++k){
                tmp.a=i;
                tmp.b=j;
                tmp.c=k;
                v.PB( tmp );
            }
        }
    }

    sort( v.begin(),v.end(),cmp );
    /*
    for (int i=0;i<15;++i){
        printf("%d %d %d\n",v[i].a,v[i].b,v[i].c);
    }
    */


    int lim = 0;
    for (int i=0;i<v.size();++i){
        if ( two(v[i]) && !three(v[i]) ){
            lim = i;
        }
        mp[ v[i] ] = i;
    }

    int a,b,c;
    int arr[5];
    while ( scanf("%d %d %d",&a,&b,&c) == 3 && (a+b+c) ){
        arr[0]=a;
        arr[1]=b;
        arr[2]=c;
        sort( arr,arr+3 );
        tmp.a=arr[0];
        tmp.b=arr[1];
        tmp.c=arr[2];

        int ind = mp[ tmp ];
        if ( ind == 0 )printf("*\n");
        else {
            if (ind>lim)ind= lim+1;
            printf("%d %d %d\n",v[ind-1].a,v[ind-1].b,v[ind-1].c);
        }
    }

    return 0;
}
