#include <iostream>
//06
#include <cstdio>
//07
#include <algorithm>
//08
#include <cstring>
//09
#include <string>
//10
#include <cctype>
//11
#include <stack>
//12
#include <queue>
//13
#include <list>
//14
#include <vector>
//15
#include <map>
//16
#include <sstream>
//17
#include <bitset>
//18
#include <utility>
//19
#include <set>
//20
#define pi acos(-1.0)
//21
#define N 1000000
//22
using namespace std;
//23

//24
bool matrix [30 + 3] [30 + 3];
//25

//26
void reset ()
//27
{
//28
    for ( int i = 0; i < 33; i++ )
//29
        memset (matrix [i], false, sizeof (matrix [i]));
//30
}
//31

//32
int main ()
//33
{
//34
	 freopen("input.txt","r",stdin);
    int edges;
//35
    int cases = 0;
//36

//37
    while ( cin >> edges && edges ) {
//38
map<int,int> index;
        /*reset ();
//39

//40
        map <int, int> index;
//41
        int nodeNumber = 1;
//42

//43
        for ( int i = 0; i < edges; i++ ) {
//44
            int a, b;
//45
            cin >> a >> b;
//46
            if ( !index [a] ) index [a] = nodeNumber++;
//47
            if ( !index [b] ) index [b] = nodeNumber++;
//48

//49
            matrix [index [a]] [index [b]] = matrix [index [b]] [index [a]] = true;
//50
        }*/

        bool matrix[35][35];
        for (int i=0;i<35;++i)
            for(int j=0;j<35;++j)
                matrix[i][j]=false;

        //scanf("%d",&edges);

        if (!edges)return 0;

        int nodeNumber=1;
        for(int i=0;i<edges;++i)
        {
            int a,b;

            cin>>a>>b;

            if (!index[a]) index[a]=nodeNumber++;
            if (!index[b]) index[b]=nodeNumber++;

            matrix[ index[a] ][ index[b] ]=matrix[ index[b] ][ index[a] ]=true;

        }


//51

//52
        int queryNode;
//53
        int ttl;
//54
        int dist [30 + 3];
//55

//56
        while ( cin >> queryNode >> ttl ) {
//57
            if ( queryNode == 0 && ttl == 0 ) break;
//58

//59
            memset (dist, -1, sizeof (dist));
//60

//61
            dist [index [queryNode]] = 0;
//62

//63
            /*queue <int> q;
//64
            q.push (index [queryNode]);
//65

//66
            while ( !q.empty () ) {
//67
                int pop = q.front ();
//68
                q.pop ();
//69

//70
                for ( int i = 1; i < nodeNumber; i++ ) {
//71
                    if ( matrix [pop] [i] && dist [i] == -1 ) {
//72
                        dist [i] = dist [pop] + 1;
//73
                        q.push (i);
//74
                    }
//75
                }
//76
            }*/
            queue <int> q;

            q.push(index[queryNode]);
            while(!q.empty())
            {
                int temp=q.front();
                q.pop();

                for (int i=1;i<nodeNumber;++i)
                {
                    if (dist[i]==-1 && matrix[temp][i])
                    {
                        dist[i]=dist[temp]+1;
                        q.push(i);
                    }
                }
            }
//77

//78
            int cnt = 0;
//79

//80
            for (int i=1;i<nodeNumber;++i)
                if (dist[i]==-1 || dist[i]>ttl)
                    ++cnt;
                    //printf("%d ",dist[i]);
            //printf("\n");
//83

//84
            printf ("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
//85
                    ++cases, cnt, queryNode, ttl);
//86
        }
//87
    }
//88

//89
    return 0;
//90
}
