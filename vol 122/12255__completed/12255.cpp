#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct mathv{
    mathv(){x=0;y=0;}
    mathv(int a,int b){x=a;y=b;}
    int x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }

}soldier[11000];
int n,s,d,k;

struct LL{
    int leftx,rightx;
}line[11000];

bool cmp( const LL&a,const LL&b ){
    return a.leftx<b.leftx;
}


bool posible(int mid ){

    for (int i=0;i<n;++i){
        int mm=soldier[i].y-mid;
        if (  d < mm  )
            return false;
        line[i].leftx=int ( ceil( soldier[i].x-sqrt( double(d)*d - double(mm)*mm ) )+1e-5) ;
        line[i].rightx=int ( floor( soldier[i].x+sqrt( double(d)*d - double(mm)*mm ) )+1e-5) ;
    }
    sort( line,line+n,cmp );

    int cnt=0;

    for (int i=0;i<n;){

        int high=line[i].rightx;

        while ( i<n &&  high>= line[i].leftx  ){

            high=min( line[i].rightx ,high);
            //printf("%d %d\n",high,cnt);
            ++i;
        }
        ++cnt;


    }
    //printf("\n\n%d %d\n",mid,cnt);

    if  ( cnt<=s )
        return true;
    else
        return false;


}

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){


        scanf("%d %d %d %d",&k,&n,&s,&d);

        for (int i=0;i<n;++i){
            scanf("%d %d",&soldier[i].x,&soldier[i].y);
        }

        int high=k,low=k-d;
        int rr;

        if ( !posible(k) ){
            printf("Case %d: IMPOSSIBLE\n",kk);
            continue;
        }

        while ( abs(low-high)>1 && low<high ){
            int mid=(high+low)/2;

            if ( posible( mid ) ){
                high=mid;
                rr=mid;
                //printf("pos\n");
            }else{
                low=mid;
                //printf("notpos\n");
            }
        }
        if ( posible(high) )
            rr=min( rr,high );
        if ( posible(low) )
            rr=min( rr,low );
        printf("Case %d: %d\n",kk,k-rr);
    }
    return 0;
}
