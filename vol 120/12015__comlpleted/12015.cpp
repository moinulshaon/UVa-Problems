#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

struct tt{
    string name;
    int val;
}arr[10];

int main(){
    freopen("in.txt","r",stdin);

    int kase;
    cin>>kase;

    for (int kk=1;kase--;++kk){
        printf("Case #%d:\n",kk);

        for (int i=0;i<10;++i){
            cin>>arr[i].name>>arr[i].val;
        }

        int mx=arr[0].val;

        for (int i=0;i<10;++i){
            if (arr[i].val>mx)
                mx=arr[i].val;
        }

        for (int i=0;i<10;++i){
            if (arr[i].val==mx)
                cout<<arr[i].name<<endl;
        }
    }
    return 0;
}
