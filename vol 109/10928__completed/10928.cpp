#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

int main(){

    freopen("in.txt","r",stdin);

    int kase,n,a;
    scanf("%d",&kase);
    getchar();

    string str;

    while (kase--){
        scanf("%d",&n);
        getchar();

        int size[1100];

        memset(size,0,sizeof(size));

        for (int i=0;i<n;++i){
            getline(cin,str);
            stringstream sstr(str);

            while (sstr>>a){
                size[i]++;
            }
        }

        int mn=100000000;
        for (int i=0;i<n;++i){
            mn=(size[i]<mn)?size[i]:mn;
        }

        bool on=false;
        for (int i=0;i<n;++i){
            if (size[i]==mn && on){
                printf(" %d",i+1);
            }else if (size[i]==mn){
                printf("%d",i+1);
                on=true;
            }
        }
        printf("\n");

        if (kase)getchar();

    }
    return 0;

}
