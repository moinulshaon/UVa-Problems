#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxVal=110;

int tree[MaxVal+5];
int val[MaxVal+5];

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

int arr[1001001];



int sz,mod;
void gene( int x ){
    if ( x<=3 ){
        arr[x]=x;
    }else{
        arr[x] = ( arr[x-1]+arr[x-2]+arr[x-3] )%mod+1;
    }
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
    int kase;

    kase=input.rInt();

    for (int kk=1;kase--;++kk){
        int total,k;
        memset(tree,0,sizeof(tree));
        memset(val,0,sizeof(val));

        total=input.rInt();
        mod=input.rInt();
        k=input.rInt();

        arr[1]=1;
        val[1]=1;
        update( 1,1 );

        int left=1,right=1;
        int ans= (1<<29);
        while( right<=total ){
            //printf("%d\n",read(k));
            if ( read( k ) == k ){
                ans=min( ans,right-left+1 );
                if ( arr[left]<=k ){
                    val[ arr[left] ]--;
                    if ( !val[ arr[left] ]  ){
                        update( arr[left], -1 );
                    }
                }
                left++;
            }else{
                gene( ++right );
                if ( arr[right]<=k ){
                    val[ arr[right] ]++;
                    if ( val[ arr[right] ] == 1  ){
                        update( arr[right], 1 );
                    }
                }
            }
        }

        if ( ans== (1<<29) ){
            printf("Case %d: sequence nai\n",kk);
        }else{
            printf("Case %d: %d\n",kk,ans);
        }
    }
    return 0;
}
