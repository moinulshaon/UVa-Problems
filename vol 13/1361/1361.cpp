#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <utility>
// header files



#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

struct Bigint {

    // representations and structures

    string a; // to store the digits

    int sign; // sign = -1 for negative numbers, sign = 1 otherwise



    // constructors

    Bigint() {} // default constructor

    Bigint( string b ) { (*this) = b; } // constructor for string



    // some helpful methods

    int size() { // returns number of digits

        return a.size();

    }

    Bigint inverseSign() { // changes the sign

        sign *= -1;

        return (*this);

    }

    Bigint normalize( int newSign ) { // removes leading 0, fixes sign

        for( int i = a.size() - 1; i > 0 && a[i] == '0'; i-- )

            a.erase(a.begin() + i);

        sign = ( a.size() == 1 && a[0] == '0' ) ? 1 : newSign;

        return (*this);

    }



    // assignment operator

    void operator = ( string b ) { // assigns a string to Bigint

        a = b[0] == '-' ? b.substr(1) : b;

        reverse( a.begin(), a.end() );

        this->normalize( b[0] == '-' ? -1 : 1 );

    }



    // conditional operators

    bool operator < ( const Bigint &b ) const { // less than operator

        if( sign != b.sign ) return sign < b.sign;

        if( a.size() != b.a.size() )

            return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();

        for( int i = a.size() - 1; i >= 0; i-- ) if( a[i] != b.a[i] )

            return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];

        return false;

    }

    bool operator == ( const Bigint &b ) const { // operator for equality

        return a == b.a && sign == b.sign;

    }



    // mathematical operators

    Bigint operator + ( Bigint b ) { // addition operator overloading

        if( sign != b.sign ) return (*this) - b.inverseSign();

        Bigint c;

        for(int i = 0, carry = 0; i<a.size() || i<b.size() || carry; i++ ) {

            carry+=(i<a.size() ? a[i]-48 : 0)+(i<b.a.size() ? b.a[i]-48 : 0);

            c.a += (carry % 10 + 48);

            carry /= 10;

        }

        return c.normalize(sign);

    }

    Bigint operator - ( Bigint b ) { // subtraction operator overloading

        if( sign != b.sign ) return (*this) + b.inverseSign();

        int s = sign; sign = b.sign = 1;

        if( (*this) < b ) return ((b - (*this)).inverseSign()).normalize(-s);

        Bigint c;

        for( int i = 0, borrow = 0; i < a.size(); i++ ) {

            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);

            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;

            borrow = borrow >= 0 ? 0 : 1;

        }

        return c.normalize(s);

    }

    Bigint operator * ( Bigint b ) { // multiplication operator overloading

        Bigint c("0");

        for( int i = 0, k = a[i] - 48; i < a.size(); i++, k = a[i] - 48 ) {

            while(k--) c = c + b; // ith digit is k, so, we add k times

            b.a.insert(b.a.begin(), '0'); // multiplied by 10

        }
        return c.normalize(sign * b.sign);
    }

    Bigint operator / ( Bigint b ) { // division operator overloading

        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );

        Bigint c("0"), d;

        for( int j = 0; j < a.size(); j++ ) d.a += "0";

        int dSign = sign * b.sign; b.sign = 1;

        for( int i = a.size() - 1; i >= 0; i-- ) {

            c.a.insert( c.a.begin(), '0');

            c = c + a.substr( i, 1 );

            while( !( c < b ) ) c = c - b, d.a[i]++;

        }

        return d.normalize(dSign);

    }

    Bigint operator % ( Bigint b ) { // modulo operator overloading

        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );

        Bigint c("0");

        b.sign = 1;

        for( int i = a.size() - 1; i >= 0; i-- ) {

            c.a.insert( c.a.begin(), '0');

            c = c + a.substr( i, 1 );

            while( !( c < b ) ) c = c - b;

        }

        return c.normalize(sign);

    }



    // output method

    void print() {

        if( sign == -1 ) putchar('-');

        for( int i = a.size() - 1; i >= 0; i-- ) putchar(a[i]);

    }

};


using namespace std;

#define SIZE 20010

vector<int> outarrow[SIZE];
int level[SIZE];
int backEdge[SIZE];
int prv[SIZE];
char vis[SIZE];
int low[SIZE];
set< pair< int ,int > > bridge;

const int WHITE= -1;
const int GRAY= 1;
const int BLACK= 2;

bool cactus;
typedef long long LL;

void dfs( int x ,int p){

    if ( !cactus )return ;
    low[x]=level[x];
    vis[x]=GRAY;
    int y;
    for (int i=0;i<outarrow[x].size();++i){
        y=outarrow[x][i];
        if ( vis[y]==BLACK ){
            if ( level[y]<level[x] ) {
                if ( prv[y]!=x ){
                    backEdge[y]++;
                    prv[y]=x;
                }
            }
        }else if ( vis[y]==GRAY && y!=p ){
            if ( prv[y]!=x ){
                backEdge[y]++;
                prv[y]=x;
            }
        }
        if ( level[ y ] == -1 ){

            level[ y ]=level[x]+1;

            dfs( y ,x );

            low[x]=min( low[x],low[y] );

            if ( low[y]>level[x] ){
                bridge.insert( make_pair(x,y) );
                bridge.insert( make_pair(y,x) );
            }
        }else if ( level[y]< level[x]-1 ){
            low[x]=min( low[x],level[y] );
        }
    }
    vis[x]=BLACK;
}

Bigint dfs2(int x){
    vis[x]=GRAY;
    Bigint s("1");
    int y;
    for (int i=0;i<outarrow[x].size();++i){
        y=outarrow[x][i];

        if ( bridge.find(make_pair(x,y))!=bridge.end() )continue;

        if ( vis[y]==WHITE ){
            s=s+dfs2(y);
        }
    }
    vis[x]=BLACK;
    return s;
}

int main(){
    freopen("in.txt","r",stdin);
    int a,b,n,m,tmp;
    for (bool on=false; scanf("%d %d",&n,&m)==2;on=true ){
        if ( on )printf("\n");

        for (int i=1;i<=n;++i){
            outarrow[i].clear();
        }
        while (m--){
            scanf("%d",&tmp);
            if (tmp--)
                scanf("%d",&a);
            while (tmp--){
                scanf("%d",&b);
                outarrow[a].push_back(b);
                outarrow[b].push_back(a);
                a=b;
            }
        }
        memset(vis,WHITE,sizeof(vis));
        memset(backEdge,0,sizeof(backEdge));
        memset(level,-1,sizeof(level));
        bridge.clear();
        cactus=true;

        dfs(1,-1);

        for (int i=1;i<=n && cactus;++i){
            if ( level[i]== -1 || backEdge[i]>1 ){
                cactus=false;
            }
        }
        if ( !cactus ){
            //printf("not\n");
            printf("0\n");
        }else{
            Bigint ans("1");
            memset(vis,WHITE,sizeof(vis));
            Bigint TWO("2"),ONE("1");
            for (int i=1;i<=n;++i){
                if ( vis[i]==WHITE ){
                    Bigint tmp=dfs2(i);
                    if ( TWO < tmp){
                        ans=ans*(tmp+ONE);
                    }
                    //printf("%d %d\n",i,tmp);
                }
            }
            ans.print();
            printf("\n");
        }

    }
    return 0;

}
