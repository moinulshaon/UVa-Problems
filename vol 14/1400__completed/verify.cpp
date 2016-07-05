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

    ifstream in("out1.txt",ios::in);
    ifstream in2("out2.txt",ios::in);

    string s1="";
    string str;
    while ( in>>str ){
        s1+=str;
    }

    string s2="";
    while ( in2>>str ){
        s2+=str;
    }



    if ( s1!=s2 )cout<<"error\n";
    else cout<<"good\n";

    return 0;
}
