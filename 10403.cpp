#include <iostream>
#include <cstdio>
using namespace std;

int deci(int n){
    int num1 = 0;
    while (n != 0){
        if (n % 2 != 0) num1++;
        n /= 2;
    }
    return num1;
}

int hexa(int n){ // for every four, interpret
    int num1 = 0, tmp;
    while (n != 0){
        tmp = n % 10;
        num1 += deci(tmp);
        n /= 10;
    }
    return num1;
}

int main(){
    int cases, n;
    cin >> cases;
    while (cases--){
        cin >> n;
        printf("%d %d\n", deci(n), hexa(n));
    }

    return 0;
}