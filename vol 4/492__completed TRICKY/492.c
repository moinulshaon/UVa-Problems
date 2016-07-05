#include <stdio.h>

int main()
{
	char c,temp=' ';
	int save=0,firstletter=1;;

	while (scanf("%c",&c)==1)
	{
		if (c=='a' || c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
		{
			printf("%c",c);
			firstletter=0;
		}
		else if((c>='a' && c<='z')||(c>='A' && c<='Z'))
		{
			if (firstletter)
			{
				temp=c;
				firstletter=0;
				save=1;
			}
			else
				printf("%c",c);
		}
		else if (save)
		{
			printf("%cay%c",temp,c);
			save=0;
			firstletter=1;
		
		}
		else 
		{
			if(firstletter==0)
				printf("ay");
			printf("%c",c);
			save=0;
			firstletter=1;
		}
	}
	return (0);
}