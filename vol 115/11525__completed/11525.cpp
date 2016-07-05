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
	int prior,cnt,val;
	item * l, * r;
	item() { }
	item ( int prior,int v) :  prior(prior), l(NULL), r(NULL),cnt(1) { val=v; }
};
typedef item * pitem;

pitem root;

int cnt (pitem t) {
	return t ? t->cnt : 0;
}

void update ( pitem t) {
	if (t){
		t->cnt = 1 + cnt(t->l) + cnt (t->r);
	}
}

void split (pitem t, int key, pitem & l, pitem & r,int add=0) {
    if (!t){
		l = r = NULL;
        return ;
	}

	int cur_key = add + cnt(t->l);
	if (key <= cur_key)
		split (t->l, key, l, t->l,add),  r = t;
	else
		split (t->r, key, t->r, r,add+1+cnt(t->l)),  l = t;

    update (t);
}


void insert (pitem & t, pitem it,int ind ) {
    //cout<<ind<<endl;

	if (!t)
		t = it;
	else if (it->prior > t->prior)
		split (t, ind , it->l, it->r),  t = it;
	else
		insert ( t->r, it , ind);
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





int calc( int x ){

    pitem a,b,c;

    split( root,x-1, a,b );
    split( b,1, b,c);

    int save = b->val;

    merge (root, a,c);

	delete b;

    return save;
}



void clearAll( pitem t ){

    if ( !t )return ;

    clearAll( t->l );
    clearAll( t->r );

    delete t;
}

int main(){

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){

        int k;
        scanf("%d",&k);

        root = NULL;

        for (int i=1;i<=k;++i){
            merge( root, root, new item( rand(),i ) );
        }

        vector<int> ans;
        int tmp;
        for (int i=0;i<k;++i){
            scanf("%d",&tmp);
            ans.PB(  calc( tmp+1 ) );
        }

        clearAll(root);

        for (int i=0;i<k;++i){
            if ( i )printf(" ");
            printf("%d",ans[i]);
        }printf("\n");

    }


    return 0;
}
