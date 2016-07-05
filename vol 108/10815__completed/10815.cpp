#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <cctype>

using namespace std;

struct NODE{
    bool words;
    //int prefix;
    NODE* edge[26];
    NODE(){
        //words=prefix=0;
        words=false;
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
}*root;

void add(NODE *v,char* word){
    //printf("%s\n",word);
    if ( word[0]=='\0' ){
        v->words=true;
    }else{
        //v->prefix++;
        if ( v->edge[ word[0]-'a' ]== NULL ){
            v->edge[ word[0]-'a' ]=new NODE();
        }
        add(v->edge[ word[0]-'a' ],word+1);
    }
}

char arr[210];
int len=0;

void dfs( NODE *v ){

    if ( v->words && len ){
        arr[len++]='\0';
        printf("%s\n",arr);
        len--;
    }
        for (int i=0;i<26;++i){
            if ( v->edge[ i ] != NULL ){
                arr[len++]=i+'a';
                dfs( v->edge[i] );
                len--;
            }
        }

}



int main(){
    freopen("in.txt","r",stdin);
    root=new NODE();

    while ( scanf("%s",arr)==1 ){
        int x=0;
        for (int i=0;arr[i];++i){
            if ( isalpha(arr[i]) )
                arr[i]=tolower(arr[i]);
            else{
                arr[i]='\0';
                add( root,&arr[x] );
                x=i+1;
            }

        }
        add( root,&arr[x] );
    }

    dfs( root );

    return 0;
}
