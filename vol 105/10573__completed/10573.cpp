#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int test;
    double PI=acos(-1);
    scanf("%d",&test);
    getchar();
    while (test--)
    {
        string str;
        getline(cin,str);

        istringstream sstr(str);

        int a[2];
        int cnt;
        for (cnt=0;sstr>>a[cnt];++cnt)
            ;
        if (cnt==2)
        {
            double R=a[0]+a[1];
            double result=PI*(R*R-a[0]*a[0]-a[1]*a[1]);
            printf("%.4lf\n",result);
        }
        else if (cnt==1)
        {
            double result=(PI*a[0]*a[0])/8;
            printf("%.4lf\n",result);
        }
    }
    return 0;
}
