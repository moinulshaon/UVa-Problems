#include <cstdio>
#include <cstring>
#include <cmath>

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>

using namespace std;

typedef long long LL;
typedef pair<int,int> pint;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define SIZE 100100

char line[SIZE],rightstk[SIZE];


int main(){
    FRO

    while(gets(line)){
        int len=strlen(line);

        bool insertrightstk=true;
        int prightstk=0;
        pint tmp;
        vector< pint > v;
        for (int i=0;;++i){

            if ( line[i]=='[' ){
                if ( !insertrightstk ){
                    tmp.second=i-1;
                    v.PB( tmp );
                }
                insertrightstk=false;
                tmp.first=i+1;
            }else if (line[i]==']'){
                if ( !insertrightstk ){
                    insertrightstk=true;
                    tmp.second=i-1;
                    v.push_back( tmp );
                }
            }else if (line[i]=='\0' ){
                if ( !insertrightstk ){
                    tmp.second=i-1;
                    v.push_back( tmp );
                }
                break;
            }else{
                if ( insertrightstk ){
                    rightstk[prightstk++]=line[i];
                }
            }
        }

        rightstk[prightstk++]='\0';

        int sz=v.size();

        for (int i=sz-1;i>=0;--i){
            tmp=v[i];
            for (int j=tmp.first;j<=tmp.second;++j){
                putchar( line[j] );
            }
        }

        puts(rightstk);
    }

    return 0;
}
