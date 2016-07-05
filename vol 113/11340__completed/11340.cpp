#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main()
{

    freopen("in.txt","r",stdin);

    int test,result;
    char line[10100];
    scanf("%d",&test);
    getchar();

    while (test--)
    {
        map <char,int> val;

        result=0;

        int total,temp;
        char c;

        scanf("%d",&total);
        getchar();

        while (total--)
        {
            scanf("%c %d",&c,&temp);
            getchar();
            val[c]=temp;
        }

        scanf("%d",&total);
        getchar();

        while (total--)
        {
            gets(line);
            for (int i=0;line[i];++i)
                if (val.find(line[i])!=val.end())
                    result+=val[line[i]];
        }

        printf("%.2lf$\n",double(result)/100);
    }
    return 0;
}
