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

const int maxBufSize = (1 << 23);

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

    int kase;
    kase=input.rInt();

    for (int kk=1;kase--;++kk){

        int len;
        len=input.rInt();


        initree();
        for (int i=0;i<len;++i){
            str[i] = input.rChar();
        }

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
        qq=input.rInt();
        for (int i=0;i<qq;++i){
            query[i] =input.rChar();
        }
        for (int i=0;i<qq;++i){
            arr[i]=input.rInt();
            mp[ query[i]-'a' ][ arr[i] ];
        }

        for (int i=3;i<=now;++i){
            if ( mp[ tree[i].last ].find( tree[i].occur ) != mp[ tree[i].last ].end() ){
                mp[ tree[i].last ][ tree[i].occur ] += tree[i].cnt;
            }
        }
        output.print("Case ");
        output.print(kk);
        output.print(":\n");

        for (int i=0;i<qq;++i){
            output.print( mp[ query[i]-'a' ][ arr[i] ] );
            output.print( '\n' );
        }

    }
    output.flushBuffer();

    return 0;
}
