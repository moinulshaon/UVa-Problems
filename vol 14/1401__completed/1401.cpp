#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

struct NODE{
    bool finish;
    //int words;
    //int prefix;
    NODE* edge[26];
    NODE(){
        //words=prefix=0;
        for (int i=0;i<26;++i){
            edge[i]=NULL;
        }
        finish=false;
    }
    ~NODE(){
        for (int i=0;i<26;++i){
            if ( edge[i]!=NULL ){
                delete edge[i];
            }
        }
    }
}*root;

void add(NODE *v,char* word){
    //printf("%s\n",word);
    if ( word[0]=='\0' ){
        v->finish=true;;
    }else{
        //v->prefix++;
        if ( v->edge[ word[0]-'a' ]== NULL ){
            v->edge[ word[0]-'a' ]=new NODE();
        }
        add(v->edge[ word[0]-'a' ],word+1);
    }
}

bool find( NODE *v,char *word,int depth ){
    if ( depth==0 )return v->finish;

    if ( v->edge[ word[0]-'a' ]==NULL ){
        return false;
    }else{
        return find( v->edge[ word[0]-'a' ] , word+1,depth-1 );
    }
}

#define SIZE 300100
char line[SIZE];
char small[110];
int dp[SIZE];

const int mod=20071027;
int main(){
    freopen("in.txt","r",stdin);
    for(int kk=1;scanf("%s",line)!=EOF;++kk){

        root=new NODE();

        int n;
        scanf("%d",&n);

        while(n--){
            scanf("%s",small);
            add(root,small);
        }

        int len=strlen(line);
        dp[len]=1;
        for (int i=len-1;i>=0;--i){
            dp[i]=0;

            for (int j=i;j<len && j-i+1<101 ;++j){
                //printf("%d %d %d %s\n",i,j,j-i+1,&line[i]);
                if ( find( root, &line[i],j-i+1 ) ){
                    dp[i]=(dp[i]+dp[j+1])%mod;
                    //printf("yes\n");
                    //printf("shaon %d %d\n",i,j);
                }
            }
            //printf("%d\n",dp[i]);
        }
        printf("Case %d: %d\n",kk,dp[0]);

        delete root;
    }
    return 0;
}
