#include<cstdio>
#include<string>
#include <map>
#include <iostream>
#include <cstring>

using namespace std;

int p[100010];
int find(int x)
{
    return p[x]<0?x:(p[x]=find(p[x]));
}


int main()
{

    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);
    while(t--)
    {

        int tx,ty,input,totalfriend=0;
        scanf("%d",&input);
        memset(p,-1,sizeof(p));
        map <string,int> ind;
        string a,b;
        while (input--)
        {
            cin>>a>>b;

            if (ind.find(a)==ind.end())ind[a]=totalfriend++;
            if (ind.find(b)==ind.end())ind[b]=totalfriend++;
            tx=find(ind[a]);
            ty=find(ind[b]);
            if(ty!=tx)
            {
                p[tx]+=p[ty];
                p[ty]=tx;
            }
            printf("%d\n",-p[tx]);
        }
    }
    return 0;
}
