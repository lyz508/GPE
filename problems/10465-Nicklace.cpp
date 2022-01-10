#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    double v, v0;
    
    while (cin >> v >> v0){
        if (v == 0 && v0 == 0) break;
        int mx = 0;
        double max_n = -1;
        char s1[100], s2[100];

        for (int i=1; i<=v; i++){
            double tmp = v/i;
            double now = 0.3*sqrt(tmp-v0) * i;
            if ( tmp <= v0 ) break;

            // compare if equal, equal -> isn't unique
            sprintf(s1, "%.10lf", now);
            sprintf(s2, "%.10lf", max_n);
            if(strcmp(s1, s2) == 0){
                mx = 0;
                break;
            }
            
            if (now > max_n){
                max_n = now;
                mx = i;
            }
            else if (now < max_n){
                break;
            }

        }

        printf("%d\n", mx);
    }

    return 0;
}