#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

int mat[5][5]={
    {0,1,1,0,1},
    {1,0,1,0,1},
    {1,1,0,1,1},
    {0,0,1,0,1},
    {1,1,1,1,0}
};

using namespace std;

vector<string> v;

void start(int n,string str,int vis){

    if (vis==8){
        cout<<str+char(n+1+'0')<<endl;
        v.push_back(str);
        return ;
    }

    for (int i=0;i<5;++i){
        if (mat[n][i]==1){
            ++mat[n][i];
            ++mat[i][n];
            start(i,str+char(n+1+'0'),vis+1 );
            --mat[n][i];
            --mat[i][n];
        }
    }

}


int main(){
    start(0,"",0);
    return 0;
}
