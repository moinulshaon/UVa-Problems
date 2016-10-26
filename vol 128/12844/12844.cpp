#include<bits/stdc++.h>

using namespace std;

#define SIZE 12

int arr[SIZE];

bool check(int sum,map<int,int>&now){
    if ( now.count(sum) ==  0 )return false;
    now[sum]--;
    if ( now[sum] == 0 )now.erase( sum );
    return true;
}

bool match(int tar,map<int,int>&now,int val){
    if ( now.size() == 0 )return false;
    now.begin()->second--;
    if ( now.begin()->first -val == tar ){
        if ( now.begin()->second == 0 )now.erase( now.begin() );
        return true;
    }
    else return false;
}

int main(){

    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        for (int i=0;i<10;++i)scanf("%d",&arr[i]);
        sort( arr,arr+10 );


        map<int,int> save;
        for (int i=0;i<10;++i)save[ arr[i] ]++;

        for (int a = arr[0]/2;a>0;--a){
            int b = arr[0]-a;
            if ( b<a )continue;

            for (int e = arr[9]/2;e<arr[9];++e){
                int d = arr[9]-e;
                if ( e<d )continue;
                if ( d<b )continue;

                //cout<<a<<" "<<b<<" "<<d<<" "<<e<<endl;

                map<int,int> now = save;

                if ( !check(a+b,now) )continue;
                if ( !check(a+d,now) )continue;
                if ( !check(a+e,now) )continue;
                if ( !check(b+d,now) )continue;
                if ( !check(b+e,now) )continue;
                if ( !check(d+e,now) )continue;

                if ( now.size() == 0 )continue;


                int tar = now.begin()->first - a;

                //cout<<tar<<endl;
                if ( tar<b || tar>d )continue;

                if ( !match( tar ,now,a ) ) continue;
                if ( !match( tar ,now,b ) ) continue;
                if ( !match( tar ,now,d ) ) continue;
                if ( !match( tar ,now,e ) ) continue;





                printf("Case %d: %d %d %d %d %d\n",kk,a,b,tar,d,e);
                assert(now.size() == 0);

                goto hell;
            }
        }
        assert(false);

        hell:
            ;


    }

    return 0;
}
