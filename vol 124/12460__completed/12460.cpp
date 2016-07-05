#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }

struct NODE{
    int num;
    NODE* edge[126];
    NODE(){
        num = -1;
        for (int i=0;i<126;++i){
            edge[i]=NULL;
        }
    }
    ~NODE(){
        for (int i=0;i<126;++i){
            if ( edge[i]!=NULL ){
                delete edge[i];
            }
        }
    }
}*root;

void add(NODE *v,char* word,int num){
    if ( word[0]=='\0' ){
        v->num=num;
    }else{
        if ( v->edge[ word[0] ]== NULL ){
            v->edge[ word[0] ]=new NODE();
        }
        add(v->edge[ word[0] ],word+1,num);
    }
}

int find_trie(NODE *v,char* word){
    if ( word[0]=='\0' ){
        return v->num;
    }else{
        if ( v->edge[ word[0] ]== NULL ){
            return -1;
        }
        return find_trie(v->edge[ word[0] ],word+1);
    }
}

char str1[100100],str2[100100];

#define SIZE 20100
struct u_find{
    int parent[SIZE];
    int size[SIZE];
    void ini(int n){
        for (int i=1;i<=n;++i){
            parent [i] = i;
            size[i]=1;
        }
    }
    int parentOf (int n){
        if ( n == parent [n] ) return n;
        return parent [n] = parentOf (parent [n]);
    }
    void make_union(int x,int y){
        int p = parentOf (x);
        int q = parentOf (y);

        if ( p != q ) {
            if (size[p]>size[q])swap(p,q);
            size[q]+=size[p];
            parent [p] = q;
        }
    }
}tree;


void calc( char *s,int num ){

    for (int i=0;s[i];++i){
        char tmp = s[i];
        for (int j=1;j<126;++j){
            s[i] = j;
            if ( s[i] == tmp )continue;

            int var = find_trie( root,s );
            if ( var != -1 ){
                tree.make_union( var,num );
            }
        }
        s[i] = tmp;
    }
}


int main(){

    FRO

    root = new NODE();

    tree.ini(SIZE-1);

    for (int i=1; scanf("%s",str1) ==1 ;++i ){
        if ( str1[0] == '-' )break;
        //show( str1 );
        calc( str1,i );
        add(root,str1,i);
    }


    while ( scanf("%s %s",str1,str2)==2 ){
        int a = find_trie(root,str1);
        int b = find_trie(root,str2);

        if ( a == -1 || b== -1 ){
            printf("No\n");
        }else {

            a= tree.parentOf(a);
            b= tree.parentOf(b);

            //show(a,b);

            if ( a == b ){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }

    }


    return 0;
}
