#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int n,person;
double volume[10100];
const double PI=acos(-1);

bool isPossible(double x){
    int p=0;
    for (int i=0;i<n;++i){
        p+=int(volume[i]/x);
    }
    if ( p>=person ){
        return true;
    }else{
        return false;
    }
}

double bsearch(double high){
    double low=0;
    double mid=0;
    while ( fabs(high-low)>1e-6 ){
        mid=(low+high)/2;
        bool is=isPossible(mid);
        if (is) low=mid;
        else high=mid;
        //printf("%lf %lf %lf\n",low,high,mid);
    }
    return mid;
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

    while (kase--){
        n=input.rInt();
        person=input.rInt();
        person++;
        double mx=0;
        for (int i=0;i<n;++i){
            volume[i]=input.rInt();
            volume[i]=PI*volume[i]*volume[i];
            if ( volume[i]>mx ){
                mx=volume[i];
            }
        }
        //sort(volume,volume+n);
        printf("%.4lf\n",bsearch(mx));
    }
    return 0;
}

