#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int m,n;

struct WW{
    int x1,y1,x2,y2;
}wall[1000];

struct DD{
    int x,y,d;
}door[1000];


int main(){

    while ( scanf("%d %d",&m,&n)==2 ){
        if ( m== -1 && n== -1 )return 0;

        vector<double> posx,posy;


        int d,t;
        for (int i=0;i<m;++i){
            scanf("%d %d %d %d",&wall[i].x1,&wall[i].y1,d,t);
            if ( ! d ){
                wall[i].x2=wall[i].x1+t;
                wall[i].y2=wall[i].y1;
            }else{
                wall[i].x2=wall[i].x1;
                wall[i].y2=wall[i].y1+t;
            }
            wall[i].x1<<=1;
            wall[i].x2<<=1;
            wall[i].y1<<=1;
            wall[i].y2<<=1;

            posx.push_back( wall[i].x1 );
            posx.push_back( wall[i].x2 );

            posy.push_back( wall[i].y1 );
            posy.push_back( wall[i].y2 );


        }

        for (int i=0;i<n;++i){
            scanf("%d %d %d",&door[i].x,&door[i].y,&door[i].d);

            door[i].x<<=1;
            door[i].y<<=1;

            posx.push_back( door[i].x );
            posy.push_back( door[i].y );
        }
        sort(posx.begin(),posx.end() );
        sort(posy.begin(),posy.end() );


    }

}
