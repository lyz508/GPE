#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// pow is in cmath

int main(){
    double v, t, a, s;
    while (cin >> v >> t){
        if (t == 0){
            cout << 0 << "\n";
            continue;
        }
        a = v/t;
        s = a*(pow(2*t, 2))/2;
        cout << s << "\n";
    }

    return 0;
}