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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

string str[10];

int main(){
    //FRO

    ios_base::sync_with_stdio( false );

    int n;
    cin>>n;

    for (int i=0;i<5;++i){
        cin>>str[i];
    }

    map<string ,int >mp;

    mp[ ".*...*...*...*...*.." ]=1;
    mp[ "***...*.***.*...***." ]=2;
    mp[ "***...*.***...*.***." ]=3;

    for (int i=0;i<n;++i){
        cout<< mp[ str[0].substr( i*4,4 )+str[1].substr( i*4,4 )+
        str[2].substr( i*4,4 )+str[3].substr( i*4,4 )+str[4].substr( i*4,4 )  ];
        /*cout<<str[0].substr( i*4,4 )+str[1].substr( i*4,4 )+
        str[2].substr( i*4,4 )+str[3].substr( i*4,4 )+str[4].substr( i*4,4 )<<endl;*/
    }
    cout<<endl;





    return 0;
}
