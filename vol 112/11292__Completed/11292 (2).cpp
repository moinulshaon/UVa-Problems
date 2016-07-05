#include <cstdio>
#include <algorithm>

using namespace std;

int marr[20002];
int narr[20002];


int main()
{
    int m,n;
    while (true){
        scanf("%d %d",&m,&n);

        if (!m && !n)return 0;

        for (int i=0;i<m;++i)
            scanf("%d",&marr[i]);
        for (int i=0;i<n;++i)
            scanf("%d",&narr[i]);

        sort(marr,marr+m);
        sort(narr,narr+n);

        int cnt=0,pointer=0;
        for (int i=0;i<n && pointer<m;++i)
        {
            if (narr[i]>=marr[pointer])
            {
                cnt+=narr[i];
                pointer++;
            }
        }
        if (pointer==m)
            printf("%d\n",cnt);
        else
            printf("Loowater is doomed!\n");
    }

}
