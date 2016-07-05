#include <cstdio>
#include <queue>
#define positive(a) (a)<0?-(a):a

using namespace std;



int main()
{
    int test,n,t,m;
    char line[10];
    scanf("%d",&test);

    while (test--)
    {
        scanf("%d %d %d",&n,&t,&m);

        queue <int> ql,qr;

        int templ,tempr;
        while (m--)
        {
            scanf("%d %s",&templ,line);

            if (line[0]=='l')
                ql.push(templ);
            else
                qr.push(templ);

        }

        int start=0,prv=0;
        char pos='l';
        while (! (qr.empty()&& ql.empty()) )
        {
            if (!ql.empty())
                templ=ql.front();
            else
                templ=1000000;
            if (!qr.empty())
                tempr=qr.front();
            else
                tempr=1000000;

            printf("%d l::%d r::%d %c\n",start,templ,tempr,pos);

            if (pos=='l')
            {
                if (tempr<templ)
                {
                    start+=positive(tempr-start)+t;
                    pos='r';
                }
                else
                {
                    start+=positive(templ-start);
                    for (int i=0;!ql.empty() && ql.front()<=start && i<n;++i)
                    {
                        ql.pop();
                        printf("%d %d\n",start,start+t);
                    }
                    start+=t;
                    pos='r';

                }

            }
            else
            {
                if (templ<=tempr)
                {

                    start+=positive(templ-start)+t;
                    pos='l';
                }
                else
                {
                    start+=positive(tempr-start);

                    for (int i=0;!qr.empty() && qr.front()<=start && i<n ;++i)
                    {
                        qr.pop();
                        printf("%d %d\n",start,start+t);
                    }
                    start+=t;
                    pos='l';

                }
            }

        }




    }
}
