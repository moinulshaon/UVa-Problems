#include <cstdio>
#include <cstring>
#include <vector>
#define sz 10000

using namespace std;

vector <int> arr[sz];
bool pos[sz];
int cd[25];

int main()
{
    int n,m;

    while (scanf("%d %d",&n,&m)==2)
    {
        for (int i=0;i<m;++i)
            scanf("%d",&cd[i]);

        for (int i=0;i<=n;++i)
            arr[i].clear();
        memset(pos,false,sizeof(pos));
        pos[0]=true;

        for (int i=0;i<m;++i)
            for (int j=n;j>=0;--j)
            {
                if (pos[j]  && !pos[ j+ cd[i] ])
                {
                    pos[j+ cd[i] ]=true;
                    arr[ j+ cd[i] ]=arr[j];
                    arr[ j+ cd[i] ].push_back( cd[i] );
                }
            }

        for (int i=n;i>=0;--i)
            if (pos[i])
            {
                for (int j=0;j<arr[i].size();++j)
                    printf("%d ",arr[i][j]);
                printf("sum:%d\n",i);

                break;
            }
    }
    return 0;
}
