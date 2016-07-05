#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n;

    while (true)
    {
        scanf("%d",&n);
        if (!n)return 0;

        queue <int> q;

        printf("Discarded cards:");

        for (int i=1;i<=n;++i)
            q.push(i);

        while (q.size()>2)
        {

            printf(" %d,",q.front());
            q.pop();

            int tmp=q.front();
            q.pop();
            q.push(tmp);
        }

        if (q.size()==2)
        {
            printf(" %d",q.front());
            q.pop();
        }
        printf("\nRemaining card: %d\n",q.front());
    }

}

