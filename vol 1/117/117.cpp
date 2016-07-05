#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int mat[30][30];

vector<int> outarrow[30];
vector<int> weight[30];

int edgeCnt;
int result;

void calc(int n,int sum,int edgeVisited){
    cout<<"n: "<<char(n+'a')<<" "<<sum<<endl;
    if (edgeVisited==edgeCnt){
        if (sum<result)
            result=sum;
        return ;
    }

    for (int i=0; i<outarrow[n].size() ; ++i ){

        if ( mat[n][ outarrow[n][i] ]  ){

            if ( outarrow[ outarrow[n][i] ].size()%2 == 0 ){
                mat[n][ outarrow[n][i] ]=mat[ outarrow[n][i] ][n]=0;

                calc( outarrow[n][i],sum+weight[n][ i ] ,edgeVisited+1 );

                mat[n][ outarrow[n][i] ]=mat[ outarrow[n][i] ][n]=weight[n][i];

            }
            else{
                mat[n][ outarrow[n][i] ]=mat[ outarrow[n][i] ][n]=0;
                calc( n,sum+2*weight[n][i],edgeVisited+1 );
            }


        }

    }

}


int main(){

    freopen("in.txt","r",stdin);


    string str;

    int start;

    while (cin>>str){
        result=100000000;
        memset(mat,0,sizeof(mat));
        for (int i=0;i<30;++i){
            outarrow[i].clear();
            weight[i].clear();
        }
        edgeCnt=0;

        start=str[0]-'a';

        mat[ str[0]-'a' ][ str[ str.length()-1 ]-'a' ]=mat[ str[ str.length()-1 ]-'a' ][ str[0]-'a' ]=str.length();

        outarrow[ str[0]-'a' ].push_back(  str[ str.length()-1 ]-'a'  );
        weight[ str[0]-'a' ].push_back( str.length() );

        outarrow[ str[ str.length()-1 ]-'a' ].push_back(  str[0]-'a'  );
        weight[ str[ str.length()-1 ]-'a' ].push_back( str.length() );

        ++edgeCnt;

        while (cin>>str && str!="deadend"){
            mat[ str[0]-'a' ][ str[ str.length()-1 ]-'a' ]=mat[ str[ str.length()-1 ]-'a' ][ str[0]-'a' ]=str.length();

            outarrow[ str[0]-'a' ].push_back(  str[ str.length()-1 ]-'a'  );
            weight[ str[0]-'a' ].push_back( str.length() );

            outarrow[ str[ str.length()-1 ]-'a' ].push_back(  str[0]-'a'  );
            weight[ str[ str.length()-1 ]-'a' ].push_back( str.length() );

            ++edgeCnt;
        }

        calc( start , 0 ,0);
        cout<<result<<endl;

    }

}
