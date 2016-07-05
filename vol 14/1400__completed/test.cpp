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
}tree[5*SIZE];
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

const int maxBufSize = (8000000);

struct Input
{
	int bufSize, bufEnd, bufPos;
	char buffer[maxBufSize];
	void grabBuffer() {
		bufSize = (maxBufSize); bufPos = 0;
		bufEnd = fread(buffer, sizeof (char), bufSize, stdin);
		buffer[bufEnd] = '\0';
	}
	bool bufEof() {return bufPos == bufEnd;}
	int getChar() {return buffer[bufPos++];}
	void skipWS() {
		while ((buffer[bufPos] == '\n' ||
			buffer[bufPos] == ' ' || buffer[bufPos] == '\t'))
			bufPos++;
	}
	int rInt() {
		int n = 0, x; skipWS();
		bool neg=false;
		if (  ( x = getChar() )=='-'  ){
            neg=true;
            x=getChar();
		}

		for (; x <= '9' && x >= '0'; x = getChar())
			n = (n << 3) + (n << 1) + (x - '0');
        if ( neg )return -n;
        else return n;
	}
	inline bool isWhiteSpace(char x) {
		return x == ' ' || x == '\n' || x == '\t';
	}
	char rChar() {skipWS(); return getChar();}
};
struct Output
{
	int bufSize, bufEnd, bufPos;
	char buffer[maxBufSize];
	Output() {bufPos = bufEnd = 0; bufSize = maxBufSize;}
	void print(int x) {
		if (x < 0) {
			print('-'); print(-x); return;
		}
		char temp[1 << 4]; int idx = 0;
		do {
			temp[idx++] = '0' + (x % 10);
			x /= 10;
		} while (x != 0);
		temp[idx] = '\0';
		reverse(temp, temp + idx);
		print(temp);
	}
	inline void print(char ch) {buffer[bufEnd++] = ch;}
	inline void print(const char* s) {while (*s) buffer[bufEnd++] = *s++;}
	inline void print(const string& s) {print(s.c_str());}
	inline void flushBuffer() {buffer[bufEnd] = '\0'; printf("%s", buffer); bufEnd = 0;}
	template <class A, class B>
	void print(const A& a, const B& b) {print(a); print(b);}
	template <class A, class B, class C>
	void print(const A& a, const B& b, const C& c) {print(a); print(b); print(c);}
};

Output output;
Input input;

int main(){
    FRO

    input.grabBuffer();
    int len,qq,kk=1;
    while(!input.bufEof() ){

        len=input.rInt();
        qq=input.rInt();

        for (int i=1;i<=len;++i){
            arr[i]=input.rInt();
        }


        build(1,1,len);
        output.print("Case ");
        output.print(kk++);
        output.print('\n');


        int le,ri;
        while ( qq-- ){
            le=input.rInt();
            ri=input.rInt();

            node ans= query(1,le,ri);
            output.print( ans.ansle );
            output.print(' ');
            output.print( ans.ansri );
            output.print('\n');
            //cout<<ans.val<<endl;
        }
    }
    output.flushBuffer();
    return 0;
}
