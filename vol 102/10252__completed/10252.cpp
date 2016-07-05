#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define SIZE 10000

char str1[SIZE],str2[SIZE];
int cnt[2][26];

int main(){

    while( gets(str1) && gets(str2) ){

        int len1=strlen(str1);
        int len2=strlen(str2);

        memset( cnt,0,sizeof(cnt) );

        for (int i=0;i<len1;++i){
            cnt[0][ str1[i]-'a' ]++;
        }
        for (int i=0;i<len2;++i){
            cnt[1][ str2[i]-'a' ]++;
        }

        for (int i=0;i<26;++i){
            for (int j=min(cnt[0][i],cnt[1][i]);j>0;--j){
                printf("%c",i+'a');
            }
        }
        printf("\n");
    }
    return 0;
}
