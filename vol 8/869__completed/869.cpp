#include <iostream>
#include <cstdio>

#define min(a,b) ((a)<(b))?(a):(b)
#define INF 1000000

using namespace std;

int d1[52][52];
int d2[52][52];


int main()
{
	int i,j,k,p,q;
	int test,m;
	char a,b,flag;
	
	freopen("input.txt","r",stdin);
	
	cin>>test;
	while(test--)
	{
		
		
		for ( i = 0; i < 52; i++ ) 
            for ( j = 0; j < 52; j++ )
				d1[i][j]=d2[i][j]=INF;
			
		
		
		
		
		cin>>m;

		while (m--)
		{
			cin>>a>>b;

			if (a >='a')p=a-'a'+26;
			else p=a-'A';

			if (b >='a')q=b-'a'+26;
			else q=b-'A';

			d1[p][q]=d1[q][p]=1;	
		}
		
		cin>>m;

		while (m--)
		{
			cin>>a>>b;

			if (a >='a')p=a-'a'+26;
			else p=a-'A';

			if (b >='a')q=b-'a'+26;
			else q=b-'A';

			d2[p][q]=d2[q][p]=1;	
		}
			

		for ( i = 0; i < 52; i++ ) 
			d1[i][i]=d2[i][i]=0;

		
		

		for ( k = 0; k < 52; k++ ) 
           	for ( i = 0; i < 52; i++ ) 
               	for ( j = 0; j < 52; j++ )
		   		{
					
					d1 [i] [j] = min (d1 [i] [j],  d1 [i] [k]+ d1 [k] [j]); 
					d2 [i] [j] = min (d2 [i] [j],  d2 [i] [k]+ d2 [k] [j]);
		
				}
		
		
	
		
				
	
		flag=0;
		for (i=0;i<52;++i)
			for (j=0;j<52;++j)
				if ( (d1 [i] [j]!=INF && d2 [i] [j]==INF ) || (d2 [i] [j]!=INF && d1 [i] [j]==INF ))
				{
					flag=1;
					j=i=100;
				}
		if (flag)
			printf("NO\n");
		else
			printf("YES\n");
		
			
	}	
	return 0;
	
}