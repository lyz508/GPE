#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    vector< long long > t;
    t.resize(51);
    t[1] = 1;
    t[2] = 2;
    for (int i=3; i<t.size(); i++){
        t[i] = t[i-1] + t[i-2];
    }

    int tmp;
    while (cin >> tmp && tmp != 0){
        printf("%lld\n", t[tmp]);
    }

    return 0;
}