#include <cstdio>
#include <cstring>
#define sz 110

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);

	char arr1[sz][sz];
	memset(arr1,' ',sizeof(arr1));

	int maxLength=0,temp,line;

	for (line=0;gets(arr1[line]);++line)
	{
		temp=strlen(arr1[line]);
		if (maxLength<temp)
			maxLength=temp;
        arr1[line][temp]=' ';
	}

	for (int i=0;i<maxLength;++i){
        for (int j=line-1;j>=0;--j){
            printf("%c",arr1[j][i]);
        }
        printf("\n");
	}
	return 0;
}
