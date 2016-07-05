#include <cstdio>


int save[]={
3,
5,
8,
12,
20,
34,
57,
98,
170,
300,
536,
966,
1754,
3210,
5910,
10944,
20366,
38064,
71421,
134480,
254016,
};

int main(){

    int in;
    while (true){

        scanf("%d",&in);
        if (!in)return 0;

        printf("%d\n",save[(in-1960)/10]);
    }

}
