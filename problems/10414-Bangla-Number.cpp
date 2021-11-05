#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void convert(long long t){
    if (t / 10000000 != 0){
        convert(t / 10000000);
        cout << " kuti";
        t %= 10000000;
    }

    if (t / 100000 != 0){
        convert(t / 100000);
        cout << " lakh";
        t %= 100000;
    }
    if (t / 1000 != 0){
        convert(t / 1000);
        cout << " hajar";
        t %= 1000;
    }
    if (t / 100 != 0){
        convert(t / 100);
        cout << " shata";
        t %= 100;
    }
    // may cause redundent on the digits
    if (t != 0){
        cout << " " <<  t;
    }
}

int main(){
    int c = 1;
    long long t;

    while (cin >> t){
        printf("%d.", c++);
        if (t == 0) printf(" 0");
        convert(t);
        printf("\n");
    }

    return 0;
}