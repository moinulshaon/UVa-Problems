#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

bool cmp(const string& a,const string& b )
{
    if ( (a+b) > (b+a))
        return true;
    else
        return false;
}

int main()
{
    int n;

    while (true)
    {
        cin>>n;
        if (!n)return 0;

        vector <string> result;

        string str;
        for (int i=0;i<n;++i)
        {
            cin>>str;
            result.push_back(str);
        }



        sort(result.begin(),result.end(),cmp);

        for (int i=0;i<n;++i)
        {
            cout<<result[i];
        }
        cout<<'\n';
    }
}
