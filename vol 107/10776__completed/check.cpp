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
#include <fstream>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

int main(){

    ifstream out("out.txt");
    ifstream tmp("tmp.txt");

    string ss,sss,tt;
    while( out>>tt ){
        ss+= tt;
    }
    while( tmp>>tt ){
        sss+= tt;
    }

    if ( ss== sss )cout<<"yes\n";
    else{
        cout<<ss.length()<<"  "<<sss.length()<<endl;
    }
    return 0;
}
