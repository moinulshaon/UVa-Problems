#include<bits/stdc++.h>
using namespace std;

const int maxn = 1200 + 10;
const double PI = acos(-1.0);

struct Point
{
    int x, y;
}p[maxn];
double ang[maxn * 2];
typedef Point Vector;

double inline C2(int n) { return n * (n-1) / 2; }
double inline C3(int n) { return n * (n-1) / 2 * (n-2) / 3; }
double solve(int n)
{
    double s = C3(n-1), ans = 0;
    for(int i = 0; i < n; i++)
    {
        int k = 0;
        for(int j = 0; j < n; j++) if(j != i)
        {
            ang[k] = atan2(p[j].x-p[i].x, p[j].y-p[i].y);
            ang[k + n - 1] = ang[k] + 2.0 * PI;
            k++;
        }
        k = 2*(n-1);
        sort(ang, ang + k);

        int L = 0, R = 0;
        double t = 0;
        for(L = 0; L < n-1; L++)
        {
            double temp = ang[L] + PI;
            while(temp > ang[R]) R++;
            t += C2(R - L - 1);
        }
        ans += s - t;
        cout<<ans<<endl;

    }
    return ans;
}

int main()
{
    freopen("in.txt", "r", stdin);

    int n, kase = 0;
    while(scanf("%d", &n) == 1 && n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d%d", &p[i].x, &p[i].y);
        double ans = solve(n) / C3(n);
        printf("City %d: %.2f\n", ++kase, ans);
    }

    return 0;
}

