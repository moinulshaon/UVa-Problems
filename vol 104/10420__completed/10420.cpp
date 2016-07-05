#include <cstdio>
#include <map>
#include <iostream>
#include <string>

using namespace std;

map <string,int> list;
map <string,int> ::iterator it;

int main()
{
    freopen("input.txt","r",stdin);

    int test;

    string str;
    char line[100];
    while (scanf("%d",&test)==1)
    {
        list.clear();
        while (test--)
        {
            cin>>str;
            gets(line);
            if (list.find(str)==list.end())
                list[str]=1;
            else
                ++list[str];
        }
        for (it=list.begin();it!=list.end();++it)
            printf("%s %d\n",(*it).first.c_str(),(*it).second);
    }
    return 0;

}
