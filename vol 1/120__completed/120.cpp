#include <cstdio>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void flip (vector <int> &p, int x)
{
    for ( int i = 0; i <= x / 2; i++ )
        swap (p [i], p [x - i]);
}

int main()
{

    //freopen("in.txt","r",stdin);

    string ss;
    while (getline (cin,ss) )
    {
        vector <int> v;
        vector <int> save;
        vector <int> result;
        stringstream sstr(ss);
        int tmp;
        while (sstr>>tmp)
            v.push_back(tmp);
        tmp=v.size();
        save=v;

        for (int k=0;k<tmp;++k)
        {
            int mx=0;
            for (int i=0;i<tmp-k;++i)
            {
                if (v[i]>v[mx])
                    mx=i;
            }

            if (mx!=tmp-k-1)
            {
                if (mx!=0)
                {
                    flip(v,mx);
                    result.push_back(tmp-mx);
                }

                flip(v,tmp-k-1);
                result.push_back(k+1);

            }
        }

        tmp=save.size();
        for (int i=0;i<tmp;++i)
        {
            if (i)
                printf(" %d",save[i]);
            else
                printf("%d",save[i]);
        }
        printf("\n");

        tmp=result.size();
        for (int i=0;i<tmp;++i)
        {
            printf("%d ",result[i]);
        }
        printf("0\n");
    }
    return 0;
}
