#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <cctype>

using namespace std;

bool cmp(const char a ,const char b){
    bool lowera=islower(a),lowerb=islower(b);
    if ( (lowera && lowerb)||(!lowera && !lowerb) )
        return a<b;
    else if (lowera && !lowerb){
        if (a==tolower(b))
            return false;
        else
            return a<tolower(b);
    }
    else{
        if (tolower(a)==b )
            return true;
        else
            return tolower(a)<b;
    }
}

int main(){
    int kase;
    scanf("%d",&kase);
    getchar();

    string str;
    while (kase--){
        getline(cin,str);
        sort(str.begin(),str.end(),cmp);

        set<string> myset;

        do{
            if (myset.find(str) == myset.end() ){
                cout<<str<<endl;
                myset.insert(str);
            }
        }while (next_permutation( str.begin(),str.end() ,cmp) );
    }
    return 0;
}
