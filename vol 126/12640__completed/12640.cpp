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

    string str;
    while ( getline(cin,str) ){
        istringstream  ss(str);

        int ans=0,sum=0;
        int tmp;
        while ( ss>>tmp ){

            sum+=tmp;

            if (  sum<0 ){
                sum=0;
            }

            if ( sum>ans ){
                ans=sum;
            }


        }
        cout<<ans<<endl;
    }


    return 0;
}
