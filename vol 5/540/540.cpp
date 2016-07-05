#include <cstdio>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

int main()
{

    freopen("in.txt","r",stdin);

    char line[10];
    int team,tmp,a;
    for (int kk=1;true;++kk)
    {
        scanf("%d",&team);
        if (!team)return 0;


        printf("Scenario #%d\n",kk);

        map<int,int> teamno;
        for (int i=0;i<team;++i)
        {
            scanf("%d",&tmp);
            while (tmp--)
            {
                scanf("%d",&a);
                teamno[a]=i;
            }
        }

        queue< queue<int>* > mainq;
        queue <int> *q=new queue <int> [team];
        bool *already=new bool [team];

        memset(already,false,sizeof(already));

        while (true)
        {
            scanf("%s",line);
            if (line[0]=='E')
            {
                scanf("%d",&tmp);

                q[ teamno[tmp] ].push(tmp);

                if(!already[  teamno[tmp] ] )
                {
                    mainq.push( &q[ teamno[tmp] ] );
                    already[ teamno[tmp] ]=true;
                }
            }
            else if (line[0]=='D')
            {
                queue <int> *s=mainq.front();
                tmp=(*s).front();
                printf("%d\n",(*s).front() );
                (*s).pop();


                if ( (*s).empty() )
                {
                    mainq.pop();
                    already [ teamno[tmp] ]=false;
                }
            }
            else if (line[0]=='S')
                break;
        }

        printf("\n");

        delete []q;
        delete []already;
    }
}
