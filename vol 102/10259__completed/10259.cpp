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
#define sz 110

using namespace std;
int n,capacity;
bool vis[sz][sz];
int result[sz][sz];
int mat[sz][sz];

int DFS(int a,int b){
    if (vis[a][b])return result[a][b];

    int mx=0;
    for (int i=1;i<=capacity && a-i>=0;++i){
        if ( mat[a][b]< mat[a-i][b])
            mx=max(mx,DFS(a-i,b));
    }
    for (int i=1;i<=capacity && a+i<n;++i){
        if ( mat[a][b]< mat[a+i][b])
            mx=max(mx,DFS(a+i,b));
    }
    for (int i=1;i<=capacity && b-i>=0;++i){
        if ( mat[a][b]< mat[a][b-i])
            mx=max(mx,DFS(a,b-i));
    }
    for (int i=1;i<=capacity && b+i<n;++i){
        if ( mat[a][b]< mat[a][b+i])
            mx=max(mx,DFS(a,b+i));
    }
    vis[a][b]=true;
    return result[a][b]=mat[a][b]+mx;
}



const int maxBufSize = (1 << 20);

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

Input input;

int main(){
    freopen("in.txt","r",stdin);

    input.grabBuffer();

    int kase;

    kase=input.rInt();


    while (kase--){
        memset(vis,false,sizeof(vis));

        n=input.rInt();
        capacity=input.rInt();

        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                mat[i][j]=input.rInt();

        int mx=0;

        mx=max(mx,DFS(0,0));


        printf("%d\n",mx);

        if (kase)
            printf("\n");

    }
    return 0;
}
