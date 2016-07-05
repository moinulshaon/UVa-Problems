#include <cstdio>
#include <utility>

using namespace std;

int a[50010];
int cnt;

pair < int,int > bsearch(int x){
    int low=-1,high=cnt-1;
    int mid=(low+high)/2;;
    while (low<=high && mid>=0){
        if (a[mid]==x)return make_pair(mid-1,mid+1);
        else if (a[mid]<x)low=mid+1;
        else high=mid-1;
        mid=(low+high)/2;
    }
    return make_pair(mid,mid+1);
}

int main()
{
    int query,q;
    int chimp;
    while (scanf("%d",&chimp)==1)
    {
        cnt=0;
        for (int i=0;i<chimp;++i)
        {
            scanf("%d",&a[cnt]);
            if ( !( cnt && a[cnt]==a[cnt-1] ) )
                ++cnt;
        }
        scanf("%d",&query);
        while (query--)
        {
            scanf("%d",&q);
            pair< int ,int >pos=bsearch(q);

            if (pos.first<0 && pos.second>=cnt)
                printf("X X\n");
            else if (pos.first<0)
                printf("X %d\n",a[pos.second] );
            else if (pos.second>=cnt)
                printf("%d X\n",a[pos.first] );
            else
                printf("%d %d\n",a[pos.first],a[pos.second] );
        }
    }
    return 0;
}
