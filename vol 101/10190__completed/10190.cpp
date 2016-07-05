#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    while (scanf("%d %d",&n,&m)==2)
    {
        if (m==1 || m==0 || n==0 || n==1)
            printf("Boring!\n");
        else
        {
            vector <int> v;
            while (n%m==0 && n!=1)
            {
                v.push_back(n);
                n=n/m;
            }
            if (n==1)
            {
                int tmp=v.size();
                if (tmp>0)
                    printf("%d",v[0]);
                for (int i=1;i<tmp;++i)
                    printf(" %d",v[i]);
                if (tmp>0)
                    printf(" 1\n");
            }
            else
               printf("Boring!\n");
        }
    }
    return 0;
}
