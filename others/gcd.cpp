#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int gcd (int x, int y){
    int a = max(x, y),
        b = min(x, y), t;
    while (a % b != 0){
        t = b;
        b = (a % b);
        a = t;
    }
    return b;
}

int main()
{
    cout << gcd(1071, 462) << "\n";
    return 0;
}