#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
bool prime[32768];


void div(int input)
{
    vector <int> v;
    bool space=false;
	int count=0,temp2=sqrt(input);
	for (int i=temp2; input!=1  && i>=2;--i)
	{
		if (prime[i] && input%i==0)
		{
            v.push_back(i);

			count=0;
			while (input%i==0)
			{
				input/=i;
				++count;
			}
			v.push_back(count);
		}
	}

	if (input>temp2)
    {
        if (space)
            printf(" ");
        space=true;
        printf("%d 1",input);
    }
    for (int i=0;i<v.size();i+=2)
    {
        if (space)
            printf(" ");
        space=true;
        printf("%d %d",v[i],v[i+1]);
    }

    printf("\n");

}

int main()
{

    //freopen("in.txt","r",stdin);

    string a;
    int p,q,input;

    for (int i=2;i<32768;++i)
		prime[i]=1;

	for (int i=2;i<=181;++i)
		if (prime[i])
			for (int j=i*2;j<32768;j+=i)
				prime[j]=0;

    while (true)
    {
        input=1;
        getline(cin,a);

        istringstream sstr(a);
        while (sstr>>p>>q)
        {
            input*=int(pow(p,q));
        }

        if (!p)return 0;

        div(input-1);
    }

}
