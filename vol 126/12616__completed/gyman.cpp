//#include<stdafx.h>


#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<cstdlib>
#include<string>
#include<set>
using namespace std;

#define MAX 20010
#define ll long long

struct edge
{
	int u;
	int v;
	edge(int a,int b)
	{
		u=a;
		v=b;
	}
};

vector<int> adj[MAX];
vector<int> bcc[MAX];
stack<edge> stck;
int d[MAX];
int low[MAX];
int tim;
int bcccount;
int bccno[MAX];
int iscut[MAX];
//int take[MAX];

int ccno[MAX];
vector<int> cc[MAX];
int cccount;

int n,m,x,y;

void dfs(int u,int par)
{
	d[u]=low[u]=tim++;
	int child=0;

	cc[cccount].push_back(u);
	ccno[u]=cccount;

	for(int i=0;i<adj[u].size();i++)
	{
		if(d[adj[u][i]]==-1)
		{
			edge e(u,adj[u][i]);
			stck.push(e);
			child++;
			dfs(adj[u][i],u);
			low[u]=min(low[u],low[adj[u][i]]);
			if(d[u]<=low[adj[u][i]])
			{
				//articulation point
				iscut[u]=1;
				bcccount++;
				while(1)
				{
					edge e1=stck.top();
					if(bccno[e1.u]!=bcccount)
					{
						bccno[e1.u]=bcccount;
						bcc[bcccount].push_back(e1.u);
					}
					if(bccno[e1.v]!=bcccount)
					{
						bccno[e1.v]=bcccount;
						bcc[bcccount].push_back(e1.v);

					}
					stck.pop();
					if(e1.u==u&&e1.v==adj[u][i])
						break;
				}
			}
		}
		else if(adj[u][i]!=par)
		{
			low[u]=min(low[u],d[adj[u][i]]);
		}
	}
	if(par==-1&&child==1)
	{
			iscut[u]=0;
	}
}

ll ans;

int dfs2(int u,int par)
{
	int tot=1;
	int ex=0;
	d[u]=1;
	for(int i=0;i<adj[u].size();i++)
	{
		if(d[adj[u][i]]==-1)
		{
			int x=dfs2(adj[u][i],u);
			tot+=x;
			if(iscut[u]&&(par==-1||bccno[par]!=bccno[adj[u][i]]))
			{
				ans+=x*(cc[ccno[u]].size()-x-1);
				ex+=x;
			}
		}
	}
	//if(par!=-1&&iscut[u]&&bccno[par]!=bccno[u])
	if(iscut[u])
		ans+=(ex)*(cc[ccno[u]].size()-ex-1);
	return tot;
}

void clear()
{
	memset(iscut,0,sizeof(iscut));
	memset(d,-1,sizeof(d));
	memset(low,-1,sizeof(low));
	memset(bccno,-1,sizeof(bccno));
	while(!stck.empty())
		stck.pop();
	bcccount=0;
	for(int i=0;i<MAX;i++)
	{
		adj[i].clear();
		bcc[i].clear();
		cc[i].clear();
	}
	tim=0;

	cccount=0;
	memset(ccno,0,sizeof(ccno));
}


int main()
{
	freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	for(int cas=0;cas<t;cas++)
	{
		cin>>n>>m;
		clear();
		ans=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			adj[x-1].push_back(y-1);
			adj[y-1].push_back(x-1);
		}
		for(int i=0;i<n;i++)
		{
			if(d[i]==-1)
			{
				dfs(i,-1);
				cccount++;
			}
		}
	/*	for(int i=0;i<cccount;i++)
		{
			ll a=cc[i].size();
			ans+=a*(a-1)/2*(n-a)+a*(n-a)*(n-a-1)/2;
		}*/
		memset(d,-1,sizeof(d));
		for(int i=0;i<n;i++)
			if(d[i]==-1)
				dfs2(i,-1);
		printf("Case %d: ",cas+1);
		cout<<ans<<endl;
	}
    return 0;
}
