#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int n;

int cmp(string& t, string& p)
{

    for (int i=0;i<n;++i){
        //cout<<t.substr(i,n-i) <<' '<< p.substr(0,n-i)<<endl;
        if ( t.substr(i,n-i) == p.substr(0,n-i) ){
            return n-i;
        }

    }
    return 0;

}

int main(){

    int kase;
    scanf("%d",&kase);
    int word;

    string arr[110];

    while (kase--){
        cin>>n>>word;

        for (int i=0;i<word;++i){
            cin>>arr[i];
        }
        int result=word*n;

        for (int i=1;i<word;++i){
            result-= cmp(arr[i-1],arr[i]);
        }
        cout<<result<<endl;
    }
    return 0;

}
