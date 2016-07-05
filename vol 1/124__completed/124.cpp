#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int total;

bool mat[50][50];
bool copymat[50][50];
bool vis[50];

vector<string> result;
vector<char> rmyp;

void clearOut(int n){

    for (int i=0;i<total;++i){
        mat[n][i]=false;
    }

}
bool nothingIn(int n){
    for (int i=0;i<total;++i){
        if (mat[i][n])
            return false;
    }
    return true;
}

void copysaved(int n){
    for (int i=0;i<total;++i){
        mat[n][i]=copymat[n][i];
    }
}

void recursion(string str,int alreadyvis){


    if (alreadyvis==total){
        result.push_back(str);
        return ;
    }

    for (int i=0;i<total;++i){
        if (!vis[i] && nothingIn(i)){

            clearOut(i);
            vis[i]=true;

            recursion(str+rmyp[i],alreadyvis+1);

            copysaved(i);
            vis[i]=false;
        }
    }

}


int main(){

    string str;
    char ca,cb;

    for (bool on=false;getline(cin,str);on=true){

        if (on){
            cout<<'\n';
        }

        stringstream sstr(str);

        map<char,int> myp;
        rmyp.clear();


        result.clear();

        total=0;

        while (sstr>>ca){
            rmyp.push_back(ca);
            myp[ca]=total++;
        }

        getline(cin,str);
        stringstream sstr2(str);

        memset(mat,0,sizeof(mat));
        memset(copymat,0,sizeof(copymat));
        memset(vis,0,sizeof(vis));

        while (sstr2>>ca>>cb){
            mat[ myp[ca] ][ myp[cb] ]=true;
            copymat[ myp[ca] ][ myp[cb] ]=true;
        }

        recursion("",0);

        sort(result.begin(),result.end());

        for (int i=0;i<result.size();++i){
            cout<<result[i]<<endl;
        }

    }
    return 0;

}
