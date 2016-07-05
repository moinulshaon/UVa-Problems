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
#include <iomanip>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

const long double PI= acos(-1);

int main(){
    FRO

    long double a,b,t,a1,b1,t1;

    for (int kk=1; true ;++kk ){
        cin>>a1>>b1>>t1>>a>>b>>t;

        if ( a1+b1+t1+a+b+t<1e-3 )break;

        long double T=pow( a/a1,1.5 )*t1;

        while ( t+1e-8>T ){
            t-=T;
        }

        //cout<<"period " <<T<<" left "<<t<<endl;

        long double area=PI*a*b*t/T;

        long double cmp=area;

        bool on=false;
        if ( 2*area > PI*a*b ){
            cmp= PI*a*b-area ;
            on=true;
        }
        cout<<"area "<<area<<endl;
        cout<<"cmp "<<cmp<<endl;
        long double low= -a ,x,high=a;
        long double ansx= -1,ansy= -1;
        while ( low<=high ){
            long double mid= (low+high)/2;
            long double tmp= -b/a*( mid*sqrt( a*a-mid*mid )+ a*a/2*( asin(mid/a)-asin(1) )  );

            //cout<<"1 "<<tmp<<' '<<cmp<<' '<<mid<<endl;

            if ( mid<0 ){
                tmp-=  .5*fabs(mid)*b/a*sqrt( a*a-mid*mid ) ;
            }else{
                tmp+=  .5*fabs(mid)*b/a*sqrt( a*a-mid*mid );
            }

            cout<<"2 "<<tmp<<' '<<cmp<<' '<<mid<<endl;
            //for (int i=0;i<100000000;++i){
            //}
            if ( fabs(tmp-cmp)<1e-16 ){
                ansx=mid;
                ansy=b/a*sqrt( a*a-mid*mid );
                break;
            }else if ( tmp> cmp ){
                low=mid;
            }else{
                high=mid;
            }
        }


        if ( on ){
            ansy= -ansy;
        }

        //cout<<"ss "<<ansx<<' '<<ansy<<endl;
        cout<<fixed<<setprecision(3)<<"Solar System "<<kk<<": "<<ansx<<' '<<ansy<<endl;
    }


    return 0;
}
