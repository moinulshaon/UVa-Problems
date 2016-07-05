#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#define sz 1100

using namespace std;

map<string,int> myp;
map<int,string> rmyp;

vector <int> outarrow[sz];
bool vis[sz];
int prvnode[sz];
int nodes;


void BFS(int source,int destination)
{
    memset(vis,false,sizeof(vis));

    for (int i=0;i<sz;++i)
        prvnode[i]=-1;

    queue <int> q;
    q.push(source);
    vis[source]=true;

    while (!vis[ destination ] && !q.empty() )
    {
        int tmp=q.front();
        q.pop();


        for (int i=0;i<outarrow[tmp].size();++i)
        {
            if (!vis[  outarrow[tmp][i] ] )
            {
                vis[ outarrow[tmp][i] ]=true;
                prvnode[ outarrow[tmp][i] ]=tmp;
                q.push( outarrow[tmp][i] );
                if (outarrow[tmp][i] ==destination){
                    break;
                }
            }
        }
    }



    if (!vis[destination]){
        printf("No route\n");
        return ;
    };
    int to=destination,frm;
    while (prvnode[to]!=-1)
    {
        frm=prvnode[to];
        cout<<rmyp[to]<<' '<<rmyp[frm]<<endl;
        to=frm;
    }
    return ;

}

int main(){

    freopen("in.txt","r",stdin);

    int edges;
    string a,b;

    for (bool on=false;cin>>edges;on=true){

        if (on)
            printf("\n");

        myp.clear();
        rmyp.clear();

        for (int i=0;i<sz;++i){
            outarrow[i].clear();
        }


        nodes=0;

        while (edges--){
            cin>>a>>b;

            if (myp.find(a)==myp.end()){
                myp[a]=nodes;
                rmyp[nodes++]=a;
            }

            if (myp.find(b)==myp.end()){
                myp[b]=nodes;
                rmyp[nodes++]=b;
            }

            outarrow[ myp[a] ].push_back( myp[b] );
            outarrow[ myp[b] ].push_back( myp[a] );

        }

        cin>>a>>b;

        if (myp.find(a)==myp.end()){
            myp[a]=nodes;
            rmyp[nodes++]=a;
        }

        if (myp.find(b)==myp.end()){
            myp[b]=nodes;
            rmyp[nodes++]=b;
        }

        BFS(myp[b],myp[a]);
    }
    return 0;

}
