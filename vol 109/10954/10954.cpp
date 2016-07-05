#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    long long n;
    while (true)
    {
        scanf("%lld",&n);
        if (!n)return 0;

        priority_queue <long long,vector <long long> ,greater<long long > > q;
        long long tmp;
        for (int i=0;i<n;++i)
        {
            scanf("%lld",&tmp);
            q.push(tmp);
        }
        long long result=0;
        while( !q.empty() )
        {

            long long tmp=0;
            long long a=q.top();
            q.pop();
            if ( !q.empty() )
            {
                long long b=q.top();
                q.pop();
                result+=a+b;
                q.push(a+b);
            }
        }
        printf("%lld\n",result);
    }
}
