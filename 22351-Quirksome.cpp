#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int main(){
    int d;
    vector<int> table[4];

    for (int digit = 2; digit <= 8; digit += 2){
        int brace = (int)pow(10, digit/2),
            limit = (int)pow(10, digit);
        for (int i=0, n; i * i < limit; i++){
            n = i * i;
            if ( ((n / brace) + (n % brace)) * ((n / brace) + (n % brace))
                == n
            ){
               table[digit/2-1].push_back(n);
            }
        }
    }

    while (cin >> d){
        int idx = d / 2 - 1;
        for (int i=0; i<table[idx].size(); i++){
            printf("%0*d\n", d, table[idx][i]);
        }
    }

    return 0;
}