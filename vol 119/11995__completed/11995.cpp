#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>

using namespace  std;

int main()
{

    freopen("in.txt","r",stdin);

    int operation;

    while (scanf("%d",&operation)==1)
    {
        int a,b;
        queue <int> q;
        stack<int> stk;
        priority_queue<int> pq;
        bool isq=true,iss=true,ispq=true;
        while (operation--)
        {
            scanf("%d %d",&a,&b);

            if (a==1)
            {
                q.push(b);
                pq.push(b);
                stk.push(b);
            }
            else if (a==2)
            {
                if (!q.empty())
                {
                    if ( b!=q.front() )
                        isq=false;
                    q.pop();
                }
                else
                    isq=false;

                if (!pq.empty())
                {
                    if (b!=pq.top())
                        ispq=false;
                    pq.pop();
                }
                else
                    ispq=false;

                if (!stk.empty())
                {
                    if (b!=stk.top())
                        iss=false;
                    stk.pop();
                }
                else
                    iss=false;

            }
        }
        if ((iss+isq+ispq)==0)
            printf("impossible\n");
        else if (iss+isq+ispq>1)
            printf("not sure\n");
        else if (iss)
            printf("stack\n");
        else if (isq)
            printf("queue\n");
        else if (ispq)
            printf("priority queue\n");
    }
    return 0;
}
