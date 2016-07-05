#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct  node
{
    string name;
    int cnt;
}result[110];
map <>
map <string,vector <string> > reverse;


int main()
{
    string a,b;

    while (true)
    {
        getline(cin,a);
        b=a;

        if (a[0]=='0')return 0;


        reverse.clear();

        while (a[0]!='1')
        {
            if (a[0]>='A' && a[0]<='Z')
                b=a;
            else
            {
                result[b]=1;
                reverse[a].push_back(b);
            }
            getline(cin,a);
        }



    }

}
