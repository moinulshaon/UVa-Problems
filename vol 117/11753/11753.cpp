#include <cstdio>
#include <algorithm>


using namespace std;

int mat[10005][10005];
int arr1[10005];
int arr2[10005];

int main()
{
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kk <=kase;++kk)
    {
        int n,difficulty;

        scanf("%d %d",&n,&difficulty);


        for (int i=1;i<=n;++i)
            scanf("%d",&arr1[i]);
        for (int i=1;i<=n;++i)
            arr2[i]=arr1[n-i+1];

        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=n;++j)
            {
                if (arr1[i]==arr2[j])
                {
                    mat[i][j]=1+mat[i-1][j-1];
                }
                else
                    mat[i][j]=max( mat[i-1][j],mat[i][j-1] );
            }
        }

        int result=n-mat[n][n];

        if (!result)
            printf("Case %d: Too easy\n",kk);
        else if (result>difficulty)
            printf("Case %d: Too difficult\n",kk);
        else
            printf("Case %d: %d\n",kk,result);
    }
    return 0;
}
