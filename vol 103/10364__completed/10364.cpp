#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}

int arr[25];
int n;
bool pos;
int avr;
bool vis[1<<20+2];


void func( int state,int cnt,int sum ){

    if ( cnt==4 ){
        pos=true;
        return ;
    }

    if ( pos || sum>avr ||vis[state])return ;

    if  ( sum == avr ){
        func(state,cnt+1,0);
        return ;
    }

    for (int i=0;i<n;++i){
        if ( !pos && check(state,i)==0 ){
            func( set(state,i),cnt,sum+arr[i] );
        }
    }
    vis[state]=true;
}

int main(){

    int kase;
    scanf("%d",&kase);

    while (kase--){

        scanf("%d",&n);
        avr=0;
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            avr+=arr[i];
        }


        if ( avr%4!=0 ){
            printf("no\n");
            continue;
        }
        avr/=4;
        pos=true;
        for (int i=0;i<n;++i){
            if ( arr[i] > avr ){
                pos=false;
            }
        }
        if ( !pos ){
            printf("no\n");
            continue;
        }

        memset(vis,false,sizeof(vis));
        pos=false;
        func(0,0,0);

        if ( pos ){
            printf("yes\n");
        }else{
            printf("no\n");
        }


    }
    return 0;


}
