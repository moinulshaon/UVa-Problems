#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void determine(vector<char> & ss,vector<int> & aa,int ind)
{
    char tmp=ss[ind];
    int tt=ind;
    if (ind==0)return ;
    if (aa[ind]==-1)
    {
        for (int i=ind-1;i>=0;--i)
            if (ss[i]==tmp)
            {
                aa[i]=tt;
                tt=i;
            }
    }
    determine(ss,aa,ind-1);

}

int main()
{
    int total;
    char c;
    while (cin>>total)
    {
        vector<char> str1;
        vector<int> ind1;

        //ind1.assign(-1,total);
        for (int i=0;i<total;++i)
        {
            cin>>c;
            str1.push_back(c);
        }

        //determine(str1,ind1,total-1);


        for (int i=0;i<total;++i)
            cout<<str1[i]<<' ';
        cout<<'\n';
        for (int i=0;i<total;++i)
            cout<<ind1[i]<<' ';
        cout<<'\n';
        /*vector<char> str2;
        vector<int> ind2;

        ind2.assaign(-1,total);
        for (int i=0;i<total;++i)
        {
            cin>>c;
            str2.push_back(c);
        }
        determine(str2,ind2,total-1);*/

    }
    return 0;

}
