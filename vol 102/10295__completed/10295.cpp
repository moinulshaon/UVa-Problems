#include <iostream>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);

    long long n,m,a;
    string str;

    while (cin>>n>>m){

        map<string,long long> myp;

        while (n--){
            cin>>str>>a;
            myp[str]=a;
        }

        while (m--){
            long long sum=0;
            while (cin>>str && str!="."){

                if (myp.find(str)!=myp.end())
                    sum+=myp[str];

            }
            cout<<sum<<endl;

        }

    }
    return 0;

}
