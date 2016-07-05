#include <cstdio>
#include <cstring>

#define SIZE 200100

int tree[SIZE];
int bookInd[SIZE];

int MaxVal;
int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
    	}
}
void scale(int c){
	for (int i = 1 ; i <= MaxVal ; i++)
		tree[i] = tree[i] / c;
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

    int kase;
    kase=input.rInt();
    int n,m,a,tmp;
    while ( kase-- ){
        n=input.rInt();
        m=input.rInt();
        memset(tree,0,sizeof(tree));
        MaxVal=n+m;
        for (int i=n;i>0;--i){
            update(i,1);
            bookInd[i]=n-i+1;
        }

        for (int i=0;i<m;++i ){
            a=input.rInt();
            if ( i )
                printf(" %d",read(MaxVal)-read(bookInd[a]));
            else
                printf("%d",read(MaxVal)-read(bookInd[a]));
            update(bookInd[a],-1);
            n++;
            update(n,1);
            bookInd[a]=n;
        }
        printf("\n");
    }
    return 0;
}
