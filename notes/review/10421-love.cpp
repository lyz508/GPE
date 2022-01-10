#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
using namespace std;

bool gcd(int a, int b){
    int x = max(a, b),
        y = min(a, b), t;
    while (x % y != 0){
        t = y;
        y = x % y;
        x = t;
    }
    return (y == 1) ? false : true;
}

int convert(string num){
    int rtn = 0;
    for (int i=num.size()-1, base = 0; i>=0; i--, base++){
        if (num[i] == '1')
            rtn += 1 << base;
    }
    return rtn;
}

int main(){
    int n;
    string s1, s2;
    cin >> n;

    for (int time=1; time<=n; time++){
        cin >> s1 >> s2;
        bool res = gcd(convert(s1), convert(s2));
        if (res)
            printf ("Pair #%d: All you need is love!\n", time);
        else
            printf ("Pair #%d: Love is not all you need!\n", time);
    }

    return 0;
}