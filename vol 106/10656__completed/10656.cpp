#include <cstdio>
#include <iostream>

using namespace std;

int arr[1050];

int main()
{

    int n;
    while (true)
    {
        scanf("%d",&n);
        if (!n)return 0;

        bool on=false;
        for (int k=0;k<n;++k)
        {
            scanf("%d",&arr[k]);
            if (arr[k])
            {
                if (on)
                    printf(" %d",arr[k]);
                else
                    printf("%d",arr[k]);
                on=true;
            }
        }
        if (!on)
            printf("0\n");
        else
            printf("\n");
    }
}
