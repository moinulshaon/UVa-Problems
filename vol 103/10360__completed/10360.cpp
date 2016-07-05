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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define SIZE 1030

int tree[SIZE][SIZE];
int max_x=SIZE-1;
int max_y=SIZE-1;

int read(int x , int y ){
    int val=0;
	int y1;
	while (x > 0 ){
		y1 = y;
		while (y1>0){
			val+=tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return val;
}

void update(int x , int y , int val){
	int y1;
	while (x <= max_x){
		y1 = y;
		while (y1 <= max_y){
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int d;
        scanf("%d",&d);

        int rat,x,y,val;
        scanf("%d",&rat);

        memset(tree,0,sizeof(tree));
        int nx,ny;
        while (rat--){
            scanf("%d %d %d",&x,&y,&val);
            x++;
            y++;

            nx=x-d;
            ny=y-d;

            if ( nx<1 )nx=1;
            if ( ny<1 )ny=1;

            update( nx,ny,val );
            update( nx,y+d+1,-val );
            update( x+d+1,ny,-val );
            update( x+d+1,y+d+1,val );


        }

        int ans=0;
        for (int i=1;i<SIZE;++i){
            for (int j=1;j<SIZE;++j){
                if ( read(i,j)>ans ){
                    ans=read(i,j);
                    nx=i;
                    ny=j;
                }
            }
        }
        printf("%d %d %d\n",nx-1,ny-1,ans);
    }


    return 0;
}
