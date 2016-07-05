#include <cstdio>


using namespace std;


int arr[100];
int main()
{
    int kase;
    scanf("%d",&kase);

    int n,p,q;
    for (int kk=1;kk<=kase;++kk)
    {
        scanf("%d %d %d",&n,&p,&q);
        for (int i=0;i<n;++i)
            scanf("%d",&arr[i]);
        int sum=0,cnt=0;

        for (int i=0;i<n && sum<q && cnt<p;++i)
        {
            sum+=arr[i];
            if (sum>q )
                break;
            ++cnt;
        }
        printf("Case %d: %d\n",kk,cnt);
    }
    return 0;
}
