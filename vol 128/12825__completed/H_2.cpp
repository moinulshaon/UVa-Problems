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

#define SIZE 1005

char str[SIZE];

int len;

int xpdp[SIZE][4];
bool visxpdp[SIZE][4];

int xmax( int totake,int dir ){

    if ( totake == len ){
        return 0;
    }
    int &ret = xpdp[totake][dir];
    if ( visxpdp[totake][dir] )return ret;

    visxpdp[totake][dir]=true;

    if ( str[totake] == 'F' ){
        if ( dir == 0 ){
            ret = -1+ xmax( totake+1,dir );
        }else if ( dir==2 ){
            ret = 1+ xmax( totake+1,dir );
        }else{
            ret = xmax( totake+1, dir );
        }
    }else if ( str[totake] == 'R' ){
        ret = xmax(totake+1,(dir+1)%4);
    }else if ( str[totake] == 'L' ){
        ret = xmax(totake+1,(dir-1+4)%4);
    }else{
        if ( dir == 0 ){
            ret = -1+ xmax( totake+1,dir );
        }else if ( dir==2 ){
            ret = 1+ xmax( totake+1,dir );
        }else{
            ret = xmax( totake+1, dir );
        }
        ret = max(ret,xmax(totake+1,(dir+1)%4) );
        ret = max(ret,xmax(totake+1,(dir-1+4)%4) );
    }
    return ret;
}

int xmdp[SIZE][4];
bool visxmdp[SIZE][4];

int xmin( int totake,int dir ){

    if ( totake == len ){
        return 0;
    }
    int &ret = xmdp[totake][dir];
    if ( visxmdp[totake][dir] )return ret;

    visxmdp[totake][dir]=true;

    if ( str[totake] == 'F' ){
        if ( dir == 0 ){
            ret = -1+ xmin( totake+1,dir );
        }else if ( dir==2 ){
            ret = 1+ xmin( totake+1,dir );
        }else{
            ret = xmin( totake+1, dir );
        }
    }else if ( str[totake] == 'R' ){
        ret = xmin(totake+1,(dir+1)%4);
    }else if ( str[totake] == 'L' ){
        ret = xmin(totake+1,(dir-1+4)%4);
    }else{
        if ( dir == 0 ){
            ret = -1+ xmin( totake+1,dir );
        }else if ( dir==2 ){
            ret = 1+ xmin( totake+1,dir );
        }else{
            ret = xmin( totake+1, dir );
        }
        ret = min(ret,xmin(totake+1,(dir+1)%4) );
        ret = min(ret,xmin(totake+1,(dir-1+4)%4) );
    }
    return ret;
}

int ypdp[SIZE][4];
bool visypdp[SIZE][4];

int ymax( int totake,int dir ){

    if ( totake == len ){
        return 0;
    }
    int &ret = ypdp[totake][dir];
    if ( visypdp[totake][dir] )return ret;
    visypdp[totake][dir]=true;

    if ( str[totake] == 'F' ){
        if ( dir == 3 ){
            ret = -1+ ymax( totake+1,dir );
        }else if ( dir==1 ){
            ret = 1+ ymax( totake+1,dir );
        }else{
            ret = ymax( totake+1, dir );
        }
    }else if ( str[totake] == 'R' ){
        ret = ymax(totake+1,(dir+1)%4);
    }else if ( str[totake] == 'L' ){
        ret = ymax(totake+1,(dir-1+4)%4);
    }else{
        if ( dir == 3 ){
            ret = -1+ ymax( totake+1,dir );
        }else if ( dir==1 ){
            ret = 1+ ymax( totake+1,dir );
        }else{
            ret = ymax( totake+1, dir );
        }
        ret = max(ret,ymax(totake+1,(dir+1)%4) );
        ret = max(ret,ymax(totake+1,(dir-1+4)%4) );
    }
    return ret;
}


int ymdp[SIZE][4];
bool visymdp[SIZE][4];

int ymin( int totake,int dir ){

    if ( totake == len ){
        return 0;
    }
    int &ret = ymdp[totake][dir];
    if ( visymdp[totake][dir] )return ret;

    visymdp[totake][dir]=true;

    if ( str[totake] == 'F' ){
        if ( dir == 3 ){
            ret = -1+ ymin( totake+1,dir );
        }else if ( dir==1 ){
            ret = 1+ ymin( totake+1,dir );
        }else{
            ret = ymin( totake+1, dir );
        }
    }else if ( str[totake] == 'R' ){
        ret = ymin(totake+1,(dir+1)%4);
    }else if ( str[totake] == 'L' ){
        ret = ymin(totake+1,(dir-1+4)%4);
    }else{
        if ( dir == 3 ){
            ret = -1+ ymin( totake+1,dir );
        }else if ( dir==1 ){
            ret = 1+ ymin( totake+1,dir );
        }else{
            ret = ymin( totake+1, dir );
        }
        ret = min(ret,ymin(totake+1,(dir+1)%4) );
        ret = min(ret,ymin(totake+1,(dir-1+4)%4) );
    }
    return ret;
}

int main(){


    int kk=1;
    while ( scanf("%s",str)==1 ){
        len = strlen(str);


        for (int i=0;i<=len;++i){
            for (int j=0;j<4;++j){
                visxmdp[i][j] = false;
                visxpdp[i][j] = false;
                visymdp[i][j] = false;
                visypdp[i][j] = false;
            }
        }


        printf("Case %d: %d %d %d %d\n",kk++,xmin(0,2),xmax(0,2),ymin(0,2),ymax(0,2));
    }


    return 0;
}
