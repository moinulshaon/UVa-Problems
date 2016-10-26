#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pint;

#define X first
#define Y second

int calc(int a,int b,int c){
    return abs(a-c)+abs(b-c);
}

int main(){

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    pint a,b,c;

    int kk = 1;
    while ( scanf("%d %d %d %d %d %d",&a.X,&a.Y,&b.X,&b.Y,&c.X,&c.Y) == 6 ){

        int row = abs(a.X-b.X);
        int col = abs(a.Y-b.Y);

        if ( row != col ){
            printf("Case %d: %d\n",kk++,max(row,col));
        }else{
            if ( calc(a.X,b.X,c.X) == row && calc(a.Y,b.Y,c.Y) == col && abs(a.X-b.X)*abs(a.Y-c.Y) == abs(a.X-c.X)*abs(a.Y-b.Y)   ){
                printf("Case %d: %d\n",kk++,max(row,col)+1);
            }else{
                printf("Case %d: %d\n",kk++,max(row,col));
            }
        }

    }

    return 0;
}
