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

struct item {
	int key, prior,cnt,val,sum;
	item * l, * r;
	item() { }
	item (int key, int prior,int v) : key(key), prior(prior), l(NULL), r(NULL),cnt(1) { sum=val=v; }
};
typedef item * pitem;

pitem root;

int cnt (pitem t) {
	return t ? t->cnt : 0;
}
int sum( pitem t ){
	return t ? t->sum : 0;
}

void update ( pitem t) {
	if (t){
		t->cnt = 1 + cnt(t->l) + cnt (t->r);
		t->sum = t->val + sum(t->l) + sum (t->r);
	}
}

void splitsize (pitem t, int key, pitem & l, pitem & r,int add=0) {
	if (!t)
		l = r = NULL;
	else if (key <= add+cnt(t->l) )
		splitsize (t->l, key, l, t->l,add),  r = t;
	else
		splitsize (t->r, key, t->r, r,add+1+cnt(t->l) ),  l = t;

    update (t);
}
void split (pitem t, int key, pitem & l, pitem & r) {
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

void erase (pitem & t, int key) {
    if ( !t )return ;
	else if (t->key == key)
		merge (t, t->l, t->r);
	else
		erase (key < t->key ? t->l : t->r, key);

    update (t);
}

void clearAll( pitem t ){

    if ( !t )return ;

    clearAll( t->l );
    clearAll( t->r );

    delete t;
}


int calcsum( int x,int y ){

    pitem a,b,c;

    split( root,x-1, a,b );
    split( b,y, b,c);

    int save= sum(b);

    merge (root, a,b);
	merge (root, root, c);

    return save;
}


int main(){


    root =0;

    for (int i=1;i<=5;++i){
        insert( root,new item( i , rand(),1 ) );
        //cout<<sum(root)<<endl;
    }

    for (int i=1;i<=5;++i){
        for (int j=i;j<=5;++j){
            printf("%d %d %d\n",i,j,calcsum(i,j));
        }
    }





    return 0;
}
