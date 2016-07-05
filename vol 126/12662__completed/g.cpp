
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

string name[110];

int main(){

    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for (int i=1;i<=n;++i){
        cin>>name[i];
    }

    int x,q;
    cin>>q;

    while ( q-- ){
        cin>>x;
        if ( name[x] != "?" ){
            cout<<name[x]<<endl;
        }else{
            int le=x,ri=x;
            bool onl=false,onr=false;
            string tt,yy;
            while ( !onl && !onr ){
                le--;
                ri++;
                if (le>0 && !onl && name[le] != "?" ){
                    onl=true;
                    tt=name[le];
                }
                if (ri<=n && !onr && name[ri] != "?" ){
                    onr=true;
                    yy=name[ri];
                }
            }

            if ( onl && onr ){
                cout<<"middle of "<<tt<<" and "<<yy<<endl;
            }else if ( onl ){
                for (int i=le;i<x;++i){
                    cout<<"right of ";
                }cout<<tt<<endl;
            }else {
                for (int i=x;i<ri;++i){
                    cout<<"left of ";
                }cout<<yy<<endl;
            }

        }
    }


    return 0;
}
