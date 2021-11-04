#include <iostream>
using namespace std;

int main(){
    long long self, oponent, diff;
    while (cin >> self >> oponent)
    {
        diff = self - oponent;
        cout << ((diff < 0) ? -diff : diff) << "\n";
    }

    return 0;
}