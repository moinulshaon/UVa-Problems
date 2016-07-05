#include <stdio.h>
#include <string.h>

int palindrome(char arr[],int len)
{
	int i;
	for (i=0;i<len/2;++i)
		if (arr[i]!=arr[len-i-1])
			return (0);

	return (1);
}

int mirror(char arr[],int len)
{
	int i;
	for (i=0;i<len;++i)
	{
		if (arr[i]=='E')
			arr[i]='3';
		else if (arr[i]=='J')
			arr[i]='L';
		else if (arr[i]=='S')
			arr[i]='2';
		else if (arr[i]=='Z')
			arr[i]='5';
		else if (arr[i]=='O')
			arr[i]='0';
	}
	if (palindrome(arr,len))
		return (1);
	else 
		return (0);
}

 
int mirrorpalindrome(char x[],int len)
{
	    int i,c;
	    c=0;
	    for(i=0;i<len;i++)
		{
	        if(x[i]=='A'||x[i]=='0'||x[i]=='H'||x[i]=='I'||x[i]=='M'||x[i]=='O'||x[i]=='Y'
	        ||x[i]=='X'||x[i]=='W'||x[i]=='V'||x[i]=='U'||x[i]=='T'||x[i]=='1'||x[i]=='8')
	            c++;
	    }
	    if(c==len)
	        return 1;
	    else
	        return 0;
}
	    

int main()
{
	char arr[20];
	int len,p,m,mp,i;


	while (scanf("%s",arr)!=EOF)
	{
		len=strlen(arr);


		for (i=0;i<len;++i)
			printf("%c",arr[i]);
		
		p=palindrome(arr,len);
		m=mirror(arr,len);
		mp=mirrorpalindrome(arr,len);

		if (p)
		{
			if (mp)
				printf(" -- is a mirrored palindrome.\n\n");
			else 
				printf(" -- is a regular palindrome.\n\n");
		}
		else 
		{
			if (m)
				printf(" -- is a mirrored string.\n\n");
			else
				printf(" -- is not a palindrome.\n\n");
		}
	}
	return (0);
}