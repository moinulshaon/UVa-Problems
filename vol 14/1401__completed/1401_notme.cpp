#include <iostream>
#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<queue>
#include<set>
#include<cstring>
using namespace std;

#define ll long long

#define MAX 300300
#define inf ((ll)1<<61)
#define mod 20071027

int getid(char c)
{
	int id;
	id = c-'a';
	return id;
}
typedef struct
{
	int next[26];
} Trie;

const int mx = 500002;

Trie trie[mx];
long cnt[mx], last;
char str[MAX];
long res[MAX];

void add(char *s)
{
	int curr=0;
	for(int i=0;s[i];i++)
	{
		int id=getid(s[i]);
		if(trie[curr].next[id]==-1)
		{
			 trie[curr].next[id]=++last;
			 memset(trie[last].next,-1,sizeof(trie[last].next));
			 cnt[last]=0;
		}
		curr=trie[curr].next[id];
	}
	cnt[curr]++;
}

long search(char *s,long n) //returns how many times s occurs in trie
{
	long curr=0;
	for(int i=n;s[i]&&i<n+101;i++)
	{
		int id=getid(s[i]);
		if(trie[curr].next[id]==-1) return 0;
		curr=trie[curr].next[id];
		if(cnt[curr])
			res[n]=(res[n]+res[i+1])%mod;
	}
	return cnt[curr];
}

void init()
{
   last=0;
   memset(trie[0].next,-1,sizeof(trie[0].next));
   memset(res,0,sizeof(res));
}

int main()
{
	freopen("in.txt","r",stdin);
	int n;
	char temp[5000];
	int cas=0;
	while(scanf("%s",str)==1)
	{
		long len=strlen(str);
		long k;
		scanf("%d",&n);
		init();
		for(int i=0;i<n;i++)
		{
			scanf("%s",temp);
			add(temp);
		}
		for(k=0;str[k];k++)
			if(str[k]<'a'||str[k]>'z')
				break;
		if(k!=len)
		{
			printf("Case %d: %d\n",++cas,0);
			continue;
		}
		res[len]=1;
		for(int i=len-1;i>=0;i--)
		{
			search(str,i);
		}
		printf("Case %d: %ld\n",++cas,res[0]);
	}
	return 0;
}
