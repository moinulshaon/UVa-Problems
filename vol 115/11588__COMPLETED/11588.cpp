#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;


int main(){
    int kase;
    cin>>kase;
    char c;
    int letter[26];

    for (int kk=1;kase--;++kk){
        int row,col,n,m;
        cin>>row>>col>>n>>m;

        memset(letter,0,sizeof(letter));
        int tmp=row*col;
        for (int i=0;i<tmp;++i){
            cin>>c;
            letter[c-'A']++;
        }
        int mx=0;
        for (int i=0;i<26;++i)
            if (letter[i]>mx)
                mx=letter[i];
        int cnt=0;
        for (int i=0;i<26;++i)
            if (letter[i]==mx)
                cnt++;
        int result=mx*cnt*n+(tmp-mx*cnt)*m;
        printf("Case %d: %d\n",kk,result);
    }
    return 0;

}
