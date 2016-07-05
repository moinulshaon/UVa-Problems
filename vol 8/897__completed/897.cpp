#include <cstdio>

int arr[22]={2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991};

int main()
{
    int input;
    bool printed;

    while (true)
    {
        scanf("%d",&input);
        if (!input)return 0;

        printed=false;
        if (input<10)
        {
            for (int i=0;i<4;++i)
                if (input<arr[i])
                {
                    printf("%d\n",arr[i]);
                    printed=true;
                    break;
                }
        }
        else if (input<100)
        {
            for (int i=4;i<13;++i)
                if (input<arr[i])
                {
                    printf("%d\n",arr[i]);
                    printed=true;
                    break;
                }
        }
        else if (input<1000)
        {
            for (int i=13;i<22;++i)
                if (input<arr[i])
                {
                    printf("%d\n",arr[i]);
                    printed=true;
                    break;
                }
        }
        if (!printed)
            printf("0\n");
    }
}
