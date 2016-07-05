#include<cstdio>
#include<string>
#include<cstring>
#include <map>
#include <iostream>

using namespace std;


int parent[5100];

int find(int x)
{
    return parent[x]<0?x:(parent[x]=find(parent[x]));
}

int main()
{
    int ans;
    while(true)
    {
        int n,r;
        scanf("%d %d",&n,&r);

        if (!n && !r)return 0;

        string a,b;

        int i,x,y,tx,ty,ans=0;

        map<string,int> myp;

        for (i=1;i<=n;++i)
        {
            cin>>a;
            myp[a]=i;
        }

        memset(parent,-1,sizeof(parent));

        for(i=0;i<r;i++)
        {
            cin>>a>>b;

            x=myp[a];
            y=myp[b];

            tx=find(x);
            ty=find(y);

            if(tx!=ty)
            {
                parent[tx]+=parent[ty];
                parent[ty]=tx;
            }
        }

        for(i=1;i<=n;i++)
        {
            if(-parent[i]>ans)
                ans=-parent[i];
        }
        printf("%d\n",ans);
    }
}
