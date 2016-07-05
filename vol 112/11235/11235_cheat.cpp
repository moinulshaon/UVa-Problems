#include<iostream>
#include<vector>
#include <map>
#include <string>
#include<algorithm>
#include<queue>
#include<cstdio>
#include <cmath>
#include <cstring>
#include<ctime>
#include <cstdlib>
#include <climits>


#define forn(i,n) for(i=0; i<(n); i++)
#define forsn(i,s,n) for(i=(s); i<(n); i++)

using namespace std;

#define MAXN 100001
int N, A[MAXN], pi[MAXN], beta[MAXN], alfa[MAXN], tau[MAXN], lam[MAXN];
struct node {
	int child, sib, parent;
};
#define CHILD(v) nodes[v].child
#define SIB(v) nodes[v].sib
#define PARENT(v) nodes[v].parent

void process() {
	int u,v,p,h,n,t;
	struct node *nodes=(node *)calloc(N+1,sizeof(*nodes));


	t = 0;
	for(v=N; v>0; v--) {
		u = 0;
		while(A[v]>A[t] || (A[v]==A[t] && v>t)) {
			u = t;
			t = PARENT(t);
		}
		if(u) {
			SIB(v) = SIB(u);
			SIB(u) = 0;
			PARENT(u) = v;
			CHILD(v) = u;
		} else
			SIB(v) = CHILD(t);
		CHILD(t) = v;
		PARENT(v) = t;
		t = v;
	}


	p = CHILD(0);
	n = 0;
	lam[0] = -1;

s3:
	n++;
	pi[p] = n;
	tau[n] = 0;
	lam[n] = 1+lam[n>>1];
	if(CHILD(p)) {
		p = CHILD(p);
		goto s3;
	}
	beta[p] = n;

s4:
	tau[beta[p]] = PARENT(p);
	if(SIB(p)) {
		p = SIB(p);
		goto s3;
	}
	p = PARENT(p);


	if(p) {
		h = lam[n & -pi[p]];
		beta[p] = ((n>>h)|1)<<h;
		goto s4;
	}


	p = CHILD(0);
	lam[0] = lam[n];
	pi[0] = beta[0] = alfa[0] = 0;

s7:
	alfa[p] = alfa[PARENT(p)] | (beta[p] & -beta[p]);
	if(CHILD(p)) {
		p = CHILD(p);
		goto s7;
	}

s8:
	if(SIB(p)) {
		p = SIB(p);
		goto s7;
	} else {
		p = PARENT(p);
		if(p) goto s8;
	}
	free(nodes);
}

int nca(int x, int y) {
	int h,k,j,l,z;


	if(beta[x] <= beta[y])
		h = lam[beta[y] & -beta[x]];
	else
		h = lam[beta[x] & -beta[y]];


	k = alfa[x] & alfa[y] & -(1<<h);
	h = lam[k & -k];


	j = ((beta[x] >> h)|1) << h;


	if(j != beta[x]) {
		l = lam[alfa[x] & ((1<<h)-1)];
		x = tau[((beta[x] >> l)|1) << l];
	}
	if(j != beta[y]) {
		l = lam[alfa[y] & ((1<<h)-1)];
		y = tau[((beta[y] >> l)|1) << l];
	}


	z = (pi[x] <= pi[y]) ? x : y;
	return z;
}

int max(int a, int b) {
	return a > b ? a : b;
}

const int maxBufSize = (1 << 24);

using namespace std;

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


int main() {

    freopen("in.txt","r",stdin);


    input.grabBuffer();

	int n,i,j,q,Q,x,y,oldx,count,z;
	int R[MAXN],B[MAXN];
	for(;;) {
		n=input.rInt();
		//printf("%d\n",n);
		if(!n) break;
		Q=input.rInt();
		A[0] = INT_MAX;
		N=1, count=0;
		forsn(i,1,n+1) {
			x=input.rInt();
			//printf("%d\n",x);
			if(i>1 && x!=oldx) {
				A[N] = count;
				R[N] = i;
				N++;
				count = 0;
			}
			B[i] = N;
			count++;
			oldx = x;
		}
		A[N] = count;
		R[N] = i;
		process();
		forn(q,Q) {
			i=input.rInt();
			j=input.rInt();
			x=B[i], y=B[j];
			if(x == y) {
				z = j-i+1;
			} else {
				z = (x+1 != y) ? A[nca(x+1,y-1)] : 0;
				z = max(z, max(R[x]-i, A[y]-R[y]+j+1));
			}
			output.print(z);
			output.print('\n');
		}
	}
	output.flushBuffer();
	return 0;
}
