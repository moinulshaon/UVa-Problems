#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

#define sz 50

using namespace std;

bool vis[sz][sz];
bool d[sz][sz][2];
long long result[sz][sz];
long long  n;
long long destination_x,destination_y;

long long  DFS(long long  a,long long b){
    if (a==destination_x && b==destination_y)
        return 1;

    if (vis[a][b])return result[a][b];
    if (a>destination_x || b>destination_y) return 0;

    long long  m=0;
    if (d[a][b][0])
        m+=DFS(a,b+1);
    if (d[a][b][1])
        m+=DFS(a+1,b);
    vis[a][b]=true;
    return result[a][b]=m;

}

int main(){
    freopen("in.txt","r",stdin);

    long long kase,a,b,kk,x,y;
    char ch;
    scanf("%lld",&kase);

    while (kase--){
        memset(vis,false,sizeof(vis));
        memset(d,true,sizeof(d));

        scanf("%lld",&n);


        scanf("%lld %lld",&x,&y);
        scanf("%lld %lld",&destination_x,&destination_y);

        scanf("%lld",&kk);

        while (kk--){
            scanf("%lld %lld",&a,&b);
            cin>>ch;
            if (ch=='N'){
                d[a][b][0]=false;
            }
            else if (ch=='E'){
                d[a][b][1]=false;
            }
            else if (ch=='S'){
                d[a][b-1][0]=false;
            }
            else if (ch=='W'){
                d[a-1][b][1]=false;
            }
        }


        printf("%lld\n",DFS(x,y));
    }
    return 0;

}
