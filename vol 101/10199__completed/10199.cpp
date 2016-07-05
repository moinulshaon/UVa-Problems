#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define sz 110

using namespace std;
int node,edge,off;
vector<int> outarrow[sz];
bool vis[sz];


void DFS(int n){
    if (n==off)return ;
    vis[n]=true;
    for (int i=0;i<outarrow[n].size();++i){
        if (!vis[ outarrow[n][i] ] && outarrow[n][i]!=off){
            DFS(outarrow[n][i]);
        }
    }
}

bool connected(){
    for(int i=0;i<node;++i){
        if (!vis[i] && i!=off){
            return false;
        }
    }
    return true;
}

int parent[sz];

int find(int x)
{
    if (parent[x]==x)
        return x;
    else
        return parent[x]=find(parent[x]);
}



int main(){

    freopen("in.txt","r",stdin);

    string ss1,ss2;
    for (int kk=1;cin>>node && node;++kk){

        if (kk!=1)
            cout<<'\n';

        map<string,int> ind;
        map<int,string> rmyp;
        for (int i=0;i<node;++i)
            parent[i]=i;

        for (int i=0;i<node;++i)
            outarrow[i].clear();

        for (int i=0;i<node;++i){
            cin>>ss1;
            ind[ss1]=i;
            rmyp[i]=ss1;
        }
        cin>>edge;
        while (edge--){
            cin>>ss1>>ss2;

            outarrow[ ind[ss1] ].push_back( ind[ss2] );
            outarrow[ ind[ss2] ].push_back( ind[ss1] );

            int tx=find( ind[ss1] );
            int ty=find( ind[ss2] );

            if (tx!=ty)
            {
                parent[ty]=parent[tx];
            }
        }

        vector<string> result;

        for(int i=0;i<node;++i){
            off=i;
            memset(vis,false,sizeof(vis));

            for (int j=0;j<node;++j){
                if (find(j)==j){
                    if (j!=off)
                        DFS(j);
                    else if (outarrow[j].size()>0)
                        DFS(outarrow[j][0]);

                }
            }

            if (!connected())
                result.push_back( rmyp[off]);
        }

        sort(result.begin(),result.end());
        printf("City map #%d: %d camera(s) found\n",kk,result.size());
        for(int i=0;i<result.size();++i){
            cout<<result[i]<<endl;
        }

    }
    return 0;
}
