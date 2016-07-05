#include <cstdio>
#include <cstring>

using namespace std;

int main()
{

    freopen("in.txt","r",stdin);

    char arr[200];
    int line;
    int cases=1;
    while (true)
    {
        scanf("%d",&line);
        if (!line)return 0;
        getchar();
        printf("Case %d:\n",cases++);
        printf("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");
        for (int i=0;i<line;)
        {
            gets(arr);
            if (strlen(arr)==0)
                continue;

            printf("printf(\"");
            for (int j=0;arr[j]!='\0';++j)
            {
                if (arr[j]=='"' || arr[j]=='\\')
                    printf("\\");
                printf("%c",arr[j]);
            }
            printf("\\n\");\n");
            ++i;
        }
        printf("printf(\"\\n\");\nreturn 0;\n}\n");
    }
}
