#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;


/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
void find_lis(vector<int> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;

	if (a.empty()) return;

	b.push_back(0);

	for (size_t i = 1; i < a.size(); i++)
        {
                // If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] < a[i])
                {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}

                // Binary search to find the smallest element referenced by b which is just bigger than a[i]
                // Note : Binary search is performed on b (and not a). Size of b is always <=k and hence contributes O(log k) to complexity.
		for (u = 0, v = b.size()-1; u < v;)
                {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}

                // Update b if new value is smaller then previously referenced value
		if (a[i] < a[b[u]])
                {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}
	}

	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}

int arr[63000];

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

int main()
{
    freopen("in.txt","r",stdin);
    input.grabBuffer();
    int x,y,z,tmp;
    int kase;
    kase=input.rInt();
    for (int kk=1; kase-- ;++kk)
    {
        x=input.rInt();
        y=input.rInt();
        z=input.rInt();

        vector<int> a;
        vector<int> b;
        memset(arr,0,sizeof(arr));

        for (int i=0;i<=y;++i){
            tmp=input.rInt();
            arr[tmp]=i;
        }

        for (int i=0;i<=z;++i){
            tmp=input.rInt();
            if ( arr[tmp] )
                b.push_back( arr[tmp] );
        }

        vector<int> lis;
        find_lis(b,lis);

        printf("Case %d: %d\n",kk,lis.size()+1 );
    }
    return 0;
}
