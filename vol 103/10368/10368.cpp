#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define sz 20000

int func(int n,int m,int move){

    //printf("%d %d %d\n",n,m,move);


    if (m>n)swap(n,m);

    if ( m==0)return move+1;



    if ( func(n%m,m , move+1  )%2==move%2 ) return move+1;

    return 0;

}


int main(){

    freopen("in.txt","r",stdin);

    int n,m;

    while (scanf("%d %d",&n,&m)==2 && n && m){
        if (func(n,m,0)%2)
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}
