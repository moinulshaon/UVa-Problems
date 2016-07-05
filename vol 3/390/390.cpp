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
#include <cctype>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

int main(){
    FRO


    string str;
    map<string,int> mp[6];

    while ( cin >> str ){
        int n=str.length();

        for (int i=0;i<n;++i){
            str[i]=toupper( str[i] );
        }

        for (int i=0;i<n;++i){
            for(int j=1;j<=5 && (i+j)<=n ;++j  ){
                if ( ! isalnum( str[i+j-1] ) )break;
                mp[j][  str.substr(i,j) ]++;

                //cout<< str.substr(i,j)<<endl;
            }
        }
    }

    vector<string> vv[5000];
    for (int i=1;i<=5;++i){
        printf("Analysis for Letter Sequences of Length %d\n",i);
        printf("-----------------------------------------\n");

        for (int j=0;j<5000;++j){
            vv[j].clear();
        }

        for (map<string,int>::iterator it=mp[i].begin(); it!= mp[i].end();++it){
            vv[ it->second ].PB( it->first );
        }

        int cnt=0;
        for (int j=4999;j>0 && cnt< 5;--j){
            if ( vv[j].size() > 0 ){
                printf("Frequency = %d, Sequence(s) = (",j);
                for (int k=0;k<vv[j].size();++k){
                    if ( k )printf(",");
                    printf("%s",vv[j][k].c_str() );
                }
                printf(")\n");
                cnt++;
            }
        }

        if ( i!= 5 )
        printf("\n");
    }



    return 0;
}
