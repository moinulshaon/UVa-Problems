#include <cstdio>

using namespace std;

int arr[200][200];
int save[200][200];

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
            {
                scanf("%d",&arr[i][j]);
                save[i][j]=arr[i][j];
                arr[i][j]+=arr[i-1][j];
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
                    //cout<<tmp<<arr[k][j]<<arr[k][i-1]<<endl;
                }
                //printf("%d %d %d\n",mx,i,j);
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
