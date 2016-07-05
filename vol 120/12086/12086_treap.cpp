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

void changeValue( int ind,int val ){

    pitem a,b,c;

    split( root,ind-1, a,b );
    split( b,ind, b,c);

    b->val = val;

    merge (root, a,b);
	merge (root, root, c);

    return ;
}


int main(){

    FRO

    int n;
    int kase=1;
    while ( scanf("%d",&n)==1 && n ){

        if  ( kase != 1 )printf("\n");

        printf("Case %d:\n",kase++);


        root = 0;
        int tmp;
        for (int i=1;i<=n;++i){
            scanf("%d",&tmp);
            insert( root, new item( i,rand(),tmp ) );
        }

        char str[10];
        int a,b;
        while ( scanf("%s",str) && str[0] !='E' ){

            if ( str[0] == 'M'){
                scanf("%d %d",&a,&b);
                printf("%d\n",calcsum(a,b));
            }else{
                scanf("%d %d",&a,&tmp);
                changeValue( a,tmp );
            }

        }

        clearAll(root);

    }




    return 0;
}
