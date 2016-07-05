#include <stdio.h>


int arr[62];
char prime[2001];
int main()
{
	int test,m,i,j;
	char c,flag;

	for (i=2;i<2001;++i)
		prime[i]=1;

	for (i=2;i<=44;++i)
		if (prime[i])
			for (j=i*2;j<2001;j+=i)
				prime[j]=0;
	


	scanf("%d",&test);
	getchar();


	for (m=1;m<=test;++m)
	{
		flag=0;
		for (i=0;i<62;++i)
			arr[i]=0;
		while((c=getchar())!='\n')
		{
			if (c>='0' && c<='9')
				++arr[c-'0'];
			else if (c>='A' && c<='Z')
				++arr[c-'A'+10];
			else
				++arr[c-'a'+36];
		}

		printf("Case %d: ",m);

		for (i=0;i<10;++i)
		{
			if (prime[arr[i]])
			{
				printf("%c",'0'+i);
				flag=1;
			}
		}
		for (i=10;i<36;++i)
		{
			if (prime[arr[i]])
			{
				printf("%c",'A'+i-10);
				flag=1;
			}
		}
		for (i=36;i<62;++i)
		{
			if (prime[arr[i]])
			{
				printf("%c",'a'+i-36);
				flag=1;
			}
		}
		if (!flag)
			printf("empty");
		printf("\n");
	}
	return 0;
}