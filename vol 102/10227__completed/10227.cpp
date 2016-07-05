#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    freopen("in.txt","r",stdin);

    int kase,n,a,b;
    scanf("%d",&kase);
    getchar();
    getchar();
    string str;


    while (kase--){
        scanf("%d %d",&n,&b);
        getchar();

        set<int> arr[110];

        while (getline(cin,str) && str.length()){
            stringstream sstr(str);
            sstr>>a>>b;

            arr[a-1].insert(b);
        }
        set< set<int> >vset;
        for (int i=0;i<n;++i){
            vset.insert(arr[i]);
        }


        printf("%d\n",vset.size());
        if (kase)
            printf("\n");
    }
    return 0;

}
