#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool gcd(int a, int b){
    int x = max(a, b),
        y = min(a, b), t;

    while (x % y != 0){
        t = y;
        y = x%y;
        x = t;
    }

    return (y == 1)? false : true;
}

int main(){
    int t;
    cin >> t;
    for (int time=1; time <=t; time++){
        string tmpa, tmpb;
        long long a=0, b=0;

        if (tmpa.length() == 1 || tmpb.length() == 1){
            cout << "Pair #" << time << ": Love is not all you need!\n";
            continue;
        }

        cin >> tmpa >> tmpb;
        for (int i=tmpa.length()-1, c=0, base=1; i>=0; i--, c++){
            base=(1 << c);
            a += (tmpa[i] - '0') * base;
        }
        for (int i=tmpb.length()-1, c=0, base=1; i>=0; i--, c++){
            base=(1 << c);
            b += (tmpb[i] - '0') * base;
        }


        if (!gcd(a, b)){
            cout << "Pair #" << time << ": Love is not all you need!\n";
        }
        else{
            cout << "Pair #" << time << ": All you need is love!\n";
        }
    }   


    return 0;
}