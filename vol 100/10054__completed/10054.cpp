#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define SIZE 55

vector<int> outarrow[SIZE];
int matrix[SIZE][SIZE];
int node;
int start;

void DFS(int x){

    int tt;
    for (int i=0;i<outarrow[x].size();++i){
        tt=outarrow[x][i];
        if(  matrix[ x ][ tt ] ){
            matrix[x][tt]--;
            matrix[tt][x]--;
            DFS( tt );
            printf("%d %d\n",tt,x);
        }
    }
    return ;

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

    int kase,a,b;
    kase=input.rInt();

    for (int kk=1;kase--;++kk){

        node=input.rInt();

        for (int i=0;i<SIZE;++i){
            outarrow[i].clear();
        }
        memset(matrix,0,sizeof(matrix));

        for (int i=0;i<node;++i){
            a=input.rInt();
            b=input.rInt();

            matrix[a][b]++;
            matrix[b][a]++;

            outarrow[a].push_back(b);
            outarrow[b].push_back(a);
        }
        printf("Case #%d\n",kk);
        bool pos=true;
        for (int i=0;i<SIZE;++i){
            if ( outarrow[i].size()%2!=0 ){
                pos=false;
                break;
            }
        }
        if ( !pos ){
            printf("some beads may be lost\n");
        }else{

            for (int i=0;i<SIZE;++i){
                if(  outarrow[i].size() ){
                    DFS(i);
                    break;
                }
            }
        }
        if ( kase )
            printf("\n");

    }
    return 0;

}
