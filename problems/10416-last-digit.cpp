#include <cstdio>
#include <iostream>
using namespace std;

// only return last digit
int fp_mod(int n, int p){
    if (p == 1)
        return n;

    int rtn, tmp;

    if (p%2 != 0){
        tmp = fp_mod(n, (p-1)/2);
        rtn = n * tmp * tmp;
    }
    else{
        tmp = fp_mod(n, p/2);
        rtn = tmp * tmp;
    }

    return rtn%10;
}

int main(){

    // 1~99 = 1 cycle
    int table[100] = {};
    table[0] = 0;
    for (int i=1; i<100; i++){
        int a = i % 10;
        table[i] = (fp_mod(a, i) + table[i-1]) % 10;
    }


    string n;
    while (cin >> n){
        if (n == "0") break; // end

        // n%100
        int idx, sum = 0;
        if (n.length() < 2)
            idx = n[0] - '0';
        else
            idx = (n[n.length()-2] - '0') * 10 + (n[n.length()-1] - '0');

        cout << table[idx] << endl;
    }

    return 0;
}


