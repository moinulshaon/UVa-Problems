#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>
#define INF 1000000

using namespace std;

int arr[200][200];
int save[200][200];

int main()
{
    int n,test;
    scanf("%d",&test);
    while (test--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                arr[i][j]=1;

        pair <int,int> begin,last,temp;
        int query;
        scanf("%d",&query);
        while (query--)
        {
            scanf("%d %d %d %d",&begin.first,&begin.second,&last.first,&last.second);
            if (begin.first>last.first)
                swap(begin,last);

            for (int i=begin.first;i<=last.first;++i)
                for (int j=begin.second;j<=last.second;++j)
                {
                    arr[i][j]=-INF;
                }
        }

        for (int i=1;i<=n;++i)
        {

            for (int j=1;j<=n;++j)
            {

                arr[i][j]+=arr[i-1][j];
            }
        }

        int mx=0;
        for (int i=1;i<=n;++i)
            for (int j=i;j<=n;++j)
            {
                int tmp=0;
                for (int k=1;k<=n;++k)
                {
                    tmp+=arr[j][k]-arr[i-1][k];
                    if (tmp<0)tmp=0;
                    else if (tmp>mx)mx=tmp;
                }
            }
        printf("%d\n",mx);
    }
    return 0;
}
