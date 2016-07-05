/*
  Name:  UVA439
  Author: zoom
  Date: 04/06/11
*/
using namespace std;
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define LLU long long unsigned int
#define LLD long long double
#define FOR(i,N) for(int i=0;i<(N);i++)
string a,b;
int t11,t12,t21,t22,x,y;
bool vis[10][10];
int arr[10][10];
pair<int,int> c1,c2;
void init()
{
    FOR(i,10)
    FOR(j,10)
    {
        arr[i][j]=0;
        vis[i][j]=0;
    }
}
bool check(int i,int j)
{
    if((i>=1 && i<=8)&& (j>=1 && j<=8))
    {
        if(!vis[i][j])
        {
            vis[i][j]=true;
            return true;
        }
    }
    return false;
}
int calc()
{

    queue <pair<int,int> >q;
    q.push(c1);
    vis[c1.first][c1.second]=true;
    int i,j;
    while(!q.empty())
    {
        c1=q.front();
        q.pop();
        i=c1.first;
        j=c1.second;
        int k,l;
        k=i-1;l=j-2;
        if(check(k,l))
        {
            q.push(make_pair(k,l));
            arr[k][l]=arr[i][j]+1;
        }
        k=i+1;l=j-2;
        if(check(k,l))
        {
            q.push(make_pair(k,l));
            arr[k][l]=arr[i][j]+1;
        }
        k=i+2;l=j-1;
        if(check(k,l))
        {
            q.push(make_pair(k,l));
            arr[k][l]=arr[i][j]+1;
        }
        k=i+2;l=j+1;
        if(check(k,l))
        {
            q.push(make_pair(k,l));
            arr[k][l]=arr[i][j]+1;
        }
        k=i+1;l=j+2;
        if(check(k,l))
        {
            q.push(make_pair(k,l));
            arr[k][l]=arr[i][j]+1;
        }
        k=i-1;l=j+2;
        if(check(k,l))
        {
            q.push(make_pair(k,l));
            arr[k][l]=arr[i][j]+1;
        }
        k=i-2;l=j+1;
        if(check(k,l))
        {
            q.push(make_pair(k,l));
            arr[k][l]=arr[i][j]+1;
        }
        k=i-2;l=j-1;
        if(check(k,l))
        {
            q.push(make_pair(k,l));
            arr[k][l]=arr[i][j]+1;
        }
        if(vis[c2.first][c2.second]) return arr[c2.first][c2.second];
    }
    return arr[c2.first][c2.second];
}
int main()
{

	freopen("input.txt","r",stdin);
    while(cin>>a>>b)
    {
        t11=a[0]-'a'+1;
        t12=a[1]-'0';
        t21=b[0]-'a'+1;
        t22=b[1]-'0';
        c1.first=t11;
        c1.second=t12;
        c2.first=t21;
        c2.second=t22;
        init();
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<calc()<<" knight moves.\n";
    }
}
