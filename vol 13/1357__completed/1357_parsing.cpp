#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>


using namespace std;

int in[20000100];
int out[20000100];
int time;
int sum[301000];
bool vis[20000100];
int n;
int stk[301000];
int top;
void dfsStack(){
    top=0;
    stk[++top]=0;
    memset(vis,false,sizeof(vis));
    while ( top ){
        int tt=stk[top];
        if ( vis[tt] ){
            out[tt]=time++;
            --top;
            continue;
        }
        in[tt]=time++;
        if (tt<n){
            if ( tt!=0 ){
                for (int i=sum[tt-1]+1;i<=sum[tt];++i){
                    stk[++top]=i;
                }
            }else{
                for (int i=1;i<=sum[0];++i){
                    stk[++top]=i;
                }
            }
        }
        vis[tt]=true;
    }
}

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
}input;

int main(){
    freopen("in.txt","r",stdin);
    input.grabBuffer();

    int kase,tmp,m,a,b;
    kase=input.rInt();

    for (int kk=1;kase--;++kk){
        if( kk!=1 )printf("\n");
        printf("Case %d:\n",kk);
        n=input.rInt();
        for (int i=0;i<n;++i){
            sum[i]=input.rInt();
            if (i)sum[i]+=sum[i-1];
        }
        time=0;
        dfsStack();
        m=input.rInt();
        while (m--){
            a=input.rInt();
            b=input.rInt();
            if ( in[a]<in[b] && out[a]>out[b] ){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    return 0;

}
