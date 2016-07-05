#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

#define SIZE 10100

int arr[SIZE],arr2[SIZE];
int inter[SIZE];
int fromLeft[SIZE],fromRight[SIZE];
int n;


void LIS(int seq[],int save[]){

    for (int i=0;i<=n;++i){
        inter[i]=INT_MIN;
    }

    int lis=0,low,high,mid;

    for (int i=1;i<=n;++i){
        low=0;
        high=lis;

        while (low<=high){
            mid=(low+high)>>1;
            if (seq[i] <= inter[mid] )high=mid-1;
            else low=mid+1;
        }

        inter[low]=seq[i];

        save[i]=low;
        if ( low>lis )lis=low;
    }

}
const int maxBufSize = (1 << 22);

struct Input
{
	int bufSize, bufEnd, bufPos;
	char buffer[maxBufSize];
	void grabBuffer() {
		bufSize = (maxBufSize); bufPos = 0;
		bufEnd = fread(buffer, sizeof (char), bufSize, stdin);
		buffer[bufEnd] = '\0';
	}
	bool bufEof() {skipWS();return bufPos == bufEnd;}
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
    //freopen("in.txt","r",stdin);
    input.grabBuffer();


    while (!input.bufEof()){
        n=input.rInt();

        for (int i=1;i<=n;++i){
            arr[i]=input.rInt();
            arr2[n-i+1]=arr[i];
        }

        LIS(arr,fromLeft);

        LIS(arr2,fromRight);


        int ans=1,tmp;
        for (int i=1;i<=n;++i){
            tmp=min( fromLeft[i]-1,fromRight[n-i+1]-1 );
            if ( 2*tmp+1>ans ){
                ans=2*tmp+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
