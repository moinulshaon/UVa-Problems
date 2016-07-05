#include <stdio.h>

int main()
{
    int adj[100][100],i,j,k,number,result[100],n,flag,visited[100];

    while (1)
    {
        number=0;
        for (i=0;i<100;++i)
            for(j=0;j<100;++j)
                adj[i][j]=0;
        for (i=0;i<100;++i)
            visited[i]=0;
        scanf("%d %d",&n,&k);
        if (n==0 && k==0)
            return (0);
        while(k--)
        {
            scanf("%d %d",&i,&j);
            adj[i-1][j-1]=1;
        }
        while (number<n)
        {
            for (j=0;j<n;++j)
            {
                if (!visited[j])
                {
                    flag=1;
                    for (i=0;i<n;++i)
                    {
                        if (adj[i][j])
                        {
                            flag=0;
                            break;
                        }
                    }
                    if (flag)
                    {
                        result[number++]=j;
                        for (i=0;i<n;++i)
                            adj[j][i]=0;
                        visited[j]=1;
                    }
                }
            }

        }
        for (i=0;i<n-1;++i)
            printf("%d ",result[i]+1);
        printf("%d\n",result[i]+1);

    }
}
