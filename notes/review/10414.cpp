#include <iostream>
#include <cstdio>
using namespace std;

void convert(long long num){
    if (num / 10000000 != 0){
        convert(num / 10000000);
        printf (" kuti");
        num %= 10000000;
    }
    if (num / 100000 != 0){
        convert(num / 100000);
        printf(" lakh");
        num %= 100000;
    }
    if (num / 1000 != 0){
        convert(num / 1000);
        printf (" hajar");
        num %= 1000;
    }
    if (num / 100 != 0){
        convert(num / 100);
        printf (" shata");
        num %= 100;
    }
    if (num != 0){
        printf (" %d", num);
    }
}

int main(){
    long long n;
    int c = 1;
    while (cin >> n){
        printf("%d.", c++);
        convert (n);
        printf ("\n");
    }

    return 0;
}