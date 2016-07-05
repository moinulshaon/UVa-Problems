
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

struct tt{
    int last,teamid;
}ans[110];

bool vis[110][100];

int main(){
    //FRO

    ios_base::sync_with_stdio( false );

    NEG(ans);

    int problem,team,sub;

    cin>>problem>>team>>sub;

    int clk,id;
    char pp;
    string str;

    while ( sub-- ){
        cin>>clk>>id>>pp>>str;
        if ( str== "Yes"  && !vis[ id ][ pp-'A' ] ){

            vis[ id ][ pp-'A' ]=true;

            ans[ pp -'A' ].last=clk;
            ans[ pp-'A' ].teamid=id;

        }
    }


    for (int i=0;i<problem;++i){
        cout<<char( i+'A' )<<' ';
        if ( ans[i].teamid == -1 ){
            cout<<"- -\n";
        }else{
            cout<<ans[i].last<<' '<<ans[i].teamid<<endl;
        }
    }

    return 0;
}
