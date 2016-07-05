#include <iostream>
#include <string>

using namespace std;

string str;
int n;

bool fun(string s){

    int a=s.length();

    for (int i=0;i<n;i+=a){

        //cout<<s<<' '<<str.substr(i,a)<<endl;

        if ( str.substr(i,a)!=s )
            return false;

    }
    return true;


}


int main(){

    int kase;
    cin>>kase;



    while (kase--){

        cin>>str;
        n=str.length();
        for (int i=1;i<=n;++i){

            //cout<<str.substr(0,i)<<endl;

            if ( fun( str.substr(0,i) ) ){
                cout<<i<<endl;
                break;
            }
            //cout<<endl;
        }
        if (kase)cout<<endl;

    }
    return 0;

}
