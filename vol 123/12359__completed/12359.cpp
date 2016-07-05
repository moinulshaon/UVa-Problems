#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

struct NODE{
    //int words;
    //int prefix;
    NODE* edge[26];
    NODE(){
        //words=prefix=0;
        for (int i=0;i<26;++i){
            edge[i]=NULL;
        }
    }
    ~NODE(){
        for (int i=0;i<26;++i){
            if ( edge[i]!=NULL ){
                delete edge[i];
            }
        }
    }
}*pre,*suff;

void add(NODE *v,char* word){
    //printf("%s\n",word);
    if ( word[0]=='\0' ){
        //v->words++;
    }else{
        //v->prefix++;
        if ( v->edge[ word[0]-'a' ]== NULL ){
            v->edge[ word[0]-'a' ]=new NODE();
        }
        add(v->edge[ word[0]-'a' ],word+1);
    }
}


int cnt[26];

int dfs( NODE *v ){
    int sum = 1;
    for (int i=0;i<26;++i){
        if ( v->edge[i] != NULL ){
            if ( v != pre && v!= suff )
                cnt[i]++;
            sum += dfs( v->edge[i] );
        }
    }
    return sum;
}

char str[100010];

int save[26];

int main(){

    FRO

    int n,m;
    while ( scanf("%d %d",&n,&m)==2 && (n+m) ){

        pre= new NODE();
        suff= new NODE();

        for (int i=0;i<n;++i){
            scanf("%s",str);
            add( pre,str );
        }
        for (int i=0;i<m;++i){
            scanf("%s",str);
            int len = strlen(str);
            reverse( str,str+len );
            add( suff,str );
        }

        CLR(cnt);
        int x= dfs( pre )-1;

        for (int i=0;i<26;++i){
            save[i] = cnt[i];
        }

        CLR(cnt);
        int y= dfs( suff )-1;


        LL sum = 0;
        for (int i=0;i<26;++i){
            sum += LL(cnt[i])*save[i];
        }

        LL ans = LL(x)*y-sum;
        //cout<<x<<" "<<y<<" "<<sum<<endl;
        printf("%lld\n",ans);

        delete pre;
        delete suff;
    }


    return 0;
}
