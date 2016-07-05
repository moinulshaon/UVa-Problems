#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

#define sz 100100

const double INF=INT_MAX;


struct ppp{
    int x,y;
    ppp(int a=0,int b=0){
        x=a;y=b;
    }

}points[sz];
int stk[sz];
int ans[2];

bool cmp(const ppp&a,const ppp&b){
    return a.x<b.x;
}

ppp dist(int a,int b){
    return ppp( abs(points[a].x-points[b].x) ,abs(points[a].y-points[b].y)  );
}


int top;
int nowmin;
int closest(int a,int b){
    ppp tmp;
    if (a==b)return INF;
    else if ( b-a== 1 ){
        tmp=dist(a,b);
        if ( max(tmp.x,tmp.y)<nowmin ){
            ans[0]=a;
            ans[1]=b;
            nowmin=max(tmp.x,tmp.y);
        }
        return max(tmp.x,tmp.y);
    }
    int m=(a+b)/2;

    int left=closest(a,m);
    int right=closest(m+1,b);

    int d=min(left,right);
    //printf("%d\n",d);
    top=0;
    for(int i=m;i>=a && abs(points[i].x-points[m].x)<=d;i--)
		stk[top++]=i;

    for(int i=m+1;i<=b && abs(points[i].x-points[m].x)<=d;i++)
		stk[top++]=i;



    for (int i=0;i<top;++i){
        for (int j=i+1;j<top;++j){
            tmp=dist(stk[i],stk[j]);
            if ( max(tmp.x,tmp.y)<d ){
                d=max(tmp.x,tmp.y);
                if ( max(tmp.x,tmp.y)<nowmin ){
                    nowmin=max(tmp.x,tmp.y);
                    ans[0]=stk[i] ;
                    ans[1]= stk[j] ;
                }
            }
        }
    }
    return d;
}


int main(){
    freopen("in.txt","r",stdin);
    int total;
    while (scanf("%d",&total)==1 ){
        for (int i=0;i<total;++i){
            scanf("%d %d",&points[i].x,&points[i].y);
        }
        sort(points,points+total,cmp);
        nowmin=INF;
        closest(0,total-1);

        printf("%d\n",nowmin);
    }
    return 0;
}
