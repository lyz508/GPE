#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long s, d;
    while (cin >> s >> d){
        while (1){
            d -= s;
            if (d <= 0)
                break;
            s++;
        }
        printf("%lld\n", s);
    }

    return 0;
}