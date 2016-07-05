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

#define SIZE 300100

struct item {
    LL key;
    int  prior,cnt;
    item * l, * r;
    item() { }
    item (LL key, int prior) : key(key), prior(prior), l(NULL), r(NULL),cnt(1) {

    }
};
typedef item * pitem;

struct TREAP {

    pitem root;

    int cnt (pitem t) {
        return t ? t->cnt : 0;
    }


    void update ( pitem t) {
        if (t) {
            t->cnt = 1 + cnt(t->l) + cnt (t->r);
        }
    }

    void split (pitem t, LL key, pitem & l, pitem & r) {
        if (!t)
            l = r = NULL;
        else if (key < t->key)
            split (t->l, key, l, t->l),  r = t;
        else
            split (t->r, key, t->r, r),  l = t;

        update (t);
    }

    void insert (pitem & t, pitem it) {
        if (!t)
            t = it;
        else if (it->prior > t->prior)
            split (t, it->key, it->l, it->r),  t = it;
        else
            insert (it->key < t->key ? t->l : t->r, it);
        update(t);
    }


    void merge (pitem & t, pitem l, pitem r) {
        if (!l || !r)
            t = l ? l : r;
        else if (l->prior > r->prior)
            merge (l->r, l->r, r),  t = l;
        else
            merge (r->l, l, r->l),  t = r;

        update (t);
    }

    void erase (pitem & t, LL key) {
        if ( !t )return ;
        else if (t->key == key)
            merge (t, t->l, t->r);
        else
            erase (key < t->key ? t->l : t->r, key);

        update (t);
    }





    int kth(pitem t,int left) {
        if ( cnt(t->l)+1==left ) {
            return t->key;
        } else if ( cnt(t->l)+1 > left ) {
            return kth( t->l,left );
        } else {
            return kth( t->r,left-cnt(t->l)-1 );
        }
    }

    int smaller( pitem t,LL v ) {

        if ( !t )return 0;
        if ( t->key < v ) {
            return cnt( t->l )+1+smaller( t->r,v );
        } else {
            return smaller( t->l,v );
        }
    }

    bool treapSearch( pitem t, int v ) {

        if ( !t )return false;

        if ( t->key == v )return true;
        else if ( v > t->key ) {
            return treapSearch( t->r,v );
        } else {
            return treapSearch( t->l,v );
        }
    }

    void clearAll( pitem t ) {

        if ( !t )return ;

        clearAll( t->l );
        clearAll( t->r );

        delete t;
    }

}tree[SIZE];

int n;
LL arr[SIZE];

void add( int ind,LL val ){
    while (ind <= n){
		tree[ind].insert( tree[ind].root,new item( val,rand() ) );
        ind += (ind & -ind);
    }
}
void erase( int ind,LL val ){
    while (ind <= n){
		tree[ind].erase( tree[ind].root,val );
        ind += (ind & -ind);
    }
}

int read( int ind ,LL val){
    int sum = 0;
	while (ind > 0){
		sum += tree[ind].smaller(tree[ind].root,val);
		ind -= (ind & -ind);
	}
	return sum;
}


int main() {

    FRO

    LL u;
    int qq;
    while ( scanf("%d %d %lld",&n,&qq,&u)==3 ){

        for (int i=0;i<=n;++i){
            //tree[i].clearAll(tree[i].root);
            tree[i].root=0;
        }

        LL tmp;
        for (int i=1;i<=n;++i){
            scanf("%lld",&tmp);
            arr[i] = tmp;
            add( i,tmp );
        }

        int x,y,p;
        LL v;
        while ( qq-- ){
            scanf("%d %d %lld %d",&x,&y,&v,&p);

            int cnt = read( y,v )-read( x-1,v );

            erase( p,arr[p] );

            arr[p] = u*cnt /( y-x+1 );

            add( p,arr[p] );
        }

        for (int i=1;i<=n;++i){
            printf("%lld\n",arr[i]);
        }

    }


    return 0;
}
