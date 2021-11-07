#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    long long n;
    while (cin >> n && n != 0){
        long long j = sqrt(n);
        if ( j*j == n )
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}