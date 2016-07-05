#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;


string str[10] = {
	 ".***.." ,
	 "*....." ,
	 "*.*..." ,
	 "**...." ,
	 "**.*.." ,
	 "*..*.." ,
	 "***..." ,
	 "****.." ,
	 "*.**.." ,
	 ".**..." ,
};

char in[10010];

char dig[10010][15];

int main(){

    FRO

    int len;
    while ( scanf("%d",&len)==1 && len ){
        char query[5];
        scanf("%s",query);

        if ( query[0] == 'S' ){
            scanf("%s",in);
            for (int line=0;line<3;++line){
                for (int i=0;in[i];++i){
                    if ( i )printf(" ");
                    for (int j=0;j<2;++j){
                        printf("%c",str[ in[i]-'0' ][2*line+j]);
                    }
                }
                printf("\n");
            }
        }else{
            for (int i=0;i<len;++i){
                dig[i][0] = '\0';
            }
            for (int line = 0;line<3;++line){
                for (int i=0;i<len;++i){
                    scanf("%s",in);
                    strcat( dig[i],in );
                }
            }
            for (int i=0;i<len;++i){

                for (int j=0;j<10;++j){
                    if ( strcmp( dig[i],str[j].c_str() )==0 ){
                        printf("%d",j);
                        break;
                    }
                }
            }printf("\n");
        }
    }


    return 0;
}
