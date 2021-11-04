#include <iostream>
#include <cmath>
using namespace std;

int main(){
    unsigned int n, sq;
    while (cin >> n && n != 0){
        sq = sqrt(n);
        cout << ((sq * sq == n) ? "yes" : "no") << "\n";
    }

    return 0;
}