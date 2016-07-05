    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <cstring>
    #include <queue>
    #define INF 100000000


    using namespace std;

    int totalnode,totaledge;
    struct EDGES
    {
        int start,finish,weight;
    }edge[2100];

    vector<int>result;
    int d[1100];
    bool vis[1100];

    void bellmanford()
    {
            for (int i = 0; i < totalnode; ++i)
                d[i] = INF;

            //d[0] = 0;

            for (int i = 0; i < totalnode - 1; ++i)
                    for (int j = 0; j < totaledge; ++j)
                            if (d[edge[j].start] + edge[j].weight < d[edge[j].finish])
                                    d[edge[j].finish] = d[edge[j].start] + edge[j].weight;

            //printf("%d\n",d[1]);

            memset(vis,false,sizeof(vis));
            for (int i = 0; i < totalnode - 1; ++i)
            for (int j = 0; j < totaledge; ++j)
                if (d[edge[j].start] + edge[j].weight < d[edge[j].finish])
                {
                    vis[ edge[j].start ]=vis[ edge[j].finish ] =true;
                    d[edge[j].finish]=d[edge[j].start]=-INF;
                }

            for (int i=0;i<totalnode;++i){
                if (vis [i])
                    result.push_back(i);
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

        int test;
        input.grabBuffer();
        test=input.rInt();

        for (int kk=1;test--;++kk)
        {
            totalnode=input.rInt();
            totaledge=input.rInt();



            for (int i=0;i<totaledge;++i)
            {
                edge[i].finish=input.rInt();
                edge[i].start=input.rInt();
                edge[i].weight=input.rInt();
            }
            result.clear();
            bellmanford();

            printf("Case %d:",kk);
            if (result.size()==0){
                printf(" impossible");
            }else{
                for (int i=0;i<result.size();++i){
                    printf(" %d",result[i]);
                }
            }
            printf("\n");

        }

        return 0;
    }

