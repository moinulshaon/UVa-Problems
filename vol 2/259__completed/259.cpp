#include <cstdio>
#include <cstring>
#include <queue>
#define INF 2147483647
#define sz 50

using namespace std;

int d[sz][sz];
bool vis[sz];
int prvnode[sz];
int nodes=sz;

int leftNode[15];

int bfs(int source,int destination)
{
    memset(vis,false,sizeof(vis));
    memset(prvnode,-1,sizeof(prvnode));

    queue <int> q;
    q.push(source);
    vis[source]=true;

    while (!vis[ destination ] && !q.empty() )
    {
        int tmp=q.front();
        q.pop();

        //printf("%d\n",tmp);

        for (int i=0;i<nodes;++i)
        {
            if (!vis[i] && d[tmp][i]>0 )
            {
                vis[i]=true;
                prvnode[i]=tmp;
                q.push(i);
                if (i==destination){
                    //printf("true\n");
                     break;
                }

            }
        }
    }

    int to=destination,frm,path=INF;
    while (prvnode[to]!=-1)
    {
        frm=prvnode[to];
        if (d[frm][to] < path )
            path=d[frm][to];
        to=frm;
    }
    if (path==INF)return 0;

    to=destination;
    for (int i=0;prvnode[to]!=-1;++i)
    {
        frm=prvnode[to];
        d[frm][to]-=path;
        d[to][frm]+=path;
         if (i%2){
            //printf("%d %d\n",to,frm);
            leftNode[ to -36 ]=frm;
        }

        to=frm;




    }
    return path;

}

int maxflow(int s,int d)
{
    int path=0,perpath;

    while ( perpath=bfs(s,d) )
        path+=perpath;

    return path;
}


int main ()
{

    freopen("in.txt","r",stdin);

    char a;
    char c;
    int source,destination;

    while ( true)
	{
	    memset(d,0,sizeof(d));
	    source=0;
        destination=sz-1;
        memset(leftNode,-1,sizeof(leftNode));

        int sum=0;

	    while (  ( c=getchar() )!='\n' && c!=EOF){


            a=getchar();
            a=a-'0';

            c =c-'A'+1;

            //printf("%d %d %d\n",destination,c,a);

            d[source][ c ]=a;
            sum+=a;

            a=getchar();

            while ( ( a=getchar() )!=';' ){
                a=a-'0'+36;
                d[c][a]=1;
                //printf("%d %d\n",c,a);
            }
            c=getchar();


        }

        for (int i=36;i<46;++i){
            d[i][destination]=1;
        }

        //printf("\nbreak\n");

        if (sum==maxflow(source,destination)){
            for (int i=0;i<10;++i){
                if (leftNode[i]== -1)
                    putchar('_');
                else
                    putchar( leftNode[i]-1+'A' );
            }

        }
        else
            putchar('!');
        putchar('\n');
        if (c==EOF)
            return 0;

    }

    return 0;

}
