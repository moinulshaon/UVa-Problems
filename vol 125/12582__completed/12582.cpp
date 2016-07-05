#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int cnt[26];

int main(){

    int kase;

    scanf("%d",&kase);

    char line[1000];

    for (int kk=1;kase--;++kk){
        scanf("%s",line);
        int n=strlen(line);

        stack<char> stk;
        memset(cnt,0,sizeof(cnt));
        for (int i=0;i<n;++i){

            if (!stk.empty() && stk.top()==line[i] ){
                stk.pop();
            }else{
                stk.push(line[i]);
            }

            if ( !stk.empty() )
            cnt[ stk.top()-'A' ]++;

        }

        cnt[ line[0]-'A' ]--;

        printf("Case %d\n",kk);

        for (int i=0;i<26;++i){
            if ( cnt[i] )
                printf("%c = %d\n",i+'A',cnt[i]);
        }

    }
    return 0;

}
