#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#define sz 60


#define max(a,b) ((a)>(b))?(a):(b)
#define in(p) (2*(p))
#define out(p) (2*(p)+1)

#define INF 100000000

using namespace std;

int d[sz][sz];

int main(){
    freopen("in.txt","r",stdin);

    int kase;
    string str,str2;
    char c;
    int val;

    scanf("%d",&kase);
    getchar();
    getchar();

    bool last=false;
    for (bool notFirst=false; true;notFirst=true ){

        if (notFirst)
            printf("\n");


        for (int i=0;i<sz;++i){
            for (int j=0;j<sz;++j){
                d[i][j]= -INF;
            }
        }
        int limit=0;

        while (true){

            if (! getline(cin,str) ){
                last=true;
                break;
            }

            if (str.length()==0)break;

            stringstream sstr( str );
            sstr>>c>>val;

            d[ in(c-'A'+1) ][out(c-'A'+1)]=val;
            str2="";
            sstr>>str2;

            for (int i=0;i<str2.length();++i){
                d[ out( str2[i]-'A' +1) ] [ in( c-'A' +1) ]=0;
            }
            if (out( c-'A'+1 )>limit)
                limit=out( c-'A'+1 );
        }

        for (int k=0;k<=limit;++k){
            for (int i=0;i<=limit;++i){
                for (int j=0;j<=limit;++j){
                    d [i] [j] = max (d [i] [j],  d [i] [k]+ d [k] [j]);
                }
            }
        }

        int mx=0;
        for (int i=0;i<sz;++i){
                for (int j=0;j<sz;++j){
                    if (d[i][j]>mx)
                        mx=d[i][j];
                }
        }
        printf("%d\n",mx);

        if (last)return 0;

    }

}
