#include <stdio.h>
#include <string.h>
#define size 2000

int palindrome(char *number);
int scanNumber(char *number,int *i);
int strcpyrev_(char *temp,char *number,int *digit);
int add(char *number,int *digit,int base);



int main()
{
	char number[size+1],temp[size+1];
	int step,digit,base,i,flag,tempDigit;

	while (scanNumber(number,&digit))
	{
		strcpy(temp,number);
		tempDigit=digit;
		for (base=15;base>=2;--base)
		{
			if (base!=15)
				printf(" ");
			strcpy(number,temp);
			digit=tempDigit;
			flag=step=0;
			for (i=0;i<digit;++i)
			{
				if (number[size-digit+i]>='0'+base)
				{
					flag=1;
					break;
				}
			}
			if (flag)
			{
				printf("?");
				continue;
			}
			while   (palindrome(&number[size-digit]))
			{
				add(number,&digit,base);
				++step;
			//	printf("%s\n",&number[size-digit]);
			//	getchar();
			}
			printf("%d",step);
			
		}
		printf("\n");	

	}
	return (0);
}

int palindrome(char *number)
{
	int i,len;
	len=strlen(number);
	for (i=0;i<len/2;++i)
		if (number[i]!=number[len-i-1])
			return (1);
	return (0);
}
int scanNumber(char *number,int *i)
{
	char c;
	for (*i=0;(c=getchar())!='\n';++(*i))
	{
		if (c>='0' && c<='9')
			number[size-*i-1]=c;
		else if (c>='A' && c<='E')
			number[size-*i-1]=c-'A'+10+'0';
		else if (c>='a' && c<='e')
			number[size-*i-1]=c-'a'+10+'0';
		else if (c==EOF)
			return (0);
	}	
	number[size]='\0';
	return (1);
}
int strcpyrev_(char *temp,char *number,int *digit)
{
	int i=0;
	for (i=0;number[i]!='\0';++i)
	{
		temp[i]=number[*digit-i-1];
	}
	temp[i]='\0';
	return (0);
}

int add(char *number,int *digit,int base)
{
	int i,temp2=*digit;
	char temp[size];
	strcpyrev_(temp,&number[size-*digit],digit);
	
	for (i=0;i<temp2;++i)
	{
		number[size-i-1]+=temp[temp2-i-1]-'0';
		if (number[size-i-1]>'0'+base-1)
		{
			number[size-i-1]-=base;
			if (i!=temp2-1)
				number[size-i-2]+=1;
			else
			{
				number[size-i-2]='1';
				++(*digit);
			}
		}
	}
	return (0);

}