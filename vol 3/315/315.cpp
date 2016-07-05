#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#define sz 110

using namespace std;

vector <int> outarrow[sz];
int node;
bool vis[sz];
int off;

void dfs(int n){
    vis[n]=true;
    for (int i=0;i<outarrow[n].size();++i){
        if (!vis[ outarrow[n][i] ]  && outarrow[n][i]!=off)
            dfs( outarrow[n][i]);
    }
}
bool connected(){
    for (int i=1;i<=node;++i)
        if (!vis[i] && i!=off)
            return false;
    return true;
}

int main(){
    //freopen("in.txt","r",stdin);

    string str;
    int n,tmp;
    while (cin>>node && node){
        for (int i=0;i<=node;++i)
            outarrow[i].clear();
        while (getline(cin,str) && str!="0"){
            stringstream sstr(str);
            sstr>>n;
            while (sstr>>tmp){
                outarrow[n].push_back(tmp);
                outarrow[tmp].push_back(n);
            }
        }

        memset(vis,false,sizeof(vis));
        off=1;
        dfs(2);
        int result=0;
        if ( ! connected() )
            ++result;
        for (int i=2;i<=node;++i){
            memset(vis,false,sizeof(vis));
            off=i;
            dfs(1);
            if ( ! connected() )
                ++result;
        }
        cout<<result<<endl;
    }
    return 0;
}
