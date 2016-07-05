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

#define SIZE 1100

pair<LL,LL> row[SIZE],col[SIZE];

const double PP=pow( 10,7 )+1e-7;
int x,y;

bool posrr(){
    if ( x==0 || row[0].first > 0 )return false;
    LL high = 75LL*PP+1e-6;

    LL mx= row[0].second;

    for (int i = 1;i<x;++i ){
        if ( row[i].first > mx ){
            return false;
        }
        //cout<<i<<" "<<row[i].first<<" "<<mx<<endl;

        mx = max( mx, row[i].second );
    }

    return mx >= high;
}

bool poscc(){
    if ( y==0 || col[0].first > 0 )return false;
    LL high = 100LL*PP+1e-6;

    LL mx= col[0].second;

    for (int i = 1;i<y;++i ){
        if ( col[i].first > mx ){
            return false;
        }
        mx = max( mx, col[i].second );
    }
    return mx >= high;
}

int main(){

    FRO

    double w;

    while ( scanf("%d %d %lf",&x,&y,&w) == 3 && ( x+y+w )>1e-6 ){

        w/=2;

        double tmp ;
        for (int i=0;i<x;++i){
            scanf("%lf",&tmp);
            row[i].first = (tmp-w)*PP+1e-6;
            row[i].second = (tmp+w)*PP+1e-6;
        }

        for (int i=0;i<y;++i){
            scanf("%lf",&tmp);
            col[i].first = (tmp-w)*PP+1e-6;
            col[i].second = (tmp+w)*PP+1e-6;
        }

        bool rr= false,cc=false;


        sort( row,row+x );
        sort( col,col+y );

        //cout<<posrr()<<" "<<poscc()<<endl;

        if ( posrr() && poscc()  ){
            printf("YES\n");
        }else{
            printf("NO\n");
        }

    }


    return 0;
}
