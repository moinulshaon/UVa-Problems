#include <cstdio>
#include <cstring>

#define sz 1005

char pos[sz];
int n;
int arr[25];


char check( int number,int totake ){

    if (number<0)return false;
    else if (!number)return true;
    else if (pos[number]!=-1)return pos[number];

    bool on=false;

    for (int i=totake;i<n && !on;++i)
        on= on | check( number-arr[i] ,i+1 );

    return pos[number]=on;

}


int main(){

    freopen("in.txt","r",stdin);

    int kase,destination;

    scanf("%d",&kase);

    while ( kase-- ){
        scanf("%d",&destination);

        memset(pos,-1,sizeof(pos));

        scanf("%d",&n);

        for (int i=0;i<n;++i)
            scanf("%d",&arr[i]);

        if ( check( destination, 0  ) )
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;

}
