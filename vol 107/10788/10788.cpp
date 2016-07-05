#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

bool vis[30][110];

int main(){

    freopen("in.txt","r",stdin);

    int kase;
    cin>>kase;
    string str;

    for (int kk=1;kase--;++kk){
        cin>>str;
        vector<char> stk;
        bool unique=true;

        memset(vis,0,sizeof(vis));

        for (int i=0;i<str.length();++i){

            if (vis[ str[i]-'a' ][stk.size()]){
                    unique=false;
            }
            vis[ str[i]-'a' ][stk.size()]=true;

            if (stk.size()==0){
                stk.push_back( str[i] );
            }else if ( stk.back() == str[i] ){
                stk.pop_back();
            }else {
                stk.push_back(str[i]);
            }
            //printf("%d %c %c\n",stk.size(),stk.back(),str[i]);
        }

        printf("Case %d: ",kk);
        if (stk.size()!=0){
            printf("Invalid\n");
        }else{
            if (unique){
                printf("Valid, Unique\n");
            }else{
                printf("Valid, Multiple\n");
            }

        }
    }
    return 0;

}
