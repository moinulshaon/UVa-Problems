#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

map <string,int> cnt;
map <string,int>:: iterator it;


int main()
{

    //freopen("in.txt","r",stdin);

    int test;
    scanf("%d",&test);
    getchar();
    getchar();

    string a;
    for (int m=0;m<test;++m)
    {
        cnt.clear();
        if (m)printf("\n");


        while ( getline(cin,a))
        {


            if (!a.size())break;

            if (cnt.find(a)==cnt.end())
                cnt[a]=1;
            else
                ++cnt[a];
        }
        int total=0;
        for (it=cnt.begin();it!=cnt.end();++it)
            total+=it->second;

        for (it=cnt.begin();it!=cnt.end();++it)
            printf("%s %.4lf\n",it->first.c_str(),double(it->second)*100/total);
    }
    return 0;

}
