#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>

using namespace std;

int failure[510000];

char encrypt[510000],plain[51000];
int len,sublen;

bool Morris_Pratt()
{
    if (sublen > len) return false;


    for (int i=1, j=failure[0]= -1; i<sublen; ++i){
        while (j >= 0 && plain[j+1] != plain[i])
            j = failure[j];
        if (plain[j+1] == plain[i]) j++;
        failure[i] = j;
    }

    char ss=0;
    for (int i=0, j=-1; i<len; ++i){

        while (j >= 0 && plain[j+1] != encrypt[i])
            j = failure[j];

        if (plain[j+1] == encrypt[i]) j++;


        if (j == sublen-1){
            ss++;
            if ( ss>1 )return false;
            j = failure[j];
        }
    }
    if ( ss==1 )return true;
    else return false;
}

int main(){
    freopen("in.txt","r",stdin);
    int kase;


    char alpha[100];

    gets(alpha);
    sscanf(alpha,"%d",&kase);

    while(kase--){
        gets(alpha);

        map<char,char> mp;

        int ll=strlen(alpha);

        for (int i=0;i<ll-1;++i){
            mp[ alpha[i] ]=alpha[i+1];
        }
        mp[ alpha[ll-1] ]= alpha[0];


        gets(plain);
        gets(encrypt);

        len=strlen(encrypt);
        sublen=strlen(plain);

        vector<int> rr;

        for (int i=0;i<ll;++i){

            if( Morris_Pratt(  ) ){
                rr.push_back(i);
            }

            for (int j=0;j<sublen;++j){
                plain[j]=  mp[ plain[j] ];
            }

        }
        if ( rr.size()==0 ){
            printf("no solution\n");
        }else if ( rr.size()==1 ){
            printf("unique: %d\n",rr[0]);
        }else{
            printf("ambiguous:");
            for (int i=0;i<rr.size();++i){
                printf(" %d",rr[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
