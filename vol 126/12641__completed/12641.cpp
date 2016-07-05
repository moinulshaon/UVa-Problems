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
#include <sstream>

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

    ios_base::sync_with_stdio(false);

    int kase;
    string str;
    getline(cin,str);
    stringstream tt(str);
    tt>>kase;

    while (kase--){
        getline(cin,str);
        stringstream ss(str);

        map<string,string> mp;

        string save;
        while ( ss>>str ){
            save=str;

            if ( str.length()>1 )
                sort( str.begin()+1,str.end()-1 );
            if ( mp.find(str)==mp.end() ){
                mp[ str ]=save;
            }else{
                mp[ str ]=min(mp[ str ],save);
            }
        }


        getline(cin,str);
        stringstream ss2(str);


        for (bool on=false; ss2>>str ;on=true ){
            if ( on )cout<<' ';
            save=str;

            if ( str.length()>1 )
                sort( str.begin()+1,str.end()-1 );
            if ( mp.find(str)==mp.end() ){
                cout<<save;
            }else{
                cout<<mp[str];
            }
        }
        cout<<endl;
    }


    return 0;
}
