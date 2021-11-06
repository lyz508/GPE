#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    double d;
    while (cin >> d){
        double dd = d * d,
            a = dd - 2*((double)1/12)*dd*M_PI - sqrt(3)/4*dd,
            b = dd - (double)1/4 * dd*M_PI - 2*a,
            c = dd - 4*a - 4*b;

        printf("%.3lf %.3f %.3f\n", c, 4*b, 4*a);
    }

    return 0;
}