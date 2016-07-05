#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#define N 65536

using namespace std;

bool primes[N+1];
bool mark[N+1];
unsigned long long int  maxi[N+1];
unsigned long long int super[100000];

void cachePrimes()
{
	unsigned int i,j;

	for(i=2;i<=N;i++)
		maxi[i] = ceil(64/(log(i)/log(2)));
	primes[0] = true;
	primes[1] = true;
	for(i=4;i<=N;i+=2)
		primes[i] = true;
	for(i=3;i*i<=N;i+=2)
		if(!primes[i])
			for(j=i*i;j<=N;j+=i)
				primes[j] = true;
}

int main()
{

	unsigned int i,j,top,power;
	unsigned long long int l;
	//super = (unsigned long long int*) malloc(100000*sizeof(unsigned long long int*));
	cachePrimes();
	top=0;
	super[top++]=1;
	for(i=2;i<N;i++)
	{
		if(!mark[i])
		{
			for(j=i*i;j<N;j*=i)
				mark[j]=1;
			l = i;
			power = 1;
			for(j=4;j<maxi[i];j++)
			{
				if(primes[j])
				{
					while(power<j)
					{
						l*=i;
						power++;
					}
					super[top++]=l;
				}
			}
		}
	}

    cout<<top<<endl;
    exit(0);

	sort(super,super+top);
	for(i=0;i<top;i++)
		printf("%llu\n",super[i]);
	return 0;
}
