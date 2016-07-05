//Bismillahir Rahmanir Raheem

#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<string.h>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<stdlib.h>
#include<string>
#include<set>
#include<iomanip>
#define rep(i,n) for(i=1;i<=n;i++)
#define FOR(i,n) for(i=0;i<n;i++)
#define si(i) scanf("%d",&i)
#define sii(i,j) scanf("%d %d",&i,&j)
#define siii(i,j,k) scanf("%d %d %d",&i,&j,&k)
#define INF 1e9
#define lld long long int
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("output.txt","w",stdout);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ui unsigned int
#define came "came"
#define pii pair<long long int,int>
#define ninf (-1e9)-2
#define inf (1e9)+2
using namespace std;

char a[300][300];
int n,m;
char ln[50];

void K(int si,int sj, int ei, int ej, int col)
{
    int i,j;
    for(i=si;i<=ei;i++)
    {
        for(j=sj;j<=ej;j++)
        {
            a[i][j]=col;
        }
    }
}

void I()
{
    clr(a);
    scanf("%d %d",&m,&n);
    K(0,0,n-1,m-1,'O');
}

void C()
{
    K(0,0,n-1,m-1,'O');
}

void H()
{
    int x,y1,y2;
    char a[10];
    scanf("%d %d %d %s",&y1,&y2,&x,a);
    x--,y1--,y2--;
    if(y1>y2) swap(y1,y2);
    K(x,y1,x,y2,a[0]);
}

void V()
{
    int x,y1,y2;
    char a[10];
    scanf("%d %d %d %s",&x,&y1,&y2,a);
    x--,y1--,y2--;
    if(y1>y2) swap(y1,y2);
    K(y1,x,y2,x,a[0]);
}

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void F()
{
    bool vis[300][300];
    clr(vis);
    queue<int>qx,qy;
    char ln[10],col,pcol;
    int x,y,p,q;
    scanf("%d %d %s",&y,&x,ln);
    x--,y--;
    col=ln[0];
    pcol=a[x][y];
    qx.push(x),qy.push(y);
    vis[x][y]=true;
    a[x][y]=col;
    int i;
    while(!qx.empty())
    {
        x=qx.front(),y=qy.front();
        qx.pop(),qy.pop();
        for(i=0;i<4;i++)
        {
            p=x+dx[i];
            q=y+dy[i];
            if(p>=0 && p<n && q>=0 && q<m && !vis[p][q] && a[p][q]==pcol)
            {
                vis[p][q]=true;
                a[p][q]=col;
                qx.push(p),qy.push(q);
            }
        }
    }
}

void S()
{
    gets(ln);
    puts(ln+1);
    int i;
    for(i=0;i<n;i++)
    {
        puts(a[i]);
    }
}

int main()
{
    //FRO
    //FROut
    n=m=0;
    int x,y;
    char col[10];
    while(scanf("%s",ln)==1)
    {
        int len=strlen(ln);
        if(len==1)
        {
            if(ln[0]=='I')
            {
                I();
            }
            else if(ln[0]=='C')
            {
                C();
            }
            else if(ln[0]=='L')
            {
                scanf("%d %d %s",&y,&x,col);
                x--,y--;
                a[x][y]=col[0];
            }
            else if(ln[0]=='S')
            {
                S();
            }
            else if(ln[0]=='V')
            {
                V();
            }
            else if(ln[0]=='H')
            {
                H();
            }
            else if(ln[0]=='K')
            {
                int sx,sy,ex,ey;
                scanf("%d %d %d %d %s",&sy,&sx,&ey,&ex,ln);
                sx--,sy--,ex--,ey--;
                if(sy>ey) swap(sy,ey);
                if(sx>ex) swap(sx,ex);
                K(sx,sy,ex,ey,ln[0]);
            }
            else if(ln[0]=='F')
            {
                F();
            }
            else if(ln[0]=='X')
            {
                break;
            }
            else
            {
                gets(ln);
            }

        }
        else
        {
            gets(ln);
        }
    }
}
