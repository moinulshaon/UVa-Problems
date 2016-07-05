#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>


using namespace std;


int main(){

    freopen("in.txt","r",stdin);

    int kase,n;
    cin>>kase;

    string arr[10100];

    while (kase--){

        cin>>n;

        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        sort(arr,arr+n);

        bool on=true;

        for (int i=0;i<n-1;++i){

            if (arr[i]==arr[i+1].substr(0 , arr[i].length() ) ){
                cout<<"NO\n";
                on=false;
                break;
            }

        }
        if (on){
            cout<<"YES\n";
        }

    }
    return 0;

}
