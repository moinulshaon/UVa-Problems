#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define FO(i,a,b) for (int i = (a); i < (b); i++)

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


#define SIZE 1000100

char str[SIZE];
pint query[SIZE];

int main(){

    //FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        scanf("%s",str);

        int q;
        scanf("%d",&q);

        int tar[26];
        FO(i,0,26)tar[i] = i;

        char sss[10];

        FO(i,0,q){
            scanf("%s",sss);
            query[i].X = sss[0]-'A';
            scanf("%s",sss);
            query[i].Y = sss[0]-'A';
        }

        for (int i=q-1;i>=0;--i){
            int &a = query[i].X;
            int &b = query[i].Y;
            tar[b] = tar[a];
        }

        for (int i=0;str[i];++i){
            if ( str[i] == '_' )printf("_");
            else printf("%c",tar[ str[i]-'A' ]+'A');
        }
        printf("\n");

    }

    return 0;
}
