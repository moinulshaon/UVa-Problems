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
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 200000

int save[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

struct date{
    int total,dd;
}le,ri;

bool leap( int x ){
    return ( x%400==0 ) || ( (x%4==0) && (x%100!=0) );
}
int calc( int d ){

    int cnt = 0;
    int yy= d/10000 ;
    //cout<<yy<<endl;
    for (int i= 1700 ; i< yy ; ++i ){
        if ( leap( i ) ){
            cnt+= 366 ;
        }else{
            cnt+= 365;
        }
    }
    int mm= (d/100)%100;
    for (int i=1;i<mm;++i){
        if ( i==2 ){
            if ( leap(yy) ){
                cnt+= 29;
            }else{
                cnt+= 28;
            }
        }else{
            cnt+= save[i];
        }
    }
    cnt+= d%100;
    return cnt;
}

bool cover[SIZE];

void shaon(int v){

    int yy,mm;
	for(yy=1700;true;yy++){
	    int tt= 365+leap(yy) ;
        if ( v>tt ){
            v-=tt;
        }else{
            break;
        }
	}

	for(mm=1;true;mm++){
        int tt= save[mm]+( mm==2&&leap(yy) );
        if ( v>tt ){
            v-=tt;
        }else{
            break;
        }
	}
	printf("%d/%d/%d",mm,v,yy);
}

int main(){

    FRO

    int n,m;


    for (int kk=1; scanf("%d %d",&n,&m) == 2 && (n+m) ;++kk ){

        if ( kk!= 1 )printf("\n");

        printf("Case %d:\n",kk);

        memset(  cover ,true ,sizeof(cover) );

        vector< pair<date,date> > v;

        for (int i=0;i<n;++i){
            scanf("%d %d",&le.dd,&ri.dd);

            le.total=calc(le.dd);
            ri.total=calc(ri.dd);



            v.PB( make_pair( le,ri ) );

        }

        while ( m-- ){
            scanf("%d %d",&le.dd,&ri.dd);

            le.total=calc(le.dd);
            ri.total=calc(ri.dd);

            //cout<<le.total<<" "<<le.dd<<endl;

            for (int i=le.total;i<=ri.total;++i){
                cover[i] = false;
            }
        }

        for (int i=0;i<n;++i){

            le= v[i].first;
            ri= v[i].second;

            for (int i=le.total;i<=ri.total;++i){
                cover[i] = true;
            }
        }

        bool ok=false;

        for (int i=0;i<SIZE;++i){

            if ( !cover[i] ){
                int j=i+1;

                while ( !cover[j] ){
                    j++;
                }

                printf("    ");

                ok=true;

                if ( j==i+1 ){
                    shaon(i);
                    printf("\n");
                }else{
                    shaon(i);
                    printf(" to ");
                    shaon(j-1);
                    printf("\n");
                }
                i=j;
            }

        }

        if ( !ok )printf("    No additional quotes are required.\n");


    }

    return 0;
}
