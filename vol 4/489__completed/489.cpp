#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;


int main(){
    int kase;
    string str,user;
    int freq[26];
    while (cin>>kase && kase!=-1){
        getchar();
        getline(cin,str);
        getline(cin,user);
        int fault=0;



        int len=str.length();
        memset(freq,0,sizeof(freq));

        for (int i=0;i<len;++i)
            freq[ str[i]-'a' ]++;
        int len2=user.length();

        for (int i=0;i<len2 && fault!=7 && len;++i){
            if (freq[ user[i] -'a']){
                len-=freq[ user[i] -'a'];
                freq[ user[i] -'a']=0;
            }
            else{
                fault++;
            }
        }
        printf("Round %d\n",kase);
        if (!len){
            printf("You win.\n");
        }
        else if (fault==7){
            printf("You lose.\n");
        }
        else {
            printf("You chickened out.\n");
        }
    }
    return 0;
}
