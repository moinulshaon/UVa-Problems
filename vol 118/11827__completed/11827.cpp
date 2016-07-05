#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int gcd(int a,int b)
{
    int temp;
    if (a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    temp=a;
    while (b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return temp;

}

int arr[120];
int main()
{
    int cases;
    cin>>cases;
    getchar();
    while (cases--)
    {
        string line;
        getline(cin,line);

        istringstream sstr(line);

        int d=1,in,cnt;
        for (cnt=0;sstr>>arr[cnt];++cnt)
            ;
        for (int i=0;i<cnt;++i)
            for (int j=i+1;j<cnt;++j)
            {
                in=gcd(arr[i],arr[j]);
                if (in>d)
                    d=in;
            }
        printf("%d\n",d);
    }
    return 0;
}
