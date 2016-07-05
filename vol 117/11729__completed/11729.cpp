#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
    int a,b;
}arr[1005];

bool cmp(const node &x,const node &y)
{
    if (x.b<y.b)return false;
    else return true;
}

int main()
{
    int n,result,save,tmp;

    for (int kk=1;true;++kk)
    {
        scanf("%d",&n);
        if (!n)return 0;

        for (int i=0;i<n;++i)
            scanf("%d %d",&arr[i].a,&arr[i].b);

        sort (arr,arr+n,cmp);

        result=0;
        tmp=0;
        for (int i=0;i<n;++i)
        {
            if (  ( save=( tmp+arr[i].b+arr[i].a ) )>result )
                result=save;
            tmp+=arr[i].a;
        }
        printf("Case %d: %d\n",kk,result);

    }
}
