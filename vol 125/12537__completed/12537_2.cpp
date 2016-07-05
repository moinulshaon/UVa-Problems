#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

#define Rep(i,n) for(__typeof(n) i = 0; i < (n); ++i)
#define Repd(i,n) for(__typeof(n) i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(__typeof(b) i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(__typeof(a) i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define nl puts("")
#define sp printf(" ")
#define ok puts("ok")

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> void db(T a, int p = -1) { if (p >= 0) cout << fixed << setprecision(p); cout << a << " "; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> struct Triple { T x, y, z; Triple() {} Triple(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {} };
template<class T> Triple<T> euclid(T a, T b) { if (b == 0) return Triple<T>(1, 0, a); Triple<T> r = euclid(b, a % b); return Triple<T>(r.y, r.x - a / b * r.y, r.z); }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); }
const int bfsz = 1 << 16; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
char gc() { if (rsz <= 0) { ptr = 0; rsz = (int) fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> bool gi(T &v) {
    v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
    while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}

struct mathv{
    int x,y;
}points[210000],circle1,circle2;

int pointsTotal;

double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}

int save[13001];
int save2[13001];

int main()
{

    freopen("in.txt","r",stdin);

    int leaf=13001,a,b;
    int numberofquery;

    for (int kk=1;;++kk)
    {
        gi(pointsTotal);
        if (!pointsTotal)return 0;

        for (int i=0;i<pointsTotal;++i){
            gi(points[i].x);
            gi(points[i].y);
        }
        gi(circle1.x);
        gi(circle1.y);
        gi(circle2.x);
        gi(circle2.y);
        gi(numberofquery);

        //scanf("%d %d %d %d %d",&circle1.x,&circle1.y,&circle2.x,&circle2.y,&numberofquery);

        for (int i=0;i<leaf;++i){
            save[i]=0;
            save2[i]=0;
        }


        for (int i=0;i<pointsTotal;++i){
            int tmp=int ( ceil( distance2DPointAndPoint( points[i],circle1 ) ) );

            if (tmp<13001){
                save[tmp]++;
            }
        }

        for (int i=1;i<leaf;++i){
            save[i]+=save[i-1];
        }

        for (int i=0;i<pointsTotal;++i){

            int tmp=int ( ceil( distance2DPointAndPoint( points[i],circle2 ) ) );

            if (tmp<13001){
                save2[tmp]++;
            }
        }

        for (int i=1;i<leaf;++i){
            save2[i]+=save2[i-1];
        }

        printf("Case %d:\n",kk);

        while (numberofquery--){
            gi(a);
            gi(b);

            int tmp=pointsTotal-save[a]-save2[b];
            if (tmp<0)tmp=0;

            printf("%d\n",tmp);
        }

    }
}
