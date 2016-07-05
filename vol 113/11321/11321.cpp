#include <cstdio>
#include <algorithm>

using namespace std;

struct st
{
    int num,mod;
}arr[11000];

int absolute(int x)
{
    return (x<0)?-x:x;
}

bool cmp(st  a,st b)
{
    if (a.mod>b.mod)
        return false;
    else if (a.mod<b.mod)
        return true;
    else
    {
        int tmpa=absolute(a.num),tmpb=absolute(b.num);
        if (tmpa%2==0 && tmpb%2==0)
        {
            if (a.num>b.num)
                return false;
            else
                return true;
        }
        else if (tmpa%2==0 && tmpb%2==1)
            return false;
        else if (tmpa%2==1 && tmpb%2==0)
            return true;
        else
        {
            if (a.num>b.num)
                return true;
            else
                return false;
        }
    }
}


int main()
{
    int n,m,a;

    //freopen("in.txt","r",stdin);

    while (true)
    {
        scanf("%d %d",&n,&m);
        printf("%d %d\n",n,m);

        if (!n && !m)
            return 0;

        for (int i=0;i<n;++i)
        {
            scanf("%d",&a);
            arr[i].num=a;
            arr[i].mod=a%m;
        }

        stable_sort(arr,arr+n,cmp);

        for (int i=0;i<n;++i)
            printf("%d\n",arr[i].num);
    }

}
