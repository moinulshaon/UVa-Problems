#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

#define sz 100100

const double INF=INT_MAX;


struct ppp{
    int x,y;
    ppp(int a=0,int b=0){
        x=a;y=b;
    }

}points[sz];
int stk[sz];
int ans[2];

bool cmp(const ppp&a,const ppp&b){
    return a.x<b.x;
}

ppp dist(int a,int b){
    return ppp( abs(points[a].x-points[b].x) ,abs(points[a].y-points[b].y)  );
}


int top;
int nowmin;
int closest(int a,int b){
    ppp tmp;
    if (a==b)return INF;
    else if ( b-a== 1 ){
        tmp=dist(a,b);
        if ( max(tmp.x,tmp.y)<nowmin ){
            ans[0]=a;
            ans[1]=b;
            nowmin=max(tmp.x,tmp.y);
        }
        return max(tmp.x,tmp.y);
    }
    int m=(a+b)/2;

    int left=closest(a,m);
    int right=closest(m+1,b);

    int d=min(left,right);
    //printf("%d\n",d);
    top=0;
    for(int i=m;i>=a && abs(points[i].x-points[m].x)<=d;i--)
		stk[top++]=i;

    for(int i=m+1;i<=b && abs(points[i].x-points[m].x)<=d;i++)
		stk[top++]=i;



    for (int i=0;i<top;++i){
        for (int j=i+1;j<top;++j){
            tmp=dist(stk[i],stk[j]);
            if ( max(tmp.x,tmp.y)<d ){
                d=max(tmp.x,tmp.y);
                if ( max(tmp.x,tmp.y)<nowmin ){
                    nowmin=max(tmp.x,tmp.y);
                    ans[0]=stk[i] ;
                    ans[1]= stk[j] ;
                }
            }
        }
    }
    return d;
}
const int maxBufSize = 4000000;

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
    int total;
    while (!input.bufEof() ){
        total=input.rInt();
        for (int i=0;i<total;++i){
            points[i].x=input.rInt();
            points[i].y=input.rInt();
        }
        sort(points,points+total,cmp);
        nowmin=INF;
        closest(0,total-1);

        printf("%d\n",nowmin);
    }
    return 0;
}
