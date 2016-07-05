#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

int parent[100];



int find(int x)
{
    if (parent[x]==x)
        return x;
    else
        return parent[x]=find(parent[x]);
}




int main()
{
    freopen("in.txt","r",stdin);

    int m,n,tx,ty,a,b,component,total;
    char c1,c2;

    while(scanf("%d %d",&total,&m)==2)
    {
        map<char,int> myp;
        if (!total && !m)return 0;

        for (int i=1;i<=total;++i)
            parent[i]=i;

        int node=1;
        for (int i=0; i<m; ++i)
        {

            cin>>c1>>c2;
            if (myp.find(c1)==myp.end())
                myp[c1]=node++;
            if (myp.find(c2)==myp.end())
                myp[c2]=node++;

            a=myp[c1];
            b=myp[c2];

            tx=find(a);
            ty=find(b);

            if (tx!=ty)
            {
                parent[ty]=parent[tx];
            }
        }

        component=0;
        for (int i=1;i<=total;++i)
        {
            if (find(i)==i)
                ++component;
        }

        int result=(m+component-1)-total+2;
        printf("%d\n",result);
    }
    return 0;

}
