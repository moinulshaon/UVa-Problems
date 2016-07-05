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

typedef pair<int,int> pint;
typedef map<int,int> mint;


const int maxBufSize = (6000000);

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


#define X first
#define Y second
#define MP make_pair

pint win[100100];

pint mm[100100];

struct tt{
    int ind,num;
    int ans ;
}ans[ 100100 ];

bool cmp ( const tt&a,const tt&b ){
    return a.ind<b.ind;
}
int n,m;
int cnt ;

int score(int x,int ind){

    //cout<<cnt<<" "<<x<<" "<<ind<<' '<<mm[x].X<<' '<<mm[x].Y<<endl;

    if ( x>=cnt ){
        return INT_MIN;
    }else if ( ind>=mm[x].X && ind<=mm[x].Y ){
        //cout<<"shaon\n";
        return min( ind - mm[x].X,mm[x].Y - ind );
    }else{
        return 0;
    }

}

bool ccc ( const tt&a,const tt&b ){
    return a.num<b.num;
}
bool sss ( const pint&a,const pint&b ){
    if ( a.X != b.X ) return a.X<b.X;
    else return a.Y>b.Y;
}

int main(){

    FRO

    input.grabBuffer();

    int kase;
    kase=input.rInt();

    for ( int kk=1;kase--;++kk ){


        n=input.rInt();
        m=input.rInt();

        for (int i=0;i<n;++i){
            win[i].X=input.rInt();
            win[i].Y=input.rInt();
        }
        for (int i=0;i<m;++i){
            ans[i].ind=input.rInt();
            ans[i].num= i;
            ans[i].ans = 0;
        }


        sort( win,win+n, sss );

        cnt = 0;
        int lim = win[0].Y;
        mm[ cnt++ ] = win[0];
        for (int i=0;i<n;++i){
            if ( win[i].Y > lim ){
                mm[ cnt++ ] = win[i];
                lim=win[i].Y;
            }
        }

        sort( ans,ans+m  , cmp );

        //cout<<score( 1,9 )<<endl;


        int le = 0,save;
        for (int i=0;i<m;){
            //cout<<le<<' '<<i<<' '<<score( le,ans[i].ind )<<endl;
            save=score( le,ans[i].ind );
            if (  save == 0 ){
                if ( mm[le].Y < ans[i].ind && le+1<cnt ){
                    le++;
                    continue;
                }
            }

            if ( score( le+1,ans[i].ind ) > save ){
                le++;
            }else{
                ans[ i ].ans = save;
                //cout<<ans[i].ind<<' '<<ans[i].ans<<' '<<le<<endl;;
                i++;
            }

        }

        sort( ans,ans+m, ccc  );
        output.print("Case ");
        output.print(kk);
        output.print(":\n");
        //printf("Case %d:\n",kk);
        for (int i=0;i<m;++i){
            //printf("%d\n",ans[i].ans);
            output.print(ans[i].ans);
            output.print('\n');
        }
    }


    output.flushBuffer();

    return 0;
}
