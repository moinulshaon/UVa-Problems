#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

long long arr[11000];

int main()
{
    vector <long long> v;
    v.push_back(1);
    for (int i=2;i<22;++i)
        v.push_back(pow(i,3));
    arr[0]=1;
    int sz=v.size();
    for (int i=0;i<sz;++i)
            for (int j=1;j<=10000;++j)
                if (j-v[i]>=0)
                    arr[j]+=arr[j-v[i]];
    int in;
    while (scanf("%d",&in)==1)
        printf("%lld\n",arr[in]);
    return 0;
}
