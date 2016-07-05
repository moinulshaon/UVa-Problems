#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#define sz 11000
#define color 8
#define INF 100000000

using namespace std;

vector<int> outarrow[sz];

bool vis[sz][color];
int dp[sz][color];


int DFS( int n,int on,int prvnode){
    if (vis[n][on]) return dp[n][on];

    int thisColor;
    int result=INF;
    for (int c=color-1;c>0;--c){
        if (c!=on){
            /*if (result==INF)
                thisColor=c;*/
            int sum=0;
            for (int i=0; i<outarrow[n].size();++i){
                if ( outarrow[n][i]!=prvnode ){
                    sum+=DFS( outarrow[n][i] , c , n);
                }
            }
            if ( sum+c < result){
                result=sum+c;
                thisColor=c;
            }
        }
    }
    if (result==INF)result=0;

    //printf("%d %d %d %d\n",n,on,thisColor,result);
    vis[n][on]=true;
    return dp[n][on]=result;


}

int main(){
    freopen("in.txt","r",stdin);

    int total;
    char cc;
    int a,b;
    string str;

    while (scanf("%d",&total)==1 && total){
        getchar();


        for (int i=0;i<=total;++i){
            outarrow[i].clear();
        }
        while ( getline(cin,str) && str.length()!=0 ){
            stringstream sstr(str);

            sstr>>a>>cc;

            while (sstr>>b){

                outarrow[a].push_back(b);
                outarrow[b].push_back(a);
            }

        }
        int result=INF;

        memset(vis , false,sizeof(vis) );

        result=min( result, DFS( 0 , 0 , -1) );


        printf("%d\n",result);

    }
    return 0;

}
