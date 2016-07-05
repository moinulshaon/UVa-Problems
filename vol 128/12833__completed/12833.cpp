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

#define SIZE 100100

struct node{
    int nxt[26];
    int len;
    int suffixLink;

    int last;
    int occur;

    int cnt ;

}tree[SIZE];

int now,suf;

char str[SIZE];
int sum[SIZE][26];

void addNode(int ind){

    int cur = suf,curlen=tree[suf].len;
    int toAdd = str[ind]-'a';

    while ( true ){
        if ( ind-1-curlen >=0 && str[ ind-1-curlen ] == str[ind] ){
            break;
        }
        cur = tree[cur].suffixLink;
        curlen= tree[cur].len;
    }

    if ( tree[cur].nxt[toAdd]) {
		suf = tree[cur].nxt[toAdd];
		tree[suf].cnt++;
		return ;
	}

    tree[++now].len = tree[cur].len + 2;
    tree[now].last = toAdd;


    tree[now].occur = sum[ ind ][toAdd] -  ( ( ind -tree[now].len <0 )?0:sum[ ind -tree[now].len ][toAdd] );

    //cout<<ind<<" "<<tree[now].len<<" "<<tree[now].last<<" "<<tree[now].occur<<endl;


    tree[cur].nxt[ toAdd ] = now;
    suf = now;

    if ( tree[now].len == 1) {
		tree[now].suffixLink = 2;
		tree[now].cnt = 1;
		return ;
	}


    while ( true ){

        cur = tree[cur].suffixLink;
        curlen= tree[cur].len;

        if ( ind-1-curlen >=0 && str[ ind-1-curlen ] == str[ind] ){
            tree[now].suffixLink = tree[cur].nxt[toAdd];
            break;
        }
    }
    tree[now].cnt = 1;
}



void initree(){

    CLR(tree);

    now = suf = 0;
    tree[++now].len = -1;
    tree[now].suffixLink = 1;
    tree[++now].len = 0;
    tree[now].suffixLink = 1;
    suf = 2;
}

mint mp[26];

char query[SIZE];
int arr[SIZE];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int len;
        scanf("%d",&len);


        initree();
        scanf("%s",str);

        for (int j=0;j<26;++j){
            sum[0][j] = ( str[0] -'a' == j );
            //cout<<sum[0][j]<<endl;
        }
        for (int i=1;i<=len;++i){
            for (int j=0;j<26;++j){
                sum[i][j] = sum[i-1][j] + ( str[i] -'a' == j );
            }
        }

        for (int i=0;i<len;++i){
            addNode(i);
        }

        for (int i=now;i>2;--i){
            tree[ tree[i].suffixLink ].cnt += tree[i].cnt;
        }

        for (int i=0;i<26;++i){
            mp[i].clear();
        }

        int qq;
        scanf("%d",&qq);
        scanf("%s",query);
        for (int i=0;i<qq;++i){
            scanf("%d",&arr[i]);
            mp[ query[i]-'a' ][ arr[i] ];
        }

        for (int i=3;i<=now;++i){
            if ( mp[ tree[i].last ].find( tree[i].occur ) != mp[ tree[i].last ].end() ){
                mp[ tree[i].last ][ tree[i].occur ] += tree[i].cnt;
            }
        }

        printf("Case %d:\n",kk);
        for (int i=0;i<qq;++i){
            printf("%d\n",mp[ query[i]-'a' ][ arr[i] ]);
        }

    }

    return 0;
}
