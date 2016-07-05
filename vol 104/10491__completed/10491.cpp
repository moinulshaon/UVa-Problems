#include<cstdio>

double COWS, CARS, SHOW;

int main()
{
    while(scanf("%lf%lf%lf", &COWS, &CARS, &SHOW) == 3)
        printf("%.5lf\n", (COWS * CARS + CARS * (CARS - 1)) / (CARS + COWS) / (CARS + COWS - SHOW - 1));
    return 0;
}
