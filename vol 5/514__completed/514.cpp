#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;


int main()
{
    bool found;
    int n, i, val;
    while (true)
    {
        scanf("%d",&n);
        if (!n)return 0;

        while (true)
        {
            scanf("%d",&val);
            if (!val)
            {
                printf("\n");
                break;
            }

            stack<int> b;
            stack<int> s;


            b.push(val);
            for (i=1 ; i<n ; i++)
            {
                scanf("%d",&val);
                b.push(val);
            }

            for (i=n, found=true ; i>=1 && found ; i--)
            {
                if (!s.empty() && i==s.top())
                {
                    s.pop();
                    continue;
                }
                while (true)
                {
                    if (!b.empty() && i!=b.top())
                    {
                        val = b.top();
                        s.push(val);
                        b.pop();
                        found=false;
                    }

                    else if (!b.empty() && i==b.top())
                    {
                        b.pop();
                        found=true;
                        break;
                    }

                    else {
                        found=false;
                        break;
                    }
                }
            }

            if (found) printf("Yes\n");
            else printf("No\n");
        }

    }
    return 0;

}
