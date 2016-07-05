#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }


typedef pair<double,double> point;
struct line{
    double a,b,c;
};


line getline( point a, point b ){
    line ret ;
    ret .a = a.Y-b.Y;
    ret.b = -( a.X-b.X );
    ret.c = a.Y*( a.X-b.X ) - a.X*( a.Y-b.Y );
    return ret;
}

line getper( line v ,point p,point q ){
    line ret;
    ret.a = v.b;
    ret.b = -v.a;
    ret.c = (  v.a *( p.Y+q.Y ) - v.b * ( p.X+q.X )  )/2;
    return ret;
}

point getinter( line p,line q ){

    point ret;
    ret.X = ( p.b * q.c - q.b * p.c )/(  p.a*q.b - q.a*p.b  );
    ret.Y = ( p.c * q.a - q.c * p.a )/(  p.a*q.b - q.a*p.b  );

    return ret;
}

double getdis( point p,point q ){
    return sqrt( pow(p.X-q.X,2)+pow(p.Y-q.Y,2) );
}

char* calc( double x ){

    char *str;
    str = new char [15];
    str[0] = 0;
    if ( x < 0 ){
        strcat(str,"- ");
        x = -x;
    }else{
        strcat(str,"+ ");
    }
    char tmp[15];
    sprintf(tmp,"%.3f",x);
    strcat( str,tmp );

    return str;
}

int main(){

    FRO

    point a,b,c;
    while ( scanf("%lf %lf %lf %lf %lf %lf",&a.X,&a.Y,&b.X,&b.Y,&c.X,&c.Y) != EOF ){

        line A = getline( a,b );
        //show( a.X,a.Y,b.X,b.Y,A.a,A.b,A.c );
        line B = getline( b,c );

        line p = getper( A,a,b );
        //show( p.a,p.b,p.c );

        line q = getper( B,b,c );

        c = getinter( p,q );

        //show( c.X,c.Y );
        double r = getdis( c,a );

        printf("(x %s)^2 + (y %s)^2 = %.3f^2\n",calc(-c.X),calc(-c.Y),r);
        printf("x^2 + y^2 %sx %sy %s = 0\n",calc( -2*c.X ),calc( -2*c.Y ), calc( pow( c.X,2 )+ pow( c.Y,2 )-r*r ) );
        printf("\n");

    }

    return 0;
}
