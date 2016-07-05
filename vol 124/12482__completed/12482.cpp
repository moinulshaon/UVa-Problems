#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


int main(){
    //freopen("in.txt","r",stdin);
    int n,l,c;

    while ( cin>>n>>l>>c ){
        //cout<<n<<l<<c<<endl;
        string str;
        cin>>str;
        int cntchar=str.length(),cntline=1;
        for (int i=1;i<n;++i){
            cin>>str;

            if ( cntchar+str.length()+1 <= c ){
                cntchar+=str.length()+1;
            }else{
                cntchar=str.length();
                cntline++;
            }
        }
        //cout<<cntline<<endl;
        if ( cntline %l ==0 ){
            cout<<cntline/l<<endl;
        }else{
            cout<<cntline/l+1<<endl;
        }
    }
    return 0;
}
