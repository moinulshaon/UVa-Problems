#include <cstdio>
#include <cmath>
#include <vector>
#define siz 10101


using namespace std;

int sum[siz];
bool prime[siz];
vector <int> p;

int main()
{
    for (int i=2;i<siz;++i)
        prime[i]=true;
    for (int i=2;i<=100;++i)
        if (prime[i])
            for (int j=2*i;j<siz;j+=i)
                prime[j]=false;
    for (int i=2;i<siz;++i)
        if (prime[i])
            p.push_back(i);
    int s=0;
    for (int i=0 ; i<p.size() ; ++i)
    {
        s+=p[i];
        if (s<siz)
            ++sum[s];
        int save=s;
        for (int j=0 ; p[j]<=p[i] ; ++j)
        {
            save-=p[j];
            if (save>0 && save<siz)
                ++sum[save];
        }
    }
    int in;
    while (true)
    {
        scanf("%d",&in);
        if (!in)return 0;
        printf("%d\n",sum[in]);
    }

}
