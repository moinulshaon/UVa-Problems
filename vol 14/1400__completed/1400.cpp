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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;


#define SIZE 500100

struct node{
    LL val,sum;
    int ansle,ansri;
    int left,right;
    LL suffix,prefix;
    int sufind,preind;
}tree[7*SIZE];
LL arr[SIZE];




node merge( node x,node y ){
    node tmp;
    tmp.val=max( x.suffix+y.prefix,
                    max( x.val, y.val ) );

    tmp.ansle=tmp.ansri=(1<<29);
    if ( x.suffix+y.prefix == tmp.val ){

        if ( x.sufind < tmp.ansle ){
            tmp.ansle=x.sufind;
            tmp.ansri=y.preind;
        }else if ( x.sufind == tmp.ansle ){
            tmp.ansri=min( tmp.ansri, y.preind );
        }
        //cout<<"ss "<<tmp.ansle<<' '<<tmp.ansri<<endl;

    }
    if ( x.val== tmp.val ){
        if ( x.ansle < tmp.ansle ){
            tmp.ansle=x.ansle;
            tmp.ansri=x.ansri;
        }else if ( x.ansle == tmp.ansle ){
            tmp.ansri=min( tmp.ansri, x.ansri );
        }
    }
    if ( y.val== tmp.val ){
        if ( y.ansle < tmp.ansle ){
            tmp.ansle=y.ansle;
            tmp.ansri=y.ansri;
        }else if ( y.ansle == tmp.ansle ){
            tmp.ansri=min( tmp.ansri, y.ansri );
        }
    }

    tmp.sum=x.sum+y.sum;

    tmp.prefix=max( x.prefix,x.sum+y.prefix );
    if ( x.prefix < x.sum+y.prefix  ){
        tmp.preind= y.preind;
    }else{
        tmp.preind= x.preind;
    }

    tmp.suffix=max( y.suffix,y.sum+x.suffix );
    if ( y.suffix > y.sum+x.suffix ){
        tmp.sufind= y.sufind;
    }else{
        tmp.sufind= x.sufind;
    }

    tmp.left=x.left;
    tmp.right=y.right;

    return tmp;
}

void build( int num ,int le,int ri){
    //printf("%d\n",num);
    tree[num].left=le;
    tree[num].right=ri;
    if ( le==ri ){
        tree[num].val=tree[num].sum=arr[le];
        tree[num].prefix=tree[num].suffix= arr[ le ] ;
        tree[num].ansle=tree[num].ansri=tree[num].preind=tree[num].sufind= le ;
    }else{
        build(2*num,le,(le+ri)/2);
        build(2*num+1, (le+ri)/2+1,ri);
        tree[num]=merge(tree[2*num],tree[2*num+1]);
    }
}

node query( int num,int ql,int qr ){
    //printf("%d %d %d %lld\n",num,tree[num].left,tree[num].right,tree[num].val);
    if ( ql <= tree[num].left && qr >= tree[num].right  )return tree[num];
    else{
        bool lon=false,ron=false;
        if (  ql<= tree[2*num].right )
            lon=true;
        if ( qr>= tree[2*num+1].left  )
            ron=true;
        if ( lon && ron ){
            return merge(query(2*num,ql,qr),query(2*num+1,ql,qr));
        }else if ( lon ){
            return query(2*num,ql,qr);
        }else if ( ron ){
            return query(2*num+1,ql,qr);
        }
    }
}


int main(){
    FRO

    int len,qq,kk=1;
    while( scanf("%d %d",&len,&qq)==2 ){

        for (int i=1;i<=len;++i){
            scanf("%lld",&arr[i]);
        }


        build(1,1,len);
        printf("Case %d:\n",kk++);
        int le,ri;
        while ( qq-- ){
            scanf("%d %d",&le,&ri);
            node ans= query(1,le,ri);
            printf("%d %d\n",ans.ansle,ans.ansri );
            //cout<<ans.val<<endl;
        }
    }
    return 0;
}
