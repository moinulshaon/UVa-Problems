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

struct mathv{
    mathv(){x=0;y=0;}
    mathv(int a,int b){x=a;y=b;}
    int x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }

};

int cross2D(mathv v1, mathv v2){
    return v1.x * v2.y - v1.y * v2.x;
}

mathv point[110];
int n;

int main(){
    FRO

    while ( scanf("%d",&n) == 1 && n ){
        for (int i=0;i<2*n;++i){
            scanf("%d %d",&point[i].x,&point[i].y);
        }


        int a,b;
        for (int i= -500 ;i<=500;++i ){
            for (int j= -500 ; j<=500;++j){
                if ( __gcd(i,j) != 1 )continue;

                int le=0,tmp,ri=0;
                mathv tt( i,j );

                for (int k=0;k<2*n;++k){
                    tmp= cross2D( point[k],tt  );
                    if ( tmp ==0 ){
                        ri=10000;
                        break;
                    }else if ( tmp>0 ){
                        ri++;
                    }else{
                        le++;
                    }
                }

                if ( le==ri ){
                    a=i;
                    b=j;
                    i=j= 10000;
                }
            }
        }

        printf("%d %d\n",b,-a);
    }


    return 0;
}
