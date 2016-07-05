#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cnt1[26];
int cnt2[26];

char a[110],b[110];

int main(){
    //freopen("in.txt","r",stdin);
    while ( gets(a) ){
        gets(b);
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
        int len=strlen(a);
        if ( len!=strlen(b) ){
            printf("NO\n");
            continue;
        }
        for (int i=0;i<len;++i){
            cnt1[ a[i]-'A' ]++;
            cnt2[ b[i]-'A' ]++;
        }
        sort(cnt1,cnt1+26);
        sort(cnt2,cnt2+26);
        bool pos=true;
        for (int i=0;i<26;++i){
            if ( cnt1[i] != cnt2[i] ){
                pos=false;
                break;
            }
        }
        if ( pos )printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
