#include <cstdio>
#include <iostream>

using namespace std;

int arr[20100];

int main()
{

    freopen("in.txt","r",stdin);

    int n;
    while (scanf("%d",&n)==1)
    {
        for (int m=1;m<=n;++m)
        {
            int route;
            scanf("%d",&route);
            for (int k=1;k<route;++k)
            {
                scanf("%d",&arr[k]);
            }

            int mx=0,starttmp=0,start,finish;

            int tmp=0;
            for (int i=1;i<route;++i)
            {
                tmp+=arr[i];
                if (tmp<0)
                {
                    tmp=0;
                    starttmp=i;
                }
                if (tmp>mx)
                {
                    mx=tmp;
                    start=starttmp;
                    finish=i;
                }
                else if (tmp==mx && i-starttmp>finish-start)
                {
                    start=starttmp;
                    finish=i;
                }
            }
            if (mx)
                printf("The nicest part of route %d is between stops %d and %d\n",m,start+1,finish+1);
            else
                printf("Route %d has no nice parts\n",m);
        }
    }
    return 0;
}
