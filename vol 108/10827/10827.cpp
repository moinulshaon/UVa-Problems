#include <cstdio>
#include <iostream>

using namespace std;

int arr[400][400];
int save[400][400];

int main()
{
    freopen("in.txt","r",stdin);

    int n,test;
    scanf("%d",&test);
    while (test--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
            {
                scanf("%d",&arr[i][j]);
                save[i][j]=arr[i][j];
                arr[i][j]+=arr[i-1][j];
            }
        for (int i=n+1,p=1;i<=2*n;++i,++p)
            for (int j=1,q=1;j<=n;++j,++q)
                arr[i][j]=save[p][q]+arr[i-1][j];
        for (int i=1;i<=2*n;++i)
        {
            for (int j=n+1;j<=2*n;++j)
                arr[i][j]=arr[i][j-n];
        }


        int mx=0;
        for (int i=1;i<=n;++i)
            for (int j=i;j<i+n;++j)
            {

                for (int ss=1;ss<=n;++ss)
                {
                    int tmp=0;
                    for (int k=ss;k<n+ss;++k)
                    {
                        tmp+=arr[j][k]-arr[i-1][k];
                        if (tmp>mx)mx=tmp;
                        else if (tmp<0)
                        {
                            tmp=0;
                        }
                    }
                }


            }
        if (!mx)
        {
            mx=save[1][1];
            for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j)
                    if (save[i][j]>mx)
                        mx=save[i][j];
        }
        printf("%d\n",mx);
    }
    return 0;
}
