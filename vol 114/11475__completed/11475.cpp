#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;


int failure[101000];

int Morris_Pratt(string& t, string& p){


    for (int i=1, j=failure[0]= -1; i<p.size() ; ++i)
    {
        while (j >= 0 && p[j+1] != p[i])
            j = failure[j];
        if (p[j+1] == p[i]) j++;
        failure[i] = j;
    }


    for (int i=0, j=-1; i<t.size(); ++i)
    {
        while (j >= 0 && p[j+1] != t[i])
            j = failure[j];

        if (p[j+1] == t[i]) j++;


        if (i == t.size()-1)
        {
            //cout << i - p.size() + 2<<endl;
            return j;
            j = failure[j];
        }
    }
    return 0;
}


int main(){

    string a,b;

    while (getline(cin,a)){

        b=a;
        reverse(b.begin(),b.end());
        int tmp=Morris_Pratt(a,b);
        //printf("%d\n",tmp);
        printf("%s\n",(a+b.substr( tmp+1,b.length()-tmp-1 )).c_str() );


    }
    return 0;
}
