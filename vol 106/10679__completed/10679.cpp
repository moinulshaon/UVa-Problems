#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char one[1000001];
    char two[1001];
    int test,len,tmp,query;
    scanf("%d",&test);
    while (test--)
    {
        tmp=strlen(one);
        query;

        scanf("%s",one);
        scanf("%d",&query);

        while (query--)
        {

            scanf("%s",two);

            len=strlen(two);

            if (strncmp(one,two,len)==0)
                printf("y\n");
            else
                printf("n\n");
        }
    }
    return 0;
}
