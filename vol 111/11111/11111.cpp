#include <cstdio>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;

int absol(int a)
{
    return (a<0)?-a:a;
}

int main()
{

    freopen("in.txt","r",stdin);

    int lval;
    while (scanf("%d",&lval)==1)
    {
        stack <int> stk;

        stk.push(lval);
        bool on=true;
        while ( !stk.empty() )
        {
            int tmp;
            scanf("%d",&tmp);

            if ( absol( tmp) == absol( stk.top() ) )
            {
                stk.pop();

            }
            else if (absol( tmp) > absol( stk.top() ) )
            {
                on=false;
                string ss;
                getline(cin,ss);
                while (!stk.empty())
                    stk.pop();
            }
            else
            {
                stk.push(tmp);
            }
        }
        if (on)
            printf(":-) Matrioshka!\n");
        else
            printf(":-( Try again.\n");
    }
}
