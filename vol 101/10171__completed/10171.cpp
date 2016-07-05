#include <iostream>
#include <cstdio>

#define min(a,b) ((a)<(b))?(a):(b)
#define INF 1000000

using namespace std;

int dy[26][26];
int dm[26][26];


int main()
{
	int i,j,k,dis;
	int test;
	char c,a,b;
	
	freopen("input.txt","r",stdin);
	
	while(1)
	{
		cin>>test;
		if (!test)return 0;
		
		for ( i = 0; i < 26; i++ ) 
            for ( j = 0; j < 26; j++ )
        	{
				dy[i][j]=dm[i][j]=INF;
			}
		for ( i = 0; i < 26; i++ ) 
			dy[i][i]=dm[i][i]=0;
		
		while(test--)
		{
			
			
			
			cin>>c;
			if (c=='Y')
			{
				
				cin>>c;
				cin>>a>>b>>dis;
				
				
				
				if (c=='U')
				{
					if (dis<dy[a-'A'][b-'A'])
						dy[a-'A'][b-'A']=dis;
				}
				else
				{
					
					if (dis<dy[a-'A'][b-'A'])
						dy[a-'A'][b-'A']=dis;
					
					if (dis<dy[b-'A'][a-'A'])
						dy[b-'A'][a-'A']=dis;
				}
					
			}
			else if (c=='M')
			{
				cin>>c;
				cin>>a>>b>>dis;
				
				if (c=='U')
				{
					if (dis<dm[a-'A'][b-'A'])
						dm[a-'A'][b-'A']=dis;
				}
				else
				{
					
					if (dis<dm[a-'A'][b-'A'])
						dm[a-'A'][b-'A']=dis;
					
					if (dis<dm[b-'A'][a-'A'])
						dm[b-'A'][a-'A']=dis;
				}
					
			}
		}
		
		
		
		cin>>a>>b;
			
			
			
		for ( k = 0; k < 26; k++ ) 
           	for ( i = 0; i < 26; i++ ) 
               	for ( j = 0; j < 26; j++ )
		   		{
					
					dy [i] [j] = min (dy [i] [j],  dy [i] [k]+ dy [k] [j]); 
					dm [i] [j] = min (dm [i] [j],  dm [i] [k]+ dm [k] [j]);
		
				}
		
		
	
		
				
		dis=INF;
		for ( i = 0; i < 26; i++ ) 
		{
			if (dy[a-'A'][i]+dm[b-'A'][i]<dis)
				dis=dy[a-'A'][i]+dm[b-'A'][i];
		}
		if (dis<INF)
		{
			printf("%d",dis);
			for (i=0;i<26;++i)
				if (dy[a-'A'][i]+dm[b-'A'][i]==dis)
					printf(" %c",i+'A');
			printf("\n");
				
					
		}
		else 
			printf("You will never meet.\n");
			
		
		
			
	}	
	
}
