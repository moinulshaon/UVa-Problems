#include <cstdio>
#include <cstring>
#include <iostream>
#define INF 10000

using namespace std;

int arr[50][50];
char line[100];

int main()
{
    freopen("in.txt","r",stdin);

    int n;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%s",line);
        int len=strlen(line);
        for (int i=1;i<=len;++i)
        {
            arr[1][i]=line[i-1]-'0';
        }
        for (int i=2;i<=len;++i)
        {
            scanf("%s",line);
            for (int j=1;j<=len;++j)
            {
                arr[i][j]=line[j-1]-'0';
            }
        }

        for (int i=1;i<=len;++i)
            for (int j=1;j<=len;++j)
                if (arr[i][j]==0)
                    arr[i][j]=-INF;

        for (int i=1;i<=len;++i)
            for (int j=1;j<=len;++j)
            {
                arr[i][j]+=arr[i-1][j];
            }






        int mx=0;
        for (int i=1;i<=len;++i)
            for (int j=i;j<=len;++j)
            {
                int tmp=0;
                for (int k=1;k<=len;++k)
                {
                    tmp+=arr[j][k]-arr[i-1][k];
                    if (tmp<0)tmp=0;
                    else if (tmp>mx)mx=tmp;
                }
            }
        printf("%d\n",mx);
        if (n)printf("\n");
    }
    return 0;
}
