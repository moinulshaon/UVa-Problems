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

int tree[SIZE];
int MaxVal=SIZE-10;
int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
    //cout<<idx<<" "<<val<<endl;
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
    }
}

vector<int> pos[SIZE*10];
int arr[SIZE];
vector<pint> lazy[SIZE];

int frmleft[SIZE],frmright[SIZE];

struct qq{
    int a,b,ind;
    int ans ;
}query[SIZE];

bool cmp( const qq&x,const qq&y ){
    return x.b<y.b;
}
bool ccc( const qq&x,const qq&y ){
    return x.ind<y.ind;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,q;
        scanf("%d %d",&n,&q);
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
            pos[ arr[i] ].PB( i );
        }

        CLR(tree);

        for (int i=1;i<=n;++i){
            frmleft[i] = 0;
            frmright[i] = n+1;
        }



        for (int i=1;i<=n;++i){
            int &v=arr[i];
            vector<int> div;
            for (int d=1;d*d<=v;++d){
                if ( v%d==0 ){
                    div.PB( d );
                    if ( v != d*d ){
                        div.PB( v/d );
                    }
                }
            }
            for (int j=0;j<div.size();++j){
                int &x = div[j];
                vector<int>::iterator it= lower_bound( pos[x].begin(),pos[x].end(),i+1 );
                if ( it != pos[x].end() ){
                    frmright[i]= min( frmright[i], *it );
                }

                it= lower_bound( pos[x].begin(),pos[x].end(),i );
                if ( it != pos[x].begin() ){
                    it--;
                    frmleft[i]= max( frmleft[i], *it );
                }

            }
        }
/*
        for (int i=1;i<=n;++i){
            cout<<i<<" "<<frmleft[i]<<" "<<frmright[i]<<endl;
        }
*/

        for (int i=0;i<q;++i){
            scanf("%d %d",&query[i].a,&query[i].b);
            query[i].ind= i;
        }
        sort( query,query+q ,cmp );
        int now =0;
        for (int i=1;i<=n;++i){

            for (int j=0;j<lazy[i].size();++j){
                update( lazy[i][j].X,-1 );
                if ( lazy[i][j].Y >0 )
                    update( lazy[i][j].Y,1 );
            }

            update( i,1 );
            if ( frmleft[i]>0 )
                update( frmleft[i],-1 );
            lazy[ frmright[i] ].PB( MP( i,frmleft[i] ) );

            while ( now<q && query[now].b == i ){
                query[ now ].ans = read( query[now].b )-read( query[now].a-1 );
                now++;
            }

        }


        sort( query,query+q,ccc );

        printf("Case %d:\n",kk);
        for (int i=0;i<q;++i){
            printf("%d\n",query[i].ans);
        }

        for (int i=1;i<=n;++i){
            pos[ arr[i] ].clear();
        }
        for (int i=0;i<=n+1;++i){
            lazy[ i ].clear();
        }

    }


    return 0;
}
