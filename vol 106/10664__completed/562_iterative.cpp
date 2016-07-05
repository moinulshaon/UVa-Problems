#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int arr[30];

int n;
int capacity;
bool vis[250];

int main()
{
    int kase;
    scanf("%d",&kase);
    getchar();
    string str;
    while (kase--)
    {
        capacity=0;
        getline(cin,str);
        stringstream sstr(str);
        for (n=0;sstr>>arr[n];++n)
        {
            capacity+=arr[n];
        }
        int save=capacity;
        capacity/=2;

        for (int i=0;i<=capacity;++i)
            vis[i]=false;
        vis[0]=true;
        for (int i=0;i<n;++i)
        {
            for (int j=249;j>=0;--j)
            {
                if (vis[j])
                    vis[ j+arr[i] ]=true;
            }
        }

        int result;

        for (int i=capacity;i>=0;--i)
            if (vis[i])
            {
                result=i;
                break;
            }
        if (save-2*result==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
