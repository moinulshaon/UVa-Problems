#include <cstdio>
#include <cmath>

const double EPS=1e-6;

using namespace std;

int main() {

    double len, width, x;

    while(scanf("%lf %lf", &len, &width)==2) {

        x = (width + len - sqrt(width*width + len*len - width*len))/6.0;

        printf ("%.3f 0.000 ", x+EPS);

        if (len < width) {
            printf ("%.3f", len/2.0+EPS);
        }else {
            printf ("%.3f", width/2.0+EPS);
        }

        printf("\n");

    }
    return 0;
}
