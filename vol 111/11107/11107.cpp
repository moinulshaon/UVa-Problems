#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

struct ob
{
    string str;
    int species;
    int lcp;
}arr[200000];


int main()
{
    int test;
    while (true)
    {
        cin>>test;
        if (!test)return 0;

        string ss;
        for (int i=0;i<test;++i)
        {
            cin>>ss;
            int tmp=ss.length();
            for (int j=0;j<tmp;++j)
            {
                arr[i].str=ss.substr(j,tmp-j);
                arr[i].species=1;
                arr[i].lcp=0;
            }
        }


    }
}
