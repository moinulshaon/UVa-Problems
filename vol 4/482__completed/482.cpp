#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

pair <int,string> myp[1000000];

bool cmp(pair <int,string> a,pair <int,string> b)
{
    if (a.first>b.first)
        return false;
    else
        return true;
}


int main()
{

    freopen("input.txt","r",stdin);

    int test;
    scanf("%d",&test);
    getchar();

    for (int m=0;m<test;++m)
    {
        if (m)printf("\n");

        string a;
        getchar();
        getline(cin,a);

        istringstream sstr(a);

        int i;
        for (i=0;sstr>>myp[i].first;++i)
            ;


        getline(cin,a);
        istringstream sstr2(a);

        for (int j=0;sstr2>>myp[j].second;++j)
            ;

        sort(myp,myp+i,cmp);

        for (int j=0;j<i;++j)
            printf("%s\n",myp[j].second.c_str());
    }
    return 0;


}
