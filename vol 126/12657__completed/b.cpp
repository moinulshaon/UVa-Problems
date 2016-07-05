#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <list>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;


const int maxBufSize = (6000000);

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


list<int> ls;
map< int, list<int>::iterator > mp;
list<int>::iterator it;

int main(){
    FRO

    input.grabBuffer();
    int n,m;

    for(int kk=1;!input.bufEof() ;++kk ){

        n=input.rInt();
        m=input.rInt();

        ls.clear();
        mp.clear();



        for (int i=1;i<=n;++i){

            ls.push_back( i );
            mp[ i ] = ls.end();
            mp[i]--;

            //cout<<*mp[ i ]<<endl;
        }


        int id,x,y;
        int rev=0;
        while (  m--  ){
            id=input.rInt();
            if ( id==1 ){
                x=input.rInt();
                y=input.rInt();

                ls.erase( mp[x] );
                if( rev%2==0 ){
                    mp[x]=ls.insert( mp[y],x );
                }else{
                    it=mp[y];
                    it++;
                    mp[x]=ls.insert( it,x );
                }
            }else if ( id==2 ){
                x=input.rInt();
                y=input.rInt();

                ls.erase( mp[x] );
                if( rev%2==1 ){
                    mp[x]=ls.insert( mp[y],x );
                }else{
                    it=mp[y];
                    it++;
                    mp[x]=ls.insert( it,x );
                }
            }else if ( id==3 ){
                x=input.rInt();
                y=input.rInt();

                swap( *mp[x],*mp[y] );
                swap( mp[x],mp[y] );
            }else{
                rev++;
            }
            /*
            for (it=ls.begin();it!= ls.end();++it){
                printf("%d ",*it);
            }printf("\n");
            */
        }

        LL ans=0;
        int tmp;

        for (it=ls.begin(),tmp=1;it!= ls.end();++it,++tmp){
            if  ( tmp%2 ==1 ){
                ans+= *it;
            }
        }

        if ( rev%2 == 1 && n%2==0 ){
            ans=LL(n)*(n+1)/2 - ans;
        }


        printf("Case %d: %lld\n",kk,ans);
    }


    return 0;
}
